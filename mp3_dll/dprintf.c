//We don't know who was the original developer of this file (dprintf.c) ...then the copyright is ours

 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *                                                                                *
  *      Licensa de C�pia (C) <202*>  <Corpora��o do Trabalho Bin�rio>             *
  *                                                                                *
  *   Este programa � software livre: voc� pode redistribuir isto e/ou modificar   *
  *   isto sobre os termos do GNU Licensa Geral P�blica como publicado pela        *
  *   Funda��o de Software Livre, tanto a vers�o 3 da Licensa, ou                  *
  *   (dependendo da sua op��o) qualquer vers�o posterior.                         *
  *                                                                                *
  *   Este programa � distribu�do na esperan�a que isto vai ser �til,              *
  *   mas SEM QUALQUER GARANTIA; sem at� mesmo a implicada garantia de             *
  *   COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
  *   Licensa Geral P�blica para mais detalhes.                                    *
  *                                                                                *
  *   Voc� deve ter recebido uma c�pia da LICENSA GERAL PUBLICA                    *
  *       e a GNU Licensa P�blica Menor junto com este programa                    *
  *       Se n�o, veja <http://www.gnu.org/licenses/>.                             *
  *                                                                                *
  *   Suporte: https://arsoftware.net.br/binarywork ____________________           *
  *   Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/           *
  *             http://nomade.sourceforge.net/binarywork/ ______________            *
  *                                                                                *
  *       e-mails direto dos felizes programadores:                                *
  *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
  *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
  *                                                                                *
  *       contato imediato(para uma resposta muita r�pida) WhatsApp                *
  *       (+55)41 9627 1708 - isto est� sempre ligado                              *
  *                                                                                *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

extern double
inittimer2 (int value);

extern int setdebuginformation (char *string);

void dprintf_z (const char *format, ...);
/**
 * To print an internal debug information

void
indprintff (const char *format, ...)
{
#if 1

	{

		int rete;
		va_list args;
		static char buffer[10000];
		int ret;

		rete = GetLastError ();

		va_start (args, format);
		ret = vsprintf (buffer, format, args);

		setdebuginformation (buffer);

		SetLastError (rete);

	}
#else

	return;
#endif

}
*/
/**
 * To print to the system debugger a string, I use it all the time
 */
void
dprintf_z (const char *format, ...)
{
#ifdef AMANDA_DEBUG_MODE_____S2____
	int rete;
	va_list args;
	char buffer[20000];
	int ret;
	rete = GetLastError ();
	va_start (args, format);
	ret = vsprintf (buffer, format, args);
	OutputDebugString (buffer);
	assert(19999>strlen(buffer));
	printf (buffer);
	SetLastError (rete);
#endif
	return;

}

int __stdcall my_timer (int val, char *filter);
int __stdcall
my_timer (int val, char *filter)
{
	if (0 == val)
	{
		inittimer2 (0);
	}
	else
	{
		//dprintf_z ("tempo decorrido %f - %s\n", inittimer2 (1), filter);
	}
	return 0;
}
