
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
  
/*****************************************************************************
* This define will control the attenuation of the mix of 5.1 and 7.1 channels
******************************************************************************
* 1.0 for no attentuation, 0.5 for half of the level, make your tests...
*****************************************************************************/
#define AR_K_P_ATTENUATION_LEVEL 1.0

/*

   downmix information to be used:

   I believe downmixing a 5.1 PCM stream to stereo could be done something like this:

   L = clamp((FL + RL + C*0.708 + LFE*0.708) / 2)
   R = clamp((FR + RR + C*0.708 + LFE*0.708) / 2)
   You can refer e.g. to the downmix effect in Android for an example of this.

   Or just select two of the channels that you will keep (e.g. FL and FR) and skip past the samples from the other channels.

 */

#include <windows.h>
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

//com calma
#include "../mp3_dll/mv_from_be.h"
#include "../morcego/be_constants.h"

//#include "SDL\SDL.h"

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
//#include <libpostproc/postprocess.h>
#include <libavdevice/avdevice.h>
#include <libavfilter/avfilter.h>
#include <libavutil/avutil.h>
/////////////////////////////////////////////////////////////////////////////
//the main struct that holds the media information

/*

What is this?...

        AVCodecContext *video_pCodecCtx = NULL;

                SDL_LockYUVOverlay

   SDL_MapRGB

   SDL_UpdateRect

   SDL_SetVideoMode

   SDL_CreateYUVOverlay

   SDL_Event

 */

/////////////////////////////////////////////////////////////////////////////
extern morcego___i___instance__a__bucaneiro_engineering *copy;
int av_strstart(const char *str, const char *pfx, const char **ptr);
void
mprintf (char *format, ...);

#ifndef MINHA_AMANDA
void dprintf_z (const char *format, ...);
#endif
void deinit (void);
//removed in 2020, sorry for the delay... void ffms_patch_lavf_file_open (void);
void indprintff (const char *format, ...);
int setdebuginformation_multithread(morcego___i___instance__a__bucaneiro_engineering *mv_______,char *string);
void init_video(morcego___i___instance__a__bucaneiro_engineering *mv_______,be_libav_struct * be_data);
void
deinit2_video (morcego___i___instance__a__bucaneiro_engineering *mv_______);
/////////////////////////////////////////////////////////////////////////////

void
changecharacter (char *path, const char itemtosearch, char finalcharacter)
{
//this function was wrote in 1999
	int ret;
	ret = strlen (path);
	if (ret)
	{
		int i;
		for (i = 0; i < ret; i++)
		{
			if (path[i] == itemtosearch)
			{
				path[i] = finalcharacter;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
int get_morcego_bitrate (char *file, double seconds__);
/**
 * Retrieve the value based in the percentage
 */
double
getval_100 (double max, double por)
{

	// a formula aqui ï¿½
	// max / 100 * por

	double maxa;
	double porr;

	maxa = (double) max;
	porr = (double) por;

	maxa = (maxa / 100.0) * porr;

	return maxa;

}
//certo
#define BE_IS_DEBUG
#ifdef BE_IS_DEBUG

void
av_log_windebug_callback (void *ptr, int level, const char *fmt, va_list vl)
{


	char line[1024];
	//AVClass *avc = ptr ? *(AVClass **) ptr : NULL;
	if (level > av_log_get_level ())
		return;

	vsnprintf (line, sizeof (line), fmt, vl);
	changecharacter (line, '\r', ' '), changecharacter (line, '\n', ' ');
#ifndef MINHA_AMANDA
	//dprintf_z ("-%s-  debugfixo", line);
#endif
	/*
	   if(copy)
	   {
	        dprintf_z("copy here debugfixo\n");
	   }
	   if(0== strcmp(line, "Missing reference picture "))
	   {
	        copy->libav_c___error_in_decode=1;
	   }
	   if(0== strcmp(line, "mmco: unref short failure "))
	   {
	        copy->libav_c___error_in_decode=1;
	   }
	   if(0== strcmp(line, "number of reference frames (0+4) exceeds max (3; probably corrupt input), discarding one  "))
	   {
	        copy->libav_c___error_in_decode=1;
	   }
	 */

	/*[5004] reference picture missing during reorder -  debugfixo

	   [5004] Missing reference picture -  debugfixo
	   [5004] mmco: unref short failure -  debugfixo
	   [2612] -mmco: unref short failure -  debugfixo
	   [2612] -number of reference frames (0+4) exceeds max (3; probably corrupt input), discarding one -  debugfixo


	 */

}

#endif

void
mprintf (char *format, ...)
{
	va_list args;
	char buffer[1024];
	va_start (args, format);
	vsprintf (buffer, format, args);
	/*
	   MessageBox (0, buffer, "BW1", MB_ICONINFORMATION | MB_OK | MB_TOPMOST);
	   MessageBox (0, buffer, "BW2", MB_ICONWARNING     | MB_OK | MB_TOPMOST);
	   MessageBox (0, buffer, "BW3", MB_ICONQUESTION    | MB_OK | MB_TOPMOST);*/
	MessageBox (0, buffer, "BinaryWork Corp. Info", MB_ICONERROR | MB_OK | MB_SYSTEMMODAL);
}
/**
        It will initialize everything that is necessary for the good work of the player, as you may expect...
 */
void
init (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	if (!mv_______->libav_c___already)
	{
		//av_register_all ();
		//pedro
		//ffms_patch_lavf_file_open (); //removed from code in 2020
		mv_______->libav_c___already++;
	}
}

#define countof(array) (sizeof(array) / sizeof(array[0]))

static const struct s_ffmpeg_codec_overrides
{
	int codec;
	const char *override;
} ffmpeg_codec_overrides[] =
{
	{AV_CODEC_ID_MP1, "mp1float"},
	{AV_CODEC_ID_MP2, "mp2float"},
	{AV_CODEC_ID_MP3, "mp3float"},
	{AV_CODEC_ID_AMR_NB, "libopencore_amrnb"},
	{AV_CODEC_ID_AMR_WB, "libopencore_amrwb"},
};

const char *find_codec_override(int codec)
{
	for (int i = 0; i < countof(ffmpeg_codec_overrides); ++i)
	{
		if (ffmpeg_codec_overrides[i].codec == codec)
			return ffmpeg_codec_overrides[i].override;
	}
	return NULL;
}

int
init_decoder2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,be_libav_struct * be_data)
{
	AVCodecContext *pCodecCtx = avcodec_alloc_context3(NULL);
	AVFormatContext *FormatContext = NULL;
	AVCodec *Codec = NULL;
	
	static bool already_missing = false;
	
	int i;
	int returnvalue = 0;
	int ret_k_p;


	init (mv_______);

	//avcodec_register_all();


/* here...my love*/
	pCodecCtx->thread_count = 0;

	mv_______->libav_c___audiostream = -1;

	pedro_dprintf(-1, "dentro de init_decoder2 entrada ");

#if 0
	av_log_set_callback (av_log_windebug_callback);
	av_log_set_level (AV_LOG_ERROR);
#else
	pedro_dprintf(-1, "log quiet");
	av_log_set_level (AV_LOG_QUIET);
#endif

	pedro_dprintf(-1, "dentro de init_decoder2 saida");

	mv_______->libav_c___width_of_window=0;

	mv_______->libav_c___height_of_window=0;

	mv_______->libav_c___video_ready_to_play = 0;

	mv_______->libav_c___video_information[0]=0;

	mv_______->libav_c___mode_is_free_play=0;

	memset(mv_______->libav_c___empty_data,0,sizeof(mv_______->libav_c___empty_data));

	mv_______->libav_c___ajusted_frame_rate=0;

	mv_______->libav_c___old_rate=mv_______->libav_c___old_tempo=-1000;

	if(!mv_______->libav_c___dont_do_video)
	{

		init_video(mv_______,be_data);

	}
	pedro_dprintf(-1, "passou de init_video");
	if (avformat_open_input
	            (&FormatContext, be_data->sourcefile, NULL, (AVDictionary **) (NULL)) != 0)
	{
		strcpy (be_data->be_error_message, "Can't open the media file");
		returnvalue = 10;
		goto saida;
	}
	pedro_dprintf(-1, "passou de avformat_open_input");
	mv_______->libav_c___FormatContext_ptr=(void*)FormatContext;
	if (avformat_find_stream_info (FormatContext, (AVDictionary **) (NULL)) < 0)
	{
		if(mv_______->libav_c___video_ready_to_play)
		{
			mv_______->libav_c___mode_is_free_play=1;
		}
		else
		{
			strcpy (be_data->be_error_message, "Can't find the stream information");

			pedro_dprintf(-1, "avformat_find_stream_info error");

			avformat_close_input (&FormatContext);
			mv_______->libav_c___FormatContext_ptr=NULL;
			FormatContext = NULL;
			returnvalue = 20;
		}
	}
	pedro_dprintf(-1, "passou de avformat_find_stream_info");
	{
		int counter=0;
		for (i = 0; i < FormatContext->nb_streams; i++)
			if (FormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO)
			{
				counter++;
				if(counter==be_data->track_to_play_or_decode)
				{
					if(false == already_missing)
					{
						pedro_dprintf(1001, "@@track support missing, 06/july/2021\n");
						already_missing = true;
					}
					mv_______->libav_c___audiostream = i;
					goto achou;
				}

			}
		if(mv_______->libav_c___video_ready_to_play)
		{
			mv_______->libav_c___mode_is_free_play=1;
		}
		else
		{
			strcpy (be_data->be_error_message, "The track resquested was not found");
			returnvalue=30;
			goto saida;
		}

achou:
		;
	}

	if(!mv_______->libav_c___mode_is_free_play)
	{
		if (-1 == mv_______->libav_c___audiostream)
		{
			strcpy (be_data->be_error_message, "Audio stream not found");
			returnvalue = 40;
			goto saida;
		}

		mv_______->libav_c___duracao = FormatContext->duration;

		if (0x8000000000000000 ==
			(uint64_t)(mv_______->libav_c___duracao))
		{
			mv_______->libav_c___amanda_s_smart_ape_is_new_webm = true;
			//FormatContext->duration = 1000000 * 300;			

			//mv_______->libav_c___duracao = 

		}

		if(mv_______->libav_c___amanda_s_smart_ape_is_new_webm)
		{
			mv_______->libav_c___duracao = mv_______->libav_c___amanda_s_smart_ape_new_generated_duration;
			FormatContext->duration = mv_______->libav_c___duracao;
		}

		be_data->length = (double)mv_______->libav_c___duracao;

		mv_______->libav_c___seconds = (double)((double)(FormatContext->duration) / 1000000.0);

		if (!pCodecCtx)
		{
			strcpy (be_data->be_error_message, "Cannot allocate memory");
			returnvalue = 9000;
			goto saida;
		}

		ret_k_p = avcodec_parameters_to_context(pCodecCtx, FormatContext->streams[mv_______->libav_c___audiostream]->codecpar);
		if (ret_k_p < 0)
		{
			strcpy (be_data->be_error_message, "Cannot allocate memory");
			returnvalue = 9001;
			goto saida;
		}

		mv_______->libav_c___pCodecCtx_ptr=pCodecCtx;

		strcpy (be_data->be__magic_value__format_name,
		        FormatContext->iformat->long_name);

		{
			double den=FormatContext->streams[(int) mv_______->libav_c___audiostream]->time_base.den;
			double num=FormatContext->streams[(int) mv_______->libav_c___audiostream]->time_base.num;
			mv_______->libav_c___audio_timebase=num/den;
		}
		
		/*

		   const char *codec_override = find_codec_override(pCodecCtx->codec_id);
		    if (codec_override)
		        Codec = avcodec_find_decoder_by_name(codec_override);

		   pedro_dprintf(-1, "Achou %I64x", Codec);

		   exit(1);

		 */

		Codec = (void*) avcodec_find_decoder (pCodecCtx->codec_id);
		pedro_dprintf(-1, "passou de avcodec_find_decoder");
		if (NULL == Codec)
		{
			strcpy (be_data->be_error_message, "Can't initiate the decoder 1");
			returnvalue = 50;
			goto saida;
		}

		strcpy (be_data->be_codec_name, Codec->name ? Codec->name : "unknown");

		strcpy (be_data->be_media_information, be_data->be_codec_name);

		if(mv_______->libav_c___video_ready_to_play)
		{
			strcat(be_data->be_media_information," - ");
			strcat(be_data->be_media_information,mv_______->libav_c___video_codec);
		}

		if (0 !=
		    strcmp (be_data->be_codec_name, be_data->be__magic_value__format_name))
		{
			strcat (be_data->be_media_information, " - ");
			strcat (be_data->be_media_information,
			        be_data->be__magic_value__format_name);
		}

		if (Codec->capabilities & AV_CODEC_CAP_TRUNCATED)
		{
			pCodecCtx->flags |= AV_CODEC_FLAG_TRUNCATED;
			// we do not send complete frames, I yet don't know if
			//this can affect our audio player..., but since it is
			//in the libav documentation I will keep it this way
		}

		if (avcodec_open2 (pCodecCtx, Codec, NULL) < 0)
		{
			strcpy (be_data->be_error_message, "Can't open the decoder");
			returnvalue = 60;
			avcodec_free_context (&pCodecCtx);
			mv_______->libav_c___pCodecCtx_ptr=NULL;//why???
			pCodecCtx = NULL;
			goto saida;
		}
		pedro_dprintf(-1, "passou de avcodec_open2");
		mv_______->libav_c___BitsPerSample = av_get_bytes_per_sample (pCodecCtx->sample_fmt)*8;

		mv_______->libav_c___original_bitrate_k_p = mv_______->libav_c___BitsPerSample;

		mv_______->libav_c___BitsPerSample = 16;//hack ...

		pedro_dprintf(-1, "0 Bits per sample %d", mv_______->libav_c___BitsPerSample);

		mv_______->libav_c___pCodecCtx_ptr=pCodecCtx;
		/*
		   if (AV_SAMPLE_FMT_S32==pCodecCtx->sample_fmt
		    && pCodecCtx->bits_per_raw_sample)
		    mv_______->libav_c___BitsPerSample = pCodecCtx->bits_per_raw_sample;
		 *///hack again
		pedro_dprintf(-1, "2 Bits per sample %d", mv_______->libav_c___BitsPerSample);

		be_data->be_bitrate = pCodecCtx->bit_rate;

		mv_______->libav_c___channels_ = pCodecCtx->channels;

		mv_______->libav_c___original_number_of_channels_k_p = mv_______->libav_c___channels_;

		if(2 < mv_______->libav_c___channels_)
		{
			mv_______->libav_c___channels_ = 2;
		}

		be_data->be_channels = mv_______->libav_c___channels_;

		mv_______->libav_c___sample_rate = pCodecCtx->sample_rate;

		mv_______->libav_c___sample_fmt_ = pCodecCtx->sample_fmt; //1

		be_data->sample_format = mv_______->libav_c___sample_fmt_;

		be_data->be_samplerate = mv_______->libav_c___sample_rate;

		be_data->be_bits_per_sample = mv_______->libav_c___BitsPerSample;

		be_data->be_seconds = mv_______->libav_c___seconds;
	}
	else
	{
		mv_______->libav_c___audio_frame=-1;

		AVFormatContext *FormatContext =
			(AVFormatContext *) mv_______->libav_c___FormatContext_ptr_video;

		mv_______->libav_c___duracao = FormatContext->duration;

		//mprintf("valor %I64d ",mv_______->libav_c___duracao);

		be_data->length = (double) mv_______->libav_c___duracao;

		mv_______->libav_c___seconds = (double) ((double) (FormatContext->duration) / 1000000.0);

		/////aqui meu amor...
		pCodecCtx = mv_______->libav_c___pCodecCtx_ptr_video;

		strcpy (be_data->be__magic_value__format_name,
		        FormatContext->iformat->long_name);

		Codec = (void *) avcodec_find_decoder (pCodecCtx->codec_id);

		if (NULL == Codec)
		{
			strcpy (be_data->be_error_message, "Can't initiate the decoder 2");
			returnvalue = 50;
			goto saida;
		}

		strcpy (be_data->be_codec_name, Codec->name ? Codec->name : "unknown");

		strcpy (be_data->be_media_information, be_data->be_codec_name);

		if(mv_______->libav_c___video_ready_to_play)
		{
			strcat(be_data->be_media_information," - ");
			strcat(be_data->be_media_information,mv_______->libav_c___video_codec);
		}

		if (0 !=
		    strcmp (be_data->be_codec_name, be_data->be__magic_value__format_name))
		{
			strcat (be_data->be_media_information, " - ");
			strcat (be_data->be_media_information,
			        be_data->be__magic_value__format_name);
		}

		mv_______->libav_c___original_bitrate_k_p = 16;
		mv_______->libav_c___original_number_of_channels_k_p = 2;
		mv_______->libav_c___BitsPerSample = 16;

		be_data->be_bitrate = 0;

		mv_______->libav_c___channels_ = 2;

		be_data->be_channels = 2;

		mv_______->libav_c___sample_rate = 44100;

		mv_______->libav_c___sample_fmt_ = 1;

		be_data->sample_format = mv_______->libav_c___sample_fmt_;

		be_data->be_samplerate = mv_______->libav_c___sample_rate;

		be_data->be_bits_per_sample = 16;

		be_data->be_seconds = mv_______->libav_c___seconds;

	}

	{

		double size_of_data;
		double adjusted_bps = mv_______->libav_c___BitsPerSample;

		if (24 == mv_______->libav_c___BitsPerSample)
		{
			adjusted_bps = 32;
			assert (2 == mv_______->libav_c___sample_fmt_);
		}

		assert(2 >= mv_______->libav_c___channels_ && 538 && "libav.c");

		if (mv_______->libav_c___channels_ > 2)
		{
			//hack...
			size_of_data =
				mv_______->libav_c___seconds * 2.0 * (double) mv_______->libav_c___sample_rate *(double) adjusted_bps / 8.0;
		}
		else
		{
			size_of_data =
				mv_______->libav_c___seconds * (double) mv_______->libav_c___channels_ *(double) mv_______->libav_c___sample_rate *
				(double) adjusted_bps / 8.0;
		}

		mv_______->libav_c___be_size_of_pcm_data = (__int64) size_of_data;

		be_data->be_samples = mv_______->libav_c___be_size_of_pcm_data / mv_______->libav_c___channels_ / 2;

		size_of_data =
			mv_______->libav_c___seconds * (double) mv_______->libav_c___channels_ *(double) mv_______->libav_c___sample_rate *
			(double) adjusted_bps / 8.0;

		mv_______->libav_c___real_size_of_pcm_data = (__int64) size_of_data;

		if (1 == mv_______->libav_c___channels_)
		{

			if (mv_______->libav_c___be_size_of_pcm_data % 2)
			{
				mv_______->libav_c___be_size_of_pcm_data--;
			}

		}
		else
		{

			while (mv_______->libav_c___be_size_of_pcm_data % (mv_______->libav_c___channels_ * 2))
			{
				mv_______->libav_c___be_size_of_pcm_data--;
			}

			if (mv_______->libav_c___be_size_of_pcm_data < 0)
			{
				mv_______->libav_c___be_size_of_pcm_data = 0;
			}

		}
		be_data->be_size_of_pcm_data = mv_______->libav_c___be_size_of_pcm_data;
	}

	if(0==be_data->be_bitrate)
	{
		be_data->be_bitrate=
			get_morcego_bitrate
			(
				be_data->sourcefile,
				be_data->be_seconds
			)
			*
			1000
		;
	}
saida:
	;
	//("saiu de init 2");

	pedro_dprintf(-1, "saindo de initdecoder 2");

	return returnvalue;
}

void __stdcall get_sample_format_info_k_p
(
	int sample_format_k_p,
	char * out_information_k_p,
	char * out_information_simplified_k_p
)
{
	/*
	   enum AVSampleFormat {
	   AV_SAMPLE_FMT_NONE = -1,
	   AV_SAMPLE_FMT_U8,          ///< unsigned 8 bits
	   AV_SAMPLE_FMT_S16,         ///< signed 16 bits
	   AV_SAMPLE_FMT_S32,         ///< signed 32 bits
	   AV_SAMPLE_FMT_FLT,         ///< float
	   AV_SAMPLE_FMT_DBL,         ///< double

	   AV_SAMPLE_FMT_U8P,         ///< unsigned 8 bits, planar
	   AV_SAMPLE_FMT_S16P,        ///< signed 16 bits, planar
	   AV_SAMPLE_FMT_S32P,        ///< signed 32 bits, planar
	   AV_SAMPLE_FMT_FLTP,        ///< float, planar
	   AV_SAMPLE_FMT_DBLP,        ///< double, planar
	   AV_SAMPLE_FMT_S64,         ///< signed 64 bits
	   AV_SAMPLE_FMT_S64P,        ///< signed 64 bits, planar

	   AV_SAMPLE_FMT_NB           ///< Number of sample formats. DO NOT USE if linking dynamically

	 */

	switch(sample_format_k_p)
	{
	case AV_SAMPLE_FMT_NONE:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_NONE -1");
		strcpy(out_information_simplified_k_p, "NONE");
		break;
	case AV_SAMPLE_FMT_U8:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_U8 unsigned 8 bits");
		strcpy(out_information_simplified_k_p, "unsigned 8 bits");
		break;
	case AV_SAMPLE_FMT_S16:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_S16 signed 16 bits");
		strcpy(out_information_simplified_k_p, "signed 16 bits");
		break;
	case AV_SAMPLE_FMT_S32:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_S32 signed 32 bits");
		strcpy(out_information_simplified_k_p, "signed 32 bits");
		break;
	case AV_SAMPLE_FMT_FLT:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_FLT float");
		strcpy(out_information_simplified_k_p, "float");
		break;
	case AV_SAMPLE_FMT_DBL:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_DBL double");
		strcpy(out_information_simplified_k_p, "double");
		break;
	case AV_SAMPLE_FMT_U8P:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_U8P unsigned 8 bits, planar");
		strcpy(out_information_simplified_k_p, "unsigned 8 bits, planar");
		break;
	case AV_SAMPLE_FMT_S16P:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_S16P signed 16 bits, planar");
		strcpy(out_information_simplified_k_p, "signed 16 bits, planar");
		break;
	case AV_SAMPLE_FMT_S32P:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_S32P signed 32 bits, planar");
		strcpy(out_information_simplified_k_p, "signed 32 bits, planar");
		break;
	case AV_SAMPLE_FMT_FLTP:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_FLTP float, planar");
		strcpy(out_information_simplified_k_p, "float, planar");
		break;
	case AV_SAMPLE_FMT_DBLP:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_DBLP double, planar");
		strcpy(out_information_simplified_k_p, "double, planar");
		break;
	case AV_SAMPLE_FMT_S64:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_S64 signed 64 bits");
		strcpy(out_information_simplified_k_p, "signed 64 bits");
		break;
	case AV_SAMPLE_FMT_S64P:
		strcpy(out_information_k_p, "AV_SAMPLE_FMT_S64P signed 64 bits, planar");
		strcpy(out_information_simplified_k_p, "signed 64 bits, planar");
		break;
	default:
		assert(0 && "Unnown sample format, contact the developer amanda@arsoftware.net.br");
		abort();
		break;

	}
	return;
}

//esta eh a funcao que tem que ser alterada para a versao nova, ok?...
int
decode2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *buf, int *size_out)
{
        
	//mv_______->libav_c___mode_is_free_play=1; //for debug

	if(mv_______->libav_c___mode_is_free_play)
	{
		*size_out=0;
		if(mv_______->libav_c___video_thread_running)
		{
			memcpy(buf,mv_______->libav_c___empty_data,4096);//what is this my love?...why not memset?
			*size_out=4096;
			return BE_DECODED;
		}
		else
		{
			*size_out=0;
			return BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE;
		}
	}
	int got_frame=0;
	AVFrame *decoded_frame = NULL;
	//char *buffer_v11=av_malloc(192000);
	AVCodecContext *pCodecCtx = (void*)mv_______->libav_c___pCodecCtx_ptr;
	AVFormatContext *FormatContext = (AVFormatContext *)mv_______->libav_c___FormatContext_ptr;
//the packet
	AVPacket *packet_ptr = av_packet_alloc();
	*size_out = 0;
	//memset (packet_ptr, 0, sizeof (AVPacket));
final:
	;
	while (mv_______->libav_c___is_seeking)
	{
		Sleep (15);
	}
	if(!mv_______->libav_c___pCodecCtx_ptr||!mv_______->libav_c___FormatContext_ptr)
	{
		assert(0);
		goto final_ha_ha_ha_ha_ha;
	}
	while (av_read_frame (FormatContext, packet_ptr) >= 0)
	{

		if (mv_______->libav_c___is_seeking)
		{
			av_packet_unref (packet_ptr);
			goto final;
		}
		if(!mv_______->libav_c___pCodecCtx_ptr||!mv_______->libav_c___FormatContext_ptr)
		{
			assert(0);
			goto final_ha_ha_ha_ha_ha;
		}
		if (packet_ptr->stream_index == mv_______->libav_c___audiostream)
		{

			if (AV_NOPTS_VALUE == packet_ptr->pts)
			{
				// ("packet.pts == AV_NOPTS_VALUE\n");
				setdebuginformation_multithread (mv_______,"Missing presentation timestamp, on some frames");
			}

			mv_______->libav_c___audio_frame=packet_ptr->pts;

			pedro_dprintf(-1, "Audio update ----------");

			if(!mv_______->libav_c___pCodecCtx_ptr || !mv_______->libav_c___FormatContext_ptr)
			{
				assert(0);
				goto final_ha_ha_ha_ha_ha;
			}
			/*
			                        if (!decoded_frame)
			                        {
			                                if (!(decoded_frame = av_frame_alloc()))
			                                {
			                                        fprintf(stderr, "Could not allocate audio frame\n");
			                                        assert(0 && "Could not allocate audio frame\n");
			                                }
			                        }
			                        else
			                                av_frame_unref(decoded_frame);
			 */
			assert(NULL == decoded_frame);

			decoded_frame = av_frame_alloc();

/*
                        mv_______->libav_c___morcego =
                                avcodec_decode_audio4 (pCodecCtx, decoded_frame, &got_frame
                                                       , packet_ptr);
                        if (mv_______->libav_c___morcego < 0)
                        {
                                if (decoded_frame)
                                {
                                        av_frame_unref(decoded_frame);
                                        decoded_frame = NULL;
                                }
                                av_packet_unref (packet_ptr);

                                continue;
                        }
 */
			mv_______->libav_c___morcego = avcodec_send_packet(pCodecCtx, packet_ptr);
			if (mv_______->libav_c___morcego < 0 && mv_______->libav_c___morcego != AVERROR(EAGAIN) && mv_______->libav_c___morcego != AVERROR_EOF)
			{
				av_packet_unref (packet_ptr);

				if (decoded_frame)
				{				
					av_frame_unref(decoded_frame);
					av_frame_free(&decoded_frame);
					decoded_frame = NULL;
				}

				continue;
			}
			else
			{
				if (mv_______->libav_c___morcego >= 0)
					packet_ptr->size = 0;
			
				mv_______->libav_c___morcego = avcodec_receive_frame(pCodecCtx, decoded_frame);
				if (mv_______->libav_c___morcego >= 0)
					got_frame = 1;
				else
				{
					got_frame = 0;

					if (decoded_frame)
					{
						av_frame_unref(decoded_frame);
						av_frame_free(&decoded_frame);
						decoded_frame = NULL;
					}

					av_packet_unref (packet_ptr);
					continue;
				}
			}

			/*
			   mv_______->libav_c___morcego =
			        avcodec_decode_audio3 (pCodecCtx, (int16_t *) buffer_v11,
			                               &buffer_size, packet_ptr);
			   if (mv_______->libav_c___morcego < 0)
			   {

			        av_free_packet (packet_ptr);

			        continue;

			   }
			 */
			/*
			   if (buffer_size)
			   {
			        memcpy (buf, buffer_v11, buffer_size);
			 * size_out = buffer_size;

			        av_free_packet (packet_ptr);
			        av_free(buffer_v11);
			        av_free(packet_ptr);
			        //("saiu de decode audio");
			        return BE_DECODED;
			   }
			 */
			if(got_frame)
			{
				int frame_processed_k_p = 0;
				char sample_info_k_p[300];
				int data_size = av_samples_get_buffer_size(NULL,pCodecCtx->channels,
				                                           decoded_frame->nb_samples,
				                                           pCodecCtx->sample_fmt, 1);

				if(0 == mv_______->libav_c___sample_rate_format_string[0])
				{
					get_sample_format_info_k_p
					(
						pCodecCtx->sample_fmt,
						mv_______->libav_c___sample_rate_format_string,
						sample_info_k_p
					);
				}
				/*

				   enum AVSampleFormat {
				   AV_SAMPLE_FMT_NONE = -1,
				   AV_SAMPLE_FMT_U8,          ///< unsigned 8 bits - yes
				   AV_SAMPLE_FMT_S16,         ///< signed 16 bits  - yes
				   AV_SAMPLE_FMT_S32,         ///< signed 32 bits  - yes
				   AV_SAMPLE_FMT_FLT,         ///< float           - yes
				   AV_SAMPLE_FMT_DBL,         ///< double          - yes

				   AV_SAMPLE_FMT_U8P,         ///< unsigned 8 bits, planar - yes
				   AV_SAMPLE_FMT_S16P,        ///< signed 16 bits, planar  - yes
				   AV_SAMPLE_FMT_S32P,        ///< signed 32 bits, planar  - yes
				   AV_SAMPLE_FMT_FLTP,        ///< float, planar           - yes
				   AV_SAMPLE_FMT_DBLP,        ///< double, planar          - yes
				   AV_SAMPLE_FMT_S64,         ///< signed 64 bits          - yes
				   AV_SAMPLE_FMT_S64P,        ///< signed 64 bits, planar  - yes

				   AV_SAMPLE_FMT_NB           ///< Number of sample formats. DO NOT USE if linking dynamically

				 */

				/*****************************************************************************
				* This is the part of the code that handles the sample format
				* now with full 5.1 and 7.1 channels support in systems that have only stereo
				* output, notice that for the moment in a real 5.1 and 7.1 system all the
				* channels will be mixed and sent to the front speakers, this limitation will
				* be solved in the next week (27-October-2020)
				*****************************************************************************
				* Some of the formats was not tested fully, but must work
				*****************************************************************************/
				
				if(AV_SAMPLE_FMT_U8P == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_U8P_k_p.c"
				}

				if(AV_SAMPLE_FMT_S16P == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_S16P_k_p.c"
				}

				if(AV_SAMPLE_FMT_FLTP == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_FLTP_k_p.c"
				}

				if(AV_SAMPLE_FMT_DBLP == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_DBLP_k_p.c"
				}

				if(AV_SAMPLE_FMT_S32P == pCodecCtx->sample_fmt) //untested, please check
				{
#include "AV_SAMPLE_FMT_S32P_k_p.c"
				}

				if(AV_SAMPLE_FMT_S64P == pCodecCtx->sample_fmt) //untested, please check
				{
#include "AV_SAMPLE_FMT_S64P_k_p.c"
				}

				if(AV_SAMPLE_FMT_U8 == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_U8_k_p.c"
				}

				if(AV_SAMPLE_FMT_S16 == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_S16_k_p.c"
				}

				if(AV_SAMPLE_FMT_S32 == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_S32_k_p.c"
				}

				if(AV_SAMPLE_FMT_S64 == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_S64_k_p.c"
				}

				if(AV_SAMPLE_FMT_FLT == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_FLT_k_p.c"
				}

				if(AV_SAMPLE_FMT_DBL == pCodecCtx->sample_fmt)
				{
#include "AV_SAMPLE_FMT_DBL_k_p.c"
				}

				if(!frame_processed_k_p)
				{
					pedro_dprintf(-1, "bits %d data_size %d format %s\n", (int)mv_______->libav_c___original_bitrate_k_p, data_size, mv_______->libav_c___sample_rate_format_string);

					mprintf("The format \' %s \' is not supported at this moment, please contact the developer at arsoftware10@gmail.com and send a printscreen of this error, now the application will exit and return an error 25\n", mv_______->libav_c___sample_rate_format_string);
					exit(25);
				}

				av_packet_unref (packet_ptr);

				av_frame_unref(decoded_frame);
				av_frame_free(&decoded_frame);
				decoded_frame = NULL;

				pedro_dprintf(-1, "size out %d", *size_out);
				av_packet_free(&packet_ptr);

				return BE_DECODED;
			}

			if(decoded_frame)
			{

				av_frame_unref(decoded_frame);
				av_frame_free(&decoded_frame);
				decoded_frame = NULL;

			}

		}
		av_packet_unref (packet_ptr);
		if(!mv_______->libav_c___pCodecCtx_ptr||!mv_______->libav_c___FormatContext_ptr)
		{
			assert(0);
			goto final_ha_ha_ha_ha_ha;
		}
		
	}

//aqui1
final_ha_ha_ha_ha_ha:
	;
	//av_free(buffer_v11);
	av_packet_unref(packet_ptr);

	av_frame_free(&decoded_frame);
	//av_frame_free(&decoded_frame);

	av_packet_free(&packet_ptr);
	//("saiu de decode audio");
	return BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE;
}
//to remember how to adjust structs size on the compiler, do not remove it
#pragma pack(push, 1)
void
deinit2 (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	deinit2_video(mv_______);
	AVCodecContext *pCodecCtx = (void*)mv_______->libav_c___pCodecCtx_ptr;
	AVFormatContext *FormatContext = (AVFormatContext *)mv_______->libav_c___FormatContext_ptr;
	if (FormatContext)
	{
		
		avformat_close_input (&FormatContext);
	
		if (pCodecCtx)
		{
			//("fechou codec de audio");
			avcodec_free_context (&pCodecCtx);
			pCodecCtx = NULL;
			mv_______->libav_c___pCodecCtx_ptr=NULL;
		}

		FormatContext = NULL;
		mv_______->libav_c___FormatContext_ptr=NULL;
	}
}

#pragma pack(pop)

/**
   Wrapper to file support of the libav, not is use anymore
 */
int
ffms_wchar_open (const char *fname, WCHAR * mode)
{
	int ret;
	/*

	   switch (*mode)
	   {
	   case 'a':
	   oflags = O_CREAT | (rw ? O_RDWR : O_WRONLY);
	   break;
	   case 'r':
	   oflags = rw ? O_RDWR : O_RDONLY;
	   break;
	   case 'w':
	   oflags = O_TRUNC | O_CREAT | (rw ? O_RDWR : O_WRONLY);
	   break;
	   default:
	   return (NULL);
	   }

	 */
	unicode_large *ul=calloc(sizeof(unicode_large),1);
	ret= _wopen (utf8towide_fixed (ul,fname), O_RDONLY|O_BINARY);
	free(ul);
	return ret;
}

/**
   Wrapper to file support of the libav, come from the ffms2.dll project.
 */
/*
   static int
   ffms_lavf_file_open (URLContext * h, const char *filename, int flags)
   {

        int fd;

        WCHAR moder[300] = L"rb"; //only this is being used at this moment, because we dont write using libav yet, but soon we will
        //WCHAR moderw[300] = L"rb+";
        //WCHAR modew[300] = L"wb";

        av_strstart (filename, "file:", &filename);

        if (flags & URL_RDWR)
        {
                fd = ffms_wchar_open (filename, moder);
        }
        else if (flags & URL_WRONLY)
        {
                fd = ffms_wchar_open (filename, moder);
        }
        else
        {
                fd = ffms_wchar_open (filename, moder);
        }

        if (0 == fd)
        {
                return AVERROR (ENOENT);
        }

        h->priv_data = (void *) (intptr_t) (fd);
        return 0;
   }
 */
/**
   Wrapper to file support of the libav...
 */
/*
   static int
   file_close (URLContext * h)
   {
        int fd = (intptr_t) h->priv_data;
        return close (fd);
   }
 */
/*
   void
   ffms_patch_lavf_file_open ()
   {
        URLProtocol *proto = av_protocol_next (NULL);
        while (proto != NULL)
        {
                if (strcmp ("file", proto->name) == 0)
                {
                        break;
                }
                proto = proto->next;
        }
        if (proto != NULL)
        {
                proto->url_open = &ffms_lavf_file_open;
                proto->url_close=file_close;
        }
   }
 */
/**
 * 19/nov/2011 - the position to seek in percent as double, it is
 * precise enough, (problems with matroska (webm) at this moment,
 * it will seek just to a position close of the real desired position,
 * will be fixed soon).
 */
void
seek2 (morcego___i___instance__a__bucaneiro_engineering *mv_______, double value)
{
	/**

	 */
///dprintf("seeking... debug4\n");
	mv_______->libav_c___reinit_uf=0;
	mv_______->libav_c___reinit_uf2=0;

	AVFormatContext *FormatContext = (AVFormatContext *)mv_______->libav_c___FormatContext_ptr;
	if (mv_______->libav_c___mode_is_free_play||(FormatContext && (-1 != mv_______->libav_c___audiostream)))
	{
		mv_______->libav_c___is_seeking = 1;

		Sleep (50); //for safety
		value = getval_100 ((double) mv_______->libav_c___duracao, value);

		mv_______->decoder_c___newsecond_copy=0;

		if ((__int64) value > mv_______->libav_c___duracao)
		{
			value = mv_______->libav_c___duracao - 1;
		}
		if (value < 0)
		{
			value = 0;
		}
		/**
		    int av_seek_frame(
		 */
		if(!mv_______->libav_c___mode_is_free_play)
		{
			mv_______->libav_c___morcego =
				av_seek_frame (FormatContext, -1, (__int64) value,
				               AVSEEK_FLAG_BACKWARD);

			if (mv_______->libav_c___morcego < 0)
			{
				mv_______->libav_c___morcego =
					av_seek_frame (FormatContext, -1, (__int64) value,
					               AVSEEK_FLAG_BACKWARD | AVSEEK_FLAG_ANY);
			}
		}
		if(mv_______->libav_c___video_ready_to_play)
		{

			AVFormatContext *FormatContext = (AVFormatContext *)mv_______->libav_c___FormatContext_ptr_video;
			mv_______->libav_c___morcego =
				av_seek_frame (FormatContext, -1, (__int64) value,
				               AVSEEK_FLAG_BACKWARD);

			if (mv_______->libav_c___morcego < 0)
			{
				mv_______->libav_c___morcego =
					av_seek_frame (FormatContext, -1, (__int64) value,
					               AVSEEK_FLAG_BACKWARD | AVSEEK_FLAG_ANY);
			}

		}
		mv_______->libav_c___is_seeking = 0;
	}
	//("deu seek");
}
int get_number_of_audio_tracks_internal(morcego___i___instance__a__bucaneiro_engineering *mv_______,char * utf8_filename, char * error_message)
{
	AVFormatContext *FormatContext_b = NULL;
	int i;
	int count=0;
	int returnvalue=0;
	error_message[0]=0;

	init (mv_______);

	if (avformat_open_input
	            (&FormatContext_b, utf8_filename, NULL, NULL) != 0)
	{
		strcpy(error_message,"Can't open the media file");
		returnvalue = -1;
		goto saida;
	}

	if (avformat_find_stream_info (FormatContext_b, NULL) < 0)
	{
		strcpy(error_message,"Can't find the media stream");
		avformat_close_input (&FormatContext_b);
		FormatContext_b = NULL;
		returnvalue=-2;
		goto saida;
	}
	/*

	    AVMEDIA_TYPE_UNKNOWN = -1,
	    AVMEDIA_TYPE_VIDEO,
	    AVMEDIA_TYPE_AUDIO,
	    AVMEDIA_TYPE_DATA,
	    AVMEDIA_TYPE_SUBTITLE,
	    AVMEDIA_TYPE_ATTACHMENT,
	    AVMEDIA_TYPE_NB


	        codecpar;

	 */
	for (i = 0; i < FormatContext_b->nb_streams; i++)
		if (FormatContext_b->streams[i]->codecpar->codec_type == /*AVMEDIA_TYPE_AUDIO*/ AVMEDIA_TYPE_AUDIO)
		{
			//dprintf("achou track %d debug8\n",i+1);
			count++; //untested, as usual
		}
saida:
	;

	if(FormatContext_b)
	{
		avformat_close_input (&FormatContext_b);
	}

	if(returnvalue<0)
		return returnvalue;

	return count;

}
