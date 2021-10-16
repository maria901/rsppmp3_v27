/* 2021 october */

/*

   Our software is developed with the help of The TTL Data Book
   for Design Engineers - Second Edition. 1976

     ;-)

 */

/********************************************************************************
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
 ********************************************************************************

      E-mails:
      maria@arsoftware.net.br
      pedro@locacaodiaria.com.br

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *
 *                                                                              *
 *******************************************************************************/

#include <windows.h>
#include <stdint.h>
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

#include <stdbool.h>

#include <process.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

#include "include_amanda/vorbis/vorbisfile.h"

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know
 *
 */
#define AMANDA__SIZE_w (32767)

#define AMANDA__SIZE_ww ((32767 * 2) + 2)

void pedro_dprintf(int amanda_level,
                   char *format, ...);

void add_to_buffer(char *data, int len);

#include "rspogg_v2.h"

int modooriginal;

#define VERSIONSTRING "Borrowed from OggDec 5.0\n"

static int quiet = 0;
static int bits = 16;
static int endian = 0;
static int sign = 1;
unsigned char headbuf[44]; /* The whole buffer */

#define WRITE_U32(buf, x)                                \
     *(buf) = (unsigned char)((x)&0xff);                 \
     *((buf) + 1) = (unsigned char)(((x) >> 8) & 0xff);  \
     *((buf) + 2) = (unsigned char)(((x) >> 16) & 0xff); \
     *((buf) + 3) = (unsigned char)(((x) >> 24) & 0xff);

#define WRITE_U16(buf, x)                \
     *(buf) = (unsigned char)((x)&0xff); \
     *((buf) + 1) = (unsigned char)(((x) >> 8) & 0xff);

/*
 * Some of this based on ao/src/ao_wav.c
 */
static int
write_prelim_header(FILE *out, int channels, int samplerate)
{

     int knownlength = 0;

     unsigned int size = 0x7fffffff;

     int bytespersec = channels * samplerate * bits / 8;
     int align = channels * bits / 8;
     int samplesize = bits;

     if (knownlength)
          size = (unsigned int)knownlength;

     memcpy(headbuf, "RIFF", 4);
     WRITE_U32(headbuf + 4, size - 8);
     memcpy(headbuf + 8, "WAVE", 4);
     memcpy(headbuf + 12, "fmt ", 4);
     WRITE_U32(headbuf + 16, 16);
     WRITE_U16(headbuf + 20, 1); /* format */
     WRITE_U16(headbuf + 22, channels);
     WRITE_U32(headbuf + 24, samplerate);
     WRITE_U32(headbuf + 28, bytespersec);
     WRITE_U16(headbuf + 32, align);
     WRITE_U16(headbuf + 34, samplesize);
     memcpy(headbuf + 36, "data", 4);
     WRITE_U32(headbuf + 40, size - 44);

     if (fwrite(headbuf, 1, 44, out) != 44)
     {
          // printf ("ERROR: Failed to write wav header: %s\n", strerror (errno));
          return 1;
     }

     return 0;
}

static int
rewrite_header(FILE *out, unsigned int written)
{
     unsigned int length = written;

     length += 44;

     WRITE_U32(headbuf + 4, length - 8);
     WRITE_U32(headbuf + 40, length - 44);
     if (fseek(out, 0, SEEK_SET) != 0)
     {
          // printf ("ERROR: Failed to seek on seekable file: %s\n",
          // strerror (errno));
          return 1;
     }

     if (fwrite(headbuf, 1, 44, out) != 44)
     {
          // printf ("ERROR: Failed to write wav header: %s\n", strerror (errno));
          return 1;
     }
     return 0;
}

int errno_18_27 = 0;
void add_to_buffer(char *data, int len);
void set_this_thread_to_idle_17_55_23_june_2011(void);
extern int is_decoding;
extern int method_is_internal_pcm;
extern char *buffer_initial_address;
extern char *buffer_final_address;
extern char *buffer_current_address;

int allocate_the_memory_23_06_2011(
    double seconds,
    int rate,
    int channels);

extern int cancelflag;

#define BucaneiroMin(a, b) ((a) < (b) ? (a) : (b))

enum morcego_decoder_constants
{

     BE_INITIAL_STATE,
     BE_DECODED,
     BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE,
     BE_ERROR_DURING_DECODE,
     BE_DECODER_NOT_LOADED,

};

enum Amanda_Command
{

     KOCI_INIT__ = 1001,
     KOCI_PROCESS__,
     KOCI_FINISH__,

};
enum Amanda_Status
{

     PEREIRA_HAS_DATA = 1002,
     PEREIRA_NO_MORE_DATA,

};

enum decoder_id_maria
{
     AMANDA_OPUS__ = 1001,
     AMANDA_OGG_VORBIS,
};

typedef struct pedro_27_
{
     int64_t duracao_feline;
     int64_t raw_total_ric;
     int64_t sample_rate_v;
     int64_t channels_p;
} juliete_struct;

typedef struct pedro_k_
{
     char *of;
     char *filename_utf_8_m;
     int *error_code_aline_;
     int current_decoder_pedro;
     int current_bitrate_juliete;
     int the_andrea_command;
     int decoder_status_mislaine;
     int ret_m;
     int prev_li_j;
     int64_t bytes_in_the_buffer_paul;
     char buffer_junior[192000];
     char *ptr_data_position_douglas;
     juliete_struct dados_do_audio_ar;











     
} pedro_k;

int ogg_decode_file_shinkal(char *infile,
                            char *outfile,
                            double *seconds_,
                            int *channels_,
                            int *samplerate_,
                            char *media_description,
                            int *out_bitrate,
                            pedro_k *maria_struct_);

int ogg_decode_file_shinkal(__attribute__((unused)) char *infile,
                            __attribute__((unused)) char *outfile,
                            __attribute__((unused)) double *seconds_,
                            __attribute__((unused)) int *channels_,
                            __attribute__((unused)) int *samplerate_,
                            __attribute__((unused)) char *media_description,
                            __attribute__((unused)) int *out_bitrate,
                            __attribute__((unused)) pedro_k *maria_struct_)
{
     int retval = 0;
     FILE *in = NULL;
     // FILE *out = NULL;
     OggVorbis_File vf;
     int bs = 0;
     char buf[8192];
     int buflen = 8192;
     unsigned int written = 0;
     int ret;
     int open_ = 0;

     if (KOCI_INIT__ == maria_struct_->the_andrea_command)
     {
          maria_struct_->ptr_data_position_douglas = maria_struct_->buffer_junior;

          maria_struct_->bytes_in_the_buffer_paul = 0;
          ; // do nothing it is ok...
     }

     if (KOCI_PROCESS__ == maria_struct_->the_andrea_command)
     {
          goto entering_function_pedro;
     }

     if (KOCI_FINISH__ == maria_struct_->the_andrea_command)
     {
          goto exit_function_pedro;
     }

     // printf("esfregue a lampada\n");
     in = fopen((infile), "rb");
     if (!in)
     {
          ;
          return 2;
          // goto saida;
     }

     /*
     out = fopen((outfile), "wb");
     if (!out)
     {
          ;
          retval = 2;
          goto saida;
     }
     */

     if (ov_open(in, &vf, NULL, 0) < 0)
     {
          ;
          fclose(in);

          return 3;
     }
     open_ = 1;
     {
          vorbis_comment *com;
          int channels;
          int rate;
          int version;

          channels = ov_info(&vf, 0)->channels;
          *channels_ = channels;
          rate = ov_info(&vf, 0)->rate;

          // write_prelim_header(out, channels, rate);

          *samplerate_ = rate;
          version = ov_info(&vf, 0)->version;
          // ov_info (&vf, 0)->bitrate_nominal;
          *out_bitrate = ov_info(&vf, 0)->bitrate_nominal;
          *out_bitrate = *out_bitrate / 1000;
          *seconds_ = ov_time_total(&vf, -1);
          com = ov_comment(&vf, -1);
          memset(media_description, 0, 300);

          if (com && com->vendor)
          {
               if (strlen(com->vendor) < 300)
               {
                    strcpy(media_description, com->vendor);
               }
               else
               {
                    strcpy(media_description, "");
               }
          }
          else
          {
               strcpy(media_description, "");
          }
          {
               char temp[300];
               sprintf(temp, "%d\n", version);

               strcat(media_description, " ");
               strcat(media_description, temp);
          }
     }

     /*
        if(allocate_the_memory_23_06_2011(
   *seconds_,
   *samplerate_,
   *channels_)
           )
        {
                errno_18_27=1;
                retval = 1;
                goto saida;
        }
 */
     if (ov_seekable(&vf))
     {
          // length = ov_pcm_total (&vf, 0);
          // size = bits / 8 * ov_info (&vf, 0)->channels;
     }

entering_function_pedro:;

     while ((ret = ov_read(&vf, buf, buflen, endian, bits / 8, sign, &bs)) != 0)
     {
          if (bs != 0)
          {
               break;
          }

          if (ret < 0 && !quiet)
          {
               continue;
          }

          {
               // int len;
               //  add_to_buffer(buf,ret);
               /*
               len = fwrite(buf, 1, ret, out);
               if (len != ret)
               {
                    retval = 10;
                    goto saida;
               }
               */
          }
          written += ret;
     }
     // rewrite_header(out, written);
// saida:;
exit_function_pedro:;

     vf.datasource = NULL;
     if (open_)
          ov_clear(&vf);

     if (in)
          fclose(in);

     return retval;
}

#include "win64.h"

char *__stdcall svc_init_ogg_m(char *filename_utf_8_v,
                               int *error_code_aline_,
                               juliete_struct *dados_m);

char *__stdcall svc_init_ogg_m(__attribute__((unused)) char *filename_utf_8_v,
                               __attribute__((unused)) int *error_code_aline_,
                               __attribute__((unused)) juliete_struct *dados_m)
{
     double seconds_;
     int channels_;
     int samplerate_;
     char media_description[1000];
     int out_bitrate;

     char *ptr_shinkal;
     (void)ptr_shinkal;
     (void)OV_CALLBACKS_STREAMONLY_NOCLOSE;
     (void)OV_CALLBACKS_STREAMONLY;
     (void)OV_CALLBACKS_NOCLOSE;
     (void)OV_CALLBACKS_DEFAULT;

     pedro_dprintf(-15, "svc_init_opus_m\n");
     pedro_k *feline_p = calloc(sizeof(pedro_k), 1);
     // assert(0);
     if (NULL == feline_p)
     {
          *error_code_aline_ = 10001; // Cannot allocate memory
          return NULL;
     }
     feline_p->current_decoder_pedro = AMANDA_OGG_VORBIS;
     feline_p->error_code_aline_ = error_code_aline_;
     assert(feline_p->error_code_aline_);
     feline_p->filename_utf_8_m = calloc(AMANDA__SIZE, 1);

     strcpy(feline_p->filename_utf_8_m, filename_utf_8_v);
     pedro_dprintf(-14, "debug 1\n");

     feline_p->the_andrea_command = KOCI_INIT__;

     ogg_decode_file_shinkal("jota.ogg",

#ifdef WIN64
                             "carlinhos.wav",
#else
                             "edson.wav",
#endif

                             &seconds_,
                             &channels_,
                             &samplerate_,
                             media_description,
                             &out_bitrate,
                             feline_p);
     // main_old_p(feline_p);

     pedro_dprintf(-14, "debug 2\n");
     assert(error_code_aline_);
     assert(feline_p);
     assert(feline_p->error_code_aline_);
     if (10004 == *feline_p->error_code_aline_)
     {
          free(feline_p->filename_utf_8_m);
          free(feline_p);
          return NULL;
     }

     // if opus
     feline_p->dados_do_audio_ar.sample_rate_v = 48000;
     feline_p->dados_do_audio_ar.channels_p = 2;

     *dados_m = feline_p->dados_do_audio_ar;
     pedro_dprintf(-14, "debug 3\n");
     return (char *)feline_p;
}

int __stdcall morcego_decode_libav_svc_process_ogg_m(__attribute__((unused)) char *struct_opus_m,
                                                     __attribute__((unused)) int bytes_to_decode_m,
                                                     __attribute__((unused)) char *bufout_m,
                                                     __attribute__((unused)) int *size_out);
int __stdcall morcego_decode_libav_svc_process_ogg_m(__attribute__((unused)) char *struct_opus_m,
                                                     __attribute__((unused)) int bytes_to_decode_m,
                                                     __attribute__((unused)) char *bufout_m,
                                                     __attribute__((unused)) int *size_out)
{
     return -27;
}
void morcego_deinit_libav_svc_deinit_ogg_m(char *struct_opus_m);
void morcego_deinit_libav_svc_deinit_ogg_m(__attribute__((unused)) char *struct_opus_m)
{
     return;
}

void __stdcall svc_seek_ogg_m(__attribute__((unused)) char *struct_opus_m,
                              __attribute__((unused)) double maquisistem_value);
void __stdcall svc_seek_ogg_m(__attribute__((unused)) char *struct_opus_m,
                              __attribute__((unused)) double maquisistem_value)
{
     return;
}