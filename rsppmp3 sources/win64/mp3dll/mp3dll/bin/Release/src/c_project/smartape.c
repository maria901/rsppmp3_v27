
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

static int replacestringsensitive2_feline(char *comando, char *source, char *dest);

#include "be_xml.c"

/**
 * My fixed strncpy
 *
 *
 */
void strncpy_z(char *dest_z, char *src_z, size_t len)
{
    assert(0 <= len);

    len--;

    if (0 > len)
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

    char     small_buffer_amanda_s_smart_ape[100];
    char *   ini_buffer = NULL;
    char *   read_buffer_amanda_s_smart_ape = calloc(1, AMANDA_S_SMART_APE_SIZE);
    FILE *   cs_file_in__amanda_s_smart_ape = NULL;
    FILE *   cs_file_out_amanda_s_smart_ape = NULL;
    int      amandaricardo_build_sex;
    int      amandaricardo_major;
    int      amandaricardo_minor;
    int      amandaricardo_revision;
    int      ret_amanda_s_smart_ape;
    int64_t  size_of_ini_amanda_s_smart_ape;

    int return_value_amanda_s_smart_ape = 0;

    if (8 != argc_amanda_s_smart_ape)
    {
        printf("Wrong number of arguments\n");
        return_value_amanda_s_smart_ape = 10; //se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
    }

    //tem que ler os contadores e incrementar eles se for o caso

    size_of_ini_amanda_s_smart_ape = getfilesize_ar_may_fail_amanda_s_smart_ape(argv_amanda_s_smart_ape[1]);

    if (-1 == size_of_ini_amanda_s_smart_ape)
    {
        size_of_ini_amanda_s_smart_ape = 10000;//magic value...
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

if(ret_amanda_s_smart_ape)
{
    write_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
    "amandaricardo_major",
    "0"
    );

    ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                           "amandaricardo_major",
                                                           ini_buffer,
                                                           size_of_ini_amanda_s_smart_ape + 1);
    if (ret_amanda_s_smart_ape)
    {
        printf("Ini file -> %s <- is invalid or locked\n", argv_amanda_s_smart_ape[1]);
        return_value_amanda_s_smart_ape = 30; //se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
    }
}

amandaricardo_major = atoi(ini_buffer);

//printf("pegou .%d. .%s.", amandaricardo_major, ini_buffer);

ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                           "amandaricardo_minor",
                                                           ini_buffer,
                                                           size_of_ini_amanda_s_smart_ape + 1);
if(ret_amanda_s_smart_ape)
{
    printf("Ini file -> %s <- is invalid\n", argv_amanda_s_smart_ape[1]);
        return_value_amanda_s_smart_ape = 40; //se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
}

amandaricardo_minor = atoi(ini_buffer);

ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                           "amandaricardo_revision",
                                                           ini_buffer,
                                                           size_of_ini_amanda_s_smart_ape + 1);
if(ret_amanda_s_smart_ape)
{
    printf("Ini file -> %s <- is invalid\n", argv_amanda_s_smart_ape[1]);
        return_value_amanda_s_smart_ape = 40; //se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
        goto saida_amanda_s_smart_ape;
}

amandaricardo_revision = atoi(ini_buffer);

ret_amanda_s_smart_ape = read_xml_z_amanda_s_smart_ape(argv_amanda_s_smart_ape[1],
                                                           "amandaricardo_build_sex",
                                                           ini_buffer,
                                                           size_of_ini_amanda_s_smart_ape + 1);
if(ret_amanda_s_smart_ape)
{
    printf("Ini file -> %s <- is invalid\n", argv_amanda_s_smart_ape[1]);
        return_value_amanda_s_smart_ape = 40; //se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
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

    //write now

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

//now update the file...

cs_file_in__amanda_s_smart_ape = fopen(argv_amanda_s_smart_ape[2], "rb");
if(cs_file_in__amanda_s_smart_ape)
{
    cs_file_out_amanda_s_smart_ape = fopen(argv_amanda_s_smart_ape[3], "wb");
    if (cs_file_out_amanda_s_smart_ape)
    {
        ret_amanda_s_smart_ape = fread(read_buffer_amanda_s_smart_ape, 1, AMANDA_S_SMART_APE_SIZE, cs_file_in__amanda_s_smart_ape);

        if (AMANDA_S_SMART_APE_SIZE == ret_amanda_s_smart_ape)
        {
            printf("Maximum file size limit reached -> %d\n", AMANDA_S_SMART_APE_SIZE);
            return_value_amanda_s_smart_ape = 50; //se voce da nome pros bois depois nao da pra mudar amigo...tem que ser pra sempre
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

        fwrite(read_buffer_amanda_s_smart_ape, 1, strlen(read_buffer_amanda_s_smart_ape), cs_file_out_amanda_s_smart_ape);
    }
}

saida_amanda_s_smart_ape:

    if (ini_buffer)
    {
        free(ini_buffer);
        ini_buffer = NULL;
    }
    if(read_buffer_amanda_s_smart_ape)
    {
        free(read_buffer_amanda_s_smart_ape);
        read_buffer_amanda_s_smart_ape = NULL;
    }
    if(cs_file_out_amanda_s_smart_ape)
    fclose(cs_file_out_amanda_s_smart_ape), cs_file_out_amanda_s_smart_ape =NULL;
    if(cs_file_in__amanda_s_smart_ape)
    fclose(cs_file_in__amanda_s_smart_ape), cs_file_in__amanda_s_smart_ape =NULL;
    return return_value_amanda_s_smart_ape;

}