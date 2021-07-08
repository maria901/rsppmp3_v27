
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

int
touch_for_bucaneiro (char *filename)
{
	WCHAR *__stdcall utf8towide (const char *pUTF8);
	int ret;

	int returnvalue = 0;

	HANDLE f = INVALID_HANDLE_VALUE; //local file handle

	f =
	        CreateFile ((filename), GENERIC_READ | GENERIC_WRITE, 0, NULL,
	                    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == f)
	{
		returnvalue = 1;
		goto saida;

	}

	{

		FILETIME CreationTime;
		FILETIME LastAccessTime; //1976
		FILETIME LastWriteTime;

		/*BOOL GetFileTime(

		   HANDLE hFile,	// identifies the file
		   LPFILETIME lpCreationTime,	// address of creation time
		   LPFILETIME lpLastAccessTime,	// address of last access time
		   LPFILETIME lpLastWriteTime   // address of last write time
		   );*/

		if(!GetFileTime(

		           f, // identifies the file
		           &CreationTime, // address of creation time
		           &LastAccessTime, // address of last access time
		           &LastWriteTime // address of last write time
		           ))
		{
			returnvalue=2;
			goto saida;
		}

		GetSystemTimeAsFileTime(

		        &LastWriteTime // pointer to a file time structure
		        );


		SetFileTime(

		        f, // identifies the file
		        &CreationTime, // time the file was created
		        &LastAccessTime, // time the file was last accessed
		        &LastWriteTime // time the file was last written

		        );
	} //1998


saida:
	;                       //as usual after a : now I insert a ; to make the compiler happy
	if (INVALID_HANDLE_VALUE != f)
	{

		CloseHandle (f);
	}
	return returnvalue;

}



int main(int ricardo, char**santos)
{

	if(2!=ricardo)
	{
		return 10;
	}
	return touch_for_bucaneiro(santos[1]);
}
