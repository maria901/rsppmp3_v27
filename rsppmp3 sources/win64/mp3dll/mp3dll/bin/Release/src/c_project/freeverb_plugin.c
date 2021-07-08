
// Freeverb port to XMMS.
// v0.01
//
// by Matthew Stewart-Smith
// 21/02/2001, Odemar

/*
    <C/C++ source code of the support dlls>
    Copyright (C) <2021>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
	and GNU LESSER GENERAL PUBLIC LICENSE along with this program.
	If not, see <http://www.gnu.org/licenses/>.

    support: http://nomade.sourceforge.net

	direct programmers e-mails:
	MathMan: arsoftware25@gmail.com
	Amanda : arsoftware10@gmail.com

	immediate contact(for a very fast answer) WhatsApp
	(+55)41 9627 1708 - it is always on
	
	We don´t charge for support

*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>

#undef NDEBUG
#include <assert.h>

#include "mv_from_be.h"

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

static void init (void);
static void cleanup (void);
static void about (void);
static void configure (void);

extern void do_reverb (float *, float *, float *, float *, long);
extern void set_reverb_params (float, float, float, float, float, float);

void
freeverbinit (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	mv_______->freeverb_plugin___notyet = 1;
	if (mv_______->freeverb_plugin___buffer_in_left)
	{
		free (mv_______->freeverb_plugin___buffer_in_left);
		mv_______->freeverb_plugin___buffer_in_left = NULL;
	}

	if (mv_______->freeverb_plugin___buffer_in_right)
	{
		free (mv_______->freeverb_plugin___buffer_in_right);
		mv_______->freeverb_plugin___buffer_in_right = NULL;
	}

	if (mv_______->freeverb_plugin___buffer_out_left)
	{
		free (mv_______->freeverb_plugin___buffer_out_left);
		mv_______->freeverb_plugin___buffer_out_left = NULL;
	}

	if (mv_______->freeverb_plugin___buffer_out_right)
	{
		free (mv_______->freeverb_plugin___buffer_out_right);
		mv_______->freeverb_plugin___buffer_out_right = NULL;
	}



	//roomsize_adjustment = 0.50;//gtk_adjustment_new(0.50, 0.0, 1.0, 0.05, 0.1, 0);

	/*damp_adjustment = gtk_adjustment_new(0.50, 0.0, 1.0, 0.05, 0.1, 0);
	   wet_adjustment = gtk_adjustment_new(0.25, 0.0, 1.0, 0.05, 0.1, 0);
	   dry_adjustment = gtk_adjustment_new(0.95, 0.0, 1.0, 0.05, 0.1, 0);
	   width_adjustment = gtk_adjustment_new(1.00, 0.0, 1.0, 0.05, 0.1, 0);
	   atten_adjustment = gtk_adjustment_new(0.65, 0.0, 1.0, 0.05, 0.1, 0);
	 */
}
int
freeverb (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int srate, int nch, int bits, int channels)
{
	int                        i;
	int no_samples = length >> 2;
	short *data = (short *)    d;
	float                      f;



	if (16 != bits)
	{

		return length;
	}

	if (2 != channels)
	{

		return length;

	}
	// Allocate float sample buffers if this hasn't already been done.
	if (mv_______->freeverb_plugin___buffer_in_left == NULL)
	{
		i = sizeof (float) * no_samples;
		mv_______->freeverb_plugin___buffer_in_left = (float *) malloc (i);
		mv_______->freeverb_plugin___buffer_in_right = (float *) malloc (i);
		mv_______->freeverb_plugin___buffer_out_left = (float *) malloc (i);
		mv_______->freeverb_plugin___buffer_out_right = (float *) malloc (i);
	}


	// Copy data into float input buffer.
	for (i = 0; i < no_samples; i++)
	{
		mv_______->freeverb_plugin___buffer_in_left[i] = ((float) data[i << 1]) * mv_______->freeverb_plugin___attenuation;
		mv_______->freeverb_plugin___buffer_in_right[i] = ((float) data[(i << 1) + 1]) * mv_______->freeverb_plugin___attenuation;
	}






	if (mv_______->freeverb_plugin___notyet)
	{
		int i;
		int b;

		float *left = NULL;
		float *right = NULL;
		float *out_left = NULL;
		float *out_right = NULL;


		i = sizeof (float) * no_samples;
		left = (float *) malloc (i);
		right = (float *) malloc (i);
		out_left = (float *) malloc (i);
		out_right = (float *) malloc (i);

		for (b = 0; b < no_samples; b++)
		{

			left[b] = 0.0;
			right[b] = 0.0;
			out_left[b] = 0.0;
			out_right[b] = 0.0;

		}



		do_reverb (left, right, out_left, out_right, no_samples);


		for (b = 0; b < no_samples; b++)
		{

			left[b] = 0.0;
			right[b] = 0.0;
			out_left[b] = 0.0;
			out_right[b] = 0.0;

		}



		do_reverb (left, right, out_left, out_right, no_samples);


		for (b = 0; b < no_samples; b++)
		{

			left[b] = 0.0;
			right[b] = 0.0;
			out_left[b] = 0.0;
			out_right[b] = 0.0;

		}



		do_reverb (left, right, out_left, out_right, no_samples);


		for (b = 0; b < no_samples; b++)
		{

			left[b] = 0.0;
			right[b] = 0.0;
			out_left[b] = 0.0;
			out_right[b] = 0.0;

		}



		do_reverb (left, right, out_left, out_right, no_samples);



		free (left);
		free (right);
		free (out_left);
		free (out_right);

		mv_______->freeverb_plugin___notyet = 0;
	}







	do_reverb (mv_______->freeverb_plugin___buffer_in_left, mv_______->freeverb_plugin___buffer_in_right,
	           mv_______->freeverb_plugin___buffer_out_left, mv_______->freeverb_plugin___buffer_out_right, no_samples);

	// Extract data from float output buffer.
	for (i = 0; i < no_samples; i++)
	{
		// Clip to max/min value if overflow/underflow occurs
		// to reduce audible artifacts resulting from values outside
		// representable range.

		f = mv_______->freeverb_plugin___buffer_out_left[i];
		if (f > 32767.0)
			data[i << 1] = 32767;
		else if (f < -32768.0)
			data[i << 1] = -32768;
		else
			data[i << 1] = f;
		f = mv_______->freeverb_plugin___buffer_out_right[i];
		if (f > 32767.0)
			data[(i << 1) + 1] = 32767;
		else if (f < -32768.0)
			data[(i << 1) + 1] = -32768;
		else
			data[(i << 1) + 1] = f;
	}
//assert(0);
	return length;
}
