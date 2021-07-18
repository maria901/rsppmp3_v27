//ricardo & amanda original code stolen from the .net

 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://arsoftware.net.br/binarywork_____________________       *
 *     Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/       *
 *              http: //nomade.sourceforge.net/binarywork_______________/       *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     Ricardinho:    arsoftware25@gmail.com    ricardo@arsoftware.net.br       *
 *     Koci______:    arsoftware10@gmail.com    am_koci@arsoftware.net.br       *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/
 

/*
#pragma warning( disable : 4101 )
#pragma warning( disable : 4123 )
#pragma warning( disable : 4025 )
*/

#define IS_IT_OITENTA_FROM_THE_70S_AMANDA_S_SMART_APE (0b1010000)

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

#include "win64.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

#include "mv_from_be.h"

size_t fread_unbuffered (void *ptr, size_t size, size_t nelem, FILE * stream);
size_t fwrite_unbuffered (const void *ptr, size_t size, size_t nelem,
                          FILE * stream);
static char fixo_file_path[300];
WCHAR *__stdcall utf8towide (const char *pUTF8);
int chmod (const char *filename, int pmode);

extern void __cdecl dprintf_z (const char *format, ...);
extern void __cdecl dprintf2 (const char *format, ...);
extern void __cdecl replace_char_binary (char *temp, char init, char out,
                                         int len);
extern int __cdecl rsp_get_error (char *buffer);
extern void __cdecl rsp_error_print ();
extern int __cdecl checkoverflow_minuschar2 (char a, char b, char *result);
extern int __cdecl checkoverflow_minuschar (char a, char b, char *result);
extern int __cdecl checkoverflow_pluschar (char a, char b, char *result);
extern void __cdecl mprintf (char *format, ...);
extern int __cdecl fix8 (int value);
extern int __cdecl fix4 (int value);
extern int __cdecl fix2 (int value);
extern int __cdecl rspparser (char *instring, char *delimiter,
                              char *returnstring, int comand);
extern void __cdecl stripfilenameandpath_url (char *path, char *onlypath,
                                              char *onlyfilename);
extern int __cdecl stripfilenameandpath (char *path, char *onlypath,
                                         char *onlyfilename);
extern int __cdecl octaltoint (char *p);
extern char *__cdecl inttooctal (unsigned int value, int numberofitens);
static int __cdecl getbits (unsigned int value, unsigned int bit);
extern int __cdecl setbits (unsigned int value, unsigned int bit,
                            unsigned int bitvalue);
extern int __cdecl newsetbits (unsigned int value, unsigned int bit,
                               unsigned int bitvalue);
extern unsigned int __cdecl binarioparadecimal (char *binval);
extern char *__cdecl decimalparabinarioprintf (unsigned int value);
extern char *__cdecl decimalparabinario (unsigned int value);
extern char *__cdecl decimalparabinarioold (unsigned int value);
extern char __cdecl pegaultimocaracter (char *path);
extern double __cdecl inittimer2 (int value);
extern float __cdecl inittimer (unsigned int comando);
extern int __cdecl rspgetdrivetype (char *path1);
extern char *__cdecl rspgetcomputername ();
extern int __cdecl rspsetcurrentdirectory (char *path);
extern char *__cdecl rspgetcurrentdirectory ();
extern char *__cdecl rspgetsystemdirectory ();
extern char *__cdecl rspgetwindowsdirectory ();
extern char *__cdecl rspgettemppath ();
extern int __cdecl save_to_file (char *infile, char *data, int size, int mode,
                                 int limit);
extern __int64 __cdecl getfilesize (char *infile);
extern unsigned int __cdecl getval (int max, unsigned int por);
extern unsigned int __cdecl getmax (int por, unsigned int fatia);
extern unsigned int __cdecl getpor (int max, unsigned int fatia);
extern int __cdecl contastringinsensitive (char *comando, char *string);
extern int __cdecl contastringsensitive (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive_new (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal_new (char *comando,
                                                  char *string);
extern int __cdecl procuradordestringsensitive (char *comando, char *string);
extern int __cdecl procuradordestringinsensitive (char *comando,
                                                  char *string);
extern int __cdecl checkmaxsize (char *comando);
extern void __cdecl stripspace (char *intcomando);
extern void __cdecl trocadordebackslashtras (char *path);
extern void __cdecl trocadordebackslashfrente (char *path);
extern void __cdecl adicionadordebackslashtras (char *path);
extern void __cdecl adicionadordebackslashfrente (char *path);
extern void __cdecl removedordeespaconofinal (char *path);
extern void __cdecl removedordecaracternofinal (char *path, char caracter);
extern void __cdecl removedordecaracternoinicio (char *path, char caracter);
extern void __cdecl removedordeespaconoinicio (char *path);
extern void __cdecl changecharacter (char *path, char itemtosearch,
                                     char finalcharacter);
extern int __cdecl countitens (char *comand, char item);
extern void __cdecl strtolower (char *path);
extern void __cdecl strtoupper (char *path);
extern int __cdecl testdirectory (char *path);
extern int __cdecl createtestfilename (char *path1);
extern int __cdecl pathexists (char *path);
extern int __cdecl pathappearsvalid (char *path);
extern int __cdecl ispathreadonly (char *path);
extern int __cdecl ispathfolder (char *path);
extern int __cdecl ispathfile (char *path);
extern void __cdecl geterrorstringrspmakedir (int errorcode, char *path);
extern int __cdecl rspmakedirUNIX (char *destination, char *path);
extern int __cdecl rspmakedir (char *path);
extern char *__cdecl validanomedearquivoerrorstring ();
extern int __cdecl validanomedearquivo (char *path);
extern char *__cdecl validatefoldertocreateerrorstring ();
extern int __cdecl validatefoldertocreate (char *path);
extern int __cdecl rspposicaofixa (int mode, int value);
extern int __cdecl wildcardselection (const char *path, const char *string1);
char *strrstr (char *s1, char *s2);

/**
   retrieve the extension of the filename, lowercase always, or an empty string
   if no extension
   Thu May 13 17:56:03 2010
 */
int
strip_extension_alladin (char *data, char *ext)
{
	char temp[300*6];
	char *ptr = NULL;
	stripfilenameandpath (data, NULL, temp);
	ptr = strrstr (temp, ".");
	if (NULL == ptr)
	{
		strcpy (ext, "");
		return 0;
	}
	ptr++;
	strcpy (ext, ptr);
	strtolower (ext);
	return 0;
}

/**
   reverse string search, it will serch the last occurrence of the string in the string
   s1 - input string
   s2 - search string
   //Thu May 13 17:42:03 1996
 */
char *
strrstr (char *s1, char *s2)
{

	char /**sc1, */*sc2, *psc1, *ps1;

	if (*s2 == '\0')
	{
		return ((char *) s1);
	}

	ps1 = s1 + strlen (s1);

	while (ps1 != s1)
	{
		--ps1;
		for (psc1 = ps1, sc2 = s2;; )
		{
			if (*(psc1++) != *(sc2++))
			{
				break;
			}
			else if (*sc2 == '\0')
			{
				return ((char *) ps1);
			}
		}

	}
	return ((char *) NULL);
}

/**
 * It can be used for bug endian and little endian code
 */
int
invertbits32 (int value)
{

	int out;
	char *input = (char *) &value;
	char *output = (char *) &out;
	output[0] = input[3];
	output[1] = input[2];
	output[2] = input[1];
	output[3] = input[0];
	return out;
}

/**
 * big endian and little endian support code
 */
short
invertbits16 (short value)
{

	short out;
	char *input = (char *) &value;
	char *output = (char *) &out;
	output[0] = input[1];
	output[1] = input[0];

	return out;
}

/**
 * It will create a temp file , returns 0 if ok as usual
 */
int
createtempfilename (char *path1, char *destfile)
{
/*
 *
 * retorna 0 se der para criar , retorna 1 se nao der
   destfile tem o nome do arquivo
 *
 */
	int ret;
	char fixo[(300*6)];
	char path[(300*6)];

	strcpy (path, path1);

	removedordeespaconofinal (path);

	ret = strlen (path);

	if (path[ret - 1] != '\\')
	{

		path[ret] = '\\';
		path[ret + 1] = 0;

	}

	memset (fixo, 0, 254);
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	unicode_large *ul_______2=calloc(sizeof(unicode_large),1);
	WCHAR fixo_w[300]={0};

	ret = GetTempFileNameW (utf8towide_fixed(ul_______,path), L"be_", 0, fixo_w);
	free(ul_______);

	strcpy(fixo,widetoutf8_fixed(ul_______2,fixo_w));

	if (ret == 0)
	{
		free(ul_______);
		free(ul_______2);
		strcpy (destfile, "");
		return 1;
	}
	else
	{
		//DeleteFile (fixo);//can be useful, I guess

		strcpy (destfile, fixo);
		free(ul_______);
		free(ul_______2);
		return 0;
	}
	free(ul_______);
	free(ul_______2);
	return 0;

}

/**
 * It will return 1 if the file is read only
 */
int
detect_readonly_file (char *filename)
{
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	int ret;

	ret = GetFileAttributesW (utf8towide_fixed(ul_______,filename));
	if (0xffffffff != ret)
	{
		if (FILE_ATTRIBUTE_READONLY & ret)
		{
			free(ul_______);
			return 1;
		}
	}
	free(ul_______);
	return 0;
}
/**
 * Can be used to adjust the size of files, returns 0 if ok, and filename is utf-8 as usual now
 */
__int64
fix_filesize
(
        char *filename, __int64 len
)
{
	WCHAR *__stdcall utf8towide (const char *pUTF8);
	int ret;
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	int returnvalue = 0;

	HANDLE f = INVALID_HANDLE_VALUE; //local file handle

	f =
	        CreateFileW (utf8towide_fixed (ul_______,filename), GENERIC_READ | GENERIC_WRITE, 0, NULL,
	                     OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	free(ul_______);

	if (INVALID_HANDLE_VALUE == f)
	{
		returnvalue = 1;
		goto saida;

	}
	{
		LARGE_INTEGER position;
		position.QuadPart = len;
		ret =
		        SetFilePointer (f, position.LowPart, &position.HighPart, FILE_BEGIN);
	}
	if (0xFFFFFFFF != ret)
	{

		ret = SetEndOfFile (f);

		if (ret)
		{
		}
		else
		{

			returnvalue = 3;
			goto saida;

		}

	}
	else
	{
		returnvalue = 2;
		goto saida;
	}
	;
saida:
	;                       //as usual after a : now I insert a ; to make the compiler happy
	if (INVALID_HANDLE_VALUE != f)
	{

		CloseHandle (f);
	}
	return returnvalue;

}

/**
 * To replace a char with another.
 */
void
replace_char_binary (char *temp, char init, char out, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{

		if (temp[i] == init)
		{
			temp[i] = out;
		}

	}

}

/**
 * It will retrieve the last system error as a description
 */
int
rsp_get_error (char *buffer)
{
	char lpMsgBuf[260];
	int value = GetLastError ();
	int ret;

	ret = FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM |
	                     FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
	                     GetLastError (), 0, (LPTSTR) &lpMsgBuf, 256, NULL);

	if (ret && value)
	{

		replace_char_binary (lpMsgBuf, '\r', ' ', 257);

		replace_char_binary (lpMsgBuf, '\n', ' ', 257);
		sprintf (buffer, "%d %s \n", value, lpMsgBuf);

		return 1;
	}
	return 0;
	SetLastError (value);

}

/**
 * It will print to OutPutDebugString() the error
 */
void
rsp_error_print ()
{
	char lpMsgBuf[260];
	int value = GetLastError ();
	int ret;

	ret = FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM |
	                     FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
	                     GetLastError (), 0, (LPTSTR) &lpMsgBuf, 256, NULL);

	if (ret && value)
	{

		replace_char_binary (lpMsgBuf, '\r', ' ', 257);

		replace_char_binary (lpMsgBuf, '\n', ' ', 257);

		if (value > 9999 && value < 12000)
		{
#ifdef NPRINTF
			//dprintf_z ("Winsock error : %d %s \n", value, lpMsgBuf);
#endif
		}
		else
		{
#ifdef NPRINTF
			//dprintf_z ("System error : %d %s \n", value, lpMsgBuf);
#endif
		}

	}

	SetLastError (value);

}

/**
 * helper function to check for overflows
 */
int
checkoverflow_minuschar2 (char a, char b, char *result)
{

	int aa = a;
	int bb = b;
	int aresult;

	//dprintf("a e b  %d  %d \n", a, b);
	*result = a  - b;

	aresult = aa - bb;

	if ((aresult > 127) || (aresult < -128))
	{

		//dprintf("valor de aresult %d \n", aresult);

		return 1;

	}

	return 0;


}

/**
 * t check for a overflow of a char
 */
int
checkoverflow_minuschar (char a, char b, char *result)
{

/*

   *result = a - b;

   0 if ok
   1 if overflow

 */

	//dprintf("a e b  %d  %d \n", a, b);
	*result = a - b;

	if ((a < 0 && b < 0) || (a >= 0 && b >= 0))
	{

		return 0;

	}
	else
	{

		if (a >= 0 && *result >= 0)
		{
			return 0;
		}

		if (a < 0 && *result < 0)
		{
			return 0;
		}

		return 1;
	}

}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int
checkoverflow_pluschar (char a, char b, char *result)
{


/*

   *result = a + b;

   0 if ok
   1 if overflow

 */
	int fixed = (b >= 0);

	*result = a + b;

	if (a >= 0)
	{

		if (fixed)      //b >= 0
		{

			if (*result < 0)
			{
				return 1; // overflow

			}

		}

		return 0;

	}
	else
	{

		if (!fixed)     //b >= 0
		{

			if (*result >= 0)
			{
				return 1; // overflow
			}

		}

		return 0;

	}

}




////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/*somente definicoes de funcoes*/

int validatefoldertocreate (char *path);
void removedordeespaconoinicio (char *path);
void removedordeespaconofinal (char *path);
////////////////////////////////////////////////////////////////////////////////////////



/**
 * To print a printf based formatted system messagebox
 */
void
mprintf (char *format, ...)
{
// para imprimir messagebox quando necessario
//#pragma comment (lib,"user32.lib")

	{	int val                                                  ;
		va_list ammannddaa                                       ;
		char buffer                                       [20000];
		va_start                             (ammannddaa, format);
		vsprintf                             (             buffer, 
		format,                               ammannddaa        );
		val                                                      =
		MessageBox (0, buffer, "Debug", MB_OKCANCEL | MB_TOPMOST);
		va_end                               (ammannddaa        );
		if (val !=                            IDOK               )
		{
			exit (1                                             ) ;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/**
 * It will fix the value below with a multiple of 8, then if will do this to 9 it will become a 8
 */
int
fix8 (int value)
{

	int mask = ~7;

	return value & mask;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/**
 * It will fix the value to the nearest multiple of 4, then if you do it to a 5 it will become a 4
 */
int
fix4 (int value)
{

	int mask = ~3;

	return value & mask;

}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int
fix2 (int value)
{

	int mask = ~1;

	return value & mask;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/**
 * It will return the filename and the path of a url
 */
void
stripfilenameandpath_url (char *path, char *onlypath, char *onlyfilename)
{

	int                             ret;

	ret = strlen                 (path);

	if (!ret                           )
	{

		if (onlyfilename               )
		{

			strcpy (onlyfilename,   "");
		}

		if (onlypath                   )
		{

			strcpy (onlypath, "/"      );
		}
		return                          ;
	                                    }

	ret = pegaposicaoinsensitivefinal   (
	path, "/"                          );

	if (ret                             )
	{

		if (onlyfilename                )
		{
			strcpy         (onlyfilename,
			                 &path[ret]);
		}

		if (onlypath)
		{
			strcpy (onlypath, path);
			onlypath[ret] = 0;

			{

				char *temp;

				if (onlypath[0] != '/')
				{
					temp = malloc (strlen (onlypath) + 2);
					strcpy (temp, onlypath);
					strcpy (onlypath, "/");
					strcat (onlypath, temp);
					free (temp);
				}

			}


		}


	}
	else
	{

		if (onlyfilename)
		{
			strcpy (onlyfilename, path);
		}

		if (onlypath)
		{

			strcpy (onlypath, "/");
		}

	}

}

/**
 * It will returns the path and filename
 */
int
stripfilenameandpath (char *path, char *onlypath, char *onlyfilename)
{
/*
   documentacao

   path = path com path e arquivo
   onlypath = somente o path
   onlyfilename = somente o arquivo sem o path

 */
	int ret;
	int i;
	int p;
	char temp[300*6];
	char *fixo;
#if 1
	const int separator = '\\';
#else
	const int separator = '/';
#endif

	fixo = path;

	if (path == NULL)
	{

		if (onlypath != NULL)
		{
			memset (onlypath, 0, 1);
		}

		if (onlyfilename != NULL)
		{
			memset (onlyfilename, 0, 1);
		}

		return 1;
	}

	ret = strlen (path);

	if (!ret)
	{

		if (onlypath != NULL)
		{
			memset (onlypath, 0, 1);
		}

		if (onlyfilename != NULL)
		{
			memset (onlyfilename, 0, 1);
		}

		return 0;
	}

	for (i = 0; i < ret; i++)
	{

		if (path[i] == separator)
		{
			goto continua;
		}

	}

/*aqui ocorre em caso que o path nao existe ou nao tem definicao de drive*/
	if (onlypath != NULL)
	{
		memset (onlypath, 0, 1);
	}

	if (onlyfilename != NULL)
	{
		strcpy (onlyfilename, path);
	}

	return 0;

	;
continua:
	;

	strcpy (temp, path);

	p = 0;

	for (i = strlen (path); i > -1; i--)
	{

		if (temp[i] == separator)
		{
			temp[i + 1] = 0;
			break;
		}
		p++;
	}

	p = ret - p;

	fixo += p + 1;

	if (onlypath != NULL)
	{
		strcpy (onlypath, temp);
	}

	if (onlyfilename != NULL)
	{
		strcpy (onlyfilename, fixo);
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/**
 * It will convert an octal string to an int, useful for tar based software
 */
int
octaltoint (char *p)
{

	/*
	   it will convert a string with a octal number to a int
	 */
	int result = 0;
	char c;

	int ret;

	ret = strlen (p);


	if (!ret)
	{
		return 0;
	}

	while (ret--)
	{
		c = *p++;
		if (c == ' ')
			continue;
		if (c == 0)
			break;
		result = result * 8 + (c - '0');
	}
	return result;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/**
 * It will convert a uint to a octal value
 */
char *
inttooctal (uint value, int numberofitens)
{
/*
        it will convert a int value to a octal string
        with the number of 0 as definied in numberofitens
 */
	static char fixo[255];
	static char fixo2[255];
	static char final[255];

	int ret;


	memset (fixo2, 0, 254);
	memset (final, 0, 254);
	memset (fixo, 0, 254);

	// int sprintf(char *s, const char *format, ...);
	sprintf (fixo, "%o", value);

	ret = strlen (fixo);

retorno:

	if (ret < numberofitens)
	{

		strcat (fixo2, "0");

		ret = ret + 1;
		goto retorno;
	}

	strcpy (final, fixo2);
	strcat (final, fixo);

	return final;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/**
 * It will retrieve the selected bit on a 32 bits value
 */
static int
getbits (uint value, uint bit)
{
/*pega o valor do bit na posicao definida em bit*/
	int ret;
	int mask;

	if (bit > 31)
	{
		return 0;
	}

	mask = 1 << bit;
	ret = mask & value;

	if (ret)
	{
		return 1;
	}

	return 0;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/**
 * It will set the bit on a 32 bits value
 */
int
setbits (uint value, uint bit, uint bitvalue)
{
/*seta o bit na posicao definida em bit
   limitado a 32 bits
 */
	int mask;
	// int fixo = getbits (value, bit);
	if (bit > 31)
	{
		return value;
	}

	mask = 1 << bit;

	if (bitvalue == 0)
	{

		if (mask & value)
		{

			value = ~value;

			value = value | mask;

			value = ~value;

			return value;
		}

		return value;

	}
	else
	{

		return value | mask;

	}

}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/**
 * To set the bit on a faster implementation
 */
int
newsetbits (uint value, uint bit, uint bitvalue)
{
/*

   seta o bit na posicao definida em bit
   limitado a 32 bits

   Versao teoricamente mais rapida

 */
	int mask;
	int fixo = getbits (value, bit);

	if (bit > 31)
	{
		return value;
	}

	mask = 1 << bit;

	if (bitvalue == 0)
	{
		if (fixo == 1)
		{
			//return value & (~mask);

			return value ^ mask;
		}
		return value;

	}
	else
	{

		return value | mask;


	}

}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


/**
 * It will convert a biary string to an int
 */
uint
binarioparadecimal (char *binval)
{
/*
        converte string binaria para decimal
 */
	uint ret;
	uint fatia;
	uint intvalue;

	uint i = 0;
	intvalue = 0;

	ret = strlen (binval);

	for (; ret > 0; ret--)
	{
		fatia = binval[ret - 1] - 48;

		if (fatia != 0 && fatia != 1)
		{
			return 0;
		}

		intvalue = intvalue + (fatia * (1 << i));
		i++;
	}

	return intvalue;

}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/**
 * It will return a string with a binary representation on the uint value
 */
char *
decimalparabinarioprintf (uint value)
{

/*converte decimal para uma string
   binaria mas formata para impressao*/
	int i;
	uint mask;

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

char __fastcall *
decimalparabinario_64__amanda_s_smart_ape (uint64_t value, bool show_amanda_s_smart_ape_split_or_not)
{

	/*
	   converte decimal para uma string
       binaria mas formata para impressao, se desejado
    */

	int        i   ;
	uint64_t   mask;

	static     unsigned char fixo_0_amanda_s_smart_ape[IS_IT_OITENTA_FROM_THE_70S_AMANDA_S_SMART_APE];
	static     unsigned char fixo_1_amanda_s_smart_ape[IS_IT_OITENTA_FROM_THE_70S_AMANDA_S_SMART_APE];
	static     unsigned char fixo_2_amanda_s_smart_ape[IS_IT_OITENTA_FROM_THE_70S_AMANDA_S_SMART_APE];
	static     unsigned char fixo_3_amanda_s_smart_ape[IS_IT_OITENTA_FROM_THE_70S_AMANDA_S_SMART_APE];
	static     unsigned char fixo_4_amanda_s_smart_ape[IS_IT_OITENTA_FROM_THE_70S_AMANDA_S_SMART_APE];

	unsigned   char * fixo;
	unsigned   char   desl_____amanda_s_smart_ape;
	static     unsigned char position_amanda_s_smart_ape = 0;

	assert(80 == IS_IT_OITENTA_FROM_THE_70S_AMANDA_S_SMART_APE); //for safety...

	desl_____amanda_s_smart_ape = position_amanda_s_smart_ape % 5;

	if (0 == desl_____amanda_s_smart_ape)
	{
		fixo = fixo_0_amanda_s_smart_ape;
	}
	if (1 == desl_____amanda_s_smart_ape)
	{
		fixo = fixo_1_amanda_s_smart_ape;
	}
	if (2 == desl_____amanda_s_smart_ape)
	{
		fixo = fixo_2_amanda_s_smart_ape;
	}
	if (3 == desl_____amanda_s_smart_ape)
	{
		fixo = fixo_3_amanda_s_smart_ape;
	}
	if (4 == desl_____amanda_s_smart_ape)
	{
		fixo = fixo_4_amanda_s_smart_ape;
	}

	position_amanda_s_smart_ape++;

	memset(fixo, 0, sizeof(IS_IT_OITENTA_FROM_THE_70S_AMANDA_S_SMART_APE));

	for (i = 63; i > -1; i--)//what is it?...
	{

		mask = (((uint64_t)1) << i);

		if (mask & value)
		{
			strcat((void *)fixo, "1");

			if (true == show_amanda_s_smart_ape_split_or_not)
			{
				if ((i % 4 == 0) && i != 0)
				{
					strcat((void *)fixo, "-");
				}
			}

		}
		else
		{
			strcat((void *)fixo, "0");
			if (true == show_amanda_s_smart_ape_split_or_not)
			{
				if ((i % 4 == 0) && i != 0)
				{
					strcat((void *)fixo, "-");
				}
			}
		}


	}

	return (void *) fixo;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/**
 * It will return a binary string like 00101011010100101101010011010101010101011100110110
 */
char *
decimalparabinario (uint value)
{

/*
        converte um valor decimal para um string static em binario
 */
	int i;
	uint mask;

	static char fixo[255];

	// memset (fixo, 'a', 254);


	fixo[0] = 0;

	for (i = 0; i < 32; i++)
	{

		mask = (1 << (31 - i));

		if (mask & value)
		{
			fixo[i] = '1';
		}
		else
		{
			fixo[i] = '0';
		}

	}

	fixo[32] = 0;
	return fixo;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/**
 * This is an old version of the code to convert to binary string
 */
char *
decimalparabinarioold (uint value)
{

/*
        converte um valor decimal para um string static em binario
 */
	int i;
	uint mask;

	static char fixo[255];

	memset (fixo, 0, 254);

	for (i = 31; i > -1; i--)
	{

		mask = (1 << i);

		if (mask & value)
		{
			strcat (fixo, "1");
		}
		else
		{
			strcat (fixo, "0");
		}


	}

	return fixo;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/*funcao pegaultimocaracter*/
/**
 * Return the last character of the ansi string
 */
char
pegaultimocaracter (char *path)
{
	/*pega o ultimo caracter da string */
	int ret;

	ret = strlen (path);
	if (ret)
	{
		return path[ret - 1];
	}

	return 0;

}

////////////////////////////////////////////////////////////////////////////////////////


/**
 * High resolution degug timer, useful for profilling
 */
double
inittimer2 (int value)
{

	static double freq = 0;
	static LARGE_INTEGER first;
	static LARGE_INTEGER second;

	if (0 == value)
	{

		if (freq == 0)
		{

			QueryPerformanceFrequency (&first);
			freq = (double) first.QuadPart;
		}


		QueryPerformanceCounter (&first);

		return 0;


	}


	if (1 == value)
	{


		QueryPerformanceCounter (&second);

		second.QuadPart = second.QuadPart - first.QuadPart;

		return (double) second.QuadPart / freq;


	}

	return 0;


}

double
get_bucaneiro_tick (void);
double
get_bucaneiro_tick ()
{
	LARGE_INTEGER first;
	LARGE_INTEGER second;
	QueryPerformanceFrequency (&first);
	double a=first.QuadPart;
	QueryPerformanceCounter (&second);
	double b=second.QuadPart;
	return b / a;
}

////////////////////////////////////////////////////////////////////////////////////////

/*funcao de timer para debug*/
/**
 * Old mode of the timer debug function to profile, instead use the function inittimer2
 */
float
inittimer (uint comando)
{

/*

   #include <timer.h>
        inittimer(0);
        Sleep(1234);
        Sleep(25);

*/

	static uint clock1;
	static uint clock2;

	if (comando == 0)
	{
		clock1 = clock ();
	}
	else
	{

		clock2 = clock ();

		return ((float) clock2 - (float) clock1);

	}

	return 0;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


/**
 * To return the drive type
 */
int
rspgetdrivetype (char *path1)
{

	/*
	   pega o drive pelo tipo

	   DRIVE_UNKNOWN The drive type cannot be determined.
	   DRIVE_NO_ROOT_DIR The root directory does not exist.
	   DRIVE_REMOVABLE The disk can be removed from the drive.
	   DRIVE_FIXED The disk cannot be removed from the drive.
	   DRIVE_REMOTE The drive is a remote (network) drive.
	   DRIVE_CDROM The drive is a CD-ROM drive.
	   DRIVE_RAMDISK The drive is a RAM disk.

	 */

	char path             [261];

	if (!strlen         (path1))
	{
		return               -1;
	}

	strcpy (path,        path1);

	if (strlen (path) <       3)
	{
		return               -1;
	}

	path[3]              =    0;

	if (tolower (path[0]) < 'a')
	{
		return -1;
	}

	if (tolower (path[0]) > 'z')
	{
		return -1;
	}

	if (path[1] !=          ':')
	{
		return               -1;
	}

	if (path[2]         != '\\')
	{
		return               -1;
	}

	return GetDriveType  (path);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////2021
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////z

/*
   char *
   rspgetusername ()
   {
     int rico = 258;
   static char temp[258];
   memset (temp, 0, 258);

   GetUserName ((LPTSTR) temp, (LPDWORD) & rico);

   return temp;

   }
 */

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
rspgetcomputername ()
{
	int rico = 261;
	static char temp[261];
	memset (temp, 0, 261);

	GetComputerName ((LPTSTR) temp, (LPDWORD) &rico);

	return temp;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int
rspsetcurrentdirectory (char *path)
{
/*
   seta o diretorio corrente
   retorna 0 se der certo
   retorna 1 se der errado

 */

	int ret;
//If the function succeeds, the return value is nonzero.
	ret = SetCurrentDirectory (path);

	if (ret)
	{
		return 0;
	}

	return 1;


}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
rspgetcurrentdirectory ()
{
	/*
	   use o e ao inves de k
	 */
/*pega o diretorio corente*/
	static char temp[261];
	memset (temp, 0, 254);
	GetCurrentDirectory (261, temp);
	return temp;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
rspgetsystemdirectory ()
{

	static char temp[261];
	memset (temp, 0, 254);
	GetSystemDirectory (temp, 261);
	return temp;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

char *
rspgetwindowsdirectory ()
{

	static char temp[261];

	memset (temp, 0, 254);
	GetWindowsDirectory (temp, 261);

	return temp;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


void
rspgettemppath_multithread (char*path)
{

	WCHAR out[300];
	GetTempPathW (261, out);
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	strcpy(path,widetoutf8_fixed(ul_______, out));

	free(ul_______);
	return ;

}



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

//#ifdef rsptest
//
//int
//main9 ()
//{
///*
//
//DWORD GetFullPathName(
//  LPCTSTR lpFileName,  // pointer to name of file to find path for
//  DWORD nBufferLength, // size, in characters, of path buffer
//  LPTSTR lpBuffer,     // pointer to path buffer
//  LPTSTR *lpFilePart   // pointer to filename in path
//);
//
//
//*/
//
//   char path[261];
//   char *ifile;
//
//   GetFullPathName ("c:\\back2", 261, path, &ifile);
//
//   printf ("path e file %s %s \n", path, ifile);
//   printf ("Linha %d %s %s \n", __LINE__, __TIME__, __FILE__);
//
//}
//
//
//#endif

/**
 * It will save or append to a file the data information, if mode == 1 it will append
 */
int
save_to_file_multithread (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *infile, char *data, int size, int mode, int limit)
{

#define _S_IWRITE       0000200 /* write permission, owner */

	__int64 ret;

	FILE *myfile = NULL;
	char modo[20] = "wb";
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
	__int64 mv_instance=(__int64)(__INT32_OR_INT64)mv_______;
#pragma GCC diagnostic pop
	if (0 == mode)
	{
		strcpy (modo, "wb");
	}
	if (1 == mode)
	{
		strcpy (modo, "ab");
	}

	ret = chmod (infile, _S_IWRITE);

	ret = getfilesize (infile);

	if (ret && limit)
	{
		if (ret > limit)
		{
			unlink (infile);
		}
	}

	if ((myfile = _wfopen (utf8towide_multithread/*ok*/ (mv_instance,infile), utf8towide_multithread (mv_instance,modo))) == NULL)
	{
		return 1; // Cannot open file to save
	}
	
	ret = fwrite_unbuffered (data, 1, size, myfile);

	if (ret != size)
	{
		fclose (myfile);
		return 2;
	}

	fclose (myfile);
	return 0;
}
int
save_to_file (char *infile, char *data, int size, int mode, int limit)
{

#define _S_IWRITE       0000200 /* write permission, owner */

	__int64 ret;

	FILE *myfile = NULL;
	char modo[20] = "wb";
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);

	if (0 == mode)
	{
		strcpy (modo, "wb");
	}
	if (1 == mode)
	{
		strcpy (modo, "ab");
	}

	ret = chmod (infile, _S_IWRITE);

	ret = getfilesize (infile);

	if (ret && limit)
	{

		if (ret > limit)
		{

			unlink (infile);

		}

	}

	if ((myfile = _wfopen (utf8towide_fixed (ul_______,infile), utf8towide_fixed (ul_______,modo))) == NULL)
	{
		free(ul_______);
		return 1;
	}
	ret = fwrite_unbuffered (data, 1, size, myfile);
	if (ret != size)
	{
		fclose (myfile);
		free(ul_______);
		return 2;
	}
	fclose (myfile);
	free(ul_______);
	return 0;
}

//"Amanda0"
int __fastcall
save_to_file_amanda_s_smart_ape (char *data, int size, enum Amanda Amanda_mode)
{

     FILE * myfile = NULL;
     char   modo[20] = "wb";

     /*

       MARIA_CREATE_NEW_LOG___ = 1001,
       MARIA_APPEND_TO__LOG___ = 0,    

     */
     if (MARIA_CREATE_NEW_LOG___ == Amanda_mode)
     {
	  strcpy (modo, "wb");
     }
     if (MARIA_APPEND_TO__LOG___ == Amanda_mode)
     {
	  strcpy (modo, "ab");
     }

     if ((myfile = fopen ("Amanda.log", modo)) == NULL)
     {
	  return 1;
     }
  
     fwrite (data, 1, strlen(data), myfile);

     fclose (myfile);
	
     return 0;
}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/*funcao de pegar tamanho de arquivo*/
__int64 _ftelli64_arab (FILE * stream);
int _fseeki64_arab (FILE * stream, __int64 offset, int origin);
/**
 * It will returns the size of the utf-8 encoded filename
 */
__int64
getfilesize (char *infile)
{
	__int64 ret;
	FILE *myfile;

	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	if ((myfile = _wfopen (utf8towide_fixed (ul_______,infile), L"rb")) == NULL)
	{
		//dprintf          ("The file 'data' was not opened\n");
		free(ul_______);
		return 0;
	}
	else
	{
		//dprintf          ("The file 'data' was opened\n");
	}

	ret = _fseeki64_arab (myfile, 0, SEEK_END);

	ret = _ftelli64_arab (myfile);

	// dprintf          ("tamanho do arquivo %d\n ", ret);

	fclose (myfile);

	// printf ("Tamanho do arquivo %s  %d \n", infile, ret);
	free(ul_______);
	return ret;


}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


/**
 * aqui o codigo recebe o maximo , entra com
   uma porcentagem e pega o valor referente a
   porcentagem passada
 *
 * max = 10000 por = 70 result = 7000
 *
 */
uint
getval (int max, uint                         por)
{

	// a formula aqui é
	// max / 100 * por

	double                                   maxa;
	double                                   porr;

	maxa =                           (double) max;
	porr =                           (double) por;

	maxa = (maxa / 100)                    * porr;

	return (uint)                            maxa;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////2021
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////z

/**
 * (maxa / 100) * porr;
 */
double
getvalf (double maxa, double porr)
{

	// a formula aqui é
	// max / 100 * por




	maxa = (maxa / 100) * porr;

	return maxa;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////




/**
 * a formula aqui é (fatia/porcentagem) * 100
 *
 * por = 50 fatia = 100 result = 200 or not, correct me if I am wrong
 *
 * basicamente é para saber o maximo a partir da fatia e da porcentagem
 * sera pouco utilizada esta funcao, ou não
 *
 * by MathMan and amanda 2021
 *
 */
uint                            // pegar o maximo a partir da porcentagem
getmax (int por, uint fatia)
{

	float a;
	float b;

	a = (float) por;
	b = (float) fatia;

	if (por == 0)
	{
		return 0;
	}

	a = (b / a) * (float) 100;



	return (uint) a;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


/*funcao de porcentagem*/

/**

   a formula aqui é (100/max * fatia)
   aqui é para saber a porcentagem referente ao
   valor passado em relacao ao maximo

   max = 10000
   fatia = 5000

 */
uint
getpor (int max, uint fatia)
{
/*

   2/27/2004 12:13PM modificacao para evitar divisao por 0

 */

	double maxa;
	double fatiaa;

	maxa = (double) max;
	fatiaa = (double) fatia;

	if (max == 0 || fatia == 0)
	{
		return 0;
	}

	maxa = ((double) 100 / maxa * fatiaa);

	return (uint) maxa;

}



double
getporf (double maxa, double fatiaa)
{
/*

   2/27/2004 12:13PM modificacao para evitar divisao por 0

 */



	if (maxa == 0 || fatiaa == 0)
	{
		return 0;
	}

	maxa = ((double) 100 / maxa * fatiaa);

	return maxa;

}

// ///////////////////////////////////////////////////////////////////////////////////////////////////////2021/ //

int
contastringinsensitive (char *comando,          char *string)
{
/*
 * retorna a contagem de strings achada 15/1/1992 10:06:27 AM
 */

	char                                  *intcomando = NULL;
	int                                           ret =  -1 ;
	int                                       sizeret       ;
	int                                             i       ;
	int                                             b       ;
	int                                             d       ;

//  mprintf ("Funcao invalida ,   com erro de parametro\n" );

// /////////////////////////////////////////////////Ricardo//////////////////////////////////////////////////// //
// /////////////////////////////////////////////////Amanda.//////////////////////////////////////////////////// //

	d                                                 =  0  ;

	intcomando = malloc (strlen (comando)             +  2 );

	strcpy (intcomando, comando                            );

	ret = strlen (intcomando                               );

	sizeret = strlen (string                               );

	if (sizeret > ret                                       )
	{

		free (intcomando                                   );

		return                                           0  ;
	}

	if (ret && sizeret)
	{
/*
 * aqui vai o codigo my love...
 */
		for (i = 0; i < ret; i++)
		{

			if (tolower (intcomando[i]) == tolower (string[0]))
			{
// dprintf          ("Ta escaneando 1 \n");

				for (b = 0; b < sizeret; b++)
				{
// dprintf          ("Ta escaneando 2 \n");
					if ((tolower (intcomando[i + b]) != tolower (string[b])))
					{
						goto continua;
					}

				}
				d++;

			}
			;
continua:
			;

		}
		free (intcomando);
		return d;

	}
	else
	{
		free (intcomando);
		return d;
	}
	;
	free (intcomando);
	return d;
	;

	;
	free (intcomando);
	return d;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int
contastringsensitive (char *comando, char *string)
{

/*
 * * retorna a contagem de strings achada 15/1/2004 12:52
 */

	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int b;
	int d;

// //////////////////////////////////////////////////////////////////////////////////////////////////////2021// //
// //////////////////////////////////////////////////////////////////////////////////////////////////////////// //

	d = 0;

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);

		return 0;
	}
	if (ret && sizeret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{
			if ((intcomando[i]) == (string[0]))
			{
// dprintf          ("Ta escaneando 1 \n");

				for (b = 0; b < sizeret; b++)
				{
// dprintf          ("Ta escaneando 2 \n");
					if (((intcomando[i + b]) != (string[b])))
					{
						goto continua;
					}

				}
				d++;
			}
			;
continua:
			;

		}


		free (intcomando);
		return d;

	}
	else
	{

		free (intcomando);
		return d;
	}
	;


	free (intcomando);
	return d;
	;

	;

	free (intcomando);
	return d;



}

/******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
******************************************************************************************/


/*acho que da certo

   basta colocar a posicao salvada e pronto
   como é duro validar codigo nao é mesmo ?

 */


int
pegaposicaoinsensitivefinal (char *comando, char *string)
{
/*
 * retorna a posicao em que achar o item ou 0 se nao achar
 */


	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int b;
	int c;
	int pos = 0;
// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

	c = 0;

	//dprintf("Tamanho de entrada %d \n", strlen (comando));

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}

	/*
	   __asm
	   {

	   int 3;

	   }
	 */




	if (ret && sizeret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{
			c = i;
			if (tolower (intcomando[i]) == tolower (string[0]))
			{
// dprintf          ("Ta escaneando 1 \n");

				for (b = 0; b < sizeret; b++)
				{
// dprintf          ("Ta escaneando 2 \n");
					if ((tolower (intcomando[i + b]) != tolower (string[b])))
					{
						goto error1;
					}

				}


				if (b == sizeret)
				{

					pos = i + 1;

				}

error1:
				continue;
			}
		
		}

		free (intcomando);
		return pos;

	}
	else
	{

		free (intcomando);
		return 0;
	}

	free (intcomando);
	return 0;

	free (intcomando);
	return c + 1;
}

int
pegaposicaosensitivefinal (char *comando, char *string)
{
/*
 * retorna a posicao em que achar o item ou 0 se nao achar
 */


	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int b;
	int c;
	int pos = 0;
// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

	c = 0;

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}

	/*
	   __asm
	   {

	   int 3;

	   }
	 */




	if (ret && sizeret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{
			c = i;
			if ((intcomando[i]) == (string[0]))
			{
// dprintf          ("Ta escaneando 1 \n");

				for (b = 0; b < sizeret; b++)
				{
// dprintf          ("Ta escaneando 2 \n");
					if (((intcomando[i + b]) != (string[b])))
					{
						goto error1;
					}

				}


				if (b == sizeret)
				{

					pos = i + 1;

				}

error1:
				continue;
			}

		}

		free (intcomando);
		return pos;

	}
	else
	{

		free (intcomando);
		return 0;
	}

	free (intcomando);
	return 0;

	free (intcomando);
	return c + 1;
}

int
pegaposicaoinsensitive (char *comando, char *string)
{
/*
 * retorna a posicao em que achar o item ou 0 se nao achar
 */


	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int b;
	int c;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

	c = 0;

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}
	if (ret && sizeret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{
			c = i;
			if (tolower (intcomando[i]) == tolower (string[0]))
			{
// dprintf          ("Ta escaneando 1 \n");

				for (b = 0; b < sizeret; b++)
				{
// dprintf          ("Ta escaneando 2 \n");
					if ((tolower (intcomando[i + b]) != tolower (string[b])))
					{
						goto continua;
					}

				}
				goto achou;
			}
			;
continua:
			;

		}


		free (intcomando);
		return 0;

	}
	else
	{

		free (intcomando);
		return 0;
	}
	;


	free (intcomando);
	return 0;
	;
achou:
	;


	free (intcomando);
	return c + 1;
}


/*HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH*/



int
pegaposicaosensitive (char *comando, char *string)
{

/*
 * retorna a posicao que achou ou 0 se nao achar 15/1/2004 12:51
 */


	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int b;
	int c;
// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


	c = 0;

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}

	if (ret && sizeret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{
			c = i;
			if ((intcomando[i]) == (string[0]))
			{
// dprintf          ("Ta escaneando 1 \n");

				for (b = 0; b < sizeret; b++)
				{
// dprintf          ("Ta escaneando 2 \n");
					if (((intcomando[i + b]) != (string[b])))
					{
						goto continua;
					}

				}
				goto achou;
			}
			;
continua:
			;

		}


		free (intcomando);
		return 0;

	}
	else
	{


		free (intcomando);
		return 0;
	}
	;


	free (intcomando);
	return 0;
	;
achou:
	;


	free (intcomando);
	return c + 1;



}


int
pegaposicaosensitive_new (char *comando, char *string)
{

/*
 * retorna a posicao que achou ou 0 se nao achar 15/1/2004 12:51
 */

	char *intcomando;
	int ret;
	int sizeret;
	int c;

// ////////////////////////////////////////////////////////////////////////////////////////////////////////2021 //
// //////////////////////////////////////////////////////////////////////////////////////////////////////////// /z

	c = 0;

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}

	if (ret && sizeret)
	{


		__INT32_OR_INT64 pos; //__INT32_OR_INT64 defined in win64.h

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
		if ((pos = (__INT32_OR_INT64) strstr (intcomando, string)))
		{
#pragma GCC diagnostic pop
			__INT32_OR_INT64 ret;
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
			__INT32_OR_INT64 address = (__INT32_OR_INT64) &intcomando[0];
#pragma GCC diagnostic pop
			if (pos)
			{
				ret = pos - address;

				// dprintf          ("Item pego em %d \n", ret);
				c = ret;
				goto achou;

			}

		}


	}



	free (intcomando);
	return 0;
	;
achou:
	;


	free (intcomando);
	return c + 1;



}


int
pegaposicaosensitivefinal_new (char *comando, char *string)
{

/*
 * retorna a posicao que achou ou 0 se nao achar 15/1/2004 12:51
 */


	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int c;
	
// ////////////////////////////////////////////////////////////////////////////////////////////////////////2021 //
// //////////////////////////////////////////////////////////////////////////////////////////////////////////// /z

	c = 0;

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}

	if (ret && sizeret)
	{

		__INT32_OR_INT64 pos;

/*temos duas strings e vaos fazer a procura e fim de papo*/
//len = 3 entao  0 1 2+0
		for (i = ret; i + 1; i--)
		{
			//it is working
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
			if ((pos = (__INT32_OR_INT64) (void *)strstr (&intcomando[i], string)))
			{

				__INT32_OR_INT64 ret;
				__INT32_OR_INT64 address = (__INT32_OR_INT64) &intcomando[0];
#pragma GCC diagnostic pop
				if (pos)
				{
					ret = pos - address;

					// dprintf          ("Item pego em %d \n", ret);
					c = ret;
					goto achou;

				}

			}
		}

	}

	free (intcomando);
	return 0;
	
achou:
	;

	free (intcomando);
	return c + 1;

}



/* HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHz
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
 */



int
procuradordestringsensitive (char *comando, char *string)
{

/*procura a string , retorna 1 se achar ou 0 se nao*/

	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int b;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}
	if (ret && sizeret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{

			if ((intcomando[i]) == (string[0]))
			{
// dprintf          ("Ta escaneando 1 \n");

				for (b = 0; b < sizeret; b++)
				{
// dprintf          ("Ta escaneando 2 \n");
					if (((intcomando[i + b]) != (string[b])))
					{
						goto continua;
					}

				}
				goto achou;
			}
			;
continua:
			;

		}


		free (intcomando);
		return 0;

	}
	else
	{


		free (intcomando);
		return 0;
	}
	;



	free (intcomando);
	return 0;
	;
achou:
	;


	free (intcomando);
	return 1;


}

int
procuradordestringinsensitive (char *comando, char *string)
{

/*procura a string , retorna 1 se achar ou 0 se nao*/

	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int b;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);
	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}

	if (ret && sizeret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{

			if (tolower (intcomando[i]) == tolower (string[0]))
			{


				for (b = 0; b < sizeret; b++)
				{

					if ((tolower (intcomando[i + b]) != tolower (string[b])))
					{
						goto continua;
					}

				}
				goto achou;
			}
			;
continua:
			;

		}


		free (intcomando);
		return 0;

	}
	else
	{


		free (intcomando);
		return 0;
	}
	;



	free (intcomando);
	return 0;
	;
achou:
	;


	free (intcomando);
	return 1;


}


/*HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH*/


/*
 * checa o tamanho maximo da string
 */
int
checkmaxsize (char *comando)
{

	if (strlen (comando) > 490)
	{
		return 1;

	}
	else
	{
		return 0;
	}

}


void
stripchar (char *intcomando, char caracter)
{

/*remover de qualquer espao na string*/


	int ret;

	int i;

	char *saida;




	int deslocador = 0;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


	saida = malloc (strlen (intcomando) + 100);



	memset (saida, 0, strlen (intcomando) + 100);

	ret = strlen (intcomando);



	if (ret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{

			if (intcomando[i] != caracter)
			{

				saida[deslocador] = intcomando[i];
				deslocador++;
			}

		}





	}

	strcpy (intcomando, saida);

	free (saida);
	saida = NULL;

}




void
stripspace (char *intcomando)
{

/*remover de qualquer espao na string*/


	int ret;

	int i;

	char *saida;




	int deslocador = 0;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


	saida = malloc (strlen (intcomando) + 100);



	memset (saida, 0, strlen (intcomando) + 100);

	ret = strlen (intcomando);



	if (ret)
	{
/*
 * aqui vai o codigo
 */
		for (i = 0; i < ret; i++)
		{

			if (intcomando[i] != ' ')
			{

				saida[deslocador] = intcomando[i];
				deslocador++;
			}

		}





	}

	strcpy (intcomando, saida);

	free (saida);
	saida = NULL;

}









/******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
******************************************************************************************/



void
trocadordebackslashtras (char *path)
{
/*
 * troca o backslash de / para \
 *
 */
	int ret;

	char aqui;

	int i;

	ret = strlen (path);

	if (ret)
	{


		for (i = 0; i < ret; i++)
		{

			aqui = path[i];
			if (aqui == '/')
			{
				path[i] = '\\';
			}

		}

	}

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
trocadordebackslashfrente (char *path)
{
/*
 * troca o backslash de \ para /
 *
 */
	int ret;

	char aqui;

	int i;

	ret = strlen (path);

	if (ret)
	{
/*
 * executa
 */

		for (i = 0; i < ret; i++)
		{

			aqui = path[i];
			if (aqui == '\\')
			{
				path[i] = '/';
			}

		}

	}

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
adicionadordebackslashtras (char *path)
{
/*
 * adiciona o character \ no final da string
 */
	int ret;

	ret = strlen (path);

	if (ret)
	{

		if (path[(ret - 1)] != '\\')
		{
			path[ret] = '\\';
			path[ret + 1] = 0;
		}

	}

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
adicionadordebackslashfrente (char *path)
{
/*
 * adiciona o character / no final da string
 */
	int ret;
	ret = strlen (path);


	if (ret)
	{

		if (path[(ret - 1)] != '/')
		{
			path[ret] = '/';
			path[ret + 1] = 0;
		}

	}


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
removedordeespaconofinal (char *path)
{
/*
 * vai remover os itens no final que sao ' ' e quantos mais tiver
 */

	int ret;

inicio:

	ret = strlen (path);

	if (ret)
	{

		if (path[(ret - 1)] == ' ')
		{

			path[(ret - 1)] = 0;
			goto inicio;

		}
	}


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
removedordecaracternofinal (char *path, char caracter)
{
/*
 * vai remover os itens no final que sao o caracter
   mas vai retirar um unico item

 */

	int ret;



	ret = strlen (path);

	if (ret)
	{

		if (path[(ret - 1)] == caracter)
		{

			path[(ret - 1)] = 0;
// goto inicio;

		}
	}


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////



void
removedordecaracternoinicio (char *path, char caracter)
{

/*vai remover no inicio os caracters que sao o caracter
   mas tira somente um unico item*/
	int ret;
	char *ptr;

	char *ptrdesloca;

	ptrdesloca = path;
	ret = strlen (path);

	if (ret)
	{
		ptr = malloc (ret + 1);

		memset (ptr, 0, ret + 1);

		if (*ptrdesloca == caracter)
		{
// assim vai tirar um unico item
			ptrdesloca++;
		}


		strcpy (ptr, ptrdesloca);
		memset (path, 0, ret);
		strcpy (path, ptr);

		free (ptr);
	}
}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
removedordeespaconoinicio (char *path)
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

		while (*ptrdesloca == ' ')
		{

			ptrdesloca++;
		}


		strcpy (ptr, ptrdesloca);
		memset (path, 0, ret);
		strcpy (path, ptr);

		free (ptr);
	}
}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
changecharacter (char *path, char itemtosearch, char finalcharacter)
{
/*
 * changecharacter , funcao para trocar caracteres numa string
 * itemtosearch , caracter para ser procurado e trocado finalcharacter
 * , character final a ser usado
 */



	int ret;

	ret = strlen (path);

	if (ret)
	{
		int i;
		for (i = 0; i < ret; i++)
		{

			if (path[i] == itemtosearch)
			{
				path[i] = finalcharacter;
			}

		}

	}

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


int
countitens (char *comand, char item)
{
/*

   contador de itens , deve ser usada a funcao
   contastringsensitive ou
   contastringinsensitive , porque sao mais novas

 */

	int ret;
	int i;
	int counter;

	counter = 0;

	ret = strlen (comand);

	if (!ret)
	{
		return 1;

	}

	for (i = 0; i < ret; i++)
	{
		if (comand[i] == item)
		{
			counter++;
		}

	}

	return counter;

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
strtolower (char *path)
{
/*
 * funcao para passar um tolower na string inteira
 */
	int ret;
	int i;
	ret = strlen (path);
	if (ret)
	{
		for (i = 0; i < ret; i++)
		{
			path[i] = tolower (path[i]);
		}
		return;
	}
}

void
strtoupper (char *path)
{
/*
 * funcao para passar um toupper na string inteira
 */
	int ret;
	int i;

	ret = strlen (path);

	if (ret)
	{
		for (i = 0; i < ret; i++)
		{

			path[i] = toupper (path[i]);


		}

		return;

	}


}



// /////////////////////

// #define dprintf printf


/*
 * declaracoes
 */

void removedordeespaconofinal (char *path);

int contastringinsensitive (char *comando, char *string);

/*
 * aprovado para uso interno
 */
int
testdirectory (char *path)
{
/*

   Esta funcao nao deve ser usada , ja que a funcao pathexist e ispathfolder
   usam uma diferente implementacao desta funcao
   e mais profissional
   Deve ser usada somente se as outras nao funcionarem , mas felizmente funcionam
   Retorna 1 se der certo e o path existir , retorna 0 se nao for
   valido o path
   15/1/2004 13:03
 */

	char fixo[261];
	int ret2 = 0;

	GetCurrentDirectory (261,   fixo);

	ret2 = SetCurrentDirectory (path);

	SetCurrentDirectory        (fixo);

	if (ret2)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


/*
 * aprovado , para uso interno
 */
int
createtestfilename (char *path1)
{
/*
 *
 * retorna 1 se der para criar , retorna 0 se nao der
   o arquivo é deletado na finalizacao

 *
 */
	int ret;
	char fixo[261];

	char path[261];


	strcpy (path, path1);



	removedordeespaconofinal (path);

	ret = strlen (path);

	if (path[ret - 1] != '\\')
	{

		path[ret] = '\\';
		path[ret + 1] = 0;

	}

	memset (fixo, 0, 254);
	ret = GetTempFileName (path, "rsp", 0, fixo);




	if (ret == 0)
	{

		return 0;
	}

	else
	{
		DeleteFile (fixo);
		return 1;
	}


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

/*
 * aprovado
 */
int
pathexists (char *path)
{
/*
 *
 * retorna 1 se existir um diretorio ou arquivo no destino retorna 0 se
 * der erro ou o path ou arquivo nao existir
   15/1/2004 13:03
 *
 */

	char x[1000];
	int ret;

	strcpy (x, path);

	ret = strlen (x);


	if (!ret)
	{
		return 0;
	}

	if (ret < 2)
	{
		return 0;
	}


	if (x[0] == '\\' && x[1] == '\\')
	{

		goto UNC;
	}



	if (tolower (x[0]) < 'a')
	{
		return 0;

	}

	if (tolower (x[0]) > 'z')
	{
		return 0;

	}

	if (tolower (x[1]) != ':')
	{
		return 0;
	}









UNC:

	if (0xffffffff != GetFileAttributes (x))
	{

		return 1;
	}
	else
	{
		return 0;
	}

}


int
pathappearsvalid (char *path)
{
/*
 *
 * retorna 1 se parecer valido  1/14/2005 2:04PM
 *
 *
 */

	char x[1000];
	int ret;

	strcpy (x, path);

	ret = strlen (x);


	if (!ret)
	{
		return 0;
	}

	if (ret < 2)
	{
		return 0;
	}


	if (x[0] == '\\' && x[1] == '\\')
	{

		return 1;       // parece UNC

	}



	if (tolower (x[0]) < 'a')
	{
		return 0;

	}

	if (tolower (x[0]) > 'z')
	{
		return 0;

	}

	if (tolower (x[1]) != ':')
	{
		return 0;
	}

	return 1;


}



// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

int
ispathreadonly (char *path)
{
/*
 * retorna -1 se o path for invalido e der erro retorna 1 se for read
 * only retorna 0 se nao for
   15/1/2004 13:04
 */

	char x[1000];
	int ret;

	strcpy (x, path);

	ret = strlen (x);

	if (!ret)
	{
		return -1;
	}

	if (ret < 2)
	{
		return -1;
	}

	if (x[0] == '\\' && x[1] == '\\')
	{

		goto UNC;
	}



	if (tolower (x[0]) < 'a')
	{
		return -1;

	}

	if (tolower (x[0]) > 'z')
	{
		return -1;

	}

	if (tolower (x[1]) != ':')
	{
		return -1;
	}

UNC:

	ret = GetFileAttributes (x);
	if (0xffffffff != ret)
	{

		if (FILE_ATTRIBUTE_DIRECTORY & ret)
		{

			if (createtestfilename (x))
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return -1;
		}

	}
	else
	{


		return -1;
	}



}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


/*
 * aprovado
 */
int
ispathfolder (char *path)
{
/*
 * retorna 1 se o path existir e for diretorio , 0 se for arquivo ou invalido path
 */
/*15/1/2004 13:05*/

	char x[1000];
	int ret;
	strcpy (x, path);
	ret = strlen (x);

	if (!ret)
	{
		return 0;
	}

	if (ret < 2)
	{
		return 0;
	}

	if (x[0] == '\\' && x[1] == '\\')
	{

		goto UNC;
	}

	if (tolower (x[0]) < 'a')
	{
		return 0;

	}

	if (tolower (x[0]) > 'z')
	{
		return 0;

	}

	if (tolower (x[1]) != ':')
	{
		return 0;
	}


UNC:
	;
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	ret = GetFileAttributesW (utf8towide_fixed(ul_______,x));
	free(ul_______);
	if (0xffffffff != ret)
	{

		if (ret & (FILE_ATTRIBUTE_DIRECTORY))
		{

			return 1;
		}
		else
		{
			return 0;
		}

	}
	else
	{
		return 0;
	}

}

// //////////////////////////////////////////////////////////////////////////////////////



int
ispathfilepartial (char *path)
{
/*
 * retorna 1 se for arquivo e 0 se der erro ou for path ou for invalido
 */

	char x[1000];
	int ret;
	strcpy (x, path);
	ret = strlen (x);

	if (!ret)
	{
		return 0;
	}

	ret = GetFileAttributes (x);


	if (0xffffffff != ret)
	{

		if (ret & (FILE_ATTRIBUTE_DIRECTORY))
		{

			return 0;
		}
		else
		{
			return 1;
		}

	}
	else
	{
		return 0;
	}


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


// //////////////////////////////////////////////////////////////////////////////////////


int
ispathfile (char *path)
{
/*
 * retorna 1 se for arquivo e 0 se der erro ou for path ou for invalido
 */

	char x[1000];
	int ret;
	strcpy (x, path);
	ret = strlen (x);

	if (!ret)
	{
		return 0;
	}

	if (ret < 2)
	{
		return 0;
	}

	if (x[0] == '\\' && x[1] == '\\')
	{

		goto UNC;
	}

	if (tolower (x[0]) < 'a')
	{
		return 0;

	}

	if (tolower (x[0]) > 'z')
	{
		return 0;

	}

	if (tolower (x[1]) != ':')
	{
		return 0;
	}

UNC:
	;
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	ret = GetFileAttributesW (utf8towide_fixed(ul_______,x));
	free(ul_______);

	if (0xffffffff != ret)
	{

		if (ret & (FILE_ATTRIBUTE_DIRECTORY))
		{

			return 0;
		}
		else
		{
			return 1;
		}

	}
	else
	{
		return 0;
	}


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
geterrorstringrspmakedir (int errorcode, char *path)
{
/*

   esta funcao pega uma string referente a utilizacao da
   funcao rsomakedir

   com esta descricao é possivel saber qual foi o erro que
   impossibilitou a cracao do diretorio
   15/1/2004 13:06


 */
	switch (errorcode)
	{
	case 0:
		strcpy (path, "No error\0");
		return;
	case 1:
		strcpy (path, "Path is empty");
		return;
	case 2:
		strcpy (path, "Path has invalid characters");
		return;
	case 3:
		strcpy (path,
		        "The path is a file , thus it cannot be created in the destination as a path");
		return;
	case 4:
		strcpy (path,
		        "Unable to create the destination directory , possible drive invalid or read only ");
		return;
	case 5:
		strcpy (path,
		        "The UNC path is a file , thus it cannot be created in the destination as a path");
		return;
	case 6:
		strcpy (path,
		        "Unable to create the destination directory , possible UNC path invalid or disconnected or read only ");
		return;

	case 7:
		strcpy (path,
		        "You need at least two characters to a path like this a: ");
		return;
// ///

	case 8:
		strcpy (path, "Too many characters : on the path ");
		return;
	case 9:
		strcpy (path, "Invalid character ? on the path ");
		return;
	case 10:
		strcpy (path, "Invalid character * on the path ");
		return;
	case 11:
		strcpy (path, "Invalid character < on the path ");
		return;
	case 12:
		strcpy (path, "Invalid character > on the path ");
		return;
	case 13:
		strcpy (path, "Invalid character / on the path ");
		return;
	case 14:
		strcpy (path, "Invalid character \" on the path ");
		return;
	case 15:
		strcpy (path, "Path is read only ");
		return;
	case 16:
		strcpy (path, "Invalid character | on the path ");
		return;

	case 17:
		strcpy (path, "The path \'");
		strcat (path, fixo_file_path);
		strcat (path, "\' refers to a file on the disk");
		return;
//aqui vai ais um
	default:
		strcpy (path,
		        "Unexpected return value to the function to create directories");
		return;
	}



}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////



int
rspmakedirUNIX (char *destination, char *path)
{
/*
 by MathMan 2021 and amanda
 */
	int ret;
	int i;
	char temp[500];

	if (destination != NULL)
	{
		strcpy (temp, destination);

		adicionadordebackslashtras (temp);
		trocadordebackslashtras (temp);

		strcat (temp, path);
	}
	else
	{
		strcpy (temp, path);
	}
	trocadordebackslashtras (temp);

	ret = strlen (temp);
	if (!ret)
	{
		return 1;
	}

	if (ret < 2)
	{
		return 7;
	}

	if (ret != 3)
	{

		if (temp[ret - 1] == '\\')
		{

			temp[ret - 1] = 0;
		}

	}

	ret = strlen (temp);
	if (temp[0] == '\\' && temp[1] == '\\')
	{
		goto unc;
	}

	if (tolower (temp[0]) < 'a' || tolower (temp[0]) > 'z' || temp[1] != ':')
	{
		return 2;       // path has invalid characters
	}

	if (ret)
	{

		for (i = 0; i < ret; i++)
		{

			if (temp[i] == '\\')
			{
				char temp1;
				temp1 = temp[i + 1];
				temp[i + 1] = 0;
				CreateDirectory (temp, NULL);
				temp[i + 1] = temp1;
			}

		}

		CreateDirectory (temp, NULL);

	}

	if (ispathfolder (temp))
	{

		if (!ispathreadonly (temp))
		{
			return 0; // ok , nao é read only
		}
		else
		{
			return 15; // path is read only or unavailable
		}

	}
	else
	{

		if (ispathfile (temp))
		{
			return 3;
		}
		else
		{
			return 4;
		}

	}

	return 0;
unc:

	if (ret)
	{

		for (i = 0; i < ret; i++)
		{

			if (i == 0)
			{
				i = 2;
			}

			if (temp[i] == '\\')
			{
				char temp1;
				temp1 = temp[i + 1];
				temp[i + 1] = 0;

				CreateDirectory (temp, NULL);

				temp[i + 1] = temp1;
			}


		}

		CreateDirectory (temp, NULL);

	}

	if (ispathfolder (temp))
	{

		if (!ispathreadonly (temp))
		{
			return 0; // ok , nao é read only
		}
		else
		{
			return 15; // path is read only or unavailable
		}

		return 0;
	}
	else
	{

		if (ispathfile (temp))
		{
			return 5;
		}
		else
		{
			return 6;
		}

	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////2021
//////////////////////////////////////////////////////////////////////////////////////////////////////////////z///

int
rspmakedir (char *path)
{
	extern void rsp_error ();

/*

 */

	int ret2;
	int ret;
	int i;
	char *temp;

	ret = strlen (path);
	if (!ret)
	{
		return 1;
	}

	temp = malloc (ret + 2);

	strcpy (temp, path);

	if (ret < 2)
	{
		free (temp);
		return 7;
	}

	ret2 = validatefoldertocreate (temp);

	if (ret2)
	{

		switch (ret2)
		{
		case 1:
			free (temp);
			return 8;
		case 2:
			free (temp);
			return 13;
		case 3:
			free (temp);
			return 10;
		case 4:
			free (temp);
			return 9;
		case 5:
			free (temp);
			return 11;
		case 6:
			free (temp);
			return 12;
		case 7:
			free (temp);
			return 14;
		case 8:
			free (temp);
			return 16;
		}

	}

	if (ret != 3)
	{

		if (temp[ret - 1] == '\\')
		{

			temp[ret - 1] = 0;
		}

	}

	ret = strlen (temp);
	if (temp[0] == '\\' && temp[1] == '\\')
	{
		goto unc;
	}

	if (tolower (temp[0]) < 'a' || tolower (temp[0]) > 'z' || temp[1] != ':')
	{
		free (temp);
		return 2;       // path has invalid characters
	}

	if (ret)
	{

		for (i = 0; i < ret; i++)
		{

			if (temp[i] == '\\')
			{
				char temp1;
				temp1 = temp[i + 1];
				temp[i + 1] = 0;

				CreateDirectory (temp, NULL);

				if (strlen (temp) != 3)
				{

					char temp4[300];

					strcpy (temp4, temp);

					temp4[strlen (temp4) - 1] = 0;

					if (ispathfile (temp4))
					{

						strcpy (fixo_file_path, temp4);
						free (temp);
						return 17;

					}

				}

				temp[i + 1] = temp1;
			}

		}

		CreateDirectory (temp, NULL);

	}

	if (ispathfolder (temp))
	{

		if (!ispathreadonly (temp))
		{
			free (temp);
			return 0; // ok , nao é read only
		}
		else
		{
			free (temp);
			return 15; // path is read only or unavailable
		}

	}
	else
	{

		if (ispathfile (temp))
		{

			strcpy (fixo_file_path, temp);
			free (temp);
			return 17;

		}
		else
		{
			free (temp);
			return 4;
		}

	}
	free (temp);
	return 0;
unc:

	if (ret)
	{

		for (i = 0; i < ret; i++)
		{

			if (i == 0)
			{
				i = 2;
			}

			if (temp[i] == '\\')
			{
				char temp1;
				temp1 = temp[i + 1];
				temp[i + 1] = 0;

				CreateDirectory (temp, NULL);

				if (strlen (temp) != 3)
				{

					char temp4[300];

					strcpy (temp4, temp);

					temp4[strlen (temp4) - 1] = 0;

					if (ispathfile (temp4))
					{

						strcpy (fixo_file_path, temp4);
						free (temp);
						return 17;

					}

				}

				temp[i + 1] = temp1;
			}

		}

		CreateDirectory (temp, NULL);

	}

	if (ispathfolder (temp))
	{

		if (!ispathreadonly (temp))
		{
			free (temp);
			return 0; // ok , nao é read only
		}
		else
		{
			free (temp);
			return 15; // path is read only or unavailable
		}

		free (temp);
		return 0;
	}
	else
	{

		if (ispathfile (temp))
		{

			strcpy (fixo_file_path, temp);
			free (temp);
			return 17;

		}
		else
		{
			free (temp);
			return 6;
		}

	}

	free (temp);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////2021
//////////////////////////////////////////////////////////////////////////////////////////////////////////////z///

char *
validanomedearquivoerrorstring ()
{
	static char errorstring[] =
	        "the file name has invalid characters | \\ \" > < ? * / or : ";
	return errorstring;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int
validanomedearquivo (char *path)
{

/*
 MathMan and Amanda Pereira
 */

	if ((contastringinsensitive (path, ":")))
	{

		return 1;
	}

	if ((contastringinsensitive (path, "/")))
	{

		return 2;
	}

	if ((contastringinsensitive (path, "*")))
	{

		return 3;
	}

	if ((contastringinsensitive (path, "?")))
	{

		return 4;
	}

	if ((contastringinsensitive (path, "<")))
	{

		return 5;
	}

	if ((contastringinsensitive (path, ">")))
	{

		return 6;
	}

	if ((contastringinsensitive (path, "\"")))
	{

		return 7;
	}

	if ((contastringinsensitive (path, "\\")))
	{

		return 8;
	}

	if ((contastringinsensitive (path, "|")))
	{

		return 9;
	}

	return 0;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
validatefoldertocreateerrorstring ()
{
	static char errorstring[] =
	        "the path has invalid characters | \" > < ?	* / or :: ";
	return errorstring;
}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

int
validatefoldertocreate (char *path)
{


/*
   esta funcao verifica se um path passado
   tem caracteres validos para um path
   se tiver algum item que nao e valido para arquivo
   retorna o valor de erro , se der tudo certo , retorna 0
   15/1/2004 13:11
 */


	if ((contastringinsensitive (path, ":") > 1))
	{

		return 1;
	}

	if ((contastringinsensitive (path, "/")))
	{

		return 2;
	}

	if ((contastringinsensitive (path, "*")))
	{

		return 3;
	}

	if ((contastringinsensitive (path, "?")))
	{

		return 4;
	}

	if ((contastringinsensitive (path, "<")))
	{

		return 5;
	}

	if ((contastringinsensitive (path, ">")))
	{

		return 6;
	}

	if ((contastringinsensitive (path, "\"")))
	{

		return 7;
	}

	if ((contastringinsensitive (path, "|")))
	{

		return 8;
	}

	return 0;

}



int
rspposicaofixa (int mode, int value)
{

	static int valor = 0;

	if (mode == 0)
	{


		return valor;

	}

	if (mode == 1)
	{


		valor = value;
		return 0;
	}

	return 0;

}

static unsigned int rsp32(unsigned int adler, const unsigned char *buf, unsigned int len)
{
  uchar s1 = adler & 0xff;
  uchar s2 = (adler >> 8) & 0xff;
  uchar s3 = (adler >> 16) & 0xff;
  uchar s4 = (adler >> 24) & 0xff;
  int svansa = 0;
  int ok12 = len;

  if (buf == NULL)
  {
    return 1L;
  }

  while (ok12)
  {
    s1 += buf[svansa++];
    s2 += s1;
    s3 += s2;
    s4 += s3;
    ok12--;
  }

  return s1 + (s2 << 8) + (s3 << 16) + (s4 << 24);
}

int rsp32_amanda_s_smart_ape(int adler_amanda_s_smart_ape, char *buf_amanda_s_smart_ape, int len_amanda_s_smart_ape)
{

	return rsp32((unsigned int) adler_amanda_s_smart_ape, (const unsigned char *) buf_amanda_s_smart_ape, (unsigned int) len_amanda_s_smart_ape);

}

int __fastcall rsp32_file_amanda_s_smart_ape(char * filename_utf_8_amanda_s_smart_ape)
{
	unsigned char    *    buffer_amanda_s_smart_ape = malloc(RECOMMENDED_BUFFER_SIZE_FOR_FILE_FUNCTIONS_AMANDA_S_SMART_APE);
	FILE             *    our_file_amanda_s_smart_ape        = NULL;
	int              len_amanda_s_smart_ape                        ;
	int64_t          filesize_amanda_s_smart_ape                   ; 
	unsigned int     rsp32_amanda_s_smart_ape                =    1;
	
	filesize_amanda_s_smart_ape = getfilesize_ar_amanda_s_smart_ape(filename_utf_8_amanda_s_smart_ape);
	if(-1 == filesize_amanda_s_smart_ape)
	{
		free(buffer_amanda_s_smart_ape);
		return 0;
	}

	our_file_amanda_s_smart_ape = _wfopen(amanda_utf8towide_1_(filename_utf_8_amanda_s_smart_ape),
	L"rb");

	if(NULL != our_file_amanda_s_smart_ape)
	{

		while((len_amanda_s_smart_ape = fread((void *) buffer_amanda_s_smart_ape, 1, RECOMMENDED_BUFFER_SIZE_FOR_FILE_FUNCTIONS_AMANDA_S_SMART_APE, our_file_amanda_s_smart_ape)))
		{
			rsp32_amanda_s_smart_ape = rsp32(rsp32_amanda_s_smart_ape, (const unsigned char *) buffer_amanda_s_smart_ape, (unsigned int) len_amanda_s_smart_ape);
		}

		fclose(our_file_amanda_s_smart_ape);
		our_file_amanda_s_smart_ape = NULL;
	}

	free(buffer_amanda_s_smart_ape);
	buffer_amanda_s_smart_ape = NULL;

	return rsp32_amanda_s_smart_ape;

}
