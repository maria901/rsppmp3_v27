
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
analize_fft (morcego___i___instance__a__bucaneiro_engineering *mv_______,spectrum * spec, char *buffer2, int canais, int len, int mult)
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
