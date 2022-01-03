/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                             *
*        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>        *
*                                                                             *
*     Este  programa  é software livre: você pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     10
*     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opção) qualquer versão posterior.        *
*                                                                             *
*     Este  programa é distribuído na  esperança que isto vai  ser útil,      *
*     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de      *
*     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Pública para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Pública Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito rápida) WhatsApp               *
*     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

#include /* amanda's smart ape */ <windows.h>
#include /* amanda's smart ape  */ <stdint.h>
#include /* amanda's smart ape   */ <stdio.h>
#include /* amanda's smart ape  */ <stdlib.h>
#include /* amanda's smart ape  */ <string.h>
#include /* amanda's smart ape    */ <time.h>
#include /* amanda's smart ape   */ <errno.h>
#include /* amanda's smart ape   */ <fcntl.h>
#include /* amanda's smart ape   */ <ctype.h>
#include /* amanda's smart ape    */ <math.h>
#include /* amanda's smart ape  */ <wctype.h>
#include /* amanda's smart ape   */ <wchar.h>
#include /* amanda's smart ape  */ <stdarg.h>
#include /* amanda's smart ape  */ <stddef.h>
#include /* amanda's smart ape  */ <setjmp.h>
#include /* amanda's smart ape  */ <locale.h>
#include /* amanda's smart ape  */ <signal.h>
#include /* amanda's smart ape  */ <limits.h>
#include /* amanda's smart ape   */ <float.h>
#include /* amanda's smart ape  */ <iso646.h>

#undef NDEBUG
#include /* amanda's smart ape  */ <assert.h>
#include /* amanda's smart ape */ <stdbool.h>
#include /* amanda's smart ape */ <process.h>

#define AMANDA_S_SMART_APE_SIZE ((100000))

char copyleft_cirkut[] =
    " /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\r\n"
    " *                                                                              *\r\n"
    " *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *\r\n"
    " *                                                                              *\r\n"
    " *     Este  programa  é software livre: você pode redistribuir isto e/ou       *\r\n"
    " *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8\r\n"
    " *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *\r\n"
    " *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *\r\n"
    " *                                                                              *\r\n"
    " *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *\r\n"
    " *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *\r\n"
    " *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *\r\n"
    " *     Licensa Geral Pública para mais detalhes.                                *\r\n"
    " *                                                                              *\n"
    " *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *\r\n"
    " *     Licensa Pública Menor junto com este programa                            *\r\n"
    " *     Se não, veja <http://www.gnu.org/licenses/>.                             *\r\n"
    " *                                                                              *\r\n"
    " *     Suporte: https://nomade.sourceforge.io/                                  *\r\n"
    "                                                                                 \r\n"
    " *     E-mails direto dos felizes programadores:                                *\r\n"
    " *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *\r\n"
    " *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *\r\n"
    " *                                                                              *\r\n"
    " *     contato imediato(para uma resposta muita rápida) WhatsApp                *\r\n"
    " *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *\r\n"
    " *                                                                              *\r\n"
    " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/\r\n";

static int replacestringsensitive2_feline(char *comando, char *source, char *dest);

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)

/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know
 *
 */
#define AMANDA__SIZE_w (32767)

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we
 *  . provide two functions that are exactly the same because someone may
 * use it in multi-thread code
 *
 * @param pUTF8 the input utf-8 encoded filename
 *
 * @return the static allocated WCHAR array with the filename as wide string
 *
 */
WCHAR *amanda_utf8towide_3_(char *pUTF8)
{
    static WCHAR ricardo_k[AMANDA__SIZE_w + 1];

    MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, AMANDA__SIZE_w);
    return ricardo_k;
}

/**
 * To convert an input wide string to a utf-8 encoded filename on return
 *
 * @param pUSC2_maria the wide string to be converted
 *
 * @return it will return the static allocated char * string with the utf-8 encoded filename
 *
 */
char *valquiria_wide_to_utf8_3_(WCHAR *pUSC2_maria)
{
    static char saida_utf8[AMANDA__SIZE];

    WideCharToMultiByte(CP_UTF8, 0, pUSC2_maria, -1, (LPSTR)saida_utf8, AMANDA__SIZE, 0, 0);
    return saida_utf8;
}

/**
 * To make the path wide mode aware, stolen from libarchive
 *
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond..., last visit 21/sep/2021 03:57...
 *
 */
wchar_t *
permissive_name_m_(const wchar_t *wname)
{

    return (void *) wname;
    static wchar_t *wnp = NULL;
    wchar_t *wn;
    wchar_t *ws, *wsp;
    DWORD len, slen;
    int unc;

    if (NULL == wnp)
    {
        wnp = calloc((AMANDA__SIZE_w * 2) + 2, 1);
    }

    // wnp = malloc(AMANDA__SIZE * 2);

    wcscpy(wnp, wname);

    len = wcslen(wname);

    wn = wnp;

    if (wnp[0] == L'\\' && wnp[1] == L'\\' && // access to the wrong position in memory, fixed now
        wnp[2] == L'?' && wnp[3] == L'\\')
        /* We have already a permissive name. */
        return (wn);

    if (wnp[0] == L'\\' && wnp[1] == L'\\' &&
        wnp[2] == L'.' && wnp[3] == L'\\')
    {
        /* This is a device name */
        if (((wnp[4] >= L'a' && wnp[4] <= L'z') ||
             (wnp[4] >= L'A' && wnp[4] <= L'Z')) &&
            wnp[5] == L':' && wnp[6] == L'\\')
            wnp[2] = L'?'; /* Not device name. */
        return (wn);
    }

    unc = 0;
    if (wnp[0] == L'\\' && wnp[1] == L'\\' && wnp[2] != L'\\')
    {
        wchar_t *p = &wnp[2];

        /* Skip server-name letters. */
        while (*p != L'\\' && *p != L'\0')
            ++p;
        if (*p == L'\\')
        {
            wchar_t *rp = ++p;
            /* Skip share-name letters. */
            while (*p != L'\\' && *p != L'\0')
                ++p;
            if (*p == L'\\' && p != rp)
            {
                /* Now, match patterns such as
                 * "\\server-name\share-name\" */
                wnp += 2;
                len -= 2;
                unc = 1;
            }
        }
    }

    slen = 4 + (unc * 4) + len + 1;
    ws = wsp = malloc(slen * sizeof(wchar_t));
    if (ws == NULL)
    {
        // free(wn);
        return (NULL);
    }
    /* prepend "\\?\" */
    wcsncpy(wsp, L"\\\\?\\", 4);
    wsp += 4;
    slen -= 4;
    if (unc)
    {
        /* append "UNC\" ---> "\\?\UNC\" */
        wcsncpy(wsp, L"UNC\\", 4);
        wsp += 4;
        slen -= 4;
    }
    wcsncpy(wsp, wnp, slen);
    wsp[slen - 1] = L'\0'; /* Ensure null termination. */
    // free(wn);

    wcscpy(wnp, ws);

    free(ws);

    return (wnp);
}

#include "be_xml.c"

/**
 * My fixed strncpy
 *
 *
 */
void strncpy_z(char *dest_z, char *src_z, size_t len)
{
    assert(0 <= (int)len);

    len--;

    if (0 > (int)len)
    {
        len = 0;
    }

    if (strlen(src_z) < len)
    {
        strcpy(dest_z, src_z);
    }
    else
    {
        memcpy(dest_z, src_z, len);
        dest_z[len] = 0;
    }
    return;
}

char *
getyear_my_love(void)
{
    /*

       typedef struct _SYSTEMTIME {  WORD wYear;  WORD wMonth;  WORD wDayOfWeek;
       WORD wDay;  WORD wHour;  WORD wMinute;  WORD wSecond;  WORD wMilliseconds;
       } SYSTEMTIME,
     */

    static char amanda_s_smart_ape_out[MAX_PATH];
    SYSTEMTIME lst = {
        0,
    };
    GetLocalTime(&lst);
    sprintf(amanda_s_smart_ape_out, "%04d", lst.wYear);
    return amanda_s_smart_ape_out;
}

/**
 * To get the file size, filename is utf-8
 *
 * @param infile_ar the input file
 *
 * @return the size of the file or 0 in case of error or if the file is empty, if you need
 * to know whether the file do exist use ispathfile function
 *
 */
__int64
getfilesize_ar_may_fail_amanda_s_smart_ape(char *infile_ar)
{
    __int64 ret;
    FILE *myfile;

    if ((myfile = _wfopen(amanda_utf8towide_1_(infile_ar), L"rb")) == NULL)
    {
        return -1;
    }
    ret = _fseeki64(myfile, 0, SEEK_END);
    ret = _ftelli64(myfile);
    fclose(myfile);
    return ret;
}

int __stdcall write_xml_z_amanda_s_smart_ape(char *filename_amanda_s_smart_ape, char *key_name_z, char *data_z)
{
    {
        return feline_write_xml(filename_amanda_s_smart_ape,
                                "ok12_settings_16_february_1994",
                                key_name_z,
                                NULL,
                                data_z);
    }
}

int __stdcall read_xml_z_amanda_s_smart_ape(char *filename_amanda_s_smart_ape, char *key_name_z, char *data_z, int output_len_z)
{
    int ret_arp = 0;
    char *buf_z;
    int64_t size_z;

    {
        size_z = getfilesize_ar_may_fail_amanda_s_smart_ape(filename_amanda_s_smart_ape);

        if (-1 == size_z)
        {
            strncpy_z(data_z, "", output_len_z);

            ret_arp = 3;

            goto saida_getfilesize_amanda_s_smart_ape;
        }

        buf_z = malloc(size_z + 1);
        ret_arp = feline_read_xml(filename_amanda_s_smart_ape,
                                  "ok12_settings_16_february_1994",
                                  key_name_z,
                                  NULL,
                                  buf_z);
        strncpy_z(data_z, buf_z, output_len_z);
        free(buf_z);
    }

saida_getfilesize_amanda_s_smart_ape:

    return ret_arp;
}

int main(int argc_amanda_s_smart_ape,
         char **argv_amanda_s_smart_ape)
{

    /*
[amandaricardo_nosso_counter]
amandaricardo_major=3
amandaricardo_minor=2
amandaricardo_revision=9
amandaricardo_build_sex=324

@./amandaricardo_mvbuild26_33.exe                \ 0
    amanda_s_smart_ape__counter.ini              \ 1
    AssemblyInfo.smartape                        \ 2
    AssemblyInfo.cs                              \ 3
    AssemblyInfo.hh                              \ 4
    "1024 bits"                                  \ 5
    AssemblyInfo.viu.cs 6 _increase 7

    */

    char small_buffer_amanda_s_smart_ape[100];
    char *ini_buffer = NULL;
    char *read_buffer_amanda_s_smart_ape = calloc(1, AMANDA_S_SMART_APE_SIZE);
    char *paciencia = NULL;
    FILE *cs_file_in__amanda_s_smart_ape = NULL;
    FILE *cs_file_out_amanda_s_smart_ape = NULL;
    FILE *cs_file_h___amanda_s_smart_ape = NULL;
    int amandaricardo_build_sex;
    int amandaricardo_major;
    int amandaricardo_minor;
    int amandaricardo_revision;
    int ret_amanda_s_smart_ape;
    int64_t size_of_ini_amanda_s_smart_ape;

    int return_value_amanda_s_smart_ape = 0;

    if (8 > argc_amanda_s_smart_ape)
    {
        printf("Wrong number of arguments\n");
        return_value_amanda_s_smart_ape = 10; // se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
    }

    // tem que ler os contadores e incrementar eles se for o caso

    size_of_ini_amanda_s_smart_ape = getfilesize_ar_may_fail_amanda_s_smart_ape(argv_amanda_s_smart_ape[1]);

    if (-1 == size_of_ini_amanda_s_smart_ape)
    {
        size_of_ini_amanda_s_smart_ape = 10000; // magic value...
        /*
        printf("Ini file -> %s <- cannot be found, if it is utf-8 it will fail, check the code\n", argv_amanda_s_smart_ape[1]);
        return_value_amanda_s_smart_ape = 20; //se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
        */
    }

    ini_buffer = malloc(size_of_ini_amanda_s_smart_ape + 1);

    memset(ini_buffer, 0, size_of_ini_amanda_s_smart_ape + 1);

    ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                           "amandaricardo_major",
                                                           ini_buffer,
                                                           size_of_ini_amanda_s_smart_ape + 1);

    if (ret_amanda_s_smart_ape)
    {
        write_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                       "amandaricardo_major",
                                       "0");

        ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                               "amandaricardo_major",
                                                               ini_buffer,
                                                               size_of_ini_amanda_s_smart_ape + 1);
        if (ret_amanda_s_smart_ape)
        {
            printf("Ini file -> %s <- is invalid or locked\n", argv_amanda_s_smart_ape[1]);
            return_value_amanda_s_smart_ape = 30; // se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
            goto saida_amanda_s_smart_ape;
        }
    }

    amandaricardo_major = atoi(ini_buffer);

    // printf("pegou .%d. .%s.", amandaricardo_major, ini_buffer);

    ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                           "amandaricardo_minor",
                                                           ini_buffer,
                                                           size_of_ini_amanda_s_smart_ape + 1);
    if (ret_amanda_s_smart_ape)
    {
        printf("Ini file -> %s <- is invalid\n", argv_amanda_s_smart_ape[1]);
        return_value_amanda_s_smart_ape = 40; // se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
    }

    amandaricardo_minor = atoi(ini_buffer);

    ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                           "amandaricardo_revision",
                                                           ini_buffer,
                                                           size_of_ini_amanda_s_smart_ape + 1);
    if (ret_amanda_s_smart_ape)
    {
        printf("Ini file -> %s <- is invalid\n", argv_amanda_s_smart_ape[1]);
        return_value_amanda_s_smart_ape = 40; // se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
    }

    amandaricardo_revision = atoi(ini_buffer);

    ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                           "amandaricardo_build_sex",
                                                           ini_buffer,
                                                           size_of_ini_amanda_s_smart_ape + 1);
    if (ret_amanda_s_smart_ape)
    {
        printf("Ini file -> %s <- is invalid\n", argv_amanda_s_smart_ape[1]);
        return_value_amanda_s_smart_ape = 40; // se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
    }

    amandaricardo_build_sex = atoi(ini_buffer);

    if (0 == strcmp("increase", argv_amanda_s_smart_ape[7]))
    {

        amandaricardo_revision++;

        if (9 < amandaricardo_revision)
        {
            amandaricardo_revision = 0;

            amandaricardo_minor++;

            if (9 < amandaricardo_minor)
            {
                amandaricardo_minor = 0;
                amandaricardo_major++;
                /*
            if(9 < amandaricardo_major)
            {

            }
            */
            }
        }

        amandaricardo_build_sex++;

        // write now

        sprintf(small_buffer_amanda_s_smart_ape,
                "%d",
                amandaricardo_major);

        write_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                       "amandaricardo_major",
                                       small_buffer_amanda_s_smart_ape);

        sprintf(small_buffer_amanda_s_smart_ape,
                "%d",
                amandaricardo_minor);

        write_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                       "amandaricardo_minor",
                                       small_buffer_amanda_s_smart_ape);

        sprintf(small_buffer_amanda_s_smart_ape,
                "%d",
                amandaricardo_revision);

        write_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                       "amandaricardo_revision",
                                       small_buffer_amanda_s_smart_ape);

        sprintf(small_buffer_amanda_s_smart_ape,
                "%d",
                amandaricardo_build_sex);

        write_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                       "amandaricardo_build_sex",
                                       small_buffer_amanda_s_smart_ape);
    }

    printf("Current version %d.%d.%d build %d\n",
           amandaricardo_major,
           amandaricardo_minor,
           amandaricardo_revision,
           amandaricardo_build_sex);

    // now update the file...

    cs_file_in__amanda_s_smart_ape = fopen(argv_amanda_s_smart_ape[2], "rb");
    if (cs_file_in__amanda_s_smart_ape)
    {
        cs_file_out_amanda_s_smart_ape = fopen(argv_amanda_s_smart_ape[3], "wb");
        if (cs_file_out_amanda_s_smart_ape)
        {
            ret_amanda_s_smart_ape = fread(read_buffer_amanda_s_smart_ape, 1, AMANDA_S_SMART_APE_SIZE, cs_file_in__amanda_s_smart_ape);

            if (AMANDA_S_SMART_APE_SIZE == ret_amanda_s_smart_ape)
            {
                printf("Maximum file size limit reached -> %d\n", AMANDA_S_SMART_APE_SIZE);
                return_value_amanda_s_smart_ape = 50; // se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
                goto saida_amanda_s_smart_ape;
            }

            sprintf(ini_buffer, "%d", amandaricardo_major);
            replacestringsensitive2_feline(read_buffer_amanda_s_smart_ape, "$_major_", ini_buffer);

            sprintf(ini_buffer, "%d", amandaricardo_minor);
            replacestringsensitive2_feline(read_buffer_amanda_s_smart_ape, "$_minor_", ini_buffer);

            sprintf(ini_buffer, "%d", amandaricardo_revision);
            replacestringsensitive2_feline(read_buffer_amanda_s_smart_ape, "$_revision_", ini_buffer);

            sprintf(ini_buffer, "%d", amandaricardo_build_sex);
            replacestringsensitive2_feline(read_buffer_amanda_s_smart_ape, "$_build_", ini_buffer);

            sprintf(ini_buffer, "#define AMARIC__VERSION \"%d.%d.%d build %d\"", amandaricardo_major, amandaricardo_minor, amandaricardo_revision, amandaricardo_build_sex);

            paciencia = malloc(strlen(copyleft_cirkut) + strlen(ini_buffer) + 1);

            strcpy(paciencia, copyleft_cirkut);
            strcat(paciencia, ini_buffer);
            {
                cs_file_h___amanda_s_smart_ape = fopen(argv_amanda_s_smart_ape[4], "wb");
                if (cs_file_h___amanda_s_smart_ape)
                {
                    fwrite(ini_buffer, 1, strlen(ini_buffer), cs_file_h___amanda_s_smart_ape);
                    fclose(cs_file_h___amanda_s_smart_ape);
                }
            }

            sprintf(ini_buffer, "%s", argv_amanda_s_smart_ape[6]);
            replacestringsensitive2_feline(read_buffer_amanda_s_smart_ape, "$_filename_", ini_buffer);

            sprintf(ini_buffer, "%s", argv_amanda_s_smart_ape[5]);
            replacestringsensitive2_feline(read_buffer_amanda_s_smart_ape, "$_number_of_bits_", ini_buffer);

            if (true || 8 < argc_amanda_s_smart_ape)
            {
                sprintf(ini_buffer, "%s", getyear_my_love());
                replacestringsensitive2_feline(read_buffer_amanda_s_smart_ape, "$_ano_meu_amor..._", ini_buffer);
            }

            if (9 < argc_amanda_s_smart_ape)
            {
                sprintf(ini_buffer, "%s", argv_amanda_s_smart_ape[9]);
                replacestringsensitive2_feline(read_buffer_amanda_s_smart_ape, "$_imagem_da_amanda_", ini_buffer);
            }

            fwrite(read_buffer_amanda_s_smart_ape, 1, strlen(read_buffer_amanda_s_smart_ape), cs_file_out_amanda_s_smart_ape);
        }
    }
    else
    {
        printf("Missing input file %s\n", argv_amanda_s_smart_ape[2]);
        return_value_amanda_s_smart_ape = 51; // se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
    }

saida_amanda_s_smart_ape:

    if (ini_buffer)
    {
        free(ini_buffer);
        ini_buffer = NULL;
    }

    if (paciencia)
    {
        free(paciencia);
        paciencia = NULL;
    }

    if (read_buffer_amanda_s_smart_ape)
    {
        free(read_buffer_amanda_s_smart_ape);
        read_buffer_amanda_s_smart_ape = NULL;
    }
    if (cs_file_out_amanda_s_smart_ape)
        fclose(cs_file_out_amanda_s_smart_ape), cs_file_out_amanda_s_smart_ape = NULL;
    if (cs_file_in__amanda_s_smart_ape)
        fclose(cs_file_in__amanda_s_smart_ape), cs_file_in__amanda_s_smart_ape = NULL;
    return return_value_amanda_s_smart_ape;
}
