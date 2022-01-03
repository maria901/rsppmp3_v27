//ricardo & amanda original code
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                             *
*        Licensa de C�pia (C) <2022>  <Corpora��o do Trabalho Bin�rio>        *
*                                                                             *
*     Este  programa  � software livre: voc� pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como     10
*     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da      *
*     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.        *
*                                                                             *
*     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,      *
*     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de      *
*     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral P�blica para mais detalhes.                               *
*                                                                             *
*     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa P�blica Menor junto com este programa                           *
*     Se n�o, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito r�pida) WhatsApp               *
*     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
 
#include <windows.h>
#include <stdio.h>
void morcego_string_replace(char*data,char*search_string,char*dest_string)
{
	int g;
	int p;
	int i;
	int size_of_dest=strlen(dest_string);
	int size_of_search=strlen(search_string);
	int size_of_data = strlen(data);
	int data_position=0;
	char *data_large;
	double asrc;
	double a;
	int size__;
	if (0 == size_of_search)
	{
		asrc = 1.;
	}
	else
	{
		asrc = (double) size_of_search;
	}
	a = size_of_dest / asrc;
	size__ = (int) ceil (a);//bug found on this output size calculation, please be carefull
	data_large = calloc ((size_of_data * size__) + 1, 1);
	for(i=0; i<size_of_data; i++)
	{
		if(data[i]==search_string[0])
		{
			int desloca=i;
			for(p=0; p<size_of_search; p++)
			{
				if(0==data[desloca])
				{
					//printf("Achou o erro\n");
					goto jump_inside;
				}
				if(data[desloca++]!=search_string[p])
				{
					goto jump_inside;
				}
			}
			//aqui efetua em caso de realmente achar
			for(g=0; g<size_of_dest; g++)
			{
				data_large[data_position]=dest_string[g];
				data_position++;
			}
			i+=size_of_search-1; //ta certo
		}
		else
		{
jump_inside:
			;
			data_large[data_position++]=data[i];
		}
	}
	data_large[data_position]=0;
	strcpy(data,data_large);
	free(data_large);
	return;
}
