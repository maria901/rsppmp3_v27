
// Freeverb port to XMMS.
// v0.01
//
// by Matthew Stewart-Smith
// 21/02/2001, Odemar


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
