

#include <windows.h>
#include <Mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>

int decode_mad_MP3 (char *bufmp3, int len, char *out, int outlimit,
                    int *outsize, int *large);

int Exit_mad_MP3 (void);

int Init_mad_MP3 (void);
/*These are the informations that you can gather
from an mp3 file using the madlib library
*/
extern int mad_force_exit;//do not use
extern int valid_xing;
extern int madsamplerate;//sample rate
extern int madlayer;//layer
extern int madchannel;//channels
extern int numberofframes;//the number of frames
extern char madmode[];
extern int madsample_per_frame;
extern int madbitrate;//the bitrate
extern double madmpegversion;//mpeg version
extern int mad_mp3_is_valid;


#define VERSIONSTRING "OggDec 1.0\n"

static int quiet = 0;
static int bits = 16;
static int endian = 0;
static int raw = 0;
static int sign = 1;
unsigned char headbuf[44];      /* The whole buffer */







#define WRITE_U32(buf, x) *(buf)     = (unsigned char)((x)&0xff); \
        *((buf)+1) = (unsigned char)(((x)>>8)&0xff); \
        *((buf)+2) = (unsigned char)(((x)>>16)&0xff); \
        *((buf)+3) = (unsigned char)(((x)>>24)&0xff);

#define WRITE_U16(buf, x) *(buf)     = (unsigned char)((x)&0xff); \
        *((buf)+1) = (unsigned char)(((x)>>8)&0xff);

/*
 * Some of this based on ao/src/ao_wav.c
 */
static int
write_prelim_header (FILE * out, int channels, int samplerate)
{

	int knownlength = 0;

	unsigned int size = 0x7fffffff;
	// int channels = 2;
	// int samplerate = 44100;
	int bytespersec = channels * samplerate * bits / 8;
	int align = channels * bits / 8;
	int samplesize = bits;

	if (knownlength)
		size = (unsigned int) knownlength;

	memcpy (headbuf, "RIFF", 4);
	WRITE_U32 (headbuf + 4, size - 8);
	memcpy (headbuf + 8, "WAVE", 4);
	memcpy (headbuf + 12, "fmt ", 4);
	WRITE_U32 (headbuf + 16, 16);
	WRITE_U16 (headbuf + 20, 1); /* format */
	WRITE_U16 (headbuf + 22, channels);
	WRITE_U32 (headbuf + 24, samplerate);
	WRITE_U32 (headbuf + 28, bytespersec);
	WRITE_U16 (headbuf + 32, align);
	WRITE_U16 (headbuf + 34, samplesize);
	memcpy (headbuf + 36, "data", 4);
	WRITE_U32 (headbuf + 40, size - 44);

	if (fwrite (headbuf, 1, 44, out) != 44)
	{
		//printf ("ERROR: Failed to write wav header: %s\n", strerror (errno));
		return 1;
	}

	return 0;
}

static int
rewrite_header (FILE * out, unsigned int written)
{
	unsigned int length = written;

	length += 44;

	WRITE_U32 (headbuf + 4, length - 8);
	WRITE_U32 (headbuf + 40, length - 44);
	if (fseek (out, 0, SEEK_SET) != 0)
	{
		//printf ("ERROR: Failed to seek on seekable file: %s\n",
		//strerror (errno));
		return 1;
	}

	if (fwrite (headbuf, 1, 44, out) != 44)
	{
		//printf ("ERROR: Failed to write wav header: %s\n", strerror (errno));
		return 1;
	}
	return 0;
}



int main(int argc, char**argv)
{

	FILE *myfile=NULL;
	FILE *outfile=NULL;
	static char bufmp3[100000];
	static char out[4608];
	int chaveador=0;
	int len=0;
	int large=1;
	int isize=0;
	int bytes=0;
	int init=0;
	Init_mad_MP3();
	if(2==argc)
	{

		myfile=fopen(argv[1],"rb");

		if(NULL==myfile)
		{
			printf("Error openning file %s\n", argv[1]);
			goto saida;
		}


		outfile=fopen("outfile.out.wav","wb");



retornamp3:
		;

		len = fread
		              (bufmp3,
		              sizeof
		              (char),
		              large,
		              myfile);

		{
			static int size =0;
			size+=len;
			printf("Reading...% d\n",size);
		}

		if (len <= 0 && 0 != large)
		{
			printf("End of stream\n");
			goto saida;
		}
processa:
		;
		chaveador
		        =
		                decode_mad_MP3
		                        (bufmp3,
		                        len,
		                        out,
		                        4608,
		                        &isize,
		                        &large);


	}
	if(0!=chaveador)
	{
		goto retornamp3;
	}
	printf("Processing...\n");
	
	
	if(0==init)
	{
	init++;
			if(outfile)
			write_prelim_header (outfile, madchannel, madsamplerate);
			
			assert(madchannel)
			;
			assert(madsamplerate);
	}
	
	if(outfile)
		bytes+=fwrite(out,1,isize,outfile);
	goto processa;

saida:
	;
	Exit_mad_MP3();
	if(myfile)
	{
		fclose(myfile);
	}
	if(outfile)
	{
		rewrite_header (outfile, bytes);
		fclose(outfile);
	}
	printf("End of execution\n");
	return 0;
}