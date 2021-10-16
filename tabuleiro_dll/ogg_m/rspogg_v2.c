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

/**
 * To make the path wide mode aware, stolen from libarchive
 *
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond...
 *
 */
wchar_t *
permissive_name_m_(const wchar_t *wname, WCHAR *ar_temp);
/**
 * To make the path wide mode aware, stolen from libarchive
 *
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond...
 *
 */
wchar_t *
permissive_name_m_(const wchar_t *wname, WCHAR *ar_temp)
{

     wchar_t *wnp = NULL;
     wchar_t *wn;
     wchar_t *ws, *wsp;
     DWORD len, slen;
     int unc;

     wnp = ar_temp;

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

WCHAR *amanda_utf8towide_1_(char *pUTF8, WCHAR *ar_temp);

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
WCHAR *amanda_utf8towide_1_(char *pUTF8, WCHAR *ar_temp)
{
     WCHAR *ricardo_k = ar_temp;

     MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, AMANDA__SIZE_w);
     return ricardo_k;
}
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
     char media_description_m[1024];
} juliete_struct;

typedef struct pedro_k_
{
     OggVorbis_File *vf;
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

     // for Ogg Vorbis only but required also in Opus
     int open_m;
     FILE *in_m;

     OggVorbis_File vf_real_m;

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
     // FILE *in = NULL;
     //  FILE *out = NULL;
     // OggVorbis_File vf;
     int bs = 0;
     char buf[8192];
     int buflen = 8192;
     // unsigned int written = 0;
     int ret;
     // int open_ = 0;

     if (KOCI_INIT__ == maria_struct_->the_andrea_command)
     {
          maria_struct_->ptr_data_position_douglas = maria_struct_->buffer_junior;

          maria_struct_->bytes_in_the_buffer_paul = 0;
          ; // do nothing it is ok...

          maria_struct_->open_m = 0;
          maria_struct_->in_m = NULL;
          pedro_dprintf(0, "poque nao chama ?");
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
     {
          WCHAR *temp_m = malloc(AMANDA__SIZE_ww);
          WCHAR *temp2_m = malloc(AMANDA__SIZE_ww);

          pedro_dprintf(0, "file %s", infile);
          pedro_dprintf(0, "file 2 %s", maria_struct_->filename_utf_8_m);
          maria_struct_->in_m = _wfopen(permissive_name_m_(amanda_utf8towide_1_(maria_struct_->filename_utf_8_m, temp_m), temp2_m), L"rb");
          pedro_dprintf(0, "passou %s", infile);
          // maria_struct_->in_m = fopen(((infile)), "rb");
          free(temp_m);
          free(temp2_m);
     }
     if (!maria_struct_->in_m)
     {
          *maria_struct_->error_code_aline_ = 10003; // will never occur...

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

     maria_struct_->vf = &maria_struct_->vf_real_m;
     pedro_dprintf(0, "passou 3.1 %s %p %p", infile, maria_struct_->in_m, maria_struct_->vf);
     if (ov_open(maria_struct_->in_m, maria_struct_->vf, NULL, 0) < 0)
     {
          ;
          fclose(maria_struct_->in_m);
          *maria_struct_->error_code_aline_ = 10004; // Cannot open media file, don't need to close file or free resources

          return 3;
     }

     pedro_dprintf(0, "passou 3 %s", infile);

     maria_struct_->open_m = 1;
     {
          vorbis_comment *com;
          int channels;
          int rate;
          int version;

          channels = ov_info(maria_struct_->vf, 0)->channels;
          *channels_ = channels;

          rate = ov_info(maria_struct_->vf, 0)->rate;

          // write_prelim_header(out, channels, rate);

          *samplerate_ = rate;
          version = ov_info(maria_struct_->vf, 0)->version;
          // ov_info (&vf, 0)->bitrate_nominal;
          *out_bitrate = ov_info(maria_struct_->vf, 0)->bitrate_nominal;
          *out_bitrate = *out_bitrate / 1000;
          *seconds_ = ov_time_total(maria_struct_->vf, -1);
          *seconds_ = *seconds_ * 1000.0 * 1000.0;
          maria_struct_->dados_do_audio_ar.duracao_feline = (int64_t)*seconds_;
          pedro_dprintf(0, "duracao inside %lld", maria_struct_->dados_do_audio_ar.duracao_feline);
          com = ov_comment(maria_struct_->vf, -1);
          memset(media_description, 0, 300);

          {
               maria_struct_->dados_do_audio_ar.sample_rate_v = *samplerate_;
               maria_struct_->dados_do_audio_ar.channels_p = *channels_;

               if (2 < *channels_)
               {
                    pedro_dprintf(1001, "Cannot handle more than 2 channels in Vorbis at this moment");
                    maria_struct_->vf->datasource = NULL;
                    if (maria_struct_->open_m)
                         ov_clear(maria_struct_->vf);

                    if (maria_struct_->in_m)
                         fclose(maria_struct_->in_m);
                    ;

                    *maria_struct_->error_code_aline_ = 10004; // Cannot open media file, don't need to close file or free resources

                    return 3;
               }
          }
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
          strcpy(maria_struct_->dados_do_audio_ar.media_description_m, "Ogg ;-) ");
          strcat(maria_struct_->dados_do_audio_ar.media_description_m, media_description);
          pedro_dprintf(0, "description -> %s\n", media_description);
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

     maria_struct_->dados_do_audio_ar.raw_total_ric = 1;

     if (ov_seekable(maria_struct_->vf))
     {
          // int ov_raw_seek(OggVorbis_File *vf,long pos); for posterity
          maria_struct_->dados_do_audio_ar.raw_total_ric = ov_raw_total(maria_struct_->vf, -1);
          // length = ov_pcm_total (&vf, 0);
          // size = bits / 8 * ov_info (&vf, 0)->channels;
     }

entering_function_pedro:;

     maria_struct_->decoder_status_mislaine = PEREIRA_HAS_DATA;

     while ((ret = ov_read(maria_struct_->vf, buf, buflen, endian, bits / 8, sign, &bs)) != 0)
     {
          if (bs != 0)
          {
               maria_struct_->decoder_status_mislaine = PEREIRA_NO_MORE_DATA;
               return 0;
               break;
          }

          if (ret < 0 && !quiet)
          {
               continue;
          }

          // if (ret)
          {
               assert(192000 > ret);
               memcpy(maria_struct_->buffer_junior, buf, ret);
               maria_struct_->ptr_data_position_douglas = maria_struct_->buffer_junior;
               maria_struct_->bytes_in_the_buffer_paul += ret;
               return 0;
          }
     }
     maria_struct_->decoder_status_mislaine = PEREIRA_NO_MORE_DATA;
     return 0;

exit_function_pedro:;

     maria_struct_->vf->datasource = NULL;
     if (maria_struct_->open_m)
          ov_clear(maria_struct_->vf);

     if (maria_struct_->in_m)
          fclose(maria_struct_->in_m);

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
     *feline_p->error_code_aline_ = 0;
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

     pedro_dprintf(0, "debug 2\n");
     assert(error_code_aline_);
     assert(feline_p);
     assert(feline_p->error_code_aline_);
     if (10004 == *feline_p->error_code_aline_)
     {
          pedro_dprintf(0, "debug 3\n");
          free(feline_p->filename_utf_8_m);
          free(feline_p);
          return NULL;
     }

     // if opus
     // feline_p->dados_do_audio_ar.sample_rate_v = 48000;
     // feline_p->dados_do_audio_ar.channels_p = 2;

     pedro_dprintf(0, "return from call %d", *feline_p->error_code_aline_);

     *dados_m = feline_p->dados_do_audio_ar;

     pedro_dprintf(0, "data -> %lld\n", dados_m->duracao_feline);

     if (0 == *feline_p->error_code_aline_)
     {
          return (char *)feline_p;
     }
     else
     {
          free(feline_p->filename_utf_8_m);
          free(feline_p);

          return NULL;
     }
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
     double seconds_;
     int channels_;
     int samplerate_;
     char media_description[1000];
     int out_bitrate;

     int len_m;
     char *ptr_1;
     (void)ptr_1;
     pedro_dprintf(-1, "svc_ogg_process_m\n");
     if (NULL == struct_opus_m)
     {
          *size_out = 0;
          return BE_ERROR_DURING_DECODE;
     }

     pedro_k *feline_p = (void *)struct_opus_m;
     (void)feline_p;

     if (AMANDA_OPUS__ == feline_p->current_decoder_pedro)
     {
          pedro_dprintf(0, "Error 85766567"); // just pass by
          exit(27);
     }
     else if (AMANDA_OGG_VORBIS == feline_p->current_decoder_pedro)
     {
          ; // pass by
     }
     else
     {
          pedro_dprintf(0, "Error gthy78"); // just pass by
          exit(27);
     }

     *size_out = 0;

     //*maria_struct_->error_code_aline_ = 10005; // Error decoding Opus file
     if (10005 == *feline_p->error_code_aline_)
     {
          return BE_ERROR_DURING_DECODE;
     }

again_amanda:;

     if (0 == 1)
     {
          goto again_amanda;
     }

     if (PEREIRA_NO_MORE_DATA == feline_p->decoder_status_mislaine)
     {

          len_m = BucaneiroMin(feline_p->bytes_in_the_buffer_paul, bytes_to_decode_m);

          memcpy(bufout_m, feline_p->ptr_data_position_douglas, len_m);
          bufout_m += len_m;
          feline_p->ptr_data_position_douglas += len_m;
          *size_out += len_m;
          feline_p->bytes_in_the_buffer_paul -= len_m;
          bytes_to_decode_m -= len_m;
          if (0 == feline_p->bytes_in_the_buffer_paul)
          {
               return BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE;
          }

          if (0 < feline_p->bytes_in_the_buffer_paul)
          {
               return BE_DECODED;
          }

          return BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE;
     }

     if (PEREIRA_HAS_DATA == feline_p->decoder_status_mislaine)
     {
          len_m = BucaneiroMin(feline_p->bytes_in_the_buffer_paul, bytes_to_decode_m);

          bytes_to_decode_m -= len_m;
          memcpy(bufout_m, feline_p->ptr_data_position_douglas, len_m);
          bufout_m += len_m;
          feline_p->ptr_data_position_douglas += len_m;

          pedro_dprintf(-15, "val %lld\n", feline_p->ptr_data_position_douglas - feline_p->buffer_junior);

          feline_p->bytes_in_the_buffer_paul -= len_m;
          *size_out += len_m;
          if (0 == bytes_to_decode_m)
          {
               return BE_DECODED;
          }

          if (0 == feline_p->bytes_in_the_buffer_paul)
          {
               feline_p->ptr_data_position_douglas = feline_p->buffer_junior;
               feline_p->bytes_in_the_buffer_paul = 0;
               feline_p->the_andrea_command = KOCI_PROCESS__;
               {
                    ogg_decode_file_shinkal("jota.ogg", // Deus te abençoe amigo

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
               }
               goto again_amanda;
          }

          pedro_dprintf(-15, "passou e vai sair");
          exit(27);
     }

     pedro_dprintf(-15, "passou e vai sair2");
     exit(27);
     return -27;
}
void morcego_deinit_libav_svc_deinit_ogg_m(char *struct_opus_m);
void morcego_deinit_libav_svc_deinit_ogg_m(__attribute__((unused)) char *struct_opus_m)
{
     double seconds_;
     int channels_;
     int samplerate_;
     char media_description[1000];
     int out_bitrate;

     if (NULL == struct_opus_m)
     {
          pedro_dprintf(1001, "Erro 263746 no codigo");
          exit(27);
     }

     pedro_k *feline_p = (void *)struct_opus_m;
     feline_p->the_andrea_command = KOCI_FINISH__;

     ogg_decode_file_shinkal("jota.ogg", // Deus te abençoe amigo

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
     free(feline_p->filename_utf_8_m);
     free(feline_p);
     pedro_dprintf(0, "saiu de deinit_ogg");
     // exit(27);
     return;
}

double
getval_100(double max, double por);
double
getval_100(double max, double por)
{

     // a formula aqui ï¿½
     // max / 100 * por

     double maxa;
     double porr;

     maxa = (double)max;
     porr = (double)por;

     maxa = (maxa / 100.0) * porr;

     return maxa;
}
void __stdcall svc_seek_ogg_m(__attribute__((unused)) char *struct_opus_m,
                              __attribute__((unused)) double maquisistem_value);
void __stdcall svc_seek_ogg_m(__attribute__((unused)) char *struct_opus_m,
                              __attribute__((unused)) double maquisistem_value)
{
     int ret_m;
     double val_m;
     if (NULL == struct_opus_m)
     {
          return;
     }

     pedro_k *feline_p = (void *)struct_opus_m;
     (void)feline_p;

     if (AMANDA_OPUS__ == feline_p->current_decoder_pedro)
     {
          pedro_dprintf(1001, "Error fg65789");
          exit(27);
     }
     else if (AMANDA_OGG_VORBIS == feline_p->current_decoder_pedro)
     {
          ; // go by
     }
     else
     {
          pedro_dprintf(0, "Error 3e4r5t");
          exit(27);
     }

     val_m = getval_100(feline_p->dados_do_audio_ar.raw_total_ric, maquisistem_value);

     if (NULL == feline_p->vf)
     {
          return;
     }

     ret_m = ov_raw_seek(feline_p->vf, (int64_t)val_m);
     if (ret_m < 0)
     {
          pedro_dprintf(1001, "\nSeek failed: -> %i.\n", ret_m);
     }

     feline_p->ptr_data_position_douglas = feline_p->buffer_junior;
     feline_p->bytes_in_the_buffer_paul = 0;
     // for your pleasure...
     return;
}