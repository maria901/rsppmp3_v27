////////////////////////////////////////////////////////////////////////////////////////////////////////////// 2021
///
/// SoundStretch main routine.
///
/// Author        : Copyright (c) Olli Parviainen
/// Author e-mail : oparviai 'at' iki.fi
/// SoundTouch WWW: http://www.surina.net/soundtouch
///
///////////////////////////////////////////////////////////////////////////////////////////////////////////]// ////
//
// Last changed  : $Date: 2006/02/05 16:44:06 $
// File revision : $Revision: 1.20 $
//
// $Id: main.cpp,v 1.20 2006/02/05 16:44:06 Olli Exp $
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////// ////
//
// License :
//
//  SoundTouch audio processing library
//  Copyright (c) Olli Parviainen
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////// ////

#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include "RunParameters.h"
#include "WavFile.h"
#include "SoundTouch.h"
#include "BPMDetect.h"

using namespace soundtouch;
using namespace std;

// Processing chunk size
#define BUFF_SIZE           2048

static const char _helloText[] =
        "\n"
        "   SoundStretch v%s -  Written by Olli Parviainen 2001 - 2006\n"
        "==================================================================\n"
        "author e-mail: <oparviai@iki.fi> - WWW: http://www.surina.net/soundtouch\n"
        "\n"
        "This program is subject to (L)GPL license. Run \"soundstretch -license\" for\n"
        "more information.\n"
        "\n";

static void openFiles(WavInFile **inFile, WavOutFile **outFile, const RunParameters *params)
{
	int bits, samplerate, channels;

	// open input file...
	*inFile = new WavInFile(params->inFileName);

	// ... open output file with same sound parameters
	bits = (*inFile)->getNumBits();
	samplerate = (*inFile)->getSampleRate();
	channels = (*inFile)->getNumChannels();

	if (params->outFileName)
	{
		*outFile = new WavOutFile(params->outFileName, samplerate, bits, channels);
	}
	else
	{
		*outFile = NULL;
	}
}

// Sets the 'SoundTouch' object up according to input file sound format &
// command line parameters
static void setup(SoundTouch *pSoundTouch, int sampleRate,int channels, int tempoDelta, int pitchDelta,int rateDelta  )
{

	pSoundTouch->setSampleRate(sampleRate);
	pSoundTouch->setChannels(channels);

	pSoundTouch->setTempoChange(tempoDelta);
	pSoundTouch->setPitchSemiTones(pitchDelta);
	pSoundTouch->setRateChange(rateDelta);

	pSoundTouch->setSetting(SETTING_USE_QUICKSEEK, 0);
	pSoundTouch->setSetting(SETTING_USE_AA_FILTER, !0);

	// print processing information
	if (1)
	{
#ifdef INTEGER_SAMPLES
		//printf("Uses 16bit integer sample type in processing.\n\n");
#else
    #ifndef FLOAT_SAMPLES
	#error "Sampletype not defined"
    #endif
		//printf("Uses 32bit floating point sample type in processing.\n\n");
#endif
		// print processing information only if outFileName given i.e. some processing will happen
		//printf("Processing the file with the following changes:\n");
		//printf("  tempo change = %+g %%\n", (double)tempoDelta);
		//printf("  pitch change = %+g semitones\n", (double)pitchDelta);
		//printf("  rate change  = %+g %%\n\n", (double)rateDelta);
		//printf("Working...");
	}
	else
	{
		// outFileName not given
		//printf("Warning: output file name missing, won't output anything.\n\n");
	}

}

// Processes the sound
static void process(int reset,SoundTouch *pSoundTouch, int nChannels,char *inbuffer, char *outbuffer, int size, int *sizeout)
{
	int nSamples;

	int buffSizeSamples;
	SAMPLETYPE sampleBuffer[100000];

	char *ptr=outbuffer;
	*sizeout=0;
	// nChannels = inFile->getNumChannels();
	buffSizeSamples = (size/2) / nChannels;

	// Process samples read from the input file
	while (size)
	{
		int num=size;

		// Read a chunk of samples from the input file
		memcpy(sampleBuffer, inbuffer,size);
		size=0;
		num = num / 2;
		nSamples = num / nChannels;

		// Feed the samples into SoundTouch processor
		pSoundTouch->putSamples(sampleBuffer, nSamples);

		// Read ready samples from SoundTouch processor & write them output file.
		// NOTES:
		// - 'receiveSamples' doesn't necessarily return any samples at all
		//   during some rounds!
		// - On the other hand, during some round 'receiveSamples' may have more
		//   ready samples than would fit into 'sampleBuffer', and for this reason
		//   the 'receiveSamples' call is iterated for as many times as it
		//   outputs samples.
		do
		{
			nSamples = pSoundTouch->receiveSamples(sampleBuffer, buffSizeSamples);
			//   outFile->write(sampleBuffer, nSamples * nChannels);

			if(nSamples)
			{
				memcpy(ptr,sampleBuffer,(nSamples * nChannels*2));
				ptr+=(nSamples * nChannels*2);
				*sizeout+=(nSamples * nChannels*2);
			}

		} while (nSamples != 0);
	}

	// Now the input file is processed, yet 'flush' few last samples that are
	// hiding in the SoundTouch's internal processing pipeline.
	if(reset)
	{
		pSoundTouch->flush();
		do
		{
			nSamples = pSoundTouch->receiveSamples(sampleBuffer, buffSizeSamples);
			// outFile->write(sampleBuffer, nSamples * nChannels);
			if(nSamples)
			{
				memcpy(ptr,sampleBuffer,(nSamples * nChannels*2));
				ptr+=(nSamples * nChannels*2);
				*sizeout+=(nSamples * nChannels*2);
			}

		} while (nSamples != 0);
	}

}

// Detect BPM rate of inFile and adjust tempo setting accordingly if necessary
static void detectBPM(WavInFile *inFile, RunParameters *params)
{
	float bpmValue;
	int nChannels;
	BPMDetect bpm(inFile->getNumChannels(), inFile->getSampleRate());
	SAMPLETYPE sampleBuffer[BUFF_SIZE];

	// detect bpm rate
	//printf("Detecting BPM rate...");
	fflush(stdout);

	nChannels = inFile->getNumChannels();

	// Process the 'inFile' in small blocks, repeat until whole file has
	// been processed
	while (inFile->eof() == 0)
	{
		int num, samples;

		// Read sample data from input file
		num = inFile->read(sampleBuffer, BUFF_SIZE);

		// Enter the new samples to the bpm analyzer class
		samples = num / nChannels;
		bpm.inputSamples(sampleBuffer, samples);
	}

	// Now the whole song data has been analyzed. Read the resulting bpm.
	bpmValue = bpm.getBpm();
	//printf("Done!\n");

	// rewind the file after bpm detection
	inFile->rewind();

	if (bpmValue > 0)
	{
		//printf("Detected BPM rate %.1f\n\n", bpmValue);
	}
	else
	{
		//printf("Couldn't detect BPM rate.\n\n");
		return;
	}

	if (params->goalBPM > 0)
	{
		// adjust tempo to given bpm
		params->tempoDelta = (params->goalBPM / bpmValue - 1.0f) * 100.0f;
		//printf("The file will be converted to %.1f BPM\n\n", params->goalBPM);
	}
}

extern "C" {

	int sound_touch(int reset, int samplerate, int channels, int size, int *sizeout, char *inbuffer, char *outbuffer, int tempoDelta, int pitchDelta, int rateDelta)
	{

		static SoundTouch SoundTouch;

		// Parse command line parameters

		// Setup the 'SoundTouch' object for processing the sound
		{

			static int gsamplerate=0;
			static int gchannels=0;
			static int gtempoDelta=0;
			static int gpitchDelta=0;
			static int grateDelta=0;

			if((gsamplerate!=samplerate)||(gchannels!=channels)||(gtempoDelta!=tempoDelta)
			   ||(gpitchDelta!=pitchDelta)||(grateDelta!=rateDelta))
			{

				setup(&SoundTouch, samplerate,channels,tempoDelta,pitchDelta,rateDelta);

				grateDelta=rateDelta;
				gpitchDelta=pitchDelta;
				gtempoDelta=tempoDelta;
				gchannels=channels;
				gsamplerate=samplerate;
			}
		}
		// Process the sound
		process(reset,&SoundTouch,channels, inbuffer, outbuffer, size, sizeout);

		// Close WAV file handles & dispose of the objects

		return 0;
	}

}

