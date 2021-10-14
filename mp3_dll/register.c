
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
 
#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif


#include <windows.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#undef NDEBUG
#include <assert.h>


//Variables

int is_registered = 0;

////////////////////////////////////////////////////////////////////////Amanda*
/* Ricardo ********************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************Alessandra*/
size_t fread_unbuffered (void *ptr, size_t size, size_t nelem, FILE * stream);
size_t fwrite_unbuffered (const void *ptr, size_t size, size_t nelem,
                          FILE * stream);
void
removespace_begin (char *path)
{

/*retira o caracter ' ' no inicio , e quantos mais tiver em sequencia*/

	int ret;
	char *ptr;

	char *ptrdesloca;

	ptrdesloca = path;
	ret = strlen (path);

	if (ret)
	{
		ptr = malloc (ret + 1);

		memset (ptr, 0, ret + 1);
//while ((c = getchar ()) == ' ' || c == '\t')
		while ((*ptrdesloca == ' ') || (*ptrdesloca == '\r')
		       || (*ptrdesloca == '\n') || (*ptrdesloca == '\t'))
		{

			ptrdesloca++;
		}


		strcpy (ptr, ptrdesloca);
		memset (path, 0, ret); //pra que isto ?
		strcpy (path, ptr);

		free (ptr);
	}
}


void
removespace_end (char *path)
{

	int ret;

inicio:

	ret = strlen (path);

	if (ret)
	{
//while ((c = getchar ()) == ' ' || c == '\t')


/*
   invertido
 */
		if ((path[(ret - 1)] == ' ') || (path[(ret - 1)] == '\r')
		    || (path[(ret - 1)] == '\n') || (path[(ret - 1)] == '\t'))
		{

			path[(ret - 1)] = 0;
			goto inicio;

		}
	}


}

void
removespace (char *data)
{
	removespace_begin (data);
	removespace_end (data);



}


char *__stdcall
create (char *name)
{
	uint crc32b (uint crc, const uchar * buf, uint len);

#define LICENSA "Alessandra Mbroczkoski Pereira"

	char a_name[1000] = { 0, };
	char b_code[300] = { 0, };

	static char out[300];

	memset (out, 0, sizeof (out));

	strcpy (a_name, name);
	strcat (a_name, LICENSA);

	removespace (a_name);

	sprintf (b_code, "%08x", crc32b (0, a_name, strlen (a_name)));

	strcpy (out, b_code);
	return out;
}

////////////////////////////////////////////////////////////////////////Amanda*
/* Ricardo ********************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************************
*******************************************************************Alessandra*/

int
main (int argc, char **argv)
{

//printf("item-%s\n",argv[1]);
	if (2 != argc)
	{
		printf ("Missing arguments\n");
		return 1;

	}

	{
		FILE *output = fopen ("lic.txt", "wb");//to never forget 1996...and Patrick

		if (output)
		{
			char temp2[2000] = { 0, };

			char *temp = create (argv[1]);


			strcpy (temp2, "Name=");
			strcat (temp2, argv[1]);
			strcat (temp2, "\r\n");
			strcat (temp2, "Code=");


			fwrite_unbuffered (temp2, 1, strlen (temp2), output);
			fwrite_unbuffered (temp, 1, strlen (temp), output);


			fclose (output);
		}

	}

	return 0;
}
