// Macro for killing denormalled numbers
//
// Written by Jezar at Dreampoint, June 2000
// http://www.dreampoint.co.uk
// Based on IS_DENORMAL macro by Jon Watte
// This code is public domain

 
#ifndef _denormals_
#define _denormals_

//will keep this for historical reasons...
//#define undenormalise(sample) if(((*(unsigned int*)&sample)&0x7f800000)==0) sample=0.0f

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value"
		
    /*
#define undenormalise(sample) \
do \
{ \
if(1.0==sample) sample=1.0; \
} while(0)
*/

#pragma GCC diagnostic pop
#endif //_denormals_

//ends
