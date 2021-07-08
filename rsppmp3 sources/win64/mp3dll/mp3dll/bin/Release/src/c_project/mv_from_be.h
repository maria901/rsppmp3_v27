
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
 
#include /* amanda's smart ape */ <windows.h>
#include /* amanda's smart ape  */ <stdint.h>
#include /* amanda's smart ape   */ <stdio.h>
#include /* amanda's smart ape  */ <stdlib.h>
#include /* amanda's smart ape  */ <string.h>
#include /* amanda's smart ape    */ <time.h>
#include /* amanda's smart ape   */ <errno.h>
#include /* amanda's smart ape   */ <fcntl.h>
#include /* amanda's smart ape   */ <ctype.h>
#include /* amanda's smart ape    */ <math.h>
#include /* amanda's smart ape  */ <wctype.h>
#include /* amanda's smart ape   */ <wchar.h>
#include /* amanda's smart ape  */ <stdarg.h>
#include /* amanda's smart ape  */ <stddef.h>
#include /* amanda's smart ape  */ <setjmp.h>
#include /* amanda's smart ape  */ <locale.h>
#include /* amanda's smart ape  */ <signal.h>
#include /* amanda's smart ape  */ <limits.h>
#include /* amanda's smart ape   */ <float.h>
#include /* amanda's smart ape  */ <iso646.h>

#undef NDEBUG
#include /* amanda's smart ape  */ <assert.h>
#include /* amanda's smart ape */ <stdbool.h>
#include /* amanda's smart ape */ <process.h>

#include "win64.h"

#ifndef MORCEGO___I___INSTANCE__A__BUCANEIRO_ENGINEERING__
#define MORCEGO___I___INSTANCE__A__BUCANEIRO_ENGINEERING__
/**
 * Função pra imprimir dados para o cara...
 *
 * @param amanda_level acima de -1 mostra os dados
 * 
 * @param format       printf based data
 * 
 */
extern void pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

enum be_normalization_flags___
{
	BE_CLEAR____,
	BE_PROCESS___,
	BE_RETRIEVE_NORMALIZATION_VALUE,
	BE_AMANDARICARDO_KOCI_PEREIRA_COMMAND
}
;

#define BE_PTS_ADJUST______ (0.015)
#define BE_PTS_ADJUST_2______ (0.5)

#define BE__FFT_ADJUST___ (8000.0)

#define BucaneiroMax(a,b) ((a)>(b) ? (a) : (b))

#define MAXIMUM_FOR_FFT_____ (0.5)

#define BUFFER_SIZE____ (500000)

#define BE_TAMANHO2________ (100000 * 2)

#define GAIN_NOT_ENOUGH_SAMPLES  -24601
#define GAIN_ANALYSIS_ERROR           0
#define GAIN_ANALYSIS_OK              1

#define INIT_GAIN_ANALYSIS_ERROR      0
#define INIT_GAIN_ANALYSIS_OK         1

#define YULE_ORDER          10
#define BUTTER_ORDER        2
#define RMS_PERCENTILE      0.95        /* percentile which is louder than the proposed level */
#define MAX_SAMP_FREQ       48000.      /* maximum allowed sample frequency [Hz] */
#define RMS_WINDOW_TIME     0.050       /* Time slice size [s] */
#define STEPS_per_dB        100.        /* Table entries per dB, someday we will learn what dB is... */
#define MAX_dB              120.        /* Table entries for 0...MAX_dB (normal max. values are 70...80 dB) */

#define MAX_ORDER               (BUTTER_ORDER > YULE_ORDER ? BUTTER_ORDER : YULE_ORDER)
#define MAX_SAMPLES_PER_WINDOW  ((int)(MAX_SAMP_FREQ * RMS_WINDOW_TIME) + 1)    /* max. Samples per Time slice */
#define PINK_REF                64.82 /* 298640883795 */	/* calibration value */

typedef unsigned short Uint16_t;
typedef signed short Int16_t;
typedef unsigned int Uint32_t;
typedef signed int Int32_t;

typedef float Float_t;  /* Type used for filtering */

#define BE_FIRST_SIZE (9644/sizeof(Float_t))
#define BE_SECOND_SIZE (48000/sizeof(Uint32_t)) /*protected*/

typedef struct
{
	int band_num;
	int use_xmms_original_freqs, use_independent_channels;
	int x, y;
	int equalizer_autoload, equalizer_active, lock_sliders, initialized;
	float equalizer_preamp[2], equalizer_bands[31][2];
	char *eqpreset_default_file, *eqpreset_extension;
	int extra_filtering;
	int use_fixed;
	int gui_visible;
	int auto_volume_down;
	int auto_volume_down_ms;
	char *skin;
} EQConfig;


typedef struct
{
	int beta;
	int alpha;
	int gamma;
} sIIRCoefficients_fixed;

/*
 * Coefficient history for the IIR filter
 */
typedef struct
{
	int x[3];               /* x[n], x[n-1], x[n-2] */
	int y[3];               /* y[n], y[n-1], y[n-2] */
} sXYData_fixed;

/*
 * Floating point
 */
typedef struct
{
	double beta;
	double alpha;
	double gamma;
} sIIRCoefficients;

/*
 * Coefficient history for the IIR filter
 */
typedef struct
{
	double x[3];             /* x[n], x[n-1], x[n-2] */
	double y[3];             /* y[n], y[n-1], y[n-2] */
} sXYData;

typedef struct _wavefile     // this will never change I supose
{
	char riff[4]; ///////////// '4
	int bytes; //////////////// '8
	char wave[4]; ///////////// '12
	char format[4]; /////////// '16
	int chunksize; //////////// '20
	short formattag; ////////// '22
	short channels; /////////// '24
	int samplespersecond; ///// '28
	int avebytespersec; /////// '32
	short blockalign; ///////// '34
	short bitspersample; ////// '36
	char pad[8]; ////////////// '44
} wavefile;

typedef struct _spectrum
{
	int f60;
	int f170;
	int f310;
	int f600;
	int f1000;
	int f3000;
	int f6000;
	int f12000;
	int f14000;
	int f16000;
	int peak;
} spectrum;

typedef struct unicode_large_
{
	WCHAR unicode_large_c___pUSC2[300];
	WCHAR unicode_large_c___pUSC2_2[300];
	char unicode_large_c___pUTF8[(300*6)];
	char unicode_large_c___pUTF8_2[(300*6)];
	int unicode_large_c___position_utf8;
	int unicode_large_c___position;
}   unicode_large;

typedef struct _spectrumd
{

	double f60;
	double f170;
	double f310;
	double f600;
	double f1000;
	double f3000;
	double f6000;
	double f12000;
	double f14000;
	double f16000;
	int peak;

} spectrumd;

enum morcego_ratio
{
	BE_AUTO_______,
	BE_5x4_______,
	BE_16x9_______,
	BE_16x10_______,
	BE_4x3_______,
	BE_2_21x1_______,
	BE_2_35x1_______,
	BE_2_39x1_______,
	BE_2_50x1_______,
	BE_1x1_______,
};

/**
 * the whole struct to store everything
 */
//#pragma pack(push, 4)
typedef struct morcego_instance_be_
{

	int sIgnature;

	//setor de playlist.c playlist_c___

	int playlist_c___player_index;
	char playlist_c___playlist_filename[300*6];
	char playlist_c___is_playlist;
	char *playlist_c___media_files[50000];
	int playlist_c___media_files_int[50000][2];
	int playlist_c___media_files_count;

	//setor de analisys.c       analisys_c___
	int analisys_c___string_position;
	double analisys_c___sync;
	int analisys_c___analisys_value;
	char analisys_c___normalization_is_replaygain;

	//setor de libav.c libav_c___
	double libav_c___sync_adjust;
	double libav_c___ticks;
	char libav_c___is_flv;
	int libav_c___old_rate;
	int libav_c___old_tempo;
	double libav_c___ajusted_frame_rate;
	int libav_c___disable_width_limit;
	int libav_c___request_for_adjust;
	double libav_c___the_real_ratio;
	double libav_c___old_adjusted_ratio;
	double libav_c___old_ratio;
	int libav_c___old_x;
	int libav_c___old_y;
	int libav_c___old_width;
	int libav_c___old_height;
	double libav_c___adjusted_ratio;
	char libav_c___audio_finished;
	double libav_c___video_timebase;
	double libav_c___audio_timebase;

	int libav_c___reinit_uf;
	int libav_c___reinit_uf2;

	char libav_c___format_name[1024];
	double libav_c___audio_frame;
	double libav_c___video_frame;
	int libav_c___pixel_format;
	int libav_c___adjust_left;
	int libav_c___adjust_top;
	int libav_c___width_of_window;
	int libav_c___height_of_window;
	char libav_c___empty_data[4096];
	int libav_c___mode_is_free_play;
	int libav_c___donot_draw_video;
	int libav_c___disable_video;
	int libav_c___pause_counter;
	char libav_c___video_information[300];

	int libav_c___cancel_redea_thread;
	int libav_c___directx_X;
	int libav_c___directx_Y;
	int libav_c___X;
	int libav_c___Y;
	int libav_c___the_ratio;
	int libav_c___dont_do_video;
	int libav_c___ajuste_width;
	int libav_c___ajuste_heigth;
	__int64 libav_c___hwnd;
	__int64 libav_c___player_hwnd;
	int libav_c___size_of_window_width;
	int libav_c___size_of_window_height;
	__int64 libav_c___morcego_window;
	int libav_c___inputwidth;
	char libav_c___video_codec[300];
	double libav_c___framerate;
	double libav_c___posicaoinicial_do_audio;
	double libav_c___audio_position_real;
	double libav_c___audio_position_deslocado;
	char libav_c___canquit;
	void*libav_c___screen;
	int libav_c___the_width;
	int libav_c___the_height;
	void* libav_c___bmp;
	char libav_c___cancel_video_thread;
	char libav_c___pause_video_thread;
	char libav_c___initiate_playback;
	char libav_c___video_thread_running;
	double libav_c___deslocacao;
	double libav_c___ponto_inicial;
	int libav_c___skipframes;
	double libav_c___frames_shown_1;
	double libav_c___frames_shown_2;
	int libav_c___width;
	int libav_c___height;
	int libav_c___video_ready_to_play;
	int libav_c___is_seeking;
	__int64 libav_c___audiostream;
	__int64 libav_c___videostream;
	int libav_c___morcego;
	int libav_c___already;
	__int64 libav_c___real_size_of_pcm_data;
	__int64 libav_c___be_size_of_pcm_data;
	int libav_c___sample_fmt_;
	int libav_c___channels_;
	int libav_c___sample_rate;
	__int64 libav_c___BitsPerSample;
	double libav_c___seconds;
	__int64 libav_c___duracao;
	void *libav_c___pCodecCtx_ptr;
	void *libav_c___FormatContext_ptr;


	void *libav_c___pCodecCtx_ptr_video;
	void *libav_c___FormatContext_ptr_video;
	void *libav_c___dict_1_video;
	void *libav_c___dict_2_video;

	void *libav_c___dict_1_audio;
	void *libav_c___dict_2_audio;
	double libav_c___displacement_for_see_adjust_k_p;
	char libav_c___original_number_of_channels_k_p;
	char libav_c___enable_slow_computers_hack_k_p;

	//added 13-October-2020 - 02-12 AM
	char *libav_c___sample_rate_format_string;

	//added 13-October-2020 - 11-52 AM
	uint64_t libav_c___original_bitrate_k_p;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*by Amanda & Ricardo 2020*/
	BOOL libav_c___player_ar_ready;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int64_t libav_c___player_ar_only_one_frame_flag;

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	char libav_c___amanda_video_thread_error_message_kp[8 * 8];
	int libav_c___amanda_video_thread_error_value_kp;
	void *libav_c___screen_kp;
	void *libav_c___renderer_kp;
	void *libav_c___texture_kp;
	unsigned char *libav_c___yPlane_kp;
	unsigned char *libav_c___uPlane_kp;
	unsigned char *libav_c___vPlane_kp;
	size_t libav_c___yPlaneSz_kp;
	size_t libav_c___uvPlaneSz_kp;
	int libav_c___uvPitch_kp;

	void *libav_c___sc_kp;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//setor de morcego_interface_c___
	double morcego_interface_c___seek;
	int morcego_interface_c___decoder_in_use;
	int morcego_interface_c___decoder_state;
	short morcego_interface_c___short_temp[100000];
	int morcego_interface_c___adjusted_bps;
	char morcego_interface_c___message___[1024];
	__int64 morcego_interface_c___percent;
	int morcego_interface_c___wav_mode_;
	char morcego_interface_c___out_wav_file_[1024];
	char morcego_interface_c___filename_[1024];
	int morcego_interface_c___bytes_available_in_buffer;
	char *morcego_interface_c___buffer_address;
	char morcego_interface_c___internal_buffer[1000000];
	__int64 morcego_interface_c___tamanho;
	__int64 morcego_interface_c___restante;
	int morcego_interface_c___tamanhodecadafatia;
	char morcego_interface_c___buffer[100000];
	char morcego_interface_c___morcego_temp[1000000];
	int morcego_interface_c___the_track;
	int morcego_interface_c___porcentagem;
	int morcego_interface_c___returnvalue_wav;
	int morcego_interface_c___finished_wav;
	int morcego_interface_c___after_conversion_size;

	//setor de iir.c iir_c___


	int iir_c_60__already;
	int iir_c_60__k;
	int iir_c_60__j;
	int iir_c_60__i;
	double iir_c_60__gain[31][2];
	sIIRCoefficients_fixed *iir_c_60__iir_cf_fixed;
	sIIRCoefficients *iir_c_60__iir_cf;
	sXYData_fixed iir_c_60__data_history2_fixed[31][2];
	sXYData_fixed iir_c_60__data_history_fixed[31][2];
	sXYData iir_c_60__data_history2[31][2];
	sXYData iir_c_60__data_history[31][2];
	EQConfig iir_c_60__eqcfg;

	int iir_c___value_60;
	int iir_c___value_170;
	int iir_c___value_310;
	int iir_c___value_600;
	int iir_c___value_1000;
	int iir_c___value_3000;
	int iir_c___value_6000;
	int iir_c___value_12000;
	int iir_c___value_14000;
	int iir_c___value_16000;
	int iir_c___k;
	int iir_c___j;
	int iir_c___i;
	float iir_c___gain[31][2];
	sIIRCoefficients_fixed *iir_c___iir_cf_fixed;
	sIIRCoefficients *iir_c___iir_cf;
	sXYData_fixed iir_c___data_history2_fixed[31][2];
	sXYData_fixed iir_c___data_history_fixed[31][2];
	sXYData iir_c___data_history2[31][2];
	sXYData iir_c___data_history[31][2];
	EQConfig iir_c___eqcfg;

	int iir_c_2__k;
	int iir_c_2__j;
	int iir_c_2__i;
	double iir_c_2__gain[31][2];
	sIIRCoefficients_fixed *iir_c_2__iir_cf_fixed;
	sIIRCoefficients *iir_c_2__iir_cf;
	sXYData_fixed iir_c_2__data_history2_fixed[31][2];
	sXYData_fixed iir_c_2__data_history_fixed[31][2];
	sXYData iir_c_2__data_history2[31][2];
	sXYData iir_c_2__data_history[31][2];
	EQConfig iir_c_2__eqcfg;

//setor de gainanalysis.c gain_analysis_c___
	Uint32_t gain_analysis_c___B[BE_SECOND_SIZE];
	Uint32_t gain_analysis_c___A[BE_SECOND_SIZE];
	int gain_analysis_c___first;
	int gain_analysis_c___freqindex;
	double gain_analysis_c___rsum;
	double gain_analysis_c___lsum;
	unsigned long gain_analysis_c___totsamp;
	unsigned int gain_analysis_c___sampleWindow;
	Float_t *gain_analysis_c___rout;
	Float_t gain_analysis_c___routbuf[BE_FIRST_SIZE];
	Float_t *gain_analysis_c___rstep;
	Float_t gain_analysis_c___rstepbuf[BE_FIRST_SIZE];
	Float_t *gain_analysis_c___rinpre;
	Float_t gain_analysis_c___rinprebuf[MAX_ORDER * 2];
	Float_t *gain_analysis_c___lout;
	Float_t gain_analysis_c___loutbuf[BE_FIRST_SIZE];
	Float_t *gain_analysis_c___lstep;
	Float_t gain_analysis_c___lstepbuf[BE_FIRST_SIZE];
	Float_t *gain_analysis_c___linpre;
	Float_t gain_analysis_c___linprebuf[MAX_ORDER * 2];
	//setor de freeverb freeverb_plugin___
	int freeverb_plugin___notyet;
	float freeverb_plugin___attenuation;
	float *freeverb_plugin___buffer_out_right;
	float *freeverb_plugin___buffer_in_right;
	float *freeverb_plugin___buffer_in_left;
	float *freeverb_plugin___buffer_out_left;
	//setor de fourier.c    fourier_c___
	int fourier_c___enable;
	char fourier_c___buffer[10000];
	spectrumd fourier_c___spec2;
	spectrumd fourier_c___spec3;
	spectrumd fourier_c___spec4;
	spectrumd fourier_c___spect;
	spectrumd fourier_c___spectemp;
	double fourier_c___mdf60;
	double fourier_c___mdf170;
	double fourier_c___mdf310;
	double fourier_c___mdf600;
	double fourier_c___mdf1000;
	double fourier_c___mdf3000;
	double fourier_c___mdf6000;
	double fourier_c___mdf12000;
	double fourier_c___mdf14000;
	double fourier_c___mdf16000;
	double fourier_c___pontodbl;
	int fourier_c___fftenabled;

	//setor de analisys.c analisys_c___
	char analisys_c___out[100000];

	//setor de id3.c id3_c___
	int id3_c___v1Track;
	char id3_c___v1Title[100];
	char id3_c___v1Artist[100];
	char id3_c___v1Album[100];
	char id3_c___v1Year[100];
	int id3_c___v1Genre;
	char id3_c___v1Comment[100];
	char id3_c___tempfolder[300];
	int id3_c___v2Composersize;
	char *id3_c___v2Composer;
	int id3_c___v2OriginalArtistsize;
	char *id3_c___v2OriginalArtist;
	int id3_c___v2Copyrightsize;
	char *id3_c___v2Copyright;
	int id3_c___v2URLsize;
	char *id3_c___v2URL;
	int id3_c___v2EncodedBysize;
	char *id3_c___v2EncodedBy;
	int id3_c___v2Commentsize;
	char *id3_c___v2Comment;
	int id3_c___v2Genresize;
	char *id3_c___v2Genre;
	int id3_c___v2Yearsize;
	char *id3_c___v2Year;
	int id3_c___v2Albumsize;
	char *id3_c___v2Album;
	int id3_c___v2Artistsize;
	char *id3_c___v2Artist;
	int id3_c___v2Titlesize;
	char *id3_c___v2Title;
	int id3_c___v2Tracksize;
	char *id3_c___v2Track;

	//dsp section            dsp_c___
	char dsp_c___globalbuf1[BE_TAMANHO2________];
	char dsp_c___convbuffer[BE_TAMANHO2________];
	char dsp_c___mpeg[255];
	char dsp_c___mode[255];
	char dsp_c___layer[255];
	char dsp_c___outbuffer[200000];
	int dsp_c____surround_clean;
	char dsp_c___sutemp[50000];
	short *dsp_c___pitch_buffer;
	int dsp_c___pitch_buffer_len;
	int dsp_c___clean;
	short *dsp_c___chan1;
	short *dsp_c___chan2;
	short dsp_c___temp1[250000];
	short dsp_c___temp2[250000];
	short dsp_c___temp3[250000];
	short dsp_c___temp4[250000];
	int dsp_c___limpador;
	short dsp_c___echof[1 + (48000 / 2)];
	short dsp_c___echoold[1 + (48000 / 2)];
	short dsp_c___echo2[1 + (48000 / 2)];
	short dsp_c___echo3[1 + (48000 / 2)];
	short dsp_c___echo4[1 + (48000 / 2)];
	short dsp_c___echo5[1 + (48000 / 2)];
	short dsp_c___echo6[1 + (48000 / 2)];

	//sector decoder.c       decoder_c___
	double decoder_c___tm_value;
	int decoder_c___tm;
	char decoder_c___filename[300*6];
	int decoder_c___will_loop;
	int decoder_c___track;
	int decoder_c___initial_init_playback_value;
	int decoder_c___force_exit;
	wavefile decoder_c___wav;
	int decoder_c___ponto;
	int decoder_c___pauseflag;
	int decoder_c___intwaveout;
	int decoder_c___intsamplerate;
	int decoder_c___intreturn;
	int decoder_c___intreturn2;
	int decoder_c___intpriority;
	int decoder_c___intloop;
	int decoder_c___flagdewave;
	int decoder_c___cancelflag;
	char decoder_c___tempbuf[BE_TAMANHO2________];
	char decoder_c___salvbuffer[BE_TAMANHO2________];
	char decoder_c___intfilename[255];
	char decoder_c___globalbuf[BE_TAMANHO2________];
	char decoder_c___globalbuf2[BE_TAMANHO2________];
	spectrum decoder_c___spec;
	int decoder_c___valuetoset;
	int decoder_c___salvadata;
	int decoder_c___rightvalf;
	int decoder_c___rightval;
	int decoder_c___notloaded;
	int decoder_c___multiplier;
	int decoder_c___liberafft;
	int decoder_c___leftvalf;
	int decoder_c___leftval;
	int decoder_c___isvbr;
	int decoder_c___inttamanho;
	int decoder_c___intplayback;
	int decoder_c___intismp3;
	int decoder_c___flag_de_pause;
	int decoder_c___enablevoiceremoval;
	int decoder_c___enablepreamp;
	int decoder_c___enableequalizer;
	int decoder_c___enableecho;
	int decoder_c___doublebuffer;
	int decoder_c___bitrate;
	float decoder_c___intvolume2;
	float decoder_c___intvolume;
	double decoder_c___seekto;
	double decoder_c___seconds;
	double decoder_c___newtime;
	double decoder_c___newsecond;
	double decoder_c___newsecond_copy;

	int decoder_c___clean_up_flag;
	int decoder_c___loaded_player;
	int decoder_c___debug_flag;
	double decoder_c___valor_de_deslocamento_de_audio;

/*

 	Flag for waveout open status

*/
	bool decoder_c___wave_out_open_flag;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////arp/

	void* be_real;
	void* be_for_wav_convert;
	void *be_ptr;
	char decoder_c___current_string[300];
	int decoder_c___hasdebuginfo;
	char decoder_c___debugstring[302][260];
	WAVEFORMATEX decoder_c___pwfx;
	HWAVEOUT decoder_c___phwo;
	int decoder_c___analized;
	float decoder_c___globalfactor;
	int decoder_c___enablesurround;
	int decoder_c___enablesurround2;
	int decoder_c___multiplayer_or_not;
	int decoder_c___globalrange;
	char decoder_c___key2[300];
	int decoder_c___bucaneiro_play_as_mono;
	int decoder_c___the_bitrate;
	int decoder_c___the_samplerate;
	int decoder_c___enablefreeverb;
	int decoder_c___gpitch;
	int decoder_c___grate;
	int decoder_c___gtempo;
	int decoder_c___enablesoundtouch;
	int decoder_c___usandoencrypt;

	int decoder_c___olditem;
	int decoder_c___olditem_2;
	int decoder_c___olditem_3;
	int decoder_c___internal_replaygain_fast_mode;
	int decoder_c___the_track;
	char decoder_c___morcego_libav_error[1024];
	int decoder_c___morcego_channels;
	int decoder_c___bits_per_sample;
	int decoder_c___just_clean_buffers;
	int decoder_c____play_1_position;
	unsigned char decoder_c____play_1_copia_1[100000];
	unsigned char decoder_c____play_1_copia_2_24_june_2011__14_12_PM[100000];
	unsigned char decoder_c____play_1_copia_3_24_june_2011__14_19_PM[100000];
	unsigned char decoder_c____play_1_copia_4_24_june_2011__14_26_PM[100000];
	unsigned char decoder_c____play_1_copia_5_24_june_2011__14_46_PM[100000];
	WAVEHDR decoder_c____play_1WaveHdr;
	WAVEHDR decoder_c____play_1WaveHdr1;
	WAVEHDR decoder_c____play_1WaveHdr2;
	WAVEHDR decoder_c____play_1WaveHdr3;
	WAVEHDR decoder_c____play_1WaveHdr4;
	int decoder_c____play_2_position;
	unsigned char decoder_c____play_2_copia_1[100000];
	unsigned char decoder_c____play_2_copia_2_24_june_2011__14_12_PM[100000];
	unsigned char decoder_c____play_2_copia_3_24_june_2011__14_19_PM[100000];
	unsigned char decoder_c____play_2_copia_4_24_june_2011__14_26_PM[100000];
	unsigned char decoder_c____play_2_copia_5_24_june_2011__14_46_PM[100000];
	WAVEHDR decoder_c____play_2WaveHdr;
	WAVEHDR decoder_c____play_2WaveHdr1;
	WAVEHDR decoder_c____play_2WaveHdr2;
	WAVEHDR decoder_c____play_2WaveHdr3;
	WAVEHDR decoder_c____play_2WaveHdr4;
	int decoder_c____play_3_position;
	unsigned char decoder_c____play_3_copia_1[100000];
	unsigned char decoder_c____play_3_copia_2_24_june_2011__14_12_PM[100000];
	unsigned char decoder_c____play_3_copia_3_24_june_2011__14_19_PM[100000];
	unsigned char decoder_c____play_3_copia_4_24_june_2011__14_26_PM[100000];
	unsigned char decoder_c____play_3_copia_5_24_june_2011__14_46_PM[100000];
	WAVEHDR decoder_c____play_3WaveHdr;
	WAVEHDR decoder_c____play_3WaveHdr1;
	WAVEHDR decoder_c____play_3WaveHdr2;
	WAVEHDR decoder_c____play_3WaveHdr3;
	WAVEHDR decoder_c____play_3WaveHdr4;
	int decodec_c___function_play_position;
	char decoder_c___inputfileok[300];

	//added 13-October-2020 19:25 PM
	char decodec_c___last_pcm_slice_to_play_k_p;


	//sector unicode_large.c
	WCHAR unicode_large_c___pUSC2[300];
	WCHAR unicode_large_c___pUSC2_2[300];
	int unicode_large_c___position;
	int syncstatus;
	int libav_c___error_in_decode;
	void *copy;

	//setor de wav extract, hack for new webm files without duration
	bool      libav_c___amanda_s_smart_ape__is_open                       ;
	bool      libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true;
	bool      libav_c___amanda_s_smart_ape_is_new_webm                    ;
	int64_t   libav_c___amanda_s_smart_ape_new_generated_duration         ;
	bool      libav_c___has_an_entry                                      ;
	char      libav_c___webm________________amanda_s_smart_ape[MAX_PATH]  ;
	char      libav_c___normalization_mode__amanda_s_smart_ape[MAX_PATH]  ;
	char      libav_c___normalization_value_amanda_s_smart_ape[MAX_PATH]  ;
	char      libav_c___normalization_valu2_amanda_s_smart_ape[MAX_PATH]  ;
	char      libav_c___normalization_valu3_amanda_s_smart_ape[MAX_PATH]  ;
}morcego___i___instance__a__bucaneiro_engineering;
//#pragma pack(pop)
//morcego_instance_be *mv_______

int    InitGainAnalysis (morcego___i___instance__a__bucaneiro_engineering *mv_______,long samplefreq);
int    AnalyzeSamples (morcego___i___instance__a__bucaneiro_engineering *mv_______,const Float_t * left_samples, const Float_t * right_samples, size_t num_samples, int num_channels);
int    ResetSampleFrequency (morcego___i___instance__a__bucaneiro_engineering *mv_______,long samplefreq);
Float_t GetTitleGain (morcego___i___instance__a__bucaneiro_engineering *mv_______,int*error);
Float_t GetAlbumGain (morcego___i___instance__a__bucaneiro_engineering *mv_______);


#define BE_INI_NAME___                                                                                          "rspmp3ocx1.ini"
#endif
__int64 BE_CreateDecoder(void);
void BE_CloseDecoder(__int64 *instance_64);
int morcego_cancel(morcego___i___instance__a__bucaneiro_engineering *mv_______);
int morcego_open(morcego___i___instance__a__bucaneiro_engineering *mv_______,__INT32_OR_INT64 argumento2,__INT32_OR_INT64 argumento3);
void
get_ini_name (char*name);
WCHAR *__stdcall
utf8towide_multithread
(
	__int64 mv_instance,
	const char *pUTF8
);
__int64
id3v2tag_multithread
(
	morcego___i___instance__a__bucaneiro_engineering *mv_______,
	char *filename
);
int
save_to_file_multithread
(
	morcego___i___instance__a__bucaneiro_engineering *mv_______,
	char *infile, char *data, int size,
	int mode, int limit
);

int
id3v2tag_ok_write_multithread
(
	morcego___i___instance__a__bucaneiro_engineering *mv_______,
	char *filename
);
int
surround2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *buf, int bytes, int bps, int nch)
;
int
resetwaveeefects (morcego___i___instance__a__bucaneiro_engineering *mv_______);
int
echo (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *buf, int bytes, int bps, int nch);
int
echofinal (morcego___i___instance__a__bucaneiro_engineering *mv_______,int multiplier, int enableecho, int ponto, char *globalbuf,
           int inttamanho, int wav_bitspersample, int intchannels);
int
id3v2tag_ok (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename);
int
v2cleanup (morcego___i___instance__a__bucaneiro_engineering *mv_______);
WCHAR *__stdcall
utf8towide_fixed
(
	unicode_large *ul_______,
	const char *pUTF8
);
char *__stdcall
widetoutf8_fixed
(
	unicode_large *ul_______,
	WCHAR * pUSC2
);
void
init_iir (morcego___i___instance__a__bucaneiro_engineering *mv_______);
int
iir (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);
int
configequalizer____2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,int b60, int b170, int b310, int b600, int b1000, int b3000,
                      int b6000, int b12000, int b14000, int b16000);
int
iir___2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);
void
init_iir____2 (morcego___i___instance__a__bucaneiro_engineering *mv_______);
double
get_bucaneiro_tick (void);

//////////////////////////////////////////////////////////////////////////////////////////////////////
//added by smart ape at 20:30 Sunday 04/July/2021

/**
 * Para imprimir a string como formato binário, igual o nome da companhia do cara...
 * 
 * @param value 64 bits variable data
 *  
 * @param       show_amanda_s_smart_ape_split_or_not amanda based bool
 * flag to show or not the split character '-' between each four binary representation
 * 
 * @return a char * based ansi string with 5 threads possible suppot (not tested)
 * 
 */
char __fastcall *
decimalparabinario_64__amanda_s_smart_ape (uint64_t value, bool show_amanda_s_smart_ape_split_or_not);

//////////////////////////////////////////////////////////////////////////////////////////////////////
// added by smartape terça-feira 06/07/2021 06:54

#include "sha.h"

static int sha512_224_init(SHA512_CTX       *c);
static int sha512_256_init(SHA512_CTX       *c);
static int SHA384_Init(SHA512_CTX           *c);
static int SHA512_Init(SHA512_CTX           *c);

static
void sha512_block_data_order(SHA512_CTX *ctx, const void *in, size_t num);

static int SHA512_Final     (unsigned char *md, SHA512_CTX             *c);
static int SHA384_Final     (unsigned char *md, SHA512_CTX             *c);
static int SHA512_Update    (SHA512_CTX *c, const void *data, size_t  len);
static int SHA384_Update    (SHA512_CTX *c, const void *data, size_t  len);
static void SHA512_Transform(SHA512_CTX *c, const unsigned char     *data);
static unsigned char *SHA384(const unsigned char *d, size_t n, unsigned char *md);
static unsigned char *SHA512(const unsigned char *d, size_t n, unsigned char *md);

static void * sha512_init_k(void);

static void sha512_update_k(void * ctx, unsigned char * buffer_k, unsigned int len_k);

static void sha512_final_k(void * ctx, unsigned char *array_digest_64_bytes);

static void get_sha_512_as_an_array_of_bytes_k(unsigned char *buffer_k, unsigned int len_k, unsigned char * array_digest_k);

void get_sha_512_as_string_k(char *buffer_k, unsigned int len_k, char * digest_k);

int __fastcall get_amanda_s_smart_ape_sha513(char * buf_in, int len_amanda_s_smart_ape, char * outbuf_amanda_s_smart_ape_minimum_129_chars);

//////////////////////////////////////////////////////////////////////////////////////////////////////
// added by Amanda husband at 19:37

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
getfilesize_ar_amanda_s_smart_ape(char *infile_ar);

//////////////////////////////////////////////////////////////////////////////////////////////////////
// added at 19:47

#define MAXPATH_UTF_8_MODE_AMANDA_S_SMART_APE (MAX_PATH * 6 \
) /* is it enough */

//////////////////////////////////////////////////////////////////////////////////////////////////////
// added at 20:53, modified 23:20

bool __fastcall amanda_s_smart_ape_query_webm_and_normalization(__attribute__((unused)) char *entry_______________amanda_s_smart_ape_,
																__attribute__((unused)) char *webm________________amanda_s_smart_ape,
																__attribute__((unused)) char *normalization_mode__amanda_s_smart_ape,
																__attribute__((unused)) char *normalization_value_amanda_s_smart_ape,
																
																__attribute__((unused)) char *normalization_value2_amanda_s_smart_ape,
																
																__attribute__((unused)) char *normalization_value3_amanda_s_smart_ape);

////////////////////////////////////////////////////////////////////////////////////////////////////
//  added at 22:24

int __fastcall replacestringsensitive2_juliete(char *comando, char *source, char *dest);

//////////////////////////////////////////////////////////////////////////////////////////////////////
