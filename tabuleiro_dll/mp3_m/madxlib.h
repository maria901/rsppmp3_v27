/****************************************************************************
   madxlib                                           (c) 2004 J. A. Robson

   Definitions file. See inline comments for details. See comments in
   source files 'madxlib.cpp' and 'test.cpp' for information on
   programming madxlib. To compile, see Makefile comments.

$Name:  $
$Date: 2005/03/04 15:03:12 $
$Revision: 1.8 $

****************************************************************************/

#ifndef _MADXLIB_H_
#define _MADXLIB_H_



// Must know where "mad.h" from libmad
// distribution is to compile:
#include "mad.h"



#define MADX_INPUT_BUFFER_SIZE	(1152*4)	//(5*1152*8)
//                              original is (1152*8)
#define MADX_OUTPUT_BUFFER_SIZE	 (1152*4)




//
// madx_read() return type. Used to
// determine action in calling code.
//

enum madx_sig
{
  ERROR_OCCURED,
  MORE_INPUT,
  FLUSH_BUFFER,
  EOF_REACHED,
  CALL_AGAIN
};






//
// Structure that "houses" all the necessary
// libmad (and other) variables. Must be
// declared in calling code and passed to
// the below functions.
//

struct madx_house
{
  struct mad_stream stream;
  struct mad_frame frame;
  struct mad_synth synth;
  mad_timer_t timer;
  unsigned long frame_cnt;
  unsigned char *output_ptr;
};





//
// Use for communication and
// control between calling
// code and "madx_read()".
//

struct madx_stat
{
  char msg[256];
  size_t write_size;
  int is_eof;
  size_t readsize;
  size_t remaining;

  // Will reference some
  // "middle part" of in_buffer:
  unsigned char *buffstart;
};




// Function exports hence




//
// Description:
//              Initialize madx structures
//
// Parameters:
//
//      *out_buffer                     Pointer to output byte array
//      *mxhouse                        Pointer to madx_house structure (declared
//                                              in user code)
//

extern "C"
__declspec (dllexport)
     int __stdcall
       madx_init (unsigned char *out_buffer, madx_house * mxhouse);






//
// Description:
//              Read input buffer, decode, fill output buffer
//
// Parameters:
//
//      *in_buffer                      Points to input byte array
//      *out_buffer                     Points to output byte array
//      *mxhouse                        Points to madx_house structure (declared
//                                              in user code)
//  *mxstat                             Points to madx_stat structure (declared
//                                      in user code)
//

     extern "C" __declspec (dllexport)
     madx_sig __stdcall
       madx_read (unsigned char *in_buffer,
		  unsigned char *out_buffer, madx_house * mxhouse,
		  madx_stat * mxstat);






//
// Description:
//              Destroy libmad variables housed in "madx_house"
//
// Parameters:
//
//      *mxhouse                        Pointer to madx_house structure (declared
//                                              in user code)
//

     extern "C" __declspec (dllexport)
     void __stdcall madx_deinit (madx_house * mxhouse);



#endif
