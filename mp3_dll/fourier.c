
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de C�pia (C) <2021>  <Corpora��o do Trabalho Bin�rio>         *
 *                                                                              *
 *     Este  programa  � software livre: voc� pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como       8
 *     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da       *
 *     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.         *
 *                                                                              *
 *     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de       *
 *     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P�blica para mais detalhes.                                *
 *                                                                              *
 *     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P�blica Menor junto com este programa                            *
 *     Se n�o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita r�pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                 *      
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

// Fourier.cpp: implementation of the Fourier class. by who?
//
//////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <stdio.h>
#include <math.h>
//#include <unistd.h>
#include <limits.h>
#include <time.h>

#undef NDEBUG

//#define NDEBUG 1
#include <assert.h>
#include <string.h>
#include <mmsystem.h>
#include <stdlib.h>

#include "mv_from_be.h"


int
iir___60 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___170 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___310 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___600 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___1000 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___3000 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___6000 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___12000 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___14000 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);

int
iir___16000 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels);






double
inittimer2 (int value);

int adjust_fftvalue(int val)
{
if(val>100)
{
val = 100;
}
return val;
}

void
analize_fft (morcego___i___instance__a__bucaneiro_engineering *mv_______,spectrum * spec, char *buffer2, int canais, int len, __attribute__((unused)) int mult)
{
	/* //how to force errors on case of floating point problems
		_clearfp();
		unsigned unused_current_word = 0;
		// clearing the bits unmasks (throws) the exception
		_controlfp_s(&unused_current_word, _EM_UNDERFLOW, _EM_OVERFLOW | _EM_ZERODIVIDE);  // _controlfp_s is the secure version of _controlfp
	*/
	//return; 
	if(mv_______->fourier_c___enable)
	{

		iir___60 (mv_______,buffer2,len, canais);

		spec->f60=adjust_fftvalue(mv_______->iir_c___value_60);
		spec->f170=adjust_fftvalue(mv_______->iir_c___value_170);
		spec->f310=adjust_fftvalue(mv_______->iir_c___value_310);
		spec->f600=adjust_fftvalue(mv_______->iir_c___value_600);
		spec->f1000=adjust_fftvalue(mv_______->iir_c___value_1000);
		spec->f3000=adjust_fftvalue(mv_______->iir_c___value_3000);
		spec->f6000=adjust_fftvalue(mv_______->iir_c___value_6000);
		spec->f12000=adjust_fftvalue(mv_______->iir_c___value_12000);
		spec->f14000=adjust_fftvalue(mv_______->iir_c___value_14000);
		spec->f16000=adjust_fftvalue(mv_______->iir_c___value_16000);

		spec->peak=(spec->f60+
		            spec->f170+
		            spec->f310+
		            spec->f600+
		            spec->f1000+
		            spec->f3000+
		            spec->f6000+
		            spec->f12000+
		            spec->f14000+
		            spec->f16000)/10;
	}
	return;
}

int
enable_fft_ok (morcego___i___instance__a__bucaneiro_engineering *mv_______,int val)
{
	mv_______->fourier_c___enable=val;
	return 0;
}
