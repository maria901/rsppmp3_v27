//by amanda & ricardo 30-08-2020 01-27


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

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
)
{
	if(-1 < amanda_level)
	{
		va_list args;
		char *buffer_kp = malloc(20000);
		va_start (args, format);
		vsprintf (buffer_kp, format, args);
		fprintf(stdout, "%s", buffer_kp); 
		fflush(stdout);
		/*		
				if('\n' == buffer_kp[strlen(buffer_kp)-1])
				{
				buffer_kp[strlen(buffer_kp)-1]=' ';
				}
				strcat(buffer_kp," _amanda_debug_");
				OutputDebugString (buffer_kp);
		*/		
		free(buffer_kp);
		//someday we fix it...
	}
	return;
}
