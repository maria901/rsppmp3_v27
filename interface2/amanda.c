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

#include "aline_definitive_header_2_.h"

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("Libav interface2.dll " AMARIC__VERSION
		                   " - DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__
		                   ") \n");
		break;
	case DLL_THREAD_ATTACH:

		break;
	case DLL_THREAD_DETACH:

		break;
	case DLL_PROCESS_DETACH:

		break;
	}
	return TRUE;
}
