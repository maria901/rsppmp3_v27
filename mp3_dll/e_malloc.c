
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

/* enhanced malloc */
/*

Wed Apr 20 GMT 19:11:15 2011 , by arab

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

/* 

__MINGW32__ or __GNUC__ in mingw
WIN32 both mingw and msvc
#if defined (__MINGW32__) || defined (WIN32)

*/

#define DEBUG___

void e_memory_test(void *ptr,char*source,int line);
void *e_calloc(size_t nelem, size_t size__);
void *e_malloc(size_t size__);
void *e_realloc(void *ptr, size_t size__);
void e_free(void *ptr,char*source,int line);

static void
mprintf___ (char *format, ...)
{
	/* void *calloc(size_t nelem, size_t size); */
    char *buffer=calloc(1, 10000); //for multithread sake
    va_list amanda;
    va_start(amanda, format);
    vsprintf (buffer, format, amanda);
    MessageBox (0, buffer, "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
	va_end(amanda);
    free(buffer);
}

void *e_malloc(size_t size__)
{
#ifdef DEBUG___
    char *ptr;
    int *iptr;
    char*returnvalue;
    ptr=malloc((size__)+12);
    if(NULL==ptr)
    {
        return NULL;
    }
    iptr=(int*)ptr;
    *iptr=size__;
    iptr++;
    *iptr=0x12345678;
    ptr=(char*)iptr;
    ptr+=4;
    returnvalue=ptr;
    ptr+=size__;
    iptr=(int*)ptr;
    *iptr=0x87654321;
    return returnvalue;
#else
    return malloc(size__);
#endif
}

void *e_calloc(size_t nelem, size_t size__)
{
#ifdef DEBUG___
    char *ptr;
    int *iptr;
    char*returnvalue;
    ptr=malloc((nelem*size__)+12);
    if(NULL==ptr)
    {
        return NULL;
    }
    memset(ptr,0,(nelem*size__)+12);
    iptr=(int*)ptr;
    *iptr=nelem*size__;
    iptr++;
    *iptr=0x12345678;
    ptr=(char*)iptr;
    ptr+=4;
    returnvalue=ptr;
    ptr+=nelem*size__;
    iptr=(int*)ptr;
    *iptr=0x87654321;
    return returnvalue;
#else
    return calloc(nelem,size__);
#endif
}

void e_free(void *ptr__,char*source,int line)
{
#ifdef DEBUG___
    int *iptr;
    int nelen;
    char*a;
    char*ptr=ptr__;
    if(NULL==ptr)
    {
        mprintf___("NULL pointer being freed at source: %s line: %d ",source,line);
        exit(1);
    }
    ptr-=8;
    a=ptr;
    iptr=(int*)ptr;
    nelen=*iptr;
    iptr++;
    if(0x12345678!=*iptr)
    {
        mprintf___("Memory corruption detected at source: %s line: %d ",source,line);
        exit(1);
    }
    ptr+=8;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"	
    ptr+=nelen;
#pragma GCC diagnostic pop	
    iptr=(int*)ptr;
    if(0x87654321 != (unsigned int) *iptr)
    {
        mprintf___("Memory corruption detected at source: %s line: %d ",source,line);
        exit(1);
    }
    free(a);
#else
    free(ptr__);
#endif
    return;
}

void e_memory_test(void *ptr__,char*source,int line)
{
#ifdef DEBUG___
    int *iptr     ;
    int nelen     ;
    char*ptr=ptr__;
    if(NULL==ptr  )
    {
        mprintf___("NULL pointer being tested at source: %s line: %d ",source,line);
        exit(1)   ;
    }
    ptr       -= 8;
    iptr=(int*)ptr;
    nelen =*  iptr;
    iptr++        ;
    if(0x12345678!=*iptr)
    {
        mprintf___("Memory corruption detected at source: %s line: %d ",source,line);
        exit(1);
    }
    ptr       += 8;
    ptr +=   nelen;
    iptr=(int*)ptr;
    if(0x87654321!= (unsigned int ) *iptr)
    {
        mprintf___("Memory corruption detected at source: %s line: %d ",source,line);
        exit(1);
    }
#else

#endif
    return;
}

void *e_realloc(void *ptr__, size_t size__)
{
#ifdef DEBUG___
    char *ptr_;
    int *iptr;
    char*returnvalue;
    char*ptr=ptr__;
    ptr-=8;
    ptr_=realloc(ptr,(size__)+12);
    if(NULL==ptr_)
    {
        return NULL;
    }
    iptr=(int*)ptr_;
    *iptr=size__;
    iptr++;
    *iptr=0x12345678;
    ptr_=(char*)iptr;
    ptr_+=4;
    returnvalue=ptr_;
    ptr_+=size__;
    iptr=(int*)ptr_;
    *iptr=0x87654321;
    return returnvalue;
#else
    return realloc(ptr__,size__);
#endif
}
