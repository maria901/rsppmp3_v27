/*

         ////////////////////////////////////////////////////////////////////
       //                                                                 ///
     //                     Bucaneiro Engineering 01011                 /////
    ///                                                               ///////
    /// Author        :     Morcego Vermelho                        /////////
    /// Author e-mail :     bucaneiro@go.to                       ///////////
    ///           WWW :     nomade                              ///////////
    /////////////////////////////////////////////////////////////////////

 */

#include <stdio.h>
#include <windows.h>

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

extern int setdebuginformation (char *string);

void dprintf (const char *format, ...);
/**
 * To print an internal debug information
 */
 /*
 * To print to the system debugger a string, I use it all the time
 */
void
dprintf (const char *format, ...)
{
	int rete;
	va_list args;
	static char buffer[1000000];
	int ret;
	rete = GetLastError ();
	va_start (args, format);
	ret = vsprintf (buffer, format, args);
	OutputDebugString (buffer);
	printf (buffer);
	SetLastError (rete);
	return;
}