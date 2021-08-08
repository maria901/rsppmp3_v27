
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
 
#define _WIN32_WINNT 0x500
#include "mv_from_be.h"
#include "nome_da_companhia.h"

/*

   a lot of time have passed since this project was started, and a lot of time will pass before it work as expected...

 */

#ifndef __BUCANEIRO__
#error Bucaneiro not defined
#endif
/*

     http://en.wikipedia.org/wiki/Boolean_algebra

     thy computer's book:
     The TTL Data Book for Design Engineers. 1st Ed. Dallas: Texas Instruments Semiconductor. 1973

 */

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar  unsigned   char
#define uint   unsigned    int
#define ulong  unsigned   long
#define ushort unsigned  short
#endif
#endif

#pragma message " Compiling decoder.c for your pleasure... "

/*
 * Functions that don't start with a capitalized character are for internal use only, even if documented
 */

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
#include /* amanda's smart ape */   <psapi.h>

#include <MmSystem.h>

#include "win64.h"

#include "../morcego/be_constants.h"

#include "be_xml.c"

//tag1
#define tamanho ((100000 * 2))
#define tamanho2 (tamanho)

#include "decoder.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////2021 z
// added december 2020, 01

void amanda_fix_dithering(char *d_kp, int length_kp);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////z
//Added 2021/03/23 10:45

FILE * our_jun_playlist_file_z;
int64_t number_z = 0;
bool loading_z = true;
// Added 2021/04/08 10:56
int ret_arp_;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Added 2021/04/16 21:21

static int   oldvalue_Z =  0;
static int last_value_Z = -1;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//playlist debug mode

bool enable_playlist_debug = false;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//unused anymore...
#define limite_i 1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// for desktop playback

enum amanda_position
{
	I_TOP__,
	I_CENTER,
	I_BOTTOM,
};

bool enable_desktop_i = 0;

int w_i;
int h_i;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int stripfilenameandpath(char *path, char *onlypath, char *onlyfilename);

int __stdcall Play(__int64 mv_instance, char *filename___, int loop, int track,
                   __int64 hwnd_, __int64 player_hwnd_, int width_, int heigth_,
                   int ratio_, int left_, int top_, int);

int is_playlist(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                char *filename_);

char
*
get_pixel_format_info___(morcego___i___instance__a__bucaneiro_engineering
                         *mv_______);

void freeverbinit(morcego___i___instance__a__bucaneiro_engineering *mv_______);
int freeverb(morcego___i___instance__a__bucaneiro_engineering *mv_______,
             char *d, int length, int srate, int nch, int bits, int channels);

int reset_fft(morcego___i___instance__a__bucaneiro_engineering *mv_______);
void analize_fft(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                 spectrum *spec, char *buffer2, int canais, int len, int mult);
////////////////////////////////////////////////////////////////////////////
int __stdcall read_ini(char *app_name, char *key_name, char *data, int len,
                       char *ini_file, int filename_is_utf8);
int __stdcall write_ini_unix(char *app_name, char *key_name, char *data,
                             char *ini_file, int filename_is_utf8);
int __stdcall write_ini_mac(char *app_name, char *key_name, char *data,
                            char *ini_file, int filename_is_utf8);
int __stdcall write_ini_windows(char *app_name, char *key_name, char *data,
                                char *ini_file, int filename_is_utf8);
int __stdcall get_error_string(int val, char *data);
int __stdcall read_ini_binary(char *app_name, char *key_name, char *data,
                              int *out_len, char *ini_file,
                              int filename_is_utf8);
int __stdcall write_ini_binary(char *app_name, char *key_name, char *data,
                               int len, char *ini_file,
                               int filename_is_utf8);
/////////////////////////////////////////////////////////////////////////////

void rspgettemppath_multithread(char *path);

void morcego_seek_100_libav(morcego___i___instance__a__bucaneiro_engineering *
                            mv_______,
                            double valor);

//int just_clean_buffers;

void convertmp3towav_extended(morcego___i___instance__a__bucaneiro_engineering *
                              mv_______,
                              char *filename, char *outname,
                              int wav_mode, int track);

int convertmp3towav(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                    char *filename, char *outname, int wav_mode, int track);

void get_wav_progress_information(morcego___i___instance__a__bucaneiro_engineering
                                  *mv_______,
                                  int *por, int *ret, int *fin,
                                  char *);

/** Some of my old nicks */
typedef union pastor {

	struct
	{
		int cardo; //primeiro apelido
		int bond;
	} carolco; /**< Na realidade era caroço e não carolco */

	double seth;
} morcego_vermelho51; //ultimo apelido

const int play_as_mp3 = 0;

/////////////////////////////////////////////////////////////////////////////
int remove_id3v1_tag(morcego___i___instance__a__bucaneiro_engineering *
                     mv_______,
                     char *filename);
void BucaneiroStereoToMono(char *buffer, int len);
int PCM16MonoToPCM16Stereo(char *inSamples_b, unsigned int b_len,
                           char *outSamples_b);
int __stdcall my_timer(int val, char *filter);
__int64 _ftelli64_arab(FILE *stream);
int _fseeki64_arab(FILE *stream, __int64 offset, int origin);
WCHAR *__stdcall utf8towide(const char *pUTF8);
//definicaodefuncoes
int strip_extension_alladin(char *data, char *ext);
char *strrstr(char *s1, char *s2);
int initiatedownload(char *filename, char *url);
int isurl(char *url);
void cancel_execution(void);
int encryptfile(char *inputfile, char *outputfile, char *password);
FILE *buffer_fopen(const char *filename, const char *mode);
char *getnetstatus(int *value);
double getporf(double maxa, double fatiaa);
double getvalf(double maxa, double porr);
extern char *__cdecl decimalparabinario(unsigned int value);
extern char *__cdecl decimalparabinarioold(unsigned int value);
extern char *__cdecl decimalparabinarioprintf(unsigned int value);
extern char *__cdecl inttooctal(unsigned int value, int numberofitens);
extern char *__cdecl rspgetcomputername(void);
extern char *__cdecl rspgetcurrentdirectory(void);
extern char *__cdecl rspgetsystemdirectory(void);
extern char *__cdecl rspgettemppath(void);
extern char *__cdecl rspgetwindowsdirectory(void);
extern char *__cdecl validanomedearquivoerrorstring(void);
extern char *__cdecl validatefoldertocreateerrorstring(void);
extern char __cdecl pegaultimocaracter(char *path);
extern const char *const ID3v1_genre[];
extern double __cdecl getporf(double maxa, double fatiaa);
extern double __cdecl getvalf(double maxa, double porr);
extern double __cdecl inittimer2(int value);
extern float __cdecl inittimer(unsigned int comando);
extern int __cdecl checkmaxsize(char *comando);
extern int __cdecl checkoverflow_minuschar(char a, char b, char *result);
extern int __cdecl checkoverflow_minuschar2(char a, char b, char *result);
extern int __cdecl checkoverflow_pluschar(char a, char b, char *result);
extern int __cdecl contastringinsensitive(char *comando, char *string);
extern int __cdecl contastringsensitive(char *comando, char *string);
extern int __cdecl countitens(char *comand, char item);
extern int __cdecl createtempfilename(char *path1, char *destfile);
extern int __cdecl createtestfilename(char *path1);
extern int __cdecl detect_readonly_file(char *filename);
extern int __cdecl fix2(int value);
extern int __cdecl fix4(int value);
extern int __cdecl fix8(int value);
extern int __cdecl fix_filesize(char *filename, int len);
extern int __cdecl genrand(void);
extern __int64 __cdecl getfilesize(char *infile);
extern int __cdecl invertbits32(int value);
extern int __cdecl ispathfile(char *path);
extern int __cdecl ispathfolder(char *path);
extern int __cdecl ispathreadonly(char *path);
extern int __cdecl newsetbits(unsigned int value, unsigned int bit,
                              unsigned int bitvalue);
extern int __cdecl octaltoint(char *p);
extern int __cdecl pathappearsvalid(char *path);
extern int __cdecl pathexists(char *path);
extern int __cdecl pegaposicaoinsensitive(char *comando, char *string);
extern int __cdecl pegaposicaoinsensitivefinal(char *comando, char *string);
extern int __cdecl pegaposicaosensitive(char *comando, char *string);
extern int __cdecl pegaposicaosensitive_new(char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal(char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal_new(char *comando,
                                                 char *string);
extern int __cdecl procuradordestringinsensitive(char *comando,
                                                 char *string);
extern int __cdecl procuradordestringsensitive(char *comando, char *string);
extern int __cdecl rsp_get_error(char *buffer);
extern int __cdecl rspgetdrivetype(char *path1);
extern int __cdecl rspmakedir(char *path);
extern int __cdecl rspmakedirUNIX(char *destination, char *path);
extern int __cdecl rspparser(char *instring, char *delimiter,
                             char *returnstring, int comand);
extern int __cdecl rspposicaofixa(int mode, int value);
extern int __cdecl rspsetcurrentdirectory(char *path);
extern int __cdecl save_to_file(char *infile, char *data, int size, int mode,
                                int limit);
extern int __cdecl setbits(unsigned int value, unsigned int bit,
                           unsigned int bitvalue);
extern int __cdecl stripfilenameandpath(char *path, char *onlypath,
                                        char *onlyfilename);
extern int __cdecl testdirectory(char *path);
extern int __cdecl validanomedearquivo(char *path);
extern int __cdecl validatefoldertocreate(char *path);
extern int __cdecl wildcardselection(const char *path, const char *string1);
extern int decode_file(char *infile, char *outfile);
extern short __cdecl invertbits16(short value);
extern uint getpor(int max, uint fatia);
extern uint getval(int max, uint por);
extern unsigned int __cdecl binarioparadecimal(char *binval);
extern unsigned int __cdecl getmax(int por, unsigned int fatia);
extern unsigned int __cdecl getpor(int max, unsigned int fatia);
extern unsigned int __cdecl getval(int max, unsigned int por);
extern void _VDBG_dump(void);
extern void __cdecl adicionadordebackslashfrente(char *path);
extern void __cdecl adicionadordebackslashtras(char *path);
extern void __cdecl changecharacter(char *path, char itemtosearch,
                                    char finalcharacter);
extern void __cdecl geterrorstringrspmakedir(int errorcode, char *path);
extern void __cdecl mprintf(char *format, ...);
extern void __cdecl removedordecaracternofinal(char *path, char caracter);
extern void __cdecl removedordecaracternoinicio(char *path, char caracter);
extern void __cdecl removedordeespaconofinal(char *path);
extern void __cdecl removedordeespaconoinicio(char *path);
extern void __cdecl replace_char_binary(char *temp, char init, char out,
                                        int len);
extern void __cdecl rsp_error_print();
extern void __cdecl sgenrand(unsigned long seed);
extern void __cdecl stripchar(char *intcomando, char caracter);
extern void __cdecl stripfilenameandpath_url(char *path, char *onlypath,
                                             char *onlyfilename);
extern void __cdecl stripspace(char *intcomando);
extern void __cdecl strtolower(char *path);
extern void __cdecl strtoupper(char *path);
extern void __cdecl trocadordebackslashfrente(char *path);
extern void __cdecl trocadordebackslashtras(char *path);
static int __stdcall startapi(int parameter);
int buffer_fclose(FILE *stream);
int buffer_fseek(FILE *stream, __int64 offset, int origin);
int cancel_winsock(void);
int configequalizer(morcego___i___instance__a__bucaneiro_engineering *
                    mv_______,
                    int b60, int b170, int b310, int b600,
                    int b1000, int b3000, int b6000, int b12000, int b14000,
                    int b16000);
int configequalizer2(morcego___i___instance__a__bucaneiro_engineering *
                     mv_______,
                     int b60, int b170, int b310, int b600,
                     int b1000, int b3000, int b6000, int b12000, int b14000,
                     int b16000);
int debug_rede(char *url);
int detect(char *filename, __int64 *seekpoint);
int disablefilebuffer(void);
int disablefilebuffernoinfo(void);
int echo(morcego___i___instance__a__bucaneiro_engineering *mv_______,
         char *buf, int bytes, int bps, int nch);
int echofinal(morcego___i___instance__a__bucaneiro_engineering *mv_______,
              int multiplier, int enableecho, int ponto, char *globalbuf,
              int inttamanho, int wav_bitspersample, int intchannels);
int pitch_control(morcego___i___instance__a__bucaneiro_engineering *
                  mv_______,
                  int enabledpitchcontrol, char *buf, int bytes,
                  int bps, int nch, int pitchi);
int soundtouch(morcego___i___instance__a__bucaneiro_engineering *mv_______,
               int reset, int enable, int samplerate, int channels, int size,
               char *buf, int tempoDelta, int pitchDelta, int rateDelta);

int finalize_effects_memory(morcego___i___instance__a__bucaneiro_engineering *
                            mv_______);

int enable_fft_ok(morcego___i___instance__a__bucaneiro_engineering *
                  mv_______,
                  int val);
int enablefilebuffer();
int enablefilebuffersmart();
int finalize_effects_memory();
int finalizeplayer();
int genrand();
int id3tag(morcego___i___instance__a__bucaneiro_engineering *mv_______,
           char *filename, int mode, float *iglobalfloat, int *ianalized,
           int convertmode);
int id3tagcheck(char *filename);
int invertbits32(int value);
int id3v1tag_ok_write(morcego___i___instance__a__bucaneiro_engineering *
                      mv_______,
                      char *filename);
int isclosed(void);
int ispathfile(char *path);
int ispathfolder(char *path);
int liberleitor(void);
int surround(morcego___i___instance__a__bucaneiro_engineering *mv_______,
             char *buf, int bytes, int bps, int nch);
int minbuffersize(int size);
int mygain(uchar *buf, uint len, float factor);
int pause_winsock(void);
int reinitplayer(void);
int reset_fft(morcego___i___instance__a__bucaneiro_engineering *mv_______);
int resume_winsock(void);
int save_to_file(char *infile, char *data, int size, int mode, int limit);
int set_dest_path(char *path);
int set_pass(char *url);
int set_passive(int pasv);
int set_port(int port);
int set_sendmessage_nwnd(int value);
int set_user(char *url);
int setvolume(morcego___i___instance__a__bucaneiro_engineering *mv_______,
              int newvalue);
int travaleitor();
int v2cleanup();
int voiceremoval(char *buf, int bytes, int bps, int nch);
__int64 buffer_ftell(FILE *stream);
short invertbits16(short value);
static int __cdecl getbits(unsigned int value, unsigned int bit);
unsigned int buffer_fread(void *buffer, unsigned int size,
                          unsigned int count, FILE *stream);
size_t fread_unbuffered(void *ptr, size_t size, size_t nelem, FILE *stream);
size_t fwrite_unbuffered(const void *ptr, size_t size, size_t nelem,
                         FILE *stream);
int remove_id3v2_tag(morcego___i___instance__a__bucaneiro_engineering *
                     mv_______,
                     char *filename);
void *rmalloc(int size);

int id3v1tag_ok(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                char *filename);
int id3v2tag_ok(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                char *filename);
void analize_fft(morcego___i___instance__a__bucaneiro_engineering *
                 mv_______,
                 spectrum *spec, char *buffer2, int canais,
                 int len, int mult);
void dprintf_z(const char *format, ...);
void indprintff(const char *format, ...);
void mprintf(char *format, ...);
void rfree(void *add);
void sgenrand(unsigned long seed);

volatile int is_registered = 1;

/**
 * To print a debug information
 */
void pass_debug_function(void *val);

/**
 * (not in use these days, everything is sent to DebugView) It will add the debug information to be shown on the sample project, but notice that when debugging we only send the information to OutPutDebugStringA
 *
 *
 */
int setdebuginformation_multithread(morcego___i___instance__a__bucaneiro_engineering *mv_______, char *string)
{

	if (300 < mv_______->decoder_c___hasdebuginfo)
	{
		strcpy(mv_______->decoder_c___debugstring[mv_______->decoder_c___hasdebuginfo -
		                                          1],
		       "Debug information above limit");

		return 0;
	}
	strncpy(mv_______->decoder_c___debugstring[mv_______->decoder_c___hasdebuginfo++],
	        string, 253);
	return 0;
}

/**
 * To retrieve the last string added to the debug function, in a FILO way (first in, last out)
 */
static char *
get_debuginformation_multithread(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	int i;
	if (mv_______->decoder_c___hasdebuginfo)
	{
		strcpy(mv_______->decoder_c___current_string,
		       mv_______->decoder_c___debugstring[0]);
		for (i = 0; i < mv_______->decoder_c___hasdebuginfo; i++)
		{
			strcpy(mv_______->decoder_c___debugstring[i],
			       mv_______->decoder_c___debugstring[i + 1]);
		}
		mv_______->decoder_c___hasdebuginfo--;
		return mv_______->decoder_c___current_string;
	}
	else
	{
		return "No debug information";
	}
}

/**
 * This will return a string with the time repreentation of the double value, I spent a few minutes trying to figure out how to implement it, it was 2004
 */
static char *
secondtostring(double value)
{

	static char fixo  [255];
	uint                ret;
	uint                seg;
	uint                min;
	uint               hour;

	ret = (uint)      value;
	seg = ret %          60;
	ret = ret /          60; // minutos
	min = ret %          60;
	ret = ret /          60; // horas
	hour = ret %        100;
	sprintf(fixo, "%02d:%02d:%02d", hour, min, seg);//limited to 99 hours, above it will wrap to below to 99

	return fixo; // single thread only for the moment
}
/**
 * It will return the number of soundcards installed and working, in case you have 10 soundcards installed
 *
 */
int getdev()
{
	uint                  numdev;
	numdev = waveOutGetNumDevs();
	return                numdev;
}

/**
 * simple callback function, required by the mv_______->decoder_c___wav write process
 */
static void CALLBACK
callback(__attribute__((unused)) HWAVEOUT handle, UINT message, __attribute__((unused)) DWORD data, __attribute__((unused)) DWORD param1,
         __attribute__((unused)) DWORD param2)
{
	switch (message)
	{

	case WOM_DONE:

		break;
	case WOM_OPEN:

		break;
	case WOM_CLOSE:

		break;
	}
}

/**
 * It will open the mv_______->decoder_c___wav out to play, it has support to the Windows 7 wave out open bug...
 */
int initplayer(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	int ret = 0;

	mv_______->decoder_c___pwfx.wFormatTag = WAVE_FORMAT_PCM;

	mv_______->decoder_c___pwfx.nChannels = 2;  /*
	                                               hardcoded because even mono files are converted to stereo in order to play and multichannel files are mixed to play using only two channels (October/2020).
	                                             */

	mv_______->decoder_c___pwfx.nSamplesPerSec =
		mv_______->decoder_c___intsamplerate;

	mv_______->decoder_c___pwfx.nAvgBytesPerSec = (mv_______->decoder_c___intsamplerate * 4);
	mv_______->decoder_c___pwfx.nAvgBytesPerSec =
		mv_______->decoder_c___wav.avebytespersec;
	mv_______->decoder_c___pwfx.nBlockAlign = 4;
	mv_______->decoder_c___pwfx.wBitsPerSample = 16; //hardcoded because even other values are converted to signed 16 bits in order to play at this moment, may change in the future, I am not sure...
	mv_______->decoder_c___pwfx.cbSize = 0;

	if (mv_______->decoder_c___phwo)
	{
		ret = waveOutClose(mv_______->decoder_c___phwo);

		if (ret == MMSYSERR_NOERROR)
		{
			mv_______->decoder_c___phwo = 0;
		}
		else
		{

			switch (ret)
			{
			case MMSYSERR_INVALHANDLE:
				//dprintf("MMSYSERR_INVALHANDLE\n");
				break;
			case WAVERR_STILLPLAYING:

				//dprintf("WAVERR_STILLPLAYING\n");
				break;
			case MMSYSERR_NOERROR:
				//dprintf("MMSYSERR_NOERROR\n");
				break;
			case WAVERR_SYNC:
				//dprintf("WAVERR_SYNC\n");
				break;
			case WAVERR_BADFORMAT:
				//dprintf("WAVERR_BADFORMAT\n");
				break;
			case MMSYSERR_NOMEM:
				//dprintf("MMSYSERR_NOMEM\n");
				break;
			case MMSYSERR_NODRIVER:
				//dprintf("MMSYSERR_NODRIVER\n");
				break;
			case MMSYSERR_BADDEVICEID:
				//dprintf("MMSYSERR_BADDEVICEID\n");
				break;
			default:
				//dprintf("UNKNOWN\n");
				break;
			}
		}
	}

	if (0 == mv_______->decoder_c___phwo)
	{
		//dprintf("waveOutOpen init\n");
		ret =
			waveOutOpen(&mv_______->decoder_c___phwo,
			            mv_______->decoder_c___intwaveout,
			            &mv_______->decoder_c___pwfx, (DWORD_PTR)callback, 0,
			            CALLBACK_FUNCTION);
		mv_______->decoder_c___flag_de_pause = 1;
		if (ret)
		{
			return 1;
		}
		ret = waveOutPause(mv_______->decoder_c___phwo);
		if (ret)
		{
			return 1;
		}
	}
	else
	{
		mv_______->decoder_c___flag_de_pause = 1;
		ret = waveOutPause(mv_______->decoder_c___phwo);
		if (ret)
		{
			return 1;
		}
	}

	mv_______->decoder_c___wave_out_open_flag = 0;

	return ret;
}

#define TEST_1 5
/**
 * This series of functions just send slices of the pcm data to the sound card
 *
 * @param buf the pcm data to play, need to be a multiple of 4 for obvious reasons
 *
 * @param len the size of the data to play in bytes
 */
int play_number_1_26_june_2011(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                               uchar *buf, uint len)
{
	if (mv_______->decoder_c___just_clean_buffers)
	{
		memset(mv_______->decoder_c____play_1_copia_1, 0, 100000);
		memset(mv_______->decoder_c____play_1_copia_2_24_june_2011__14_12_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_1_copia_3_24_june_2011__14_19_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_1_copia_4_24_june_2011__14_26_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_1_copia_5_24_june_2011__14_46_PM,
		       0, 100000);
		return 0;
	}
	switch (mv_______->decoder_c____play_1_position)
	{
	case 0:
	{

		double amanda_tempo;
		amanda_tempo = get_bucaneiro_tick();
		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_1_copia_1, 2,
		            mv_______->decoder_c___inttamanho, 1);

		pedro_dprintf(-1, "2 tempo decorrido amanda... %f %d", (get_bucaneiro_tick() - amanda_tempo) * 1000., mv_______->decoder_c___inttamanho);

		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;

		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_1WaveHdr,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_1_copia_1, buf, len);
		mv_______->decoder_c____play_1WaveHdr.lpData = (char *)
			mv_______->decoder_c____play_1_copia_1;
		mv_______->decoder_c____play_1WaveHdr.dwBufferLength = len;
		mv_______->decoder_c____play_1WaveHdr.dwUser = 1;
		mv_______->decoder_c____play_1WaveHdr.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_1WaveHdr,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_1WaveHdr,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_1WaveHdr,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}

		}

		mv_______->decoder_c____play_1_position = 1;
		return 0;
	}
	break;
	case 1:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_1_copia_2_24_june_2011__14_12_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_1WaveHdr1,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_1_copia_2_24_june_2011__14_12_PM,
		       buf, len);
		mv_______->decoder_c____play_1WaveHdr1.lpData = (char *)
			mv_______->decoder_c____play_1_copia_2_24_june_2011__14_12_PM;
		mv_______->decoder_c____play_1WaveHdr1.dwBufferLength = len;
		mv_______->decoder_c____play_1WaveHdr1.dwUser = 2;
		mv_______->decoder_c____play_1WaveHdr1.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_1WaveHdr1,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_1WaveHdr1,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_1WaveHdr1,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}

		mv_______->decoder_c____play_1_position = 2;
		return 0;
	}
	break;
	case 2:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_1_copia_3_24_june_2011__14_19_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_1WaveHdr2,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_1_copia_3_24_june_2011__14_19_PM,
		       buf, len);
		mv_______->decoder_c____play_1WaveHdr2.lpData = (char *)
			mv_______->decoder_c____play_1_copia_3_24_june_2011__14_19_PM;
		mv_______->decoder_c____play_1WaveHdr2.dwBufferLength = len;
		mv_______->decoder_c____play_1WaveHdr2.dwUser = 3;
		mv_______->decoder_c____play_1WaveHdr2.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_1WaveHdr2,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_1WaveHdr2,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_1WaveHdr2,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}

		mv_______->decoder_c____play_1_position = 3;
		return 0;
	}
	break;
	case 3:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_1_copia_4_24_june_2011__14_26_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_1WaveHdr3,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_1_copia_4_24_june_2011__14_26_PM,
		       buf, len);
		mv_______->decoder_c____play_1WaveHdr3.lpData = (char *)
			mv_______->decoder_c____play_1_copia_4_24_june_2011__14_26_PM;
		mv_______->decoder_c____play_1WaveHdr3.dwBufferLength = len;
		mv_______->decoder_c____play_1WaveHdr3.dwUser = 3;
		mv_______->decoder_c____play_1WaveHdr3.dwFlags = 0;
		(void)waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_1WaveHdr3,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_1WaveHdr3,
			             sizeof(WAVEHDR));
		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_1WaveHdr3,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_1_position = 4;
		return 0;
	}
	break;
	case 4:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_1_copia_5_24_june_2011__14_46_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_1WaveHdr4,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_1_copia_5_24_june_2011__14_46_PM,
		       buf, len);
		mv_______->decoder_c____play_1WaveHdr4.lpData = (char *)
			mv_______->decoder_c____play_1_copia_5_24_june_2011__14_46_PM;
		mv_______->decoder_c____play_1WaveHdr4.dwBufferLength = len;
		mv_______->decoder_c____play_1WaveHdr4.dwUser = 3;
		mv_______->decoder_c____play_1WaveHdr4.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_1WaveHdr4,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_1WaveHdr4,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_1WaveHdr4,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_1_position = 0;
		return 0;
	}
	break;
	}

	return 0;
}

int play_number_2_26_june_2011(morcego___i___instance__a__bucaneiro_engineering *
                               mv_______,
                               uchar *buf, uint len)
{
	if (mv_______->decoder_c___just_clean_buffers)
	{
		memset(mv_______->decoder_c____play_2_copia_1, 0, 100000);
		memset(mv_______->decoder_c____play_2_copia_2_24_june_2011__14_12_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_2_copia_3_24_june_2011__14_19_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_2_copia_4_24_june_2011__14_26_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_2_copia_5_24_june_2011__14_46_PM,
		       0, 100000);
		return 0;
	}
	switch (mv_______->decoder_c____play_2_position)
	{
	case 0:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_2_copia_1, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;

		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_2WaveHdr,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_2_copia_1, buf, len);
		mv_______->decoder_c____play_2WaveHdr.lpData = (char *)
			mv_______->decoder_c____play_2_copia_1;
		mv_______->decoder_c____play_2WaveHdr.dwBufferLength = len;
		mv_______->decoder_c____play_2WaveHdr.dwUser = 1;
		mv_______->decoder_c____play_2WaveHdr.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_2WaveHdr,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_2WaveHdr,
			             sizeof(WAVEHDR));
		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_2WaveHdr,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_2_position = 1;
		return 0;
	}
	break;
	case 1:
	{
		
		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_2_copia_2_24_june_2011__14_12_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_2WaveHdr1,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_2_copia_2_24_june_2011__14_12_PM,
		       buf, len);
		mv_______->decoder_c____play_2WaveHdr1.lpData = (char *)
			mv_______->decoder_c____play_2_copia_2_24_june_2011__14_12_PM;
		mv_______->decoder_c____play_2WaveHdr1.dwBufferLength = len;
		mv_______->decoder_c____play_2WaveHdr1.dwUser = 2;
		mv_______->decoder_c____play_2WaveHdr1.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_2WaveHdr1,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_2WaveHdr1,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_2WaveHdr1,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}

		}
		mv_______->decoder_c____play_2_position = 2;
		return 0;
	}
	break;
	case 2:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_2_copia_3_24_june_2011__14_19_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_2WaveHdr2,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_2_copia_3_24_june_2011__14_19_PM,
		       buf, len);
		mv_______->decoder_c____play_2WaveHdr2.lpData = (char *)
			mv_______->decoder_c____play_2_copia_3_24_june_2011__14_19_PM;
		mv_______->decoder_c____play_2WaveHdr2.dwBufferLength = len;
		mv_______->decoder_c____play_2WaveHdr2.dwUser = 3;
		mv_______->decoder_c____play_2WaveHdr2.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_2WaveHdr2,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_2WaveHdr2,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_2WaveHdr2,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_2_position = 3;
		return 0;
	}
	break;
	case 3:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_2_copia_4_24_june_2011__14_26_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_2WaveHdr3,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_2_copia_4_24_june_2011__14_26_PM,
		       buf, len);
		mv_______->decoder_c____play_2WaveHdr3.lpData = (char *)
			mv_______->decoder_c____play_2_copia_4_24_june_2011__14_26_PM;
		mv_______->decoder_c____play_2WaveHdr3.dwBufferLength = len;
		mv_______->decoder_c____play_2WaveHdr3.dwUser = 3;
		mv_______->decoder_c____play_2WaveHdr3.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_2WaveHdr3,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_2WaveHdr3,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_2WaveHdr3,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_2_position = 4;
		return 0;
	}
	break;
	case 4:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_2_copia_5_24_june_2011__14_46_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_2WaveHdr4,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_2_copia_5_24_june_2011__14_46_PM,
		       buf, len);
		mv_______->decoder_c____play_2WaveHdr4.lpData = (char *)
			mv_______->decoder_c____play_2_copia_5_24_june_2011__14_46_PM;
		mv_______->decoder_c____play_2WaveHdr4.dwBufferLength = len;
		mv_______->decoder_c____play_2WaveHdr4.dwUser = 3;
		mv_______->decoder_c____play_2WaveHdr4.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_2WaveHdr4,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_2WaveHdr4,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_2WaveHdr4,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}

		}
		mv_______->decoder_c____play_2_position = 0;
		return 0;
	}
	break;
	}

	return 0;
}

int play_number_3_26_june_2011(morcego___i___instance__a__bucaneiro_engineering *
                               mv_______,
                               uchar *buf, uint len)
{
	if (mv_______->decoder_c___just_clean_buffers)
	{
		memset(mv_______->decoder_c____play_3_copia_1, 0, 100000);
		memset(mv_______->decoder_c____play_3_copia_2_24_june_2011__14_12_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_3_copia_3_24_june_2011__14_19_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_3_copia_4_24_june_2011__14_26_PM,
		       0, 100000);
		memset(mv_______->decoder_c____play_3_copia_5_24_june_2011__14_46_PM,
		       0, 100000);
		return 0;
	}
	switch (mv_______->decoder_c____play_3_position)
	{
	case 0:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *)mv_______->decoder_c____play_3_copia_1, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;

		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_3WaveHdr,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_3_copia_1, buf, len);
		mv_______->decoder_c____play_3WaveHdr.lpData = (char *)
			mv_______->decoder_c____play_3_copia_1;
		mv_______->decoder_c____play_3WaveHdr.dwBufferLength = len;
		mv_______->decoder_c____play_3WaveHdr.dwUser = 1;
		mv_______->decoder_c____play_3WaveHdr.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_3WaveHdr,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_3WaveHdr,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_3WaveHdr,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_3_position = 1;
		return 0;
	}
	break;
	case 1:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_3_copia_2_24_june_2011__14_12_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_3WaveHdr1,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_3_copia_2_24_june_2011__14_12_PM,
		       buf, len);
		mv_______->decoder_c____play_3WaveHdr1.lpData = (char *)
			mv_______->decoder_c____play_3_copia_2_24_june_2011__14_12_PM;
		mv_______->decoder_c____play_3WaveHdr1.dwBufferLength = len;
		mv_______->decoder_c____play_3WaveHdr1.dwUser = 2;
		mv_______->decoder_c____play_3WaveHdr1.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_3WaveHdr1,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_3WaveHdr1,
			             sizeof(WAVEHDR));


		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_3WaveHdr1,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_3_position = 2;
		return 0;
	}
	break;
	case 2:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_3_copia_3_24_june_2011__14_19_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_3WaveHdr2,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_3_copia_3_24_june_2011__14_19_PM,
		       buf, len);
		mv_______->decoder_c____play_3WaveHdr2.lpData = (char *)
			mv_______->decoder_c____play_3_copia_3_24_june_2011__14_19_PM;
		mv_______->decoder_c____play_3WaveHdr2.dwBufferLength = len;
		mv_______->decoder_c____play_3WaveHdr2.dwUser = 3;
		mv_______->decoder_c____play_3WaveHdr2.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_3WaveHdr2,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_3WaveHdr2,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_3WaveHdr2,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_3_position = 3;
		return 0;
	}
	break;
	case 3:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_3_copia_4_24_june_2011__14_26_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_3WaveHdr3,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_3_copia_4_24_june_2011__14_26_PM,
		       buf, len);
		mv_______->decoder_c____play_3WaveHdr3.lpData = (char *)
			mv_______->decoder_c____play_3_copia_4_24_june_2011__14_26_PM;
		mv_______->decoder_c____play_3WaveHdr3.dwBufferLength = len;
		mv_______->decoder_c____play_3WaveHdr3.dwUser = 3;
		mv_______->decoder_c____play_3WaveHdr3.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_3WaveHdr3,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_3WaveHdr3,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_3WaveHdr3,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_3_position = 4;
		return 0;
	}
	break;
	case 4:
	{

		analize_fft(mv_______, &mv_______->decoder_c___spec,
		            (char *) mv_______->decoder_c____play_3_copia_5_24_june_2011__14_46_PM, 2,
		            mv_______->decoder_c___inttamanho, 1);
		mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
		mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
		while (WAVERR_STILLPLAYING ==
		       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
		                              &mv_______->decoder_c____play_3WaveHdr4,
		                              sizeof(WAVEHDR)))
		{
			Sleep(TEST_1);
		}
		if (mv_______->decoder_c___cancelflag)
		{
			return 0;
		}
		memcpy(mv_______->decoder_c____play_3_copia_5_24_june_2011__14_46_PM,
		       buf, len);
		mv_______->decoder_c____play_3WaveHdr4.lpData = (char *)
			mv_______->decoder_c____play_3_copia_5_24_june_2011__14_46_PM;
		mv_______->decoder_c____play_3WaveHdr4.dwBufferLength = len;
		mv_______->decoder_c____play_3WaveHdr4.dwUser = 3;
		mv_______->decoder_c____play_3WaveHdr4.dwFlags = 0;
		waveOutPrepareHeader(mv_______->decoder_c___phwo,
			                     &mv_______->decoder_c____play_3WaveHdr4,
			                     sizeof(WAVEHDR));
		waveOutWrite(mv_______->decoder_c___phwo,
			             &mv_______->decoder_c____play_3WaveHdr4,
			             sizeof(WAVEHDR));

		if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
		{
			while (WAVERR_STILLPLAYING ==
			       waveOutUnprepareHeader(mv_______->decoder_c___phwo,
			                              &mv_______->decoder_c____play_3WaveHdr4,
			                              sizeof(WAVEHDR)))
			{
				Sleep(TEST_1);
			}
		}
		mv_______->decoder_c____play_3_position = 0;
		return 0;
	}
	break;
	}

	return 0;
}

/**
 * It will send in sequence perfectly the pcm data to the soundcard
 */
int play(morcego___i___instance__a__bucaneiro_engineering *mv_______,
         uchar *buf, uint len)
{
	pedro_dprintf(-1, "size em play len %d", len);
	if (mv_______->decoder_c___cancelflag)
	{
		return 0;
	}

	switch (mv_______->decodec_c___function_play_position)
	{
	case 0:
		play_number_1_26_june_2011(mv_______, buf, len);
		mv_______->decodec_c___function_play_position = 1;
		break;
	case 1:
		play_number_2_26_june_2011(mv_______, buf, len);
		mv_______->decodec_c___function_play_position = 2;
		break;
	case 2:
		play_number_3_26_june_2011(mv_______, buf, len);
		mv_______->decodec_c___function_play_position = 0;
		break;
	}
	return 0;
}

/**
 * It will reset the mv_______->decoder_c___wav out, it don't close the wave out due
 * to a bug in our code or in the Windows 7 and above waveout APIs, in the initplayer
 * function the wave out will be closed and reopened again, this is a workaround for
 * the moment
 */
int finalizeplayer(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	if (0 == mv_______->decoder_c___phwo)
	{
		return 0;
	}
	waveOutReset(mv_______->decoder_c___phwo);
	return 0;
}

/**
 *
 * It will return the size of the id3 v2 tag if it exist and check if it is correct
 * to avoid that nasty problem that I detected in 2003 that could crash winamp
 *
 * \param filename is utf-8, after release 7.1.4 need revision to check for compatibility
 * of new mp3 files with a video frame on it, and this function is compatible with id3 v2
 * version 2.3 and not 2.4 like the latest Libav releases, use it with care (November/2020)
 */
__int64
id3v2tag_multithread(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                     char *filename)
{

	FILE *astdin    = NULL;
	int                ret;
	static uchar item[255];
	uint            fatia1;
	uint             fatia2;
	uint            fatia3;
	uint            fatia4;
	__int64 mv_instance = (__int64)(__INT32_OR_INT64)mv_______;
	if ((astdin =
		     _wfopen(utf8towide_multithread(mv_instance, filename),
		             L"rb")) == NULL)
	{
		return 0;
	}

	ret = fread((char *)item, 1, 10, astdin);
	fclose(astdin);

	if (ret == 10)
	{

		if (('I' == item[0]) && (item[1] == 'D') && (item[2] == '3'))
		{

			fatia1 = (uint)item[6];
			fatia2 = (uint)item[7];
			fatia3 = (uint)item[8];
			fatia4 = (uint)item[9];
			fatia1 = (fatia1 << (7 * 3)) | (fatia2 << (7 * 2)) | (fatia3 << (7)) | fatia4;

			if (getfilesize(filename) < fatia1)
			{

				return 0;
			}
			return fatia1 + 10;
		}
	}
	return 0;
}

/**
 * It will set the volume
 *
 * buf is the signed short sized samples
 *
 * len is the whole size of the bytes in the signed short samples
 */
void setvolume2(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                uchar *buf, uint len)
{
	signed short  *fatia; // notice that it is ´signed´ no matter what it means
	int            tempo;
	int *fatia2 = &tempo;
	float           temp;
	int i;
	fatia = (signed short *)buf;
	for (i = 0; i < (int) len; i = i + 2)
	{
		*fatia2 = (int)*fatia;
		temp = (float)*fatia2;
		temp = temp * mv_______->decoder_c___intvolume;
		*fatia2 = (int)temp       ;
		if (*fatia2 > 32767       )
		{
			*fatia2 = 32767       ;
		}
		if (*fatia2 < -32768      )
		{

			*fatia2 = -32768      ;
		}
		*fatia = (signed short)*
		                    fatia2;
		fatia++;
	}
}

/**
 * volume is set here
 */
int setvolume3(morcego___i___instance__a__bucaneiro_engineering *mv_______,
               uchar *buf, uint len)
{
	signed short            *fatia;	
	int                      tempo;
	int *fatia2           = &tempo;
	float                     temp;
	int                          i;
	fatia = (signed short *)   buf;
	for (i = 0; i < (int) len; i = i + 2)
	{

		*fatia2 = (int)*fatia;
		temp = (float)*fatia2;
		temp = temp * mv_______->decoder_c___intvolume2;
		*fatia2 =   (int)temp;
		if (*fatia2 >   32767)
		{
			*fatia2 =   32767;
		}
		if (*fatia2 <  -32768)
		{

			*fatia2 =  -32768; //this is the smallest short value
		}

		*fatia =       (signed
		        short)*fatia2;

		fatia++;
	}
	return    0;
}

/**
 * Main decoder (player) function.
 * \param filename the file to play as a utf-8 encoded C string
 * \return 0 if no error or the error value<br>
 */
int
morcego_play
(
	morcego___i___instance__a__bucaneiro_engineering *mv_______,
	unsigned
	char
	*filename, int track
);
//this is where the magic occurs
#include "player.c"

/**
 * It will call the player function
 */
int __stdcall startapi2(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	mv_______->decoder_c___flagdewave = 0;
	mv_______->decoder_c___intreturn2 = 0;
	//thinktwice1);

	int ret;
	
	ret =
		morcego_play(mv_______,
		             (unsigned char *) mv_______->decoder_c___intfilename, mv_______->decoder_c___the_track);

	mv_______->decoder_c___intreturn2 = mv_______->decoder_c___intreturn = ret;
	
	return 0;
}

/**
 * As you can see it was copied from the BW OGG Vorbis OCX code (my ocx, of course), and it will create the player thread, it will be modified soon to avoid the thread problem of msvcrt.DLL
 */
int __stdcall playogg /* because this code was borrowed from Ogg Vorbis code 20 years ago */ (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	static HANDLE myhandle;
	static __INT32_OR_INT64 ThreadId;
	mv_______->decoder_c___notloaded = 1;

	myhandle =
		CreateThread((LPSECURITY_ATTRIBUTES)0, 0,
		             (LPTHREAD_START_ROUTINE)startapi2,
		             (LPVOID)mv_______, 0, (LPDWORD)&ThreadId);
	CloseHandle(myhandle);
	return 0;
}

/**
 * It will set the Wave out volume for the application, after windows 7
 * each application running have their own volume settings that dont affect
 * the master machine volume level (but correct me if I am wrong)
 *
 */
int setvolume(morcego___i___instance__a__bucaneiro_engineering *mv_______,
              int newvalue)
{
	int first;
	int second;
	
	if (mv_______->decoder_c___phwo == 0)
	{
		return 0;
	}
	if (-1 == mv_______->decoder_c___valuetoset)
	{
		return 0;
	}
	newvalue = newvalue * 0x28f;//I dont remember what is it, kkkk, but works..., this volume set API is just weird, low 16 bits set one channel and high 16 bits set the other channel
	if (newvalue > 0xffff)
	{
		newvalue = 0xffff;
	}
	first = newvalue;
	second = (first << 16) + newvalue;
	(void) waveOutSetVolume(mv_______->decoder_c___phwo, second);
	mv_______->decoder_c___valuetoset = -1;
	return 0;
}
/**
 * It will retrieve the openned wav out device name and information
 *
 */
int __stdcall getdevicename(uchar *nome, uint devicenumber)
{
	WAVEOUTCAPS pwoc;
	memset(&pwoc, 0, sizeof(pwoc));
	waveOutGetDevCaps(devicenumber, &pwoc, sizeof(WAVEOUTCAPS));
	strcpy( (char *) nome, pwoc.szPname);
	sprintf((char *) nome + strlen((char *) nome), " (wMid:%d wPid:%d)", pwoc.wMid, pwoc.wPid);
	return 0;
}

/**
 * It will return the status of the player, if 0 the player is running
 *
 */
int
checkinit(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	if (mv_______->decoder_c___notloaded)
	{
		Sleep(50);
		return 1;
	}
	return 0;
}

/**
 * Back in the VB5 days this function was the main interface to the DLL, this is why
 * today we have an interface2.dll for the video functions
 *
 */
int __stdcall interface1(__attribute__((unused)) __INT32_OR_INT64 argumento1, __attribute__((unused)) __INT32_OR_INT64 argumento2,
                         __attribute__((unused)) __INT32_OR_INT64 argumento3, __attribute__((unused)) __INT32_OR_INT64 argumento4)
{
	assert(0 && "Not in use anymore, unfortunatelly...\n");
	return                            0;
}

/**

   It will copy the src to the destination dest
   If the function succeeds, the return value is nonzero.

   If the function fails, the return value is zero. To get extended error information, call GetLastError.

 */
int rsplink(char *dest, char *src)
{
	WCHAR *__stdcall utf8towide_fixed(unicode_large * ul_______, const char *pUTF8);
	int ret;
	unicode_large *ul = calloc(sizeof(unicode_large), 1);
	ret =
		CopyFileW(utf8towide_fixed(ul, src), utf8towide_fixed(ul, dest), 0);
	free(ul);
	return ret;
}

/* Maria Ava Pereira ***********************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 ******************************************************************************/
//funcoes_tag
HMODULE instances[1000] = {
	0,
};
extern char *__cdecl rspgettemppath();

/**
 * It will retrieve the ini (now (2021) xml file) file for the application running the mp3 dll
 *
 */
void get_ini_name(char *name)
{
	char temp [300] = {
		             0,
	                 };
	HMODULE       hmod;
	hmod = GetModuleHandle("rspmp3ocx1.dll");
	if (0 ==      hmod)
	{
		mprintf("Missing rspmp3ocx1.dll dll \n");
		exit       (1);
	}
	{
		WCHAR temp_w[300];
		unicode_large *ul = calloc(sizeof(unicode_large), 1);
		GetModuleFileNameW(hmod, temp_w, 300);

		strcpy(temp, widetoutf8_fixed(ul, temp_w));

		free(ul);
	}
	temp[strlen(temp) - 4] = 0;
	strcat(temp, ".ini");//don`t be afraid, it will be replaced with a xml file with extension .mis, later in the code
	strcpy(name, temp);
}

int __stdcall write_ini_xml(char *app_name, char *key_name, char *data,
                            int len, char *ini_file);
int __stdcall read_ini_xml(char *app_name, char *key_name, char *data,
                           int *out_len, char *ini_file);
/**
 * It will create a new instance of the decoder, this is the first function that need to be called
 */
__int64
BE_CreateDecoder()
{
	morcego___i___instance__a__bucaneiro_engineering *mv_______;
	mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		calloc(sizeof(morcego___i___instance__a__bucaneiro_engineering), 1);
	if (mv_______)
	{
		mv_______->sIgnature =                              0xbadc0da;
		mv_______->decoder_c___the_track                    =       1;
		mv_______->decoder_c___morcego_channels             =       2;
		mv_______->decoder_c___globalrange                  =      50;
		mv_______->decoder_c___seekto                       =      -1;
		mv_______->decoder_c___intvolume                    =     1.0;
		mv_______->decoder_c___intvolume2                   =     1.0;
		mv_______->decoder_c___liberafft                    =       1;
		mv_______->decoder_c___valuetoset                   =      -1;
		mv_______->decoder_c___intpriority                  =       2;
		mv_______->decoder_c___intwaveout               = WAVE_MAPPER;
		mv_______->be_real = calloc      (sizeof(be_libav_struct), 1);
		mv_______->be_ptr = calloc       (sizeof(be_libav_struct), 1);
		mv_______->fourier_c___fftenabled                   =       1;
		mv_______->fourier_c___enable                       =       1;
		mv_______->freeverb_plugin___attenuation            =    0.65; // magic value
		mv_______->iir_c___j                                =       2;
		mv_______->iir_c___k                                =       1;
		mv_______->iir_c_2__j                               =       2;
		mv_______->iir_c_2__k                               =       1;
		mv_______->iir_c_60__k                              =       1;
		mv_______->iir_c_60__j                              =       2;
		mv_______->morcego_interface_c___seek               =      -1;
		mv_______->libav_c___adjusted_ratio                 =       0;
		mv_______->libav_c___sync_adjust                    =     0.0;

		mv_______->libav_c___enable_slow_computers_hack_k_p =       1;

		//added October 2020
		mv_______->libav_c___sample_rate_format_string = malloc(1024);

		assert(mv_______->libav_c___sample_rate_format_string);

		//added November 2020
		memset(mv_______->libav_c___amanda_video_thread_error_message_kp, 0, 8*8);
		mv_______->libav_c___amanda_video_thread_error_value_kp   = 0;
		mv_______->libav_c___screen_kp                         = NULL;
		mv_______->libav_c___renderer_kp                       = NULL;
		mv_______->libav_c___texture_kp                        = NULL;
		mv_______->libav_c___yPlane_kp                         = NULL;
		mv_______->libav_c___uPlane_kp                         = NULL;
		mv_______->libav_c___vPlane_kp                         = NULL;
		mv_______->/*bom dia amor...*/ libav_c___yPlaneSz_kp   =    0;
		mv_______->libav_c___uvPlaneSz_kp                      =    0;
		mv_______->libav_c___uvPitch_kp                        =    0;
		mv_______->libav_c___sc_kp                             = NULL;
		/*
			dprintf_z("allocated memory %08x size %d\n",        mv_______,
			sizeof(morcego___i___instance__a__bucaneiro_engineering));
		*/
	}
	else
		mprintf("Cannot allocate memory\n"),                 exit(23);
	return (__int64)(__INT32_OR_INT64)mv_______;
}

/**
 * It will close the instance of the decoder.
 */
void BE_CloseDecoder(__int64 *instance_64)
{
	//protected
	int *instance = (int *)(__INT32_OR_INT64)*instance_64;

	if (instance)
	{
		//dprintf_z("freeing memory %p\n", instance);

		morcego___i___instance__a__bucaneiro_engineering     *mv_______ =
			(morcego___i___instance__a__bucaneiro_engineering *)instance;
		free(mv_______->libav_c___sample_rate_format_string            );
		mv_______->libav_c___sample_rate_format_string            = NULL;
		free(mv_______->be_ptr);
		mv_______->be_ptr = NULL;
		free(mv_______->be_real);
		mv_______->be_real = NULL;
		free(instance);
		*instance_64 = 0;
	}
	else
	{
		pedro_dprintf(1001, "tentando dar free em endereco 0\n");
	}

}
/**
 * It will retrieve the information from the ini file
 *
 */
int __stdcall GetSettings(char *key, char *data, char *defaulT)
{
	char filename    [300] = {0};
	char filename_mis[300] = {0};
	int len = 300;
	data[0] = 0;
	{
		get_ini_name(filename);
		get_ini_name(filename_mis);

		filename_mis[strlen(filename_mis) - 3] = 'm';//.mis == xml file as you will see :  Mislaine my first daughther
		filename_mis[strlen(filename_mis) - 2] = 'i';
		filename_mis[strlen(filename_mis) - 1] = 's';
	}
	data[0] = 0;
	ret_arp_ = feline_read_xml(filename_mis ,
		    "impxmlv2 settings, from 2021, by z",
		    key                                 ,
		    NULL                                ,
		    data);

	pedro_dprintf(-1, "ret_arp_ %d mis file %s\n", ret_arp_,
		      filename_mis);
	
	//read_ini("impxmlv2 settings, from 2011", key, data, len, filename, 1);

	if(1 == ret_arp_)
	{
	     char * data_v27 = malloc(1027);
	     char key_27[1027];
	     
	     strcpy(key_27, "priority");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
     
	     strcpy(key_27, "filename");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "be_effect");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "be_effect_val");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "replaygain");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "volume_v11");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "loop");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "stereo_as_mono");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "equalizer");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "s60");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "s170");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "s310");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "s12000");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "s14000");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
    
	     strcpy(key_27, "s16000");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "waveout");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "double");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "pre");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "pre_val");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
     
	     strcpy(key_27, "s600");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "s1000");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "s3000");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "s6000");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "wav_out_vol");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "randon");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "slow_computers_hack_k_p");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);
	     
	     strcpy(key_27, "new_filename_k_p");
	     data_v27[0] = 0;
	     read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	     feline_write_xml(filename_mis        ,
			      "impxmlv2 settings, from 2021, by z"  ,
			      key_27  ,
			      NULL  ,
			      data_v27);

	     unlink("rspmp3ocx1.ini");
	     free (data_v27);

	     ret_arp_ = feline_read_xml(filename_mis ,
		    "impxmlv2 settings, from 2021, by z",
		    key                                 ,
		    NULL                                ,
		    data);
	}
	
	if (0 == strlen(data))
	{
		strcpy(data, defaulT);
	}
	
	return 0;
}

/**
 * It will save the information using our impxmlv2 (from 2021) method
 * to the file "rspmp3ocx1.mis (xml like file) in the same path of the dll
 */
int __stdcall SaveSettings(char *key, char *data)
{
     int len = 300;
     char filename_mis[300] = {0};
     char filename    [300] = {0};
     char temp_z      [300] = {0};
     {
	 
	  get_ini_name(filename_mis);
	  get_ini_name(filename    );

	  filename_mis[strlen(filename_mis) - 3] = 'm';
	  filename_mis[strlen(filename_mis) - 2] = 'i';
	  filename_mis[strlen(filename_mis) - 1] = 's';
     }

     ret_arp_ = feline_read_xml(filename_mis                        ,
				"impxmlv2 settings, from 2021, by z",
				key                                 ,
				NULL                                ,
				temp_z                             );
	
     if(1 == ret_arp_)
     {
	  char * data_v27 = malloc(1027);
	  char key_27[1027];
	     
	  strcpy(key_27, "priority");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
     
	  strcpy(key_27, "filename");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "be_effect");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "be_effect_val");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "replaygain");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "volume_v11");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "loop");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "stereo_as_mono");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "equalizer");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "s60");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "s170");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "s310");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "s12000");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "s14000");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
    
	  strcpy(key_27, "s16000");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "waveout");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "double");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "pre");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "pre_val");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
     
	  strcpy(key_27, "s600");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "s1000");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "s3000");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "s6000");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "wav_out_vol");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "randon");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "slow_computers_hack_k_p");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);
	     
	  strcpy(key_27, "new_filename_k_p");
	  data_v27[0] = 0;
	  read_ini("impxmlv2 settings, from 2011", key_27, data_v27, len, filename, 1);
	     
	  feline_write_xml(filename_mis        ,
			   "impxmlv2 settings, from 2021, by z"  ,
			   key_27  ,
			   NULL  ,
			   data_v27);

	  free (data_v27);
	  unlink("rspmp3ocx1.ini");
     }

     feline_write_xml(filename_mis        ,
		      "impxmlv2 settings, from 2021, by z"  ,
		      key  ,
		      NULL  ,
		      data);
	
     return 0;
}

/**
 * It will check to see if a valid instance was passed
 */
void check_mv_instance(__int64 mv_instance)
{

	morcego___i___instance__a__bucaneiro_engineering *mv_______;

	if (0 == mv_instance)
	{
		mprintf("mv_instance cannot be 0, you need to call BE_CreateDecoder() to create one\n");
		exit(24);
	}

	mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	if (0xbadc0da != mv_______->sIgnature)
	{
		mprintf("Invalid signature for the mv_instance\n");
		exit(51);
	}
}

/**
 * It will cancel the playback
 */
int morcego_cancel(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{


//pedro_dprintf(0, "in cancel 1\n");

	mv_______->syncstatus                     = 0;

	if (mv_______->decoder_c___phwo              )
	{

		waveOutReset(mv_______->decoder_c___phwo);

	}

//pedro_dprintf(0, "in cancel 2\n");

	mv_______->decoder_c___intloop = 0;
	mv_______->decoder_c___cancelflag = 1;
	while (mv_______->decoder_c___intreturn == 1000)
	{

		mv_______->decoder_c___cancelflag = 1;
		Sleep(33);

		mv_______->decoder_c___spec.peak = 0;
		mv_______->decoder_c___leftvalf = 0;
		mv_______->decoder_c___rightvalf = 0;

		return -1;
	}
	
	mv_______->decoder_c___leftvalf = 0;
	mv_______->decoder_c___rightvalf = 0;
	mv_______->decoder_c___spec.peak = 0;

	return 0;
}

/**
 * Internal function to initiate the playback
 */
int morcego_open(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                 __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3)
{
	mv_______->decoder_c___wave_out_open_flag = 1;
	mv_______->decoder_c___intreturn = 1000;
	strcpy(mv_______->decoder_c___intfilename, (char *)argumento2);
	mv_______->decoder_c___the_track = argumento3;
	playogg(mv_______);
	return 0;
}

/**
 * It is required to set some important settings that will define the playback
 *
 * @param track_ even if not 1 it will play only for the moment the first detected audio
 * track (soon we will be fixing it (November/2020))
 */
void pass_information_to_replay(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                                char *file, int loop_, int track_)
{
	strcpy(mv_______->decoder_c___filename, file);
	mv_______->decoder_c___will_loop = loop_;
	mv_______->decoder_c___track = track_;
}

HWND GetRealParent(HWND hWnd)
{
    HWND hParent;

    hParent = GetAncestor(hWnd, GA_PARENT);
    if(!hParent || hParent == GetDesktopWindow())
        return NULL;

    return hParent;
}
//PlayInDesktop(long mv_instance, int enable, int system_screen_w, int system_screen_h, int desired_w, int desired_h, amanda_position position_i);
int __stdcall PlayInDesktop(__int64 mv_instance, int enable_i, int system_screen_w,
							int system_screen_h, int w, int h, int position_i_)
{
	
	
	check_mv_instance(mv_instance);

	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
		
	enable_desktop_i = false;
	if(enable_i)
	{
		enable_desktop_i = true;
	}
	
	mv_______->libav_c___show_in_position____i = position_i_;
	
	mv_______->libav_c___system_screen_w_____i = system_screen_w;
	mv_______->libav_c___system_screen_h_____i = system_screen_h;

	w_i = w;
	h_i = h;	
	
	return 0;
	
}

/**
 * It will play the media file
 *
 * filename is utf-8
 *
 * loop: will define if it loops
 *
 * track: the track to play (for the moment just 1)
 *
 * hwnd: the first window that will be the background of the player
 *
 * player_hwnd: the player window, will be adjusted based on the size of the media file
 *
 * width: the width of the background window
 *
 * heigth: the height
 *
 * ratio: the ratio to be used
 *
 * left: the X position of the window
 *
 * top: the Y position of the window
 *
 * is the number of audio track to play, starting from 1 (usually 1)
 */
int __stdcall Play(__int64 mv_instance, char *filename, int loop, int track, __attribute__((unused)) __int64 hwnd_,
                   __attribute__((unused)) __int64 player_hwnd_,
                   int width_, int heigth_, int ratio_, int left_, int top_, int subtitle_i)
{
	
	check_mv_instance(mv_instance);

	pedro_dprintf(-1, "Dentro de play");

	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	mv_______->libav_c___sample_rate_format_string[0] = '\0';

	pedro_dprintf(-1, "veja %s", mv_______->libav_c___sample_rate_format_string);


	if (mv_______->decoder_c___notloaded)
	{
		return -1;
	}
	
	while (-1 == morcego_cancel(mv_______))
	{
	}
			
	//mv_______->libav_c___show_in_position____i = position_i;
		
	mv_______->libav_c___use_subtitles_track_i = subtitle_i;
		
	mv_______->libav_c___hwnd = (int64_t)hwnd_;
	mv_______->libav_c___size_of_window_width = width_;
	mv_______->libav_c___size_of_window_height = heigth_;
	mv_______->libav_c___player_hwnd = (int64_t) player_hwnd_; 
	mv_______->libav_c___the_ratio = ratio_;
	mv_______->libav_c___adjust_top = top_;
	mv_______->libav_c___adjust_left = left_;

	pass_information_to_replay(mv_______, filename, loop, track);
	
	//mv_______->decoder_c___phwo = 0;//fix
	if (loop)
	{
		mv_______->decoder_c___intloop = 1;
	}
	mv_______->decoder_c___intplayback = 1;
	mv_______->decoder_c___initial_init_playback_value = 1;
	morcego_open((morcego___i___instance__a__bucaneiro_engineering
	              *)(__INT32_OR_INT64)mv_instance,
	             (__INT32_OR_INT64)filename, (__INT32_OR_INT64)track);
	pedro_dprintf(-1, "Sai de play");
	return 0;
}
/**
 * The same as Play but will not initiate the playback without a resume call
 *
 * filename is utf-8
 *
 * @param loop        will define if it loops
 *
 * @param track       the track to play (for the moment just 1)
 *
 * @param hwnd        the first window that will be the background of the player
 *
 * @param player_hwnd the player window, will be adjusted based on the size of the media file
 *
 * @param width       the width of the background window
 *
 * @param heigth      the height
 *
 * @param ratio       the ratio to be used
 *
 * @param left        the X position of the window
 *
 * @param top         the Y position of the window
 */
int __stdcall Open(__int64 mv_instance, char *filename, int loop, int track, __int64 hwnd_,
                   __int64 player_hwnd_,
                   int width_, int heigth_ /* I am brazilian, sorry...*/, int ratio_, int left_, int top_,
				   int subtitle_i)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	if (mv_______->decoder_c___notloaded)
	{
		return -1;
	}

	while (-1 == morcego_cancel(mv_______))
	{
	}
	
	mv_______->libav_c___use_subtitles_track_i = subtitle_i;
	
	mv_______->libav_c___sample_rate_format_string[0] = '\0';

	mv_______->libav_c___hwnd = hwnd_;
	mv_______->libav_c___size_of_window_width = width_;
	mv_______->libav_c___size_of_window_height = heigth_;
	mv_______->libav_c___player_hwnd = player_hwnd_;
	mv_______->libav_c___the_ratio = ratio_;
	mv_______->libav_c___adjust_top = top_;
	mv_______->libav_c___adjust_left = left_;

	pass_information_to_replay(mv_______, filename, loop, track);
	//mv_______->decoder_c___phwo = 0;
	if (loop)
	{
		mv_______->decoder_c___intloop = 1;
	}
	mv_______->decoder_c___intplayback = 0;
	mv_______->decoder_c___initial_init_playback_value = 0;

	morcego_open((morcego___i___instance__a__bucaneiro_engineering
	              *)(__INT32_OR_INT64)mv_instance,
	             (__INT32_OR_INT64)filename, (__INT32_OR_INT64)track);
	return 0;
}

/**
 * It will return the status of the playback, if running or finished, it
 * is required to know when the end of the playback occurs
 *
 */
int __stdcall IntReturn(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return mv_______->decoder_c___intreturn + mv_______->decoder_c___pauseflag;
}
/**
 * As far as I remember it will retrieve the progress position of the media to wav conversion, take a look in the sources to learn more
 *
 */
void __stdcall GetConversionInfo(__int64 mv_instance, int *percent, int *finished,
                                 int *returnvalue_, char *___message)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	get_wav_progress_information(mv_______, percent, returnvalue_, finished,
	                             ___message);
	return;
}
/**
 * The internal function to pause the playback, if it is running, of course
 *
 */
int morcego_pause(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	if (mv_______->decoder_c___intreturn != 1000)
	{
		return 0;
	}
	mv_______->decoder_c___pauseflag = 1;
	mv_______->decoder_c___flag_de_pause = 1;
	waveOutPause(mv_______->decoder_c___phwo);
	mv_______->decoder_c___newsecond_copy =
		mv_______->decoder_c___valor_de_deslocamento_de_audio;

	return 0;
}
/**
 * The function to pause the playback, if it is running, of course
 *
 */
int __stdcall PlaybackPause(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	mv_______->libav_c___pause_video_thread = 1;
	mv_______->libav_c___audio_position_real = get_bucaneiro_tick();
	mv_______->libav_c___posicaoinicial_do_audio =
		mv_______->libav_c___audio_position_real;
	return morcego_pause(mv_______);
}
/**
 * The internal function to resume the playback, if it was open with Open or if it was paused
 *
 */
int morcego_resume(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	if (mv_______->decoder_c___intreturn != 1000)
	{
		return 0;
	}

	mv_______->decoder_c___pauseflag = 0;
	mv_______->decoder_c___flag_de_pause = 0;
	
	waveOutRestart(mv_______->decoder_c___phwo);
	
	static int flag = 0;  // for debug purposes
	if (0 == flag)
	{
		flag = 1;
		//mv_______->decoder_c___debug_flag=2;
	}
	else
	{
		flag = 0;
		//mv_______->decoder_c___debug_flag=1; // if 1 it will simulate a delay in the audio, if 2 in the video
	}
	return 0;
}
/**
 * The function to resume the playback, if it was open with Open or if it was paused
 *
 */
int __stdcall PlaybackResume(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->libav_c___pause_video_thread = 0;
	mv_______->libav_c___audio_position_real = get_bucaneiro_tick();
	mv_______->libav_c___posicaoinicial_do_audio =
		mv_______->libav_c___audio_position_real;

	pedro_dprintf(-1, "passou 1");
	return morcego_resume(mv_______);
}
/**
 * To cancel the playback, just it
 *
 */
int __stdcall PlaybackCancel(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	int ret;

	while (-1 == (ret = morcego_cancel(mv_______)))
	{
	}

	return ret;
}
/**
 * The internal function to get the sample rate of the loaded media file
 *
 */
int morcego_samplerate(morcego___i___instance__a__bucaneiro_engineering *
                       mv_______)
{
	if (checkinit(mv_______))
	{
		return -1;
	}
	return mv_______->decoder_c___intsamplerate;
}
/**
 * The function to get the sample rate of the loaded media file
 *
 */
int __stdcall SampleRate(__int64 mv_instance)
{
	int ret;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	ret = morcego_samplerate(mv_______);
	return ret;
}
/**
 * The internal function to get the number of channels of the loaded media file
 *
 */
int morcego_channels_(morcego___i___instance__a__bucaneiro_engineering *
                      mv_______)
{

	if (checkinit(mv_______))
	{

		return -1;
	}

	return mv_______->decoder_c___morcego_channels;
}
/**
 * The function to get the number of channels of the loaded media file
 *
 */
int __stdcall Channels(__int64 mv_instance)
{
	int ret;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	ret = morcego_channels_(mv_______);
	return ret;
}

/** It is the media bits per sample, but notice that the player will convert
 * it to 16 bits to play, if it is a problem send me an e-mail and I will
 * extend it to play in the real number of bits
 */
int __stdcall Bits_per_Sample(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	if (checkinit(mv_______))
	{

		return -1;
	}
	return mv_______->decoder_c___bits_per_sample;
}
/**
 * The internal function to get the playback position of the loaded media file as milliseconds
 *
 */
int morcego_gettime(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	uint ret;
	if (checkinit(mv_______))
	{
		return -1;
	}

	if (mv_______->decoder_c___newsecond > mv_______->decoder_c___seconds)
	{
		ret = (mv_______->decoder_c___seconds * (double)1000);
	}
	else
	{
		ret = (mv_______->decoder_c___newsecond * (double)1000);
	}

	return ret;
}
/**
 * The function to get the position of playback of the loaded media file as milliseconds
 *
 */
int __stdcall GetTimeMilliseconds(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return morcego_gettime(mv_______);
}
/**
 * The internal function to get the playback position of the loaded media file as seconds
 *
 */
int morcego_gettimes(morcego___i___instance__a__bucaneiro_engineering *
                     mv_______)
{
	uint ret;

	if (checkinit(mv_______))
	{

		return -1;
	}
	ret = (mv_______->decoder_c___newsecond);
	return ret;
}
/**
 * The function to get the position of the playback of the loaded media file as seconds
 *
 */
int __stdcall GetTime(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return morcego_gettimes(mv_______);
}
/**
 * The internal function to get the position of the playback of the loaded media file as a string
 *
 */
int morcego_gettimestring(morcego___i___instance__a__bucaneiro_engineering *
                          mv_______,
                          __INT32_OR_INT64 argumento2)
{
	char fixo                [255]; //cannot be static anymore
	uint                       ret;
	uint                       seg;
	uint                       min;
	uint                      hour;
	if (checkinit(mv_______))
	{
		return -1;
	}
	ret = mv_______->decoder_c___newsecond;
	seg =                 ret % 60;
	ret =                 ret / 60;
	min =                 ret % 60;
	ret =                 ret / 60;
	hour =               ret % 100;
	sprintf(fixo, "%02d:%02d:%02d", hour, min, seg);
	strcpy((char *)argumento2, fixo);
	return 0;
}
/**
 * The function to get the position of playback of the loaded media file as string
 *
 */
int __stdcall GetTimeString(__int64 mv_instance, char *time)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return morcego_gettimestring(mv_______, (__INT32_OR_INT64)time);
}
/**
 * The internal function to get the length of the loaded media file as string
 *
 */
int morcego_getsecondsstring(morcego___i___instance__a__bucaneiro_engineering *
                             mv_______,
                             __INT32_OR_INT64 argumento2)
{
	char fixo[255];
	uint ret;
	uint seg;
	uint min;
	uint hour;
	if (checkinit(mv_______))
	{
		return -1;
	}
	ret = mv_______->decoder_c___newtime;
	seg = ret % 60;
	ret = ret / 60;
	min = ret % 60;
	ret = ret / 60;
	hour = ret % 100;
	sprintf(fixo, "%02d:%02d:%02d", hour, min, seg);
	strcpy((char *)argumento2, fixo);
	return 0;
}
/**
 * The function to get the length of the loaded media file as string
 *
 */
int __stdcall GetLengthString(__int64 mv_instance, char *time)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return morcego_getsecondsstring(mv_______, (__INT32_OR_INT64)time);
}
/**
 * The internal function to get the length of the loaded media file as milliseconds
 *
 */
int morcego_getseconds(morcego___i___instance__a__bucaneiro_engineering *
                       mv_______)
{
	if (checkinit(mv_______))
	{

		return -1;
	}
	return (int)(double)((mv_______->decoder_c___newtime * (double)1000));
}
/**
 * The function to get the length of the loaded media file as milliseconds
 *
 */
int __stdcall GetLengthMilliseconds(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return morcego_getseconds(mv_______);
}
/**
 * The internal function to get the length of the loaded media file as seconds
 *
 */
int morcego_getsecondss(morcego___i___instance__a__bucaneiro_engineering *
                        mv_______)
{
	if (checkinit(mv_______))
	{

		return -1;
	}
	return (int)(mv_______->decoder_c___newtime);
}
/**
 * The function to get the length of the loaded media file as seconds
 *
 */
int __stdcall GetLength(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return morcego_getsecondss(mv_______);
}
/**
 * The internal function to terminate the player
 *
 */
int morcego_closeplayer(morcego___i___instance__a__bucaneiro_engineering *
                        mv_______)
{
	finalizeplayer(mv_______);
	return 0;
}
/**
 * The function to terminate the player
 *
 */
int __stdcall ClosePlayer(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return morcego_closeplayer(mv_______);
}

int morcego_seekto(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                   __INT32_OR_INT64 argumento2)
{
	mv_______->decoder_c___seekto = (double)argumento2 / (double)1000;
	return 0;
}
/**
 * Function to seek on the media file loaded
 *
 */
void __stdcall SeekTo(__int64 mv_instance, double seek)
{
	int val;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	seek = seek * 1000;
	val = (__INT32_OR_INT64)seek;
	morcego_seekto(mv_______, (__INT32_OR_INT64)val);
}
/**
 * Function to show or hide the cursor, for fullscreen playback
 *
 */
void __stdcall ShowCursor_(int enable)
{
	int ret;
	/*
	   int ShowCursor(

	   BOOL bShow  // cursor visibility flag
	   );
	 */
	if (enable)
	{

		ret = ShowCursor(1);
volta:          ;
		if (ret > 0)
		{
			ret = ShowCursor(0);
			goto volta;
		}
	}
	else
	{
denovo:         ;
		ret = ShowCursor(0);

		if (ret > 0)
		{
			goto denovo;
		}
denovo2:

		if (ret < -1)//looks weird but works...
		{
			ret = ShowCursor(1);
			goto denovo2;
		}
	}
}
/**
 * The function to seek on the media file as if it was a 10000 slices, 5000 to
 * the middle of the media file, it is required because the sample player split
 * the media file in 10000 positions
 *
 */
void __stdcall SeekTo_10000(__int64 mv_instance, double seek)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	seek = seek / 100.;
	if (seek >     100)
	{
		seek     = 100;
	}
	if (seek       < 0)
	{
		seek       = 0;
	}
	mv_______->decoder_c___seekto = seek;
	return;
}
/**
 * To seek on the media file as the standard AV_TIME_BASE value, 1000000 to each second, anyone that is familiar with Libav know what I am saying
 *
 */
void __stdcall SeekTo_AV_TIME_BASE(__int64 mv_instance, double seek)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	seek = getporf((double)mv_______->libav_c___duracao, seek);

	if (seek > 100)
	{
		seek = 100;
	}
	if (seek < 0)
	{
		seek = 0;
	}
	mv_______->decoder_c___seekto = seek;
	return;
}
/**
 * Internal function to get the playback position as a slice of a percentage (not in use at this moment)
 *
 */
int morcego_getplaybackposition(morcego___i___instance__a__bucaneiro_engineering
                                *mv_______)
{
	if (checkinit(mv_______))
	{

		return -1;
	}
	if (mv_______->decoder_c___newtime != 0)
	{
		int ret;
		ret =
			getporf(mv_______->decoder_c___newtime,
			        mv_______->decoder_c___newsecond);
		if (ret < 0)
		{
			ret = 0;
		}
		if (ret > 100)
		{
			ret = 100;
		}
		return ret;
	}
	return 0;
}
/**
 * Function to get the playback position as a slice of a percentage (not in use at this moment)
 *
 */
int __stdcall PlayBackPosition(__int64 mv_instance)
{
	int ret;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	ret = morcego_getplaybackposition(mv_______);
	if (-1 == ret)
	{
		return 0;
	}
	return ret;
}

int morcego_be_getplaybackposition_2(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                                     __INT32_OR_INT64 argumento2)
{
	double *valor = (double *)argumento2;
	if (checkinit(mv_______))
	{

		*valor = -1;
		return 0;
	}
	double ret;
	if (-1 != mv_______->decoder_c___seekto)
	{
		ret = mv_______->decoder_c___seekto;
	}
	else
		ret =
			getporf(mv_______->decoder_c___newtime,
			        mv_______->decoder_c___newsecond);

	if (ret < 0)
	{
		ret = 0;
	}
	if (ret > 100)
	{
		ret = 100;
	}
	*valor = ret;
	return 0;
}
/**
 * Function to get the playback position as a slice of 10000, 5000 to exactly the middle of the media file
 *
 */
int __stdcall PlayBackPosition_10000(__int64 mv_instance)
{
	double val;
	double valor;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	morcego_be_getplaybackposition_2(mv_______, (__INT32_OR_INT64)&valor);
	if (-1 == valor)
	{
		return 0;
	}
	val = valor * 100.;
	if (val > 10000)
	{
		val = 10000;
	}
	if (val < 0)
	{
		val = 0;
	}
	return (int)val;
}
/**
 * Function to get the playback position as a AV_TIME_BASE value, this represents a second of the media file as 1000000
 *
 */
double __stdcall PlayBackPosition_AV_TIME_BASE(__int64 mv_instance)
{
	double val;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	val = mv_______->decoder_c___newsecond * 1000000.0;

	return val;
}
/**
 * To set the priority of the player
 *
 * @param priority
 *
 * 0 - Idle processor time
 *
 * 1 - Normal processor time
 *
 * 2 - High processor time
 *
 */
int __stdcall SetPriority(__int64 mv_instance, int priority)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___intpriority = priority;
	return 0;
}
/**
 * This function will change the volume of the playback
 * In the version 2.5.0 this function was modified, now it range from 0 to 100 and not from 0 to 10 anymore
 *
 * Notice that this function access the system mixer, then it affect the volume of any file playing (at least below windows 7), if
 * you want to change only the playback of the file playing in the control, then use the InternalVolume
 * function, now the InternalVolume function is the preferred way to change volume playback
 *
 * A value of 0 will mute the playback, a value of 100 to maximum volume
 *
 */
int __stdcall SetVolumeGain(__int64 mv_instance, int value)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___valuetoset = value;
	return 0;
}
/**
 * To set the wav out that will play the media file
 *
 */
int __stdcall SetWaveOutDevice(__int64 mv_instance, int device)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___intwaveout = device;
	return 0;
}
/**
 * To get the name of the wav out devices, just informative
 *
 */
int __stdcall GetWaveOutDevicesName(__int64 mv_instance, int device, char *data)
{
	if(0 != mv_instance)
	check_mv_instance(mv_instance);
	
	getdevicename((unsigned char *)data, device);
	return 0;
}
/**
 * Not in use these days (November/2020), because Libav don't inform this
 *
 */
int morcego_isvbr(morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	if (checkinit(mv_______))
	{
		return -1;
	}
	return mv_______->decoder_c___isvbr;
}
/**
 * Not in use these days (November/2020), because Libav don't inform this
 *
 */
int __stdcall GetVBR(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return morcego_isvbr(mv_______);
}
/**
 * To get the bitrate of the media file, may include not only the audio but video bitrate too
 *
 */
int __stdcall GetBitrate(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	if (checkinit(mv_______))
	{
		return -1;
	}
	return mv_______->decoder_c___bitrate;
}
/**
 * Not in use these days anymore, we keep it for compatibility with older software
 *
 */
int __stdcall GetMpegVersion(__int64 mv_instance, char *version)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	if (checkinit(mv_______))
	{
		return -1;
	}
	strcpy(version, mv_______->dsp_c___mpeg);
	return 0;
}
/**
 * It will return the media information about the file, if available
 *
 */
int __stdcall GetMediaInformation(__int64 mv_instance, char *layer_)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	if (checkinit(mv_______))
	{
		return -1;
	}
	strcpy(layer_, mv_______->dsp_c___layer);
	return 0;
}
/**
 * Not in use these days anymore, but we cannot just remove this function
 *
 */
int __stdcall GetMpegMode(__int64 mv_instance, char *mode_)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	if (checkinit(mv_______))
	{
		return -1;
	}
	strcpy(mode_, mv_______->dsp_c___mode);
	return 0;
}
/**
 * Function to convert a media file to wav pcm in various formats, not only signed 16 bits
 *
 */
int __stdcall ConvertMP3ToWav(__int64 mv_instance, char *input, char *output,
                              int tipo, __attribute__((unused)) char *mess, int track)
{
	int ret;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return convertmp3towav(mv_______, input, output, tipo, track);
	return ret;
}

int morcego_converttowav_be(morcego___i___instance__a__bucaneiro_engineering *
                            mv_______,
                            __INT32_OR_INT64 argumento2)
{
	morcego_property_bag *ptr_pb = (morcego_property_bag *)argumento2;
	convertmp3towav_extended(mv_______,
	                         (char *)ptr_pb->string_1,
	                         (char *)ptr_pb->string_2,
	                         (int)(ptr_pb->int64_2), (int)(ptr_pb->int64_1));
	return 0;
}
/**
 * New function to convert a media file to wav pcm in various formats, not only signed 16 bits, preferred method to convert to wav
 *
 * @param input input file
 * @param output the output file
 * @param tipo_de_wav if 1 the standard 16 bits pcm mode will be used<br>
 * if 2 24 bits wav pcm<br>
 * if 3 32 bits wav pcm<br>
 * if 4 IEEE float wav<br>
 * 5 is available but 64 bits FLOAT are not supported
 * yet because the documentation about this wav file is vague
 */
int __stdcall ConvertMP3ToWavExtended(__int64 mv_instance, char *input, char *output, int tipo_de_wav, int track)
{
	int returnvalue_amanda_s_smart_ape = 0;
	check_mv_instance(mv_instance);

	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
			mv_instance;

	if (mv_______->libav_c___amanda_s_smart_ape__is_open)
	{
		returnvalue_amanda_s_smart_ape = 1;
		goto saida_amanda_s_smart_ape;
	}

	morcego_property_bag *pb = malloc(sizeof(morcego_property_bag));
	memset(pb, 0, sizeof(morcego_property_bag));
	pb->int64_1 = track; //track
	strcpy(pb->string_1, input);
	strcpy(pb->string_2, output);
	pb->int64_2 = tipo_de_wav;
	morcego_converttowav_be(mv_______, (__INT32_OR_INT64)pb);
	free(pb);
	
	saida_amanda_s_smart_ape:

	return returnvalue_amanda_s_smart_ape;//always 0...weird...
}
/**
 * It will enable or disable the equalizer
 *
 */
int __stdcall EnableEqualizer(__int64 mv_instance, int enable)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___enableequalizer = enable;
	return 0;
}
/**
 * To pass the equalizer settings if it is running and enabled
 *
 */
int __stdcall EqualizerSettings(__int64 mv_instance,
                                int Band60,
                                int Band170,
                                int Band310,
                                int Band600,
                                int Band1000,
                                int Band3000,
								int Band6000,
								int Band12000,
								int Band14000,
								int Band16000)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	configequalizer(mv_______, Band60, Band170, Band310, Band600, Band1000,
	                Band3000, Band6000, Band12000, Band14000, Band16000);
	configequalizer____2(mv_______, Band60, Band170, Band310, Band600,
	                     Band1000, Band3000, Band6000, Band12000, Band14000,
	                     Band16000);
	return 0;
}
/**
 * Enable or disable the preamplifier, 1 will enable
 *
 */
int __stdcall EnablePreamplifier(__int64 mv_instance, int enable)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___enablepreamp = enable;
	return 0;
}
/**
 * The setting for the preamplifier if it is enabled, 50 means no gain, 100 means the double of the gain and so on
 *
 */
int __stdcall PreamplifierValue(__int64 mv_instance, int value)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___intvolume = (float)value / (float)50;
	return 0;
}
/**
 * It can set the internal volume, for the argument 100 means the default volume, 200 means the double of the volume, it can be usefull
 * if the media file has too low volume, but notice that the normalization function that can adjust automagically the volume of the low volume
 * media file, give it a try EnableOnTheFlyVolumeNormalization
 *
 */
int morcego_internalvolume(morcego___i___instance__a__bucaneiro_engineering *
                           mv_______,
                           __INT32_OR_INT64 argumento2)
{
	float vol2int;
	vol2int = (float)argumento2 / (float)100;
	if (vol2int < 0.0)
	{
		mv_______->decoder_c___intvolume2 = 0;
	}
	if (vol2int > 2.0)
	{
		mv_______->decoder_c___intvolume2 = 2.0;
	}
	mv_______->decoder_c___intvolume2 = vol2int;
	return 0;
}
/**
 * It can set the internal volume, for the argument 100 means the default volume, 200 means the double of the volume, it can be usefull
 * if the media file has too low volume, but notice that the normalization function that can adjust automagically the volume of the low volume
 * media file, give it a try EnableOnTheFlyVolumeNormalization
 *
 */
int __stdcall InternalVolume(__int64 mv_instance, int value)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	morcego_internalvolume(mv_______, value);
	return 0;
}
/**
 * This function will enable or disable the on the fly volume normalization, it can make a very low volume media file
 * play as if it was a normal record as any other
 *
 * If mode is 0 then no normalization
 *
 * if 1 the normalization will be based on the whole file
 *
 * if 2 then only 30 seconds will be used to generate the
 * normalization value
 *
 * if 3 the new recommended method BENormalize will be used
 *
 */
int __stdcall EnableOnTheFlyVolumeNormalization(__int64 mv_instance, int mode)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___internal_replaygain_fast_mode = mode;

	assert(0 == mode || 1 == mode || 2 == mode || 3 == mode);

	mv_______->analisys_c___normalization_is_replaygain = 0;
	if (1 == mv_______->decoder_c___internal_replaygain_fast_mode || 2 == mv_______->decoder_c___internal_replaygain_fast_mode)
	{
		mv_______->analisys_c___normalization_is_replaygain = 1;
	}

	return 0;
}
/**
 * This function will make the equalizer to provide the double of the gain
 *
 * It was added because some users have reported that the response of the equalizer was not enough
 *
 * Now it provides more gain than Winamp or Media Player equalizer, indeed, it can even introduce a
 * little noise or distortion when the equalizer gain is set to the maximum
 *
 */
int __stdcall DoubleBuffer(__int64 mv_instance, int enable)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___doublebuffer = enable;
	return 0;
}
/**
 * To know whether the playback is paused
 *
 */
int __stdcall PauseState(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return mv_______->decoder_c___pauseflag;
}
/**
 * To know whether the volume normalization is being used
 *
 */
int __stdcall IsUsingNormalization(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	if (mv_______->decoder_c___internal_replaygain_fast_mode)
	{
		return 1;
	}
	return 0;
}
/**
 * To retrieve the volume multiplication level, this means that by this value each signed short sample is
 * being multiplied, ex 1.000000 means no volume adjust
 *
 */
int morcego_normalizationdata(morcego___i___instance__a__bucaneiro_engineering *
                              mv_______,
                              __INT32_OR_INT64 argumento2)
{
	char thedata[255];
	if (mv_______->decoder_c___internal_replaygain_fast_mode)
	{
		memset(thedata, 0, 255);
		sprintf(thedata, "%f", (float)(mv_______->decoder_c___globalfactor));
		strcpy((char *)argumento2, thedata);
		return 1;
	}
	else
	{
		strcpy((char *)argumento2, " \0");
		return 0;
	}
	return 0;
}
/**
 * To retrieve the volume multiplication level, this means that by this value each signed short sample is
 * being multiplied, ex 1.000000 means no volume adjust
 *
 */
int __stdcall NormalizationFactor(__int64 mv_instance, char *value)
{
	check_mv_instance(mv_instance);
	morcego_normalizationdata((morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
	                          mv_instance,
	                          (__INT32_OR_INT64)value);
	return 0;
}
/**
 * It will retrieve the peak value for the left channel, please examine the sources to see if it is correct
 *
 */
int morcego_getleftchannel(morcego___i___instance__a__bucaneiro_engineering *
                           mv_______)
{
	int ret;
	ret = mv_______->decoder_c___rightval;
	if (mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	if (ret < 0)
	{
		ret = 0;
	}
	if (ret > 100)
	{
		ret = 100;
	}
	return ret;
}
/**
 * It will retrieve the peak value for the left channel, please examine the sources to see if it is correct
 *
 */
int __stdcall GetPeak(__int64 mv_instance)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	if(mv_______->decodec_c___last_pcm_slice_to_play_k_p)
	{
		return 0;
	}

	return morcego_getleftchannel(mv_______);
}
/**
 * Function to get the id3 v1 data, examine the sources to see whether the file can be normal or utf-8 encoded...
 *
 */
int __stdcall Read_ID3_v1_tag(__int64 mv_instance, char *filename, int *Track,
                              char *Title, char *Artist, char *Album,
                              char *Year, int *Genre, char *Comment)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	int ret;
	ret = id3v1tag_ok(mv_______, filename);
	if (0 == ret)
	{
		strcpy(Title, mv_______->id3_c___v1Title);
		strcpy(Artist, mv_______->id3_c___v1Artist);
		strcpy(Album, mv_______->id3_c___v1Album);
		strcpy(Year, mv_______->id3_c___v1Year);
		strcpy(Comment, mv_______->id3_c___v1Comment);
		*Track = mv_______->id3_c___v1Track;
		*Genre = mv_______->id3_c___v1Genre;
		return 0;
	}
	else
	{
		return ret;
	}
}
/**
 * It will return the genre names based on the number 'pos', it range from 0 to 148
 * The genre list is the same genre list supported by Winamp, indeed the whole ID3 tag
 * support on this control was based exactly in the same way it is supported and implemented in Winamp
 *
 * @param pos position, from 0 to 148
 * @param data Where the string returns
 * \return Always 0
 *
 */
int __stdcall Generate_ID3v1Genre(__int64 mv_instance, int pos, char *data)
{
	check_mv_instance(mv_instance);
	
	if (pos >= 148)
	{
		strcpy(data, "Invalid value");
		return 0;
	}
	if (pos < 0)
	{
		return 0;
	}
	strcpy(data, ID3v1_genre[pos]); //constantes nao tem problema
	return 0;
}
/**
 * To retrieve the id3 v1 comment
 *
 */
int morcego_wv1Comment(morcego___i___instance__a__bucaneiro_engineering *
                       mv_______,
                       __INT32_OR_INT64 argumento2)
{
	char v1temp[100];
	memset(mv_______->id3_c___v1Comment, 0, 100);
	if (mv_______->id3_c___v1Track)
	{
		memcpy(v1temp, ((char *)argumento2), 28);
		v1temp[28] = 0;
		strcpy(mv_______->id3_c___v1Comment, v1temp);
	}
	else
	{
		memcpy(v1temp, ((char *)argumento2), 30);
		v1temp[30] = 0;
		strcpy(mv_______->id3_c___v1Comment, v1temp);
	}
	return 0;
}
/**
 * This fuction will write the id3 v1 tag on the file
 *
 * The MP3 file (not utf-8 encoded), examine the sources to confirm
 *
 * \return
 *
 * 0 - no error
 *
 * 1 - cannot open mp3 file
 *
 * 2 - file is too small
 *
 * 3 - invalid file
 *
 * 4 - file is read only
 *
 */
int __stdcall Write_ID3_v1_tag(__int64 mv_instance, char *filename, int Track, char *Title,
                               char *Artist, char *Album, char *Year, int Genre,
                               char *Comment)
{
	check_mv_instance(mv_instance);
	char v1temp[100];
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	memset(mv_______->id3_c___v1Title, 0, 100);
	strncpy(v1temp, ((char *)Title), 30);
	v1temp[30] = 0;
	strcpy(mv_______->id3_c___v1Title, v1temp);
	memset(mv_______->id3_c___v1Artist, 0, 100);
	strncpy(v1temp, ((char *)Artist), 30);
	v1temp[30] = 0;
	strcpy(mv_______->id3_c___v1Artist, v1temp);
	memset(mv_______->id3_c___v1Album, 0, 100);
	strncpy(v1temp, ((char *)Album), 30);
	v1temp[30] = 0;
	strcpy(mv_______->id3_c___v1Album, v1temp);
	memset(mv_______->id3_c___v1Year, 0, 100);
	strncpy(v1temp, ((char *)Year), 4);
	v1temp[4] = 0;
	strcpy(mv_______->id3_c___v1Year, v1temp);
	mv_______->id3_c___v1Track = Track;
	morcego_wv1Comment(mv_______, (__INT32_OR_INT64)Comment);
	mv_______->id3_c___v1Genre = Genre;
	return id3v1tag_ok_write(mv_______, filename);
}
/**
 * To remove the id3 v1 tag, if it do exist
 *
 */
int __stdcall Remove_ID3V1_tag(__int64 mv_instance, char *filename)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return remove_id3v1_tag(mv_______, filename);
}
/**
 * To retrieve the Composer tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020), maybe 2021 if we got time...)
 *
 */
int morcego_v2Composer(morcego___i___instance__a__bucaneiro_engineering *
                       mv_______,
                       __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Composer)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Composer);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Original Artist tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2OriginalArtist(morcego___i___instance__a__bucaneiro_engineering *
                             mv_______,
                             __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2OriginalArtist)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2OriginalArtist);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Copyright tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2Copyright(morcego___i___instance__a__bucaneiro_engineering *
                        mv_______,
                        __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Copyright)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Copyright);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the URL tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2URL(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                  __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2URL)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2URL);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Encoded By tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2EncodedBy(morcego___i___instance__a__bucaneiro_engineering *
                        mv_______,
                        __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2EncodedBy)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2EncodedBy);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Comment tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2Comment(morcego___i___instance__a__bucaneiro_engineering *
                      mv_______,
                      __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Comment)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Comment);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Genre tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2Genre(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                    __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Genre)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Genre);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Year tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2Year(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                   __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Year)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Year);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Album tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2Album(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                    __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Album)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Album);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Artist tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2Artist(morcego___i___instance__a__bucaneiro_engineering *
                     mv_______,
                     __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Artist)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Artist);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Title tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2Title(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                    __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Title)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Title);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To retrieve the Track tag from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int morcego_v2Track(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                    __INT32_OR_INT64 argumento2)
{
	if (mv_______->id3_c___v2Track)
	{
		strcpy(((char *)argumento2), mv_______->id3_c___v2Track);
	}
	else
	{
		strcpy(((char *)argumento2), "");
	}
	return 0;
}
/**
 * To all the tags from an id3 v2 version 2.3 tag (not 2.4 at this moment (November/2020))
 *
 */
int __stdcall Read_ID3_v2_tag(__int64 mv_instance, char *filename, char *Track,
                              char *Title, char *Artist, char *Album,
                              char *Year, char *Genre, char *Comment,
                              char *EncodedBy, char *URL, char *Copyright,
                              char *OriginalArtist, char *Composer)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	int ret;
	ret = id3v2tag_ok(mv_______, (char *)filename);
	if (0 == ret)
	{
		morcego_v2Composer(mv_______, (__INT32_OR_INT64)Composer);
		morcego_v2OriginalArtist(mv_______, (__INT32_OR_INT64)OriginalArtist);
		morcego_v2Copyright(mv_______, (__INT32_OR_INT64)Copyright);
		morcego_v2URL(mv_______, (__INT32_OR_INT64)URL);
		morcego_v2EncodedBy(mv_______, (__INT32_OR_INT64)EncodedBy);
		morcego_v2Comment(mv_______, (__INT32_OR_INT64)Comment);
		morcego_v2Genre(mv_______, (__INT32_OR_INT64)Genre);
		morcego_v2Year(mv_______, (__INT32_OR_INT64)Year);
		morcego_v2Album(mv_______, (__INT32_OR_INT64)Album);
		morcego_v2Artist(mv_______, (__INT32_OR_INT64)Artist);
		morcego_v2Title(mv_______, (__INT32_OR_INT64)Title);
		morcego_v2Track(mv_______, (__INT32_OR_INT64)Track);
	}
	v2cleanup(mv_______);
	return ret;
}

extern char *__cdecl rspgettemppath();

/**
 * This fuction will write the id3 v2 tag on the file (support only to version 2.3 for the moment)
 *
 * utf8_filename = The mp3 file, (not utf-8 encoded)
 *
 * \return
 *
 * 0 - no error
 *
 * 1 - read only
 *
 * 2 - unable to create temp file
 *
 * 3 - cannot load data from file
 *
 * 4 - cannot open temp file to write (mode 1)
 *
 * 5 - cannot open input file to read
 *
 * 6 - cannot open temp file to write (mode 2)
 *
 * 7 - cannot replace original file
 *
 * 8 - ? ( I supose tampered id3v2 that may crash due to too large memory requirements )
 *
 */
int __stdcall Write_ID3_v2_tag(__int64 mv_instance, char *filename, char *Track,
                               char *Title, char *Artist, char *Album,
                               char *Year, char *Genre, char *Comment,
                               char *EncodedBy, char *URL, char *Copyright,
                               char *OriginalArtist, char *Composer)
{

	char temp[(300 * 6)];
	int ret;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	rspgettemppath_multithread(temp);
	strcpy(mv_______->id3_c___tempfolder, (char *)temp);
	v2cleanup(mv_______);
	mv_______->id3_c___v2Composer = malloc(strlen((char *)Composer) + 100);
	strcpy(mv_______->id3_c___v2Composer, ((char *)Composer));
	mv_______->id3_c___v2OriginalArtist =
		malloc(strlen((char *)OriginalArtist) + 100);
	strcpy(mv_______->id3_c___v2OriginalArtist, ((char *)OriginalArtist));
	mv_______->id3_c___v2Copyright = malloc(strlen((char *)Copyright) + 100);
	strcpy(mv_______->id3_c___v2Copyright, ((char *)Copyright));
	mv_______->id3_c___v2URL = malloc(strlen((char *)URL) + 100);
	strcpy(mv_______->id3_c___v2URL, ((char *)URL));
	mv_______->id3_c___v2EncodedBy = malloc(strlen((char *)EncodedBy) + 100);
	strcpy(mv_______->id3_c___v2EncodedBy, ((char *)EncodedBy));
	mv_______->id3_c___v2Comment = malloc(strlen((char *)Comment) + 100);
	strcpy(mv_______->id3_c___v2Comment, ((char *)Comment));
	mv_______->id3_c___v2Genre = malloc(strlen((char *)Genre) + 100);
	strcpy(mv_______->id3_c___v2Genre, ((char *)Genre));
	mv_______->id3_c___v2Year = malloc(strlen((char *)Year) + 100);
	strcpy(mv_______->id3_c___v2Year, ((char *)Year));
	mv_______->id3_c___v2Album = malloc(strlen((char *)Album) + 100);
	strcpy(mv_______->id3_c___v2Album, ((char *)Album));
	mv_______->id3_c___v2Artist = malloc(strlen((char *)Artist) + 100);
	strcpy(mv_______->id3_c___v2Artist, ((char *)Artist));
	mv_______->id3_c___v2Title = malloc(strlen((char *)Title) + 100);
	strcpy(mv_______->id3_c___v2Title, ((char *)Title));
	mv_______->id3_c___v2Track = malloc(strlen((char *)Track) + 100);
	strcpy(mv_______->id3_c___v2Track, ((char *)Track));
	ret =
		id3v2tag_ok_write_multithread((morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)mv_instance, (char *)filename);
	v2cleanup(mv_______);
	return ret;
}
/**
 * It will remove the ID3 v2 tag from the file (only support for version 2.3 (November/2020)), after the removal it will adjust the size of the file
 *
 * @param filename the mp3 file
 *
 * \return
 *
 * 0 - no error
 *
 * 1 - read only
 *
 * 2 - unable to create temp file
 *
 * 3 - cannot open input file to read
 *
 * 4 - cannot open temp file to write
 *
 * 5 - cannot replace original file
 *
 */
int __stdcall Remove_ID3V2_tag(__int64 mv_instance, char *filename)
{
	char temp[(300 * 6)];
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	rspgettemppath_multithread(temp);
	strcpy(mv_______->id3_c___tempfolder, (char *)temp);
	return remove_id3v2_tag(mv_______, (char *)filename);
}
/**
 * To retrieve the 60 hertz level from the equalizer
 *
 */
int morcego_getfft60(morcego___i___instance__a__bucaneiro_engineering *
                     mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f60;
}
/**
 * To retrieve the 170 hertz level from the equalizer
 *
 */
int morcego_getfft170(morcego___i___instance__a__bucaneiro_engineering *
                      mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f170;
}
/**
 * To retrieve the 310 hertz level from the equalizer
 *
 */
int morcego_getfft310(morcego___i___instance__a__bucaneiro_engineering *
                      mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f310;
}
/**
 * To retrieve the 600 hertz level from the equalizer
 *
 */
int morcego_getfft600(morcego___i___instance__a__bucaneiro_engineering *
                      mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f600;
}
/**
 * To retrieve the 1 kilohertz level from the equalizer
 *
 */
int morcego_getfft1000(morcego___i___instance__a__bucaneiro_engineering *
                       mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f1000;
}
/**
 * To retrieve the 3 kilohertz level from the equalizer
 *
 */
int morcego_getfft3000(morcego___i___instance__a__bucaneiro_engineering *
                       mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f3000;
}
/**
 * To retrieve the 6 kilohertz level from the equalizer
 *
 */
int morcego_getfft6000(morcego___i___instance__a__bucaneiro_engineering *
                       mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f6000;
}
/**
 * To retrieve the 12 kilohertz level from the equalizer
 *
 */
int morcego_getfft12000(morcego___i___instance__a__bucaneiro_engineering *
                        mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f12000;
}
/**
 * To retrieve the 14 kilohertz level from the equalizer
 *
 */
int morcego_getfft14000(morcego___i___instance__a__bucaneiro_engineering *
                        mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f14000;
}
/**
 * To retrieve the 16 kilohertz level from the equalizer
 *
 */
int morcego_getfft16000(morcego___i___instance__a__bucaneiro_engineering *
                        mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.f16000;
}
/**
 * To retrieve the peak value from the equalizer
 *
 */
int morcego_getfftpeak(morcego___i___instance__a__bucaneiro_engineering *
                       mv_______)
{
	if (mv_______->decoder_c___liberafft || mv_______->decoder_c___flag_de_pause)
	{
		return 0;
	}
	return mv_______->decoder_c___spec.peak;
}
/**
 * To retrieve the levels for the spectrum analizer form in C# or other GUI generator, it is very accurate
 *
 */
int __stdcall GetSpectrumAnalyzer(__int64 mv_instance, int *f60, int *f170,
                                  int *f310, int *f600, int *f1000,
                                  int *f3000, int *f6000, int *f12000,
                                  int *f14000, int *f16000, int *fpeak)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	*f60 = morcego_getfft60(mv_______);
	*f170 = morcego_getfft170(mv_______);
	*f310 = morcego_getfft310(mv_______);
	*f600 = morcego_getfft600(mv_______);
	*f1000 = morcego_getfft1000(mv_______);
	*f3000 = morcego_getfft3000(mv_______);
	*f6000 = morcego_getfft6000(mv_______);
	*f12000 = morcego_getfft12000(mv_______);
	*f14000 = morcego_getfft14000(mv_______);
	*f16000 = morcego_getfft16000(mv_______);
	*fpeak = morcego_getfftpeak(mv_______);
	return 0;
}
/**
 * To enable or disable the spectrum analizer
 *
 */
int __stdcall EnableSpectrumAnalyzer(__int64 mv_instance, int enable)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	enable_fft_ok(mv_______, enable);
	return 0;
}
/**
 * To know if a path is a file, use the System.IO method instead
 *
 */
int __stdcall IsPathFile(__int64 mv_instance, char *filename)
{
	check_mv_instance(mv_instance);
	return (ispathfile((char *)filename));
}
/**
 * To know if a path is a folder, use the System.IO method instead
 *
 */
int __stdcall IsPathFolder(__int64 mv_instance, char *filename)
{
	check_mv_instance(mv_instance);
	return (ispathfolder((char *)filename));
}
/**
 * To retrieve the debug information, notice that we preffer to use the DebugView from Mark Russinovich if possible, it is an amazing application that need to be present in all developers machine
 *
 */
int __stdcall DebugInformation(__int64 mv_instance, char *debug)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	debug[0] = 0;
	if (mv_______->decoder_c___hasdebuginfo)
	{
		strcpy((char *)debug, get_debuginformation_multithread(mv_______));
		return 0;
	}
	return 1;
}
/**
 * To remove the voice, it works very well if the voice in a media file is equal in both stereo channels
 *
 */
int morcego_enablevoiceremoval(morcego___i___instance__a__bucaneiro_engineering *mv,
                               __INT32_OR_INT64 argumento2)
{
	mv->decoder_c___enablevoiceremoval = argumento2;
	return 0;
}
/**
 * To remove the voice, it works very well if the voice in a media file is equal in both stereo channels
 *
 */
int __stdcall EnableVoiceRemoval(__int64 mv_instance, int enable)
{
	check_mv_instance(mv_instance);
	return morcego_enablevoiceremoval((morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)mv_instance, enable);
}
/**
 * To enable the echo wav effect, very limited, maybe better in a near future
 *
 */
int morcego_enableecho(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                       int argumento2, int argumento3)
{
	mv_______->decoder_c___enableecho = argumento2;
	mv_______->decoder_c___multiplier = argumento3;
	resetwaveeefects(mv_______);
	return 0;
}
/**
 * To enable the echo wav effect, very limited, maybe better in a near future
 *
 */
int __stdcall EnableEcho(__int64 mv_instance, int enable, int delay)
{
	check_mv_instance(mv_instance);
	return morcego_enableecho((morcego___i___instance__a__bucaneiro_engineering
	                           *)(__INT32_OR_INT64)mv_instance,
	                          enable, delay);
}
/**
 * To enable the surround wav effect, very simple, give it a try
 *
 */
int __stdcall EnableSurround(__int64 mv_instance, int enable)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___enablesurround = enable;
	return 0;
}
/**
 * To enable the Amanda wav effect, the results are amazing, even for mono files, give it a try, you will never listen to music again with this disabled...requires phones
 *
 */
int __stdcall BE_Special_Wav_Effect(__int64 mv_instance, int enable, int range)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___enablesurround2 = enable;
	mv_______->decoder_c___globalrange =      range;
	return 0;
}
/**
 * Not in use anymore (November/2020), Libav don`t play encrypted data as far I know
 *
 */
int morcego_useencryption(morcego___i___instance__a__bucaneiro_engineering *
                          mv_______,
                          __INT32_OR_INT64 argumento2,
                          __INT32_OR_INT64 argumento3)
{
	if (!memcmp((char *)argumento3, "yes", 3))
	{
		mv_______->decoder_c___usandoencrypt = 1;
		strncpy(mv_______->decoder_c___key2, (char *)argumento2, 32);
		mv_______->decoder_c___key2[32] = 0;
	}
	else
	{
		mv_______->decoder_c___usandoencrypt = 0;
	}
	return 0;
}
/**
 * Not in use anymore (November/2020)
 *
 */
int __stdcall UseEncryption(__int64 mv_instance, int enable, char *pass)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	if (enable)
	{
		return morcego_useencryption(mv_______, (__INT32_OR_INT64)pass,
		                             (__INT32_OR_INT64) "yes");
	}
	else
	{
		return morcego_useencryption(mv_______, (__INT32_OR_INT64)pass,
		                             (__INT32_OR_INT64) "no");
	}
	return 0;
}
/**
 * Function to encrypt the media file (DRM like method), not in use anymore (November/2020)
 *
 */
int __stdcall Encrypt_File(__int64 mv_instance, char *input, char *output, char *pass)
{
	check_mv_instance(mv_instance);
	return encryptfile(input, output, (char *)pass);
}
/**
 * To enable the Freeverb wav effect, it is a very good reverb effect, stolen from the linux media player XMMS
 *
 */
int __stdcall EnableFreeverb(__int64 mv_instance, int enable)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___enablefreeverb = enable;
	return 0;
}
/**
 * It will enable SoundTouch by http://www.surina.net/soundtouch, then you can change the tempo,
 * pitch and rate, the quality of this code is amazing only testing you will see the very good
 * precision, the original developer of SoundTouch know what he is doing<br><br>
 *
 * Notice that we have modified the sources to compile without warnings
 *
 * @param enable 0 to no or 1
 *
 * @param tempo range from -95 to +95
 *
 * @param pitch range from -60 to +60
 *
 * @param rate range from -95 to +95
 *
 * \return always 0
 */
int __stdcall EnableSoundTouch(__int64 mv_instance, int enable, int tempo, int pitch,
                               int rate)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	if (tempo < -45)//need to check it later...
	{
		tempo = -45;
	}
	if (rate < -45)
	{
		rate = -45;
	}
	mv_______->decoder_c___grate = rate;
	mv_______->decoder_c___gpitch = pitch;
	mv_______->decoder_c___gtempo = tempo;
	mv_______->decoder_c___enablesoundtouch = enable;
	return 0;
}
/**
 * Simple wrapper to waveOutGetNumDevs windows function
 *
 */
int __stdcall GetNumberofWaveOutDevices(__int64 mv_instance) //not really necessary but we are tring to follow standards
{
	if(0 != mv_instance)
	check_mv_instance(mv_instance);
	return waveOutGetNumDevs();
}

/**
 * To detect whether a new Phone or soundcard appeared to the system
 *
 */
int __stdcall DetectChangeInSoundCards_i(__int64 mv_instance) //not really necessary but we are tring to follow standards
{
	int ret_i;
	int l_i;

	check_mv_instance(mv_instance);
	
	static char signature_phones    [1027] = {0};
	char        signature_phones_cur[1027] = {0};
	char        data_i              [1027] = {0};
	
	ret_i = GetNumberofWaveOutDevices(mv_instance);

			if (0 == ret_i)
			{
				return 0;
			}
			else
			{
				for (l_i = 0; l_i < ret_i; l_i++)
				{
					memset(data_i, 0, sizeof(data_i));
					GetWaveOutDevicesName(mv_instance, l_i, data_i);
					strcat(signature_phones_cur, data_i);
				}
			}
	
	if(0 != strcmp(signature_phones, signature_phones_cur))
	{
		if(0 == strlen(signature_phones))
		{
			strcpy(signature_phones, signature_phones_cur);
			return 1; //first change
		}
		else
		{
			strcpy(signature_phones, signature_phones_cur);
			return 2; //real change
		}

	}
	else
	{
		return 0;
	}
	
}

/**
 * To detect whether a new Phone or soundcard appeared to the system, internal use
 *
 */
int __fastcall DetectChangeInSoundCards_i_internal(void) //not really necessary but we are tring to follow standards
{
	int ret_i;
	int l_i;
	
	static char signature_phones    [1027] = {0};
	char        signature_phones_cur[1027] = {0};
	char        data_i              [1027] = {0};
	
	ret_i = GetNumberofWaveOutDevices(0);

			if (0 == ret_i)
			{
				return 0;
			}
			else
			{
				for (l_i = 0; l_i < ret_i; l_i++)
				{
					memset(data_i, 0, sizeof(data_i));
					GetWaveOutDevicesName(0, l_i, data_i);
					strcat(signature_phones_cur, data_i);
				}
			}
	
	if(0 != strcmp(signature_phones, signature_phones_cur))
	{
		if(0 == strlen(signature_phones))
		{
			strcpy(signature_phones, signature_phones_cur);
			return 1; //first change
		}
		else
		{
			strcpy(signature_phones, signature_phones_cur);
			return 2; //real change
		}

	}
	else
	{
		return 0;
	}
	
}

////////////////////////////////////////////////////////////////////////
/* Bucaneiro **********************************************************Amanda***
 *******************************************************************************
 ************Paul***********************************Lucrecia********************
 *********************************Deus******************************************
 *******************************************************************************
 ******Andrea*******************************************************Alessandra*/

/**
 * To remove the initial spaces including \r \n and \t
 *
 */
void removespace_begin(char *path)
{
	int ret;
	char *ptr;
	char *ptrdesloca;
	ptrdesloca = path;
	ret = strlen(path);
	if (ret)
	{
		ptr = malloc(ret + 1);
		memset(ptr, 0, ret + 1);
		while ((*ptrdesloca == ' ') || (*ptrdesloca == '\r') || (*ptrdesloca == '\n') || (*ptrdesloca == '\t'))
		{
			ptrdesloca++;
		}
		strcpy(ptr, ptrdesloca);
		memset(path, 0, ret);
		strcpy(path, ptr);
		free(ptr);
	}
}
/**
 * To remove the end of string spaces including \r \n and \t
 *
 */
void removespace_end(char *path)
{
	int ret;
inicio:
	ret = strlen(path);
	if (ret)
	{
		if ((path[(ret - 1)] == ' ') || (path[(ret - 1)] == '\r') || (path[(ret - 1)] == '\n') || (path[(ret - 1)] == '\t'))
		{
			path[(ret - 1)] = 0;
			goto inicio;
		}
	}
}
/**
 * Equivalent to C# Trim(), this is what we was using before the knowledge about the Trim method of csharp, this is not a joke
 *
 */
void removespace(char *data)
{
	removespace_begin(data);
	removespace_end(data);
}
//needs updates

/**
 * To return a string with the error description
 *
 */
int morcego_geterrorstring(morcego___i___instance__a__bucaneiro_engineering *mv_______,
                           __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3)
{
	((char *)argumento3)[0] = 0;
	switch (argumento2)
	{
	case 0:
		strcpy((char *)argumento3, "No error");
		break;
	case 1000:
		strcpy((char *)argumento3, "Playing..."); //20
		break;
	case 1001:
		strcpy((char *)argumento3, "Playback paused"); //20
		break;
	case 10:
		strcpy((char *)argumento3, "Cannot open media file"); //20
		break;
	case 9:
		strcpy((char *)argumento3, "No valid devices in the system");
		break;
	case 3:
		strcpy((char *)argumento3, "Input does not appear to be a mv_______->decoder_c___wav file"); //23
		break;
	case 4:
		strcpy((char *)argumento3,
		       "Error reading first page of Ogg bitstream data");
		break;
	case 5:
		strcpy((char *)argumento3, "Error reading initial header packet");
		break;
	case 6:
		strcpy((char *)argumento3,
		       "This Ogg bitstream does not contain Vorbis");
		break;
	case 7:
		strcpy((char *)argumento3, "Corrupt secondary header");
		break;
	case 8:
		strcpy((char *)argumento3,
		       "End of file before finding all Vorbis headers!");
		break;
	case 2:
		strcpy((char *)argumento3, "Error opening waveout");
		break;
	case 20:
		strcpy((char *)argumento3,
		       "Input does not appear to be a wav file");
		break;
	case 21:
		strcpy((char *)argumento3,
		       "Only PCM wav files can play");
		break;
	case 22:
		strcpy((char *)argumento3, "Invalid number of bits per sample");
		break;
	case 24:
		strcpy((char *)argumento3, "Invalid MPEG file");
		break;
	case 25:
		strcpy((char *)argumento3, "Invalid number of channels");
		break;
	case 26:
		strcpy((char *)argumento3, "Invalid sample rate");
		break;
	case 300:
		strcpy((char *)argumento3,
		       "Tampering detected , please reinstall the component");
		break;
	case 900:
		strcpy((char *)argumento3, "Unknown event");
		break;
	case 901:
		strcpy((char *)argumento3, "Libav error: ");
		strcat((char *)argumento3,
		       mv_______->decoder_c___morcego_libav_error);
		break;
	default:
		strcpy((char *)argumento3, "Unknown error");
		break;
	}
	return 0;
}
/**
 * To return a string with the error description
 *
 */
int __stdcall GetErrorString(__int64 mv_instance, int value, char *data)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	morcego_geterrorstring(mv_______, (__INT32_OR_INT64)value, (__INT32_OR_INT64)data);
	return 0;
}
/**
 * As the name says it will retrieve how many audio tracks a media file have
 *
 */
int __stdcall GetNumberOfAudioTracks(__int64 mv_instance, char *utf8_filename,
                                     char *error_message)
{
	int
	get_number_of_audio_tracks(morcego___i___instance__a__bucaneiro_engineering * mv_______,
	                           char *utf8_filename, char *error_message);
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
		
	mv_______->libav_c___retrieve_track_and_subtitles_mode_i = I_MODE_IS_AUDIO____;
		
	return get_number_of_audio_tracks(mv_______, (char *)utf8_filename,
	                                  (char *)error_message);
}

/**
 * As the name says it will retrieve how many subtitles tracks a media file have
 *
 */
int __stdcall GetNumberOfSubtitles(__int64 mv_instance, char *utf8_filename,
                                     char *error_message)
{
	int
	get_number_of_audio_tracks(morcego___i___instance__a__bucaneiro_engineering * mv_______,
	                           char *utf8_filename, char *error_message);
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
		
	mv_______->libav_c___retrieve_track_and_subtitles_mode_i = I_MODE_IS_SUBTITLE_;
		
	return get_number_of_audio_tracks(mv_______, (char *)utf8_filename,
	                                  (char *)error_message);
}
/**
 * To play a media file as if it was mono channel
 *
 */
int __stdcall BucaneiroPlayStereoAsMono(__int64 mv_instance, int enable)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___bucaneiro_play_as_mono = enable;
	return 0;
}
/**
 * To show an informative Message Box
 *
 */
void mprintf_about(char *format,     ...)
{
	va_list tua_amanda                  ;
	char buffer                   [1024];
	va_start(tua_amanda,         format);
	vsprintf(buffer, format, tua_amanda);
	va_end(tua_amanda                  );
	MessageBox(0,                 buffer, 
	   O_NOME_ATUAL, MB_OK | MB_TOPMOST);
}
/**
 * To show the About box of the DLL
 *
 */
int __stdcall About()
{
	void mprintf_about(char *format, ...);
	mprintf_about("Brazilian GPL 3 DLL to play and decode"
	              " any media file"
	              " supported by ffmpeg (Libav) with some wave effects and equalizer");
	return 0xdeadbeef;
}
/**
 * To retrieve the remaining playback time as a string
 *
 */
int __stdcall Alladin_GetRemainingTime(__int64 mv_instance, char *data)
{
	int lenght = 0;
	int position = 0;
	double a;
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	lenght = morcego_getseconds(mv_______);
	position = morcego_gettime(mv_______);
	a = lenght - position;
	a = a / 1000;
	strcpy((char *)data, secondtostring(a));
	return 0;
}
/**
 * To retrieve the bytes, kilobytes, megabytes and gigabytes from an int value
 *
 */
void calc(int val, int *bytes, int *kbs, char *mb, char *gb)
{
	double       a;
	a =        val;
	*bytes   = val;
	a = val / 1024;
	*kbs =       a;
	a = a   / 1024;
	*mb =        a;
	a = a   / 1024;
	*gb =        a;
	return        ;
}
/**
 * It is required because the player was adapted to only play two channels and it make
 * possible to use some wav effects in any media file, ok?
 *
 */
int PCM16MonoToPCM16Stereo(char *inSamples_b, unsigned int b_len,
                           char *outSamples_b)
{

	/*
	   this code is very clever because input and output can overlap, if it was my code I
	   would make a copy on a temp buffer first, of course not optimized as this.

	   Spend a few minutes trying to figure how it works and you will see how clever these original developers was
	 */


	short *inSamples = (short *)inSamples_b;
	short *outSamples = (short *)outSamples_b;
	unsigned int i;
	unsigned int index;

	for (i = 1; i <= b_len / 2; i++)
	{
		index = b_len / 2 - i;
		outSamples[2 * index    ] = inSamples[index];
		outSamples[2 * index + 1] = inSamples[index];
	}
	
	return b_len * 2;
}
/**
 * My code, back in 2004, very simple, it will force the same data on both channels
 *
 */
void BucaneiroStereoToMono(char *buffer, int len)
{
	int p = 0;
	int i;
	short *a = (short *)buffer;
	double temp;
	for (i = 0; i < len / 2 / 2; i++)
	{
		temp = ((double)a[p] + (double)a[p + 1]) * 0.5;
		if (temp > 32767)
		{
			temp = 32767;
		}
		if (temp < -32768)
		{
			temp = -32768;
		}
		a[p] = temp;
		a[p + 1] = temp;
		p += 2;
	}
	return;
}
/**
 * It will retrieve whether the player is in multiplayer mode, now with Libav the player is never multiplayer, maybe
 * again in the future when we make the whole code of the DLL multiplayer capable, a lot of time to do this is required
 *
 */
void __stdcall IsMultiplayer(__int64 mv_instance, int multiplayer_or_not)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->decoder_c___multiplayer_or_not = multiplayer_or_not;
}
/**
 * It will define the width of the player window (internal use)
 *
 */
void __stdcall SetVideoWidth(__int64 mv_instance, int width)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->libav_c___inputwidth = width;
}

/**
 * It will pass the window handles required and the arguments for the video playback, the hwnd of the window need to be from a C# picturebox
 *
 * @param hwnd the first window that will be the background of the player
 *
 * @param player_hwnd the player window, will be adjusted based on the size of the media file
 *
 * @param width the width of the background window
 *
 * @param heigth the height
 *
 * @param ratio the ratio to be used
 *
 * @param left the X position of the window
 *
 * @param top the Y position of the window
 *
 */
void __stdcall PassWindowInformation(__int64 mv_instance,
                                     __int64 hwnd,
                                     __int64 player_hwnd, int width, int heigth, int ratio, int left, int top)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	if(enable_desktop_i)
	{
		return;
	}

	mv_______->libav_c___hwnd = hwnd;
	mv_______->libav_c___size_of_window_width = width;
	mv_______->libav_c___size_of_window_height = heigth;
	mv_______->libav_c___player_hwnd = player_hwnd;
	mv_______->libav_c___the_ratio = ratio;

	mv_______->libav_c___adjust_top = top;
	mv_______->libav_c___adjust_left = left;
	mv_______->libav_c___request_for_adjust = 1;
}
/**
 * To retrieve the video information, very informative
 *
 */
void __stdcall GetVideoInfo(__int64 mv_instance, char *data)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	strcpy(data, mv_______->libav_c___video_information);
}
/**
 * To disable the video
 *
 */
void __stdcall DisableVideo(__int64 mv_instance, int disable)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->libav_c___disable_video = disable;
}
/**
 * To make the video thread stop working
 *
 */
void __stdcall Don_t_Draw_Video(__int64 mv_instance, int do_not_draw)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->libav_c___donot_draw_video = do_not_draw;
}
/**
 * To return the width and height of the media file that was loaded, need to be called only after the Play or Open function are called
 *
 * @param w the width
 *
 * @param h the height, as you may expect
 *
 */
void __stdcall GetWindowSize(__int64 mv_instance, int *w, int *h)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	*w = mv_______->libav_c___width_of_window;
	*h = mv_______->libav_c___height_of_window;
}
/**
 * It will return the pixel format (but notice that in October/2020
 * it was modified, and for the moment is incomplete) and a few other
 * informations about the video rate, audio and video sync
 *
 */
void __stdcall GetPixelFormat____(__int64 mv_instance, char *format)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	if (mv_______->decoder_c___tm < (int) GetTickCount())
	{
		mv_______->decoder_c___tm = GetTickCount() + 500;
		mv_______->decoder_c___tm_value = mv_______->analisys_c___sync;
	}
	sprintf(format, "%s rate %0.2f audio %0.2f video %0.2f",
	        get_pixel_format_info___(mv_______),
	        mv_______->libav_c___ajusted_frame_rate,
	        mv_______->decoder_c___valor_de_deslocamento_de_audio * 1000,
	        mv_______->decoder_c___tm_value);
}
/**
 * To adjust the ratio of the video player
 *
 */
void __stdcall AdjustRatio(__int64 mv_instance, double adjust)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	mv_______->libav_c___adjusted_ratio = adjust;
	mv_______->libav_c___request_for_adjust = 1;
}
/**
 * Without this call the maximum video width is the limit of the real form size,
 * with this the video size can be above the form limits, usefull for modified
 * fullscreen sizes, above 300% of the original video window
 *
 */
void __stdcall DisableWidthLimit(__int64 mv_instance)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->libav_c___disable_width_limit = 1;
}
/**
 * To know whether the media file is a playlist file (.wpl for Windows
 * Media Player or .jun for rsppmp3 DLL), filename can be Unicode
 * (utf-8 based), these are the only playlist files handled
 * for the moment by the DLL, soon Winamp playlists will be supported
 *
 */
int __stdcall Is_WPL_Playlist(__int64 mv_instance, char *filename_utf8)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	is_playlist(mv_______, filename_utf8);
	if (mv_______->playlist_c___is_playlist)
	{
		return 1;
	}
	return 0;
}
/**
 * To return all the media files that are available in the wpl file (notice that it is using my own xml parser implementation and that it may have bugs for Unicode based media files at this moment, we will check and fix it in a near future) or the jun file (rsppmp3 based original playlist mode and file)
 *
 */
int __stdcall GetPlaylistFiles(__int64 mv_instance, char *filename)
{
	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	if (mv_______->playlist_c___player_index ==
	    mv_______->playlist_c___media_files_count)
	{
		return 0;
	}
	strcpy(filename,
	       mv_______->playlist_c___media_files[mv_______->playlist_c___player_index++]);
	return 1;
}

#include <stdio.h>
/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0df       /* constant vector a */
#define UPPER_MASK 0x80000000 /* most significant w-r bits */
#define LOWER_MASK 0x7fffffff /* least significant r bits */
/* Tempering parameters */
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y) (y >> 11)
#define TEMPERING_SHIFT_S(y) (y << 7)
#define TEMPERING_SHIFT_T(y) (y << 15)
#define TEMPERING_SHIFT_L(y) (y >> 18)
static unsigned long mt[N]; /* the array for the state vector  */
static int mti = N + 1;         /* mti==N+1 means mt[N] is not initialized */
/* initializing the array with a NONZERO seed */
void sgenrand(unsigned long seed)
{
	/* setting initial seeds to mt[N] using         */
	/* the generator Line 25 of Table 1 in          */
	/* [KNUTH 1981, The Art of Computer Programming */
	/*    Vol. 2 (2nd Ed.), pp102]                  */
	mt[0] = seed & 0xffffffff;
	for (mti = 1; mti < N; mti++)
		mt[mti] = (69069 * mt[mti - 1]) & 0xffffffff;
}

int genrand()
{
	unsigned long y;
	static unsigned long mag01[2] = {0x0, MATRIX_A};
	/* mag01[x] = x * MATRIX_A  for x=0,1 */
	if (mti >= N)
	{ /* generate N words at one time */
		int kk;
		if (mti == N + 1)       /* if sgenrand() has not been called, */
			sgenrand(4357); /* a default initial seed is used   */
		for (kk = 0; kk < N - M; kk++)
		{
			y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
			mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
		}
		for (; kk < N - 1; kk++)
		{
			y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
			mt[kk] = mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1];
		}
		y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
		mt[N - 1] = mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1];
		mti = 0;
	}

	y = mt[mti++];
	y ^= TEMPERING_SHIFT_U(y);
	y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
	y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
	y ^= TEMPERING_SHIFT_L(y);
	//return ((double) y / (unsigned long) 0xffffffff);  /* reals */
	return (int)y; /* for integer generation */
}

/**
 * To get a randomic number between min and max inclusive, seed is automatic loaded during the first call
 *
 */
int __stdcall get_rand(int min, int max)
{
   
     int range = max - min;
     int ret;
     int genrand();
     void sgenrand(unsigned long seed);
     static int already = 0;
     if (0 == already)
     {
	  sgenrand(GetTickCount());
	  already = 1;
     }

     /*
       BOOLEAN RtlGenRandom(
       PVOID RandomBuffer,
       ULONG RandomBufferLength
       );
     */
	     
     typedef BOOLEAN (__stdcall * RtlGenRandom)(PVOID RandomBuffer,
						ULONG RandomBufferLength);


     static HMODULE my_i____dll = NULL;
     static RtlGenRandom RtlGenRandom_func = NULL;

     ret = genrand() + GetTickCount();
 
     if(RtlGenRandom_func)
     {
	  assert(TRUE == RtlGenRandom_func(& ret, 4));
	  goto already_i;
     }
	     
     if(NULL == my_i____dll)
     {	  
		  
	  my_i____dll = LoadLibraryA
	       (
		    "Advapi32.dll"
		    );

	  if(NULL == my_i____dll)
	  {
	       ;	
	  }
	  else
	  {

	       RtlGenRandom_func = (void *) GetProcAddress(
		    my_i____dll,
		    "SystemFunction036"
		    );
	     
	       if(NULL == RtlGenRandom_func)
	       {
		    ;
	       }
	       else
	       {		    

		    assert(TRUE == RtlGenRandom_func(& ret, 4));
			    
	       }
		       
	  }

     }

already_i:;

     if(/*1 || */ NULL == RtlGenRandom_func)
     {
	  pedro_dprintf(1001, "Important!!! Cannot use the function SystemFunction036\n");
	  Beep(1000, 1000);
     }

     //ret = -2147483648;
     
     ret = abs(ret);
     ret = ret % (range + 1);
     ret += min;

     pedro_dprintf(-1, "valor de ret antes do fix %d\n", ret);
     
     if(ret < min)
     {
	  ret = min;//fix for the abs problem
	  
	  pedro_dprintf(-1, "valor de ret depois do fix %d\n", ret);
     
     }
     return ret;
}
/**
 * To retrieve the filename from the path, please use the System.IO methods instead
 *
 */
void __stdcall get_filename(char *path, char *filename)
{

	stripfilenameandpath(path, NULL, filename);
}
/**
 * It can adjust the audio and video sysnc, by default the
 * audio and video sync is very well defined, but you can
 * change it if you want, the value is based in milliseconds
 *
 */
void __stdcall AdjustSync(__int64 mv_instance, double value)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	mv_______->libav_c___sync_adjust = value;

	if(-27 == value)
	{

	     pedro_dprintf(1001, "Playlist debug mode enabled, to disable pass -28\n");
	     enable_playlist_debug = true;
	     
	}
	
	if(-28 == value)
	{

	     pedro_dprintf(1001, "Playlist debug mode disabled\n");
	     enable_playlist_debug = false;
	     
	}
	
}
/**
 * To know whether the audio and video sync was lost, just informative for the moment and
 * due to the many modifications on the libav code it may not be working very well at this
 * moment, please, check
 *
 */
int __stdcall GetSyncStatus(__int64 mv_instance)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	return mv_______->syncstatus;
}
/**
 * It will enable or disable the slow computers modification to make the audio and video match even if
 * the time required to decode and show the video frame is less than the processing time available.
 *
 * In fast computers this function is irrelevant, but if it is the case never enable it because in
 * case of too many processor load due to other applications running may trigger the portions of
 * the code that handle it and the video playback can become unstable
 */
void __stdcall SlowComputersCommand_k_p(__int64 mv_instance, int enable_slow_computers_hack)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	mv_______->libav_c___enable_slow_computers_hack_k_p = enable_slow_computers_hack;

	return;

}
/**
 * It will retrieve the real number of channels in the media file.
 *
 * Internally the player will convert all channels above 2 to 2 and play.
 *
 * It is just informative.
 */
int __stdcall GetOriginalNumberofChannels(__int64 mv_instance)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;


	return mv_______->libav_c___original_number_of_channels_k_p;
}
/**
 * It will return the information about the sample format of the media file loaded, with description
 *
 */
void __stdcall GetSampleFormatInfo
(
	__int64 mv_instance,
	char    * sample_format_string_k_p
)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;
	strcpy(sample_format_string_k_p, mv_______->libav_c___sample_rate_format_string);
	return;
}
/**
* Return 1 if the waveout was not ready yet, the player need to wait for
* this value to be 0 in order to call resume, it was added to the fullscreen code.
*
*/
int __stdcall GetWaveOutStatus_arp
(
	__int64 mv_instance
)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
		mv_instance;

	return mv_______->decoder_c___wave_out_open_flag;
}

/**
 * To init the playlist control
 *
 */
int __stdcall init_playlist_z(void);

int64_t item_number_z_;

bool active_z = false;

struct my_struct_for_list_ar_is_amanda_update_//for list only
{

  bool    nodata_z   ;
  bool    played_z   ;
  int64_t position   ;
  
  struct    my_struct_for_list_ar_is_amanda_update_ * next_ar;
};

struct my_struct_for_list_ar_is_amanda_update_ *aak_is_amanda_update_        = NULL;
struct my_struct_for_list_ar_is_amanda_update_ *aak_inicio_is_amanda_update_ = NULL;

struct my_struct_for_list_ar_is_amanda_update_ *aak_pointer_is_amanda_update_;

int has_itens_is_amanda_update_ = 0;

int has_itens_copy_is_amanda_update_ = 0;

/**
 * To add a new item to the linked list
 *
 */
void __stdcall add_more_one_z
(
)
{
  struct my_struct_for_list_ar_is_amanda_update_ *aak_ptr;
  if(!has_itens_is_amanda_update_)
    {
      aak_is_amanda_update_ = calloc(1, sizeof(struct my_struct_for_list_ar_is_amanda_update_));
      aak_inicio_is_amanda_update_    =  aak_is_amanda_update_;
      aak_pointer_is_amanda_update_   = aak_is_amanda_update_ ;
      aak_is_amanda_update_->next_ar  = calloc(1, sizeof(struct my_struct_for_list_ar_is_amanda_update_));

      aak_is_amanda_update_->next_ar->nodata_z = true;
      
      aak_is_amanda_update_->position = 0;

      aak_is_amanda_update_->nodata_z = false;
      
      has_itens_is_amanda_update_ = 1;
      has_itens_copy_is_amanda_update_ = has_itens_is_amanda_update_;
      aak_is_amanda_update_ = aak_is_amanda_update_->next_ar;
    }
  else
    {
      aak_ptr = aak_is_amanda_update_;
      assert(aak_ptr);
      aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_amanda_update_));
      aak_ptr->next_ar->nodata_z = true;
      aak_is_amanda_update_ = aak_ptr->next_ar;
      aak_ptr->position = has_itens_is_amanda_update_;
      aak_ptr->nodata_z = false;
      has_itens_is_amanda_update_++;
      has_itens_copy_is_amanda_update_ = has_itens_is_amanda_update_;
    }
	active_z = true;
}

int clean_list__ar_is_amanda_update_(void);

/**
 * To cleanup the linked list when it is not in use anymore
 *
 */
int clean_list_itens_is_amanda_update_(void)
{
 
  if(!has_itens_copy_is_amanda_update_)
    {
      clean_list__ar_is_amanda_update_();
      return 0;
    }
	
  aak_pointer_is_amanda_update_ = aak_pointer_is_amanda_update_->next_ar;
  has_itens_copy_is_amanda_update_--;
  assert(has_itens_copy_is_amanda_update_ >= 0);
	
  return 1;
}

/**
 * To cleanup the linked list when it is not in use anymore
 *
 */
int clean_list__ar_is_amanda_update_(void)
{
  struct my_struct_for_list_ar_is_amanda_update_ *my_ptr_ar ;
  struct my_struct_for_list_ar_is_amanda_update_ *my_ptr2_ar;
  my_ptr2_ar = aak_inicio_is_amanda_update_;
  my_ptr_ar  = aak_inicio_is_amanda_update_;
 inicio_ar:;
  if(!has_itens_is_amanda_update_)
    {
      has_itens_copy_is_amanda_update_ = 0;
      return 0;
    }
  my_ptr2_ar = my_ptr_ar;
  my_ptr_ar = my_ptr_ar->next_ar;

  if(1 == has_itens_is_amanda_update_)
    {      
      free(my_ptr2_ar->next_ar);
    }

  free(my_ptr2_ar);

  has_itens_is_amanda_update_--;

  goto inicio_ar;
  return 1;
}

/**
 * Search for a randomic item that have not played yet
 *
 * @return 0 if a valid item was found, 1 if all the itens played and the
 * looped started again, with this you can select if you want to stop
 * playing or keep playing randonly
 */

int __stdcall get_next_item_z(int64_t * item_got_z, int64_t * item_number_z)
{

     int items_skipped_i = 0;
     int i_z;
     int item_randomico_z = get_rand(0, has_itens_is_amanda_update_ - 1) ;

     * item_got_z    = 0;
     * item_number_z = 0;

     if(enable_playlist_debug)
	  pedro_dprintf(1001, "Randomic item got %d\n", item_randomico_z);
     
     if(0 == item_randomico_z && 1 == item_randomico_z)//compiler happy...
     {
	  exit(27);
     }

     if(false == active_z)
     {
		
	  if(enable_playlist_debug)
	       pedro_dprintf(1001, "No items in playlist yet\n");
	  return 0;
		
     }

     struct my_struct_for_list_ar_is_amanda_update_ *my_ptr_ar ;  
     my_ptr_ar  = aak_inicio_is_amanda_update_;


      if(enable_playlist_debug)
	   pedro_dprintf(1001, "Items to search in the playlist -> %d\n",
		(has_itens_is_amanda_update_ * 2 ) + 5);
     
     for(i_z = 0; i_z < (has_itens_is_amanda_update_ * 2 ) + 5; i_z++)
     {
            
	  if(i_z >= item_randomico_z)
	  {

	       if(false == my_ptr_ar->played_z)
	       {
		    item_number_z_ ++;
		    * item_number_z = item_number_z_;
		    my_ptr_ar->played_z = true;
		    *item_got_z = my_ptr_ar->position;		  
		    pedro_dprintf(-1, "saiu de get_next_item_z, pegou %lld\n", *item_got_z);
		    
		    if(enable_playlist_debug)
		    {
			 pedro_dprintf(1001, "Items skipped to get a file that was not played yet -> %d\n", items_skipped_i);
		    
			 pedro_dprintf(1001, "Item got in the first try item got %lld item number %lld\n", *item_got_z, * item_number_z);
		    }

		    return 0;
	      
	       }
	       else
	       {
		    items_skipped_i ++; 
	       }
	  
	  }

	  my_ptr_ar = my_ptr_ar->next_ar;
      
	  if(true == my_ptr_ar->nodata_z)
	  {	  
	       my_ptr_ar = aak_inicio_is_amanda_update_;
	  }
     }

     if(enable_playlist_debug)
	  pedro_dprintf(1001, "Cannot find an item in the first try, cleanning\n");
     
     my_ptr_ar = aak_inicio_is_amanda_update_;
     for(i_z = 0; i_z < has_itens_is_amanda_update_; i_z++)
     {

	  my_ptr_ar->played_z = false;
	  my_ptr_ar = my_ptr_ar->next_ar;
      
     }

     item_randomico_z = get_rand(0, has_itens_is_amanda_update_ - 1);

      if(enable_playlist_debug)
	   pedro_dprintf(1001, "New randomic number got %d\n", item_randomico_z);
     
     my_ptr_ar = aak_inicio_is_amanda_update_;
     for(i_z = 0; i_z < (has_itens_is_amanda_update_ * 2 ) + 1; i_z++)
     {
            
	  if(i_z >= item_randomico_z)
	  {

	       if(false == my_ptr_ar->played_z)
	       {
		    item_number_z_ = 0;
		    * item_number_z = item_number_z_;
		    *item_got_z = my_ptr_ar->position;
		        if(enable_playlist_debug)
			     pedro_dprintf(1001, "Item got after cleaning, in i_z position %d, item got %lld item number %lld\n",i_z, *item_got_z, * item_number_z);
		    return 1;
	      
	       }
	  
	  }

	  my_ptr_ar = my_ptr_ar->next_ar;
      
	  if(true == my_ptr_ar->nodata_z)
	  {	  
	       my_ptr_ar = aak_inicio_is_amanda_update_;
	  }
     }
  
     return 1;    
}
/**
 * To tell to the DLL that the selected item already played, then don`t play again until
 * the restart of the playlist (year-> 2021)
 *
 */
int __stdcall set_played_item_z(int64_t item_z)
{

  int i_z;
  struct my_struct_for_list_ar_is_amanda_update_ *my_ptr_ar ;  
  my_ptr_ar  = aak_inicio_is_amanda_update_;

	if(false == active_z)
	{
		
		return 0;
		
	}

  for(i_z = 0; i_z < has_itens_is_amanda_update_; i_z++)
    {

      if(my_ptr_ar->position == item_z)
	{
	  my_ptr_ar->played_z = true;
	}
      
      my_ptr_ar = my_ptr_ar->next_ar;
      
    }
  return 0;
}
/**
 * To clean-up and make it ready to the new process
 *
 *
 */
int __stdcall init_playlist_z()
{

  while(clean_list_itens_is_amanda_update_())
    {
      ;
    }
  assert(0 == has_itens_is_amanda_update_);

  item_number_z_ = 0;
  active_z = false;
  return 0;
}

int __stdcall init_jun_playlist_z(char * jun_playlist_z)
{

 our_jun_playlist_file_z =  _wfopen(utf8towide(jun_playlist_z), L"wb");

 if(our_jun_playlist_file_z)
   {
     return 0;
   }

 return 1;
}

void __stdcall  add_item_to_playlist_z(char * entry_z)
{
  fwrite(entry_z, 1, strlen(entry_z), our_jun_playlist_file_z);
  fwrite("\n", 1, 1, our_jun_playlist_file_z                 );
  return                                                      ;
}
void __stdcall close_playlist_z()
{
  fclose(our_jun_playlist_file_z                             );
  our_jun_playlist_file_z                               = NULL;
}

int __stdcall add_to_jun_playlist_z(char * jun_playlist_z)
{

 our_jun_playlist_file_z =  _wfopen(utf8towide(jun_playlist_z), L"ab");

 if(our_jun_playlist_file_z)
   {
     return 0;
   }

 return 1;
}

int __stdcall init_data_info_z()
{

  if(0 == number_z)
    {
      number_z = BE_CreateDecoder();
      pedro_dprintf(-1, "Value of init %lld\n", number_z);
    }
  return 0;
}

int __stdcall get_video_size_z(char * media_file_utf8_z,
			       __int64 hwnd_z,
			       __int64 player_hwnd_z,
			       int width__z,
			       int height__z,
			       int left_z,
			       int top_z,
			       __attribute__((unused)) int * width_z, __attribute__((unused)) int * height_z)
{

  init_data_info_z();

  loading_z = true;

check_mv_instance(number_z);
  morcego___i___instance__a__bucaneiro_engineering *mv_______ =
    (morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
    number_z;
  
  mv_______->libav_c___width_of_window  = -1;
  mv_______->libav_c___height_of_window = -1;
  
  /*
    ret = MP3.Open(number, MP3.wide2utf8(filename.Text), loop_, int.Parse(track.Text),
    video_p.Handle.ToInt64(),
    video_f_p.Handle.ToInt64(),
    video_p.Width,
    video_p.Height,
    the_ratio,
    video_p.Left,
    video_p.Top);
  */
  Open(number_z, media_file_utf8_z, 0, 1, hwnd_z,
       player_hwnd_z,
       width__z, height__z, 0, left_z, top_z, 0);
  /*
  while(-1 == SampleRate(number_z))
    {
      Sleep(50);
    }
  */

  //PlaybackCancel(number_z);
	
  return 0;
}
/**
 * This function is required by the project rspanyenc an ffmpeg based encoder...
 *
 *
 */
int __stdcall get_video_data(int * width_z, int * height_z, char * ratio_string_z, double * ratio_double_z)
{
  
  if(number_z)
    {
      check_mv_instance(number_z);
      morcego___i___instance__a__bucaneiro_engineering *mv_______ =
	(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
	number_z;

      pedro_dprintf(-1, "width  %d\n", 	mv_______->libav_c___width_of_window);
      pedro_dprintf(-1, "height %d\n", 	mv_______->libav_c___height_of_window);

      * width_z  =  mv_______->libav_c___width_of_window ;
      * height_z =  mv_______->libav_c___height_of_window;

      if(!loading_z)
	{

	  if(0 != * height_z)
	    {
	      * ratio_double_z = (double)* width_z / (double) * height_z;	  
	    }
	  else
	    {
	      * ratio_double_z = 1.0;
	    }
      
	  sprintf(ratio_string_z, "%.4f",  * ratio_double_z);
	      
	  return 0;
	}
  
      return 1;
    }
  else
    {
      return 1;
    }
}

int __stdcall unload_media_file_z()
{

  if(number_z)
    {
      PlaybackCancel(number_z);
    }
  
  return 0;
}
/**
 * This function will retrieve the actual memory usage of
 * the process using the rsppmp3 DLL
 *
 *
 *
 */
int __stdcall memory_usage__z(char *data_z)
{
  //#pragma message "amanda & MathMan compiling Tar DLL at " __TIME__ "..."
  /*
                                                                                                                                                                                  ¯\_(^^)_/¯
   */
  double val_z;
  PROCESS_MEMORY_COUNTERS_EX memory;

  if(-1 == last_value_Z)
  {

       goto inside_Z;       
       
  }
  
  if(GetTickCount() > (DWORD) oldvalue_Z)
  {

  inside_Z:;
       pedro_dprintf(-1, "vai %d\n", GetTickCount());
       /* Mr Do. */ GetProcessMemoryInfo(GetCurrentProcess(), (void *)&memory, sizeof(memory));

       oldvalue_Z =  GetTickCount() + 500;

       last_value_Z = memory.WorkingSetSize;

  }
  else
  {
       memory.WorkingSetSize = last_value_Z;
  }
  val_z = memory.WorkingSetSize;
  val_z = val_z / 1024.0;
  val_z = val_z / 1024.0;
  sprintf(data_z, "%.3f MB", val_z);

  if(GetTickCount() < (DWORD) oldvalue_Z - 600)//o avoid the 49 days problem...
  {

       oldvalue_Z = GetTickCount();
       
  }
    
  return 0;
}

void __stdcall Amanda_s_Smart_Ape_Use_Cache(__int64 mv_instance, int value_amanda_s_smart_ape)
{

	check_mv_instance(mv_instance);
	morcego___i___instance__a__bucaneiro_engineering *mv_______ =
		(morcego___i___instance__a__bucaneiro_engineering *)(__INT32_OR_INT64)
			mv_instance;

	if (27 == value_amanda_s_smart_ape)
	{
		mv_______->libav_c___amanda_s_smart_ape_use_cache = false;
	}
	else if (51 == value_amanda_s_smart_ape)
	{
		mv_______->libav_c___amanda_s_smart_ape_use_cache = true;
	}
	else
	{
		exit(27);
	}
	return;
}