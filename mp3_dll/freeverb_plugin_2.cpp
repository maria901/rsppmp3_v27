
// Freeverb port to XMMS.
// v0.01
//
// by Matthew Stewart-Smith
// 21/02/2001, Odemar
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


#include <stdio.h>
#include "revmodel.h"

// Export these functions to be accessible from the C part of the program
// containing the API / GUI code.
extern "C"
{

  extern "C" void do_reverb (float *, float *, float *, float *, long);
  void set_reverb_params (float, float, float, float, float, float);

// The reverb model object.  XXX should this be allocated with 'new'?
  revmodel rev;

  extern "C" void do_reverb (float *inputL, float *inputR, float *outputL,
			     float *outputR, long numsamples)
  {
    rev.processreplace (inputL, inputR, outputL, outputR, numsamples, 1);
  }

  void set_reverb_params (float roomsize, float damp, float wet, float dry,
			  float width, float mode)
  {
    rev.setroomsize (roomsize);
    rev.setdamp (damp);
    rev.setwet (wet);
    rev.setdry (dry);
    rev.setwidth (width);
    rev.setmode (mode);
  }

}
