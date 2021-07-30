
/*
 *  ReplayGainAnalysis - analyzes input samples and give the
   recommended dB change
 *  Copyright (C) 2001 David Robinson and Glen Sawyer
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR gain_analysis_c PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  concept and filter values by David Robinson (David@Robinson.org)
 *    -- blame him if you think the idea is flawed
 *  original coding by Glen Sawyer (glensawyer@hotmail.com)
 *    -- blame him if you think this runs too slowly, or the coding is otherwise flawed
 *
 *  lots of code improvements by Frank Klemm ( http://www.uni-jena.de/~pfk/mpp/ )
 *    -- credit him for all the _good_ programming ;)
 *
 *
 *  For an explanation of the concepts and the basic algorithms involved, go to:
 *    http://www.replaygain.org/
 */
 
/*
    <C/C++ source code of the support dlls>    
    Copyright (C) <2020>  <BinaryWork Corp.>

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
	Ricardo: arsoftware25@gmail.com
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

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#undef NDEBUG
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "mv_from_be.h"

/*
 *  Here's the deal. Call
 *
 *    InitGainAnalysis ( long samplefreq );
 *
 *  to initialize everything. Call
 *
 *    AnalyzeSamples ( const Float_t*  left_samples,
 *                     const Float_t*  right_samples,
 *                     size_t          num_samples,
 *                     int             num_channels );
 *
 *  as many times as you want, with as many or as few samples as you want.
 *  If mono, pass the sample buffer in through left_samples, leave
 *  right_samples NULL, and make sure num_channels = 1.
 *
 *    GetTitleGain()
 *
 *  will return the recommended dB level change for all samples analyzed
 *  SINCE THE LAST TIME you called GetTitleGain() OR InitGainAnalysis().
 *
 *    GetAlbumGain()
 *
 *  will return the recommended dB level change for all samples analyzed
 *  since InitGainAnalysis() was called and finalized with GetTitleGain().
 *
 *  Pseudo-code to process an album:
 *
 *    Float_t       l_samples [4096];
 *    Float_t       r_samples [4096];
 *    size_t        num_samples;
 *    unsigned int  num_songs;
 *    unsigned int  i;
 *
 *    InitGainAnalysis ( 44100 );
 *    for ( i = 1; i <= num_songs; i++ ) {
 *        while ( ( num_samples = getSongSamples ( song[i], left_samples, right_samples ) ) > 0 )
 *            AnalyzeSamples ( left_samples, right_samples, num_samples, 2 );
 *        fprintf ("Recommended dB change for song %2d: %+6.2f dB\n", i, GetTitleGain() );
 *    }
 *    fprintf ("Recommended dB change for whole album: %+6.2f dB\n", GetAlbumGain() );
 */

/*
 *  So here's the main source of potential code confusion:
 *
 *  The filters applied to the incoming samples are IIR filters,
 *  meaning they rely on up to <filter order> number of previous samples
 *  AND up to <filter order> number of previous filtered samples.
 *
 *  I set up the AnalyzeSamples routine to minimize memory usage and interface
 *  complexity. The speed isn't compromised too much (I don't think), but the
 *  internal complexity is higher than it should be for such a relatively
 *  simple routine.
 *
 *  Optimization/clarity suggestions are welcome.
 */

int id3v2tag_check (char *filename);

__int64 id3v2tag (char *filename);

int rewrite_header (FILE * out, unsigned int written);

int write_prelim_header (FILE * out, int channels, int samplerate);

int detect (char *filename, __int64 *seekpoint);

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
int set_dest_path (char *path);
int detect (char *filename, __int64 *seekpoint);
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

int convertmp3towav (char *filename, char *outname);

int configequalizer (int b60, int b170, int b310, int b600, int b1000,
                     int b3000, int b6000, int b12000, int b14000,
                     int b16000);

int setvolume (int newvalue);


int v2cleanup ();

int configequalizer2 (int b60, int b170, int b310, int b600, int b1000,
                      int b3000, int b6000, int b12000, int b14000,
                      int b16000);


int isclosed ();





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

#include             <stdio.h>
#include            <stdlib.h>
#include            <string.h>
#include              <math.h>

const Float_t AYule[9][11] = {
	{1., -3.84664617118067, 7.81501653005538, -11.34170355132042,
	 13.05504219327545, -12.28759895145294, 9.48293806319790,
	 -5.87257861775999, 2.75465861874613, -0.86984376593551,
	 0.13919314567432},
	{1., -3.47845948550071, 6.36317777566148, -8.54751527471874,
	 9.47693607801280, -8.81498681370155, 6.85401540936998,
	 -4.39470996079559, 2.19611684890774, -0.75104302451432,
	 0.13149317958808},
	{1., -2.37898834973084, 2.84868151156327, -2.64577170229825,
	 2.23697657451713, -1.67148153367602, 1.00595954808547,
	 -0.45953458054983, 0.16378164858596, -0.05032077717131,
	 0.02347897407020},
	{1., -1.61273165137247, 1.07977492259970, -0.25656257754070,
	 -0.16276719120440, -0.22638893773906, 0.39120800788284,
	 -0.22138138954925, 0.04500235387352, 0.02005851806501,
	 0.00302439095741},
	{1., -1.49858979367799, 0.87350271418188, 0.12205022308084,
	 -0.80774944671438, 0.47854794562326, -0.12453458140019,
	 -0.04067510197014, 0.08333755284107, -0.04237348025746,
	 0.02977207319925},
	{1., -0.62820619233671, 0.29661783706366, -0.37256372942400,
	 0.00213767857124, -0.42029820170918, 0.22199650564824,
	 0.00613424350682, 0.06747620744683, 0.05784820375801,
	 0.03222754072173},
	{1., -1.04800335126349, 0.29156311971249, -0.26806001042947,
	 0.00819999645858, 0.45054734505008, -0.33032403314006,
	 0.06739368333110, -0.04784254229033, 0.01639907836189,
	 0.01807364323573},
	{1., -0.51035327095184, -0.31863563325245, -0.20256413484477,
	 0.14728154134330, 0.38952639978999, -0.23313271880868,
	 -0.05246019024463, -0.02505961724053, 0.02442357316099,
	 0.01818801111503},
	{1., -0.25049871956020, -0.43193942311114, -0.03424681017675,
	 -0.04678328784242, 0.26408300200955, 0.15113130533216,
	 -0.17556493366449, -0.18823009262115, 0.05477720428674,
	 0.04704409688120}
};

const Float_t BYule[9][11] = {
	{0.03857599435200, -0.02160367184185, -0.00123395316851,
	 -0.00009291677959, -0.01655260341619, 0.02161526843274,
	 -0.02074045215285, 0.00594298065125, 0.00306428023191,
	 0.00012025322027, 0.00288463683916},
	{0.05418656406430, -0.02911007808948, -0.00848709379851,
	 -0.00851165645469, -0.00834990904936, 0.02245293253339,
	 -0.02596338512915, 0.01624864962975, -0.00240879051584,
	 0.00674613682247, -0.00187763777362},
	{0.15457299681924, -0.09331049056315, -0.06247880153653,
	 0.02163541888798, -0.05588393329856, 0.04781476674921,
	 0.00222312597743, 0.03174092540049, -0.01390589421898,
	 0.00651420667831, -0.00881362733839},
	{0.30296907319327, -0.22613988682123, -0.08587323730772,
	 0.03282930172664, -0.00915702933434, -0.02364141202522,
	 -0.00584456039913, 0.06276101321749, -0.00000828086748,
	 0.00205861885564, -0.02950134983287},
	{0.33642304856132, -0.25572241425570, -0.11828570177555,
	 0.11921148675203, -0.07834489609479, -0.00469977914380,
	 -0.00589500224440, 0.05724228140351, 0.00832043980773,
	 -0.01635381384540, -0.01760176568150},
	{0.44915256608450, -0.14351757464547, -0.22784394429749,
	 -0.01419140100551, 0.04078262797139, -0.12398163381748,
	 0.04097565135648, 0.10478503600251, -0.01863887810927,
	 -0.03193428438915, 0.00541907748707},
	{0.56619470757641, -0.75464456939302, 0.16242137742230,
	 0.16744243493672, -0.18901604199609, 0.30931782841830,
	 -0.27562961986224, 0.00647310677246, 0.08647503780351,
	 -0.03788984554840, -0.00588215443421},
	{0.58100494960553, -0.53174909058578, -0.14289799034253,
	 0.17520704835522, 0.02377945217615, 0.15558449135573,
	 -0.25344790059353, 0.01628462406333, 0.06920467763959,
	 -0.03721611395801, -0.00749618797172},
	{0.53648789255105, -0.42163034350696, -0.00275953611929,
	 0.04267842219415, -0.10214864179676, 0.14590772289388,
	 -0.02459864859345, -0.11202315195388, -0.04060034127000,
	 0.04788665548180, -0.02217936801134}
};

const Float_t AButter[9][3] = {
	{1., -1.97223372919527, 0.97261396931306},
	{1., -1.96977855582618, 0.97022847566350},
	{1., -1.95835380975398, 0.95920349965459},
	{1., -1.95002759149878, 0.95124613669835},
	{1., -1.94561023566527, 0.94705070426118},
	{1., -1.92783286977036, 0.93034775234268},
	{1., -1.91858953033784, 0.92177618768381},
	{1., -1.91542108074780, 0.91885558323625},
	{1., -1.88903307939452, 0.89487434461664}
};

const Float_t BButter[9][3] = {
	{0.98621192462708, -1.97242384925416, 0.98621192462708},
	{0.98500175787242, -1.97000351574484, 0.98500175787242},
	{0.97938932735214, -1.95877865470428, 0.97938932735214},
	{0.97531843204928, -1.95063686409857, 0.97531843204928},
	{0.97316523498161, -1.94633046996323, 0.97316523498161},
	{0.96454515552826, -1.92909031105652, 0.96454515552826},
	{0.96009142950541, -1.92018285901082, 0.96009142950541},
	{0.95856916599601, -1.91713833199203, 0.95856916599601},
	{0.94597685600279, -1.89195371200558, 0.94597685600279}
};

/* When calling this procedure, make sure that ip[-order] and op[-order] point to real data! */

static void
filter (const Float_t * input, Float_t * output, size_t nSamples,
        const Float_t * a, const Float_t * b, size_t order)
{
	double y;
	size_t i;
	size_t k;

	for (i = 0; i < nSamples; i++)
	{
		y = input[i] * b[0];
		for (k = 1; k <= order; k++)
			y += input[i - k] * b[k] - output[i - k] * a[k];
		output[i] = (Float_t) y;
	}
}

/* returns a INIT_GAIN_ANALYSIS_OK if successful, INIT_GAIN_ANALYSIS_ERROR if not */

int
ResetSampleFrequency (morcego___i___instance__a__bucaneiro_engineering *mv_______,long samplefreq)
{
	int i;

	/* zero out initial values */
	for (i = 0; i < MAX_ORDER; i++)
		mv_______->gain_analysis_c___linprebuf[i] = mv_______->gain_analysis_c___lstepbuf[i] = mv_______->gain_analysis_c___loutbuf[i] = mv_______->gain_analysis_c___rinprebuf[i] =
		                                                                               mv_______->gain_analysis_c___rstepbuf[i] = mv_______->gain_analysis_c___routbuf[i] = 0.;

	switch ((int) (samplefreq))
	{
	case 48000:
		mv_______->gain_analysis_c___freqindex = 0;
		break;
	case 44100:
		mv_______->gain_analysis_c___freqindex = 1;
		break;
	case 32000:
		mv_______->gain_analysis_c___freqindex = 2;
		break;
	case 24000:
		mv_______->gain_analysis_c___freqindex = 3;
		break;
	case 22050:
		mv_______->gain_analysis_c___freqindex = 4;
		break;
	case 16000:
		mv_______->gain_analysis_c___freqindex = 5;
		break;
	case 12000:
		mv_______->gain_analysis_c___freqindex = 6;
		break;
	case 11025:
		mv_______->gain_analysis_c___freqindex = 7;
		break;
	case 8000:
		mv_______->gain_analysis_c___freqindex = 8;
		break;
	default:
		return INIT_GAIN_ANALYSIS_ERROR;
	}

	mv_______->gain_analysis_c___sampleWindow = (int) ceil (samplefreq * RMS_WINDOW_TIME);

	mv_______->gain_analysis_c___lsum = 0.;
	mv_______->gain_analysis_c___rsum = 0.;
	mv_______->gain_analysis_c___totsamp = 0;

	memset (mv_______->gain_analysis_c___A, 0, sizeof (mv_______->gain_analysis_c___A));

	return INIT_GAIN_ANALYSIS_OK;
}

int
InitGainAnalysis (morcego___i___instance__a__bucaneiro_engineering *mv_______,long samplefreq)
{
	if (ResetSampleFrequency (mv_______,samplefreq) != INIT_GAIN_ANALYSIS_OK)
	{
		return INIT_GAIN_ANALYSIS_ERROR;
	}

	mv_______->gain_analysis_c___linpre = mv_______->gain_analysis_c___linprebuf + MAX_ORDER;
	mv_______->gain_analysis_c___rinpre = mv_______->gain_analysis_c___rinprebuf + MAX_ORDER;
	mv_______->gain_analysis_c___lstep = mv_______->gain_analysis_c___lstepbuf + MAX_ORDER;
	mv_______->gain_analysis_c___rstep = mv_______->gain_analysis_c___rstepbuf + MAX_ORDER;
	mv_______->gain_analysis_c___lout = mv_______->gain_analysis_c___loutbuf + MAX_ORDER;
	mv_______->gain_analysis_c___rout = mv_______->gain_analysis_c___routbuf + MAX_ORDER;

	memset (mv_______->gain_analysis_c___B, 0, sizeof (mv_______->gain_analysis_c___B));

	return INIT_GAIN_ANALYSIS_OK;
}

/* returns GAIN_ANALYSIS_OK if successful, GAIN_ANALYSIS_ERROR if not */

int
AnalyzeSamples (morcego___i___instance__a__bucaneiro_engineering *mv_______,const Float_t * left_samples, const Float_t * right_samples,
                size_t num_samples, int num_channels)
{
	const Float_t *curleft;
	const Float_t *curright;
	long batchsamples;
	long cursamples;
	long cursamplepos;
	int i;

	//thinktwice (1);

	if (num_samples == 0)
		return GAIN_ANALYSIS_OK;

	cursamplepos = 0;
	batchsamples = num_samples;

	switch (num_channels)
	{
	case 1:
		right_samples = left_samples;
	case 2:
		break;
	default:
		return GAIN_ANALYSIS_ERROR;
	}

	if (num_samples < MAX_ORDER)
	{
		memcpy (mv_______->gain_analysis_c___linprebuf + MAX_ORDER, left_samples,
		        num_samples * sizeof (Float_t));
		memcpy (mv_______->gain_analysis_c___rinprebuf + MAX_ORDER, right_samples,
		        num_samples * sizeof (Float_t));
	}
	else
	{
		memcpy (mv_______->gain_analysis_c___linprebuf + MAX_ORDER, left_samples,
		        MAX_ORDER * sizeof (Float_t));
		memcpy (mv_______->gain_analysis_c___rinprebuf + MAX_ORDER, right_samples,
		        MAX_ORDER * sizeof (Float_t));
	}

	while (batchsamples > 0)
	{
		cursamples =
		        (long unsigned int) batchsamples >
		        mv_______->gain_analysis_c___sampleWindow - mv_______->gain_analysis_c___totsamp ? mv_______->gain_analysis_c___sampleWindow -
		        mv_______->gain_analysis_c___totsamp : (long unsigned int ) batchsamples;
		if (cursamplepos < MAX_ORDER)
		{
			curleft = mv_______->gain_analysis_c___linpre + cursamplepos;
			curright = mv_______->gain_analysis_c___rinpre + cursamplepos;
			if (cursamples > MAX_ORDER - cursamplepos)
				cursamples = MAX_ORDER - cursamplepos;
		}
		else
		{
			curleft = left_samples + cursamplepos;
			curright = right_samples + cursamplepos;
		}

		filter (curleft, mv_______->gain_analysis_c___lstep + mv_______->gain_analysis_c___totsamp, cursamples,
		        AYule[mv_______->gain_analysis_c___freqindex], BYule[mv_______->gain_analysis_c___freqindex], YULE_ORDER);
		filter (curright, mv_______->gain_analysis_c___rstep + mv_______->gain_analysis_c___totsamp, cursamples,
		        AYule[mv_______->gain_analysis_c___freqindex], BYule[mv_______->gain_analysis_c___freqindex], YULE_ORDER);

		filter (mv_______->gain_analysis_c___lstep + mv_______->gain_analysis_c___totsamp, mv_______->gain_analysis_c___lout + mv_______->gain_analysis_c___totsamp, cursamples,
		        AButter[mv_______->gain_analysis_c___freqindex], BButter[mv_______->gain_analysis_c___freqindex],
		        BUTTER_ORDER);
		filter (mv_______->gain_analysis_c___rstep + mv_______->gain_analysis_c___totsamp, mv_______->gain_analysis_c___rout + mv_______->gain_analysis_c___totsamp, cursamples,
		        AButter[mv_______->gain_analysis_c___freqindex], BButter[mv_______->gain_analysis_c___freqindex],
		        BUTTER_ORDER);

		for (i = 0; i < cursamples; i++)
		{               /* Get the squared values */
			mv_______->gain_analysis_c___lsum += mv_______->gain_analysis_c___lout[mv_______->gain_analysis_c___totsamp + i] * mv_______->gain_analysis_c___lout[mv_______->gain_analysis_c___totsamp + i];
			mv_______->gain_analysis_c___rsum += mv_______->gain_analysis_c___rout[mv_______->gain_analysis_c___totsamp + i] * mv_______->gain_analysis_c___rout[mv_______->gain_analysis_c___totsamp + i];
		}

		batchsamples -= cursamples;
		cursamplepos += cursamples;
		mv_______->gain_analysis_c___totsamp += cursamples;
		if (mv_______->gain_analysis_c___totsamp == mv_______->gain_analysis_c___sampleWindow)
		{               /* Get the Root Mean Square (RMS) for this set of samples */
			double val =
			        STEPS_per_dB * 10. *
			        log10 ((mv_______->gain_analysis_c___lsum + mv_______->gain_analysis_c___rsum) / mv_______->gain_analysis_c___totsamp * 0.5 +
			               1.e-37);
			int ival = (int) val;
			if (ival < 0)
				ival = 0;
			if ((long long unsigned int) ival >= sizeof (mv_______->gain_analysis_c___A) / sizeof (*mv_______->gain_analysis_c___A))
				ival = sizeof (mv_______->gain_analysis_c___A) / sizeof (*mv_______->gain_analysis_c___A) - 1;
			mv_______->gain_analysis_c___A[ival]++;
			mv_______->gain_analysis_c___lsum = mv_______->gain_analysis_c___rsum = 0.;
			memmove (mv_______->gain_analysis_c___loutbuf, mv_______->gain_analysis_c___loutbuf + mv_______->gain_analysis_c___totsamp,
			         MAX_ORDER * sizeof (Float_t));
			memmove (mv_______->gain_analysis_c___routbuf, mv_______->gain_analysis_c___routbuf + mv_______->gain_analysis_c___totsamp,
			         MAX_ORDER * sizeof (Float_t));
			memmove (mv_______->gain_analysis_c___lstepbuf, mv_______->gain_analysis_c___lstepbuf + mv_______->gain_analysis_c___totsamp,
			         MAX_ORDER * sizeof (Float_t));
			memmove (mv_______->gain_analysis_c___rstepbuf, mv_______->gain_analysis_c___rstepbuf + mv_______->gain_analysis_c___totsamp,
			         MAX_ORDER * sizeof (Float_t));
			mv_______->gain_analysis_c___totsamp = 0;
		}
		if (mv_______->gain_analysis_c___totsamp > mv_______->gain_analysis_c___sampleWindow)     /* somehow I really screwed up: Error in programming! Contact author about mv_______->gain_analysis_c___totsamp > mv_______->gain_analysis_c___sampleWindow */
			return GAIN_ANALYSIS_ERROR;
	}
	if (num_samples < MAX_ORDER)
	{
		memmove (mv_______->gain_analysis_c___linprebuf, mv_______->gain_analysis_c___linprebuf + num_samples,
		         (MAX_ORDER - num_samples) * sizeof (Float_t));
		memmove (mv_______->gain_analysis_c___rinprebuf, mv_______->gain_analysis_c___rinprebuf + num_samples,
		         (MAX_ORDER - num_samples) * sizeof (Float_t));
		memcpy (mv_______->gain_analysis_c___linprebuf + MAX_ORDER - num_samples, left_samples,
		        num_samples * sizeof (Float_t));
		memcpy (mv_______->gain_analysis_c___rinprebuf + MAX_ORDER - num_samples, right_samples,
		        num_samples * sizeof (Float_t));
	}
	else
	{
		memcpy (mv_______->gain_analysis_c___linprebuf, left_samples + num_samples - MAX_ORDER,
		        MAX_ORDER * sizeof (Float_t));
		memcpy (mv_______->gain_analysis_c___rinprebuf, right_samples + num_samples - MAX_ORDER,
		        MAX_ORDER * sizeof (Float_t));
	}

	return GAIN_ANALYSIS_OK;
}

Float_t
analyzeResult (Uint32_t * Array, size_t len, __attribute__((unused)) int *error)
{
	Uint32_t elems;
	Int32_t upper;
	size_t i;

	elems = 0;
	for (i = 0; i < len; i++)
		elems += Array[i];
	if (elems == 0)
		return GAIN_NOT_ENOUGH_SAMPLES;  //bug not yours

	upper = (Int32_t) ceil (elems * (1. - RMS_PERCENTILE));
	for (i = len; i-- > 0; )
	{
		if ((upper -= Array[i]) <= 0)
			break;
	}
/*

   aparentemente é aqui que da o valor em multiplicador

   Uma simples analize deste codigo vai dar o valor
   porque aqui tem uma conversao de multiplicador por db
   a conversao é baseada nisto

   +5 db + 14 db e assim por diante
 */

	{

		Float_t a;
		a= (Float_t) ((Float_t) PINK_REF -
		              (Float_t) i / (Float_t) STEPS_per_dB);
		return a;
		
	}
}

Float_t
GetTitleGain (morcego___i___instance__a__bucaneiro_engineering *mv_______,int *error)
{
	Float_t retval;
	int i;

	//int error=0;
	*error=0;
	retval = analyzeResult (mv_______->gain_analysis_c___A, sizeof (mv_______->gain_analysis_c___A) / sizeof (*mv_______->gain_analysis_c___A), error);

	for (i = 0; (long long unsigned int) i < sizeof (mv_______->gain_analysis_c___A) / sizeof (*mv_______->gain_analysis_c___A); i++)
	{
		mv_______->gain_analysis_c___B[i] += mv_______->gain_analysis_c___A[i];
		mv_______->gain_analysis_c___A[i] = 0;
	}

	for (i = 0; i < MAX_ORDER; i++)
		mv_______->gain_analysis_c___linprebuf[i] = mv_______->gain_analysis_c___lstepbuf[i] = mv_______->gain_analysis_c___loutbuf[i] = mv_______->gain_analysis_c___rinprebuf[i] =
		                                                                               mv_______->gain_analysis_c___rstepbuf[i] = mv_______->gain_analysis_c___routbuf[i] = 0.f;

	mv_______->gain_analysis_c___totsamp = 0;
	mv_______->gain_analysis_c___lsum = mv_______->gain_analysis_c___rsum = 0.;
	return retval;
}