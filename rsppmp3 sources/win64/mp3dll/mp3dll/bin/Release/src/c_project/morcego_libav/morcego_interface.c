
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://arsoftware.net.br/binarywork_____________________       *
 *     Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/       *
 *              http: //nomade.sourceforge.net/binarywork_______________/       *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     Ricardinho:    arsoftware25@gmail.com    ricardo@arsoftware.net.br       *
 *     Koci______:    arsoftware10@gmail.com    am_koci@arsoftware.net.br       *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

#include /* amanda's smart ape */   <windows.h>
#include /* amanda's smart ape  */   <stdint.h>
#include /* amanda's smart ape   */   <stdio.h>
#include /* amanda's smart ape  */   <stdlib.h>
#include /* amanda's smart ape  */   <string.h>
#include /* amanda's smart ape    */   <time.h>
#include /* amanda's smart ape   */   <errno.h>
#include /* amanda's smart ape   */   <fcntl.h>
#include /* amanda's smart ape   */   <ctype.h>
#include /* amanda's smart ape    */   <math.h>
#include /* amanda's smart ape  */   <wctype.h>
#include /* amanda's smart ape   */   <wchar.h>
#include /* amanda's smart ape  */   <stdarg.h>
#include /* amanda's smart ape  */   <stddef.h>
#include /* amanda's smart ape  */   <setjmp.h>
#include /* amanda's smart ape  */   <locale.h>
#include /* amanda's smart ape  */   <signal.h>
#include /* amanda's smart ape  */   <limits.h>
#include /* amanda's smart ape   */   <float.h>
#include /* amanda's smart ape  */   <iso646.h>

#undef NDEBUG
#include /* amanda's smart ape  */   <assert.h>
#include /* amanda's smart ape */   <stdbool.h>
#include /* amanda's smart ape */   <process.h>

#include <ffms.h>
#include <objbase.h>

#include "../win64.h"
#include "../mv_from_be.h"
#include "definitive_header.h"
#include "be_constants.h"

char *get_checksum_for_filename(char *file);
__int64 rsp64(__int64 rsp64, int len, char buffer__[]);
void set_this_thread_to_idle_17_55_23_june_2011(void);
__int64 _ftelli64_arab(FILE *stream);
int _fseeki64_arab(FILE *stream, __int64 offset, int origin);
__int64 getfilesize(char *infile);
static void
mprintf(char *format, ...);
__int64 _ftelli64_arab(FILE *stream);
int _fseeki64_arab(FILE *stream, __int64 offset, int origin);
WCHAR *__stdcall utf8towide(const char *pUTF8);
extern short __cdecl invertbits16(short value);
extern int __cdecl invertbits32(int value);
__int64
id3v2tag(char *filename);
extern __int64 __cdecl getfilesize(char *infile);
int decode_mad_MP3(char *, int, char *, int, int *, int *);

#include "audio.h"
#define BucaneiroMin(a, b) ((a) < (b) ? (a) : (b))

#define BUCANEIROSIZE 6000

/** Simple function to retrieve the bitrate
 */
int get_morcego_bitrate(
	char *file,
	double seconds)
{
	double a;
	int size;
	double sizeb;
	size = getfilesize(file);
	sizeb = (double)size;
	a = sizeb / seconds;
	a = a / 125.0; // magic value my love...
	return (int)a;
}

int strip_extension_alladin(char *data, char *ext);

static int convert_multiples_channels_to_2(morcego___i___instance__a__bucaneiro_engineering *mv_______, int len, char *sample_buffer,
										   int channels);
/**
 * It will get the percentage based on the slice
 */
static double
getporf(double maxa, double fatiaa)
{
	if (maxa == 0 || fatiaa == 0)
	{
		return 0;
	}
	maxa = ((double)100.0 / maxa * fatiaa);
	return maxa;
}
/**
 * it will retrieve the percentage based on the slice over the maximum value (100/(max/slice))
 */
static __int64
getpor__int64(double maxa_, double fatiaa_)
{
	//fix for negative values when got time.
	double maxa = maxa_;
	double fatiaa = fatiaa_;
	if (maxa == 0 || fatiaa == 0)
	{
		return 0;
	}
	maxa = ((double)100 / maxa * fatiaa);
	return (__int64)maxa;
}

/**
 * Retrieve the value based in the percentage
 */
double getval_100(double max, double por)
{

	// a formula aqui Ã©
	// max / 100 * por

	double maxa;
	double porr;

	maxa = (double)max;
	porr = (double)por;

	maxa = (maxa / 100.0) * porr;

	return maxa;
}

/**
 * Retrieve the value based in the 10000 slice
 */
__int64 getval_10000(__int64 max, __int64 por)
{

	// a formula aqui Ã©
	// max / 100 * por

	double maxa;
	double porr;

	maxa = (double)max;
	porr = (double)por;

	maxa = (maxa / 10000.0) * porr;

	return (__int64)maxa;
}
/**
 * It will print a message box with printf arguments
 */
static void
mprintf(char *format, ...)
{
	/* void *calloc(size_t nelem, size_t size); */
	char *buffer2 = calloc(1, 10000); //for
									  //multithread sake
	va_list args;
	va_start(args, format);
	vsprintf(buffer2, format, args);

	MessageBox(0, buffer2, "Error",
			   MB_OK | MB_ICONINFORMATION |
				   MB_SYSTEMMODAL);
	free(buffer2);
}
/**
 *     It is the flag to see whether the com support was
 *     already initiated, not in use anymore of course
 *     because we are in 2021
 */
const int com_inited = 0; //this variable will be here forever, donÂ´t remove it
/**
 * This function makes the required initialization
 *
 */
static int
init()
{
	//this empty function I will not remove, because it
	//remembers me of ffms2.dll, we have some good reasons
	//to dont use ffms2.dll anymore
	return 0;
}
void dprintf_z(const char *format, ...);

/**
 *     It will convert the input data that can be any kind of samples to 16 bits ready to play and save data
 */
int convert_pcm_data(morcego___i___instance__a__bucaneiro_engineering *mv_______, int len, char *buffer_, int bits, int format, int channels)
{
	short *morcego_sample_short = (short *)mv_______->morcego_interface_c___morcego_temp;
	int i;
	switch (bits)
	{
	case 8:
		for (i = 0; i < len; i++)
		{
			unsigned char a;
			int e;
			a = (unsigned char)buffer_[i];
			e = a;
			e -= 127;
			e *= 256;
			if (e > 32767)
			{
				e = 32767;
			}
			if (e < -32768)
			{
				e = -32768;
			}

			e = e > 32767 ? 32767 : e < -32768 ? -32768
											   : e; //you need to read it twice to understand what it does

			morcego_sample_short[i] = (short)e;
		}
		memcpy(buffer_, morcego_sample_short, len * 2);
		len = convert_multiples_channels_to_2(mv_______, len * 2, buffer_, channels);
		return len;
		break;
	case 16:
		len = convert_multiples_channels_to_2(mv_______, len, buffer_, channels);
		return len;
		break;
	case 24:
		return len;
		break;
	case 32:
		switch (format)
		{
		case FFMS_FMT_S32:
		{
			int outsample = 0;
			short outval;
			int *ptr;
			char temp[4];
			ptr = (int *)temp;
			for (i = 0; i < len; i += 4)
			{

				temp[0] = buffer_[i];
				temp[1] = buffer_[i + 1];
				temp[2] = buffer_[i + 2];
				temp[3] = buffer_[i + 3];

				*ptr = *ptr >> 16;

				*ptr = *ptr > 32767 ? 32767 : *ptr < -32768 ? -32768
															: *ptr;

				outval = (short)*ptr;

				morcego_sample_short[outsample++] = outval;
			}
			memcpy(buffer_, morcego_sample_short, outsample * 2);
			len = convert_multiples_channels_to_2(mv_______, outsample * 2, buffer_, channels);
			return len;
		}
		break;
		case FFMS_FMT_FLT:
		{
			{
				int outsample = 0;
				short outval;
				float *ptr;
				char temp[4];
				ptr = (float *)temp;
				for (i = 0; i < len; i += 4)
				{

					temp[0] = buffer_[i];
					temp[1] = buffer_[i + 1];
					temp[2] = buffer_[i + 2];
					temp[3] = buffer_[i + 3];

					*ptr = 32767.0 * *ptr;

					*ptr = *ptr > 32767 ? 32767 : *ptr < -32787 ? -32787
																: *ptr;

					outval = (short)*ptr;

					morcego_sample_short[outsample++] = outval;
				}
				memcpy(buffer_, morcego_sample_short, outsample * 2);
				len = convert_multiples_channels_to_2(mv_______, outsample * 2, buffer_, channels);
				return len;
			}
			break;

		default:
			return len;
		}
		break;
		}
		return len;
		break;

	default:

		return len;
		break;
	}

	return len;
}

/** This function was not tested with a 4 6 or 8 channels media file yet, it will convert multiples channels samples to 2 or 1 channel
 *
 */
static int
convert_multiples_channels_to_2(morcego___i___instance__a__bucaneiro_engineering *mv_______, int len, char *sample_buffer, int channels)
{
	short *samples_in = (short *)sample_buffer;

	int i;

	int samples = 0;

	if (channels < 3)
	{
		return len;
	}
	if (channels == 4)
	{
		len = len / 2;
		for (i = 0; i < len; i += 4)
		{
			mv_______->morcego_interface_c___short_temp[samples++] = samples_in[i];
			mv_______->morcego_interface_c___short_temp[samples++] = samples_in[i + 1];
		}

		memcpy(sample_buffer, mv_______->morcego_interface_c___short_temp, samples * 2);

		return samples * 2;
	}
	if (channels == 6)
	{
		len = len / 2;
		for (i = 0; i < len; i += 6)
		{
			mv_______->morcego_interface_c___short_temp[samples++] = samples_in[i];
			mv_______->morcego_interface_c___short_temp[samples++] = samples_in[i + 1];
		}

		memcpy(sample_buffer, mv_______->morcego_interface_c___short_temp, samples * 2);

		return samples * 2;
	}
	if (channels == 8)
	{
		len = len / 2;
		for (i = 0; i < len; i += 8)
		{
			mv_______->morcego_interface_c___short_temp[samples++] = samples_in[i];
			mv_______->morcego_interface_c___short_temp[samples++] = samples_in[i + 1];
		}

		memcpy(sample_buffer, mv_______->morcego_interface_c___short_temp, samples * 2);

		return samples * 2;
	}
	assert(0 && "number of channels not equal 4, 6 or 8");
	exit(1);
}
const int is_mp3 = 0;
void set_debug_value(int val);

/**
 *     It will initiate the decoder library
   \param morcego_is_mp3 This will define if the file will play as a mp3, if 0 it will detect te media type
 */
int morcego_init_libav(morcego___i___instance__a__bucaneiro_engineering *mv_______, be_libav_struct *be_data, int morcego_is_mp3)
{
	int returnvalue = 0;
	mv_______->libav_c___amanda_s_smart_ape__is_open = true;
	
	init();
	pedro_dprintf(-1, "morcego_init_libav                          b");
	if (mv_______->morcego_interface_c___decoder_in_use)
	{
		strcpy(be_data->be_error_message, "Decoder is in use");
		returnvalue = 1;
		goto saida;
	}
	mv_______->morcego_interface_c___seek = -1;
	mv_______->morcego_interface_c___decoder_in_use = 1;
	mv_______->morcego_interface_c___decoder_state = BE_STATE_DECODING;

	mv_______->morcego_interface_c___buffer_address = mv_______->morcego_interface_c___internal_buffer;
	mv_______->morcego_interface_c___bytes_available_in_buffer = 0;
	mv_______->libav_c___pixel_format = 1000;
	strcpy(be_data->be_error_message, "");

	pedro_dprintf(-1, "dentro de morcego_init_libav");

	{

		int ret;
		pedro_dprintf(-1, "morcego_init_libav c");
		if ((ret = init_decoder2(mv_______, be_data)))
		{
			{
				char savemessage[1024];
				strcpy(savemessage,
					   be_data->be_error_message);

				if (30 == ret)
				{
					goto pula;
				}

			pula:;
				strcpy(be_data->be_error_message,
					   savemessage);
			}
			returnvalue = 2;
			goto saida;
		}
		pedro_dprintf(-1, "morcego_init_libav d");
		pedro_dprintf(-1,
					  "passou de init_decoder2");

		mv_______->morcego_interface_c___adjusted_bps =
			be_data->be_bits_per_sample;
		if (24 == be_data->be_bits_per_sample)
		{

			mv_______->morcego_interface_c___adjusted_bps =
				32;
			assert(FFMS_FMT_S32 == be_data->sample_format);
		}

		if (2 == be_data->be_channels)
		{
			strcpy(be_data->be_mode,
				   "normal LR stereo");
		}
		if (1 == be_data->be_channels)
		{
			strcpy(be_data->be_mode,
				   "single channel");
		}
		if (4 == be_data->be_channels)
		{
			strcpy(be_data->be_mode, "4 channels");
		}
		if (6 == be_data->be_channels)
		{
			strcpy(be_data->be_mode, "6 channels");
		}
		if (8 == be_data->be_channels)
		{
			strcpy(be_data->be_mode, "8 channels");
		}
		double size_of_data;

		if (be_data->be_channels > 2)
		{
			size_of_data =
				be_data->be_seconds * 2 * (double)be_data->be_samplerate *
				(double)mv_______->morcego_interface_c___adjusted_bps / 8.0;
		}
		else
		{
			size_of_data =
				be_data->be_seconds * be_data->be_channels * (double)be_data->be_samplerate *
				(double)mv_______->morcego_interface_c___adjusted_bps / 8.0;
		}
		be_data->be_size_of_pcm_data = (__int64)size_of_data;
		//("passou 2");
		if (be_data->be_samplerate < 8000 || be_data->be_samplerate > 96000)
		{

			strcpy(be_data->be_error_message, "Invalid sample rate");
			returnvalue = 7;
			goto saida;
		}

		if (be_data->be_bits_per_sample < 8 || be_data->be_bits_per_sample > 64)
		{
			strcpy(be_data->be_error_message, "Invalid bits per sample value");
			returnvalue = 8;
			goto saida;
		}

		{

			mv_______->morcego_interface_c___after_conversion_size = 0;
			mv_______->morcego_interface_c___tamanhodecadafatia = 0;
			mv_______->morcego_interface_c___restante = 0;
			mv_______->morcego_interface_c___tamanho = 0;

			mv_______->morcego_interface_c___tamanhodecadafatia = (mv_______->morcego_interface_c___adjusted_bps / 8) * be_data->be_channels;

			if (1 != be_data->be_channels && 2 != be_data->be_channels && 4 != be_data->be_channels && 6 != be_data->be_channels && 8 != be_data->be_channels)
			{
				strcpy(be_data->be_error_message,
					   "Only support to 1, 2, 4, 5.1 or 7.1 channels (output to 2 channels) available at this moment");
				returnvalue = 9;
				goto saida;
			}

			if (64 == be_data->be_bits_per_sample)
			{
				strcpy(be_data->be_error_message,
					   "Cannot play 64 bits audio for the moment");
				returnvalue = 11;
				goto saida;
			}
		saida:;
			if (returnvalue)
			{
				morcego_deinit_libav(mv_______);
			}
			pedro_dprintf(-1, "morcego_init_libav f");

			return returnvalue;
		}
	}
}
/**
 * This is the function to decode to pcm 16 bits
 */
int morcego_decode_libav(morcego___i___instance__a__bucaneiro_engineering *mv_______, int bytes_to_decode, char *bufout, int *size_out)
{

	be_libav_struct *be_copy;
	if (mv_______->be_for_wav_convert)
	{
		be_copy = (be_libav_struct *)mv_______->be_for_wav_convert;
	}
	else
		be_copy = (be_libav_struct *)mv_______->be_real;

	int size_out_b;

	int bytes = 0;

	int returnvalue;

	int bytespegos = 0;

	if (0 == mv_______->morcego_interface_c___decoder_in_use)
	{

		return BE_DECODER_NOT_LOADED;
	}

	assert(bytes_to_decode);

	assert(bytes_to_decode < 1000000);

	*size_out = 0;

	if (-1 != mv_______->morcego_interface_c___seek)
	{

		if (0 == is_mp3)
		{

			mv_______->morcego_interface_c___bytes_available_in_buffer = 0;
			mv_______->morcego_interface_c___buffer_address = mv_______->morcego_interface_c___internal_buffer;

			seek2(mv_______, mv_______->morcego_interface_c___seek);
			mv_______->morcego_interface_c___seek = -1;
			mv_______->morcego_interface_c___decoder_state = BE_STATE_DECODING;
		}
	}

again:;
	if (mv_______->morcego_interface_c___bytes_available_in_buffer)
	{

		int fatia_copiada;
		fatia_copiada =
			BucaneiroMin(bytes_to_decode, mv_______->morcego_interface_c___bytes_available_in_buffer);

		memcpy(bufout, mv_______->morcego_interface_c___buffer_address, fatia_copiada);

		mv_______->morcego_interface_c___buffer_address += fatia_copiada;

		bytes += fatia_copiada;

		bufout += fatia_copiada;
		bytes_to_decode -= fatia_copiada;
		mv_______->morcego_interface_c___bytes_available_in_buffer -= fatia_copiada;

		if (0 == mv_______->morcego_interface_c___bytes_available_in_buffer)
		{
			mv_______->morcego_interface_c___buffer_address = mv_______->morcego_interface_c___internal_buffer;
		}

		*size_out += fatia_copiada;
		bytespegos += fatia_copiada;
		if (0 == bytes_to_decode)
		{
			pedro_dprintf(-1, " BE_DECODED %d", *size_out);

			return BE_DECODED;
		}
	}

	if (BE_STATE_NO_MORE_SAMPLES == mv_______->morcego_interface_c___decoder_state)
	{
		pedro_dprintf(-1, " BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE %d", *size_out);
		return BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE;
	}

	if (mv_______->morcego_interface_c___bytes_available_in_buffer)
	{
		goto again;
	}

	while (1)
	{
		returnvalue = BE_DECODED;

		decode2(mv_______, mv_______->morcego_interface_c___buffer, &size_out_b);

		mv_______->morcego_interface_c___restante = size_out_b;

		mv_______->morcego_interface_c___after_conversion_size =
			convert_pcm_data(
				mv_______, size_out_b, mv_______->morcego_interface_c___buffer,
				/*mv_______->morcego_interface_c___adjusted_bps this is a hac to force 16 bits because the decoder always convert all audio formats to 16 bits*/ 16, be_copy->sample_format, be_copy->be_channels);

		memcpy(mv_______->morcego_interface_c___buffer_address, mv_______->morcego_interface_c___buffer, mv_______->morcego_interface_c___after_conversion_size);
		mv_______->morcego_interface_c___bytes_available_in_buffer += mv_______->morcego_interface_c___after_conversion_size;

		if (!mv_______->morcego_interface_c___restante)
		{
			mv_______->morcego_interface_c___decoder_state = BE_STATE_NO_MORE_SAMPLES;
			goto again;
			break;
		}
		mv_______->morcego_interface_c___decoder_state = BE_STATE_DECODING;
		goto again;
	}

	return returnvalue;
}
/**
 * It will free the memory used and files opened
 */
void morcego_deinit_libav(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	mv_______->morcego_interface_c___decoder_in_use = 0;
	deinit2(mv_______);

	//("deinit");
	mv_______->libav_c___amanda_s_smart_ape__is_open = false;

	return;
}

void get_wav_progress_information(morcego___i___instance__a__bucaneiro_engineering *mv_______, int *por, int *ret, int *fin, char *message_)
{
	*por = mv_______->morcego_interface_c___porcentagem;
	*ret = mv_______->morcego_interface_c___returnvalue_wav;
	*fin = mv_______->morcego_interface_c___finished_wav;
	strcpy(message_, mv_______->morcego_interface_c___message___);
}

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we
 * provide two functions that are exactly the same because someone may
 * use it in multi-thread code
 *
 * @param pUTF8 the input utf-8 encoded filename
 *
 * @return the static allocated WCHAR array with the filename as wide string
 *
 */
WCHAR * amanda_utf8towide_1_(char *pUTF8)
{
	static WCHAR ricardo_k[1024];

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, 1024);
	return ricardo_k;
}

/**
 * To get the file size, filename is utf-8
 *
 * @param infile_ar the input file
 *
 * @return the size of the file or -1 in case of error or if the file is empty, if you need
 * to know whether the file do exist use ispathfile function
 *
 */
int64_t
getfilesize_ar_amanda_s_smart_ape(char *infile_ar)
{
	__int64 ret;
	FILE *myfile;

	if ((myfile = _wfopen(amanda_utf8towide_1_(infile_ar), L"rb")) == NULL)
	{
		return -1;
	}
	ret = _fseeki64(myfile, 0, SEEK_END);
	ret = _ftelli64(myfile);
	fclose(myfile);
	return ret;
}

/**
 * It will extract the media file to wav
 */
int morcego_extract_wav(morcego___i___instance__a__bucaneiro_engineering *mv_______, char *filename_amanda_s_smart_ape, char *out_wav_file, int wav_mode,
						int track)
{

#define FAAD_FMT_16BIT 1
#define FAAD_FMT_24BIT 2
#define FAAD_FMT_32BIT 3
#define FAAD_FMT_FLOAT 4

	
	__int64            processed   =                                                               0;
	//int64_t            file_size_
	audio_file *       wav_stream  =                                                            NULL;
	char               int_buffer  [4096                                                           ];
	char               signature_amanda_s_smart_ape[MAXPATH_UTF_8_MODE_AMANDA_S_SMART_APE ] = { 0, };
	double             amanda_s_smart_ape_timestamp                                                 ;
	int                ret_amanda_s_smart_ape                                                       ;
	int                returnvalue =                                                               0;
	int                size_out                                                                     ;
	long long          generated_size_amanda_s_smart_ape                           =               0;

	__attribute((unused)) enum amanda_s_smart_ape_webm_commands webm_commands_amanda_s_smart_ape                                                                ;
	be_libav_struct *  be = (be_libav_struct *)mv_______->be_ptr                                    ;

	if (5 == wav_mode)
	{
		mprintf("64 bits FLOAT not implemented yet, moving to 32 bits FLOAT");
		wav_mode = FAAD_FMT_FLOAT;
	}

	memset(be, 0, sizeof(be_libav_struct));

	strcpy(be->sourcefile, filename_amanda_s_smart_ape);

	be->track_to_play_or_decode = track;

	mv_______->be_for_wav_convert = (void *)be;

	if (morcego_init_libav(mv_______, be, 0))
	{
		strcpy(mv_______->morcego_interface_c___message___, be->be_error_message);
		returnvalue = 1;
		goto saida_amanda_s_smart_ape;
	}
	
	if (false == mv_______->libav_c___amanda_s_smart_ape_is_new_webm)
	{
		goto saida_amanda_s_smart_ape;
	}

	{

		//vamos la, tem que fazer oque, tem que pagar o tamanho do arquivo e nome e criar uma entrada, voce nao vai ver mesmo entao nao tem problema

		amanda_s_smart_ape_timestamp = get_bucaneiro_tick();

		sprintf(signature_amanda_s_smart_ape, "Amanda_27_Ricardo_51_%lld_%d_%s", getfilesize_ar_amanda_s_smart_ape(filename_amanda_s_smart_ape),
				rsp32_file_amanda_s_smart_ape(filename_amanda_s_smart_ape),
				filename_amanda_s_smart_ape);

		amanda_s_smart_ape_timestamp = get_bucaneiro_tick() - amanda_s_smart_ape_timestamp;

		

		pedro_dprintf(0, "amor a string %s\n", signature_amanda_s_smart_ape);

		//exit(27);
	}

	{

		//agora se nao tiver salva

		if (true == amanda_s_smart_ape_query_webm_and_normalization(signature_amanda_s_smart_ape, mv_______->libav_c___webm________________amanda_s_smart_ape,
																	mv_______->libav_c___normalization_mode__amanda_s_smart_ape, mv_______->libav_c___normalization_value_amanda_s_smart_ape, mv_______->libav_c___normalization_valu2_amanda_s_smart_ape, mv_______->libav_c___normalization_valu3_amanda_s_smart_ape, &mv_______->libav_c___has_an_entry))
		{
			pedro_dprintf(0, "Deu certo meu amor...agora vou cagar melhor kkkkkk\n");

			pedro_dprintf(0, "webm .%s.\n", mv_______->libav_c___webm________________amanda_s_smart_ape);
			pedro_dprintf(0, "normalization_mode  .%s.\n", mv_______->libav_c___normalization_mode__amanda_s_smart_ape);
			pedro_dprintf(0, "normalization_value .%s.\n", mv_______->libav_c___normalization_value_amanda_s_smart_ape);
			pedro_dprintf(0, "normalization_valu2 .%s.\n", mv_______->libav_c___normalization_valu2_amanda_s_smart_ape);
			pedro_dprintf(0, "normalization_valu3 .%s.\n", mv_______->libav_c___normalization_valu3_amanda_s_smart_ape);
			/*
			pedro_dprintf(0, "webm .%s.\n", webm________________amanda_s_smart_ape);
			pedro_dprintf(0, "webm .%s.\n", webm________________amanda_s_smart_ape);
			*/

			pedro_dprintf(0, "enabled cache? %d\n", (int) mv_______->libav_c___amanda_s_smart_ape_use_cache);

			pedro_dprintf(0, "Tem itens %d\n", (int)mv_______->libav_c___has_an_entry);

			if('\0' == mv_______->libav_c___webm________________amanda_s_smart_ape[0])
			{
				pedro_dprintf(0, "Não tem webm data salva, simplesmente isso\n");
			}
			else
			{
				pedro_dprintf(0, "!Tem webm data salva, simplesmente isso\n");
			}

		}
	}

	if (false == mv_______->libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true)
	{

		wav_stream =
			open_audio_file(out_wav_file, be->be_samplerate, be->be_channels, wav_mode,
							1, 0);

		if (NULL == wav_stream)
		{
			//strcpy (be_error_message, "Cannot open outputfile to write");
			strcpy(mv_______->morcego_interface_c___message___, "Cannot open outputfile to write");
			returnvalue = 2; //se dois deu erro
			goto saida_amanda_s_smart_ape;
		};
	}

again:;
	//
	int por;
	mv_______->morcego_interface_c___percent = getpor__int64(be->be_size_of_pcm_data, processed);
	por = (int)mv_______->morcego_interface_c___percent;
	if (por >= 100)
		por = 99;
	if (por < 0)
		por = 0;

	mv_______->morcego_interface_c___porcentagem = por;

	ret_amanda_s_smart_ape = morcego_decode_libav(mv_______, sizeof(int_buffer), int_buffer, &size_out);

	processed += size_out;

	if (BE_ERROR_DURING_DECODE == ret_amanda_s_smart_ape)
	{
		returnvalue = 3;
		strcpy(mv_______->morcego_interface_c___message___, be->be_error_message);
		//strcpy (be_error_message, be_copy->be_error_message);
		goto saida_amanda_s_smart_ape;
	}
	if (BE_DECODED == ret_amanda_s_smart_ape || BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE == ret_amanda_s_smart_ape)
	{

		int size = size_out;
		char *out = int_buffer;
		if (0 == size_out)
		{
			goto saida_amanda_s_smart_ape;
		}
		switch (wav_mode)
		{
		case FAAD_FMT_16BIT:

		if(-1 == mv_______->libav_c___amanda_s_smart_ape_new_generated_duration)
		{
generated_size_amanda_s_smart_ape += size_out;
		}

			if (false == mv_______->libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true)
			{
				if (write_audio_file(wav_stream, out, size / 2, 0) == 0)
				{
					;
					//strcpy (be_error_message, "Error on the wav write function");
					strcpy(mv_______->morcego_interface_c___message___, "Error on the wav write function");
					//strcpy(mv_______->morcego_interface_c___message___, be_copy->be_error_message);
					returnvalue = 4;
					goto saida_amanda_s_smart_ape;
				}
			}
			break;
		case FAAD_FMT_24BIT:
		{
			long *data = malloc(size * 4 + 1);
			int i;
			short *datashort = (short *)out;
			if (size)
			{
				for (i = 0; i < size / 2; i++)
				{
					data[i] = datashort[i] * 256;
				}

				if (-1 == mv_______->libav_c___amanda_s_smart_ape_new_generated_duration)
				{
					generated_size_amanda_s_smart_ape += size;
				}

				if (false == mv_______->libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true)
				{
					if (write_audio_file(wav_stream, (void *)data, size / 2, 0) == 0)
					{
						strcpy(mv_______->morcego_interface_c___message___,
							   "Error on the wav write function");
						returnvalue = 4;
						free(data);
						goto saida_amanda_s_smart_ape;
					}
				}
			}
			free(data);
		}
		break;
		case FAAD_FMT_32BIT:
		{
			long *data = malloc(size * 4 + 1); //long
			int i;
			short *datashort = (short *)out;
			if (size)
			{
				for (i = 0; i < size / 2; i++)
				{
					int tam = datashort[i];
					data[i] = tam * (256 * 256);
				}

				if (-1 == mv_______->libav_c___amanda_s_smart_ape_new_generated_duration)
				{
					generated_size_amanda_s_smart_ape += size;
				}

				if (false == mv_______->libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true)
				{
					if (write_audio_file(wav_stream, (void *)data, size / 2, 0) == 0)
					{
						strcpy(mv_______->morcego_interface_c___message___,
							   "Error on the wav write function");
						free(data);
						returnvalue = 4;
						goto saida_amanda_s_smart_ape;
					}
				}
			}
			free(data);
		}
		break;
		case FAAD_FMT_FLOAT:
		{
			float *data = malloc(size * 4 + 1);
			int i;
			short *datashort = (short *)out;
			if (size)
			{
				for (i = 0; i < size / 2; i++)
				{
					data[i] = (float)datashort[i] / 32767;
					if (data[i] > 1.0)
					{
						data[i] = 1.0;
					}
					if (data[i] < -1.0)
					{
						data[i] = -1.0;
					}
				}
				
				if (-1 == mv_______->libav_c___amanda_s_smart_ape_new_generated_duration)
				{
					generated_size_amanda_s_smart_ape += size;
				}

				if (false == mv_______->libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true)
				{
					if (write_audio_file(wav_stream, (void *)data, size / 2, 0) == 0)
					{
						strcpy(mv_______->morcego_interface_c___message___,
							   "Error on the wav write function");
						free(data);
						returnvalue = 4;
						goto saida_amanda_s_smart_ape;
					}
				}
			}
			free(data);
		}
		break;
		default:

			break;
		}

		if (size_out)
		{
			goto again;
		}
	}

saida_amanda_s_smart_ape:

	if (false == mv_______->libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true)
	{
		if (wav_stream)
			close_audio_file(wav_stream);
	}
	mv_______->morcego_interface_c___decoder_in_use = 0;
	morcego_deinit_libav(mv_______);

	mv_______->morcego_interface_c___porcentagem = 100;
	mv_______->morcego_interface_c___returnvalue_wav = returnvalue;
	mv_______->morcego_interface_c___finished_wav = 1;

	mv_______->be_for_wav_convert = NULL;

	if (-1 == mv_______->libav_c___amanda_s_smart_ape_new_generated_duration) //uma coisa por vez...
	{
		mv_______->libav_c___amanda_s_smart_ape_new_generated_duration = generated_size_amanda_s_smart_ape;

		mv_______->libav_c___amanda_s_smart_ape_new_generated_duration =

			((double)(mv_______->libav_c___amanda_s_smart_ape_new_generated_duration) / (double)(be->be_samplerate) / (double)be->be_channels) / 2. * 1000000.0;

		//pensei que fosse serio...

		if (mv_______->libav_c___amanda_s_smart_ape_use_cache)
		{
			//save... se nao estiver carregado, checa se tem o item ou nao
			if (mv_______->libav_c___has_an_entry)
			{
				pedro_dprintf(0, "webm - will update it anyway...\n");
				//update
			}
			else
			{		

				pedro_dprintf(0, "webm - will create an entry for webm...\n");

				assert(strlen(signature_amanda_s_smart_ape));

				sprintf(mv_______->libav_c___webm________________amanda_s_smart_ape, "%lld", mv_______->libav_c___amanda_s_smart_ape_new_generated_duration);

				mv_______->libav_c___normalization_value_amanda_s_smart_ape[0] = '\0';

				mv_______->libav_c___normalization_valu2_amanda_s_smart_ape[0] = 0x0;

				mv_______->libav_c___normalization_valu3_amanda_s_smart_ape[0] = 0b0;

			if(amanda_s_smart_ape_add_entry(signature_amanda_s_smart_ape, mv_______->libav_c___webm________________amanda_s_smart_ape, mv_______->libav_c___normalization_value_amanda_s_smart_ape, mv_______->libav_c___normalization_valu2_amanda_s_smart_ape,
			mv_______->libav_c___normalization_valu3_amanda_s_smart_ape))
			{
					pedro_dprintf(0, "adicionou a entrada amor\n");
			}
			//here, por parts...
			//ja passa os 4...

			//vamos...
			}
		}
	}
	mv_______->libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true = false;

	//for historical reasons...

	return returnvalue;
}
/**
 * It will mv_______->morcego_interface_c___seek based in percentage
 */
void morcego_seek_100_libav(morcego___i___instance__a__bucaneiro_engineering *mv_______, double valor)
{
	be_libav_struct *be_copy;
	if (mv_______->be_for_wav_convert)
	{
		be_copy = (be_libav_struct *)mv_______->be_for_wav_convert;
	}
	else
		be_copy = (be_libav_struct *)mv_______->be_real;

	if (mv_______->morcego_interface_c___decoder_in_use)
	{
		double ret;
		if (0 == is_mp3)
		{
			mv_______->morcego_interface_c___seek = valor; //ready
		}
		else
		{
			ret = getval_100(be_copy->mp3_sizeofdata, valor);
			if (ret >= be_copy->mp3_sizeofdata)
			{
				ret = be_copy->mp3_sizeofdata;
			}
			//ret--;
			ret--;
			if (ret < 0)
			{
				ret = 0;
			}
			mv_______->morcego_interface_c___seek = ret;
			mv_______->morcego_interface_c___seek += be_copy->mp3_adjust;
		}
	}
}
/**
 * The version of the ffms2.dll interface
 */
char *
get_morcego_interface_version(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	return MORCEGO_VERSION;
}
/**
 * This is the function that will call the extract to wav function
 */
static int __stdcall init_decoder(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	mv_______->morcego_interface_c___porcentagem = 0;
	mv_______->morcego_interface_c___returnvalue_wav = 0;
	mv_______->morcego_interface_c___finished_wav = 0;

	set_this_thread_to_idle_17_55_23_june_2011();
	morcego_extract_wav(mv_______, mv_______->morcego_interface_c___filename_, mv_______->morcego_interface_c___out_wav_file_, mv_______->morcego_interface_c___wav_mode_,
						mv_______->morcego_interface_c___the_track);
	return 0;
}
/**
 * The function that will create the thread to decode
 */
static int __stdcall decode(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	HANDLE myhandle;
	__INT32_OR_INT64 ThreadId;
	myhandle = CreateThread(
		(LPSECURITY_ATTRIBUTES)0,
		0,
		(LPTHREAD_START_ROUTINE)init_decoder,
		(LPVOID)mv_______,
		0,
		(LPDWORD)&ThreadId);
	CloseHandle(myhandle);
	return 0;
}
/**
 * It will decode to wav with progress support
 */
void morcego_extract_wav_extended(
	morcego___i___instance__a__bucaneiro_engineering *mv_______,
	char *filename,
	char *out_wav_file,
	int wav_mode,
	int track)
{
	mv_______->morcego_interface_c___the_track = track; //tem que verificar isto mais tarde...
	strcpy(mv_______->morcego_interface_c___filename_, filename);
	strcpy(mv_______->morcego_interface_c___out_wav_file_, out_wav_file);
	mv_______->morcego_interface_c___wav_mode_ = wav_mode;
	decode(mv_______);
	return;
}
int get_number_of_audio_tracks(morcego___i___instance__a__bucaneiro_engineering *mv_______, char *utf8_filename, char *error_message)
{
	return get_number_of_audio_tracks_internal(mv_______, utf8_filename, error_message); //defined in libav.c
}
