
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

char *
decimalparabinarioprintf (unsigned int value)
{

/*converte decimal para uma string
   binaria mas formata para impressao*/
	int i;
	unsigned int mask;

	static char fixo[255];

	memset (fixo, 0, 254);

	for (i = 31; i > -1; i--)
	{

		mask = (1 << i);

		if (mask & value)
		{
			strcat (fixo, "1");

			if ((i % 4 == 0) && i != 0)
			{
				strcat (fixo, "-");
			}

		}
		else
		{
			strcat (fixo, "0");
			if ((i % 4 == 0) && i != 0)
			{
				strcat (fixo, "-");
			}
		}


	}

	return fixo;

}


int main()
{
int eu=0;
int *ptr = &eu;
char temp[300];
char temp2[300]="olaseuburro";
short val;
temp[0]=0xff;
temp[1]=0xff;
temp[2]=0xee;
temp[3]=0x80;
ptr=temp;


//*ptr=-*ptr;
printf("valor %x %d %s\n",*ptr ,*ptr, decimalparabinarioprintf(*ptr));

printf("valor %x %d %s\n",*ptr ,*ptr, decimalparabinarioprintf(*ptr));
*ptr = (*ptr >> 8) ;
val = *ptr ;
printf("valor %x %d %s\n",*ptr ,*ptr, decimalparabinarioprintf(*ptr));

printf("valor %x %d %s\n",val ,val, decimalparabinarioprintf(val));

{
int len=0;
printf("val %d %d\n",len,len%3);

len=1;
printf("val %d %d\n",len,len%3);

len=2;
printf("val %d %d\n",len,len%3);

len=3;
printf("val %d %d\n",len,len%3);

len=4;
printf("val %d %d\n",len,len%3);
}
}
