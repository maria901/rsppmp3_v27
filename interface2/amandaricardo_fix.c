//by amanda & ricardo 2020, workaround to avoid the circular reference problem...(as usual)


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
//to comment in a few minutes
double
get_bucaneiro_tick (void);
double
get_bucaneiro_tick ()
{
  abort();
	LARGE_INTEGER first;
	LARGE_INTEGER second;
	QueryPerformanceFrequency (&first);
	double a=first.QuadPart;
	QueryPerformanceCounter (&second);
	double b=second.QuadPart;
	return b / a;
}

void dprintf_z (const char *format, ...)
{
  abort();
}

WCHAR *__stdcall
utf8towide_multithread
(
        __int64 mv_instance,
        const char *pUTF8
)
{
  abort();
  return L"oi";
}

int
get_morcego_bitrate
(
        char*file,
        double seconds
)
{
  abort();
  return 0xbadc0da;
}
int
setdebuginformation_multithread
        (void * mv_______, char *string)
{
  abort();
  return 0xdeadbeef;
}
  
WCHAR *__stdcall
utf8towide_fixed
(
        void *ul_______,
        const char *pUTF8
)
{
  abort();
  return L"ola amanda eu te amo pra SEMPRE";
}
double getvalf (double maxa, double porr)
{
  abort();
  return 25.0;
}
