
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

/**
   definitive checksum solution
 */
int bucaneiro32(int buc,char*buf,int len)
{
	char *temp=(char*)&buc;
	char item0 = temp[0];
	char item1 = temp[1];
	char item2 = temp[2];
	char item3 = temp[3];
	if(0==len)
	{
		return buc;
	}
	while(len--)
	{
		{

			item0 = item0 + *buf++;
			item0++;
			item1 = item1 + item0;
			item1++;
			item2 = item2 + item1;
			item2++;
			item3 = item3 + item2;
			item3++;

		}
	}
	temp[0]=item0;
	temp[1]=item1;
	temp[2]=item2;
	temp[3]=item3;
	return buc;
}

int
main ()
{

	int ret;
	int val=1000000;
	static char test[1000000]={0,};
	{

		ret = bucaneiro32(0,test,val);
		printf("val %08x\n",ret);
	}

	return 0;
}
