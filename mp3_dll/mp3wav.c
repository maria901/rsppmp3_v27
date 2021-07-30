
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

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif
#include <windows.h>
#include <stdio.h>
#undef NDEBUG
#include <assert.h>

#include "neaacdec.h"
#include "audio.h"

#include "../morcego/be_constants.h"
/*
#pragma warning( disable : 4101 )

#pragma warning( disable : 4102 )
#pragma warning( disable : 4018 )
*/
int id3v2tag_check (char *filename);
size_t fread_unbuffered (void *ptr, size_t size, size_t nelem, FILE * stream);
size_t fwrite_unbuffered (const void *ptr, size_t size, size_t nelem,
			  FILE * stream);
__int64 _ftelli64_arab (FILE * stream);
int _fseeki64_arab (FILE * stream, __int64 offset, int origin);

__int64 id3v2tag (char *filename);
extern int posicionador_de_mpeglib;
extern int flag_de_seek_mpeglib_;
int rewrite_header (FILE * out, unsigned int written);

int write_prelim_header (FILE * out, int channels, int samplerate);

int detect (char *filename, __int64 * seekpoint);

void rfree (void *add);

void *rmalloc (int size);

int remove_id3v2_tag (char *filename);

int id3v2tag_ok_write (char *filename);

short invertbits16 (short value);

int invertbits32 (int value);

extern const char *const ID3v1_genre[];

int remove_id3v1_tag (char *filename);

int id3v1tag_ok_write (char *filename);

int id3v1tag_ok (char *filename);

void dprintf_z (char *format, ...);
int save_to_file (char *infile, char *data, int size, int mode, int limit);
double getvalf (double maxa, double porr);
double getporf (double maxa, double fatiaa);
int id3tag (char *filename, int mode, float *iglobalfloat, int *ianalized,
	    int convertmode);
int id3tagcheck (char *filename);
int mygain (uchar * buf, uint len, float factor);
char *getnetstatus (int *value);
int set_sendmessage_nwnd (int value);
extern void _VDBG_dump (void);
extern uint getval (int max, uint por);
extern uint getpor (int max, uint fatia);
extern int decode_file (char *infile, char *outfile);
int debug_rede (char *url);
int set_port (int port);
int set_passive (int pasv);
int resume_winsock ();
int pause_winsock ();
int cancel_winsock ();
int set_user (char *url);
int set_pass (char *url);
int id3tag (char *filename, int mode, float *iglobalfloat, int *ianalized,
	    int convertmode);
int set_dest_path (char *path);
int detect (char *filename, __int64 * seekpoint);
int __stdcall startapi (int parameter);


void mprintf (const char *format, ...);

unsigned int buffer_fread (void *buffer, unsigned int size,
			   unsigned int count, FILE * stream);
size_t fread_unbuffered (void *ptr, size_t size, size_t nelem, FILE * stream);
size_t fwrite_unbuffered (const void *ptr, size_t size, size_t nelem,
			  FILE * stream);
int finalizeplayer ();

int enablefilebuffersmart ();

int minbuffersize (int size);


extern int __cdecl invertbits32 (int value);
extern short __cdecl invertbits16 (short value);
extern int __cdecl createtempfilename (char *path1, char *destfile);
extern int __cdecl detect_readonly_file (char *filename);
extern int __cdecl fix_filesize (char *filename, int len);
extern void __cdecl replace_char_binary (char *temp, char init, char out,
					 int len);
extern int __cdecl rsp_get_error (char *buffer);
extern void __cdecl rsp_error_print ();
extern int __cdecl checkoverflow_minuschar2 (char a, char b, char *result);
extern int __cdecl checkoverflow_minuschar (char a, char b, char *result);
extern int __cdecl checkoverflow_pluschar (char a, char b, char *result);
extern void __cdecl mprintf (const char *format, ...);
extern int __cdecl fix8 (int value);
extern int __cdecl fix4 (int value);
extern int __cdecl fix2 (int value);
extern int __cdecl rspparser (char *instring, char *delimiter,
			      char *returnstring, int comand);
extern void __cdecl stripfilenameandpath_url (char *path, char *onlypath,
					      char *onlyfilename);
extern int __cdecl stripfilenameandpath (char *path, char *onlypath,
					 char *onlyfilename);
extern int __cdecl octaltoint (char *p);
extern char *__cdecl inttooctal (unsigned int value, int numberofitens);
static int __cdecl getbits (unsigned int value, unsigned int bit);
extern int __cdecl setbits (unsigned int value, unsigned int bit,
			    unsigned int bitvalue);
extern int __cdecl newsetbits (unsigned int value, unsigned int bit,
			       unsigned int bitvalue);
extern unsigned int __cdecl binarioparadecimal (char *binval);
extern char *__cdecl decimalparabinarioprintf (unsigned int value);
extern char *__cdecl decimalparabinario (unsigned int value);
extern char *__cdecl decimalparabinarioold (unsigned int value);
extern char __cdecl pegaultimocaracter (char *path);
extern double __cdecl inittimer2 (int value);
extern float __cdecl inittimer (unsigned int comando);
extern int __cdecl rspgetdrivetype (char *path1);
extern char *__cdecl rspgetcomputername ();
extern int __cdecl rspsetcurrentdirectory (char *path);
extern char *__cdecl rspgetcurrentdirectory ();
extern char *__cdecl rspgetsystemdirectory ();
extern char *__cdecl rspgetwindowsdirectory ();
extern char *__cdecl rspgettemppath ();
extern int __cdecl save_to_file (char *infile, char *data, int size, int mode,
				 int limit);
extern int __cdecl getfilesize (char *infile);
extern unsigned int __cdecl getval (int max, unsigned int por);
extern double __cdecl getvalf (double maxa, double porr);
extern unsigned int __cdecl getmax (int por, unsigned int fatia);
extern unsigned int __cdecl getpor (int max, unsigned int fatia);
extern double __cdecl getporf (double maxa, double fatiaa);
extern int __cdecl contastringinsensitive (char *comando, char *string);
extern int __cdecl contastringsensitive (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive_new (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal_new (char *comando,
						  char *string);
extern int __cdecl procuradordestringsensitive (char *comando, char *string);
extern int __cdecl procuradordestringinsensitive (char *comando,
						  char *string);
extern int __cdecl checkmaxsize (char *comando);
extern void __cdecl stripchar (char *intcomando, char caracter);
extern void __cdecl stripspace (char *intcomando);
extern void __cdecl trocadordebackslashtras (char *path);
extern void __cdecl trocadordebackslashfrente (char *path);
extern void __cdecl adicionadordebackslashtras (char *path);
extern void __cdecl adicionadordebackslashfrente (char *path);
extern void __cdecl removedordeespaconofinal (char *path);
extern void __cdecl removedordecaracternofinal (char *path, char caracter);
extern void __cdecl removedordecaracternoinicio (char *path, char caracter);
extern void __cdecl removedordeespaconoinicio (char *path);
extern void __cdecl changecharacter (char *path, char itemtosearch,
				     char finalcharacter);
extern int __cdecl countitens (char *comand, char item);
extern void __cdecl strtolower (char *path);
extern void __cdecl strtoupper (char *path);
extern int __cdecl testdirectory (char *path);
extern int __cdecl createtestfilename (char *path1);
extern int __cdecl pathexists (char *path);
extern int __cdecl pathappearsvalid (char *path);
extern int __cdecl ispathreadonly (char *path);
extern int __cdecl ispathfolder (char *path);
extern int __cdecl ispathfile (char *path);
extern void __cdecl geterrorstringrspmakedir (int errorcode, char *path);
extern int __cdecl rspmakedirUNIX (char *destination, char *path);
extern int __cdecl rspmakedir (char *path);
extern char *__cdecl validanomedearquivoerrorstring ();
extern int __cdecl validanomedearquivo (char *path);
extern char *__cdecl validatefoldertocreateerrorstring ();
extern int __cdecl validatefoldertocreate (char *path);
extern int __cdecl rspposicaofixa (int mode, int value);
extern int __cdecl wildcardselection (const char *path, const char *string1);
extern void __cdecl sgenrand (unsigned long seed);
extern int __cdecl genrand ();

int configequalizer (int b60, int b170, int b310, int b600, int b1000,
		     int b3000, int b6000, int b12000, int b14000,
		     int b16000);

int setvolume (int newvalue);


int v2cleanup ();

int configequalizer2 (int b60, int b170, int b310, int b600, int b1000,
		      int b3000, int b6000, int b12000, int b14000,
		      int b16000);


int isclosed ();

extern int mad_mp3_is_valid;


WCHAR *__stdcall utf8towide (const char *pUTF8);

int reinitplayer ();

FILE *buffer_fopen (const char *filename, const char *mode);

long buffer_ftell (FILE * stream);


int buffer_fseek (FILE * stream, long offset, int origin);


int buffer_fclose (FILE * stream);

int ispathfile (char *path);

int enablefilebuffer ();

int disablefilebuffer ();


void sgenrand (unsigned long seed);
int genrand ();


int ispathfolder (char *path);

double inittimer2 (int value);

int decode_mad_MP3 (char *, int, char *, int, int *, int *);
int Init_mad_MP3 (void);
int Exit_mad_MP3 (void);

char out[100000];

extern int madsamplerate;
extern int madlayer;
extern int madchannel;
extern char madmode[];
extern int madsample_per_frame;
extern int madbitrate;

int get_data (char *filename, int *samplerate_, int *channel_);

void
convertmp3towav_extended (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename, char *outname, int wav_mode, int track)
;

int
convertmp3towav (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename, char *outname, int wav_mode, int track)
;

void
convertmp3towav_extended (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename, char *outname, int wav_mode,
			              int track)
{
  morcego_extract_wav_extended (mv_______,filename, outname, wav_mode, track);
  return;
}

int
convertmp3towav (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename, char *outname, int wav_mode, int track)
{

  return morcego_extract_wav (mv_______,filename, outname, wav_mode, track);

}
