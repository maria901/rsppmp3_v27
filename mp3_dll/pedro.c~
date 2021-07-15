
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *                                                                                *
  *      Licensa de Cópia (C) <202*>  <Corporação do Trabalho Binário>             *
  *                                                                                *
  *   Este programa é software livre: você pode redistribuir isto e/ou modificar   *
  *   isto sobre os termos do GNU Licensa Geral Pública como publicado pela        *
  *   Fundação de Software Livre, tanto a versão 3 da Licensa, ou                  *
  *   (dependendo da sua opção) qualquer versão posterior.                         *
  *                                                                                *
  *   Este programa é distribuído na esperança que isto vai ser útil,              *
  *   mas SEM QUALQUER GARANTIA; sem até mesmo a implicada garantia de             *
  *   COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
  *   Licensa Geral Pública para mais detalhes.                                    *
  *                                                                                *
  *   Você deve ter recebido uma cópia da LICENSA GERAL PUBLICA                    *
  *       e a GNU Licensa Pública Menor junto com este programa                    *
  *       Se não, veja <http://www.gnu.org/licenses/>.                             *
  *                                                                                *
  *   Suporte: https://arsoftware.net.br/binarywork ____________________           *
  *   Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/           *
  *             http://nomade.sourceforge.net/binarywork/ ______________            *
  *                                                                                *
  *       e-mails direto dos felizes programadores:                                *
  *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
  *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
  *                                                                                *
  *       contato imediato(para uma resposta muita rápida) WhatsApp                *
  *       (+55)41 9627 1708 - isto está sempre ligado                              *
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

/**
 * Function to send a formatted string to OutputDebugString that
 * can be captured by DebugView or the installed debugger
 *
 * @param amanda_level if above -1 it will show the string
 *
 * @param format the formatted string to show
 *
 */
void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
)
{
	if(-1 < amanda_level)
	{
		va_list                        tua_amanda;
		char buffer_kp  [20000];// = malloc(2000);
		va_start (tua_amanda,             format);
		vsprintf (buffer_kp, format,  tua_amanda);
		if('\n' == buffer_kp[strlen(buffer_kp)-1])
		{
			buffer_kp[strlen(buffer_kp)   -1]=' ';
		}
		strcat(buffer_kp," _amanda_debug_"      );
		OutputDebugString (buffer_kp            );
		va_end(tua_amanda                       );
		//free(buffer_kp                        );
		//someday we fix it...     this is the day
	}
	return;
}


/**
 * Function to send a formatted string to OutputDebugString as a wide string that
 * can be captured by DebugView or the installed debugger
 *
 * @param amanda_level if above -1 it will show the string
 *
 * @param format the formatted string to show
 *
 */
void pedro_dprintfW( //para imprimir wide string use %ls ok?, te amo...
	int amanda_level,
	const wchar_t *format, ...)
{
	if (-1 < amanda_level)
	{
		
#if 1

//int vswprintf (wchar_t * ws, size_t len, const wchar_t * format, va_list arg );

		wchar_t buffer[20000];
		va_list args;
		va_start(args, format);
		vswprintf(buffer, 20000, format, args);
		if ('\n' == buffer[wcslen(buffer) - 1])
		{
			buffer[wcslen(buffer) - 1] = ' ';
		}
		wcscat(buffer, L" _amanda_debug_");
		OutputDebugStringW(buffer);
		va_end(args);

#else
		wchar_t buffer[20000];
		va_list args;
		va_start(args, format);
		vswprintf(buffer, format, args);
		if ('\n' == buffer[wcslen(buffer) - 1])
		{
			buffer[wcslen(buffer) - 1] = ' ';
		}
		wcscat(buffer, L" _amanda_debug_");
		OutputDebugStringW(buffer);
		va_end(args);
#endif
	}
	return;
}
