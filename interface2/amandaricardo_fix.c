//by amanda & ricardo 2020, workaround to avoid the circular reference problem...(as usual)
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                             *
*        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>        *
*                                                                             *
*     Este  programa  é software livre: você pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     10
*     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opção) qualquer versão posterior.        *
*                                                                             *
*     Este  programa é distribuído na  esperança que isto vai  ser útil,      *
*     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de      *
*     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Pública para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Pública Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito rápida) WhatsApp               *
*     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
 
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
