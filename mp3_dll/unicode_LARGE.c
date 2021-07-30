
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
  
/* 02 Jun 2011 b */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>

#include "mv_from_be.h"

void check_mv_instance(__int64 mv_instance);
char *__stdcall
widetoutf8
(
        WCHAR * pUSC2
)
{
	static int position = 0;
#define THESIZE (300*6)
	if (0 == position)
	{
		static char pUTF8[THESIZE];
		position = 1;
		WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) pUTF8, THESIZE, 0,
		                     0);
		return pUTF8;
	}
	else
	{
		static char pUTF8[THESIZE];
		position = 0;
		WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) pUTF8, THESIZE, 0,
		                     0);
		return pUTF8;
	}
	return NULL;
}
char *__stdcall
widetoutf8_fixed
(
	unicode_large *ul_______,
        WCHAR * pUSC2
)
{
	if (0 == ul_______->unicode_large_c___position_utf8)
	{
		ul_______->unicode_large_c___position_utf8 = 1;
		WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) ul_______->unicode_large_c___pUTF8, THESIZE, 0,
		                     0);
		return ul_______->unicode_large_c___pUTF8;
	}
	else
	{
		ul_______->unicode_large_c___position_utf8 = 0;
		WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) ul_______->unicode_large_c___pUTF8_2, THESIZE, 0,
		                     0);
		return ul_______->unicode_large_c___pUTF8_2;
	}
	return NULL;
}
WCHAR *__stdcall
utf8towide_multithread
(
        __int64 mv_instance,
        const char *pUTF8
)
{
	morcego___i___instance__a__bucaneiro_engineering *mv_______=
	        (morcego___i___instance__a__bucaneiro_engineering*)(__INT32_OR_INT64)mv_instance;
	if(0==mv_______->unicode_large_c___position)
	{
		mv_______->unicode_large_c___position=1;
		MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, mv_______->unicode_large_c___pUSC2, 300);
		return mv_______->unicode_large_c___pUSC2;
	}
	else
	{
		mv_______->unicode_large_c___position=0;
		MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, mv_______->unicode_large_c___pUSC2_2, 300);
		return mv_______->unicode_large_c___pUSC2_2;
	}
	return NULL;
}
WCHAR *__stdcall
utf8towide_fixed
(
        unicode_large *ul_______,
        const char *pUTF8
)
{
	if(0==ul_______->unicode_large_c___position)
	{
		ul_______->unicode_large_c___position=1;
		MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, ul_______->unicode_large_c___pUSC2, 300);
		return ul_______->unicode_large_c___pUSC2;
	}
	else
	{
		ul_______->unicode_large_c___position=0;
		MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, ul_______->unicode_large_c___pUSC2_2, 300);
		return ul_______->unicode_large_c___pUSC2_2;
	}
	return NULL;
}

WCHAR *__stdcall
utf8towide
(
        const char *pUTF8
)
{
	static int position=0;
	if(0==position)
	{
		static WCHAR pUSC2[300];
		position=1;
		MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, 300);
		return pUSC2;
	}
	else
	{
		static WCHAR pUSC2[300];
		position=0;
		MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, 300);
		return pUSC2;
	}
	return NULL;
}
__int64 _ftelli64_arab (FILE * stream);
int _fseeki64_arab (FILE * stream, __int64 offset, int origin);
int
_fseeki64_arab (FILE * stream, __int64 offset, int origin)
{
#ifdef __GNUC__
	return fseeko64 ((stream), offset, origin);
#else
	return _fseeki64 ((stream), offset, origin);
#endif
}
__int64
_ftelli64_arab (FILE * stream)
{
#ifdef __GNUC__
	return ftello64 ((stream));
#else
	return _ftelli64 ((stream));
#endif
}
size_t fread_unbuffered (void *ptr, size_t size, size_t nelem, FILE * stream);
size_t
fread_unbuffered (void *ptr, size_t size, size_t nelem, FILE * stream)
{
	return fread ((ptr), size, nelem, stream);
}
size_t fwrite_unbuffered (const void *ptr, size_t size, size_t nelem,
                          FILE * stream);
size_t
fwrite_unbuffered (const void *ptr, size_t size, size_t nelem, FILE * stream)
{
	return fwrite ((ptr), size, nelem, stream);
}
