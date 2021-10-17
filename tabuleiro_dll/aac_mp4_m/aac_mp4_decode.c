/* 28 Jun 2011 */
/*

   Our software is developed with the help of The TTL Data Book for Design Engineers - Second Edition. 1976

 */
/*
** FAAD2 - Freeware Advanced Audio (AAC) Decoder including SBR decoding
*/

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know
 *
 */
#define AMANDA__SIZE_w (32767)

#define AMANDA__SIZE_ww ((32767 * 2) + 2)

#ifdef _WIN64
#define __INT32_OR_INT64 __int64
#else
#define __INT32_OR_INT64 int
#endif // 2021 MathMan and amanda
#include <windows.h>
//#include   <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

#include <stdbool.h>

#include <process.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

#include <getopt.h>

#include <neaacdec.h>
#include <mp4ff.h>
#include "aac_decode_enums.h"
#include "audio.h"
WCHAR *__stdcall utf8towide(const char *pUTF8);

void pedro_dprintf(int amanda_level,
				   char *format, ...);

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

extern int written;

int method_is_internal_pcm = 1;

FILE *outfile;

/**
 * To make the path wide mode aware, stolen from libarchive
 *
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond...
 *
 */
wchar_t *
permissive_name_m_(const wchar_t *wname, WCHAR *ar_temp);
/**
 * To make the path wide mode aware, stolen from libarchive
 *
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond...
 *
 */
wchar_t *
permissive_name_m_(const wchar_t *wname, WCHAR *ar_temp)
{

	wchar_t *wnp = NULL;
	wchar_t *wn;
	wchar_t *ws, *wsp;
	DWORD len, slen;
	int unc;

	wnp = ar_temp;

	// wnp = malloc(AMANDA__SIZE * 2);

	wcscpy(wnp, wname);

	len = wcslen(wname);

	wn = wnp;

	if (wnp[0] == L'\\' && wnp[1] == L'\\' && // access to the wrong position in memory, fixed now
		wnp[2] == L'?' && wnp[3] == L'\\')
		/* We have already a permissive name. */
		return (wn);

	if (wnp[0] == L'\\' && wnp[1] == L'\\' &&
		wnp[2] == L'.' && wnp[3] == L'\\')
	{
		/* This is a device name */
		if (((wnp[4] >= L'a' && wnp[4] <= L'z') ||
			 (wnp[4] >= L'A' && wnp[4] <= L'Z')) &&
			wnp[5] == L':' && wnp[6] == L'\\')
			wnp[2] = L'?'; /* Not device name. */
		return (wn);
	}

	unc = 0;
	if (wnp[0] == L'\\' && wnp[1] == L'\\' && wnp[2] != L'\\')
	{
		wchar_t *p = &wnp[2];

		/* Skip server-name letters. */
		while (*p != L'\\' && *p != L'\0')
			++p;
		if (*p == L'\\')
		{
			wchar_t *rp = ++p;
			/* Skip share-name letters. */
			while (*p != L'\\' && *p != L'\0')
				++p;
			if (*p == L'\\' && p != rp)
			{
				/* Now, match patterns such as
				 * "\\server-name\share-name\" */
				wnp += 2;
				len -= 2;
				unc = 1;
			}
		}
	}

	slen = 4 + (unc * 4) + len + 1;
	ws = wsp = malloc(slen * sizeof(wchar_t));
	if (ws == NULL)
	{
		// free(wn);
		return (NULL);
	}
	/* prepend "\\?\" */
	wcsncpy(wsp, L"\\\\?\\", 4);
	wsp += 4;
	slen -= 4;
	if (unc)
	{
		/* append "UNC\" ---> "\\?\UNC\" */
		wcsncpy(wsp, L"UNC\\", 4);
		wsp += 4;
		slen -= 4;
	}
	wcsncpy(wsp, wnp, slen);
	wsp[slen - 1] = L'\0'; /* Ensure null termination. */
	// free(wn);

	wcscpy(wnp, ws);

	free(ws);

	return (wnp);
}

WCHAR *amanda_utf8towide_1_(char *pUTF8, WCHAR *ar_temp);

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we
 *  . provide two functions that are exactly the same because someone may
 * use it in multi-thread code
 *
 * @param pUTF8 the input utf-8 encoded filename
 *
 * @return the static allocated WCHAR array with the filename as wide string
 *
 */
WCHAR *amanda_utf8towide_1_(char *pUTF8, WCHAR *ar_temp)
{
	WCHAR *ricardo_k = ar_temp;

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, AMANDA__SIZE_w);
	return ricardo_k;
}
#define BucaneiroMin(a, b) ((a) < (b) ? (a) : (b))

enum morcego_decoder_constants
{

	BE_INITIAL_STATE,
	BE_DECODED,
	BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE,
	BE_ERROR_DURING_DECODE,
	BE_DECODER_NOT_LOADED,

};

enum Amanda_Command
{

	KOCI_INIT__ = 1001,
	KOCI_PROCESS__,
	KOCI_FINISH__,

};
enum Amanda_Status
{

	PEREIRA_HAS_DATA = 1002,
	PEREIRA_NO_MORE_DATA,

};

enum decoder_id_maria
{
	AMANDA_OPUS__ = 1001,
	AMANDA_OGG_VORBIS,
	AMANDA_MP4_AAC,
};

typedef struct pedro_27_
{
	int64_t duracao_feline;
	int64_t raw_total_ric;
	int64_t sample_rate_v;
	int64_t channels_p;
	char media_description_m[1024];
} juliete_struct;

typedef struct pedro_k_
{
	char *vf;
	char *filename_utf_8_m;
	int *error_code_aline_;
	int current_decoder_pedro;
	int current_bitrate_juliete;
	int the_andrea_command;
	int decoder_status_mislaine;
	int ret_m;
	int prev_li_j;
	int64_t bytes_in_the_buffer_paul;
	char buffer_junior[192000];
	char *ptr_data_position_douglas;
	juliete_struct dados_do_audio_ar;
	/*







	*/
	// for your pleasure...

	bool is_MP4_m;

	/*








	*/

} pedro_k;

#define VERSIONSTRING "OggDec 1.0\n"

// static int quiet = 0;
static const int bits = 16;

unsigned char headbuf[44]; /* The whole buffer */

#define WRITE_U32(buf, x)                               \
	*(buf) = (unsigned char)((x)&0xff);                 \
	*((buf) + 1) = (unsigned char)(((x) >> 8) & 0xff);  \
	*((buf) + 2) = (unsigned char)(((x) >> 16) & 0xff); \
	*((buf) + 3) = (unsigned char)(((x) >> 24) & 0xff);

#define WRITE_U16(buf, x)               \
	*(buf) = (unsigned char)((x)&0xff); \
	*((buf) + 1) = (unsigned char)(((x) >> 8) & 0xff);

/*
 * Some of this based on ao/src/ao_wav.c
 */
static int
write_prelim_header(FILE *out, int channels, int samplerate)
{

	int knownlength = 0;

	unsigned int size = 0x7fffffff;
	// int channels = 2;
	// int samplerate = 44100;
	int bytespersec = channels * samplerate * bits / 8;
	int align = channels * bits / 8;
	int samplesize = bits;

	if (knownlength)
		size = (unsigned int)knownlength;

	memcpy(headbuf, "RIFF", 4);
	WRITE_U32(headbuf + 4, size - 8);
	memcpy(headbuf + 8, "WAVE", 4);
	memcpy(headbuf + 12, "fmt ", 4);
	WRITE_U32(headbuf + 16, 16);
	WRITE_U16(headbuf + 20, 1); /* format */
	WRITE_U16(headbuf + 22, channels);
	WRITE_U32(headbuf + 24, samplerate);
	WRITE_U32(headbuf + 28, bytespersec);
	WRITE_U16(headbuf + 32, align);
	WRITE_U16(headbuf + 34, samplesize);
	memcpy(headbuf + 36, "data", 4);
	WRITE_U32(headbuf + 40, size - 44);

	if (fwrite(headbuf, 1, 44, out) != 44)
	{
		// printf ("ERROR: Failed to write wav header: %s\n", strerror (errno));
		return 1;
	}

	return 0;
}

static int
rewrite_header(FILE *out, unsigned int written)
{
	unsigned int length = written;

	length += 44;

	WRITE_U32(headbuf + 4, length - 8);
	WRITE_U32(headbuf + 40, length - 44);
	if (fseek(out, 0, SEEK_SET) != 0)
	{
		// printf ("ERROR: Failed to seek on seekable file: %s\n",
		// strerror (errno));
		return 1;
	}

	if (fwrite(headbuf, 1, 44, out) != 44)
	{
		// printf ("ERROR: Failed to write wav header: %s\n", strerror (errno));
		return 1;
	}
	return 0;
}

#define MAX_CHANNELS 6 /* make this higher to support files with \
					  more channels */

extern int errno_18_27;

extern int is_decoding;

void dprintf(const char *format, ...);
int allocate_the_memory_23_06_2011(
	double seconds,
	int rate,
	int channels);
extern int bytes_available;

int aac_decoder_status = 0;

static int quiet = 0;

int aac_percent = 0;
double aac_seconds = 0.0;
int aac_samplerate = 0;
int aac_channels = 0;
char aac_mode[300];
int aac_bitrate = 0;
static void faad_fprintf(FILE *stream, const char *fmt, ...)
{
	va_list ap;

	if (!quiet)
	{
		va_start(ap, fmt);

		vfprintf(stream, fmt, ap);

		va_end(ap);
	}
}

/* FAAD file buffering routines */
typedef struct
{
	long bytes_into_buffer;
	long bytes_consumed;
	long file_offset;
	unsigned char *buffer;
	int at_eof;
	FILE *infile;
} aac_buffer;

static int fill_buffer(aac_buffer *b)
{
	int bread;

	if (b->bytes_consumed > 0)
	{
		if (b->bytes_into_buffer)
		{
			memmove((void *)b->buffer, (void *)(b->buffer + b->bytes_consumed),
					b->bytes_into_buffer * sizeof(unsigned char));
		}

		if (!b->at_eof)
		{
			bread = fread((void *)(b->buffer + b->bytes_into_buffer), 1,
						  b->bytes_consumed, b->infile);

			if (bread != b->bytes_consumed)
				b->at_eof = 1;

			b->bytes_into_buffer += bread;
		}

		b->bytes_consumed = 0;

		if (b->bytes_into_buffer > 3)
		{
			if (memcmp(b->buffer, "TAG", 3) == 0)
				b->bytes_into_buffer = 0;
		}
		if (b->bytes_into_buffer > 11)
		{
			if (memcmp(b->buffer, "LYRICSBEGIN", 11) == 0)
				b->bytes_into_buffer = 0;
		}
		if (b->bytes_into_buffer > 8)
		{
			if (memcmp(b->buffer, "APETAGEX", 8) == 0)
				b->bytes_into_buffer = 0;
		}
	}

	return 1;
}

static void advance_buffer(aac_buffer *b, int bytes)
{
	b->file_offset += bytes;
	b->bytes_consumed = bytes;
	b->bytes_into_buffer -= bytes;
	if (b->bytes_into_buffer < 0)
		b->bytes_into_buffer = 0;
}

static int adts_sample_rates[] = {96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050, 16000, 12000, 11025, 8000, 7350, 0, 0, 0};

static int adts_parse(aac_buffer *b, int *bitrate, float *length)
{
	int frames, frame_length;
	int t_framelength = 0;
	int samplerate = 0;
	float frames_per_sec, bytes_per_frame;

	/* Read all frames to ensure correct time and bitrate */
	for (frames = 0; /* */; frames++)
	{
		fill_buffer(b);

		if (b->bytes_into_buffer > 7)
		{
			/* check syncword */
			if (!((b->buffer[0] == 0xFF) && ((b->buffer[1] & 0xF6) == 0xF0)))
				break;

			if (frames == 0)
				samplerate = adts_sample_rates[(b->buffer[2] & 0x3c) >> 2];

			frame_length = ((((unsigned int)b->buffer[3] & 0x3)) << 11) | (((unsigned int)b->buffer[4]) << 3) | (b->buffer[5] >> 5);

			t_framelength += frame_length;

			if (frame_length > b->bytes_into_buffer)
				break;

			advance_buffer(b, frame_length);
		}
		else
		{
			break;
		}
	}

	frames_per_sec = (float)samplerate / 1024.0f;
	if (frames != 0)
		bytes_per_frame = (float)t_framelength / (float)(frames * 1000);
	else
		bytes_per_frame = 0;
	*bitrate = (int)(8. * bytes_per_frame * frames_per_sec + 0.5);
	if (frames_per_sec != 0)
		*length = (float)frames / frames_per_sec;
	else
		*length = 1;

	return 1;
}

uint32_t read_callback(void *user_data, void *buffer, uint32_t length);

uint32_t read_callback(void *user_data, void *buffer, uint32_t length)
{
	return fread(buffer, 1, length, (FILE *)user_data);
}

uint32_t seek_callback(void *user_data, uint64_t position);

uint32_t seek_callback(void *user_data, uint64_t position)
{
	return fseek((FILE *)user_data, position, SEEK_SET);
}

/* MicroSoft channel definitions */
#define SPEAKER_FRONT_LEFT 0x1
#define SPEAKER_FRONT_RIGHT 0x2
#define SPEAKER_FRONT_CENTER 0x4
#define SPEAKER_LOW_FREQUENCY 0x8
#define SPEAKER_BACK_LEFT 0x10
#define SPEAKER_BACK_RIGHT 0x20
#define SPEAKER_FRONT_LEFT_OF_CENTER 0x40
#define SPEAKER_FRONT_RIGHT_OF_CENTER 0x80
#define SPEAKER_BACK_CENTER 0x100
#define SPEAKER_SIDE_LEFT 0x200
#define SPEAKER_SIDE_RIGHT 0x400
#define SPEAKER_TOP_CENTER 0x800
#define SPEAKER_TOP_FRONT_LEFT 0x1000
#define SPEAKER_TOP_FRONT_CENTER 0x2000
#define SPEAKER_TOP_FRONT_RIGHT 0x4000
#define SPEAKER_TOP_BACK_LEFT 0x8000
#define SPEAKER_TOP_BACK_CENTER 0x10000
#define SPEAKER_TOP_BACK_RIGHT 0x20000
#define SPEAKER_RESERVED 0x80000000

static long aacChannelConfig2wavexChannelMask(NeAACDecFrameInfo *hInfo)
{
	if (hInfo->channels == 6 && hInfo->num_lfe_channels)
	{
		return SPEAKER_FRONT_LEFT + SPEAKER_FRONT_RIGHT +
			   SPEAKER_FRONT_CENTER + SPEAKER_LOW_FREQUENCY +
			   SPEAKER_BACK_LEFT + SPEAKER_BACK_RIGHT;
	}
	else
	{
		return 0;
	}
}

static char *position2string(int position)
{
	switch (position)
	{
	case FRONT_CHANNEL_CENTER:
		return "Center front";
	case FRONT_CHANNEL_LEFT:
		return "Left front";
	case FRONT_CHANNEL_RIGHT:
		return "Right front";
	case SIDE_CHANNEL_LEFT:
		return "Left side";
	case SIDE_CHANNEL_RIGHT:
		return "Right side";
	case BACK_CHANNEL_LEFT:
		return "Left back";
	case BACK_CHANNEL_RIGHT:
		return "Right back";
	case BACK_CHANNEL_CENTER:
		return "Center back";
	case LFE_CHANNEL:
		return "LFE";
	case UNKNOWN_CHANNEL:
		return "Unknown";
	default:
		return "";
	}

	return "";
}

static void print_channel_info(NeAACDecFrameInfo *frameInfo)
{
	/* print some channel info */
	int i;
	long channelMask = aacChannelConfig2wavexChannelMask(frameInfo);

	faad_fprintf(stderr, "  ---------------------\n");
	if (frameInfo->num_lfe_channels > 0)
	{
		faad_fprintf(stderr, " | Config: %2d.%d Ch     |", frameInfo->channels - frameInfo->num_lfe_channels, frameInfo->num_lfe_channels);
	}
	else
	{
		faad_fprintf(stderr, " | Config: %2d Ch       |", frameInfo->channels);
	}
	if (channelMask)
		faad_fprintf(stderr, " WARNING: channels are reordered according to\n");
	else
		faad_fprintf(stderr, "\n");
	faad_fprintf(stderr, "  ---------------------");
	if (channelMask)
		faad_fprintf(stderr, "  MS defaults defined in WAVE_FORMAT_EXTENSIBLE\n");
	else
		faad_fprintf(stderr, "\n");
	faad_fprintf(stderr, " | Ch |    Position    |\n");
	faad_fprintf(stderr, "  ---------------------\n");
	for (i = 0; i < frameInfo->channels; i++)
	{
		faad_fprintf(stderr, " | %.2d | %-14s |\n", i, position2string((int)frameInfo->channel_position[i]));
	}
	faad_fprintf(stderr, "  ---------------------\n");
	faad_fprintf(stderr, "\n");
}

static int FindAdtsSRIndex(int sr)
{
	int i;

	for (i = 0; i < 16; i++)
	{
		if (sr == adts_sample_rates[i])
			return i;
	}
	return 16 - 1;
}

static unsigned char *MakeAdtsHeader(int *dataSize, NeAACDecFrameInfo *hInfo, int old_format)
{
	unsigned char *data;
	int profile = (hInfo->object_type - 1) & 0x3;
	int sr_index = ((hInfo->sbr == SBR_UPSAMPLED) || (hInfo->sbr == NO_SBR_UPSAMPLED)) ? FindAdtsSRIndex(hInfo->samplerate / 2) : FindAdtsSRIndex(hInfo->samplerate);
	int skip = (old_format) ? 8 : 7;
	int framesize = skip + hInfo->bytesconsumed;

	if (hInfo->header_type == ADTS)
		framesize -= skip;

	*dataSize = 7;

	data = malloc(*dataSize * sizeof(unsigned char));
	memset(data, 0, *dataSize * sizeof(unsigned char));

	data[0] += 0xFF; /* 8b: syncword */

	data[1] += 0xF0; /* 4b: syncword */
	/* 1b: mpeg id = 0 */
	/* 2b: layer = 0 */
	data[1] += 1; /* 1b: protection absent */

	data[2] += ((profile << 6) & 0xC0);	 /* 2b: profile */
	data[2] += ((sr_index << 2) & 0x3C); /* 4b: sampling_frequency_index */
	/* 1b: private = 0 */
	data[2] += ((hInfo->channels >> 2) & 0x1); /* 1b: channel_configuration */

	data[3] += ((hInfo->channels << 6) & 0xC0); /* 2b: channel_configuration */
	/* 1b: original */
	/* 1b: home */
	/* 1b: copyright_id */
	/* 1b: copyright_id_start */
	data[3] += ((framesize >> 11) & 0x3); /* 2b: aac_frame_length */

	data[4] += ((framesize >> 3) & 0xFF); /* 8b: aac_frame_length */

	data[5] += ((framesize << 5) & 0xE0); /* 3b: aac_frame_length */
	data[5] += ((0x7FF >> 6) & 0x1F);	  /* 5b: adts_buffer_fullness */

	data[6] += ((0x7FF << 2) & 0x3F); /* 6b: adts_buffer_fullness */
	/* 2b: num_raw_data_blocks */

	return data;
}

/* globals */
char *progName;

static const char __attribute__((unused)) * file_ext[] =
	{
		NULL,
		".wav",
		".aif",
		".au",
		".au",
		".pcm",
		NULL};

static void usage(void)
{
	faad_fprintf(stdout, "\nUsage:\n");
	faad_fprintf(stdout, "%s [options] infile.aac\n", progName);
	faad_fprintf(stdout, "Options:\n");
	faad_fprintf(stdout, " -h    Shows this help screen.\n");
	faad_fprintf(stdout, " -i    Shows info about the input file.\n");
	faad_fprintf(stdout, " -a X  Write MPEG-4 AAC ADTS output file.\n");
	faad_fprintf(stdout, " -t    Assume old ADTS format.\n");
	faad_fprintf(stdout, " -o X  Set output filename.\n");
	faad_fprintf(stdout, " -f X  Set output format. Valid values for X are:\n");
	faad_fprintf(stdout, "        1:  Microsoft WAV format (default).\n");
	faad_fprintf(stdout, "        2:  RAW PCM data.\n");
	faad_fprintf(stdout, " -b X  Set output sample format. Valid values for X are:\n");
	faad_fprintf(stdout, "        1:  16 bit PCM data (default).\n");
	faad_fprintf(stdout, "        2:  24 bit PCM data.\n");
	faad_fprintf(stdout, "        3:  32 bit PCM data.\n");
	faad_fprintf(stdout, "        4:  32 bit floating point data.\n");
	faad_fprintf(stdout, "        5:  64 bit floating point data.\n");
	faad_fprintf(stdout, " -s X  Force the samplerate to X (for RAW files).\n");
	faad_fprintf(stdout, " -l X  Set object type. Supported object types:\n");
	faad_fprintf(stdout, "        1:  Main object type.\n");
	faad_fprintf(stdout, "        2:  LC (Low Complexity) object type.\n");
	faad_fprintf(stdout, "        4:  LTP (Long Term Prediction) object type.\n");
	faad_fprintf(stdout, "        23: LD (Low Delay) object type.\n");
	faad_fprintf(stdout, " -d    Down matrix 5.1 to 2 channels\n");
	faad_fprintf(stdout, " -w    Write output to stdio instead of a file.\n");
	faad_fprintf(stdout, " -g    Disable gapless decoding.\n");
	faad_fprintf(stdout, " -q    Quiet - suppresses status messages.\n");
	faad_fprintf(stdout, "Example:\n");
	faad_fprintf(stdout, "       %s infile.aac\n", progName);
	faad_fprintf(stdout, "       %s infile.mp4\n", progName);
	faad_fprintf(stdout, "       %s -o outfile.wav infile.aac\n", progName);
	faad_fprintf(stdout, "       %s -w infile.aac > outfile.wav\n", progName);
	faad_fprintf(stdout, "       %s -a outfile.aac infile.aac\n", progName);
	return;
}

static int decodeAACfile(char *aacfile, char *sndfile, char *adts_fn, int to_stdout,
						 int def_srate, int object_type, int outputFormat, int fileType,
						 int downMatrix, int infoOnly, int adts_out, int old_format,
						 float *song_length)
{
	int tagsize;
	unsigned long samplerate = 0;
	unsigned char channels;
	void *sample_buffer;

	audio_file *aufile = NULL;

	FILE *adtsFile;
	unsigned char *adtsData;
	int adtsDataSize;

	NeAACDecHandle hDecoder;
	NeAACDecFrameInfo frameInfo;
	NeAACDecConfigurationPtr config;

	char percents[200];
	int percent, old_percent = -1;
	int bread, fileread;
	int header_type = 0;
	int bitrate = 0;
	float length = 0;

	int first_time = 1;

	aac_buffer b;
	(void)downMatrix;
	memset(&b, 0, sizeof(aac_buffer));

	if (adts_out)
	{
		adtsFile = fopen((adts_fn), "wb");
		if (adtsFile == NULL)
		{
			faad_fprintf(stderr, "Error opening file: %s\n", adts_fn);
			return 1;
		}
	}

	b.infile = fopen((aacfile), "rb");
	if (b.infile == NULL)
	{
		/* unable to open file */
		faad_fprintf(stderr, "Error opening file: %s\n", aacfile);
		return 11;
	}

	fseek(b.infile, 0, SEEK_END);
	fileread = ftell(b.infile);
	fseek(b.infile, 0, SEEK_SET);

	if (!(b.buffer = (unsigned char *)malloc(FAAD_MIN_STREAMSIZE * MAX_CHANNELS)))
	{
		faad_fprintf(stderr, "Memory allocation error\n");
		return 0;
	}
	memset(b.buffer, 0, FAAD_MIN_STREAMSIZE * MAX_CHANNELS);

	bread = fread(b.buffer, 1, FAAD_MIN_STREAMSIZE * MAX_CHANNELS, b.infile);
	b.bytes_into_buffer = bread;
	b.bytes_consumed = 0;
	b.file_offset = 0;

	if (bread != FAAD_MIN_STREAMSIZE * MAX_CHANNELS)
		b.at_eof = 1;

	tagsize = 0;
	if (!memcmp(b.buffer, "ID3", 3))
	{
		/* high bit is not used */
		tagsize = (b.buffer[6] << 21) | (b.buffer[7] << 14) |
				  (b.buffer[8] << 7) | (b.buffer[9] << 0);

		tagsize += 10;
		advance_buffer(&b, tagsize);
		fill_buffer(&b);
	}

	hDecoder = NeAACDecOpen();

	/* Set the default object type and samplerate */
	/* This is useful for RAW AAC files */
	config = NeAACDecGetCurrentConfiguration(hDecoder);
	if (def_srate)
		config->defSampleRate = def_srate;
	config->defObjectType = object_type;
	config->outputFormat = outputFormat;
	config->downMatrix = 1;
	config->useOldADTSFormat = old_format;
	// config->dontUpSampleImplicitSBR = 1;
	NeAACDecSetConfiguration(hDecoder, config);

	/* get AAC infos for printing */
	header_type = 0;
	if ((b.buffer[0] == 0xFF) && ((b.buffer[1] & 0xF6) == 0xF0))
	{
		adts_parse(&b, &bitrate, &length);
		fseek(b.infile, tagsize, SEEK_SET);

		bread = fread(b.buffer, 1, FAAD_MIN_STREAMSIZE * MAX_CHANNELS, b.infile);
		if (bread != FAAD_MIN_STREAMSIZE * MAX_CHANNELS)
			b.at_eof = 1;
		else
			b.at_eof = 0;
		b.bytes_into_buffer = bread;
		b.bytes_consumed = 0;
		b.file_offset = tagsize;

		header_type = 1;
	}
	else if (memcmp(b.buffer, "ADIF", 4) == 0)
	{
		int skip_size = (b.buffer[4] & 0x80) ? 9 : 0;
		bitrate = ((unsigned int)(b.buffer[4 + skip_size] & 0x0F) << 19) |
				  ((unsigned int)b.buffer[5 + skip_size] << 11) |
				  ((unsigned int)b.buffer[6 + skip_size] << 3) |
				  ((unsigned int)b.buffer[7 + skip_size] & 0xE0);

		length = (float)fileread;
		if (length != 0)
		{
			length = ((float)length * 8.f) / ((float)bitrate) + 0.5f;
		}

		bitrate = (int)((float)bitrate / 1000.0f + 0.5f);

		header_type = 2;
	}

	*song_length = length;

	fill_buffer(&b);
	if ((bread = NeAACDecInit(hDecoder, b.buffer,
							  b.bytes_into_buffer, &samplerate, &channels)) < 0)
	{
		/* If some error initializing occured, skip the file */
		printf("Error initializing decoder library.\n");
		if (b.buffer)
			free(b.buffer);
		NeAACDecClose(hDecoder);
		fclose(b.infile);
		return 20;
	}
	advance_buffer(&b, bread);
	fill_buffer(&b);

	/* print AAC file info */
	faad_fprintf(stderr, "%s file info:\n", aacfile);
	switch (header_type)
	{
	case 0:
		faad_fprintf(stderr, "RAW\n\n");
		break;
	case 1:
		faad_fprintf(stderr, "ADTS, %.3f sec, %d kbps, %d Hz\n\n",
					 length, bitrate, samplerate);
		strcpy(aac_mode, "ADTS");
		break;
	case 2:
		faad_fprintf(stderr, "ADIF, %.3f sec, %d kbps, %d Hz\n\n",
					 length, bitrate, samplerate);
		strcpy(aac_mode, "ADIF");
		break;
	}
	aac_seconds = length;
	aac_samplerate = samplerate;
	aac_channels = channels;
	aac_bitrate = bitrate;
	if (infoOnly)
	{
		NeAACDecClose(hDecoder);
		fclose(b.infile);
		if (b.buffer)
			free(b.buffer);
		return 0;
	}

	do
	{
		sample_buffer = NeAACDecDecode(hDecoder, &frameInfo,
									   b.buffer, b.bytes_into_buffer);

		if (adts_out == 1)
		{
			int skip = (old_format) ? 8 : 7;
			adtsData = MakeAdtsHeader(&adtsDataSize, &frameInfo, old_format);

			/* write the adts header */
			fwrite(adtsData, 1, adtsDataSize, adtsFile);

			/* write the frame data */
			if (frameInfo.header_type == ADTS)
				fwrite(b.buffer + skip, 1, frameInfo.bytesconsumed - skip, adtsFile);
			else
				fwrite(b.buffer, 1, frameInfo.bytesconsumed, adtsFile);
		}

		/* update buffer indices */
		advance_buffer(&b, frameInfo.bytesconsumed);

		if (frameInfo.error > 0)
		{
			faad_fprintf(stderr, "Error: %s\n",
						 NeAACDecGetErrorMessage(frameInfo.error));
		}

		/* open the sound file now that the number of channels are known */
		if (first_time && !frameInfo.error)
		{
			/* print some channel info */
			print_channel_info(&frameInfo);

			if (!adts_out)
			{
				/* open output file */
				if (!to_stdout)
				{

					/* estamos alterando aqui */

					write_prelim_header(outfile, frameInfo.channels, frameInfo.samplerate);

					aufile = open_audio_file(sndfile, frameInfo.samplerate, frameInfo.channels,
											 outputFormat, fileType, aacChannelConfig2wavexChannelMask(&frameInfo));
				}
				else
				{

					write_prelim_header(outfile, frameInfo.channels, frameInfo.samplerate);
					aufile = open_audio_file("-", frameInfo.samplerate, frameInfo.channels,
											 outputFormat, fileType, aacChannelConfig2wavexChannelMask(&frameInfo));
				}
				if (aufile == NULL)
				{
					if (b.buffer)
						free(b.buffer);
					NeAACDecClose(hDecoder);
					fclose(b.infile);
					return 0;
				}
			}
			else
			{
				faad_fprintf(stderr, "Writing output MPEG-4 AAC ADTS file.\n\n");
			}
			first_time = 0;
		}

		percent = min((int)(b.file_offset * 100) / fileread, 100);
		if (percent > old_percent)
		{
			old_percent = percent;
			sprintf(percents, "%d%% decoding %s.", percent, aacfile);
			faad_fprintf(stderr, "%s\r", percents);
#ifdef _WIN32
			SetConsoleTitle(percents);
#endif
		}

		if ((frameInfo.error == 0) && (frameInfo.samples > 0) && (!adts_out))
		{
			if (write_audio_file(aufile, sample_buffer, frameInfo.samples, 0) == 0)
				break;
		}

		/* fill buffer */
		fill_buffer(&b);

		if (b.bytes_into_buffer == 0)
			sample_buffer = NULL; /* to make sure it stops now */

	} while (sample_buffer != NULL);

	NeAACDecClose(hDecoder);

	if (adts_out == 1)
	{
		fclose(adtsFile);
	}

	fclose(b.infile);

	if (!first_time && !adts_out)
		close_audio_file(aufile);

	if (b.buffer)
		free(b.buffer);

	return frameInfo.error;
}

static int GetAACTrack(mp4ff_t *infile)
{
	/* find AAC track */
	int i, rc;
	int numTracks = mp4ff_total_tracks(infile);

	for (i = 0; i < numTracks; i++)
	{
		unsigned char *buff = NULL;
		int buff_size = 0;
		mp4AudioSpecificConfig mp4ASC;

		mp4ff_get_decoder_config(infile, i, &buff, (void *)&buff_size);

		if (buff)
		{
			rc = NeAACDecAudioSpecificConfig(buff, buff_size, &mp4ASC);
			free(buff);

			if (rc < 0)
				continue;
			return i;
		}
	}

	/* can't decode this */
	return -1;
}

static int decodeMP4file(pedro_k *feline_p, char *mp4file, char *sndfile, char *adts_fn, int to_stdout,
						 int outputFormat, int fileType, int downMatrix, int noGapless,
						 int infoOnly, int adts_out, float *song_length)
{
	int track;
	unsigned long samplerate = 0;
	unsigned char channels;
	void *sample_buffer;

	mp4ff_t *infile;
	long sampleId, numSamples;

	audio_file *aufile = NULL;

	FILE *mp4File;
	FILE *adtsFile;
	unsigned char *adtsData;
	int adtsDataSize;

	NeAACDecHandle hDecoder;
	NeAACDecConfigurationPtr config;
	NeAACDecFrameInfo frameInfo;
	mp4AudioSpecificConfig mp4ASC;

	unsigned char *buffer;
	int buffer_size;

	char percents[200];
	int percent, old_percent = -1;

	int first_time = 1;

	/* for gapless decoding */
	unsigned int useAacLength = 1;
	unsigned int initial = 1;
	unsigned int framesize;
	unsigned long timescale;

(void) feline_p;

	/* initialise the callback structure */
	mp4ff_callback_t *mp4cb = malloc(sizeof(mp4ff_callback_t));

	mp4File = fopen((mp4file), "rb");
	mp4cb->read = read_callback;
	mp4cb->seek = seek_callback;
	mp4cb->user_data = mp4File;

	hDecoder = NeAACDecOpen();

	/* Set configuration */
	config = NeAACDecGetCurrentConfiguration(hDecoder);
	config->outputFormat = outputFormat;
	config->downMatrix = 1;
	// config->dontUpSampleImplicitSBR = 1;
	NeAACDecSetConfiguration(hDecoder, config);

	(void)downMatrix;

	if (adts_out)
	{
		adtsFile = fopen((adts_fn), "wb");
		if (adtsFile == NULL)
		{
			faad_fprintf(stderr, "Error opening file: %s\n", adts_fn);
			return 1;
		}
	}

	infile = mp4ff_open_read(mp4cb);
	if (!infile)
	{
		/* unable to open file */
		faad_fprintf(stderr, "Error opening file: %s\n", mp4file);
		return 1;
	}

	if ((track = GetAACTrack(infile)) < 0)
	{
		faad_fprintf(stderr, "Unable to find correct AAC sound track in the MP4 file.\n");
		NeAACDecClose(hDecoder);
		mp4ff_close(infile);
		free(mp4cb);
		fclose(mp4File);
		return 1;
	}

	buffer = NULL;
	buffer_size = 0;
	mp4ff_get_decoder_config(infile, track, &buffer, (void *)&buffer_size);

	if (NeAACDecInit2(hDecoder, buffer, buffer_size,
					  &samplerate, &channels) < 0)
	{
		/* If some error initializing occured, skip the file */
		faad_fprintf(stderr, "Error initializing decoder library.\n");
		NeAACDecClose(hDecoder);
		mp4ff_close(infile);
		free(mp4cb);
		fclose(mp4File);
		return 1;
	}

	timescale = mp4ff_time_scale(infile, track);
	framesize = 1024;
	useAacLength = 0;

	if (buffer)
	{
		if (NeAACDecAudioSpecificConfig(buffer, buffer_size, &mp4ASC) >= 0)
		{
			if (mp4ASC.frameLengthFlag == 1)
				framesize = 960;
			if (mp4ASC.sbr_present_flag == 1)
				framesize *= 2;
		}
		free(buffer);
	}

	/* print some mp4 file info */
	faad_fprintf(stderr, "%s file info:\n\n", mp4file);
	{
		char *tag = NULL, *item = NULL;
		int k, j;
		char *ot[6] = {"NULL", "MAIN AAC", "LC AAC", "SSR AAC", "LTP AAC", "HE AAC"};
		long samples = mp4ff_num_samples(infile, track);
		float f = 1024.0;
		float seconds;
		if (mp4ASC.sbr_present_flag == 1)
		{
			f = f * 2.0;
		}
		seconds = (float)samples * (float)(f - 1.0) / (float)mp4ASC.samplingFrequency;

		*song_length = seconds;

		faad_fprintf(stderr, "%s\t%.3f secs, %d ch, %d Hz\n\n", ot[(mp4ASC.objectTypeIndex > 5) ? 0 : mp4ASC.objectTypeIndex],
					 seconds, mp4ASC.channelsConfiguration, mp4ASC.samplingFrequency);

		strcpy(aac_mode, ot[(mp4ASC.objectTypeIndex > 5) ? 0 : mp4ASC.objectTypeIndex]);
		aac_seconds = seconds;
		aac_samplerate = mp4ASC.samplingFrequency;
		aac_channels = mp4ASC.channelsConfiguration;
		aac_bitrate = 0;
#define PRINT_MP4_METADATA
#ifdef PRINT_MP4_METADATA
		j = mp4ff_meta_get_num_items(infile);
		for (k = 0; k < j; k++)
		{
			if (mp4ff_meta_get_by_index(infile, k, &item, &tag))
			{
				if (item != NULL && tag != NULL)
				{
					faad_fprintf(stderr, "%s: %s\n", item, tag);
					free(item);
					item = NULL;
					free(tag);
					tag = NULL;
				}
			}
		}
		if (j > 0)
			faad_fprintf(stderr, "\n");
#endif
	}

	if (infoOnly)
	{
		NeAACDecClose(hDecoder);
		mp4ff_close(infile);
		free(mp4cb);
		fclose(mp4File);
		return 0;
	}

	numSamples = mp4ff_num_samples(infile, track);

	for (sampleId = 0; sampleId < numSamples; sampleId++)
	{
		int rc;
		long dur;
		unsigned int sample_count;
		unsigned int delay = 0;

		/* get acces unit from MP4 file */
		buffer = NULL;
		buffer_size = 0;

		dur = mp4ff_get_sample_duration(infile, track, sampleId);
		rc = mp4ff_read_sample(infile, track, sampleId, &buffer, (void *)&buffer_size);
		if (rc == 0)
		{
			faad_fprintf(stderr, "Reading from MP4 file failed.\n");
			NeAACDecClose(hDecoder);
			mp4ff_close(infile);
			free(mp4cb);
			fclose(mp4File);
			return 1;
		}

		sample_buffer = NeAACDecDecode(hDecoder, &frameInfo, buffer, buffer_size);

		if (adts_out == 1)
		{
			adtsData = MakeAdtsHeader(&adtsDataSize, &frameInfo, 0);

			/* write the adts header */
			fwrite(adtsData, 1, adtsDataSize, adtsFile);

			fwrite(buffer, 1, frameInfo.bytesconsumed, adtsFile);
		}

		if (buffer)
			free(buffer);

		if (!noGapless)
		{
			if (sampleId == 0)
				dur = 0;

			if (useAacLength || (timescale != samplerate))
			{
				sample_count = frameInfo.samples;
			}
			else
			{
				sample_count = (unsigned int)(dur * frameInfo.channels);
				if (sample_count > frameInfo.samples)
					sample_count = frameInfo.samples;

				if (!useAacLength && !initial && (sampleId < numSamples / 2) && (sample_count != frameInfo.samples))
				{
					faad_fprintf(stderr, "MP4 seems to have incorrect frame duration, using values from AAC data.\n");
					useAacLength = 1;
					sample_count = frameInfo.samples;
				}
			}

			if (initial && (sample_count < framesize * frameInfo.channels) && (frameInfo.samples > sample_count))
				delay = frameInfo.samples - sample_count;
		}
		else
		{
			sample_count = frameInfo.samples;
		}

		/* open the sound file now that the number of channels are known */
		if (first_time && !frameInfo.error)
		{
			/* print some channel info */
			print_channel_info(&frameInfo);

			if (!adts_out)
			{
				/* open output file */
				if (!to_stdout)
				{

					write_prelim_header(outfile, frameInfo.channels, frameInfo.samplerate);

					aufile = open_audio_file(sndfile, frameInfo.samplerate, frameInfo.channels,
											 outputFormat, fileType, aacChannelConfig2wavexChannelMask(&frameInfo));
				}
				else
				{
#ifdef _WIN32
					setmode(fileno(stdout), O_BINARY);
#endif
					aufile = open_audio_file("-", frameInfo.samplerate, frameInfo.channels,
											 outputFormat, fileType, aacChannelConfig2wavexChannelMask(&frameInfo));

					write_prelim_header(outfile, frameInfo.channels, frameInfo.samplerate);
				}
				if (aufile == NULL)
				{
					NeAACDecClose(hDecoder);
					mp4ff_close(infile);
					free(mp4cb);
					fclose(mp4File);
					return 0;
				}
			}
			first_time = 0;
		}

		if (sample_count > 0)
			initial = 0;

		percent = min((int)(sampleId * 100) / numSamples, 100);

		aac_percent = percent;

		if (percent > old_percent)
		{
			old_percent = percent;
			sprintf(percents, "%d%% decoding %s.", percent, mp4file);
			faad_fprintf(stderr, "%s\r", percents);
#ifdef _WIN32
			SetConsoleTitle(percents);
#endif
		}

		if ((frameInfo.error == 0) && (sample_count > 0) && (!adts_out))
		{
			if (write_audio_file(aufile, sample_buffer, sample_count, delay) == 0)
				break;
		}

		if (frameInfo.error > 0)
		{
			faad_fprintf(stderr, "Warning: %s\n",
						 NeAACDecGetErrorMessage(frameInfo.error));
		}
	}

	NeAACDecClose(hDecoder);

	if (adts_out == 1)
	{
		fclose(adtsFile);
	}

	mp4ff_close(infile);

	if (!first_time && !adts_out)
		close_audio_file(aufile);

	free(mp4cb);
	fclose(mp4File);

	return frameInfo.error;
}
int the_info_only = 0;

int the_aac_decoder(int argc, char *argv[], pedro_k *feline_p);

int the_aac_decoder(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[], pedro_k *feline_p)
{
	int result;
	int infoOnly = 0;
	int writeToStdio = 0;
	int object_type = LC;
	int def_srate = 0;
	int downMatrix = 0;
	int format = 1;
	int outputFormat = FAAD_FMT_16BIT;
	// int outfile_set = 1;
	int adts_out = 0;
	int old_format = 0;
	int mp4file = 0;
	int noGapless = 0;

	static char adtsFileName[AMANDA__SIZE];
	unsigned char header[8] = {0};
	float length = 0;
	FILE *hMP4File;

	/* System dependant types */

	(void)argc;

	outputFormat = FAAD_FMT_16BIT; /* just use default */

	if (KOCI_INIT__ == feline_p->the_andrea_command)
	{
		feline_p->ptr_data_position_douglas = feline_p->buffer_junior;

		feline_p->bytes_in_the_buffer_paul = 0;
		; // do nothing it is ok...

		feline_p->is_MP4_m = 0;
	}

	if (KOCI_PROCESS__ == feline_p->the_andrea_command)
	{
		goto entering_position_in_the_code_m;
	}

	if (KOCI_FINISH__ == feline_p->the_andrea_command)
	{
		goto entering_position_in_the_code_m;
	}

	/* check for mp4 file */
	mp4file = 0;
	{
		WCHAR *temp_a = malloc(AMANDA__SIZE_ww);
		WCHAR *temp_a2 = malloc(AMANDA__SIZE_ww);
		hMP4File = _wfopen(permissive_name_m_(amanda_utf8towide_1_(feline_p->filename_utf_8_m, temp_a), temp_a2), L"rb");
		free(temp_a);
		free(temp_a2);
	}
	if (!hMP4File)
	{
		pedro_dprintf(0, "cannot open %s my love...\n", feline_p->filename_utf_8_m);
		*feline_p->error_code_aline_ = 10003; // if cannot open
		return 30;
	}

	fread(header, 1, 8, hMP4File);
	fclose(hMP4File);

	if (header[4] == 'f' && header[5] == 't' && header[6] == 'y' && header[7] == 'p')
		mp4file = 1;

	feline_p->is_MP4_m = mp4file;

entering_position_in_the_code_m:;

	//pedro_dprintf(0, "file is mp4 ? %d\n", mp4file);

	if (0 == 1)
	{
		goto entering_position_in_the_code_m;
	}

	if (feline_p->is_MP4_m)
	{
		pedro_dprintf(0, "vai chamar mp4\n");

		exit(27);
		result = decodeMP4file(feline_p, feline_p->filename_utf_8_m, "nul", adtsFileName, writeToStdio,
							   outputFormat, format, downMatrix, noGapless, infoOnly, adts_out, &length);
	}
	else
	{
		pedro_dprintf(0, "vai chamar aac\n");

		exit(27);
		result = decodeAACfile(feline_p->filename_utf_8_m, "nul", adtsFileName, writeToStdio,
							   def_srate, object_type, outputFormat, format, downMatrix, infoOnly, adts_out,
							   old_format, &length);
	}

	return result;
}
int decode_aac_file(pedro_k *feline_p);

int decode_aac_file(pedro_k *feline_p)
{
	// int ret;
	/*
	char *arguments[5];

	arguments[0] = "rsp_aac_decoder.exe";
	arguments[1] = "-o";
	arguments[2] = out_filename;
	arguments[3] = in_filename;
*/
	the_aac_decoder(0, NULL, feline_p);

	return -1994;
}

int aac_mp4_decode_file_28_june_2011_08_46_am_real_decode(pedro_k *feline_p,
														  double *seconds_,
														  int *channels_,
														  int *samplerate_,
														  int only_retrieve_info,
														  char *media_description,
														  int *bitrate);

int aac_mp4_decode_file_28_june_2011_08_46_am_real_decode(pedro_k *feline_p,
														  double *seconds_,
														  int *channels_,
														  int *samplerate_,
														  int only_retrieve_info,
														  char *media_description,
														  int *bitrate)
{
	int ret;

	the_info_only = 0;
	ret = decode_aac_file(feline_p);

	*bitrate = aac_bitrate;
	*channels_ = aac_channels;
	*samplerate_ = aac_samplerate;
	*seconds_ = aac_seconds;
	strcpy(media_description, aac_mode);
	(void)only_retrieve_info;
	return ret;
}
/*
int aac_mp4_decode_file_28_june_2011_08_46_am(char *infile,
											  double *seconds_,
											  int *channels_,
											  int *samplerate_,
											  int only_retrieve_info,
											  char *media_description,
											  int *bitrate);

int aac_mp4_decode_file_28_june_2011_08_46_am(char *infile,
											  double *seconds_,
											  int *channels_,
											  int *samplerate_,
											  int only_retrieve_info,
											  char *media_description,
											  int *bitrate)
{
	int ret;

	the_info_only = 1;
	ret = decode_aac_file(
		infile,
		"");

	*bitrate = aac_bitrate;
	*channels_ = aac_channels;
	*samplerate_ = aac_samplerate;
	*seconds_ = aac_seconds;
	strcpy(media_description, aac_mode);
	(void)only_retrieve_info;
	return ret;
}
*/
#include "win64.h"
/*
		aac_mp4_decode_file_28_june_2011_08_46_am_real_decode (
				in_filename,
				&seconds_,
				&channels_,
				&samplerate_,
				0,
				temp,
				&bitrate);
 */

int uncompress_aac_mp4(pedro_k *feline_p); // char *inputfile, char *outputwav);

int uncompress_aac_mp4(pedro_k *feline_p) // ok Amanda
{
	double seconds;
	int channels;
	int samplerate = 0;

	char media_description[300];
	int bitrate;
	int ret;
	written = 0;

	ret = aac_mp4_decode_file_28_june_2011_08_46_am_real_decode(
		feline_p,
		&seconds,
		&channels,
		&samplerate,
		0,
		media_description,
		&bitrate);

	return ret;
}
/*
int main()

{
	int retval;

	retval = uncompress_aac_mp4("C:\\Users\\User\\Downloads\\Dua Lipa - Secrets (Lyrics).juliete4", "test_k.wav");

	printf("return value %d\n", retval);

	return 0;
}
*/
BOOL WINAPI DllMain(__attribute__((unused)) HINSTANCE hModule,
					__attribute__((unused)) DWORD ul_reason_for_call,
					__attribute__((unused)) LPVOID lpReserved);
BOOL WINAPI DllMain(__attribute__((unused)) HINSTANCE hModule,
					__attribute__((unused)) DWORD ul_reason_for_call,
					__attribute__((unused)) LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString("svc MP4/AAC DLL Interface "
						  " - DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__
						  ") \n");
		break;
	case DLL_THREAD_ATTACH:

		break;
	case DLL_THREAD_DETACH:

		break;
	case DLL_PROCESS_DETACH:

		break;
	}
	return TRUE;
}

char *__stdcall svc_init_mp4_m(char *filename_utf_8_v,
							   int *error_code_aline_,
							   juliete_struct *dados_m);
int __stdcall morcego_decode_libav_svc_process_mp4_m(__attribute__((unused)) char *struct_opus_m,
													 __attribute__((unused)) int bytes_to_decode_m,
													 __attribute__((unused)) char *bufout_m,
													 __attribute__((unused)) int *size_out);

void __stdcall svc_seek_mp4_m(__attribute__((unused)) char *struct_opus_m,
							  __attribute__((unused)) double maquisistem_value);

void morcego_deinit_libav_svc_deinit_mp4_m(char *struct_opus_m);

char *__stdcall svc_init_mp4_m(__attribute__((unused)) char *filename_utf_8_v,
							   __attribute__((unused)) int *error_code_aline_,
							   __attribute__((unused)) juliete_struct *dados_m)
{
	// hacked at 15:24 17/oct/2021 by Amanda husband...
	/*




	for your pleasure...




	*/

	// first of all the initialization on Opus DLL,

	char *ptr_shinkal;
	(void)ptr_shinkal;
	/*
	(void)OV_CALLBACKS_STREAMONLY_NOCLOSE;
	(void)OV_CALLBACKS_STREAMONLY;
	(void)OV_CALLBACKS_NOCLOSE;
	(void)OV_CALLBACKS_DEFAULT;*/

	pedro_dprintf(0, "svc_init_mp4_m\n");
	pedro_k *feline_p = calloc(sizeof(pedro_k), 1);
	// assert(0);
	if (NULL == feline_p)
	{
		*error_code_aline_ = 10001; // Cannot allocate memory
		return NULL;
	}
	feline_p->current_decoder_pedro = AMANDA_MP4_AAC;
	feline_p->error_code_aline_ = error_code_aline_;
	assert(feline_p->error_code_aline_);
	feline_p->filename_utf_8_m = calloc(AMANDA__SIZE, 1);

	strcpy(feline_p->filename_utf_8_m, filename_utf_8_v);

	*feline_p->error_code_aline_ = 0;
	feline_p->the_andrea_command = KOCI_INIT__;

	uncompress_aac_mp4(feline_p);
	/*
		 ogg_decode_file_shinkal("jota.ogg",

	#ifdef WIN64
								 "carlinhos.wav",
	#else
								 "edson.wav",
	#endif

								 &seconds_,
								 &channels_,
								 &samplerate_,
								 media_description,
								 &out_bitrate,
								 feline_p);*/
	// main_old_p(feline_p);

	pedro_dprintf(0, "pode continuar amor...\n");
	assert(error_code_aline_);
	assert(feline_p);
	assert(feline_p->error_code_aline_);
	exit(27);
	if (10004 == *feline_p->error_code_aline_)
	{
		pedro_dprintf(0, "arquivo nao é MP4/AAC\n");

		return (char *)feline_p;
	}

	// if opus
	// feline_p->dados_do_audio_ar.sample_rate_v = 48000;
	// feline_p->dados_do_audio_ar.channels_p = 2;

	pedro_dprintf(0, "return from call %d", *feline_p->error_code_aline_);

	*dados_m = feline_p->dados_do_audio_ar;

	pedro_dprintf(0, "data -> %lld\n", dados_m->duracao_feline);

	if (0 == *feline_p->error_code_aline_)
	{
		return (char *)feline_p;
	}
	else
	{
		// any other error is fatal...
		free(feline_p->filename_utf_8_m);
		free(feline_p);

		return NULL;
	}
}
int __stdcall morcego_decode_libav_svc_process_mp4_m(__attribute__((unused)) char *struct_opus_m,
													 __attribute__((unused)) int bytes_to_decode_m,
													 __attribute__((unused)) char *bufout_m,
													 __attribute__((unused)) int *size_out)
{
	return -27;
}
void __stdcall svc_seek_mp4_m(__attribute__((unused)) char *struct_opus_m,
							  __attribute__((unused)) double maquisistem_value)
{
	return;
}

void morcego_deinit_libav_svc_deinit_mp4_m(__attribute__((unused)) char *struct_opus_m)
{
	return;
}