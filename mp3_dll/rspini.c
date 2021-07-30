
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
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/
 
/*
   New Standard C ini handling routines to solve some
   of the limitations of the windows ini apis
   WritePrivateProfileString and GetPrivateProfileString

   replace WritePrivateProfileString and
   GetPrivateProfileString with write_ini_xml and
   read_ini_xml and call me in the morning

   https://sourceforge.net/projects/rspini/
   https://sourceforge.net/projects/impxmlv2/
 */
/*

   Copyright (C) 2011 Bucaneiro Engineering

   Our software is e_free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the e_free software Foundation, either version 3 of
   the License, or by (at your option) any later version.

   This program is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
   PURPOSE.  See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with this program.  If not, see
   http://www.gnu.org/licenses/.

 */

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

#include "mv_from_be.h"

#include "base91.c"
///////////////////////////////////////////////////////////////////////////////////////////////
void e_memory_test (void *ptr, char *source, int line);
void *e_calloc (size_t nelem, size_t size__);
void *e_malloc (size_t size__);
void *e_realloc (void *ptr, size_t size__);
void e_free (void *ptr, char *source, int line);
#include "e_malloc.c"
///////////////////////////////////////////////////////////////////////////////////////////////
/* return value for the write and read ini functions:
   0 - No error
   1 - Memory allocation failed
   2 - Error retrieving file size
   3 - Failed to read the ini file
   4 - Error during close of ini file to read
   5 - Failed to open ini file to save
   6 - System or disk error during save of ini file
   7 - Error during close of ini file to read
   8 - Error during close of ini file to save
 */
////////////////////////////////////////////////////////////////////////////
int __stdcall read_ini (char *app_name, char *key_name, char *data, int len,
                        char *ini_file,int filename_is_utf8);
int __stdcall write_ini_unix (char *app_name, char *key_name, char *data,
                              char *ini_file,int filename_is_utf8);
int __stdcall write_ini_mac (char *app_name, char *key_name, char *data,
                             char *ini_file,int filename_is_utf8);
int __stdcall write_ini_windows (char *app_name, char *key_name, char *data,
                                 char *ini_file,int filename_is_utf8);
int __stdcall get_error_string (int val, char *data);
int __stdcall read_ini_binary (char *app_name, char *key_name, char *data,
                               int *out_len, char *ini_file,int filename_is_utf8);
int __stdcall write_ini_binary (char *app_name, char *key_name, char *data,
                                int len, char *ini_file,int filename_is_utf8);
/*

   impxmlv2 based function http://impxmlv2.sourceforge.net/

   xml like based database storage with a faster approuch,
   it was created with the idea in mind of a faster
   xml utilization.

   it will encode the data in the same encode
   mode used in standard xml files
   characters 0 10 13 and 38 are encoded

   if filename_is_utf8is 1 then it considers the ini filename
   as a uft8 encoded name of file, and will convert it to a
   wide string filename to open with the Unicode
   version of fopen (_wfopen)

 */
int __stdcall write_ini_xml (char *app_name, char *key_name, char *data,
                             int len, char *ini_file,int filename_is_utf8);


/*

   impxmlv2 based function http://impxmlv2.sourceforge.net/

   xml like based database storage with a faster approuch,
   it was created with the idea in mind of a faster
   xml utilization.

   on entering the variable out_len need to have the available
   bytes to write, on exit the out_len variable will have the bytes
   written

   if filename_is_utf8is 1 then it considers the ini filename
   as a uft8 encoded name of file, and will convert it to a
   wide string filename to open with the Unicode
   version of fopen (_wfopen)

 */
int __stdcall read_ini_xml (char *app_name, char *key_name, char *data,
                            int *out_len, char *ini_file,int filename_is_utf8);
/////////////////////////////////////////////////////////////////////////////
int
the_problem (int val);
__int64
getfilesize_v2 (char *infile, int *error,int filename_is_utf8);
void
removedordeespaconoinicio_with_tab (char *path);
void
removedordeespaconofinal_with_tab (char *path);
void
trim (char *data);
void
trim_real (char *data);
int
get_line (char *data, char *line, int *position, int *line_size);
static
int
countitens (const char *string, int len, const char item);
int
test_for_new_app_name (int ssize, char *line, int line_size);
int
locate_app_name (int ssize, char *line, char **app_name_returned,
                 int line_size);
void
add_endofline (char **ptr, int mode);
int
search_for_entry (char *line, int line_size, char *key_name,
                  int *read_position);
void
strncpy_v2 (char *s1, const char *s2, size_t n);
int
process (char *wholefile, char *line, char *app_name, char *key_name,
         char *data, char *file_to_save, int mode, int *position,
         int *bytes2save, int wsize,
         int process_mode,
         int available_bytes, char *destination_bytes_for_read);
int
replace_or_count_stringsensitive_arab (int mode, char *data, int datalen,
                                       char *search_string,
                                       int search_string_len, char *replace,
                                       int replace_len, int *count,
                                       char **output_string, int *output_len);
int
string_remove (char *data, int datalen,
               char *search_string, int search_string_len,
               char **output_string, int *output_len);
int
internal_write_ini (char *app_name, char *key_name, char *data,
                    char *ini_file, int mode,
                    int end_of_line_mode, int bytes_to_save, char *read_data,int filename_is_utf8);
static double
inittimer2 (int value)
;
static int stringreplace(char *data,int data_len
                         ,char*search,
                         int searchlen,
                         char*replace,
                         int replacelen,
                         int*out_len,char**outdata);
/////////////////////////////////////////////////////////////////////////////
//#define MEMORY_ERROR__

int
the_problem (__attribute__((unused)) int val)
{
/*

   as you can see it remove data that surrounds the string

   next release will have the workarounds to this problem

 */

	char data[1001] = { 0, };

	WritePrivateProfileString ("app_name", "key_name", "\"data\"",
	                                 "c:\\rsp_software_ini_test.ini");
	GetPrivateProfileString ("app_name", "key_name", "", data, 1000,
	                               "c:\\rsp_software_ini_test.ini");
	printf ("return data is ->%s<-\n", data);

	WritePrivateProfileString ("app_name", "key_name", "\'data\'",
	                                 "c:\\rsp_software_ini_test.ini");
	GetPrivateProfileString ("app_name", "key_name", "", data, 1000,
	                               "c:\\rsp_software_ini_test.ini");
	printf ("return data is ->%s<-\n", data);

	WritePrivateProfileString ("app_name", "key_name", " data ",
	                                 "c:\\rsp_software_ini_test.ini");
	GetPrivateProfileString ("app_name", "key_name", "", data, 1000,
	                               "c:\\rsp_software_ini_test.ini");
	printf ("return data is ->%s<-\n", data);

	WritePrivateProfileString ("app_name", "key_name", "\ndata\n",
	                                 "c:\\rsp_software_ini_test.ini");
	GetPrivateProfileString ("app_name", "key_name", "", data, 1000,
	                               "c:\\rsp_software_ini_test.ini");
	printf ("return data is ->%s<-\n", data);

	WritePrivateProfileString ("app_name", "key_name", "\rdata\r",
	                                 "c:\\rsp_software_ini_test.ini");
	GetPrivateProfileString ("app_name", "key_name", "", data, 1000,
	                               "c:\\rsp_software_ini_test.ini");
	printf ("return data is ->%s<-\n", data);

	return 0;
}
int __stdcall stringtobyte (unsigned char *dest, unsigned char *src, int len);
int __stdcall stringtobyte (unsigned char *dest, unsigned char *src, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	return 0;
}
int __stdcall bytetostring (unsigned char *dest, unsigned char *src, int len);
int __stdcall bytetostring (unsigned char *dest, unsigned char *src, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return 0;
}
/////////////////////////////////////////////////////////////////////////////
void trucate_file_large(char*filename,off64_t length,int filename_is_utf8);
void trucate_file_large(char*filename,off64_t length,int filename_is_utf8)
{
	HANDLE hf;

	unicode_large *ul=calloc(sizeof(unicode_large),1);

	if(filename_is_utf8)
	{
		hf=CreateFileW (utf8towide_fixed(ul,filename),
		                GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
		                OPEN_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
	}
	else
	{
		hf=CreateFile (filename,
		               GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
		               OPEN_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
	}
	if(INVALID_HANDLE_VALUE!=hf)
	{
		LARGE_INTEGER position=(LARGE_INTEGER)length;
		SetFilePointer(hf, position.LowPart, &position.HighPart, FILE_BEGIN);
		SetEndOfFile(hf);
		CloseHandle(hf);
	}
	free(ul);
	return ;

}
/////////////////////////////////////////////////////////////////////////////
 #define         Min(A, B)       ((A) < (B) ? (A) : (B))
/* on entering the variable out_len has the available bytes to write,
   on exit it will have the bytes written */
int __stdcall
read_ini_xml (char *app_name, char *key_name, char *data, int *out_len,
              char *ini_file,int filename_is_utf8)
{
	int out_len2 = 0;
	char *outdata = NULL;
	char *outdata2 = NULL;
	char *outdata3 = NULL;
	char *outdata4 = NULL;
	char *outdata5 = NULL;
	char search[300];
	char replace[300];
	int returnvalue=0;
	int error2=0;
	int bufsize=0;
	/////////////////////////////////////////////////////////////////////////
	bufsize = getfilesize_v2 (ini_file, &error2,filename_is_utf8) + 100;
	outdata = e_malloc (bufsize);
	if (NULL == outdata)
	{
		returnvalue= 1;
		goto saida;
	}
	if (error2)
	{
		returnvalue =2;
		goto saida;
	}
	returnvalue = read_ini (app_name, key_name, outdata, bufsize, ini_file,filename_is_utf8);
	if(returnvalue)
	{
		goto saida;
	}
	/////////////////////////////////////////////////////////////////////////
	strcpy(search,"&#13;");
	strcpy(replace,"\r");
	stringreplace(outdata,strlen(outdata)
	              ,search,
	              strlen(search),
	              replace,
	              strlen(replace),
	              &out_len2,&outdata2);
	if (NULL == outdata2)
	{
		returnvalue =1;
		goto saida;
	}       /////////////////////////////////////////////////////////////////////////
	strcpy(search,"&#10;");
	strcpy(replace,"\n");
	stringreplace(outdata2,out_len2
	              ,search,
	              strlen(search),
	              replace,
	              strlen(replace),
	              &out_len2,&outdata3);
	if (NULL == outdata3)
	{
		returnvalue =1;
		goto saida;
	}       /////////////////////////////////////////////////////////////////////////
	strcpy(search,"&#0;");
	replace[0]=0;
	stringreplace(outdata3,out_len2
	              ,search,
	              strlen(search),
	              replace,
	              1,
	              &out_len2,&outdata4);
	if (NULL == outdata4)
	{
		returnvalue =1;
		goto saida;
	}       /////////////////////////////////////////////////////////////////////////
	strcpy(search,"&amp;");
	strcpy(replace,"&");
	(void)stringreplace(outdata4,out_len2
	                    ,search,
	                    strlen(search),
	                    replace,
	                    strlen(replace),
	                    &out_len2,&outdata5);
	if (NULL == outdata5)
	{
		returnvalue =1;
		goto saida;
	}       /////////////////////////////////////////////////////////////////////////

	memcpy(data,outdata5,Min(out_len2,*out_len));
	*out_len=Min(out_len2,*out_len);
saida:
	;
	if(outdata2)
		e_free (outdata2, __FILE__, __LINE__);
	if(outdata3)
		e_free (outdata3, __FILE__, __LINE__);
	if(outdata4)
		e_free (outdata4, __FILE__, __LINE__);
	if(outdata5)
		e_free (outdata5, __FILE__, __LINE__);
	return returnvalue;
}
int __stdcall
write_ini_xml(char *app_name, char *key_name, char *data, int len,
              char *ini_file,int filename_is_utf8)
{
	int out_len = 0;
	char *outdata = NULL;
	char *outdata2 = NULL;
	char *outdata3 = NULL;
	char *outdata4 = NULL;
	char search[300];
	char replace[300];
	int returnvalue=0;
	/////////////////////////////////////////////////////////////////////////
	strcpy(search,"&");
	strcpy(replace,"&amp;");
	stringreplace(data,len
	              ,search,
	              strlen(search),
	              replace,
	              strlen(replace),
	              &out_len,&outdata);
	if (NULL == outdata)
	{
		returnvalue =1; goto saida;
	}
	/////////////////////////////////////////////////////////////////////////
	search[0]=0;
	strcpy(replace,"&#0;");
	stringreplace(outdata,out_len
	              ,search,
	              1,
	              replace,
	              strlen(replace),
	              &out_len,&outdata2);
	if (NULL == outdata2)
	{
		returnvalue =1; goto saida;
	}
/////////////////////////////////////////////////////////////////////////////
	search[0]='\n';
	strcpy(replace,"&#10;");
	stringreplace(outdata2,out_len
	              ,search,
	              strlen(search),
	              replace,
	              strlen(replace),
	              &out_len,&outdata3);
	if (NULL == outdata3)
	{
		returnvalue =1; goto saida;
	}
	/////////////////////////////////////////////////////////////////////////
	search[0]='\r';
	strcpy(replace,"&#13;");
	stringreplace(outdata3,out_len
	              ,search,
	              strlen(search),
	              replace,
	              strlen(replace),
	              &out_len,&outdata4);
	if (NULL == outdata4)
	{
		returnvalue =1; goto saida;
	}
	/////////////////////////////////////////////////////////////////////////
	returnvalue = write_ini_windows (app_name, key_name, outdata4, ini_file, filename_is_utf8);
saida:
	;
	if(outdata2)
		e_free (outdata2, __FILE__, __LINE__);
	if(outdata3)
		e_free (outdata3, __FILE__, __LINE__);
	if(outdata4)
		e_free (outdata4, __FILE__, __LINE__);
	return returnvalue;
}
int __stdcall
write_ini_binary (char *app_name, char *key_name, char *data, int len,
                  char *ini_file,int filename_is_utf8)
{
	int ret;


	struct basE91 eu;
	char *outdata = NULL;
	char *outdata2 = NULL;
	int size__ = 0;
	outdata = e_calloc ((len * 2) + 100, 1);
	if (NULL == outdata)
	{
		return 1;
	}
	outdata2 = outdata;
	basE91_init (&eu);
	size__ = basE91_encode (&eu, data, len, outdata);
	outdata += size__;
	size__ += basE91_encode_end (&eu, outdata);
	ret = write_ini_windows (app_name, key_name, outdata2, ini_file,filename_is_utf8);
	e_free (outdata2, __FILE__, __LINE__);
	return ret;
}
int __stdcall
read_ini_binary (char *app_name, char *key_name, char *data, int *out_len,
                 char *ini_file,int filename_is_utf8)
{
	__int64 getfilesize_v2 (char *infile, int *error,int filename_is_utf8);

	struct basE91 eu;
	int size__ = 0;
	int error2 = 0;
	char *outdata = NULL;
	int bufsize;

	bufsize = getfilesize_v2 (ini_file, &error2,filename_is_utf8) + 100;

	outdata = e_malloc (bufsize);

	if (NULL == outdata)
	{
		return 1;
	}

	if (error2)
	{
		e_free (outdata, __FILE__, __LINE__);
		return 2;
	}

	basE91_init (&eu);

	read_ini (app_name, key_name, outdata, bufsize, ini_file, filename_is_utf8);

	size__ += basE91_decode (&eu, outdata, strlen (outdata), data);
	data += size__;

	size__ += basE91_decode_end (&eu, data);

	*out_len = size__;
	e_free (outdata, __FILE__, __LINE__);
	return 0;
}

//New implementation of handling of ini files
/*

   #define _S_IFMT         0170000          file type mask
   #define _S_IFDIR        0040000         / directory /
   #define _S_IFCHR        0020000         / character special /
   #define _S_IFIFO        0010000         / pipe /
   #define _S_IFREG        0100000         / regular /
   #define _S_IREAD        0000400         / read permission, owner /
   #define _S_IWRITE       0000200         / write permission, owner /
   #define _S_IEXEC        0000100         / execute/search permission, owner /

   //_O_RDWR | _O_CREAT
   int file;
   //remove("file2.txt");


   file=_wopen(L"file2.txt",_O_WRONLY | _O_CREAT | _O_BINARY );
   printf("ret , %d\n",file);
   if(-1!=file)
   {


   close(file);
   _wchmod(
   L"file2.txt",
   _S_IREAD | _S_IWRITE
   );
   }

   exit(1);

   Characters in mode string	 Equivalent oflag value for _open/_sopen
   a

   _O_WRONLY | _O_APPEND (usually _O_WRONLY | _O_CREAT | _O_APPEND)

   a+

   _O_RDWR | _O_APPEND (usually _O_RDWR | _O_APPEND | _O_CREAT )

   r

   _O_RDONLY

   r+

   _O_RDWR

   w

   _O_WRONLY (usually _O_WRONLY | _O_CREAT | _O_TRUNC)

   w+

   _O_RDWR (usually _O_RDWR | _O_CREAT | _O_TRUNC)

   b

   _O_BINARY

   t

   _O_TEXT

   c

   None

   n

   None

   S

   _O_SEQUENTIAL

   R

   _O_RANDOM

   T

   _O_SHORTLIVED

   D

   _O_TEMPORARY

   ccs=UNICODE

   _O_WTEXT

   ccs=UTF-8

   _O_UTF8

   ccs=UTF-16LE

   _O_UTF16
 */
/*
int _fseeki64(
        FILE *stream,
        __int64 offset,
        int origin
        );
int _fseeki64(
        FILE *stream,
        __int64 offset,
        int origin
        )
{
	__int64 ret;
	ret=_lseeki64 (fileno(stream), offset, origin);
	if(-1!=ret)
	{
		return 0;
	}
	return 1;
}
__int64 _ftelli64(
        FILE *stream
        );
__int64 _ftelli64(
        FILE *stream
        )
{
	__int64 ret;
	ret = _telli64 (fileno(stream));
	return ret;
}
size_t fread(void *ptr, size_t size, size_t nelem, FILE *stream);
size_t fread(void *ptr, size_t size, size_t nelem, FILE *stream)
{
	int ret;
	assert(size);
	ret=_read(
	        fileno(stream),
	        ptr,
	        size* nelem
	        );
	return ret/size;
}
size_t fwrite(const void *ptr, size_t size, size_t nelem, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nelem, FILE *stream)
{
	int ret;
	assert(size);
	ret=_write(
	        fileno(stream),
	        ptr,
	        size* nelem
	        );
	return ret/size;
}
*/
__int64
getfilesize_v2 (char *infile, int *error,int filename_is_utf8)
{
	__int64 ret;
	FILE *myfile;
	*error = 0;
	unicode_large *ul=calloc(sizeof(unicode_large),1);
	if(filename_is_utf8)
	{
		myfile = _wfopen (utf8towide_fixed(ul,infile), L"rb");
	}
	else
	{
		myfile = fopen (infile, "rb");
	}
	if (myfile == ((void *) 0))
	{
		free(ul);
		return 0;
	}
	ret = _fseeki64 (myfile, 0, SEEK_END);
	if (-1==ret)
	{
		*error = 1;
		goto saida;
	}
	ret = _ftelli64 (myfile);
	if (-1==ret)
	{
		*error = 2;
		goto saida;
	}
	if (EOF == fclose (myfile))
	{
		*error = 3;
	}
	if (ret >= 0)
	{
		free(ul);
		return ret;
	}
saida:
	free(ul);
	return 0;
}
void
removedordeespaconoinicio_with_tab (char *path)
{
	int ret;
	char *ptr;
	char *ptrdesloca;
	ptrdesloca = path;
	ret = strlen (path);
	if (ret)
	{
		ptr = e_malloc (ret + 1);
		memset (ptr, 0, ret + 1);
		while (*ptrdesloca == ' ' || *ptrdesloca == '\t')
		{

			ptrdesloca++;
		}
		strcpy (ptr, ptrdesloca);
		//memset (path, 0, ret);//?
		strcpy (path, ptr);

		e_free (ptr, __FILE__, __LINE__);
	}
	return;
}

void
removedordeespaconofinal_with_tab (char *path)
{
	int ret;
inicio:
	ret = strlen (path);
	if (ret)
	{
		if (path[(ret - 1)] == ' ' || path[(ret - 1)] == '\t')
		{
			path[(ret - 1)] = 0;
			goto inicio;
		}
	}
}
void
trim (char *data)
{
//removedordeespaconofinal_with_tab(data);
	removedordeespaconoinicio_with_tab (data);
}

void
trim_real (char *data)
{
	removedordeespaconofinal_with_tab (data);
	removedordeespaconoinicio_with_tab (data);
}

int bypassed = 0;
int end_flag = 0;
int
get_line (char *data, char *line, int *position, int *line_size)
{
/* [closed] */
/*
   you need to walk over the line
   and return 1 when no more itens are read */

	int counter = 0;
	int did = 0;
	line[0] = 0;
	*line_size = 0;
	*position = 0;
	*line_size = 0;
	//printf ("Inside get line\n");
	bypassed = 0;

	if (0 == *data)
	{

		end_flag = 1;
		//printf ("exit get line\n");
		return 1;
	}

	if ('\r' == *data)
	{
		bypassed++;
		did = 1;
		data++;
		(*position)++;

	}
	if ('\n' == *data)
	{
		bypassed++;
		did = 1;
		data++;
		(*position)++;

	}
	while (1)
	{
		did = 1;
		if ('\r' == *data || '\n' == *data)
		{
			break;
		}
		if (0 == *data)
		{
			end_flag = 1;

			break;
		}
		line[counter++] = *data++;
		line[counter] = 0;
		(*position)++;
	}

	trim (line);
	*line_size = strlen (line);

	//printf ("exit get line\n");

	return 1 != did;
}

enum
{
	MODE_READ__,
	MODE_WRITE__,
};
enum
{
/* pos1 */
	MODE_UNIX__,
	MODE_WINDOWS__,
	MODE_MAC__,
};
static
int
countitens (const char *string, int len, const char item)
{
/* [closed] */
	int i;
	int counter;
	counter = 0;
	for (i = 0; i < len; i++)
	{
		if (item == string[i])
		{
			counter++;
		}
	}
	return counter;
}

int
test_for_new_app_name (__attribute__((unused)) int ssize, char *line, int line_size)
{
/*
   [closed]
 */
	int returnvalue = 0;

	char *ptr = e_calloc (line_size + 1, 1);
	char *ptrb = ptr;
	int len;
	if (NULL == ptr)
	{
		returnvalue = -1;
		goto _exit__;
	}
	strcpy (ptr, line);
	trim_real (ptr);
	len = strlen (ptr);
	if ('[' == ptr[0])
	{
		if (']' == ptr[len - 1])
		{
			returnvalue = 1;        //found new app_name
			goto _exit__;
		}
	}
_exit__:
	;
	if (ptrb)
		e_free (ptrb, __FILE__, __LINE__);
	return returnvalue;
}

int
locate_app_name (__attribute__((unused)) int ssize, char *line, char **app_name_returned,
                 int line_size)
{
/*
   [closed]
 */
	int returnvalue = 0;

	char *ptr = e_calloc (line_size + 1, 1);
	char *ptrb = ptr;
	int len;
	if (NULL == ptr)
	{
		returnvalue = 1;
		goto _exit__;
	}
	strcpy (ptr, line);
	trim_real (ptr);
	len = strlen (ptr);
	if ('[' == ptr[0])
	{
		if (']' == ptr[len - 1])
		{
			ptr[len - 1] = 0;
			ptr++;
//problem
			trim_real (ptr);
			*app_name_returned =
			        e_calloc (strlen (ptr) + 1, 1);
			if (NULL == *app_name_returned)
			{
				returnvalue = 2;
				goto _exit__;
			}
			strcpy (*app_name_returned, ptr);
		}
	}
_exit__:
	;
	if (ptrb)
		e_free (ptrb, __FILE__, __LINE__);
	return returnvalue;
}

void
add_endofline (char **ptr, int mode)
{
/* [closed] */
	if (MODE_UNIX__ == mode)
	{
		strcat (*ptr, "\n");
	}
	else if (MODE_WINDOWS__ == mode)
	{
		strcat (*ptr, "\r\n");
	}
	else
	{
		strcat (*ptr, "\r");
	}
}
int
search_for_entry (char *line, int line_size, char *key_name,
                  int *read_position)
{
/* [closed] */
	int returnvalue = 0;
	char *ptr = e_calloc (line_size + 1000, 1);
	char *ptrb = ptr;
	int len = line_size;
	int counter = 0;
	int found = 0;
	int ret;
	*read_position = 0;
	ret = test_for_new_app_name (0, line, line_size);
	if (-1 == ret)
	{
		returnvalue = -1;
		goto _exit__;
	}
	if (1 == ret)
	{
		returnvalue = 2;        //is new app_name
		goto _exit__;
	}
	if (NULL == ptr)
	{
		returnvalue = -1;
		goto _exit__;
	}
	strcpy (ptr, line);
	while (len--)
	{
		if ('=' == ptr[counter])
		{
			found = 1;
			ptr[counter] = 0;
			break;
		}
		counter++;
	}
//here
	*read_position = strlen (ptr) + 1;      //correct
	if (0 == found)
	{
		goto _exit__;
	}
	trim_real (ptr);
	if (0 == strcmp (ptr, key_name))
	{
		returnvalue = 1;        //found
	}
_exit__:
	;
	if (ptrb)
		e_free (ptrb, __FILE__, __LINE__);
	return returnvalue;
}

/*
   It will store successive elements
   of s2 no more than n including the
   NULL termination
 */
void
strncpy_v2 (char *s1, const char *s2, size_t n)
{
	int i;
	if (n >= 1)
	{
		for (i = 0; i < (int) n - 1; i++)
		{
			if (0 == s2[i])
			{
				break;
			}

			*s1++ = s2[i];
		}
		*s1 = 0;
	}
}
static void
adjust (int *already, char **ptr, int mode, char **file_to_save,
        int *bytes2save)
{
	if (0 == *already)
	{
		*already = 1;
	}
	else
	{
		strcpy (*ptr, "");
		add_endofline (ptr, mode);
		{
			int thesize = strlen (*ptr);
			memcpy (*file_to_save, *ptr, thesize);
			*file_to_save += thesize;
			*bytes2save += thesize;
		}
		*already = 1;
	}
	return;
}
int
process (char *wholefile, char *line, char *app_name, char *key_name,
         char *data, char *file_to_save, int mode, int *position,
         int *bytes2save, int wsize,
         int process_mode,
         int available_bytes, char *destination_bytes_for_read)
{
	int already = 0;
	int read_position = 0;
	int returnvalue = 0;
	char *ptr = NULL;       //e_calloc(strlen(app_name)+10+strlen(key_name)+10+strlen(data)+10,1); //check
	int line_size = 0;
	char *app_name_returned = NULL;
	*bytes2save = 0;
	*position = 0;
	end_flag = 0;
	//printf ("inside process %d\n", process_mode);
	if (MODE_WRITE__ == process_mode)
	{
#ifdef MEMORY_ERROR__
		ptr = e_calloc (strlen (app_name) + 10 + strlen (key_name) +
		                10 + strlen (data) + 10, 1);
#else
		ptr = e_calloc (strlen (app_name) + 10 + strlen (key_name) +
		                10 + strlen (data) + 10 +
		                strlen
		                        ("#ini handling routines from sourceforge project rspini at http://rspini.sf.net")
		                + 10, 1);
#endif
		if (NULL == ptr)
		{
			returnvalue = 1;
			goto _exit__;
			//  return 1;
		}
	}
	else
	{
		if (available_bytes)
		{
			destination_bytes_for_read[0] = 0;
		}
	}
//printf          ("a\n");
	if (1 == get_line (wholefile, line, position, &line_size))
	{
		//empty file
		//printf ("empty file\n");
		wholefile += *position;         //walking over the data
		if (MODE_WRITE__ == process_mode)
		{
			strcpy (ptr,
			        "#ini handling routines from sourceforge project rspini at http://rspini.sf.net");
			add_endofline (&ptr, mode);
			strcat (ptr, "[");
			strcat (ptr, app_name);
			strcat (ptr, "]");
			add_endofline (&ptr, mode);
			strcat (ptr, key_name);
			strcat (ptr, "=");
			strcat (ptr, data);
			//add_endofline(&ptr,mode); //certo
			{
				int thesize = strlen (ptr);
				memcpy (file_to_save, ptr, thesize);
				file_to_save += thesize;
				*bytes2save += thesize;
			}
		}
	}
	else
	{
		int ret;
		wholefile += *position;
again:
		;
		//printf ("process now\n");
//printf          ("c\n");
		if (MODE_WRITE__ == process_mode)
		{
			if (0 == already)
			{
				if (bypassed)
				{
					strcpy (ptr, "");
					add_endofline (&ptr, mode);
					{
						int thesize =
						        strlen (ptr);
						memcpy (file_to_save,
						        ptr, thesize);
						file_to_save +=
						        thesize;
						*bytes2save +=
						        thesize;
					}
				}
			}
		}
		if (app_name_returned)
		{
			e_free (app_name_returned, __FILE__, __LINE__);
			app_name_returned = NULL;
		}
		//printf ("enter locate\n");
		ret = locate_app_name (wsize, line, &app_name_returned,
		                       line_size);
		//printf ("exit locate\n");
		if (ret)
		{
			returnvalue = 2;
			goto _exit__;
		}
		if (app_name_returned)
		{
//process, ok
			if (0 == strcmp (app_name_returned, app_name))
			{
//found app_name match, process
//now search for entry
				//printf          ("found app_name match, process\n");
				//printf          (" line antes -> %s\n",line);
				if (MODE_WRITE__ == process_mode)
				{
					adjust (&already, &ptr, mode,
					        &file_to_save,
					        bytes2save);
					memcpy (file_to_save, line,
					        line_size);
					file_to_save += line_size;
					*bytes2save += line_size;

				}
again2:
				;
				if (1 ==
				    get_line (wholefile, line, position,
				              &line_size))
				{
					//printf          ("just not found the entry name\n");
					//just not found the entry name
					wholefile += *position;
					if (MODE_WRITE__ ==
					    process_mode)
					{
						adjust (&already,
						        &ptr, mode,
						        &file_to_save,
						        bytes2save);
						strcpy (ptr,
						        key_name);
						strcat (ptr, "=");
						strcat (ptr, data);
						{
							int thesize
							        =
							                strlen
							                        (ptr);
							memcpy (file_to_save, ptr, thesize);
							file_to_save
							        +=
							                thesize;
							*bytes2save
							        +=
							                thesize;
						}
					}
					goto _exit__;
				}
				else
				{
					wholefile += *position;
					//goto again;
				}
				//printf          (" line -> %s\n",line);
				read_position = 0;
				//printf ("will enter search\n");
				ret = search_for_entry (line, line_size,
				                        key_name,
				                        &read_position);
				//printf ("exit search\n");
				if (-1 == ret)
				{
					returnvalue = 3;
					goto _exit__;
				}
				if (2 == ret)           //is new app_name
				{
//printf          ("f\n");
					//is new app_name
					//save the entry, save the line and save the rest of the lines

					//printf          ("is new app_name, save the entry, save the line and save the rest of the lines\n");

					if (MODE_WRITE__ ==
					    process_mode)
					{
						adjust(&already,&ptr, mode,&file_to_save,bytes2save);
						strcpy (ptr,
						        key_name);
						strcat (ptr, "=");
						strcat (ptr, data);
						{
							int thesize
							        =
							                strlen
							                        (ptr);
							memcpy (file_to_save, ptr, thesize);
							file_to_save
							        +=
							                thesize;
							*bytes2save
							        +=
							                thesize;
						}
					}
again3:
					;
/* [closed] */
					if (MODE_WRITE__ ==
					    process_mode)
					{
						adjust(&already,&ptr, mode,&file_to_save,bytes2save);
						memcpy (file_to_save, line, line_size);
						file_to_save +=
						        line_size;
						*bytes2save +=
						        line_size;

					}
					if (1 ==
					    get_line (wholefile, line,
					              position,
					              &line_size))
					{
						wholefile +=
						        *position;
						goto _exit__;
					}
					else
					{
						wholefile +=
						        *position;
						goto again3;
					}
				}
				if (1 == ret)
				{
//printf          ("g\n");
					//found the entry replace it and save the rest of the lines
					//printf          ("found the entry replace it and save the rest of the lines\n");
					if (MODE_WRITE__ ==
					    process_mode)
					{
						adjust(&already,&ptr, mode,&file_to_save,bytes2save);
						strcpy (ptr,
						        key_name);
						strcat (ptr, "=");
						strcat (ptr, data);
						{
							int thesize
							        =
							                strlen
							                        (ptr);
							memcpy (file_to_save, ptr, thesize);
							file_to_save
							        +=
							                thesize;
							*bytes2save
							        +=
							                thesize;
						}
					}
					if (MODE_READ__ ==
					    process_mode)
					{
						if (available_bytes)
						{
//copy the data here
							if (available_bytes > 0)
							{
								//printf ("will copy\n");
								strncpy_v2
								        (destination_bytes_for_read,
								        &line
								        [read_position],
								        available_bytes);
								//printf ("passed copy\n");
							}
						}
						goto _exit__;
					}
again4:
					;
/* [closed] */
					if (1 ==
					    get_line (wholefile, line,
					              position,
					              &line_size))
					{
						wholefile +=
						        *position;
						goto _exit__;
					}
					else
					{
						wholefile +=
						        *position;
						if (MODE_WRITE__ ==
						    process_mode)
						{
							adjust(&already,&ptr, mode,&file_to_save,bytes2save);
							memcpy (file_to_save, line, line_size);
							file_to_save
							        +=
							                line_size;
							*bytes2save
							        +=
							                line_size;
						}
						goto again4;
					}
				}
				if (0 == ret)
				{
//printf          ("h\n");
					//printf          ("not found, save line and goto again 2\n");
					//not found, save line and goto again 2;
					if (MODE_WRITE__ ==
					    process_mode)
					{
						adjust(&already,&ptr, mode,&file_to_save,bytes2save);
						memcpy (file_to_save, line, line_size);
						file_to_save +=
						        line_size;
						*bytes2save +=
						        line_size;
					}
					goto again2;
				}
			}
			else
			{
//notmatch, save the line and load a new line and goto again
				//printf          ("notmatch, save the line and load a new line and goto again\n");
//printf          ("i\n");

				if (MODE_WRITE__ == process_mode)
				{
					adjust(&already,&ptr, mode,&file_to_save,bytes2save);
					memcpy (file_to_save, line,
					        line_size);
					file_to_save += line_size;
					*bytes2save += line_size;

				}
				if (1 ==
				    get_line (wholefile, line, position,
				              &line_size))
				{
					wholefile += *position;
					//printf          ("just not found the app_name_returned, store everythiing\n");
					//just not found the app_name_returned, store everythiing
					if (MODE_WRITE__ ==
					    process_mode)
					{
						adjust(&already,&ptr, mode,&file_to_save,bytes2save);
						strcpy (ptr, "[");
						strcat (ptr,
						        app_name);
						strcat (ptr, "]");
						add_endofline (&ptr,
						               mode);
						strcat (ptr,
						        key_name);
						strcat (ptr, "=");
						strcat (ptr, data);
						{
							int thesize
							        =
							                strlen
							                        (ptr);
							memcpy (file_to_save, ptr, thesize);
							file_to_save
							        +=
							                thesize;

							*bytes2save
							        +=
							                thesize;
						}
					}
					goto _exit__;
				}
				else
				{
					wholefile += *position;
					goto again;
				}
			}
		}
		else
		{
			//printf          ("j\n");
//just save the line , load a new line and go to again
			//printf          ("just save the line , load a new line and go to again\n");
			if (MODE_WRITE__ == process_mode)
			{
				adjust(&already,&ptr, mode,&file_to_save,bytes2save);
				memcpy (file_to_save, line, line_size);
				file_to_save += line_size;
				*bytes2save += line_size;
			}
			if (1 ==
			    get_line (wholefile, line, position,
			              &line_size))
			{
				wholefile += *position;
				//printf          ("just not found the app_name_returned, store everythiing and exit2\n");
				//just not found the app_name_returned, store everythiing and exit
				if (MODE_WRITE__ == process_mode)
				{
					adjust(&already,&ptr, mode,&file_to_save,bytes2save);
					strcpy (ptr, "[");
					strcat (ptr, app_name);
					strcat (ptr, "]");
					add_endofline (&ptr, mode);
					strcat (ptr, key_name);
					strcat (ptr, "=");
					strcat (ptr, data);
					//add_endofline(&ptr,mode);
					{
						int thesize =
						        strlen (ptr);
						memcpy (file_to_save,
						        ptr, thesize);
						file_to_save +=
						        thesize;
						*bytes2save +=
						        thesize;
					}
				}
				goto _exit__;
			}
			else
			{
				wholefile += *position;
				goto again;
			}
		}
	}
_exit__:
	;
	if (app_name_returned)
	{
		e_free (app_name_returned, __FILE__, __LINE__);
		app_name_returned = NULL;
	}
	if (ptr)
		e_free (ptr, __FILE__, __LINE__);
	return returnvalue;
}
enum
{
	MODE_IS_REPLACE__,
	MODE_IS_COUNT__,
};
int
replace_or_count_stringsensitive_arab (int mode, char *data, int datalen,
                                       char *search_string,
                                       int search_string_len, char *replace,
                                       int replace_len, int *count,
                                       char **output_string, int *output_len)
{
	int                      q;
	char *final = ((void *) 0);
	//int          desloca = 0;
	int                    ret;
	int                sizeret;
	int         deslocador = 0;
	int          len = datalen;
	int             size__ = 0;
	double                   a;
	double               adest;
	double                asrc;
	//int position=0;
	int              debug = 0;
	int                      i;
	int                      p;
	*output_len            = 0;
	if (count                 )
	{
		*count             = 0;
	}
	adest = (double) replace_len;
	if (0 == search_string_len)
	{
		asrc = (double) 1;
	}
	else
	{
		asrc = (double) search_string_len;
	}
	a = adest / asrc;
	size__ = (int) ceil (a);
	size__++;
	if (MODE_IS_REPLACE__ == mode)
	{
		final = e_calloc (1, (len * size__) + 10000);//for safety
		*output_string = final;
		if (NULL == final)
		{
			return -1;
		}
	}
	ret                   = len;
	sizeret = search_string_len;
	
	if (sizeret > ret)
	{
		if (MODE_IS_REPLACE__ == mode)
		{
			//printf("here 1 len %d , in %d out %d\n",len,search_string_len,replace_len);
			memcpy(*output_string, data,datalen);
			(*output_string)[datalen]=0;
			*output_len=datalen;
			//(*output_string)[datalen]=0;
		}
		return 0;
	}
	//printf("passed \n");
/*
        if((0==strcmp("&",search_string))||(0==strcmp("&",replace)))
        debug=0;
 */
	//memset(final,0,
	for(i=0; i<datalen; i++)
	{
		if(data[i]==search_string[0])
		{
			{
				int deslocasize=i;
				//int real=deslocador;
				for(p=0; p<search_string_len; p++)
				{
					if(datalen<=deslocasize)
					{
						if(debug)
							printf("out of bounds trigger %d %d \n",deslocasize,datalen);
						goto naoachou;
					}
					if(data[deslocasize++]!=search_string[p])
					{
						if(debug)
							printf("pulou em %d\n",p);
						goto naoachou;
					}
				}
				if(debug)
					printf("esta trocando\n");
				for(q=0; q<replace_len; q++)
				{
					if(debug)
						printf("trocando aqui \n");
					final[deslocador++]=replace[q];
				}
				i+=search_string_len-1;
				goto vai;
naoachou:
				;
			}
			final[deslocador++]=data[i];
		}
		else
		{
			final[deslocador++]=data[i];
		} vai :
		;
	}
	final[deslocador]=0;
	*output_len=deslocador;
	;
	return 0;
}
int
string_remove (char *data, int datalen,
               char *search_string, int search_string_len,
               char **output_string, int *output_len)
{
	int size__ = datalen;
	char *ptr = e_malloc (size__ + 1);
	char *ptr2 = data;
	int slen = search_string_len;
	int p;
	*output_len = 0;
	*output_string = ptr;
	if (NULL == ptr)
	{
		return -1;
	}
	while (*ptr2)
	{
		if (*ptr2 == search_string[0])
		{
			for (p = 0; p < slen; p++)
			{
				if (ptr2[p] != search_string[p])
				{

					goto pulou;
				}
			}
			ptr2 += slen;
			continue;
		}
pulou:
		*ptr = *ptr2;
		ptr++;
		ptr2++;
		(*output_len)++;
	}
	*ptr = 0;
	return 0;
}

int __stdcall
get_error_string (int val, char *data)
{

	switch (val)
	{
	case 1:
		strcpy (data, "Memory allocation failed");
		break;
	case 2:
		strcpy (data, "Error retrieving file size");
		break;
	case 3:
		strcpy (data, "Failed to read the ini file");
		break;
	case 4:
		strcpy (data, "Error during close of ini file to read");
		break;
	case 5:
		strcpy (data, "Failed to open ini file to save");
		break;
	case 6:
		strcpy (data,
		        "System or disk error during save of ini file");
		break;
	case 7:
		strcpy (data, "Error during close of ini file to read");
		break;
	case 8:
		strcpy (data, "Error during close of ini file to save");
		break;
	}
	return 0;

}
static int stringreplace(char *data,int data_len
                         ,char*search,
                         int searchlen,
                         char*replace,
                         int replacelen,
                         int*out_len,char**outdata)
{
	int ret;
	int count;
	ret = replace_or_count_stringsensitive_arab (MODE_IS_REPLACE__,
	                                             data,
	                                             data_len, search,
	                                             searchlen, replace, replacelen, &count,
	                                             outdata, out_len);
	return ret;
}
int
internal_write_ini (char *app_name, char *key_name, char *data,
                    char *ini_file, int mode,
                    int end_of_line_mode, int bytes_to_save, char *read_data,int filename_is_utf8)
{

	//No Unix, um LF(10) ï¿½ frequentemente chamado de nova linha.
	//* LF:    Unix, Linux, AIX, Xenix, Mac OS X, BeOS, Amiga, RISC OS e outros.
	//* CR+LF: CP/M, MP/M, DOS, OS/2, Microsoft Windows
	//* CR:    Commodore, Apple II e Mac OS atï¿½ Mac OS 9.
	//'\n' (newline or line feed (10)LF) e '\r' (carriage return(13)CR)., sendo assim "\r\n"
	int returnvalue = 0;
	int outlen;
	int count2;
	char *key_name_a = NULL;
	char *key_name_b = NULL;
	int ret;

	//printf          ("1\n");

	ret = replace_or_count_stringsensitive_arab (MODE_IS_REPLACE__,
	                                             key_name,
	                                             strlen (key_name), "[",
	                                             1, "_[", 2, &count2,
	                                             &key_name_a, &outlen);
	if (-1 == ret)
	{
		returnvalue = 1;        //Memory allocation failed
		goto _exit__;
	}
	ret = replace_or_count_stringsensitive_arab (MODE_IS_REPLACE__,
	                                             key_name_a,
	                                             strlen (key_name_a), "=",
	                                             strlen ("="), "_equal_",
	                                             strlen ("_equal_"),
	                                             &count2, &key_name_b,
	                                             &outlen);
	if (-1 == ret)
	{
		returnvalue = 1;
		goto _exit__;
	}
	{
		int error = 0;
		int _size2 = getfilesize_v2 (ini_file, &error,filename_is_utf8);
		int _size = (_size2 * 2) + 100;
		char *wholefile = e_calloc (_size2 + 1, 1);
		char *line = e_calloc (_size, 1);
		char *file_to_save = NULL;
		char *file_to_saveb = file_to_save;
		int ret;
		int position2 = 0;
		int bytes2save = 0;
		FILE *myfile = NULL;
		FILE *myfile2 = NULL;
		//printf          ("3\n");

		if (0 != error)
		{
			returnvalue = 2;        //Error retrieving file size
			goto _exit__;
		}
		if (MODE_WRITE__ == mode)
		{
			//printf          ("Alocando file_to_save %d \n",_size+strlen(app_name)+strlen(key_name_b)+strlen(data)+1000);
			file_to_save =
			        e_calloc (_size + strlen (app_name) +
			                  strlen (key_name_b) +
			                  strlen (data) + 1000, 1);
			file_to_saveb = file_to_save;
			//printf          (" %x\n",file_to_save);
			if (NULL == file_to_save)
			{
				returnvalue = 1;
				goto _exit__;
			}
		}

		if (NULL == wholefile)
		{
			returnvalue = 1;
			goto _exit__;
		}
		//printf          ("4\n");

		if (NULL == line)
		{
			returnvalue = 1;        //
			goto _exit__;
		}

		if(filename_is_utf8)
		{
			unicode_large *ul=calloc(sizeof(unicode_large),1);
			myfile2 = _wfopen (utf8towide_fixed(ul,ini_file), L"rb");
			free(ul);
		}
		else
		{
			myfile2 = fopen (ini_file, "rb");
		}

		if (NULL == myfile2)
		{
			//returnvalue =4;
			//goto _exit__;
			wholefile[0] = 0;
		}
		else
		{
			ret = fread (wholefile, 1, _size2, myfile2);
			if (0 != ferror (myfile2))
			{
				returnvalue = 3;        //Failed to read the ini file
				goto _exit__;
			}

			if (EOF == fclose (myfile2))
			{
				returnvalue = 4;        //Error during close of ini file to read
				myfile2 = NULL;
				goto _exit__;
			}
			//printf          ("Close on myfile2\n");
			myfile2 = NULL;
		}
		//printf          ("5\n");

		if (MODE_WRITE__ == mode)
		{
			//printf          ("mode write\n");
			ret = process (wholefile, line, app_name, key_name_b, data, file_to_saveb, end_of_line_mode, &position2, &bytes2save, _size, mode, 0, NULL);    //ok

		}
		else
		{
			ret = process (wholefile, line, app_name,
			               key_name_b, data, file_to_saveb,
			               end_of_line_mode, &position2,
			               &bytes2save, _size, mode,
			               bytes_to_save, read_data);
		}
		file_to_saveb += bytes2save;
		if (ret)
		{
			switch (ret)
			{
			case 0:
				goto noerror;           //No error
				break;
			case 1:
				returnvalue = 1;
				break;
			case 2:
				returnvalue = 1;
				break;
			case 3:
				returnvalue = 1;
				break;
			}
			goto _exit__;
		}
noerror:
		;
		if (MODE_WRITE__ == mode)
		{
			if(filename_is_utf8)
			{
				unicode_large *ul=calloc(sizeof(unicode_large),1);
				myfile = _wfopen (utf8towide_fixed(ul,ini_file), L"wb");
				free(ul);
			}
			else
			{
				myfile = fopen (ini_file, "wb");
			}

			if (NULL == myfile)
			{
				returnvalue = 5;        //Failed to open ini file to save
				goto _exit__;
			}
			ret = fwrite (file_to_save, 1, bytes2save, myfile);
			if (0 != ferror (myfile))
			{
				returnvalue = 6;        //System or disk error during save of ini file
				goto _exit__;
			}
		}
_exit__:
		;
		if (key_name_a)
		{
			//printf          ("e_free on key_name_a\n");
			e_free (key_name_a, __FILE__, __LINE__);
		}
		if (key_name_b)
		{
			//printf          ("e_free on key_name_b\n");
			e_free (key_name_b, __FILE__, __LINE__);
		}
		if (myfile2)
		{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
			if (EOF == fclose (myfile2))
			{
				returnvalue = 7;        //Error during close of ini file to read
				goto _exit2__;
			}
#pragma GCC diagnostic pop
			//printf          ("e_free on myfile2\n");
		}
		//printf          ("8\n");
		if (MODE_WRITE__ == mode)
		{
			if (myfile)
			{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
				if (EOF == fclose (myfile))
				{
					returnvalue = 8;        //Error during close of ini file to save
					goto _exit2__;
				}
#pragma GCC diagnostic pop				
				//printf          ("e_free on myfile\n");
			}
		}
		if (wholefile)
			e_free (wholefile, __FILE__, __LINE__);
		if (line)
			e_free (line, __FILE__, __LINE__);
		if (file_to_save)
			e_free (file_to_save, __FILE__, __LINE__);
_exit2__:
		;
		return returnvalue;
	}
}
int __stdcall
write_ini_unix (char *app_name, char *key_name, char *data, char *ini_file,int filename_is_utf8)
{
	return internal_write_ini (app_name, key_name, data, ini_file,
	                           MODE_WRITE__, MODE_UNIX__, 0, NULL,filename_is_utf8);
}

int __stdcall
write_ini_windows (char *app_name, char *key_name, char *data, char *ini_file,int filename_is_utf8)
{
	//MODE_WINDOWS__
	return internal_write_ini (app_name, key_name, data, ini_file,
	                           MODE_WRITE__, MODE_WINDOWS__, 0, NULL,filename_is_utf8);
}

int __stdcall
write_ini_mac (char *app_name, char *key_name, char *data, char *ini_file,int filename_is_utf8)
{
	//MODE_MAC__
	return internal_write_ini (app_name, key_name, data, ini_file,
	                           MODE_WRITE__, MODE_MAC__, 0, NULL,filename_is_utf8);
}

int __stdcall
read_ini (char *app_name, char *key_name, char *data, int len, char *ini_file,int filename_is_utf8)
{
	return internal_write_ini (app_name, key_name, data, ini_file,
	                           MODE_READ__, MODE_UNIX__, len, data,filename_is_utf8);
}
