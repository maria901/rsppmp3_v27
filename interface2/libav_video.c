
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
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/
 
/*

   TODO

   0 - Now we will be thinking on the possibility to play DVD encrypted or not...
   1 - And also we will update the id3v2tag support to the latest version that
       have a picture of the Youtube version of the audio file on it.
   2 - Add the hability to disable display update when minimized, to use less
       processor time (working on it...)
   3 - Test to see whether the DLL is able to play all possible multichannel files
   4 - Since you know Libav provide an answer to https://stackoverflow.com/questions/18131389/how-to-convert-av-sample-fmt-s16-to-av-sample-fmt-s16p , done
   5 - Investigate a little more about why Media Player Classic Home Cinema is
       so fast, some magic is occurring...

 */

//has bugs...fix it if you got time, we will fix it as we can

/**

   que mexem tanto com minha cabeça que quando o sono vem o dia ja nasceu...

 */

#define AMANDA_MODE 0

#if AMANDA_MODE == 0
#define VIDEO_CONVERSION_MODE SWS_BICUBIC
//#warning VIDEO_CONVERSION_MODE == SWS_BICUBIC
#elif AMANDA_MODE == 1
#define VIDEO_CONVERSION_MODE SWS_FAST_BILINEAR
//#warning VIDEO_CONVERSION_MODE == SWS_FAST_BILINEAR
#elif AMANDA_MODE == 2
#define VIDEO_CONVERSION_MODE SWS_BILINEAR
#warning VIDEO_CONVERSION_MODE == SWS_BILINEAR
#else
#error Erro Ricardo...
#endif

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

#include "SDL_amanda/include/SDL.h"

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
//#include <libpostproc/postprocess.h>
#include <libavdevice/avdevice.h>
#include <libavfilter/avfilter.h>
#include <libavutil/avutil.h>

#include "../mp3_dll/decoder.h"

#include "amanda_colorspace.h"

//defines
#define WINDOW_FLAG___ HWND_TOP
#define SHOW_FLAG__    SWP_SHOWWINDOW | SWP_NOCOPYBITS
#define NO_SHOW_FLAG__ SWP_HIDEWINDOW | SWP_NOCOPYBITS

/////////////////////////////////////////////////////////////////////////////

int amanda_locked = 0;//to avoid a nasty bug in the video initialization

/////////////////////////////////////////////////////////////////////////////
// Amanda foi dar longe...kkkkkk, nao deu pra resistir....

#define RGBA_IN(r, g, b, a, s)\
{\
    unsigned int v = ((const uint32_t *)(s))[0];\
    a = (v >> 24) & 0xff;\
    r = (v >> 16) & 0xff;\
    g = (v >> 8) & 0xff;\
    b = v & 0xff;\
}

#define YUVA_OUT(d, y, u, v, a)\
{\
    ((uint32_t *)(d))[0] = (a << 24) | (y << 16) | (u << 8) | v;\
}

/////////////////////////////////////////////////////////////////////////////
//addef or desktop playback.

enum amanda_position
{
	I_TOP__,
	I_CENTER,
	I_BOTTOM,
};

long adjust_definitive_function_i(morcego___i___instance__a__bucaneiro_engineering *mv_______);

/////////////////////////////////////////////////////////////////////////////
morcego___i___instance__a__bucaneiro_engineering *copy = NULL;
/////////////
//Mr. Do
void samara_e_ricardo_close_screen(morcego___i___instance__a__bucaneiro_engineering *mv_______);
double frame_rate(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                  be_libav_struct *be_data, int video_stream_);
int is_playlist(morcego___i___instance__a__bucaneiro_engineering *mv_______, char *filename_);
double
getvalf(double maxa, double porr);
int restart_video(morcego___i___instance__a__bucaneiro_engineering *mv_______);
void adjust_video(morcego___i___instance__a__bucaneiro_engineering *mv_______);
__int64 espaco_no_tempo(void);
void pass_x_and_y(int x, int y);
int morcego_vermelho_player_thread(morcego___i___instance__a__bucaneiro_engineering *mv_______);
static int __stdcall video_player_thread(morcego___i___instance__a__bucaneiro_engineering *mv_______);
void mprintf(char *format, ...);
#ifndef MINHA_AMANDA
void dprintf_z(const char *format, ...);
#endif
void deinit2_video(morcego___i___instance__a__bucaneiro_engineering *mv_______);
int adjust_window_position_and_size(morcego___i___instance__a__bucaneiro_engineering *mv_______);
int final_adjust_fuction(morcego___i___instance__a__bucaneiro_engineering *mv_______);
int final_adjust_fuction(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	int return_value_kp = 0;
	if (!mv_______->libav_c___cancel_video_thread)
	{
		if (
			mv_______->libav_c___request_for_adjust ||
			mv_______->libav_c___old_x != mv_______->libav_c___adjust_left || mv_______->libav_c___old_y != mv_______->libav_c___adjust_top || mv_______->libav_c___old_width != mv_______->libav_c___size_of_window_width || mv_______->libav_c___old_height != mv_______->libav_c___size_of_window_height || mv_______->libav_c___old_ratio != mv_______->libav_c___the_ratio || mv_______->libav_c___old_adjusted_ratio != mv_______->libav_c___adjusted_ratio)
		{

			//Mr. do kkkkk, eu te amo...

			samara_e_ricardo_close_screen(mv_______);
			
			mv_______->libav_c___request_for_adjust = 0;
			adjust_window_position_and_size(mv_______);
			
			mv_______->libav_c___old_x = mv_______->libav_c___adjust_left;
			mv_______->libav_c___old_y = mv_______->libav_c___adjust_top;
			mv_______->libav_c___old_width = mv_______->libav_c___size_of_window_width;
			mv_______->libav_c___old_height = mv_______->libav_c___size_of_window_height;
			mv_______->libav_c___old_ratio = mv_______->libav_c___the_ratio;
			mv_______->libav_c___old_adjusted_ratio = mv_______->libav_c___adjusted_ratio;

			return_value_kp = restart_video(mv_______);
			
		}
	}
	return return_value_kp;
}

int adjust_window_position_and_size(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	int       w_i;
	int       h_i;
	double temp_i;
	__attribute__((unused)) double adjusted_ricardo;
	int rv = 0;
	char temp[1024] = {0};

	AVCodecContext *pCodecCtx = (void *)mv_______->libav_c___pCodecCtx_ptr_video;
	mv_______->libav_c___width = pCodecCtx->width;
	mv_______->libav_c___height = pCodecCtx->height;

	mv_______->libav_c___width_of_window = pCodecCtx->width;
	mv_______->libav_c___height_of_window = pCodecCtx->height;

	sprintf(
		temp, "bitrate %lld %dx%d ",
		pCodecCtx->bit_rate,
		mv_______->libav_c___width,
		mv_______->libav_c___height);

	switch (mv_______->libav_c___the_ratio)
	{
	case BE_AUTO_______:
		mv_______->libav_c___the_real_ratio = (double)mv_______->libav_c___width / ((double)mv_______->libav_c___height);
				
		if(0 != pCodecCtx->sample_aspect_ratio.den)
		{
			w_i = pCodecCtx->sample_aspect_ratio.num;
			h_i = pCodecCtx->sample_aspect_ratio.den;
			
			temp_i = (double) w_i / (double) h_i    ;
						
			sprintf(temp, "%.2f", temp_i * 100.);
			
			w_i = atoi(temp);
												
			sprintf(temp, "%.2f", mv_______->libav_c___the_real_ratio * 100.);
						
			h_i = atoi(temp);
						
			if(100 != w_i)
			{
				w_i = pCodecCtx->sample_aspect_ratio.num;
				h_i = pCodecCtx->sample_aspect_ratio.den;
								
				mv_______->libav_c___the_real_ratio = ((double) w_i / ((double) h_i)) * mv_______->libav_c___the_real_ratio;
			}
		}
		
		break;
	case BE_5x4_______:
		mv_______->libav_c___the_real_ratio = (double)5.0 / 4.0;
		break;
	case BE_16x9_______:
		mv_______->libav_c___the_real_ratio = (double)16.0 / 9.0;
		break;
	case BE_16x10_______:
		mv_______->libav_c___the_real_ratio = (double)16.0 / 10.0;
		break;
	case BE_4x3_______:
		mv_______->libav_c___the_real_ratio = (double)4.0 / 3.0;
		break;
	case BE_2_21x1_______:
		mv_______->libav_c___the_real_ratio = (double)2.21 / 1.0;
		break;
	case BE_2_35x1_______:
		mv_______->libav_c___the_real_ratio = (double)2.35 / 1.0;
		break;
	case BE_2_39x1_______:
		mv_______->libav_c___the_real_ratio = (double)2.39 / 1.0;
		break;
	case BE_2_50x1_______:
		mv_______->libav_c___the_real_ratio = (double)2.50 / 1.0;
		break;
	case BE_1x1_______:
		mv_______->libav_c___the_real_ratio = 1;
		break;
	default:
		mv_______->libav_c___the_real_ratio = (double)mv_______->libav_c___width / ((double)mv_______->libav_c___height);
		break;
	}

	mv_______->libav_c___the_real_ratio += mv_______->libav_c___adjusted_ratio;

	{
		double r;
		int val;
		r = mv_______->libav_c___the_real_ratio * 100;
		val = r;
		switch (val)
		{
		case 125:
			sprintf(temp +
			        strlen(temp),
			        "ratio 5:4 ");
			break;
		case 177:
			sprintf(temp +
			        strlen(temp),
			        "ratio 16:9 ");
			break;
		case 160:
			sprintf(temp +
			        strlen(temp),
			        "ratio 16:10 ");
			break;
		case 133:
			sprintf(temp +
			        strlen(temp),
			        "ratio 4:3 ");
			break;
		case 221:
			sprintf(temp +
			        strlen(temp),
			        "ratio 2.21:1 ");
			break;
		case 235:
			sprintf(temp +
			        strlen(temp),
			        "ratio 2.35:1 ");
			break;
		case 239:
			sprintf(temp +
			        strlen(temp),
			        "ratio 2.39:1 ");
			break;
		case 250:
			sprintf(temp +
			        strlen(temp),
			        "ratio 2.50:1 ");
			break;
		case 100:
			sprintf(temp +
			        strlen(temp),
			        "ratio 1:1 ");
			break;
		default:
		{
			double fixo = val;
			fixo = fixo / 100;
			sprintf(temp +
			        strlen(temp),
			        "ratio %0.2f:1 ", fixo);
		}
		break;
		}
	}

	//0xbadc0da;

	//0xbaddad;

	if (mv_______->libav_c___hwnd && mv_______->libav_c___player_hwnd)
	{
		int temp;

		temp = mv_______->libav_c___size_of_window_width;

retorna:
		;
		if (0 == mv_______->libav_c___size_of_window_width)
		{
			mv_______->libav_c___video_ready_to_play = 0;
			rv = 1;
			goto saida;
		}

		mv_______->libav_c___the_width = temp;
				
		mv_______->libav_c___the_height = (int)((double)temp / ((double)mv_______->libav_c___the_real_ratio) /*((1.777777)*/);

		//mv_______->libav_c___the_height = (int)((double)temp / ((double)mv_______->libav_c___the_real_ratio * (adjusted_ricardo / mv_______->libav_c___the_real_ratio)));

		//mv_______->libav_c___the_width /= 2;

		if (mv_______->libav_c___the_height > mv_______->libav_c___size_of_window_height)
		{
			temp--;
			if (!mv_______->libav_c___disable_width_limit)
			{
				goto retorna;
			}
		}
		mv_______->libav_c___disable_width_limit = 0;
		if (mv_______->libav_c___the_width % 2)
		{
			mv_______->libav_c___the_width--;
		}
		if (mv_______->libav_c___the_height % 2)
		{
			mv_______->libav_c___the_height--;
		}

		mv_______->libav_c___ajuste_width = (mv_______->libav_c___size_of_window_width - mv_______->libav_c___the_width);    ///2;
		mv_______->libav_c___ajuste_heigth = (mv_______->libav_c___size_of_window_height - mv_______->libav_c___the_height); ///2;
	}
	else
	{
		mv_______->libav_c___ajuste_heigth = 0;
		mv_______->libav_c___ajuste_width = 0;
		if (mv_______->libav_c___inputwidth < 0 || mv_______->libav_c___inputwidth > 10000 || 0 == mv_______->libav_c___inputwidth)
		{
			mv_______->libav_c___inputwidth = pCodecCtx->width;
		}
		mv_______->libav_c___the_width = mv_______->libav_c___inputwidth;
				
		mv_______->libav_c___the_height = (int)((double)mv_______->libav_c___the_width / (double)mv_______->libav_c___the_real_ratio);
		
		if (mv_______->libav_c___the_width % 2)
		{
			mv_______->libav_c___the_width--;
		}
		if (mv_______->libav_c___the_height % 2)
		{
			mv_______->libav_c___the_height--;
		}
	}

saida:

	;
	sprintf(
		mv_______->libav_c___video_information +
		mv_______->analisys_c___string_position,
		"%s",
		temp);

	return rv;
}

void samara_e_ricardo_close_screen(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	pedro_dprintf(-1, "dentro de samara_e_ricardo_close_screen inicio");
	/*

	   for historical reasons, 29/November/2020 06:14:25 AM

	   SDL_Overlay *bmp = (void *)mv_______->libav_c___bmp;

	   if (bmp)
	   {
	        SDL_FreeYUVOverlay(bmp);
	        mv_______->libav_c___bmp = NULL;
	   }
	 */

	if(NULL != mv_______->libav_c___sc_kp)
	{
		sws_freeContext((struct SwsContext *)mv_______->libav_c___sc_kp);
		mv_______->libav_c___sc_kp = NULL;
	}

	if(mv_______->libav_c___texture_kp)
		SDL_DestroyTexture((SDL_Texture *)mv_______->libav_c___texture_kp), mv_______->libav_c___texture_kp = NULL;

	if(mv_______-> libav_c___renderer_kp)
		SDL_DestroyRenderer((SDL_Renderer *)mv_______-> libav_c___renderer_kp), mv_______->libav_c___renderer_kp = NULL;

	if(mv_______->libav_c___screen_kp)
		SDL_DestroyWindow((SDL_Window *)mv_______->libav_c___screen_kp), mv_______->libav_c___screen_kp = NULL;

	if(NULL != mv_______->libav_c___vPlane_kp)
	{
		free(mv_______->libav_c___vPlane_kp);
		mv_______->libav_c___vPlane_kp = NULL;
	}

	if(NULL != mv_______->libav_c___uPlane_kp)
	{
		free(mv_______->libav_c___uPlane_kp);
		mv_______->libav_c___uPlane_kp = NULL;
	}

	if(NULL != mv_______->libav_c___yPlane_kp)
	{
		free(mv_______->libav_c___yPlane_kp);
		mv_______->libav_c___yPlane_kp = NULL;
	}

	pedro_dprintf(-1, "dentro de samara_e_ricardo_close_screen final");

//amanda_close
}

int restart_video(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	AVCodecContext *pCodecCtx;
	int returnvalue_kp = 0;

	pCodecCtx        =
		(void *)mv_______->libav_c___pCodecCtx_ptr_video;

	{
			
		if(true || !mv_______->libav_c___is_desktop_playback_amanda)
		{
			adjust_definitive_function_i(mv_______);
		} 
							 
		if(mv_______->libav_c___texture_kp)
		     SDL_DestroyTexture((SDL_Texture *)mv_______->libav_c___texture_kp), mv_______->libav_c___texture_kp = NULL;

		if(mv_______-> libav_c___renderer_kp)
		     SDL_DestroyRenderer((SDL_Renderer *)mv_______-> libav_c___renderer_kp), mv_______->libav_c___renderer_kp = NULL;

		if(mv_______->libav_c___screen_kp)
		     SDL_DestroyWindow((SDL_Window *)mv_______->libav_c___screen_kp), mv_______->libav_c___screen_kp = NULL;

		mv_______->libav_c___screen_kp = (void *)SDL_CreateWindowFrom((void *)mv_______->libav_c___player_hwnd);

		if (!mv_______->libav_c___screen_kp)
		{
		     pedro_dprintf(-1, "SDL: could not create window - exiting 1 \n");
		     strcpy(mv_______->libav_c___amanda_video_thread_error_message_kp, "SDL: could not create window - exiting...");
		     returnvalue_kp = 1025;
		     goto saida_amanda_kp;
		}
		else
		{
		     ;
		}

		mv_______->libav_c___renderer_kp =(void *) SDL_CreateRenderer((SDL_Window *)mv_______->libav_c___screen_kp, -1, SDL_RENDERER_ACCELERATED);
		if (!mv_______->libav_c___renderer_kp)
		{
		     pedro_dprintf(-1, "SDL: could not create renderer - exiting 1 \n");
		     strcpy(mv_______->libav_c___amanda_video_thread_error_message_kp, "SDL: could not create renderer - exiting...");
		     returnvalue_kp = 1026;
		     goto saida_amanda_kp;
		}
		else
		{
		     ;
		}

		{
		
		mv_______->libav_c___adjusted_i_width_for_directx = mv_______->libav_c___the_width;
			
		mv_______->libav_c___texture_kp = (void *) SDL_CreateTexture(
		     (SDL_Renderer *)mv_______->libav_c___renderer_kp,
		     SDL_PIXELFORMAT_YV12,
		     SDL_TEXTUREACCESS_STREAMING,
		     mv_______->libav_c___adjusted_i_width_for_directx,
		     mv_______->libav_c___the_height
		     );
		}
		
		if (!mv_______->libav_c___texture_kp)
		{
		     pedro_dprintf(-1, "SDL: could not create texture - exiting 1 \n");

		     strcpy(mv_______->libav_c___amanda_video_thread_error_message_kp, "SDL: could not create texture - exiting");
		     returnvalue_kp = 1027;
		     goto saida_amanda_kp;
		}
		else
		{
		     pedro_dprintf(-1, "Criou a textura");
		}
		
		assert(NULL == mv_______->libav_c___sc_kp);

		mv_______->libav_c___sc_kp = (void *) sws_getContext(pCodecCtx->width, pCodecCtx->height,
		                                                     pCodecCtx->pix_fmt, mv_______->libav_c___adjusted_i_width_for_directx, mv_______->libav_c___the_height,
		                                                     AV_PIX_FMT_YUV420P,
		                                                     VIDEO_CONVERSION_MODE,
		                                                     NULL,
		                                                     NULL,
		                                                     NULL);

		if(NULL == mv_______->libav_c___sc_kp)
		{
			strcpy(mv_______->libav_c___amanda_video_thread_error_message_kp, "Error allocating memory");
			returnvalue_kp = 1028;
			goto saida_amanda_kp;
		}
		else
		{
			pedro_dprintf(-1, "iniciou sws_getContext corretamente");
		}

		mv_______->libav_c___yPlaneSz_kp = mv_______->libav_c___adjusted_i_width_for_directx * mv_______->libav_c___the_height;
		mv_______->libav_c___uvPlaneSz_kp = mv_______->libav_c___adjusted_i_width_for_directx * mv_______->libav_c___the_height / 4;
		mv_______->libav_c___yPlane_kp = (Uint8*)malloc(mv_______->libav_c___yPlaneSz_kp);
		mv_______->libav_c___uPlane_kp = (Uint8*)malloc(mv_______->libav_c___uvPlaneSz_kp);
		mv_______->libav_c___vPlane_kp = (Uint8*)malloc(mv_______->libav_c___uvPlaneSz_kp);
		
		if (!mv_______->libav_c___yPlane_kp || !mv_______->libav_c___uPlane_kp || !mv_______->libav_c___vPlane_kp)
		{
			strcpy(mv_______->libav_c___amanda_video_thread_error_message_kp, "Error allocating memory");
			returnvalue_kp = 1028;
			goto saida_amanda_kp;
		}

		mv_______->libav_c___uvPitch_kp = mv_______->libav_c___adjusted_i_width_for_directx / 2;

	}

saida_amanda_kp:;

	mv_______->libav_c___amanda_video_thread_error_value_kp = returnvalue_kp;
	return returnvalue_kp;
}

long adjust_definitive_function_i(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	
		if(true)
		{

			mv_______->libav_c___window_was_set______i = true;

			if(mv_______->libav_c___is_desktop_playback_amanda && I_CENTER == mv_______->libav_c___show_in_position____i)
			{
								
				SetWindowPos(
					(HWND)(__INT32_OR_INT64)
					mv_______->libav_c___player_hwnd,
					WINDOW_FLAG___,
					(mv_______->libav_c___system_screen_w_____i - mv_______->libav_c___the_width) / 2,
					(mv_______->libav_c___system_screen_h_____i - mv_______->libav_c___the_height) / 2,
					mv_______->libav_c___the_width,
					mv_______->libav_c___the_height,
					(SHOW_FLAG__));

			}
			
			else if(mv_______->libav_c___is_desktop_playback_amanda && I_TOP__ == mv_______->libav_c___show_in_position____i)
			{
								
				SetWindowPos(
					(HWND)(__INT32_OR_INT64)
					mv_______->libav_c___player_hwnd,
					WINDOW_FLAG___,
					(mv_______->libav_c___system_screen_w_____i - mv_______->libav_c___the_width) / 2,
					0,
					mv_______->libav_c___the_width,
					mv_______->libav_c___the_height,
					(SHOW_FLAG__));

			}
			else if(mv_______->libav_c___is_desktop_playback_amanda && I_BOTTOM == mv_______->libav_c___show_in_position____i)
			{
								
				SetWindowPos(
					(HWND)(__INT32_OR_INT64)
					mv_______->libav_c___player_hwnd,
					WINDOW_FLAG___,
					(mv_______->libav_c___system_screen_w_____i - mv_______->libav_c___the_width) / 2,
					(mv_______->libav_c___system_screen_h_____i - mv_______->libav_c___the_height),
					mv_______->libav_c___the_width,
					mv_______->libav_c___the_height,
					(SHOW_FLAG__));
					
			}
			else
			{
				SetWindowPos(
				(HWND)(__INT32_OR_INT64)
				mv_______->libav_c___player_hwnd,
				WINDOW_FLAG___,
				mv_______->libav_c___adjust_left + (mv_______->libav_c___ajuste_width / 2),
				mv_______->libav_c___adjust_top + (mv_______->libav_c___ajuste_heigth / 2),
				mv_______->libav_c___the_width,
				mv_______->libav_c___the_height,
				(SHOW_FLAG__));
			}
			
		}
	return -27;
}

void adjust_video(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	if (IsWindow((HWND)(__INT32_OR_INT64)mv_______->libav_c___player_hwnd))
	{
		adjust_definitive_function_i(mv_______);
	}
}
void init_video(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                be_libav_struct *be_data)
{
	int ret_k_p;
	int i;

	pedro_dprintf(-1, "dentro de init video\n");
	mv_______->libav_c___reinit_uf = 0;
	mv_______->libav_c___reinit_uf2 = 0;

	mv_______->libav_c___video_ready_to_play = 0;

	if (mv_______->libav_c___disable_video || !mv_______->libav_c___player_hwnd || !mv_______->libav_c___hwnd)
	{
		goto saida;
	}

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}

	//pass_window_kp((__int64)(__INT32_OR_INT64)mv_______->libav_c___player_hwnd);

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}

	if (0 == mv_______->libav_c___canquit)
	{
		if (0 != SDL_Init(SDL_INIT_VIDEO))
		{
			pedro_dprintf(-1, "nao pode iniciar SDL_Init");
			goto saida;
		}
		else
		{
			pedro_dprintf(-1, "Iniciou sdl...");
		}
	}

	mv_______->libav_c___canquit = 1;

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}
	AVCodecContext *pCodecCtx = NULL;
	AVFormatContext *FormatContext =
		(AVFormatContext *)mv_______->libav_c___FormatContext_ptr_video;
	AVCodec *Codec = NULL;

	mv_______->libav_c___videostream = -1;

	mv_______->libav_c___dict_1_video = NULL;

	if (avformat_open_input(&FormatContext, be_data->sourcefile, NULL,
	                        (AVDictionary **)(NULL)) != 0)
	{
		strcpy(be_data->be_error_message, "Can't open the media file");

		goto saida;
	}

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}
	mv_______->libav_c___dict_2_video = NULL;
	if (0 >
	    avformat_find_stream_info(FormatContext,
	                              (AVDictionary **)(NULL)))
	{
		deinit2_video(mv_______);

		goto saida;
	}

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}
	mv_______->libav_c___FormatContext_ptr_video = (void *)FormatContext;
	for (i = 0; i < FormatContext->nb_streams; i++)
	{

		if (FormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
		{
			mv_______->libav_c___videostream = i;
			break;
		}
	}

	if (-1 == mv_______->libav_c___videostream)
	{
		goto saida;
	}

	pCodecCtx = avcodec_alloc_context3(NULL);

	if(!pCodecCtx)
	{
		mv_______->libav_c___pCodecCtx_ptr_video = pCodecCtx;
		goto saida;
	}

	/*

	   Aqui...
	   case kCodecH264:
	   case kCodecVP8:
	   // Normalize to three threads for 1080p content, then scale linearly
	   // with number of pixels.
	   // Examples:
	   // 4k: 12 threads
	   // 1440p: 5 threads
	   // 1080p: 3 threads
	   // anything lower than 1080p: 2 threads
	   desired_threads = config.coded_size().width() *
	   config.coded_size().height() * 3 / 1920 / 1080;

	   stolen from chrome sources

	 */

	pCodecCtx->thread_count = 0;        //very important

	if(FF_THREAD_SLICE & pCodecCtx->thread_type)
		pedro_dprintf(-1, "modes FF_THREAD_SLICE");

	if(FF_THREAD_FRAME & pCodecCtx->thread_type)
		pedro_dprintf(-1, "modes FF_THREAD_FRAME");

	//exit(1);
	/*
	   codec_context_->thread_type =
	   FF_THREAD_SLICE | (low_delay ? 0 : FF_THREAD_FRAME);
	   codec_context_->opaque = this;
	   codec_context_->get_buffer2 = GetVideoBufferImpl;

	 */

	ret_k_p = avcodec_parameters_to_context(pCodecCtx, FormatContext->streams[mv_______->libav_c___videostream]->codecpar);
	if (ret_k_p < 0)
	{
		goto saida;
	}

	mv_______->libav_c___pCodecCtx_ptr_video = pCodecCtx;

	strcpy(
		mv_______->libav_c___format_name,
		FormatContext->iformat->name);

	mv_______->libav_c___ticks = pCodecCtx->ticks_per_frame;

	Codec = (void *) avcodec_find_decoder(pCodecCtx->codec_id);

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}

	double den = FormatContext->streams[(int)mv_______->libav_c___videostream]->avg_frame_rate.den; //tag2
	double num = FormatContext->streams[(int)mv_______->libav_c___videostream]->avg_frame_rate.num;

	mv_______->libav_c___framerate = num / den;

	{
		double den = FormatContext->streams[(int)mv_______->libav_c___videostream]->time_base.den;
		double num = FormatContext->streams[(int)mv_______->libav_c___videostream]->time_base.num;
		mv_______->libav_c___video_timebase = num / den;
	}

	if (NULL == Codec)
	{
		pedro_dprintf(-1, "tambem deu erro em video");
		goto saida;
	}

	pedro_dprintf(-1, "Timebase %f", mv_______->libav_c___video_timebase);

	strcpy(mv_______->libav_c___video_codec, Codec->name ? Codec->name : "unknown");

	pedro_dprintf(-1, "codec %s", mv_______->libav_c___video_codec);

	mv_______->libav_c___is_flv = 0;

	sprintf(mv_______->libav_c___video_information +
	        strlen(mv_______->libav_c___video_information),
	        "rate %0.2f ", mv_______->libav_c___framerate);

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}
	if (avcodec_open2(pCodecCtx, Codec, NULL) < 0)
	{
		goto saida;
	}

	mv_______->analisys_c___string_position = strlen(mv_______->libav_c___video_information);

	////////////////////////////////////////////////////////

	if (adjust_window_position_and_size(mv_______))
	{
		goto saida;
	}

	mv_______->libav_c___old_x = mv_______->libav_c___adjust_left;
	mv_______->libav_c___old_y = mv_______->libav_c___adjust_top;
	mv_______->libav_c___old_width = mv_______->libav_c___size_of_window_width;
	mv_______->libav_c___old_height = mv_______->libav_c___size_of_window_height;

	mv_______->libav_c___old_ratio = mv_______->libav_c___the_ratio;
	mv_______->libav_c___old_adjusted_ratio = mv_______->libav_c___adjusted_ratio;

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}
	adjust_video(mv_______);
	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}
	mv_______->libav_c___request_for_adjust = 0;

/*  a clue my love...
        mv_______->libav_c___screen = (void *)SDL_SetVideoMode(mv_______->libav_c___the_width, mv_______->libav_c___the_height, 0, SDL_NOFRAME | SDL_SWSURFACE | SDL_RESIZABLE);

        if (mv_______->libav_c___screen == NULL)
        {

                mv_______->libav_c___video_ready_to_play = 0;

                goto saida;
        }
 */












/*
	
	if(mv_______->libav_c___texture_kp)
		SDL_DestroyTexture((SDL_Texture *)mv_______->libav_c___texture_kp), mv_______->libav_c___texture_kp = NULL;

	if(mv_______-> libav_c___renderer_kp)
		SDL_DestroyRenderer((SDL_Renderer *)mv_______-> libav_c___renderer_kp), mv_______-> libav_c___renderer_kp = NULL;

	if(mv_______->libav_c___screen_kp)
		SDL_DestroyWindow((SDL_Window *)mv_______->libav_c___screen_kp), mv_______->libav_c___screen_kp = NULL;

*/
	
	if(NULL != mv_______->libav_c___vPlane_kp)
	{
		free(mv_______->libav_c___vPlane_kp);
		mv_______->libav_c___vPlane_kp = NULL;
	}

	if(NULL != mv_______->libav_c___uPlane_kp)
	{
		free(mv_______->libav_c___uPlane_kp);
		mv_______->libav_c___uPlane_kp = NULL;
	}

	if(NULL != mv_______->libav_c___yPlane_kp)
	{
		free(mv_______->libav_c___yPlane_kp);
		mv_______->libav_c___yPlane_kp = NULL;
	}
	
	if(mv_______->libav_c___texture_kp)
	     SDL_DestroyTexture((SDL_Texture *)mv_______->libav_c___texture_kp), mv_______->libav_c___texture_kp = NULL;

	if(mv_______-> libav_c___renderer_kp)
	     SDL_DestroyRenderer((SDL_Renderer *)mv_______-> libav_c___renderer_kp), mv_______->libav_c___renderer_kp = NULL;

	if(mv_______->libav_c___screen_kp)
	     SDL_DestroyWindow((SDL_Window *)mv_______->libav_c___screen_kp), mv_______->libav_c___screen_kp = NULL;


	mv_______->libav_c___screen_kp = (void *) SDL_CreateWindowFrom((void *)mv_______->libav_c___player_hwnd);

	if (!mv_______->libav_c___screen_kp)
	{
	     pedro_dprintf(-1, "SDL: could not create window - exiting\n");
	     goto saida;
	}
	else
	{
	     pedro_dprintf(-1, "criou o window");
	}

	mv_______-> libav_c___renderer_kp = (void *) SDL_CreateRenderer((SDL_Window *)mv_______->libav_c___screen_kp, -1, SDL_RENDERER_ACCELERATED);
	if (!mv_______-> libav_c___renderer_kp)
	{
	     pedro_dprintf(-1, "SDL: could not create renderer - exiting\n");
	     goto saida;
	}
	else
	{
	     pedro_dprintf(-1, "criou o render");
	}

	{
	
		mv_______->libav_c___adjusted_i_width_for_directx = mv_______->libav_c___the_width;
		
		mv_______->libav_c___texture_kp = (void *) SDL_CreateTexture(
	     (SDL_Renderer *)mv_______->libav_c___renderer_kp,
	     SDL_PIXELFORMAT_YV12,
	     SDL_TEXTUREACCESS_STREAMING,
	     mv_______->libav_c___adjusted_i_width_for_directx,
	     mv_______->libav_c___the_height
	     );
	}
	if (!mv_______->libav_c___texture_kp)
	{
	     pedro_dprintf(-1, "SDL: could not create texture - exiting\n");
	     goto saida;
	}
	else
	{
	     pedro_dprintf(-1, "Criou a textura");
	}
	 	
	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}

/*
        mv_______->libav_c___bmp = (void *)SDL_CreateYUVOverlay(mv_______->libav_c___the_width, mv_______->libav_c___the_height,
                                                                SDL_YV12_OVERLAY, (SDL_Surface *)mv_______->libav_c___screen);

        if (NULL == mv_______->libav_c___bmp)
        {
                mv_______->libav_c___video_ready_to_play = 0;

                goto saida;
        }
 */

	mv_______->libav_c___ponto_inicial = -1;
	mv_______->libav_c___deslocacao = 0;
	mv_______->libav_c___skipframes = 0;
	mv_______->libav_c___frames_shown_1 = 0;
	mv_______->libav_c___frames_shown_2 = 0;
	mv_______->libav_c___video_thread_running = 0;
	mv_______->libav_c___pause_video_thread = 0;
	mv_______->libav_c___initiate_playback = 0;
	mv_______->libav_c___cancel_video_thread = 0;
	mv_______->libav_c___cancel_redea_thread = 0;

	if (mv_______->decoder_c___cancelflag)
	{
		goto saida;
	}

	video_player_thread(mv_______);

	while (!mv_______->libav_c___video_thread_running)
	{
		amanda_locked++;

		if(300 == amanda_locked)
		{
			break;
		}
		if (mv_______->libav_c___cancel_video_thread || mv_______->decoder_c___cancelflag)
		{
			break;
		}
		Sleep(10);
	}
	pedro_dprintf(-1, "nunca chega aqui");
	mv_______->libav_c___video_ready_to_play = 1;
saida:
	;

	return;
}

double update_bw_framerate(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	/* this function is broken, no use at the moment*/
	static int pos = 0;
	static double s1;
	static double s2;
	static double s3;
	//static double s4;
	double slice_1 = mv_______->libav_c___video_frame * mv_______->libav_c___video_timebase * 1000;
	//dprintf("slice %f\n",slice_1);

	///dprintf("called frame rate adjust _debug_\n");

	if (slice_1 >= 0)
	{

		if (0 == mv_______->libav_c___reinit_uf)
		{
			//pos=0;
			mv_______->libav_c___reinit_uf = 1;
			s1 = slice_1;
		}
		else
		{
			double tim = slice_1 - s1;

			if (0 == mv_______->libav_c___reinit_uf2)
			{
				mv_______->libav_c___reinit_uf2 = 1;
				pos = 0;
			}

			if (0 == pos)
			{
				s2 = tim;
			}
			else
			{
				s2 += tim;
			}
			pos++;
			if (30 == pos)
			{
				s3 = (s2) / 30.0;
				/*dprintf("time spent %f\n",(double)((double)1000.0/s3));*/
				pos = 0;
				mv_______->libav_c___reinit_uf = 0;

				return (double)((double)1000.0 / s3);
			}

			mv_______->libav_c___reinit_uf = 0;
		}
	}
	else
	{
		mv_______->libav_c___reinit_uf = 0;
	}

	return mv_______->libav_c___framerate;
}
enum maria_decoder_mode
{

	KOCI_DECODER_IS_LOADING,
	KOCI_DECODER_LOADED,
	KOCI_DECODER_THREAD_FINISHED,

};
enum pedro_status_player
{
	AMANDA_RICARDO_PLAYER_STATUS_ALREADY_PLAYED_AND_FREED,
	AMANDA_RICARDO_PLAYING,
};
enum pedro_status_decoder
{
	AMANDA_RICARDO_DECODER_DATA_IS_READY_TO_PLAY,
	AMANDA_RICARDO_DECODER_IS_WORKING//no player tem que setar para isto
};
typedef struct amandaricardo_koci_control1_
{
	__int64 junior_last_frame[2];
	char juliete_player_status[2];
	int maria_array_index_player;
	int aline_array_index_decoder;
	char juliete_decoder_status[2];
	double libav_c_amanda__video_frame[2];//ver no final como liberar a memoria alocada completamente
	AVFrame *pFrame_ptr_koci[2];
	AVPacket *packet_ptr_pereira[2];
} amandaricardo_koci_control1;

amandaricardo_koci_control1 mislaine_command;

AVFrame pict;

BOOL ar_koci_force_exit = FALSE;

AVFrame *pFrame_ptr_koci;
AVFrame *pFrame_ptr_koci_player;

__int64 junior_last_frame_forever;

AVPacket *packet_ptr_pereira_koci_forever;
AVPacket *packet_ptr_pereira_koci_forever_player;

AVCodecContext *pCodecCtx;
AVFormatContext *FormatContext;

AVSubtitle sub_amanda_;
AVSubtitle sub_ricardo;

bool alternating_i                     = false;
bool alternating_player_i              = false;

bool subtitle_1_amanda__decoder_in_use = false;
bool subtitle_2_ricardo_decoder_in_use = false;
bool subtitle_1_amanda__player__in_use = false;
bool subtitle_2_ricardo_player__in_use = false;

bool has_data_and_need_free_sub_i      = false;

char amandaricardo_koci_deslocador_decoder;

int libav_c____decoder_feline_running;

__int64 amandaricardo_koci_player_exited_at;

char maria_decoded_something;

int morcego_vermelho_player_thread_koci(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	
	AVCodecContext *pCodecCtx_sub_i = NULL;
	
	AVCodec *Codec_i = NULL;
	
	int ret_k_p;
	
	//int error_value_amanda;
	int got_frame_i     ;  
	__attribute__((unused)) int ret_i           ;
	int i_i             ;
	int count_i   =    0;
	int counter_z =    0;
	int the_subtitle_stream_i = -2;
	bool data_used_z = false;
	double amanda_tempo;
	int amandaricardo_used = 0;
	int frameFinished;
int i;
	
	mv_______->libav_c___pCodecCtx_sub_i = NULL;

	amandaricardo_koci_deslocador_decoder = 0;
	amandaricardo_koci_player_exited_at = 0;
	maria_decoded_something = 0;

	while(FALSE == mv_______->libav_c___player_ar_ready)
	{
		Sleep(1);
	}
	
	pedro_dprintf(-1, "dentro de decoder 2 ");
	libav_c____decoder_feline_running = KOCI_DECODER_LOADED;

	mv_______->libav_c___displacement_for_see_adjust_k_p = -1;


	if(0 != mv_______->libav_c___use_subtitles_track_i)
	{
		for (i_i = 0; i_i < FormatContext->nb_streams; i_i++)
			if (FormatContext->streams[i_i]->codecpar->codec_type == /*AVMEDIA_TYPE_AUDIO*/ AVMEDIA_TYPE_SUBTITLE)
			{
				
				count_i++; //...
				
				if(count_i == mv_______->libav_c___use_subtitles_track_i)
				{
					mv_______->libav_c___decode_subtitle       =                  true;
					the_subtitle_stream_i                      =                   i_i;
					mv_______->libav_c___the_subtitle_stream_i = the_subtitle_stream_i;
					
					
					
	pCodecCtx_sub_i = avcodec_alloc_context3(NULL);

	if(!pCodecCtx_sub_i)
	{
		pedro_dprintf(0, "malloc problem\n");
		exit(27);
	}
	mv_______->libav_c___pCodecCtx_sub_i = pCodecCtx_sub_i;
					
					ret_k_p = avcodec_parameters_to_context(pCodecCtx_sub_i, FormatContext->streams[the_subtitle_stream_i]->codecpar);
	if (ret_k_p < 0)
	{
		pedro_dprintf(0, "erro em avcodec_parameters_to_context\n");
		exit(27);
	}
					
					Codec_i = (void *) avcodec_find_decoder(pCodecCtx_sub_i->codec_id);
					
					if(NULL == Codec_i)
					{
						pedro_dprintf(0, "Erro em avcodec_find_decoder\n");
		exit(27);
					}
					
					if (avcodec_open2(pCodecCtx_sub_i, Codec_i, NULL) < 0)
	{
		pedro_dprintf(0, "Erro em avcodec_open2\n");
		exit(27);
	}
					
					
					pedro_dprintf(0, "Deu amor e o Ucraniano\n");
					//exit(27);
					
					
					
					break;
				}
			}
		
	}

	//pedro_dprintf(0, "found subtitle track at position %d\n", the_subtitle_stream_i);

mv_______->libav_c___the_sub_pointer_____i = (void *) &sub_amanda_;

	while (av_read_frame(FormatContext, packet_ptr_pereira_koci_forever) >=0)
	{
	 
	     data_used_z = false;
	     pedro_dprintf(-1, "dentro de decoder thread ");
	     if (mv_______->libav_c___cancel_video_thread || mv_______->decoder_c___cancelflag || ar_koci_force_exit)
	     {
			pedro_dprintf(-1, "Saiu no erro a %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);
			goto koci_finish;
	     }













//pedro_dprintf(0, "stream being decoded... %d\n", packet_ptr_pereira_koci_forever->stream_index);

if(-2 != the_subtitle_stream_i)
{
	
	//Mr. Do...
	if (packet_ptr_pereira_koci_forever->stream_index == the_subtitle_stream_i)
		{
			//pedro_dprintf(0, "1 THIS packet is mine...\n");
			
			if(has_data_and_need_free_sub_i)
			{
				pedro_dprintf(0, "dando free em sub\n");
				
				has_data_and_need_free_sub_i = false;
				
				while(subtitle_1_amanda__player__in_use)
				{
					Sleep(2);
				}
				
				avsubtitle_free(&sub_amanda_);
			}
			
			
			if(false == alternating_i)
			{
				//alternating_i = true;			
				
				while(true == subtitle_1_amanda__player__in_use)
				{
					Sleep(2);//while playing in video
				}
				
					subtitle_1_amanda__decoder_in_use = true;

					got_frame_i = 0;
					ret_i = avcodec_decode_subtitle2(pCodecCtx_sub_i, &sub_amanda_, &got_frame_i, packet_ptr_pereira_koci_forever);

					if(0 > ret_i)
					{
						;//do nothing
						pedro_dprintf(0, "erro %d\n", ret_i);
						
					}
					else
					{
						if(got_frame_i)
						{
							pedro_dprintf(0, "Frame got value %d\n", sub_amanda_.format);
							//exit(27);
							
							
							/*
							{
								AVSubtitleRect *srect = sub_amanda_.rects[0];
						
						Uint8 *p = srect->data[0];
						
						pedro_dprintf(0, "pegou %p\n", p);
						//exit(27);
							}
							{
								AVSubtitleRect *srect = sub_amanda_.rects[1];
						
						Uint8 *p = srect->data[0];
						
						pedro_dprintf(0, "pegou %p\n", p);
						exit(27);
							}
							*/
							

						AVSubtitleRect **rects = sub_amanda_.rects;
        for (i = 0; i < sub_amanda_.num_rects; i++) {
            AVSubtitleRect rect = *rects[i];
            if (rect.type == SUBTITLE_ASS) {
                pedro_dprintf(0, "ASS %s", rect.ass);
            } else if (rect.type == SUBTITLE_TEXT) {;
                pedro_dprintf(0, "TEXT %s", rect.text);
            }
        }
						
						
						
						
							
							has_data_and_need_free_sub_i = true;
							
						}
						else
						{
							pedro_dprintf(0, "Frame not got\n");
						}
					}

					subtitle_1_amanda__decoder_in_use = false;
			  
			}
			else
			{
				alternating_i = false;
				/*
				got_frame_i = 0;
				ret_i = avcodec_decode_subtitle2(pCodecCtx, &sub_ricardo, &got_frame_i, packet_ptr_pereira_koci_forever);
			  */
			  
			}
			
			//exit(27);
			
			
			
			
			
			
			
			
			
			
			
			//aqui para nao haver memory leak...
			av_packet_unref(packet_ptr_pereira_koci_forever);
			continue;
		}
}





		if (packet_ptr_pereira_koci_forever->stream_index == mv_______->libav_c___videostream)
		{

			double amanda_pts = packet_ptr_pereira_koci_forever->pts;

			if (mv_______->libav_c___cancel_video_thread || mv_______->decoder_c___cancelflag||ar_koci_force_exit)
			{
				pedro_dprintf(-1, "Saiu no erro b %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);
				goto koci_finish;
			}

			frameFinished = 0;

			amanda_tempo = get_bucaneiro_tick();

			amandaricardo_used = avcodec_send_packet(pCodecCtx, packet_ptr_pereira_koci_forever);
			if (amandaricardo_used < 0 && amandaricardo_used != AVERROR(EAGAIN) && amandaricardo_used != AVERROR_EOF)
			{
				pedro_dprintf(-1, "Saiu no erro 1 %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);
			}
			else
			{
				if (amandaricardo_used >= 0)
					packet_ptr_pereira_koci_forever->size = 0;

				amandaricardo_used = avcodec_receive_frame(pCodecCtx, pFrame_ptr_koci);
				if (amandaricardo_used >= 0)
					frameFinished = 1;

				pedro_dprintf(-1, "Antes de framefinished %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);

				if(frameFinished)
				{    
				     if(-1 == counter_z)
				     {
					  pedro_dprintf(-1, "ok\n");
				     }
					pedro_dprintf(-1, "tempo... %f", (get_bucaneiro_tick() - amanda_tempo) * 1000.);
					data_used_z = true;
				
					maria_decoded_something = 1;
					switch(amandaricardo_koci_deslocador_decoder)
					{
					case 0:
					{

						pedro_dprintf(-1, "Frame got 8.0 %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);

						while(AMANDA_RICARDO_DECODER_DATA_IS_READY_TO_PLAY == mislaine_command.juliete_decoder_status[mislaine_command.aline_array_index_decoder])// aonde verifica isto seta o AMANDA_RICARDO_DECODER_IS_WORKING
						{

							Sleep(1);
							if (mv_______->libav_c___cancel_video_thread || mv_______->decoder_c___cancelflag || ar_koci_force_exit)
							{
								pedro_dprintf(-1, "Frame got 8.1 %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);
								//av_packet_unref(packet);
								pedro_dprintf(-1, "saiu 8.2 %d %d",mv_______->libav_c___cancel_video_thread,  mv_______->decoder_c___cancelflag);
								goto koci_finish;

							}

						}
						junior_last_frame_forever++;
						mislaine_command.junior_last_frame[mislaine_command.aline_array_index_decoder] = junior_last_frame_forever;
						mislaine_command.libav_c_amanda__video_frame[mislaine_command.aline_array_index_decoder] = amanda_pts;
												
						mislaine_command.pFrame_ptr_koci[mislaine_command.aline_array_index_decoder] = pFrame_ptr_koci;
												
						pedro_dprintf(-1, "Frame got 2.a %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);
						pedro_dprintf(-1, "Frame internal address 2.b %p\n", pFrame_ptr_koci->data);
						
						mislaine_command.packet_ptr_pereira[mislaine_command.aline_array_index_decoder] = packet_ptr_pereira_koci_forever;
												
						mislaine_command.juliete_decoder_status[mislaine_command.aline_array_index_decoder] = AMANDA_RICARDO_DECODER_DATA_IS_READY_TO_PLAY;

						mislaine_command.aline_array_index_decoder++;

						mislaine_command.aline_array_index_decoder = mislaine_command.aline_array_index_decoder % 2;

						while(AMANDA_RICARDO_DECODER_DATA_IS_READY_TO_PLAY == mislaine_command.juliete_decoder_status[mislaine_command.aline_array_index_decoder])// aonde verifica isto seta o AMANDA_RICARDO_DECODER_IS_WORKING
						{

							Sleep(1);
							if (mv_______->libav_c___cancel_video_thread || mv_______->decoder_c___cancelflag || ar_koci_force_exit)
							{
								pedro_dprintf(-1, "Frame got 9.1 %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);
								//av_packet_unref(packet);
								pedro_dprintf(-1, "saiu 9.2 %d %d",mv_______->libav_c___cancel_video_thread,  mv_______->decoder_c___cancelflag);
								goto koci_finish;

							}
						}
						/*
							pFrame_ptr_koci = av_frame_alloc();
							packet_ptr_pereira_koci_forever = av_malloc(sizeof(AVPacket));
						*/
						pedro_dprintf(-1, "vai pegar o novo frame...\n");
						pFrame_ptr_koci = mislaine_command.pFrame_ptr_koci[mislaine_command.aline_array_index_decoder];
						packet_ptr_pereira_koci_forever = mislaine_command.packet_ptr_pereira[mislaine_command.aline_array_index_decoder];

						if(-1 != mv_______->libav_c___displacement_for_see_adjust_k_p)
						{
							int a_k_p = 0;
							int b_k_p = 0;
							//double videovalue_k_p = ((double)amanda_pts * (double)mv_______->libav_c___video_timebase * 1000.0 * 1000.0) + 2000000.0;
							//amanda_pts
							pedro_dprintf(-1, "Dando seek...%f", mv_______->libav_c___displacement_for_see_adjust_k_p);
							if((__int64)mv_______->libav_c___displacement_for_see_adjust_k_p >
							   mv_______->libav_c___duracao)
							{
								mv_______->libav_c___displacement_for_see_adjust_k_p =
									mv_______->libav_c___duracao - 1;
							}

							a_k_p = mv_______->libav_c___morcego =
								av_seek_frame (FormatContext, -1, (__int64) mv_______->libav_c___displacement_for_see_adjust_k_p,
								               AVSEEK_FLAG_BACKWARD);

							if (mv_______->libav_c___morcego < 0)
							{
								b_k_p = mv_______->libav_c___morcego =
									av_seek_frame (FormatContext, -1, (__int64) mv_______->libav_c___displacement_for_see_adjust_k_p,
									               AVSEEK_FLAG_BACKWARD | AVSEEK_FLAG_ANY);
							}
							mv_______->libav_c___displacement_for_see_adjust_k_p = -1;
							pedro_dprintf(-1, "Deu seek %d %d", a_k_p, b_k_p);
						}

					}

					break;
					case 1:
					{


					}

					break;
					case 2:
					{


					}

					break;
					case 3:
					{


					}

					break;
					default:
						assert(0 && "Invalid value for counter");
						break;
					}

					amandaricardo_koci_deslocador_decoder++;
					amandaricardo_koci_deslocador_decoder = amandaricardo_koci_deslocador_decoder % 4;
					amandaricardo_koci_deslocador_decoder = 0;//hack...
				}

				//aqui

			}

			/*e agora meu amor?...*/

		}
		while (mv_______->libav_c___is_seeking)
		{
			Sleep(15);
		}

		if(false == data_used_z)
		{
		     counter_z ++;
		     av_packet_unref(packet_ptr_pereira_koci_forever);
		     av_frame_unref (pFrame_ptr_koci);
		}
		
	}
		
	
	pedro_dprintf(-1, "Last pointer used io %p %p\n", pFrame_ptr_koci, packet_ptr_pereira_koci_forever);
	
koci_finish:
	;

	libav_c____decoder_feline_running = KOCI_DECODER_THREAD_FINISHED;
	return 0;
}
int morcego_vermelho_player_thread(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
    
     char flag_for_a_single_frame_playback_k = 0;
     double amanda_timer;

     DWORD style_kp;

     amanda_locked = 0;
	 mv_______->libav_c___the_subtitle_stream_i = -2;
	 mv_______->libav_c___decode_subtitle = false;

     mv_______->libav_c___video_thread_running = 1;

     mislaine_command.juliete_player_status[0] = AMANDA_RICARDO_PLAYER_STATUS_ALREADY_PLAYED_AND_FREED;
     mislaine_command.juliete_player_status[1] = AMANDA_RICARDO_PLAYER_STATUS_ALREADY_PLAYED_AND_FREED;
	
     mislaine_command.maria_array_index_player = 0;
     mislaine_command.aline_array_index_decoder = 0;

     mislaine_command.juliete_decoder_status[0] = AMANDA_RICARDO_DECODER_IS_WORKING;
     mislaine_command.juliete_decoder_status[1] = AMANDA_RICARDO_DECODER_IS_WORKING;
	
     mislaine_command.libav_c_amanda__video_frame[0] = 0.0;
     mislaine_command.libav_c_amanda__video_frame[1] = 0.0;
	
     mislaine_command.pFrame_ptr_koci[0] = av_frame_alloc();
     mislaine_command.pFrame_ptr_koci[1] = av_frame_alloc();
		
     mislaine_command.packet_ptr_pereira[0] = av_packet_alloc();
     mislaine_command.packet_ptr_pereira[1] = av_packet_alloc();
		
     pFrame_ptr_koci = mislaine_command.pFrame_ptr_koci[0];
     packet_ptr_pereira_koci_forever = mislaine_command.packet_ptr_pereira[0];
		
     junior_last_frame_forever = 0;

     mislaine_command.junior_last_frame[0] = -1;
     mislaine_command.junior_last_frame[1] = -1;
	
     double time_spent = get_bucaneiro_tick();

     double ajuste_de_sincronizacao = 0;

     double ajuste_de_sincronizacao_second = 0;

     int was_paused = 0; //do nothing
	                                                                                           //for your pleasure...
     int firstpass = 1;  //do nothing
     int dcounter3 = 0;
     __int64 ready_to_adjust = 0;
     int dcounter1 = 0;
     int dcounter2 = 0;

     __int64 free_to_adjust = 0;

     int dcounter4 = 0;
     int dcounter5 = 0;
		
     int e_counter_skip_valquiria = 0;

     BOOL disable_playback_delay_k_p = FALSE;

     double K_P_the_time = get_bucaneiro_tick();

     int ar_ret                    =     0;

     bool first_pass_z             = false;

     int update_me_z               =     0;

     int above_counter             =     0;

     int below_counter             =     0;
     ////////////////////////////////////////////////////////////////////////////////////////////////////////////
     /*as variaveis abaixo devem ser globais */
     pCodecCtx        =
	  (void *)mv_______->libav_c___pCodecCtx_ptr_video;
     FormatContext  =
	  (AVFormatContext *)mv_______->libav_c___FormatContext_ptr_video;
     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
     mv_______->libav_c___skipframes = 0;
     mv_______->libav_c___pause_counter = 0;

     ar_koci_force_exit = FALSE;
     mv_______->libav_c___player_ar_ready=TRUE;

//amanda_player : jump point for coding...

	mv_______->libav_c___pixel_format = pCodecCtx->pix_fmt;

	if(NULL != mv_______->libav_c___sc_kp)
	{
		sws_freeContext((struct SwsContext *)mv_______->libav_c___sc_kp);
		mv_______->libav_c___sc_kp = NULL;
	}

	mv_______->libav_c___sc_kp = (void *) sws_getContext(pCodecCtx->width, pCodecCtx->height,
	                                                     pCodecCtx->pix_fmt, mv_______->libav_c___adjusted_i_width_for_directx, mv_______->libav_c___the_height,
	                                                     AV_PIX_FMT_YUV420P,
	                                                     VIDEO_CONVERSION_MODE,
	                                                     NULL,
	                                                     NULL,
	                                                     NULL);

	if(NULL == mv_______->libav_c___sc_kp)
	{
		pedro_dprintf(-1, "Deu erro de memoria em sws_getContext()");
		goto finish;
	}
	else
	{
		pedro_dprintf(-1, "iniciou sws_getContext corretamente");
	}

	mv_______->libav_c___yPlaneSz_kp = mv_______->libav_c___adjusted_i_width_for_directx * mv_______->libav_c___the_height;
	mv_______->libav_c___uvPlaneSz_kp = mv_______->libav_c___adjusted_i_width_for_directx * mv_______->libav_c___the_height / 4;
	mv_______->libav_c___yPlane_kp = (Uint8*)malloc(mv_______->libav_c___yPlaneSz_kp);
	mv_______->libav_c___uPlane_kp = (Uint8*)malloc(mv_______->libav_c___uvPlaneSz_kp);
	mv_______->libav_c___vPlane_kp = (Uint8*)malloc(mv_______->libav_c___uvPlaneSz_kp);
	
	if (!mv_______->libav_c___yPlane_kp || !mv_______->libav_c___uPlane_kp || !mv_______->libav_c___vPlane_kp)
	{
		pedro_dprintf(-1, "Could not allocate pixel buffers - exiting\n");
		goto finish;
	}

	mv_______->libav_c___uvPitch_kp = mv_______->libav_c___adjusted_i_width_for_directx / 2;

final:
	;
	while (mv_______->libav_c___is_seeking)
	{

		ready_to_adjust = 0;

		ajuste_de_sincronizacao = 0;
		ajuste_de_sincronizacao_second = 0;

		mv_______->libav_c___ponto_inicial = -1;
		mv_______->libav_c___deslocacao = 0;
		mv_______->libav_c___skipframes = 0;
		mv_______->libav_c___frames_shown_1 = 0;
		mv_______->libav_c___frames_shown_2 = 0;
		Sleep(15);
	}

	while (1)
	{
		int sleeptime;

		if (1)
		{

			if (mv_______->libav_c___is_seeking)
			{
				ready_to_adjust = 0;
				ajuste_de_sincronizacao = 0;
				ajuste_de_sincronizacao_second = 0;
				mv_______->libav_c___ponto_inicial = -1;
				mv_______->libav_c___deslocacao = 0;
				mv_______->libav_c___skipframes = 0;
				mv_______->libav_c___frames_shown_1 = 0;
				mv_______->libav_c___frames_shown_2 = 0;
				goto final;
			}

			{
				pedro_dprintf(-1, "dentro de player thread 2");
				while(AMANDA_RICARDO_DECODER_DATA_IS_READY_TO_PLAY != mislaine_command.juliete_decoder_status[mislaine_command.maria_array_index_player])
				{
					Sleep(1);
					if (mv_______->libav_c___cancel_video_thread || mv_______->decoder_c___cancelflag)
					{
						pedro_dprintf(-1, "saiu 101 ");
						goto finish;
					}

					if(KOCI_DECODER_THREAD_FINISHED == libav_c____decoder_feline_running)
					{
						//Sleep(6000);
						if(0 == junior_last_frame_forever)
						{
							pedro_dprintf(-1, "Saindo porque nao decodificou frame nenhum");
							goto finish;
						}

						pedro_dprintf(-1, "player index %d decoder index %d\n", (int)mislaine_command.maria_array_index_player, (int)mislaine_command.aline_array_index_decoder-1);

						pedro_dprintf(-1, "last frame %lld\n", junior_last_frame_forever);

						/*
							if(false == already_frame_arp && 1 != junior_last_frame_forever)
							{
								pedro_dprintf(-1, "ajustando ultimo frame\n");
																
								already_frame_arp                     = true;
								
								mislaine_command.maria_array_index_player ++;
								
								mislaine_command.maria_array_index_player   ;
							}
*/

							pedro_dprintf(-1, "index de frames %d\n", (int) mislaine_command.maria_array_index_player);


						pedro_dprintf(-1, "frame sendo mostrado %d\n", (int) mislaine_command.junior_last_frame[mislaine_command.maria_array_index_player]);

						if(mislaine_command.junior_last_frame[mislaine_command.maria_array_index_player] == junior_last_frame_forever - 1)
						{
							pedro_dprintf(-1, "Saindo porque este eh o ultimo frame %I64d", junior_last_frame_forever);
							goto finish;
						}
						else
						{
							pedro_dprintf(-1, "O ultimo frame ainda nao foi exibido %I64d %I64d", mislaine_command.junior_last_frame[mislaine_command.maria_array_index_player], junior_last_frame_forever);
							//Sleep(500);
							if(1 != junior_last_frame_forever)
							{
								/*
								mislaine_command.maria_array_index_player ++;
								
								mislaine_command.maria_array_index_player %= 4;							
								*/

								mislaine_command.juliete_decoder_status[mislaine_command.maria_array_index_player] = AMANDA_RICARDO_DECODER_DATA_IS_READY_TO_PLAY;
							}
							else
							{

								pedro_dprintf(-1, "Modo eh unico frame %I64d", junior_last_frame_forever);
								//Sleep(500);
								//mv_______->libav_c___player_ar_only_one_frame_flag = 1;

								if(2 == mv_______->libav_c___player_ar_only_one_frame_flag)
								{
									pedro_dprintf(-1, "Saindo porque a flag de exit vindo de audio thread chegou");
									goto finish;
								}
								{
									pedro_dprintf(-1, "ta aqui o erro");
									static __int64 amanda_counter = 0;

									amanda_counter++;

									amanda_counter %= 250;

									if(0 == amanda_counter)
									{

										pedro_dprintf(-1, "ricardo, vai mostrar o último frame...");
										flag_for_a_single_frame_playback_k = 1;
									
										goto return_call_for_one_frame_only_playback_k;

										exit(25);//cannot call this...

return_jump_point_after_frame_shown_k:
										;

										flag_for_a_single_frame_playback_k = 0;

									}
								}
							}
						}
					}
				}
				//if(enable_debug_arp)
				/*
				{
					pedro_dprintf(-1, "addresses %lld %lld\n", mislaine_command.packet_ptr_pereira[mislaine_command.maria_array_index_player],
					mislaine_command.pFrame_ptr_koci[mislaine_command.maria_array_index_player]
					);					
				}*/
				
				packet_ptr_pereira_koci_forever_player = mislaine_command.packet_ptr_pereira[mislaine_command.maria_array_index_player];
				pFrame_ptr_koci_player = mislaine_command.pFrame_ptr_koci[mislaine_command.maria_array_index_player];

				mv_______->libav_c___video_frame = mislaine_command.libav_c_amanda__video_frame[mislaine_command.maria_array_index_player];
				pedro_dprintf(-1, "dentro de player thread 3");
			}

			if (1) //hack, as usual...
			{

				if (2 == mv_______->decoder_c___debug_flag)
				{

					Sleep(4000);

					mv_______->decoder_c___debug_flag = 0;
				}
				mv_______->libav_c___pause_counter = 0;

				while (mv_______->libav_c___pause_video_thread || !mv_______->libav_c___initiate_playback)
				{
					ready_to_adjust = 0;
					ajuste_de_sincronizacao = 0;
					ajuste_de_sincronizacao_second = 0;
					mv_______->libav_c___ponto_inicial = -1;

					mv_______->libav_c___deslocacao = 0;
					mv_______->libav_c___skipframes = 0;
					mv_______->libav_c___frames_shown_1 = 0;
					mv_______->libav_c___frames_shown_2 = 0;
					free_to_adjust = 0;

					time_spent = get_bucaneiro_tick();
					if (mv_______->libav_c___cancel_video_thread || mv_______->decoder_c___cancelflag)
					{
						pedro_dprintf(-1, "saiu 101 ");
						goto finish;
					}
					pedro_dprintf(-1, "dentro de player thread a1 initiate playback %d", mv_______->libav_c___initiate_playback);
					if (mv_______->libav_c___pause_video_thread)
					{

						if (mv_______->libav_c___pause_counter > 12)
						{
							mv_______->libav_c___pause_counter = 0;
						}
						mv_______->libav_c___pause_counter++;
						if (1 == mv_______->libav_c___pause_counter)
						{
							if (!mv_______->libav_c___donot_draw_video)
							{
								pedro_dprintf(-1, "dentro de player thread 3.1");

								/*
								   SDL_Rect rect;
								   //this line fix a weird bug that only appears in windows 8
								   bmp = mv_______->libav_c___bmp;

								   if (bmp)
								        ret = SDL_LockYUVOverlay(bmp);
								 */

								if (1)
								{

									pict.data[0] = mv_______->libav_c___yPlane_kp;
									pict.data[1] = mv_______->libav_c___uPlane_kp;
									pict.data[2] = mv_______->libav_c___vPlane_kp;
									pict.linesize[0] = mv_______->libav_c___adjusted_i_width_for_directx;
									pict.linesize[1] = mv_______->libav_c___uvPitch_kp;
									pict.linesize[2] = mv_______->libav_c___uvPitch_kp;

									if(NULL != mv_______->/*amanda*/ libav_c___renderer_kp &&
									   NULL != mv_______->libav_c___texture_kp &&
									   NULL != mv_______->libav_c___screen_kp &&
									   NULL != mv_______->libav_c___sc_kp)
									{
										amanda_timer = get_bucaneiro_tick();

										sws_scale((struct SwsContext *)mv_______->libav_c___sc_kp, (const uint8_t *const *)pFrame_ptr_koci_player->data, pFrame_ptr_koci_player->linesize,
										          0, pCodecCtx->height, pict.data, pict.linesize);
										pedro_dprintf(-1, "-tempo decorrido %f", (get_bucaneiro_tick() - amanda_timer) * 1000.);

										mv_______->libav_c___pixel_format = pCodecCtx->pix_fmt;

										//getbucaneiro_tick() %f dif %f--debug7\n",get_bucaneiro_tick(),(get_bucaneiro_tick()-time_spentb)*1000);

										amanda_timer = get_bucaneiro_tick();

										ar_ret = SDL_UpdateYUVTexture(
											(SDL_Texture *)mv_______->libav_c___texture_kp,
											NULL,
											mv_______->libav_c___yPlane_kp,
											mv_______->libav_c___adjusted_i_width_for_directx,
											mv_______->libav_c___uPlane_kp,
											mv_______->libav_c___uvPitch_kp,
											mv_______->libav_c___vPlane_kp,
											mv_______->libav_c___uvPitch_kp
											);

										if(0 != ar_ret)
										{
											pedro_dprintf(2, "Erro de SDL em SDL_UpdateYUVTexture : %s - linha: %d", SDL_GetError(), __LINE__);
										}

										ar_ret = SDL_RenderClear((SDL_Renderer *)mv_______->/*amanda*/ libav_c___renderer_kp);

										if(0 != ar_ret)
										{
											pedro_dprintf(2, "Erro de SDL em SDL_RenderClear : %s - linha: %d", SDL_GetError(), __LINE__);
										}

										ar_ret = SDL_RenderCopy((SDL_Renderer *)mv_______->/*amanda*/ libav_c___renderer_kp,
										                        (SDL_Texture *)mv_______->libav_c___texture_kp, NULL, NULL);

										if(0 != ar_ret)
										{
											pedro_dprintf(2, "Erro de SDL em SDL_RenderCopy : %s - linha: %d", SDL_GetError(), __LINE__);
										}

										SDL_RenderPresent((SDL_Renderer *)mv_______->/*amanda*/ libav_c___renderer_kp);
										pedro_dprintf(-1, "3 tempo decorrido %f", (get_bucaneiro_tick() - amanda_timer) * 1000.);


										if(get_device_lost_state_k())
										{
											static int lost_counter = 0;
											pedro_dprintf(-1, "device lost ... %d", lost_counter++);
											mv_______->libav_c___request_for_adjust = 1;
										}

									}
									else
									{
										pedro_dprintf(-1, "loopeando aguardando acquire");
										mv_______->libav_c___request_for_adjust = 1;
									}

								}

								final_adjust_fuction(mv_______);

							}
						}
					}
					Sleep(15);
				}
				pedro_dprintf(-1, "dentro de player thread a2");
				//dprintf("aqui 3.2   getbucaneiro_tick() %f dif %f--debug7\n",get_bucaneiro_tick(),(get_bucaneiro_tick()-time_spentb)*1000);
				if (was_paused)
				{
					was_paused = 0;
				}
				ready_to_adjust++;
				if (firstpass)
				{
					firstpass = 0;
				}

				if (mv_______->libav_c___cancel_video_thread || mv_______->decoder_c___cancelflag)
				{

					//av_packet_unref(packet);
					pedro_dprintf(-1, "saiu 102 ");
					pedro_dprintf(-1, "dentro de player thread saiu aqui");
					goto finish;
				}

				if (mv_______->libav_c___mode_is_free_play)
				{
					mv_______->libav_c___skipframes = 0; //to avoid the drop frames when no uadio is available
				}
				mv_______->libav_c___skipframes = 0;//hack...

				if ((0 == mv_______->libav_c___skipframes /*||mv_______->decoder_c___enablesoundtouch*/) && !mv_______->libav_c___donot_draw_video)
				{

					K_P_the_time = get_bucaneiro_tick();

					style_kp = GetWindowLong(GetParent((HWND)mv_______->libav_c___player_hwnd), GWL_STYLE);

					if (style_kp & WS_MINIMIZE)
					{
						;
					}
					else
					{

return_call_for_one_frame_only_playback_k:      //remenber it
						;
					
						pict.data[0] = mv_______->libav_c___yPlane_kp;
						pict.data[1] = mv_______->libav_c___uPlane_kp;
						pict.data[2] = mv_______->libav_c___vPlane_kp;
						pict.linesize[0] = mv_______->libav_c___adjusted_i_width_for_directx;
						pict.linesize[1] = mv_______->libav_c___uvPitch_kp;
						pict.linesize[2] = mv_______->libav_c___uvPitch_kp;

						amanda_timer = get_bucaneiro_tick();

						if(NULL != mv_______-> libav_c___renderer_kp &&
						   NULL != mv_______->libav_c___texture_kp &&
						   NULL != mv_______->libav_c___screen_kp &&
						   NULL != mv_______->libav_c___sc_kp)
						{

							sws_scale((struct SwsContext *)mv_______->libav_c___sc_kp, (const uint8_t *const *)pFrame_ptr_koci_player->data, pFrame_ptr_koci_player->linesize,
							          0, pCodecCtx->height, pict.data, pict.linesize);
							
							pedro_dprintf(-1, "w w y y %d %d %d %d\n", pCodecCtx->width, pFrame_ptr_koci_player->width,
							pCodecCtx->height, pFrame_ptr_koci_player->height);
							
							pedro_dprintf(-1, "-tempo decorrido %f", (get_bucaneiro_tick() - amanda_timer) * 1000.);

							mv_______->libav_c___pixel_format = pCodecCtx->pix_fmt;

							//getbucaneiro_tick() %f dif %f--debug7\n",get_bucaneiro_tick(),(get_bucaneiro_tick()-time_spentb)*1000);

							amanda_timer = get_bucaneiro_tick();

							//aqui mesmo...
							
							ar_ret = SDL_UpdateYUVTexture(
								(SDL_Texture *)mv_______->libav_c___texture_kp,
								NULL,
								mv_______->libav_c___yPlane_kp,
								mv_______->libav_c___adjusted_i_width_for_directx,
								mv_______->libav_c___uPlane_kp,
								mv_______->libav_c___uvPitch_kp,
								mv_______->libav_c___vPlane_kp,
								mv_______->libav_c___uvPitch_kp
								);

							if(0 != ar_ret)
							{
								pedro_dprintf(2, "Erro de SDL em SDL_UpdateYUVTexture : %s - linha: %d", SDL_GetError(), __LINE__);
							}
							
							ar_ret = SDL_RenderClear((SDL_Renderer *)mv_______->libav_c___renderer_kp);

							if(0 != ar_ret)
							{
								pedro_dprintf(2, "Erro de SDL em SDL_RenderClear : %s - linha: %d", SDL_GetError(), __LINE__);
							}
							
							ar_ret = SDL_RenderCopy((SDL_Renderer *)mv_______->libav_c___renderer_kp,
							                        (SDL_Texture *)mv_______->libav_c___texture_kp, NULL, NULL);

							if(0 != ar_ret)
							{
								pedro_dprintf(2, "Erro de SDL em SDL_RenderCopy : %s - linha: %d", SDL_GetError(), __LINE__);
							}
							
							SDL_RenderPresent((SDL_Renderer *)mv_______-> libav_c___renderer_kp);
							pedro_dprintf(-1, "3 tempo decorrido %f", (get_bucaneiro_tick() - amanda_timer) * 1000.);
							
							
							
							
							
							
							
							
							
							
							
							
									
									
									
									
									
									
									
									
									
									
									
									
									
									
									
									
									
									
									
									
									
								
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							if(get_device_lost_state_k())
							{
								static int lost_counter = 0;
								pedro_dprintf(-1, "device lost ... %d", lost_counter++);
								mv_______->libav_c___request_for_adjust = 1;
							}
							
						}
						else
						{
							pedro_dprintf(-1, "loopeando aguardando acquire");
							mv_______->libav_c___request_for_adjust = 1;
						}
						/*

						   we will keep for historical reasons...

						   pict.data[0] = bmp->pixels[0];
						   pict.data[1] = bmp->pixels[2];
						   pict.data[2] = bmp->pixels[1];

						   pict.linesize[0] = bmp->pitches[0];
						   pict.linesize[1] = bmp->pitches[2];
						   pict.linesize[2] = bmp->pitches[1];

						   pedro_dprintf(-1, "dentro de player thread 6");
						   sc = sws_getCachedContext(
						        sc,
						        pCodecCtx->width,
						        pCodecCtx->height,
						        pCodecCtx->pix_fmt,
						        mv_______->libav_c___the_width,
						        mv_______->libav_c___the_height,
						        AV_PIX_FMT_YUV420P,
						        SWS_BICUBIC, //SWS_FAST_BILINEAR is a fast option but low quality, better quality SWS_BICUBIC.
						        NULL,
						        NULL,
						        NULL);
						   pedro_dprintf(-1, "dentro de player thread 7");

						   sws_scale(sc, (const uint8_t *const *)pFrame_ptr_koci_player->data, pFrame_ptr_koci_player->linesize,
						          0, pCodecCtx->height, pict.data, pict.linesize);

						   pedro_dprintf(-1, "dentro de player thread 8");
						   SDL_UnlockYUVOverlay(bmp);


						   rect.x = 0;
						   rect.y = 0;
						   rect.w = mv_______->libav_c___the_width;
						   rect.h = mv_______->libav_c___the_height;
						   {
						        int val;
						        val = SDL_DisplayYUVOverlay(bmp, &rect);

						        pedro_dprintf(-1, "dentro de player thread 9");


						        if (-1 == val)
						        {

						                mv_______->libav_c___request_for_adjust = 1;
						        }
						   }
						 */
						/*aqui amor:?...sim minha linda, kkkkkk, */

						pedro_dprintf(-1, "DirectX time spent %f", get_bucaneiro_tick() - K_P_the_time);
						pedro_dprintf(-1, "dentro de player thread 10");

					}

					final_adjust_fuction(mv_______);

					if(flag_for_a_single_frame_playback_k)
					{					 
					     goto return_jump_point_after_frame_shown_k; //is it? ricardo...
					}

				}

				pedro_dprintf(-1, "Frame shown 10.-1 internal address %p\n", pFrame_ptr_koci_player->data);

				if(first_pass_z)
				{	
					av_packet_unref(packet_ptr_pereira_koci_forever_player);
					av_frame_unref (pFrame_ptr_koci_player);					
				}
				
				first_pass_z = true;
				
				pedro_dprintf(-1, "Frame shown 10.0 %p %p\n", pFrame_ptr_koci_player, packet_ptr_pereira_koci_forever_player);
				
				mislaine_command.juliete_decoder_status[mislaine_command.maria_array_index_player] = AMANDA_RICARDO_DECODER_IS_WORKING;

				mislaine_command.maria_array_index_player++;

				mislaine_command.maria_array_index_player = mislaine_command.maria_array_index_player % 2;
				
				//aqui...?
/*
				av_frame_free(&pFrame_ptr_koci_player);
				av_free(packet_ptr_pereira_koci_forever_player);
*/
			

				//dprintf("aqui 5   getbucaneiro_tick() %f dif %f--debug8\n",get_bucaneiro_tick(),(get_bucaneiro_tick()-time_spentb)*1000);
				//aqui4
				/*

				   int decoder_c___gpitch;
				   int decoder_c___grate;
				   int decoder_c___gtempo;
				   int decoder_c___enablesoundtouch;*/

				if (mv_______->decoder_c___enablesoundtouch)
				{

					if (mv_______->decoder_c___gtempo != mv_______->libav_c___old_tempo || mv_______->decoder_c___grate != mv_______->libav_c___old_rate)
					{

						mv_______->libav_c___old_tempo = mv_______->decoder_c___gtempo;
						mv_______->libav_c___old_rate = mv_______->decoder_c___grate;
						ready_to_adjust = 0;
						ajuste_de_sincronizacao = 0;
						ajuste_de_sincronizacao_second = 0;
						mv_______->libav_c___ponto_inicial = -1;
						mv_______->libav_c___deslocacao = 0;
						mv_______->libav_c___skipframes = 0;
						mv_______->libav_c___frames_shown_1 = 0;
						mv_______->libav_c___frames_shown_2 = 0;
					}

					int tempo_adjust = mv_______->decoder_c___gtempo + mv_______->decoder_c___grate;

					int direction = tempo_adjust >= 0 ? 1 : 0;

					int gtempo = abs(mv_______->decoder_c___gtempo + mv_______->decoder_c___grate);

					double ad = getvalf(
						mv_______->libav_c___framerate,
						gtempo);

					if (direction)
					{
						//dprintf("ajustou 1\n");
						mv_______->libav_c___ajusted_frame_rate = mv_______->libav_c___framerate + ad;
					}
					else
					{
						//dprintf("ajustou 2\n");
						mv_______->libav_c___ajusted_frame_rate = mv_______->libav_c___framerate - ad;
					}
					free_to_adjust = 8;
				}
				else
				{
					//dprintf("aqui deu ???\n");
					mv_______->libav_c___ajusted_frame_rate = mv_______->libav_c___framerate;
					//dprintf("apos!!! %f %f\n",mv_______->libav_c___ajusted_frame_rate,mv_______->libav_c___framerate);
					if (mv_______->libav_c___old_tempo != -1000)
					{
						mv_______->libav_c___old_tempo = -1000;
						mv_______->libav_c___old_rate = -1000;
						ready_to_adjust = 0;
						ajuste_de_sincronizacao = 0;
						ajuste_de_sincronizacao_second = 0;
						mv_______->libav_c___ponto_inicial = -1;
						mv_______->libav_c___deslocacao = 0;

						//dprintf("erro aqui linha %d"  "\n",__LINE__);

						mv_______->libav_c___skipframes = 0;
						mv_______->libav_c___frames_shown_1 = 0;
						mv_______->libav_c___frames_shown_2 = 0;
						free_to_adjust = 0;
					}
				}
				/*
				   if(
				   mv_______->
				   libav_c___is_flv) mv_______->libav_c___framerate
				   mv_______->libav_c___ajusted_frame_rate/=2;
				 */
				double ajustefinal = (1000.0 / mv_______->libav_c___ajusted_frame_rate);

				//dprintf("frame rate adjusted %f %f \n",mv_______->libav_c___ajusted_frame_rate,mv_______->libav_c___framerate);

				double veja = get_bucaneiro_tick() - ajuste_de_sincronizacao;

				if (-1 == mv_______->libav_c___ponto_inicial)
				{
					ajuste_de_sincronizacao = 0;
					veja = get_bucaneiro_tick();
					mv_______->libav_c___ponto_inicial = veja;
				}

				mv_______->libav_c___frames_shown_2 = ((get_bucaneiro_tick() - ajuste_de_sincronizacao) - mv_______->libav_c___ponto_inicial) * mv_______->libav_c___ajusted_frame_rate;

				int primeiro = mv_______->libav_c___frames_shown_1;
				int segundo = mv_______->libav_c___frames_shown_2 - 1;

				/**
				   dprintf_z("audio video frames %f shown %f",
				        ((((veja-mv_______->libav_c___ponto_inicial)/ajustefinal) *1000.0)),
				        mv_______->libav_c___frames_shown_1
				        );
				 */
				double definitivo;

				int deslocacao;

				double found = 1000.0 / mv_______->libav_c___ajusted_frame_rate;

				//dprintf("rate %f\n",mv_______->libav_c___ajusted_frame_rate);

				deslocacao = found;

#define DESLOCAMENTO___ 3

				if ((((veja - mv_______->libav_c___ponto_inicial) / ajustefinal) * 1000.0) > mv_______->libav_c___frames_shown_1)
				{
					//dprintf("ajustou****************");
					definitivo = 0;
					dcounter1 = 0;
					dcounter2 -= DESLOCAMENTO___;
				}
				else
				{
					//dprintf("normal***");
					definitivo = 0;
					dcounter1 += DESLOCAMENTO___;
					dcounter2 = 0;
				}

				//dprintf("ajuste %f",definitivo);
				//dprintf("aqui 9.5 getbucaneiro_tick() %f dif %f--sleep\n",get_bucaneiro_tick(),(get_bucaneiro_tick()-time_spent)*1000);
				time_spent = get_bucaneiro_tick() - time_spent;

				time_spent = time_spent * 1000;

				//dprintf("time spent %f",time_spent);

				double adjust = deslocacao + dcounter1 + dcounter2 - definitivo - time_spent; //correto
				//dprintf("timespent %f ---sleep\n",time_spent);
				{

					if (1)
					{
						if (
							mv_______->libav_c___video_frame > 0 && mv_______->libav_c___audio_frame > 0)
						{
							/*
							   dprintf_z("ajustes %f %f a %0.2f v %0.2f",posicao,dif,mv_______->libav_c___audio_frame,
							   mv_______->libav_c___video_frame
							   );*/

							double videovalue = mv_______->libav_c___video_frame * mv_______->libav_c___video_timebase * 1000;

							double audiovalue = mv_______->libav_c___audio_frame * mv_______->libav_c___audio_timebase * 1000;

							pedro_dprintf(-1, "Duration %I64d Video pos %f", mv_______->libav_c___duracao, videovalue);

							pedro_dprintf(-1, "audio timebase %f video timaebase %f videot %f audiot %f\n", audiovalue, videovalue, mv_______->libav_c___video_timebase, mv_______->libav_c___audio_timebase );

							//dprintf("videovalue and audiovalue %f %f  timebases %f %f_debug_\n",videovalue,audiovalue,mv_______->libav_c___video_timebase,mv_______->libav_c___audio_timebase);
							double posicao = mv_______->decoder_c___valor_de_deslocamento_de_audio * 1000;

							//posicao+=-120;bom

							posicao += -75; //magic value //quanto mais baixo mais o video adianta em relaï¿½ï¿½o ao audio

							posicao-= 100;
							
						        /*Use a suffix ï¿½qï¿½ or ï¿½Qï¿½ in printf for _float128.*/ __float128 dif = audiovalue - //__float128 is the 80 bits precison float type, we will be using it after now
							     videovalue;

							posicao += mv_______->libav_c___sync_adjust;

#define DEBUGMODE 0

							if(GetTickCount() > update_me_z)
							{
							     if (DEBUGMODE)
								  pedro_dprintf(-1, "valor de audio e video %f %f %f debugfixo\n", (double)dif, audiovalue, videovalue);

							}
							
							if (1500.0 < (double)dif)
							{
							     mv_______->syncstatus = 1;
							}

							mv_______->analisys_c___sync = dif;

							//tag1
							/*
							   int i = 0b1011;
							   dprintf_z("val %d\n",i);
							 */
							free_to_adjust++;
							if (free_to_adjust > 7)
							{

//#define AMANDA__FIXED_MILLISECONDS_VALUE 50 /* magic value */

#define AMANDA__FIXED_MILLISECONDS_VALUE 12 /* magic value */

								if (1)
								{
									if (!mv_______->libav_c___audio_finished) //if audio has finished playing no need to sinchronize anymore, just finish drawing the last frames
									{
										if (dif > posicao + AMANDA__FIXED_MILLISECONDS_VALUE)
										{
											dcounter1 = 0;
											dcounter2 = 0;
											dcounter4++;
											if (dcounter4 > 3)
											{

												e_counter_skip_valquiria++;
												ajuste_de_sincronizacao_second -= BE_PTS_ADJUST______;
												ajuste_de_sincronizacao -= BE_PTS_ADJUST______;
											        above_counter++;
												if (DEBUGMODE)
												     pedro_dprintf(1, "**ajustou pra cima debugfixo dif %f pos %f\n", (double) dif, (double) posicao );
												/*com atraso no playback ajusta para cima*/

												if(mv_______->libav_c___enable_slow_computers_hack_k_p)
												{
													if(15 < e_counter_skip_valquiria && ((double) dif - (double) posicao) > 100)
													{
														disable_playback_delay_k_p = TRUE;
														/*
														   parte do problema foi resolvido
														 */
														mv_______->libav_c___displacement_for_see_adjust_k_p = audiovalue * 1000 + 500000;
														e_counter_skip_valquiria = 0;
													}
												}
											}
										}
										else
										{
											if (DEBUGMODE)
												pedro_dprintf(2, "@@@@@@reset ajuste para cima %d\n", dcounter4);
											dcounter4 = 0;
											e_counter_skip_valquiria = 0;
										}
										if (dif < posicao - AMANDA__FIXED_MILLISECONDS_VALUE)
										{
											double ajuste___;
											dcounter1 = 0;
											dcounter2 = 0;
											ajuste___ = get_bucaneiro_tick();

											dcounter3++;

											if (dcounter3 > 15)
											{
											     below_counter++;
											     if (DEBUGMODE)
												  pedro_dprintf(1, "ajustou pra baixo forcado *************"); //só pode acontecer com arquivos mal codificados, e isto tem bastante, onde o pts de audio e video muda para valores inesperados, mas agora isto nao causa problemas mais

											     if (!mv_______->libav_c___is_flv)
											     {
												  if(FALSE == disable_playback_delay_k_p)
												  {
												       pedro_dprintf(-1, "Aqui...");
												       Sleep(100);
													}
													else
													{
														if (DEBUGMODE)
															pedro_dprintf(1, "disable_playback_delay_k_p == true");
													}
												}
											}
											dcounter5++;

											if (dcounter5 > 3)
											{
											     below_counter++;
												  if (DEBUGMODE)
												  pedro_dprintf(1, "ajustou pra baixo , oque** debugfixo\n");

											     Sleep(15); //0.015

											}

											ajuste___ = get_bucaneiro_tick() - ajuste___;
											ajuste_de_sincronizacao_second += ajuste___;
											ajuste_de_sincronizacao += ajuste___;
										}
										else
										{
											if (DEBUGMODE)
												pedro_dprintf(1, "####reset ajuste para baixo %d %d\n", dcounter3, dcounter5);
											dcounter5 = 0;
											dcounter3 = 0;
										}
									}
								}
							}
							else
							{
								//dprintf("faltando pts **********************             ***********************");
							}
						}
					}
				}


				if(GetTickCount() > update_me_z)
				{

				     pedro_dprintf(-1, "acima  ajustes %d\n", above_counter);
				     pedro_dprintf(-1, "abaixo ajustes %d\n", below_counter);

				     above_counter = 0;
				     below_counter = 0;
				     
				     update_me_z = 	GetTickCount() + 1000;     
				}
				
				adjust = ceil(adjust);

				adjust = adjust - 3; //interesting magic value

				if (adjust < 0)
				{
					adjust = 2;
				}

				if (mv_______->libav_c___skipframes)
				{
					//dprintf("skip frames---sleep\n");
					adjust = 1;
				}

				if (adjust <= 0)
				{
					//dprintf("skip frame 1******************************************************---sleep");
					mv_______->libav_c___skipframes = 1;
				}
				else
				{
					if (segundo > primeiro)
					{
						///dprintf("skip frame 2 ***********************************************%d %d debug2",primeiro,segundo);
						mv_______->libav_c___skipframes = 2;
					}
					else
					{
						mv_______->libav_c___skipframes = 0;
						sleeptime = (int)adjust;
						if (DEBUGMODE)
							pedro_dprintf(1, "sleep time %d\n", sleeptime);
						Sleep(sleeptime);
						if (2 == sleeptime)
						{
							mv_______->libav_c___skipframes = 3;
						}
					}
				}

				//dprintf("skipframes *** %d %s- debug7\n",mv_______->libav_c___skipframes,mv_______->libav_c___skipframes? "TRUE":"FALSE***");
				mv_______->libav_c___frames_shown_1++;
			}
			time_spent = get_bucaneiro_tick();
			//dprintf("aqui 10   getbucaneiro_tick() %f--debug3\n",time_spent);

			//time_spentb=get_bucaneiro_tick();

			//dprintf("aqui 0   getbucaneiro_tick() %f dif %f--debug8\n",get_bucaneiro_tick(),(get_bucaneiro_tick()-time_spentb)*1000);
		}
		//aqui 9
		//av_packet_unref(packet);

	}
//aqui6
finish:
	;

	if(NULL != mv_______->libav_c___sc_kp)
	{
		sws_freeContext((struct SwsContext *)mv_______->libav_c___sc_kp);
		mv_______->libav_c___sc_kp = NULL;
	}
	
	if(mv_______->libav_c___texture_kp)
		SDL_DestroyTexture((SDL_Texture *)mv_______->libav_c___texture_kp), mv_______->libav_c___texture_kp = NULL;
	pedro_dprintf(-1, "saiu thread player 0c");
	if(mv_______->libav_c___renderer_kp)
		SDL_DestroyRenderer((SDL_Renderer *)mv_______->libav_c___renderer_kp), mv_______->libav_c___renderer_kp = NULL;
	pedro_dprintf(-1, "saiu thread player 0d");
	if(mv_______->libav_c___screen_kp)
		SDL_DestroyWindow((SDL_Window *)mv_______->libav_c___screen_kp), mv_______->libav_c___screen_kp = NULL;
	pedro_dprintf(-1, "saiu thread player 0e");
	
	
	if(NULL != mv_______->libav_c___vPlane_kp)
	{
		free(mv_______->libav_c___vPlane_kp);
		mv_______->libav_c___vPlane_kp = NULL;
	}
	pedro_dprintf(-1, "saiu thread player 0f");
	if(NULL != mv_______->libav_c___uPlane_kp)
	{
		free(mv_______->libav_c___uPlane_kp);
		mv_______->libav_c___uPlane_kp = NULL;
	}
	pedro_dprintf(-1, "saiu thread player 0g");
	if(NULL != mv_______->libav_c___yPlane_kp)
	{
		free(mv_______->libav_c___yPlane_kp);
		mv_______->libav_c___yPlane_kp = NULL;
	}
	pedro_dprintf(-1, "saiu thread player 0h");
	pedro_dprintf(-1, "saiu thread player 1");

	while(KOCI_DECODER_THREAD_FINISHED != libav_c____decoder_feline_running)
	{
		Sleep(1);
		ar_koci_force_exit = TRUE;
		//mv_______->decoder_c___cancelflag = TRUE;
	}

	av_frame_free(&mislaine_command.pFrame_ptr_koci[0]);
	av_frame_free(&mislaine_command.pFrame_ptr_koci[1]);
	
	av_packet_free(&mislaine_command.packet_ptr_pereira[0]);
	av_packet_free(&mislaine_command.packet_ptr_pereira[1]);
	
	mv_______->libav_c___video_thread_running = 0;
	mv_______->decoder_c___cancelflag = 0;
	ar_koci_force_exit = FALSE;

	//amanda_final
	return 0;
}

void deinit2_video(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	pedro_dprintf(-1, "chamou deinit2_video");
	if (1 == mv_______->libav_c___video_ready_to_play)
	{
		mv_______->libav_c___cancel_video_thread = 1;
		while (mv_______->libav_c___video_thread_running)
		{
			Sleep(15);
		}
		mv_______->libav_c___cancel_video_thread = 0;
	}

	AVCodecContext *pCodecCtx =
		(void *)mv_______->libav_c___pCodecCtx_ptr_video;
	AVFormatContext *FormatContext =
		(AVFormatContext *)mv_______->libav_c___FormatContext_ptr_video;

	/*
	   SDL_Overlay *bmp = (void *)mv_______->libav_c___bmp;
	   if (bmp)
	   {
	        SDL_FreeYUVOverlay(bmp);
	        mv_______->libav_c___bmp = NULL;
	   }
	 */
	if (FormatContext)
	{
		
		
		
		if (pCodecCtx)
		{
			avcodec_free_context(&pCodecCtx);
			pCodecCtx = NULL;
			mv_______->libav_c___pCodecCtx_ptr_video = NULL;
		}
		
		pCodecCtx = (void *) mv_______->libav_c___pCodecCtx_sub_i;
		
		if(pCodecCtx)
		{
			pedro_dprintf(0, "free on sub\n");
			avcodec_free_context(&pCodecCtx);
			mv_______->libav_c___pCodecCtx_sub_i = NULL;
		}
		
		avformat_close_input(&FormatContext);

		FormatContext = NULL;
		mv_______->libav_c___FormatContext_ptr_video = NULL;
	}

}
static int __stdcall init_decoder(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	return morcego_vermelho_player_thread(mv_______);
}
static int __stdcall init_decoder_koci(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	return morcego_vermelho_player_thread_koci(mv_______);
}
static int __stdcall video_player_thread(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	int amanda_ret = av_cpu_count();

	pedro_dprintf(-1, "contagem de CPU %d", amanda_ret);

	HANDLE myhandle;
	__INT32_OR_INT64 ThreadId;

	libav_c____decoder_feline_running = KOCI_DECODER_IS_LOADING;

	mv_______->libav_c___player_ar_ready = FALSE;
	pedro_dprintf(-1, "chamou video_player_thread");
	myhandle = CreateThread(
		(LPSECURITY_ATTRIBUTES)0,
		0,
		(LPTHREAD_START_ROUTINE)init_decoder,
		(LPVOID)mv_______,
		0,
		(LPDWORD)&ThreadId);
	CloseHandle(myhandle);
	myhandle = CreateThread(
		(LPSECURITY_ATTRIBUTES)0,
		0,
		(LPTHREAD_START_ROUTINE)init_decoder_koci,
		(LPVOID)mv_______,
		0,
		(LPDWORD)&ThreadId);
	CloseHandle(myhandle);
	return 0;
}
__int64 espaco_no_tempo()
{
	char mes[300];
	SYSTEMTIME lst =
	{
		0,
	};
	GetLocalTime(&lst);

	LARGE_INTEGER second;
	/*
	   BOOL SystemTimeToFileTime(

	   CONST SYSTEMTIME *lpSystemTime,	// address of system time to convert
	   LPFILETIME lpFileTime        // address of buffer for converted file time
	   );
	 */
	SystemTimeToFileTime(&lst, (LPFILETIME)&second);
	sprintf(mes, "%lld", second.QuadPart);
	return strtoll(mes, NULL, 10) / 10000;
}
char *get_pixel_format_info___(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	switch (mv_______->libav_c___pixel_format)
	{
	/*
	   case AV_PIX_FMT_NONE:
	   return "NONE";
	   break;
	   case AV_PIX_FMT_YUV420P:
	   return "YUV420P";
	   break;
	   case AV_PIX_FMT_YUYV422:
	   return "YUYV422";
	   break;
	   case AV_PIX_FMT_RGB24:
	   return "RGB24";
	   break;
	   case AV_PIX_FMT_BGR24:
	   return "BGR24";
	   break;
	   case AV_PIX_FMT_YUV422P:
	   return "YUV422P";
	   break;
	   case AV_PIX_FMT_YUV444P:
	   return "YUV444P";
	   break;
	   case AV_PIX_FMT_YUV410P:
	   return "YUV410P";
	   break;
	   case AV_PIX_FMT_YUV411P:
	   return "YUV411P";
	   break;
	   case AV_PIX_FMT_GRAY8:
	   return "GRAY8";
	   break;
	   case AV_PIX_FMT_MONOWHITE:
	   return "MONOWHITE";
	   break;
	   case AV_PIX_FMT_MONOBLACK:
	   return "MONOBLACK";
	   break;
	   case AV_PIX_FMT_PAL8:
	   return "PAL8";
	   break;
	   case AV_PIX_FMT_YUVJ420P:
	   return "YUVJ420P";
	   break;
	   case AV_PIX_FMT_YUVJ422P:
	   return "YUVJ422P";
	   break;
	   case AV_PIX_FMT_YUVJ444P:
	   return "YUVJ444P";
	   break;
	   case AV_PIX_FMT_XVMC_MPEG2_MC:
	   return "XVMC_MPEG2_MC";
	   break;
	   case AV_PIX_FMT_XVMC_MPEG2_IDCT:
	   return "XVMC_MPEG2_IDCT";
	   break;
	   case AV_PIX_FMT_UYVY422:
	   return "UYVY422";
	   break;
	   case AV_PIX_FMT_UYYVYY411:
	   return "UYYVYY411";
	   break;
	   case AV_PIX_FMT_BGR8:
	   return "BGR8";
	   break;
	   case AV_PIX_FMT_BGR4:
	   return "BGR4";
	   break;
	   case AV_PIX_FMT_BGR4_BYTE:
	   return "BGR4_BYTE";
	   break;
	   case AV_PIX_FMT_RGB8:
	   return "RGB8";
	   break;
	   case AV_PIX_FMT_RGB4:
	   return "RGB4";
	   break;
	   case AV_PIX_FMT_RGB4_BYTE:
	   return "RGB4_BYTE";
	   break;
	   case AV_PIX_FMT_NV12:
	   return "NV12";
	   break;
	   case AV_PIX_FMT_NV21:
	   return "NV21";
	   break;
	   case AV_PIX_FMT_ARGB:
	   return "ARGB";
	   break;
	   case AV_PIX_FMT_RGBA:
	   return "RGBA";
	   break;
	   case AV_PIX_FMT_ABGR:
	   return "ABGR";
	   break;
	   case AV_PIX_FMT_BGRA:
	   return "BGRA";
	   break;
	   case AV_PIX_FMT_GRAY16BE:
	   return "GRAY16BE";
	   break;
	   case AV_PIX_FMT_GRAY16LE:
	   return "GRAY16LE";
	   break;
	   case AV_PIX_FMT_YUV440P:
	   return "YUV440P";
	   break;
	   case AV_PIX_FMT_YUVJ440P:
	   return "YUVJ440P";
	   break;
	   case AV_PIX_FMT_YUVA420P:
	   return "YUVA420P";
	   break;
	   case AV_PIX_FMT_VDPAU_H264:
	   return "VDPAU_H264";
	   break;
	   case AV_PIX_FMT_VDPAU_MPEG1:
	   return "VDPAU_MPEG1";
	   break;
	   case AV_PIX_FMT_VDPAU_MPEG2:
	   return "VDPAU_MPEG2";
	   break;
	   case AV_PIX_FMT_VDPAU_WMV3:
	   return "VDPAU_WMV3";
	   break;
	   case AV_PIX_FMT_VDPAU_VC1:
	   return "VDPAU_VC1";
	   break;
	   case AV_PIX_FMT_RGB48BE:
	   return "RGB48BE";
	   break;
	   case AV_PIX_FMT_RGB48LE:
	   return "RGB48LE";
	   break;
	   case AV_PIX_FMT_RGB565BE:
	   return "RGB565BE";
	   break;
	   case AV_PIX_FMT_RGB565LE:
	   return "RGB565LE";
	   break;
	   case AV_PIX_FMT_RGB555BE:
	   return "RGB555BE";
	   break;
	   case AV_PIX_FMT_RGB555LE:
	   return "RGB555LE";
	   break;
	   case AV_PIX_FMT_BGR565BE:
	   return "BGR565BE";
	   break;
	   case AV_PIX_FMT_BGR565LE:
	   return "BGR565LE";
	   break;
	   case AV_PIX_FMT_BGR555BE:
	   return "BGR555BE";
	   break;
	   case AV_PIX_FMT_BGR555LE:
	   return "BGR555LE";
	   break;
	   case AV_PIX_FMT_VAAPI_MOCO:
	   return "VAAPI_MOCO";
	   break;
	   case AV_PIX_FMT_VAAPI_IDCT:
	   return "VAAPI_IDCT";
	   break;
	   case AV_PIX_FMT_VAAPI_VLD:
	   return "VAAPI_VLD";
	   break;
	   case AV_PIX_FMT_YUV420P16LE:
	   return "YUV420P16LE";
	   break;
	   case AV_PIX_FMT_YUV420P16BE:
	   return "YUV420P16BE";
	   break;
	   case AV_PIX_FMT_YUV422P16LE:
	   return "YUV422P16LE";
	   break;
	   case AV_PIX_FMT_YUV422P16BE:
	   return "YUV422P16BE";
	   break;
	   case AV_PIX_FMT_YUV444P16LE:
	   return "YUV444P16LE";
	   break;
	   case AV_PIX_FMT_YUV444P16BE:
	   return "YUV444P16BE";
	   break;
	   case AV_PIX_FMT_VDPAU_MPEG4:
	   return "VDPAU_MPEG4";
	   break;
	   case AV_PIX_FMT_DXVA2_VLD:
	   return "DXVA2_VLD";
	   break;
	   case AV_PIX_FMT_RGB444LE:
	   return "RGB444LE";
	   break;
	   case AV_PIX_FMT_RGB444BE:
	   return "RGB444BE";
	   break;
	   case AV_PIX_FMT_BGR444LE:
	   return "BGR444LE";
	   break;
	   case AV_PIX_FMT_BGR444BE:
	   return "BGR444BE";
	   break;
	   case AV_PIX_FMT_Y400A:
	   return "Y400A";
	   break;
	   case AV_PIX_FMT_BGR48BE:
	   return "BGR48BE";
	   break;
	   case AV_PIX_FMT_BGR48LE:
	   return "BGR48LE";
	   break;
	   case AV_PIX_FMT_YUV420P9BE:
	   return "YUV420P9BE";
	   break;
	   case AV_PIX_FMT_YUV420P9LE:
	   return "YUV420P9LE";
	   break;
	   case AV_PIX_FMT_YUV420P10BE:
	   return "YUV420P10BE";
	   break;
	   case AV_PIX_FMT_YUV420P10LE:
	   return "YUV420P10LE";
	   break;
	   case AV_PIX_FMT_YUV422P10BE:
	   return "YUV422P10BE";
	   break;
	   case AV_PIX_FMT_YUV422P10LE:
	   return "YUV422P10LE";
	   break;
	   case AV_PIX_FMT_YUV444P9BE:
	   return "YUV444P9BE";
	   break;
	   case AV_PIX_FMT_YUV444P9LE:
	   return "YUV444P9LE";
	   break;
	   case AV_PIX_FMT_YUV444P10BE:
	   return "YUV444P10BE";
	   break;
	   case AV_PIX_FMT_YUV444P10LE:
	   return "YUV444P10LE";
	   break;
	   case AV_PIX_FMT_YUV422P9BE:
	   return "YUV422P9BE";
	   break;
	   case AV_PIX_FMT_YUV422P9LE:
	   return "YUV422P9LE";
	   break;
	   case AV_PIX_FMT_YUV422P9LE+1:
	   return "BE Special Pixel Format";
	   break;*/
	case 1000:
		return "None";
		break;
	}
	return "unknown";
}
#include "playlist.c"
/*
   double frame_rate(morcego___i___instance__a__bucaneiro_engineering * mv_______,
                  be_libav_struct * be_data, int video_stream_)
   {
        double fr=25;
        AVCodecContext *pCodecCtx = NULL;
        AVFormatContext *FormatContext = NULL;
        AVCodec *Codec = NULL;
        mv_______->libav_c___dict_1_video=NULL;

        if (avformat_open_input
                    (&FormatContext, be_data->sourcefile, NULL,
                    (AVDictionary **) (&mv_______->libav_c___dict_1_video)) != 0)
        {
                strcpy (be_data->be_error_message, "Canï¿½t open the media file");
                goto saida;
        }
        mv_______->libav_c___dict_2_video = NULL;
        if (0 >
            avformat_find_stream_info (FormatContext,
                                       (AVDictionary **) (&mv_______->
                                                          libav_c___dict_2_video)))
        {
                goto saida;
        }

        pCodecCtx =
                FormatContext->streams[video_stream_]->codec;

        Codec = avcodec_find_decoder (pCodecCtx->codec_id);

        if (NULL == Codec)
        {
                goto saida;
        }

        double dur=FormatContext->duration;

        AVFrame *pFrame;
        pFrame = avcodec_alloc_frame ();

        AVPacket *packet=av_malloc(sizeof(AVPacket));

        fr=0;
        while ( (FormatContext, packet) >= 0)
        {
                if (packet->stream_index == video_stream_)
                {
                        if(packet->pts>0)
                                dur=packet->pts;
                        fr++;

                        if(fr>15000)
                        {
                                av_free_packet (packet);
                                break;
                        }
                }
                av_free_packet (packet);
        }

        if(0==fr)
                fr=1;

        dur=dur*mv_______->libav_c___video_timebase;

        fr=fr/dur;

        av_free(pFrame);
        av_free(packet);

   saida:
        ;
        if (FormatContext)
        {
                if (pCodecCtx)
                {
                        avcodec_close (pCodecCtx);
                        pCodecCtx = NULL;
                }
                av_close_input_file (FormatContext);
                FormatContext = NULL;
        }
        return fr;
   }
 */
