
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
#include <math.h>

#include "mv_from_be.h"

/***************************************************************************/
void
set_this_thread_to_idle_17_55_23_june_2011 ()
{
	SetThreadPriority (GetCurrentThread (), -2);
}

#include "rc4.h"

int
encryptfile (char *inputfile, char *outputfile, char *password)
{
	struct rc4_state s;
	morcego___i___instance__a__bucaneiro_engineering *mv_______=calloc(sizeof(morcego___i___instance__a__bucaneiro_engineering),1);
	__int64 mv_instance=(__int64)(__INT32_OR_INT64)mv_______;
	FILE *myfile = NULL;
	FILE *outfile = NULL;
	int ret;
	char *buffer = NULL;
	int returnvalue = 0;
	if ((myfile = _wfopen (utf8towide_multithread(mv_instance,inputfile), L"rb")) == NULL)
	{
		returnvalue = 1;
		goto saida;
	}
	if ((outfile = _wfopen (utf8towide_multithread(mv_instance,outputfile), L"wb")) == NULL)
	{
		returnvalue = 2;
		goto saida;
	}
	buffer = malloc (1 << 17);//this is the best size for buffer these days
	rc4_setup (&s, (unsigned char *) password, strlen (password));
	while((ret = fread (buffer, 1, 1 << 17, myfile))>0)
	{
		int val;
		rc4_crypt (&s, (unsigned char *) buffer, ret);
		val = fwrite (buffer, 1, ret, outfile);
		if(val!=ret) //some kind of file write problem, can ocur if you remove the pen drive during the save process
		{
			returnvalue=3;
		}
	}
	;
saida:
	;
	if (buffer)
	{
		free (buffer);
	}
	if (myfile)
	{
		fclose (myfile);
	}
	if (outfile)
	{
		fclose (outfile);
	}
	free(mv_______);
	return returnvalue;
	;
}
