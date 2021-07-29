//It came from a XMMS plugin, thanks Linux guys...
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
 */

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

#include    <windows.h>
#include      <stdio.h>
#include       <math.h>
#include     <limits.h>
#include       <time.h>

#undef           NDEBUG

#include     <assert.h>
#include     <string.h>
#include   <mmsystem.h>
#include     <stdlib.h>

#include       <time.h>

#include "mv_from_be.h"

#if 0
#pragma warning( disable : 1969 )
#pragma warning( disable : 1993 )
#pragma warning( disable : 2021 )
#endif

double
inittimer2 (int value);

int id3v2tag_check (char *filename);

__int64 id3v2tag (char *filename);

int rewrite_header (FILE * out, unsigned int written);

int write_prelim_header (FILE * out, int channels, int samplerate);

int detect (char *filename, __int64 * seekpoint);

void rfree (void *add);
void *rmalloc (int size);

int remove_id3v2_tag (char *filename);


int id3v2tag_ok_write (char *filename);

int id3v2tag_ok (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename);

short invertbits16 (short value);

int invertbits32 (int value);

extern const char *const ID3v1_genre[];

int remove_id3v1_tag (char *filename);

int id3v1tag_ok_write (char *filename);

int id3v1tag_ok (char *filename);

void dprintf_z (const char *format, ...);
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

extern void __cdecl init_iir ();

int convertmp3towav (char *filename, char *outname);

int configequalizer (morcego___i___instance__a__bucaneiro_engineering *mv_______,int b60, int b170, int b310, int b600, int b1000,
                     int b3000, int b6000, int b12000, int b14000,
                     int b16000);

int setvolume (int newvalue);

int v2cleanup ();

int configequalizer2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,int b60, int b170, int b310, int b600, int b1000,
                      int b3000, int b6000, int b12000, int b14000,
                      int b16000);

int isclosed (void);

int reinitplayer (void);

FILE *buffer_fopen (const char *filename, const char *mode);

long buffer_ftell (FILE * stream);

int buffer_fseek (FILE * stream, long offset, int origin);

int buffer_fclose (FILE * stream);

int ispathfile (char *path);

int enablefilebuffer (void);

int disablefilebuffer (void);

void sgenrand (unsigned long seed);

int  genrand  (void);

int ispathfolder (char *path);

int id3v2tag_ok (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename);

double inittimer2 (int value);

void eq_read_config (void);
void eq_write_config (void);
void eq_configuration_window (void);

int iir_fixed (char *d, int length);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////2021 z

extern int rnd_k_p
(
	int ar_min,
	int ar_max
);

//static unsigned long mt[624];
//static int mti = 624 + 1;
/*
   static void
   sgenrand (unsigned long seed)
   {

        mt[0] = seed & 0xffffffff;
        for (mti = 1; mti < 624; mti++)
                mt[mti] = (69069 * mt[mti - 1]) & 0xffffffff;
   }

   static int
   genrand()
   {
        unsigned long y;
        static unsigned long mag01[2] = { 0x0, 0x9908b0df };

        if (mti >= 624)
        {
                int kk;
                if (mti == 624 + 1)
                        sgenrand (4357);
                for (kk = 0; kk < 624 - 397; kk++)
                {
                        y = (mt[kk] & 0x80000000) | (mt[kk + 1] & 0x7fffffff);
                        mt[kk] = mt[kk + 397] ^ (y >> 1) ^ mag01[y & 0x1];
                }
                for (; kk < 624 - 1; kk++)
                {
                        y = (mt[kk] & 0x80000000) | (mt[kk + 1] & 0x7fffffff);
                        mt[kk] = mt[kk + (397 - 624)] ^ (y >> 1) ^ mag01[y & 0x1];
                }
                y = (mt[624 - 1] & 0x80000000) | (mt[0] & 0x7fffffff);
                mt[624 - 1] = mt[397 - 1] ^ (y >> 1) ^ mag01[y & 0x1];
                mti = 0;
        }

        y = mt[mti++];
        y ^= (y >> 11);
        y ^= (y << 7) & 0x9d2c5680;
        y ^= (y << 15) & 0xefc60000;
        y ^= (y >> 18);

        return (int) y;
   }
 */
///randomic number generator, ar_min the min value inclusive, ar_max the max value inclusive
int rnd_k_p
(
	int ar_min,
	int ar_max
)
{
	int pos_k_p;
	int range_k_p;
	static int ar_already_k_p = 0;

	if(0 == ar_already_k_p)
	{
		sgenrand(GetTickCount());
		ar_already_k_p = 1;
	}

	range_k_p = ar_max - ar_min;

	pos_k_p = abs(genrand() % (range_k_p + 1));

	return pos_k_p + ar_min;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////2021 z

const sIIRCoefficients iir_cforiginal10_48000[] = {
	/*
	 * 60 Hz
	 */
	{9.9446178985e-01, 2.7691050731e-03, 1.9944002760e+00},
	/*
	 * 170 Hz
	 */
	{9.8438794122e-01, 7.8060293913e-03, 1.9838966333e+00},
	/*
	 * 310 Hz
	 */
	{9.7171413384e-01, 1.4142933081e-02, 1.9700909975e+00},
	/*
	 * 600 Hz
	 */
	{9.4597793866e-01, 2.7011030668e-02, 1.9399791381e+00},
	/*
	 * 1k Hz
	 */
	{9.1159452679e-01, 4.4202736607e-02, 1.8952405706e+00},
	/*
	 * 3k Hz
	 */
	{7.5755317065e-01, 1.2122341468e-01, 1.6237674017e+00},
	/*
	 * 6k Hz
	 */
	{5.7422402554e-01, 2.1288798723e-01, 1.1131444836e+00},
	/*
	 * 12k Hz
	 */
	{3.3730698905e-01, 3.3134650547e-01, 8.1883731790e-17},
	/*
	 * 14k Hz
	 */
	{2.8947322018e-01, 3.5526338991e-01, -3.3374022753e-01},
	/*
	 * 16k Hz
	 */
	{2.5620076154e-01, 3.7189961923e-01, -6.2810038077e-01},
};

const sIIRCoefficients iir_cforiginal10[] = {
	{(9.9421504945e-01), (2.8924752745e-03), (1.9941421835e+00)}, /* 60.0
	                                                               * Hz
	                                                               */
	{(9.8335039428e-01), (8.3248028618e-03), (1.9827686547e+00)}, /* 170.0
	                                                               * Hz
	                                                               */
	{(9.6958094144e-01), (1.5209529281e-02), (1.9676601546e+00)}, /* 310.0
	                                                               * Hz
	                                                               */
	{(9.4163923306e-01), (2.9180383468e-02), (1.9345490229e+00)}, /* 600.0
	                                                               * Hz
	                                                               */
	{(9.0450844499e-01), (4.7745777504e-02), (1.8852109613e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(7.3940088234e-01), (1.3029955883e-01), (1.5829158753e+00)}, /* 3000.0
	                                                               * Hz
	                                                               */
	{(5.4697667908e-01), (2.2651166046e-01), (1.0153238114e+00)}, /* 6000.0
	                                                               * Hz
	                                                               */
	{(3.1023210589e-01), (3.4488394706e-01), (-1.8142472036e-01)},  /* 12000.0
	                                                                 * Hz
	                                                                 */
	{(2.6718639778e-01), (3.6640680111e-01), (-5.2117742267e-01)},  /* 14000.0
	                                                                 * Hz
	                                                                 */
	{(2.4201241845e-01), (3.7899379077e-01), (-8.0847117831e-01)},  /* 16000.0
	                                                                 * Hz
	                                                                 */
};
const sIIRCoefficients iir_cf06[] = {
	{(9.9693837499e-01), (1.5308125034e-03), (1.9969176203e+00)}, /* 32.0
	                                                               * Hz
	                                                               */
	{(9.9009811471e-01), (4.9509426466e-03), (1.9898961294e+00)}, /* 100.0
	                                                               * Hz
	                                                               */
	{(9.6857535579e-01), (1.5712322103e-02), (1.9665297152e+00)}, /* 320.0
	                                                               * Hz
	                                                               */
	{(9.0450844499e-01), (4.7745777504e-02), (1.8852109613e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(7.2452798294e-01), (1.3773600853e-01), (1.5483763047e+00)}, /* 3200.0
	                                                               * Hz
	                                                               */
	{(3.7049610497e-01), (3.1475194751e-01), (1.9943351760e-01)}, /* 10000.0
	                                                               * Hz
	                                                               */
};
const sIIRCoefficients iir_cf08[] = {
	{(9.9762032228e-01), (1.1898388608e-03), (1.9976076503e+00)}, /* 25.0
	                                                               * Hz
	                                                               */
	{(9.9386394662e-01), (3.0680266887e-03), (1.9937836261e+00)}, /* 63.0
	                                                               * Hz
	                                                               */
	{(9.8437109822e-01), (7.8144508904e-03), (1.9838555176e+00)}, /* 160.0
	                                                               * Hz
	                                                               */
	{(9.6056748346e-01), (1.9716258268e-02), (1.9573844823e+00)}, /* 400.0
	                                                               * Hz
	                                                               */
	{(9.0450844499e-01), (4.7745777504e-02), (1.8852109613e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(7.7743720202e-01), (1.1128139899e-01), (1.6658715870e+00)}, /* 2500.0
	                                                               * Hz
	                                                               */
	{(5.3080791165e-01), (2.3459604417e-01), (9.5444312152e-01)}, /* 6300.0
	                                                               * Hz
	                                                               */
	{(2.4201241845e-01), (3.7899379077e-01), (-8.0847117831e-01)},  /* 16000.0
	                                                                 * Hz
	                                                                 */
};
const sIIRCoefficients iir_cf10[] = {
	{(9.9723137967e-01), (1.3843101653e-03), (1.9972115835e+00)}, /* 31.2
	                                                               * Hz
	                                                               */
	{(9.9406142155e-01), (2.9692892229e-03), (1.9939823631e+00)}, /* 62.5
	                                                               * Hz
	                                                               */
	{(9.8774277725e-01), (6.1286113769e-03), (1.9874275518e+00)}, /* 125.0
	                                                               * Hz
	                                                               */
	{(9.7522112569e-01), (1.2389437156e-02), (1.9739682661e+00)}, /* 250.0
	                                                               * Hz
	                                                               */
	{(9.5105628526e-01), (2.4471857368e-02), (1.9461077269e+00)}, /* 500.0
	                                                               * Hz
	                                                               */
	{(9.0450844499e-01), (4.7745777504e-02), (1.8852109613e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(8.1778971701e-01), (9.1105141497e-02), (1.7444877599e+00)}, /* 2000.0
	                                                               * Hz
	                                                               */
	{(6.6857185264e-01), (1.6571407368e-01), (1.4048592171e+00)}, /* 4000.0
	                                                               * Hz
	                                                               */
	{(4.4861333678e-01), (2.7569333161e-01), (6.0518718075e-01)}, /* 8000.0
	                                                               * Hz
	                                                               */
	{(2.4201241845e-01), (3.7899379077e-01), (-8.0847117831e-01)},  /* 16000.0
	                                                                 * Hz
	                                                                 */
};
const sIIRCoefficients iir_cf15[] = {
	{(9.9839842874e-01), (8.0078563214e-04), (1.9983857518e+00)}, /* 25.0
	                                                               * Hz
	                                                               */
	{(9.9743872469e-01), (1.2806376567e-03), (1.9974062874e+00)}, /* 40.0
	                                                               * Hz
	                                                               */
	{(9.9618559339e-01), (1.9072033053e-03), (1.9961051794e+00)}, /* 63.0
	                                                               * Hz
	                                                               */
	{(9.9360911251e-01), (3.1954437471e-03), (1.9934067709e+00)}, /* 100.0
	                                                               * Hz
	                                                               */
	{(9.8943120761e-01), (5.2843961958e-03), (1.9889143122e+00)}, /* 160.0
	                                                               * Hz
	                                                               */
	{(9.8373917895e-01), (8.1304105232e-03), (1.9824809165e+00)}, /* 250.0
	                                                               * Hz
	                                                               */
	{(9.7396730354e-01), (1.3016348231e-02), (1.9707625477e+00)}, /* 400.0
	                                                               * Hz
	                                                               */
	{(9.5936190809e-01), (2.0319045955e-02), (1.9514740931e+00)}, /* 630.0
	                                                               * Hz
	                                                               */
	{(9.3585232618e-01), (3.2073836908e-02), (1.9162372498e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(8.9926254577e-01), (5.0368727115e-02), (1.8501269767e+00)}, /* 1600.0
	                                                               * Hz
	                                                               */
	{(8.4745835906e-01), (7.6270820471e-02), (1.7314976782e+00)}, /* 2500.0
	                                                               * Hz
	                                                               */
	{(7.6761067720e-01), (1.1619466140e-01), (1.4882452608e+00)}, /* 4000.0
	                                                               * Hz
	                                                               */
	{(6.6142065199e-01), (1.6928967400e-01), (1.0358788331e+00)}, /* 6300.0
	                                                               * Hz
	                                                               */
	{(5.2702198924e-01), (2.3648900538e-01), (2.2221104143e-01)}, /* 10000.0
	                                                               * Hz
	                                                               */
	{(4.0189560481e-01), (2.9905219759e-01), (-9.1254497511e-01)},  /* 16000.0
	                                                                 * Hz
	                                                                 */
};
const sIIRCoefficients iir_cf21[] = {
	{(9.9940181485e-01), (2.9909257686e-04), (1.9993919929e+00)}, /* 22.0
	                                                               * Hz
	                                                               */
	{(9.9910132425e-01), (4.4933787259e-04), (1.9990805471e+00)}, /* 32.0
	                                                               * Hz
	                                                               */
	{(9.9880392148e-01), (5.9803926123e-04), (1.9987646455e+00)}, /* 44.0
	                                                               * Hz
	                                                               */
	{(9.9820192714e-01), (8.9903643123e-04), (1.9981214319e+00)}, /* 63.0
	                                                               * Hz
	                                                               */
	{(9.9729662470e-01), (1.3516876483e-03), (1.9971324243e+00)}, /* 90.0
	                                                               * Hz
	                                                               */
	{(9.9608832771e-01), (1.9558361473e-03), (1.9957717788e+00)}, /* 125.0
	                                                               * Hz
	                                                               */
	{(9.9427272282e-01), (2.8636385908e-03), (1.9936528670e+00)}, /* 175.0
	                                                               * Hz
	                                                               */
	{(9.9187386982e-01), (4.0630650882e-03), (1.9906104476e+00)}, /* 250.0
	                                                               * Hz
	                                                               */
	{(9.8857851601e-01), (5.7107419938e-03), (1.9861065563e+00)}, /* 350.0
	                                                               * Hz
	                                                               */
	{(9.8381454728e-01), (8.0927263624e-03), (1.9787829025e+00)}, /* 500.0
	                                                               * Hz
	                                                               */
	{(9.7728961008e-01), (1.1355194958e-02), (1.9674640138e+00)}, /* 700.0
	                                                               * Hz
	                                                               */
	{(9.6758591875e-01), (1.6207040627e-02), (1.9476493009e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(9.5511166560e-01), (2.2444167198e-02), (1.9163466653e+00)}, /* 1400.0
	                                                               * Hz
	                                                               */
	{(9.3627068388e-01), (3.1864658062e-02), (1.8581910087e+00)}, /* 2000.0
	                                                               * Hz
	                                                               */
	{(9.1207457907e-01), (4.3962710466e-02), (1.7619312399e+00)}, /* 2800.0
	                                                               * Hz
	                                                               */
	{(8.7697241507e-01), (6.1513792463e-02), (1.5803227133e+00)}, /* 4000.0
	                                                               * Hz
	                                                               */
	{(8.3287214622e-01), (8.3563926889e-02), (1.2797788153e+00)}, /* 5600.0
	                                                               * Hz
	                                                               */
	{(7.7194867684e-01), (1.1402566158e-01), (7.4026698287e-01)}, /* 8000.0
	                                                               * Hz
	                                                               */
	{(7.0545126633e-01), (1.4727436684e-01), (6.0746279366e-03)}, /* 11000.0
	                                                               * Hz
	                                                               */
	{(6.2492532874e-01), (1.8753733563e-01), (-1.0577231561e+00)},  /* 16000.0
	                                                                 * Hz
	                                                                 */
	{(7.0031477414e-01), (1.4984261293e-01), (-1.7002716302e+00)},  /* 22000.0
	                                                                 * Hz
	                                                                 */
};
const sIIRCoefficients iir_cf25[] = {
	{(9.9940551149e-01), (2.9724425274e-04), (1.9993928282e+00)}, /* 25.0
	                                                               * Hz
	                                                               */
	{(9.9925718616e-01), (3.7140692231e-04), (1.9992370516e+00)}, /* 31.5
	                                                               * Hz
	                                                               */
	{(9.9879758671e-01), (6.0120664727e-04), (1.9987651273e+00)}, /* 40.0
	                                                               * Hz
	                                                               */
	{(9.9849722245e-01), (7.5138877401e-04), (1.9984465124e+00)}, /* 50.0
	                                                               * Hz
	                                                               */
	{(9.9759663784e-01), (1.2016810790e-03), (1.9974668794e+00)}, /* 80.0
	                                                               * Hz
	                                                               */
	{(9.9699670283e-01), (1.5016485839e-03), (1.9967940174e+00)}, /* 100.0
	                                                               * Hz
	                                                               */
	{(9.9608832771e-01), (1.9558361473e-03), (1.9957717788e+00)}, /* 125.0
	                                                               * Hz
	                                                               */
	{(9.9488106021e-01), (2.5594698955e-03), (1.9943627488e+00)}, /* 160.0
	                                                               * Hz
	                                                               */
	{(9.9187386982e-01), (4.0630650882e-03), (1.9906104476e+00)}, /* 250.0
	                                                               * Hz
	                                                               */
	{(9.8977837468e-01), (5.1108126620e-03), (1.9877748003e+00)}, /* 315.0
	                                                               * Hz
	                                                               */
	{(9.8709369779e-01), (6.4531511061e-03), (1.9838676311e+00)}, /* 400.0
	                                                               * Hz
	                                                               */
	{(9.8381454728e-01), (8.0927263624e-03), (1.9787829025e+00)}, /* 500.0
	                                                               * Hz
	                                                               */
	{(9.7404386878e-01), (1.2978065611e-02), (1.9612347544e+00)}, /* 800.0
	                                                               * Hz
	                                                               */
	{(9.6758591875e-01), (1.6207040627e-02), (1.9476493009e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(9.5973086514e-01), (2.0134567431e-02), (1.9287337831e+00)}, /* 1250.0
	                                                               * Hz
	                                                               */
	{(9.4878629133e-01), (2.5606854334e-02), (1.8983695001e+00)}, /* 1600.0
	                                                               * Hz
	                                                               */
	{(9.2117604381e-01), (3.9411978094e-02), (1.8005882747e+00)}, /* 2500.0
	                                                               * Hz
	                                                               */
	{(9.0172987031e-01), (4.9135064847e-02), (1.7133994083e+00)}, /* 3150.0
	                                                               * Hz
	                                                               */
	{(8.7697241507e-01), (6.1513792463e-02), (1.5803227133e+00)}, /* 4000.0
	                                                               * Hz
	                                                               */
	{(8.4900435915e-01), (7.5497820425e-02), (1.3993428287e+00)}, /* 5000.0
	                                                               * Hz
	                                                               */
	{(7.7194867684e-01), (1.1402566158e-01), (7.4026698287e-01)}, /* 8000.0
	                                                               * Hz
	                                                               */
	{(7.2627335006e-01), (1.3686332497e-01), (2.5120594308e-01)}, /* 10000.0
	                                                               * Hz
	                                                               */
	{(6.7690084582e-01), (1.6154957709e-01), (-3.4981568641e-01)},  /* 12500.0
	                                                                 * Hz
	                                                                 */
	{(6.2492532874e-01), (1.8753733563e-01), (-1.0577231561e+00)},  /* 16000.0
	                                                                 * Hz
	                                                                 */
	{(6.1776462189e-01), (1.9111768906e-01), (-1.5492495659e+00)},  /* 20000.0
	                                                                 * Hz
	                                                                 */
};
const sIIRCoefficients iir_cf31[] = {
	{(9.9939854113e-01), (3.0072943419e-04), (1.9993904238e+00)}, /* 20.0
	                                                               * Hz
	                                                               */
	{(9.9940551149e-01), (2.9724425274e-04), (1.9993928282e+00)}, /* 25.0
	                                                               * Hz
	                                                               */
	{(9.9925718616e-01), (3.7140692231e-04), (1.9992370516e+00)}, /* 31.5
	                                                               * Hz
	                                                               */
	{(9.9879758671e-01), (6.0120664727e-04), (1.9987651273e+00)}, /* 40.0
	                                                               * Hz
	                                                               */
	{(9.9849722245e-01), (7.5138877401e-04), (1.9984465124e+00)}, /* 50.0
	                                                               * Hz
	                                                               */
	{(9.9820192714e-01), (8.9903643123e-04), (1.9981214319e+00)}, /* 63.0
	                                                               * Hz
	                                                               */
	{(9.9759663784e-01), (1.2016810790e-03), (1.9974668794e+00)}, /* 80.0
	                                                               * Hz
	                                                               */
	{(9.9699670283e-01), (1.5016485839e-03), (1.9967940174e+00)}, /* 100.0
	                                                               * Hz
	                                                               */
	{(9.9608832771e-01), (1.9558361473e-03), (1.9957717788e+00)}, /* 125.0
	                                                               * Hz
	                                                               */
	{(9.9488106021e-01), (2.5594698955e-03), (1.9943627488e+00)}, /* 160.0
	                                                               * Hz
	                                                               */
	{(9.9368508558e-01), (3.1574572116e-03), (1.9928757293e+00)}, /* 200.0
	                                                               * Hz
	                                                               */
	{(9.9187386982e-01), (4.0630650882e-03), (1.9906104476e+00)}, /* 250.0
	                                                               * Hz
	                                                               */
	{(9.8977837468e-01), (5.1108126620e-03), (1.9877748003e+00)}, /* 315.0
	                                                               * Hz
	                                                               */
	{(9.8709369779e-01), (6.4531511061e-03), (1.9838676311e+00)}, /* 400.0
	                                                               * Hz
	                                                               */
	{(9.8381454728e-01), (8.0927263624e-03), (1.9787829025e+00)}, /* 500.0
	                                                               * Hz
	                                                               */
	{(9.7966277109e-01), (1.0168614455e-02), (1.9716932308e+00)}, /* 630.0
	                                                               * Hz
	                                                               */
	{(9.7404386878e-01), (1.2978065611e-02), (1.9612347544e+00)}, /* 800.0
	                                                               * Hz
	                                                               */
	{(9.6758591875e-01), (1.6207040627e-02), (1.9476493009e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(9.5973086514e-01), (2.0134567431e-02), (1.9287337831e+00)}, /* 1250.0
	                                                               * Hz
	                                                               */
	{(9.4878629133e-01), (2.5606854334e-02), (1.8983695001e+00)}, /* 1600.0
	                                                               * Hz
	                                                               */
	{(9.3627068388e-01), (3.1864658062e-02), (1.8581910087e+00)}, /* 2000.0
	                                                               * Hz
	                                                               */
	{(9.2117604381e-01), (3.9411978094e-02), (1.8005882747e+00)}, /* 2500.0
	                                                               * Hz
	                                                               */
	{(9.0172987031e-01), (4.9135064847e-02), (1.7133994083e+00)}, /* 3150.0
	                                                               * Hz
	                                                               */
	{(8.7697241507e-01), (6.1513792463e-02), (1.5803227133e+00)}, /* 4000.0
	                                                               * Hz
	                                                               */
	{(8.4900435915e-01), (7.5497820425e-02), (1.3993428287e+00)}, /* 5000.0
	                                                               * Hz
	                                                               */
	{(8.1426291228e-01), (9.2868543858e-02), (1.1311744237e+00)}, /* 6300.0
	                                                               * Hz
	                                                               */
	{(7.7194867684e-01), (1.1402566158e-01), (7.4026698287e-01)}, /* 8000.0
	                                                               * Hz
	                                                               */
	{(7.2627335006e-01), (1.3686332497e-01), (2.5120594308e-01)}, /* 10000.0
	                                                               * Hz
	                                                               */
	{(6.7690084582e-01), (1.6154957709e-01), (-3.4981568641e-01)},  /* 12500.0
	                                                                 * Hz
	                                                                 */
	{(6.2492532874e-01), (1.8753733563e-01), (-1.0577231561e+00)},  /* 16000.0
	                                                                 * Hz
	                                                                 */
	{(6.1776462189e-01), (1.9111768906e-01), (-1.5492495659e+00)},  /* 20000.0
	                                                                 * Hz
	                                                                 */
};
const sIIRCoefficients iir_cf61[] = {
	{(9.9970758256e-01), (1.4620872211e-04), (1.9996994640e+00)}, /* 20.0
	                                                               * Hz
	                                                               */
	{(9.9985578506e-01), (7.2107470718e-05), (1.9998455093e+00)}, /* 22.5
	                                                               * Hz
	                                                               */
	{(9.9970916246e-01), (1.4541876821e-04), (1.9996964772e+00)}, /* 25.0
	                                                               * Hz
	                                                               */
	{(9.9970974706e-01), (1.4512646968e-04), (1.9996938347e+00)}, /* 28.0
	                                                               * Hz
	                                                               */
	{(9.9956195197e-01), (2.1902401550e-04), (1.9995418144e+00)}, /* 31.5
	                                                               * Hz
	                                                               */
	{(9.9956323912e-01), (2.1838043958e-04), (1.9995376625e+00)}, /* 35.5
	                                                               * Hz
	                                                               */
	{(9.9941528111e-01), (2.9235944262e-04), (1.9993828117e+00)}, /* 40.0
	                                                               * Hz
	                                                               */
	{(9.9941702000e-01), (2.9149000195e-04), (1.9993759259e+00)}, /* 45.0
	                                                               * Hz
	                                                               */
	{(9.9941840589e-01), (2.9079705642e-04), (1.9993676724e+00)}, /* 50.0
	                                                               * Hz
	                                                               */
	{(9.9912133864e-01), (4.3933067805e-04), (1.9990577081e+00)}, /* 56.0
	                                                               * Hz
	                                                               */
	{(9.9912416011e-01), (4.3791994443e-04), (1.9990436277e+00)}, /* 63.0
	                                                               * Hz
	                                                               */
	{(9.9912667284e-01), (4.3666358222e-04), (1.9990243893e+00)}, /* 71.0
	                                                               * Hz
	                                                               */
	{(9.9883088292e-01), (5.8455853918e-04), (1.9987010443e+00)}, /* 80.0
	                                                               * Hz
	                                                               */
	{(9.9853441282e-01), (7.3279359110e-04), (1.9983701107e+00)}, /* 90.0
	                                                               * Hz
	                                                               */
	{(9.9853881883e-01), (7.3059058733e-04), (1.9983359769e+00)}, /* 100.0
	                                                               * Hz
	                                                               */
	{(9.9824344910e-01), (8.7827545162e-04), (1.9979890428e+00)}, /* 112.0
	                                                               * Hz
	                                                               */
	{(9.9794828716e-01), (1.0258564207e-03), (1.9976314433e+00)}, /* 125.0
	                                                               * Hz
	                                                               */
	{(9.9795494674e-01), (1.0225266292e-03), (1.9975574991e+00)}, /* 140.0
	                                                               * Hz
	                                                               */
	{(9.9766313972e-01), (1.1684301378e-03), (1.9971441055e+00)}, /* 160.0
	                                                               * Hz
	                                                               */
	{(9.9707098665e-01), (1.4645066748e-03), (1.9964142863e+00)}, /* 180.0
	                                                               * Hz
	                                                               */
	{(9.9677953383e-01), (1.6102330867e-03), (1.9959689214e+00)}, /* 200.0
	                                                               * Hz
	                                                               */
	{(9.9649045824e-01), (1.7547708806e-03), (1.9954646938e+00)}, /* 225.0
	                                                               * Hz
	                                                               */
	{(9.9590081477e-01), (2.0495926154e-03), (1.9946348383e+00)}, /* 250.0
	                                                               * Hz
	                                                               */
	{(9.9561445263e-01), (2.1927736848e-03), (1.9940266824e+00)}, /* 280.0
	                                                               * Hz
	                                                               */
	{(9.9503011643e-01), (2.4849417865e-03), (1.9930212539e+00)}, /* 315.0
	                                                               * Hz
	                                                               */
	{(9.9444841728e-01), (2.7757913578e-03), (1.9918978341e+00)}, /* 355.0
	                                                               * Hz
	                                                               */
	{(9.9356956164e-01), (3.2152191777e-03), (1.9903329813e+00)}, /* 400.0
	                                                               * Hz
	                                                               */
	{(9.9269374379e-01), (3.6531281033e-03), (1.9885995408e+00)}, /* 450.0
	                                                               * Hz
	                                                               */
	{(9.9181867998e-01), (4.0906600101e-03), (1.9867667340e+00)}, /* 500.0
	                                                               * Hz
	                                                               */
	{(9.9094933309e-01), (4.5253334541e-03), (1.9846156195e+00)}, /* 560.0
	                                                               * Hz
	                                                               */
	{(9.8978652753e-01), (5.1067362368e-03), (1.9817762320e+00)}, /* 630.0
	                                                               * Hz
	                                                               */
	{(9.8862997453e-01), (5.6850127338e-03), (1.9784639099e+00)}, /* 710.0
	                                                               * Hz
	                                                               */
	{(9.8718144876e-01), (6.4092756212e-03), (1.9742870877e+00)}, /* 800.0
	                                                               * Hz
	                                                               */
	{(9.8544228107e-01), (7.2788594669e-03), (1.9691418274e+00)}, /* 900.0
	                                                               * Hz
	                                                               */
	{(9.8370625693e-01), (8.1468715334e-03), (1.9636062993e+00)}, /* 1000.0
	                                                               * Hz
	                                                               */
	{(9.8198327673e-01), (9.0083616337e-03), (1.9568026322e+00)}, /* 1120.0
	                                                               * Hz
	                                                               */
	{(9.7967630961e-01), (1.0161845197e-02), (1.9483637503e+00)}, /* 1250.0
	                                                               * Hz
	                                                               */
	{(9.7738495679e-01), (1.1307521606e-02), (1.9381783325e+00)}, /* 1400.0
	                                                               * Hz
	                                                               */
	{(9.7424076862e-01), (1.2879615689e-02), (1.9231654479e+00)}, /* 1600.0
	                                                               * Hz
	                                                               */
	{(9.7081442264e-01), (1.4592788680e-02), (1.9063586670e+00)}, /* 1800.0
	                                                               * Hz
	                                                               */
	{(9.6769352756e-01), (1.6153236219e-02), (1.8883467334e+00)}, /* 2000.0
	                                                               * Hz
	                                                               */
	{(9.6373550234e-01), (1.8132248830e-02), (1.8636944641e+00)}, /* 2250.0
	                                                               * Hz
	                                                               */
	{(9.5979586775e-01), (2.0102066127e-02), (1.8367840217e+00)}, /* 2500.0
	                                                               * Hz
	                                                               */
	{(9.5503518908e-01), (2.2482405462e-02), (1.8015184201e+00)}, /* 2800.0
	                                                               * Hz
	                                                               */
	{(9.4975457892e-01), (2.5122710541e-02), (1.7566681757e+00)}, /* 3150.0
	                                                               * Hz
	                                                               */
	{(9.4339710021e-01), (2.8301449895e-02), (1.7000688887e+00)}, /* 3550.0
	                                                               * Hz
	                                                               */
	{(9.3655350715e-01), (3.1723246424e-02), (1.6304871975e+00)}, /* 4000.0
	                                                               * Hz
	                                                               */
	{(9.2896076477e-01), (3.5519617616e-02), (1.5458954329e+00)}, /* 4500.0
	                                                               * Hz
	                                                               */
	{(9.2144774434e-01), (3.9276127831e-02), (1.4541686224e+00)}, /* 5000.0
	                                                               * Hz
	                                                               */
	{(9.1243019708e-01), (4.3784901461e-02), (1.3353291756e+00)}, /* 5600.0
	                                                               * Hz
	                                                               */
	{(9.0224433806e-01), (4.8877830970e-02), (1.1860299454e+00)}, /* 6300.0
	                                                               * Hz
	                                                               */
	{(8.9069401952e-01), (5.4652990239e-02), (1.0030571580e+00)}, /* 7100.0
	                                                               * Hz
	                                                               */
	{(8.7787759127e-01), (6.1061204365e-02), (7.8452090451e-01)}, /* 8000.0
	                                                               * Hz
	                                                               */
	{(8.6417007188e-01), (6.7914964061e-02), (5.3040781162e-01)}, /* 9000.0
	                                                               * Hz
	                                                               */
	{(8.5086157670e-01), (7.4569211648e-02), (2.6933592404e-01)}, /* 10000.0
	                                                               * Hz
	                                                               */
	{(8.3551232648e-01), (8.2243836759e-02), (-4.5760591993e-02)},  /* 11200.0
	                                                                 * Hz
	                                                                 */
	{(8.1957491516e-01), (9.0212542420e-02), (-3.7957870288e-01)},  /* 12500.0
	                                                                 * Hz
	                                                                 */
	{(8.0245916042e-01), (9.8770419789e-02), (-7.4132820660e-01)},  /* 14000.0
	                                                                 * Hz
	                                                                 */
	{(7.8216705610e-01), (1.0891647195e-01), (-1.1600775309e+00)},  /* 16000.0
	                                                                 * Hz
	                                                                 */
	{(7.6734339569e-01), (1.1632830216e-01), (-1.4811894772e+00)},  /* 18000.0
	                                                                 * Hz
	                                                                 */
	{(7.6536059746e-01), (1.1731970127e-01), (-1.6905946033e+00)},  /* 20000.0
	                                                                 * Hz
	                                                                 */
};

const sIIRCoefficients_fixed iir_cforiginal10_fixed[] = {
	{((int) ((9.9421504945e-01) * (1 << 28))), ((int) ((2.8924752745e-03) * (1 << 28))), ((int) ((1.9941421835e+00) * (1 << 28)))}, /* 60.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8335039428e-01) * (1 << 28))), ((int) ((8.3248028618e-03) * (1 << 28))), ((int) ((1.9827686547e+00) * (1 << 28)))}, /* 170.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.6958094144e-01) * (1 << 28))), ((int) ((1.5209529281e-02) * (1 << 28))), ((int) ((1.9676601546e+00) * (1 << 28)))}, /* 310.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.4163923306e-01) * (1 << 28))), ((int) ((2.9180383468e-02) * (1 << 28))), ((int) ((1.9345490229e+00) * (1 << 28)))}, /* 600.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.0450844499e-01) * (1 << 28))), ((int) ((4.7745777504e-02) * (1 << 28))), ((int) ((1.8852109613e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.3940088234e-01) * (1 << 28))), ((int) ((1.3029955883e-01) * (1 << 28))), ((int) ((1.5829158753e+00) * (1 << 28)))}, /* 3000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((5.4697667908e-01) * (1 << 28))), ((int) ((2.2651166046e-01) * (1 << 28))), ((int) ((1.0153238114e+00) * (1 << 28)))}, /* 6000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((3.1023210589e-01) * (1 << 28))), ((int) ((3.4488394706e-01) * (1 << 28))), ((int) ((-1.8142472036e-01) * (1 << 28)))}, /* 12000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((2.6718639778e-01) * (1 << 28))), ((int) ((3.6640680111e-01) * (1 << 28))), ((int) ((-5.2117742267e-01) * (1 << 28)))}, /* 14000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((2.4201241845e-01) * (1 << 28))), ((int) ((3.7899379077e-01) * (1 << 28))), ((int) ((-8.0847117831e-01) * (1 << 28)))},
};

const sIIRCoefficients_fixed iir_cf06_fixed[] = {
	{((int) ((9.9693837499e-01) * (1 << 28))), ((int) ((1.5308125034e-03) * (1 << 28))), ((int) ((1.9969176203e+00) * (1 << 28)))}, /* 32.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9009811471e-01) * (1 << 28))), ((int) ((4.9509426466e-03) * (1 << 28))), ((int) ((1.9898961294e+00) * (1 << 28)))}, /* 100.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.6857535579e-01) * (1 << 28))), ((int) ((1.5712322103e-02) * (1 << 28))), ((int) ((1.9665297152e+00) * (1 << 28)))}, /* 320.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.0450844499e-01) * (1 << 28))), ((int) ((4.7745777504e-02) * (1 << 28))), ((int) ((1.8852109613e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.2452798294e-01) * (1 << 28))), ((int) ((1.3773600853e-01) * (1 << 28))), ((int) ((1.5483763047e+00) * (1 << 28)))}, /* 3200.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((3.7049610497e-01) * (1 << 28))), ((int) ((3.1475194751e-01) * (1 << 28))), ((int) ((1.9943351760e-01) * (1 << 28)))}, /* 10000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
};
const sIIRCoefficients_fixed iir_cf08_fixed[] = {
	{((int) ((9.9762032228e-01) * (1 << 28))), ((int) ((1.1898388608e-03) * (1 << 28))), ((int) ((1.9976076503e+00) * (1 << 28)))}, /* 25.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9386394662e-01) * (1 << 28))), ((int) ((3.0680266887e-03) * (1 << 28))), ((int) ((1.9937836261e+00) * (1 << 28)))}, /* 63.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8437109822e-01) * (1 << 28))), ((int) ((7.8144508904e-03) * (1 << 28))), ((int) ((1.9838555176e+00) * (1 << 28)))}, /* 160.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.6056748346e-01) * (1 << 28))), ((int) ((1.9716258268e-02) * (1 << 28))), ((int) ((1.9573844823e+00) * (1 << 28)))}, /* 400.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.0450844499e-01) * (1 << 28))), ((int) ((4.7745777504e-02) * (1 << 28))), ((int) ((1.8852109613e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.7743720202e-01) * (1 << 28))), ((int) ((1.1128139899e-01) * (1 << 28))), ((int) ((1.6658715870e+00) * (1 << 28)))}, /* 2500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((5.3080791165e-01) * (1 << 28))), ((int) ((2.3459604417e-01) * (1 << 28))), ((int) ((9.5444312152e-01) * (1 << 28)))}, /* 6300.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((2.4201241845e-01) * (1 << 28))), ((int) ((3.7899379077e-01) * (1 << 28))), ((int) ((-8.0847117831e-01) * (1 << 28)))}, /* 16000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
};
const sIIRCoefficients_fixed iir_cf10_fixed[] = {
	{((int) ((9.9723137967e-01) * (1 << 28))), ((int) ((1.3843101653e-03) * (1 << 28))), ((int) ((1.9972115835e+00) * (1 << 28)))}, /* 31.2
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9406142155e-01) * (1 << 28))), ((int) ((2.9692892229e-03) * (1 << 28))), ((int) ((1.9939823631e+00) * (1 << 28)))}, /* 62.5
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8774277725e-01) * (1 << 28))), ((int) ((6.1286113769e-03) * (1 << 28))), ((int) ((1.9874275518e+00) * (1 << 28)))}, /* 125.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7522112569e-01) * (1 << 28))), ((int) ((1.2389437156e-02) * (1 << 28))), ((int) ((1.9739682661e+00) * (1 << 28)))}, /* 250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.5105628526e-01) * (1 << 28))), ((int) ((2.4471857368e-02) * (1 << 28))), ((int) ((1.9461077269e+00) * (1 << 28)))}, /* 500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.0450844499e-01) * (1 << 28))), ((int) ((4.7745777504e-02) * (1 << 28))), ((int) ((1.8852109613e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.1778971701e-01) * (1 << 28))), ((int) ((9.1105141497e-02) * (1 << 28))), ((int) ((1.7444877599e+00) * (1 << 28)))}, /* 2000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((6.6857185264e-01) * (1 << 28))), ((int) ((1.6571407368e-01) * (1 << 28))), ((int) ((1.4048592171e+00) * (1 << 28)))}, /* 4000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((4.4861333678e-01) * (1 << 28))), ((int) ((2.7569333161e-01) * (1 << 28))), ((int) ((6.0518718075e-01) * (1 << 28)))}, /* 8000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((2.4201241845e-01) * (1 << 28))), ((int) ((3.7899379077e-01) * (1 << 28))), ((int) ((-8.0847117831e-01) * (1 << 28)))}, /* 16000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
};
const sIIRCoefficients_fixed iir_cf15_fixed[] = {
	{((int) ((9.9839842874e-01) * (1 << 28))), ((int) ((8.0078563214e-04) * (1 << 28))), ((int) ((1.9983857518e+00) * (1 << 28)))}, /* 25.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9743872469e-01) * (1 << 28))), ((int) ((1.2806376567e-03) * (1 << 28))), ((int) ((1.9974062874e+00) * (1 << 28)))}, /* 40.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9618559339e-01) * (1 << 28))), ((int) ((1.9072033053e-03) * (1 << 28))), ((int) ((1.9961051794e+00) * (1 << 28)))}, /* 63.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9360911251e-01) * (1 << 28))), ((int) ((3.1954437471e-03) * (1 << 28))), ((int) ((1.9934067709e+00) * (1 << 28)))}, /* 100.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8943120761e-01) * (1 << 28))), ((int) ((5.2843961958e-03) * (1 << 28))), ((int) ((1.9889143122e+00) * (1 << 28)))}, /* 160.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8373917895e-01) * (1 << 28))), ((int) ((8.1304105232e-03) * (1 << 28))), ((int) ((1.9824809165e+00) * (1 << 28)))}, /* 250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7396730354e-01) * (1 << 28))), ((int) ((1.3016348231e-02) * (1 << 28))), ((int) ((1.9707625477e+00) * (1 << 28)))}, /* 400.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.5936190809e-01) * (1 << 28))), ((int) ((2.0319045955e-02) * (1 << 28))), ((int) ((1.9514740931e+00) * (1 << 28)))}, /* 630.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.3585232618e-01) * (1 << 28))), ((int) ((3.2073836908e-02) * (1 << 28))), ((int) ((1.9162372498e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.9926254577e-01) * (1 << 28))), ((int) ((5.0368727115e-02) * (1 << 28))), ((int) ((1.8501269767e+00) * (1 << 28)))}, /* 1600.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.4745835906e-01) * (1 << 28))), ((int) ((7.6270820471e-02) * (1 << 28))), ((int) ((1.7314976782e+00) * (1 << 28)))}, /* 2500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.6761067720e-01) * (1 << 28))), ((int) ((1.1619466140e-01) * (1 << 28))), ((int) ((1.4882452608e+00) * (1 << 28)))}, /* 4000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((6.6142065199e-01) * (1 << 28))), ((int) ((1.6928967400e-01) * (1 << 28))), ((int) ((1.0358788331e+00) * (1 << 28)))}, /* 6300.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((5.2702198924e-01) * (1 << 28))), ((int) ((2.3648900538e-01) * (1 << 28))), ((int) ((2.2221104143e-01) * (1 << 28)))}, /* 10000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((4.0189560481e-01) * (1 << 28))), ((int) ((2.9905219759e-01) * (1 << 28))), ((int) ((-9.1254497511e-01) * (1 << 28)))}, /* 16000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
};
const sIIRCoefficients_fixed iir_cf21_fixed[] = {
	{((int) ((9.9940181485e-01) * (1 << 28))), ((int) ((2.9909257686e-04) * (1 << 28))), ((int) ((1.9993919929e+00) * (1 << 28)))}, /* 22.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9910132425e-01) * (1 << 28))), ((int) ((4.4933787259e-04) * (1 << 28))), ((int) ((1.9990805471e+00) * (1 << 28)))}, /* 32.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9880392148e-01) * (1 << 28))), ((int) ((5.9803926123e-04) * (1 << 28))), ((int) ((1.9987646455e+00) * (1 << 28)))}, /* 44.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9820192714e-01) * (1 << 28))), ((int) ((8.9903643123e-04) * (1 << 28))), ((int) ((1.9981214319e+00) * (1 << 28)))}, /* 63.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9729662470e-01) * (1 << 28))), ((int) ((1.3516876483e-03) * (1 << 28))), ((int) ((1.9971324243e+00) * (1 << 28)))}, /* 90.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9608832771e-01) * (1 << 28))), ((int) ((1.9558361473e-03) * (1 << 28))), ((int) ((1.9957717788e+00) * (1 << 28)))}, /* 125.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9427272282e-01) * (1 << 28))), ((int) ((2.8636385908e-03) * (1 << 28))), ((int) ((1.9936528670e+00) * (1 << 28)))}, /* 175.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9187386982e-01) * (1 << 28))), ((int) ((4.0630650882e-03) * (1 << 28))), ((int) ((1.9906104476e+00) * (1 << 28)))}, /* 250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8857851601e-01) * (1 << 28))), ((int) ((5.7107419938e-03) * (1 << 28))), ((int) ((1.9861065563e+00) * (1 << 28)))}, /* 350.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8381454728e-01) * (1 << 28))), ((int) ((8.0927263624e-03) * (1 << 28))), ((int) ((1.9787829025e+00) * (1 << 28)))}, /* 500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7728961008e-01) * (1 << 28))), ((int) ((1.1355194958e-02) * (1 << 28))), ((int) ((1.9674640138e+00) * (1 << 28)))}, /* 700.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.6758591875e-01) * (1 << 28))), ((int) ((1.6207040627e-02) * (1 << 28))), ((int) ((1.9476493009e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.5511166560e-01) * (1 << 28))), ((int) ((2.2444167198e-02) * (1 << 28))), ((int) ((1.9163466653e+00) * (1 << 28)))}, /* 1400.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.3627068388e-01) * (1 << 28))), ((int) ((3.1864658062e-02) * (1 << 28))), ((int) ((1.8581910087e+00) * (1 << 28)))}, /* 2000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.1207457907e-01) * (1 << 28))), ((int) ((4.3962710466e-02) * (1 << 28))), ((int) ((1.7619312399e+00) * (1 << 28)))}, /* 2800.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.7697241507e-01) * (1 << 28))), ((int) ((6.1513792463e-02) * (1 << 28))), ((int) ((1.5803227133e+00) * (1 << 28)))}, /* 4000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.3287214622e-01) * (1 << 28))), ((int) ((8.3563926889e-02) * (1 << 28))), ((int) ((1.2797788153e+00) * (1 << 28)))}, /* 5600.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.7194867684e-01) * (1 << 28))), ((int) ((1.1402566158e-01) * (1 << 28))), ((int) ((7.4026698287e-01) * (1 << 28)))}, /* 8000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.0545126633e-01) * (1 << 28))), ((int) ((1.4727436684e-01) * (1 << 28))), ((int) ((6.0746279366e-03) * (1 << 28)))}, /* 11000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((6.2492532874e-01) * (1 << 28))), ((int) ((1.8753733563e-01) * (1 << 28))), ((int) ((-1.0577231561e+00) * (1 << 28)))}, /* 16000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((7.0031477414e-01) * (1 << 28))), ((int) ((1.4984261293e-01) * (1 << 28))), ((int) ((-1.7002716302e+00) * (1 << 28)))}, /* 22000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
};
const sIIRCoefficients_fixed iir_cf25_fixed[] = {
	{((int) ((9.9940551149e-01) * (1 << 28))), ((int) ((2.9724425274e-04) * (1 << 28))), ((int) ((1.9993928282e+00) * (1 << 28)))}, /* 25.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9925718616e-01) * (1 << 28))), ((int) ((3.7140692231e-04) * (1 << 28))), ((int) ((1.9992370516e+00) * (1 << 28)))}, /* 31.5
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9879758671e-01) * (1 << 28))), ((int) ((6.0120664727e-04) * (1 << 28))), ((int) ((1.9987651273e+00) * (1 << 28)))}, /* 40.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9849722245e-01) * (1 << 28))), ((int) ((7.5138877401e-04) * (1 << 28))), ((int) ((1.9984465124e+00) * (1 << 28)))}, /* 50.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9759663784e-01) * (1 << 28))), ((int) ((1.2016810790e-03) * (1 << 28))), ((int) ((1.9974668794e+00) * (1 << 28)))}, /* 80.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9699670283e-01) * (1 << 28))), ((int) ((1.5016485839e-03) * (1 << 28))), ((int) ((1.9967940174e+00) * (1 << 28)))}, /* 100.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9608832771e-01) * (1 << 28))), ((int) ((1.9558361473e-03) * (1 << 28))), ((int) ((1.9957717788e+00) * (1 << 28)))}, /* 125.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9488106021e-01) * (1 << 28))), ((int) ((2.5594698955e-03) * (1 << 28))), ((int) ((1.9943627488e+00) * (1 << 28)))}, /* 160.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9187386982e-01) * (1 << 28))), ((int) ((4.0630650882e-03) * (1 << 28))), ((int) ((1.9906104476e+00) * (1 << 28)))}, /* 250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8977837468e-01) * (1 << 28))), ((int) ((5.1108126620e-03) * (1 << 28))), ((int) ((1.9877748003e+00) * (1 << 28)))}, /* 315.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8709369779e-01) * (1 << 28))), ((int) ((6.4531511061e-03) * (1 << 28))), ((int) ((1.9838676311e+00) * (1 << 28)))}, /* 400.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8381454728e-01) * (1 << 28))), ((int) ((8.0927263624e-03) * (1 << 28))), ((int) ((1.9787829025e+00) * (1 << 28)))}, /* 500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7404386878e-01) * (1 << 28))), ((int) ((1.2978065611e-02) * (1 << 28))), ((int) ((1.9612347544e+00) * (1 << 28)))}, /* 800.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.6758591875e-01) * (1 << 28))), ((int) ((1.6207040627e-02) * (1 << 28))), ((int) ((1.9476493009e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.5973086514e-01) * (1 << 28))), ((int) ((2.0134567431e-02) * (1 << 28))), ((int) ((1.9287337831e+00) * (1 << 28)))}, /* 1250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.4878629133e-01) * (1 << 28))), ((int) ((2.5606854334e-02) * (1 << 28))), ((int) ((1.8983695001e+00) * (1 << 28)))}, /* 1600.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.2117604381e-01) * (1 << 28))), ((int) ((3.9411978094e-02) * (1 << 28))), ((int) ((1.8005882747e+00) * (1 << 28)))}, /* 2500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.0172987031e-01) * (1 << 28))), ((int) ((4.9135064847e-02) * (1 << 28))), ((int) ((1.7133994083e+00) * (1 << 28)))}, /* 3150.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.7697241507e-01) * (1 << 28))), ((int) ((6.1513792463e-02) * (1 << 28))), ((int) ((1.5803227133e+00) * (1 << 28)))}, /* 4000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.4900435915e-01) * (1 << 28))), ((int) ((7.5497820425e-02) * (1 << 28))), ((int) ((1.3993428287e+00) * (1 << 28)))}, /* 5000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.7194867684e-01) * (1 << 28))), ((int) ((1.1402566158e-01) * (1 << 28))), ((int) ((7.4026698287e-01) * (1 << 28)))}, /* 8000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.2627335006e-01) * (1 << 28))), ((int) ((1.3686332497e-01) * (1 << 28))), ((int) ((2.5120594308e-01) * (1 << 28)))}, /* 10000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((6.7690084582e-01) * (1 << 28))), ((int) ((1.6154957709e-01) * (1 << 28))), ((int) ((-3.4981568641e-01) * (1 << 28)))}, /* 12500.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((6.2492532874e-01) * (1 << 28))), ((int) ((1.8753733563e-01) * (1 << 28))), ((int) ((-1.0577231561e+00) * (1 << 28)))}, /* 16000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((6.1776462189e-01) * (1 << 28))), ((int) ((1.9111768906e-01) * (1 << 28))), ((int) ((-1.5492495659e+00) * (1 << 28)))}, /* 20000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
};
const sIIRCoefficients_fixed iir_cf31_fixed[] = {
	{((int) ((9.9939854113e-01) * (1 << 28))), ((int) ((3.0072943419e-04) * (1 << 28))), ((int) ((1.9993904238e+00) * (1 << 28)))}, /* 20.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9940551149e-01) * (1 << 28))), ((int) ((2.9724425274e-04) * (1 << 28))), ((int) ((1.9993928282e+00) * (1 << 28)))}, /* 25.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9925718616e-01) * (1 << 28))), ((int) ((3.7140692231e-04) * (1 << 28))), ((int) ((1.9992370516e+00) * (1 << 28)))}, /* 31.5
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9879758671e-01) * (1 << 28))), ((int) ((6.0120664727e-04) * (1 << 28))), ((int) ((1.9987651273e+00) * (1 << 28)))}, /* 40.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9849722245e-01) * (1 << 28))), ((int) ((7.5138877401e-04) * (1 << 28))), ((int) ((1.9984465124e+00) * (1 << 28)))}, /* 50.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9820192714e-01) * (1 << 28))), ((int) ((8.9903643123e-04) * (1 << 28))), ((int) ((1.9981214319e+00) * (1 << 28)))}, /* 63.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9759663784e-01) * (1 << 28))), ((int) ((1.2016810790e-03) * (1 << 28))), ((int) ((1.9974668794e+00) * (1 << 28)))}, /* 80.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9699670283e-01) * (1 << 28))), ((int) ((1.5016485839e-03) * (1 << 28))), ((int) ((1.9967940174e+00) * (1 << 28)))}, /* 100.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9608832771e-01) * (1 << 28))), ((int) ((1.9558361473e-03) * (1 << 28))), ((int) ((1.9957717788e+00) * (1 << 28)))}, /* 125.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9488106021e-01) * (1 << 28))), ((int) ((2.5594698955e-03) * (1 << 28))), ((int) ((1.9943627488e+00) * (1 << 28)))}, /* 160.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9368508558e-01) * (1 << 28))), ((int) ((3.1574572116e-03) * (1 << 28))), ((int) ((1.9928757293e+00) * (1 << 28)))}, /* 200.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9187386982e-01) * (1 << 28))), ((int) ((4.0630650882e-03) * (1 << 28))), ((int) ((1.9906104476e+00) * (1 << 28)))}, /* 250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8977837468e-01) * (1 << 28))), ((int) ((5.1108126620e-03) * (1 << 28))), ((int) ((1.9877748003e+00) * (1 << 28)))}, /* 315.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8709369779e-01) * (1 << 28))), ((int) ((6.4531511061e-03) * (1 << 28))), ((int) ((1.9838676311e+00) * (1 << 28)))}, /* 400.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8381454728e-01) * (1 << 28))), ((int) ((8.0927263624e-03) * (1 << 28))), ((int) ((1.9787829025e+00) * (1 << 28)))}, /* 500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7966277109e-01) * (1 << 28))), ((int) ((1.0168614455e-02) * (1 << 28))), ((int) ((1.9716932308e+00) * (1 << 28)))}, /* 630.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7404386878e-01) * (1 << 28))), ((int) ((1.2978065611e-02) * (1 << 28))), ((int) ((1.9612347544e+00) * (1 << 28)))}, /* 800.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.6758591875e-01) * (1 << 28))), ((int) ((1.6207040627e-02) * (1 << 28))), ((int) ((1.9476493009e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.5973086514e-01) * (1 << 28))), ((int) ((2.0134567431e-02) * (1 << 28))), ((int) ((1.9287337831e+00) * (1 << 28)))}, /* 1250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.4878629133e-01) * (1 << 28))), ((int) ((2.5606854334e-02) * (1 << 28))), ((int) ((1.8983695001e+00) * (1 << 28)))}, /* 1600.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.3627068388e-01) * (1 << 28))), ((int) ((3.1864658062e-02) * (1 << 28))), ((int) ((1.8581910087e+00) * (1 << 28)))}, /* 2000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.2117604381e-01) * (1 << 28))), ((int) ((3.9411978094e-02) * (1 << 28))), ((int) ((1.8005882747e+00) * (1 << 28)))}, /* 2500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.0172987031e-01) * (1 << 28))), ((int) ((4.9135064847e-02) * (1 << 28))), ((int) ((1.7133994083e+00) * (1 << 28)))}, /* 3150.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.7697241507e-01) * (1 << 28))), ((int) ((6.1513792463e-02) * (1 << 28))), ((int) ((1.5803227133e+00) * (1 << 28)))}, /* 4000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.4900435915e-01) * (1 << 28))), ((int) ((7.5497820425e-02) * (1 << 28))), ((int) ((1.3993428287e+00) * (1 << 28)))}, /* 5000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.1426291228e-01) * (1 << 28))), ((int) ((9.2868543858e-02) * (1 << 28))), ((int) ((1.1311744237e+00) * (1 << 28)))}, /* 6300.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.7194867684e-01) * (1 << 28))), ((int) ((1.1402566158e-01) * (1 << 28))), ((int) ((7.4026698287e-01) * (1 << 28)))}, /* 8000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((7.2627335006e-01) * (1 << 28))), ((int) ((1.3686332497e-01) * (1 << 28))), ((int) ((2.5120594308e-01) * (1 << 28)))}, /* 10000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((6.7690084582e-01) * (1 << 28))), ((int) ((1.6154957709e-01) * (1 << 28))), ((int) ((-3.4981568641e-01) * (1 << 28)))}, /* 12500.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((6.2492532874e-01) * (1 << 28))), ((int) ((1.8753733563e-01) * (1 << 28))), ((int) ((-1.0577231561e+00) * (1 << 28)))}, /* 16000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((6.1776462189e-01) * (1 << 28))), ((int) ((1.9111768906e-01) * (1 << 28))), ((int) ((-1.5492495659e+00) * (1 << 28)))}, /* 20000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
};
const sIIRCoefficients_fixed iir_cf61_fixed[] = {
	{((int) ((9.9970758256e-01) * (1 << 28))), ((int) ((1.4620872211e-04) * (1 << 28))), ((int) ((1.9996994640e+00) * (1 << 28)))}, /* 20.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9985578506e-01) * (1 << 28))), ((int) ((7.2107470718e-05) * (1 << 28))), ((int) ((1.9998455093e+00) * (1 << 28)))}, /* 22.5
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9970916246e-01) * (1 << 28))), ((int) ((1.4541876821e-04) * (1 << 28))), ((int) ((1.9996964772e+00) * (1 << 28)))}, /* 25.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9970974706e-01) * (1 << 28))), ((int) ((1.4512646968e-04) * (1 << 28))), ((int) ((1.9996938347e+00) * (1 << 28)))}, /* 28.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9956195197e-01) * (1 << 28))), ((int) ((2.1902401550e-04) * (1 << 28))), ((int) ((1.9995418144e+00) * (1 << 28)))}, /* 31.5
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9956323912e-01) * (1 << 28))), ((int) ((2.1838043958e-04) * (1 << 28))), ((int) ((1.9995376625e+00) * (1 << 28)))}, /* 35.5
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9941528111e-01) * (1 << 28))), ((int) ((2.9235944262e-04) * (1 << 28))), ((int) ((1.9993828117e+00) * (1 << 28)))}, /* 40.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9941702000e-01) * (1 << 28))), ((int) ((2.9149000195e-04) * (1 << 28))), ((int) ((1.9993759259e+00) * (1 << 28)))}, /* 45.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9941840589e-01) * (1 << 28))), ((int) ((2.9079705642e-04) * (1 << 28))), ((int) ((1.9993676724e+00) * (1 << 28)))}, /* 50.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9912133864e-01) * (1 << 28))), ((int) ((4.3933067805e-04) * (1 << 28))), ((int) ((1.9990577081e+00) * (1 << 28)))}, /* 56.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9912416011e-01) * (1 << 28))), ((int) ((4.3791994443e-04) * (1 << 28))), ((int) ((1.9990436277e+00) * (1 << 28)))}, /* 63.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9912667284e-01) * (1 << 28))), ((int) ((4.3666358222e-04) * (1 << 28))), ((int) ((1.9990243893e+00) * (1 << 28)))}, /* 71.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9883088292e-01) * (1 << 28))), ((int) ((5.8455853918e-04) * (1 << 28))), ((int) ((1.9987010443e+00) * (1 << 28)))}, /* 80.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9853441282e-01) * (1 << 28))), ((int) ((7.3279359110e-04) * (1 << 28))), ((int) ((1.9983701107e+00) * (1 << 28)))}, /* 90.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9853881883e-01) * (1 << 28))), ((int) ((7.3059058733e-04) * (1 << 28))), ((int) ((1.9983359769e+00) * (1 << 28)))}, /* 100.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9824344910e-01) * (1 << 28))), ((int) ((8.7827545162e-04) * (1 << 28))), ((int) ((1.9979890428e+00) * (1 << 28)))}, /* 112.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9794828716e-01) * (1 << 28))), ((int) ((1.0258564207e-03) * (1 << 28))), ((int) ((1.9976314433e+00) * (1 << 28)))}, /* 125.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9795494674e-01) * (1 << 28))), ((int) ((1.0225266292e-03) * (1 << 28))), ((int) ((1.9975574991e+00) * (1 << 28)))}, /* 140.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9766313972e-01) * (1 << 28))), ((int) ((1.1684301378e-03) * (1 << 28))), ((int) ((1.9971441055e+00) * (1 << 28)))}, /* 160.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9707098665e-01) * (1 << 28))), ((int) ((1.4645066748e-03) * (1 << 28))), ((int) ((1.9964142863e+00) * (1 << 28)))}, /* 180.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9677953383e-01) * (1 << 28))), ((int) ((1.6102330867e-03) * (1 << 28))), ((int) ((1.9959689214e+00) * (1 << 28)))}, /* 200.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9649045824e-01) * (1 << 28))), ((int) ((1.7547708806e-03) * (1 << 28))), ((int) ((1.9954646938e+00) * (1 << 28)))}, /* 225.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9590081477e-01) * (1 << 28))), ((int) ((2.0495926154e-03) * (1 << 28))), ((int) ((1.9946348383e+00) * (1 << 28)))}, /* 250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9561445263e-01) * (1 << 28))), ((int) ((2.1927736848e-03) * (1 << 28))), ((int) ((1.9940266824e+00) * (1 << 28)))}, /* 280.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9503011643e-01) * (1 << 28))), ((int) ((2.4849417865e-03) * (1 << 28))), ((int) ((1.9930212539e+00) * (1 << 28)))}, /* 315.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9444841728e-01) * (1 << 28))), ((int) ((2.7757913578e-03) * (1 << 28))), ((int) ((1.9918978341e+00) * (1 << 28)))}, /* 355.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9356956164e-01) * (1 << 28))), ((int) ((3.2152191777e-03) * (1 << 28))), ((int) ((1.9903329813e+00) * (1 << 28)))}, /* 400.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9269374379e-01) * (1 << 28))), ((int) ((3.6531281033e-03) * (1 << 28))), ((int) ((1.9885995408e+00) * (1 << 28)))}, /* 450.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9181867998e-01) * (1 << 28))), ((int) ((4.0906600101e-03) * (1 << 28))), ((int) ((1.9867667340e+00) * (1 << 28)))}, /* 500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.9094933309e-01) * (1 << 28))), ((int) ((4.5253334541e-03) * (1 << 28))), ((int) ((1.9846156195e+00) * (1 << 28)))}, /* 560.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8978652753e-01) * (1 << 28))), ((int) ((5.1067362368e-03) * (1 << 28))), ((int) ((1.9817762320e+00) * (1 << 28)))}, /* 630.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8862997453e-01) * (1 << 28))), ((int) ((5.6850127338e-03) * (1 << 28))), ((int) ((1.9784639099e+00) * (1 << 28)))}, /* 710.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8718144876e-01) * (1 << 28))), ((int) ((6.4092756212e-03) * (1 << 28))), ((int) ((1.9742870877e+00) * (1 << 28)))}, /* 800.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8544228107e-01) * (1 << 28))), ((int) ((7.2788594669e-03) * (1 << 28))), ((int) ((1.9691418274e+00) * (1 << 28)))}, /* 900.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8370625693e-01) * (1 << 28))), ((int) ((8.1468715334e-03) * (1 << 28))), ((int) ((1.9636062993e+00) * (1 << 28)))}, /* 1000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.8198327673e-01) * (1 << 28))), ((int) ((9.0083616337e-03) * (1 << 28))), ((int) ((1.9568026322e+00) * (1 << 28)))}, /* 1120.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7967630961e-01) * (1 << 28))), ((int) ((1.0161845197e-02) * (1 << 28))), ((int) ((1.9483637503e+00) * (1 << 28)))}, /* 1250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7738495679e-01) * (1 << 28))), ((int) ((1.1307521606e-02) * (1 << 28))), ((int) ((1.9381783325e+00) * (1 << 28)))}, /* 1400.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7424076862e-01) * (1 << 28))), ((int) ((1.2879615689e-02) * (1 << 28))), ((int) ((1.9231654479e+00) * (1 << 28)))}, /* 1600.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.7081442264e-01) * (1 << 28))), ((int) ((1.4592788680e-02) * (1 << 28))), ((int) ((1.9063586670e+00) * (1 << 28)))}, /* 1800.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.6769352756e-01) * (1 << 28))), ((int) ((1.6153236219e-02) * (1 << 28))), ((int) ((1.8883467334e+00) * (1 << 28)))}, /* 2000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.6373550234e-01) * (1 << 28))), ((int) ((1.8132248830e-02) * (1 << 28))), ((int) ((1.8636944641e+00) * (1 << 28)))}, /* 2250.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.5979586775e-01) * (1 << 28))), ((int) ((2.0102066127e-02) * (1 << 28))), ((int) ((1.8367840217e+00) * (1 << 28)))}, /* 2500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.5503518908e-01) * (1 << 28))), ((int) ((2.2482405462e-02) * (1 << 28))), ((int) ((1.8015184201e+00) * (1 << 28)))}, /* 2800.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.4975457892e-01) * (1 << 28))), ((int) ((2.5122710541e-02) * (1 << 28))), ((int) ((1.7566681757e+00) * (1 << 28)))}, /* 3150.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.4339710021e-01) * (1 << 28))), ((int) ((2.8301449895e-02) * (1 << 28))), ((int) ((1.7000688887e+00) * (1 << 28)))}, /* 3550.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.3655350715e-01) * (1 << 28))), ((int) ((3.1723246424e-02) * (1 << 28))), ((int) ((1.6304871975e+00) * (1 << 28)))}, /* 4000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.2896076477e-01) * (1 << 28))), ((int) ((3.5519617616e-02) * (1 << 28))), ((int) ((1.5458954329e+00) * (1 << 28)))}, /* 4500.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.2144774434e-01) * (1 << 28))), ((int) ((3.9276127831e-02) * (1 << 28))), ((int) ((1.4541686224e+00) * (1 << 28)))}, /* 5000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.1243019708e-01) * (1 << 28))), ((int) ((4.3784901461e-02) * (1 << 28))), ((int) ((1.3353291756e+00) * (1 << 28)))}, /* 5600.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((9.0224433806e-01) * (1 << 28))), ((int) ((4.8877830970e-02) * (1 << 28))), ((int) ((1.1860299454e+00) * (1 << 28)))}, /* 6300.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.9069401952e-01) * (1 << 28))), ((int) ((5.4652990239e-02) * (1 << 28))), ((int) ((1.0030571580e+00) * (1 << 28)))}, /* 7100.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.7787759127e-01) * (1 << 28))), ((int) ((6.1061204365e-02) * (1 << 28))), ((int) ((7.8452090451e-01) * (1 << 28)))}, /* 8000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.6417007188e-01) * (1 << 28))), ((int) ((6.7914964061e-02) * (1 << 28))), ((int) ((5.3040781162e-01) * (1 << 28)))}, /* 9000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.5086157670e-01) * (1 << 28))), ((int) ((7.4569211648e-02) * (1 << 28))), ((int) ((2.6933592404e-01) * (1 << 28)))}, /* 10000.0
	                                                                                                                                 * Hz
	                                                                                                                                 */
	{((int) ((8.3551232648e-01) * (1 << 28))), ((int) ((8.2243836759e-02) * (1 << 28))), ((int) ((-4.5760591993e-02) * (1 << 28)))}, /* 11200.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((8.1957491516e-01) * (1 << 28))), ((int) ((9.0212542420e-02) * (1 << 28))), ((int) ((-3.7957870288e-01) * (1 << 28)))}, /* 12500.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((8.0245916042e-01) * (1 << 28))), ((int) ((9.8770419789e-02) * (1 << 28))), ((int) ((-7.4132820660e-01) * (1 << 28)))}, /* 14000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((7.8216705610e-01) * (1 << 28))), ((int) ((1.0891647195e-01) * (1 << 28))), ((int) ((-1.1600775309e+00) * (1 << 28)))}, /* 16000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((7.6734339569e-01) * (1 << 28))), ((int) ((1.1632830216e-01) * (1 << 28))), ((int) ((-1.4811894772e+00) * (1 << 28)))}, /* 18000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
	{((int) ((7.6536059746e-01) * (1 << 28))), ((int) ((1.1731970127e-01) * (1 << 28))), ((int) ((-1.6905946033e+00) * (1 << 28)))}, /* 20000.0
	                                                                                                                                  * Hz
	                                                                                                                                  */
};

int round_trick (float floatvalue_to_round);

int
round_trick (float floatvalue_to_round)
{
	return (int) (floatvalue_to_round + 0.5);
}
void
init_iir (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	mv_______->iir_c___i=0;
	mv_______->iir_c___k=1;
	mv_______->iir_c___j=2;
	mv_______->iir_c___eqcfg.band_num = 10;
	mv_______->iir_c___eqcfg.use_xmms_original_freqs = 1;
	mv_______->iir_c___eqcfg.extra_filtering = 0;

	if (mv_______->iir_c___eqcfg.band_num == 15)
	{
		mv_______->iir_c___iir_cf = (void*)iir_cf15;
		mv_______->iir_c___iir_cf_fixed = (void*)iir_cf15_fixed;
	}
	else if (mv_______->iir_c___eqcfg.band_num == 31)
	{
		mv_______->iir_c___iir_cf = (void*)iir_cf31;
		mv_______->iir_c___iir_cf_fixed = (void*)iir_cf31_fixed;
	}
	else if (mv_______->iir_c___eqcfg.band_num == 25)
	{
		mv_______->iir_c___iir_cf = (void*)iir_cf25;
		mv_______->iir_c___iir_cf_fixed = (void*)iir_cf25_fixed;
	}
	else if (mv_______->iir_c___eqcfg.band_num == 10 && mv_______->iir_c___eqcfg.use_xmms_original_freqs)
	{
		mv_______->iir_c___iir_cf = (void*)iir_cforiginal10;
		mv_______->iir_c___iir_cf_fixed = (void*)iir_cforiginal10_fixed;
	}
	else
	{
		mv_______->iir_c___iir_cf = (void*)iir_cf10;
		mv_______->iir_c___iir_cf_fixed = (void*)iir_cf10_fixed;
	}

	memset (mv_______->iir_c___data_history, 0, sizeof (sXYData) * 31 * 2);
	memset (mv_______->iir_c___data_history2, 0, sizeof (sXYData) * 31 * 2);

	memset (mv_______->iir_c___data_history_fixed, 0, sizeof (sXYData_fixed) * 31 * 2);
	memset (mv_______->iir_c___data_history2_fixed, 0, sizeof (sXYData_fixed) * 31 * 2);

}
/* [closed] */
/*
//to fix a problem in x86 and x64 CPUs regarding floating point errors that can make the processor time usage go up to 100%
void amanda_fix_dithering(char *d_kp, int length_kp)
{

	return; 

	short *amanda = (void *) d_kp;

	int i_kp;

	for(i_kp = 0; i_kp < length_kp / 2; i_kp++)
	{

		int temp_k;

		temp_k = (int) amanda[i_kp];

		temp_k += rnd_k_p(-2,+2);

		//to avoid clipping, as usual...
		if(-32768 > temp_k)
		{
			pedro_dprintf(-1, "pegou pra baixo");
			amanda[i_kp] = -32768;
		}
		else if(32767 < temp_k)
		{
			pedro_dprintf(-1, "pegou pra cima");
			amanda[i_kp] = 32767;
		}
		else
		{
			amanda[i_kp] = (short) temp_k;
			
			if(0 == amanda[i_kp])
			{
				amanda[i_kp] = 1;
			}
		}

	}
	pedro_dprintf(-1, "dentro de amanda_fix_dithering %d %d", length_kp, i_kp);
	return;
// :-) December, 2020 ...
}
*/

int
iir (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels)
{
	short *data = (short *) d;
	int index, band, channel;
	int tempgint, halflength;
	float out[2], pcm[2];
	int deslocador = 0;

	int interactions = 0;

	mv_______->iir_c___eqcfg.band_num = 10;
	mv_______->iir_c___eqcfg.use_xmms_original_freqs = 1;
	mv_______->iir_c___eqcfg.extra_filtering = 0;

	mv_______->iir_c___iir_cf = (void*)iir_cforiginal10;
	mv_______->iir_c___iir_cf_fixed = (void*)iir_cforiginal10_fixed;

	if (channels == 1)
	{
		deslocador = 1;
	}
	else
	{
		deslocador = 2;
	}
	halflength = (length >> 1);

	for (index = 0; index < halflength; index += deslocador)
	{

		for (channel = 0; channel < channels; channel++)
		{

			pcm[channel] = data[index + channel];

			out[channel] = 0;

			for (band = 0; band < mv_______->iir_c___eqcfg.band_num; band++)
			{
				mv_______->iir_c___data_history[band][channel].x[mv_______->iir_c___i] = pcm[channel];
				mv_______->iir_c___data_history[band][channel].y[mv_______->iir_c___i] = (
					mv_______->iir_c___iir_cf
					[band].
					alpha
					*
					(mv_______->iir_c___data_history
					 [band]
					 [channel].
					 x
					 [mv_______->iir_c___i]
					 -
					 mv_______->iir_c___data_history
					 [band][channel].x[mv_______->iir_c___k])
					+
					mv_______->iir_c___iir_cf
					[band].
					gamma
					*
					mv_______->iir_c___data_history
					[band][channel].y[mv_______->iir_c___j]
					-
					mv_______->iir_c___iir_cf
					[band].
					beta
					*
					mv_______->iir_c___data_history
					[band][channel].y[mv_______->iir_c___k]);

				out[channel] += mv_______->iir_c___data_history[band][channel].y[mv_______->iir_c___i] * mv_______->iir_c___gain[band][channel]; // *

				interactions++;

			}

			out[channel] += (data[index + channel] >> 2);

			tempgint = round_trick (out[channel]);

			if (tempgint < -32768)
				data[index + channel] = -32768;
			else if (tempgint > 32767)
				data[index + channel] = 32767;
			else
				data[index + channel] = tempgint;
		}               /* For each channel */

		mv_______->iir_c___i++;
		mv_______->iir_c___j++;
		mv_______->iir_c___k++;

		if (mv_______->iir_c___i == 3)
			mv_______->iir_c___i = 0;
		else if (mv_______->iir_c___j == 3)
			mv_______->iir_c___j = 0;
		else
			mv_______->iir_c___k = 0;

	}

	return length;
}
int
configequalizer (morcego___i___instance__a__bucaneiro_engineering *mv_______,int b60, int b170, int b310, int b600, int b1000, int b3000,
                 int b6000, int b12000, int b14000, int b16000)
{

	float fixo = 60;

	float bb60 = (float) (b60 - 12) / (float) (fixo);

	float bb170 = (float) (b170 - 12) / (float) (fixo);
	float bb310 = (float) (b310 - 12) / (float) (fixo);
	float bb600 = (float) (b600 - 12) / (float) (fixo);
	float bb1000 = (float) (b1000 - 12) / (float) (fixo);
	float bb3000 = (float) (b3000 - 12) / (float) (fixo);
	float bb6000 = (float) (b6000 - 12) / (float) (fixo);
	float bb12000 = (float) (b12000 - 12) / (float) (fixo);
	float bb14000 = (float) (b14000 - 12) / (float) (fixo);
	float bb16000 = (float) (b16000 - 12) / (float) (fixo);
	{
		double fixo=0.133333;

		mv_______->iir_c___gain[0][0] = bb60-fixo;
		mv_______->iir_c___gain[0][1] = bb60-fixo;
		mv_______->iir_c___gain[1][0] = bb170-fixo;
		mv_______->iir_c___gain[1][1] = bb170-fixo;
		mv_______->iir_c___gain[2][0] = bb310-fixo;
		mv_______->iir_c___gain[2][1] = bb310-fixo;
		mv_______->iir_c___gain[3][0] = bb600-fixo;
		mv_______->iir_c___gain[3][1] = bb600-fixo;
		mv_______->iir_c___gain[4][0] = bb1000-fixo;
		mv_______->iir_c___gain[4][1] = bb1000-fixo;
		mv_______->iir_c___gain[5][0] = bb3000-fixo;
		mv_______->iir_c___gain[5][1] = bb3000-fixo;
		mv_______->iir_c___gain[6][0] = bb6000-fixo;
		mv_______->iir_c___gain[6][1] = bb6000-fixo;
		mv_______->iir_c___gain[7][0] = bb12000-fixo;
		mv_______->iir_c___gain[7][1] = bb12000-fixo;
		mv_______->iir_c___gain[8][0] = bb14000-fixo;
		mv_______->iir_c___gain[8][1] = bb14000-fixo;
		mv_______->iir_c___gain[9][0] = bb16000-fixo;
		mv_______->iir_c___gain[9][1] = bb16000-fixo;
	}
	return 0;

}
void
init_iir____2 (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	mv_______->iir_c_2__i=0;
	mv_______->iir_c_2__k=1;
	mv_______->iir_c_2__j=2;

	mv_______->iir_c_2__eqcfg.band_num = 10;
	mv_______->iir_c_2__eqcfg.use_xmms_original_freqs = 1;
	mv_______->iir_c_2__eqcfg.extra_filtering = 0;

	if (mv_______->iir_c_2__eqcfg.band_num == 15)
	{
		mv_______->iir_c_2__iir_cf = (void*)iir_cf15;
		mv_______->iir_c_2__iir_cf_fixed = (void*)iir_cf15_fixed;
	}
	else if (mv_______->iir_c_2__eqcfg.band_num == 31)
	{
		mv_______->iir_c_2__iir_cf = (void*)iir_cf31;
		mv_______->iir_c_2__iir_cf_fixed = (void*)iir_cf31_fixed;
	}
	else if (mv_______->iir_c_2__eqcfg.band_num == 25)
	{
		mv_______->iir_c_2__iir_cf = (void*)iir_cf25;
		mv_______->iir_c_2__iir_cf_fixed = (void*)iir_cf25_fixed;
	}
	else if (mv_______->iir_c_2__eqcfg.band_num == 10 && mv_______->iir_c_2__eqcfg.use_xmms_original_freqs)
	{
		mv_______->iir_c_2__iir_cf = (void*)iir_cforiginal10;
		mv_______->iir_c_2__iir_cf_fixed = (void*)iir_cforiginal10_fixed;
	}
	else
	{
		mv_______->iir_c_2__iir_cf = (void*)iir_cf10;
		mv_______->iir_c_2__iir_cf_fixed = (void*)iir_cf10_fixed;
	}

	memset (mv_______->iir_c_2__data_history, 0, sizeof (sXYData) * 31 * 2);
	memset (mv_______->iir_c_2__data_history2, 0, sizeof (sXYData) * 31 * 2);

	memset (mv_______->iir_c_2__data_history_fixed, 0, sizeof (sXYData_fixed) * 31 * 2);
	memset (mv_______->iir_c_2__data_history2_fixed, 0, sizeof (sXYData_fixed) * 31 * 2);

	;                       // dprintf ("terminou a setagem de equalizer \n");
}

int
iir___2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels)
{
	short *data = (short *) d;

	int index, band, channel;
	int tempgint, halflength;
	float out[2], pcm[2];
	int deslocador = 0;

	mv_______->iir_c_2__eqcfg.band_num = 10;
	mv_______->iir_c_2__eqcfg.use_xmms_original_freqs = 1;
	mv_______->iir_c_2__eqcfg.extra_filtering = 0;

	mv_______->iir_c_2__iir_cf = (void*)iir_cforiginal10;
	mv_______->iir_c_2__iir_cf_fixed = (void*)iir_cforiginal10_fixed;

	if (channels == 1)
	{
		deslocador = 1;
	}
	else
	{
		deslocador = 2;
	}

	halflength = (length >> 1);
	for (index = 0; index < halflength; index += deslocador)
	{

		for (channel = 0; channel < channels; channel++)
		{

			/*
			 * No need to scale when processing the PCM with the filter
			 */

			pcm[channel] = data[index + channel];

			out[channel] = 0;

			for (band = 0; band < mv_______->iir_c_2__eqcfg.band_num; band++)
			{

				/*
				 * Store Xi(n)
				 */

				mv_______->iir_c_2__data_history[band][channel].x[mv_______->iir_c_2__i] = pcm[channel];

				/*
				 * Calculate and store Yi(n)
				 */
				mv_______->iir_c_2__data_history[band][channel].y[mv_______->iir_c_2__i] = (
					/*
					 * = alpha *
					 * [x(n)-x(n-2)]
					 */
					mv_______->iir_c_2__iir_cf
					[band].
					alpha
					*
					(mv_______->iir_c_2__data_history
					 [band]
					 [channel].
					 x
					 [mv_______->iir_c_2__i]
					 -
					 mv_______->iir_c_2__data_history
					 [band][channel].x[mv_______->iir_c_2__k])
					/*
					 * + gamma * y(n-1)
					 */
					+
					mv_______->iir_c_2__iir_cf
					[band].
					gamma
					*
					mv_______->iir_c_2__data_history
					[band][channel].y[mv_______->iir_c_2__j]
					/*
					 * - beta * y(n-2)
					 */
					-
					mv_______->iir_c_2__iir_cf
					[band].
					beta
					*
					mv_______->iir_c_2__data_history
					[band][channel].y[mv_______->iir_c_2__k]);

				out[channel] += mv_______->iir_c_2__data_history[band][channel].y[mv_______->iir_c_2__i] * mv_______->iir_c_2__gain[band][channel]; // *

			}
			out[channel] += (data[index + channel] >> 2);

			tempgint = round_trick (out[channel]);

			if (tempgint < -32768)
				data[index + channel] = -32768;
			else if (tempgint > 32767)
				data[index + channel] = 32767;
			else
				data[index + channel] = tempgint;
		}               /* For each channel */

		mv_______->iir_c_2__i++;
		mv_______->iir_c_2__j++;
		mv_______->iir_c_2__k++;

		if (mv_______->iir_c_2__i == 3)
			mv_______->iir_c_2__i = 0;
		else if (mv_______->iir_c_2__j == 3)
			mv_______->iir_c_2__j = 0;
		else
			mv_______->iir_c_2__k = 0;

	}

	return length;
}

int
configequalizer____2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,int b60, int b170, int b310, int b600, int b1000, int b3000,
                      int b6000, int b12000, int b14000, int b16000)
{

	float fixo = 60;

	float bb60 = (float) (b60 - 12) / (float) (fixo);

	float bb170 = (float) (b170 - 12) / (float) (fixo);
	float bb310 = (float) (b310 - 12) / (float) (fixo);
	float bb600 = (float) (b600 - 12) / (float) (fixo);
	float bb1000 = (float) (b1000 - 12) / (float) (fixo);
	float bb3000 = (float) (b3000 - 12) / (float) (fixo);
	float bb6000 = (float) (b6000 - 12) / (float) (fixo);
	float bb12000 = (float) (b12000 - 12) / (float) (fixo);
	float bb14000 = (float) (b14000 - 12) / (float) (fixo);
	float bb16000 = (float) (b16000 - 12) / (float) (fixo);
	{
		double fixo=0.133333;

		mv_______->iir_c_2__gain[0][0] = bb60-fixo;
		mv_______->iir_c_2__gain[0][1] = bb60-fixo;
		mv_______->iir_c_2__gain[1][0] = bb170-fixo;
		mv_______->iir_c_2__gain[1][1] = bb170-fixo;
		mv_______->iir_c_2__gain[2][0] = bb310-fixo;
		mv_______->iir_c_2__gain[2][1] = bb310-fixo;
		mv_______->iir_c_2__gain[3][0] = bb600-fixo;
		mv_______->iir_c_2__gain[3][1] = bb600-fixo;
		mv_______->iir_c_2__gain[4][0] = bb1000-fixo;
		mv_______->iir_c_2__gain[4][1] = bb1000-fixo;
		mv_______->iir_c_2__gain[5][0] = bb3000-fixo;
		mv_______->iir_c_2__gain[5][1] = bb3000-fixo;
		mv_______->iir_c_2__gain[6][0] = bb6000-fixo;
		mv_______->iir_c_2__gain[6][1] = bb6000-fixo;
		mv_______->iir_c_2__gain[7][0] = bb12000-fixo;
		mv_______->iir_c_2__gain[7][1] = bb12000-fixo;
		mv_______->iir_c_2__gain[8][0] = bb14000-fixo;
		mv_______->iir_c_2__gain[8][1] = bb14000-fixo;
		mv_______->iir_c_2__gain[9][0] = bb16000-fixo;
		mv_______->iir_c_2__gain[9][1] = bb16000-fixo;
	}
	return 0;

}
double getporf (double maxa, double fatiaa);
#include "spectrum60.c"
//finished at 13:10 19/march/2021  MathMan and amanda