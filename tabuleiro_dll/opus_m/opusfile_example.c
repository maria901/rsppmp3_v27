
// slightly modified by Smart Ape, from BW in 14/oct/2021 18:38:05

/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE libopusfile SOFTWARE CODEC SOURCE CODE. *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE libopusfile SOURCE CODE IS (C) COPYRIGHT 1994-2020           *
 * by the Xiph.Org Foundation and contributors https://xiph.org/    *
 *                                                                  *
 ********************************************************************/

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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

void pedro_dprintf(int amanda_level,
                   char *format, ...);

#include "config_file_m.h"

/*For fileno()*/
#if !defined(_POSIX_SOURCE)
#define _POSIX_SOURCE 1
#endif
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <opusfile.h>
#if defined(_WIN32)
#include "win32utf8.h"
#undef fileno
#define fileno _fileno
#endif

static void print_duration(FILE *_fp, ogg_int64_t _nsamples, int _frac, int64_t *duracao_f)
{
     ogg_int64_t seconds;
     ogg_int64_t minutes;
     ogg_int64_t hours;
     ogg_int64_t days;
     ogg_int64_t weeks;

     double sec_ok_m = (double)_nsamples / 48000.0;
     _nsamples += _frac ? 24 : 24000;
     seconds = _nsamples / 48000;

     pedro_dprintf(-15, " seconds %0.2f _nsamples %lld", sec_ok_m * 1000.0, (int64_t)_nsamples);

     sec_ok_m = sec_ok_m * 1000.0 * 1000.0;

     *duracao_f = (int64_t)sec_ok_m;

     _nsamples -= seconds * 48000;
     minutes = seconds / 60;
     seconds -= minutes * 60;
     hours = minutes / 60;
     minutes -= hours * 60;
     days = hours / 24;
     hours -= days * 24;
     weeks = days / 7;
     days -= weeks * 7;

     (void)_fp;

     if (weeks)
          pedro_dprintf(-14, "%liw", (long)weeks);
     if (weeks || days)
          pedro_dprintf(-14, "%id", (int)days);
     if (weeks || days || hours)
     {
          if (weeks || days)
               pedro_dprintf(-14, "%02ih", (int)hours);
          else
               pedro_dprintf(-14, "%ih", (int)hours);
     }
     if (weeks || days || hours || minutes)
     {
          if (weeks || days || hours)
               pedro_dprintf(-14, "%02im", (int)minutes);
          else
               pedro_dprintf(-14, "%im", (int)minutes);
          pedro_dprintf(-14, "%02i", (int)seconds);
     }
     else
          pedro_dprintf(-14, "%i", (int)seconds);
     if (_frac)
          pedro_dprintf(-14, ".%03i", (int)(_nsamples / 48));
     pedro_dprintf(-14, "s");
}

static void print_size(FILE *_fp, opus_int64 _nbytes, int _metric,
                       const char *_spacer)
{
     static const char SUFFIXES[7] = {' ', 'k', 'M', 'G', 'T', 'P', 'E'};
     opus_int64 val;
     opus_int64 den;
     opus_int64 round;
     int base;
     int shift;
     base = _metric ? 1000 : 1024;
     round = 0;
     den = 1;
     (void)_fp;
     for (shift = 0; shift < 6; shift++)
     {
          if (_nbytes < den * base - round)
               break;
          den *= base;
          round = den >> 1;
     }
     val = (_nbytes + round) / den;
     if (den > 1 && val < 10)
     {
          if (den >= 1000000000)
               val = (_nbytes + (round / 100)) / (den / 100);
          else
               val = (_nbytes * 100 + round) / den;
          pedro_dprintf(-14, "%li.%02i%s%c", (long)(val / 100), (int)(val % 100),
                        _spacer, SUFFIXES[shift]);
     }
     else if (den > 1 && val < 100)
     {
          if (den >= 1000000000)
               val = (_nbytes + (round / 10)) / (den / 10);
          else
               val = (_nbytes * 10 + round) / den;
          pedro_dprintf(-14, "%li.%i%s%c", (long)(val / 10), (int)(val % 10),
                        _spacer, SUFFIXES[shift]);
     }
     else
          pedro_dprintf(-14, "%li%s%c", (long)val, _spacer, SUFFIXES[shift]);
}

static void put_le32(unsigned char *_dst, opus_uint32 _x)
{
     _dst[0] = (unsigned char)(_x & 0xFF);
     _dst[1] = (unsigned char)(_x >> 8 & 0xFF);
     _dst[2] = (unsigned char)(_x >> 16 & 0xFF);
     _dst[3] = (unsigned char)(_x >> 24 & 0xFF);
}

/*Make a header for a 48 kHz, stereo, signed, 16-bit little-endian PCM WAV.*/
static void make_wav_header(unsigned char _dst[44], ogg_int64_t _duration)
{
     /*The chunk sizes are set to 0x7FFFFFFF by default.
       Many, though not all, programs will interpret this to mean the duration is
        "undefined", and continue to read from the file so long as there is actual
        data.*/
     static const unsigned char WAV_HEADER_TEMPLATE[44] = {
         'R', 'I', 'F', 'F', 0xFF, 0xFF, 0xFF, 0x7F,
         'W', 'A', 'V', 'E', 'f', 'm', 't', ' ',
         0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00,
         0x80, 0xBB, 0x00, 0x00, 0x00, 0xEE, 0x02, 0x00,
         0x04, 0x00, 0x10, 0x00, 'd', 'a', 't', 'a',
         0xFF, 0xFF, 0xFF, 0x7F};
     memcpy(_dst, WAV_HEADER_TEMPLATE, sizeof(WAV_HEADER_TEMPLATE));
     if (_duration > 0)
     {
          if (_duration > 0x1FFFFFF6)
          {
               pedro_dprintf(-14, "WARNING: WAV output would be larger than 2 GB.\n");
               fprintf(stderr,
                       "Writing non-standard WAV header with invalid chunk sizes.\n");
          }
          else
          {
               opus_uint32 audio_size;
               audio_size = (opus_uint32)(_duration * 4);
               put_le32(_dst + 4, audio_size + 36);
               put_le32(_dst + 40, audio_size);
          }
     }
}

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
     AMANDA_MP4_AAC,
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
     OggOpusFile *of;
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

} pedro_k;

char *__stdcall svc_init_ogg_m(__attribute__((unused)) char *filename_utf_8_v,
                               __attribute__((unused)) int *error_code_aline_,
                               __attribute__((unused)) juliete_struct *dados_m);

int __stdcall morcego_decode_libav_svc_process_ogg_m(__attribute__((unused)) char *struct_opus_m,
                                                     __attribute__((unused)) int bytes_to_decode_m,
                                                     __attribute__((unused)) char *bufout_m,
                                                     __attribute__((unused)) int *size_out);

void morcego_deinit_libav_svc_deinit_ogg_m(char *struct_opus_m);

void __stdcall svc_seek_ogg_m(__attribute__((unused)) char *struct_opus_m,
                              __attribute__((unused)) double maquisistem_value);

void main_old_p(pedro_k *maria_struct_);
void main_old_p(pedro_k *maria_struct_)
{
     int len_v;
     (void)len_v;
     *maria_struct_->error_code_aline_ = 0;

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

     maria_struct_->current_bitrate_juliete = 0;
     maria_struct_->of = NULL;
     ogg_int64_t duration;
     // unsigned char wav_header[44];
     // int ret;
     int is_ssl;
     // int output_seekable;
#if defined(_WIN32)
     // win32_utf8_setup(&_argc, &_argv);
#endif
     /*
          if (_argc != 2)
          {
               pedro_dprintf(-14, "Usage: %s <file.opus>\n", _argv[0]);
               return EXIT_FAILURE;
          }
          */
     is_ssl = 0;
     if (false)
     {
          /*
          OpusFileCallbacks cb = {NULL, NULL, NULL, NULL};
          of = op_open_callbacks(op_fdopen(&cb, fileno(stdin), "rb"), &cb, NULL, 0, &ret);
          */
     }
     else
     {
          // exit(27);
          /*
           OpusServerInfo info;

           of = op_open_url(_argv[1], &ret, OP_GET_SERVER_INFO(&info), NULL);
            */
#if 0
    if(of==NULL){
      OpusFileCallbacks  cb={NULL,NULL,NULL,NULL};
      void              *fp;
      /*For debugging: force a file to not be seekable.*/
      fp=op_fopen(&cb,_argv[1],"rb");
      cb.seek=NULL;
      cb.tell=NULL;
      of=op_open_callbacks(fp,&cb,NULL,0,NULL);
    }
#else
          if (NULL == maria_struct_->of)
          {
               pedro_dprintf(-15, "open em %s\n", maria_struct_->filename_utf_8_m);
               maria_struct_->of = op_open_file(maria_struct_->filename_utf_8_m, &maria_struct_->ret_m);
          }
#endif
          else
          {
               *maria_struct_->error_code_aline_ = 10003; // will never occur...
               return;
          }
     }
     if (NULL == maria_struct_->of)
     {
          *maria_struct_->error_code_aline_ = 10004; // Cannot open media file, don't need to close file or free resources
          return;
     }
     duration = 0;
     strcpy(maria_struct_->dados_do_audio_ar.media_description_m, "Opus ;-)");
     maria_struct_->dados_do_audio_ar.duracao_feline = 0;

     maria_struct_->dados_do_audio_ar.raw_total_ric = 1;
     // output_seekable = fseek(stdout, 0, SEEK_CUR) != -1;
     if (op_seekable(maria_struct_->of))
     {
          opus_int64 size;
          pedro_dprintf(-14, "Total number of links: %i\n", op_link_count(maria_struct_->of));
          duration = op_pcm_total(maria_struct_->of, -1);
          pedro_dprintf(-14, "Total duration: ");
          print_duration(stderr, duration, 3, &maria_struct_->dados_do_audio_ar.duracao_feline);
          pedro_dprintf(-14, " (%li samples @ 48 kHz)\n", (long)duration);
          size = op_raw_total(maria_struct_->of, -1);
          pedro_dprintf(-14, "Total size: ");
          print_size(stderr, size, 0, "");
          pedro_dprintf(-14, "\n");
          maria_struct_->dados_do_audio_ar.raw_total_ric = op_raw_total(maria_struct_->of, -1);
     }
     /*
     else if (!output_seekable)
     {
          pedro_dprintf(-14, "WARNING: Neither input nor output are seekable.\n");
          fprintf(stderr,
                  "Writing non-standard WAV header with invalid chunk sizes.\n");
     }
     */
     /*
      make_wav_header(wav_header, duration);
      */
     if (false)
     {
          /*
          pedro_dprintf(-14, "Error writing WAV header: %s\n", strerror(errno));
          ret = EXIT_FAILURE;
          */
     }
     else
     {
          // int prev_li;
          maria_struct_->prev_li_j = -1;

     entering_function_pedro:;

          maria_struct_->decoder_status_mislaine = PEREIRA_HAS_DATA;

          ogg_int64_t pcm_offset;
          ogg_int64_t pcm_print_offset;
          // ogg_int64_t nsamples;
          opus_int32 bitrate;

          // nsamples = 0;
          pcm_offset = op_pcm_tell(maria_struct_->of);
          if (pcm_offset != 0)
          {
               pedro_dprintf(-14, "Non-zero starting PCM offset: %li\n", (long)pcm_offset);
          }
          pcm_print_offset = pcm_offset - 48000;
          bitrate = 0;

          for (;;)
          {
               ogg_int64_t next_pcm_offset;
               opus_int16 pcm[120 * 48 * 2];
               unsigned char out[120 * 48 * 2 * 2];
               int li;
               int si;

               (void)out;
               /*Although we would generally prefer to use the float interface, WAV
                  files with signed, 16-bit little-endian samples are far more
                  universally supported, so that's what we output.*/
               maria_struct_->ret_m = op_read_stereo(maria_struct_->of, pcm, sizeof(pcm) / sizeof(*pcm));
               if (maria_struct_->ret_m == OP_HOLE)
               {
                    pedro_dprintf(-14, "\nHole detected! Corrupt file segment?\n");
                    continue;
               }
               else if (maria_struct_->ret_m < 0)
               {
                    pedro_dprintf(-14, "\nError decoding '%s': %i\n", maria_struct_->filename_utf_8_m, maria_struct_->ret_m);
                    if (is_ssl) // never will occur Ric...
                         pedro_dprintf(-14, "Possible truncation attack?\n");
                    maria_struct_->ret_m = EXIT_FAILURE;
                    *maria_struct_->error_code_aline_ = 10005; // Error decoding Opus file
                    break;
               }
               li = op_current_link(maria_struct_->of);
               if (li != maria_struct_->prev_li_j)
               {
                    const OpusHead *head;
                    const OpusTags *tags;
                    int binary_suffix_len;
                    int ci;
                    /*We found a new link.
                      Print out some information.*/
                    pedro_dprintf(-14, "Decoding link %i:                          \n", li);
                    head = op_head(maria_struct_->of, li);
                    pedro_dprintf(-14, "  Channels: %i\n", head->channel_count);
                    if (op_seekable(maria_struct_->of))
                    {
                         ogg_int64_t duration;
                         opus_int64 size;
                         duration = op_pcm_total(maria_struct_->of, li);
                         pedro_dprintf(-14, "  Duration: ");
                         // print_duration(stderr, duration, 3);
                         pedro_dprintf(-14, " (%li samples @ 48 kHz)\n", (long)duration);
                         size = op_raw_total(maria_struct_->of, li);
                         pedro_dprintf(-14, "  Size: ");
                         print_size(stderr, size, 0, "");
                         pedro_dprintf(-14, "\n");
                    }
                    if (head->input_sample_rate)
                    {
                         pedro_dprintf(-14, "  Original sampling rate: %lu Hz\n",
                                       (unsigned long)head->input_sample_rate);
                    }
                    tags = op_tags(maria_struct_->of, li);
                    pedro_dprintf(-14, "  Encoded by: %s\n", tags->vendor);
                    for (ci = 0; ci < tags->comments; ci++)
                    {
                         const char *comment;
                         comment = tags->user_comments[ci];
                         if (opus_tagncompare("METADATA_BLOCK_PICTURE", 22, comment) == 0)
                         {
                              OpusPictureTag pic;
                              int err;
                              err = opus_picture_tag_parse(&pic, comment);
                              pedro_dprintf(-14, "  %.23s", comment);
                              if (err >= 0)
                              {
                                   pedro_dprintf(-14, "%u|%s|%s|%ux%ux%u", pic.type, pic.mime_type,
                                                 pic.description, pic.width, pic.height, pic.depth);
                                   if (pic.colors != 0)
                                        pedro_dprintf(-14, "/%u", pic.colors);
                                   if (pic.format == OP_PIC_FORMAT_URL)
                                   {
                                        // pedro_dprintf(-14, "|%s\n", pic.data);
                                   }
                                   else
                                   {
                                        pedro_dprintf(-14, "|<%u bytes of image data>\n", pic.data_length);
                                   }
                                   opus_picture_tag_clear(&pic);
                              }
                              else
                                   pedro_dprintf(-14, "<error parsing picture tag>\n");
                         }
                         else
                              pedro_dprintf(-14, "  %s\n", tags->user_comments[ci]);
                    }
                    if (opus_tags_get_binary_suffix(tags, &binary_suffix_len) != NULL)
                    {
                         pedro_dprintf(-14, "<%u bytes of unknown binary metadata>\n",
                                       binary_suffix_len);
                    }
                    pedro_dprintf(-14, "\n");
                    if (!op_seekable(maria_struct_->of))
                    {
                         pcm_offset = op_pcm_tell(maria_struct_->of) - maria_struct_->ret_m;
                         if (pcm_offset != 0)
                         {
                              pedro_dprintf(-14, "Non-zero starting PCM offset in link %i: %li\n",
                                            li, (long)pcm_offset);
                         }
                    }
               }
               if (li != maria_struct_->prev_li_j || pcm_offset >= pcm_print_offset + 48000)
               {
                    opus_int32 next_bitrate;
                    opus_int64 raw_offset;
                    next_bitrate = op_bitrate_instant(maria_struct_->of);
                    if (next_bitrate >= 0)
                         bitrate = next_bitrate;
                    raw_offset = op_raw_tell(maria_struct_->of);
                    (void)raw_offset;
                    pedro_dprintf(-14, "\r ");
                    // print_size(stderr, raw_offset, 0, "");
                    pedro_dprintf(-14, "  ");
                    // print_duration(stderr, pcm_offset, 0);
                    pedro_dprintf(-14, "  (");
                    // print_size(stderr, bitrate, 1, " ");

                    if (bitrate != maria_struct_->current_bitrate_juliete)
                    {
                         maria_struct_->current_bitrate_juliete = bitrate;
                         pedro_dprintf(-14, "meu bitrate %d", maria_struct_->current_bitrate_juliete);
                    }
                    pedro_dprintf(-14, "bps)                    \r");
                    pcm_print_offset = pcm_offset;
               }
               next_pcm_offset = op_pcm_tell(maria_struct_->of);
               if (pcm_offset + maria_struct_->ret_m != next_pcm_offset)
               {
                    pedro_dprintf(-14, "\nPCM offset gap! %li+%i!=%li\n",
                                  (long)pcm_offset, maria_struct_->ret_m, (long)next_pcm_offset);
               }
               pcm_offset = next_pcm_offset;
               if (maria_struct_->ret_m <= 0)
               {
                    maria_struct_->decoder_status_mislaine = PEREIRA_NO_MORE_DATA;
                    maria_struct_->ret_m = EXIT_SUCCESS;
                    break;
               }
               /*Ensure the data is little-endian before writing it out.*/
               for (si = 0; si < 2 * maria_struct_->ret_m; si++)
               {
                    out[2 * si + 0] = (unsigned char)(pcm[si] & 0xFF);
                    out[2 * si + 1] = (unsigned char)(pcm[si] >> 8 & 0xFF);
               }

               /*
               if (!fwrite(out, sizeof(*out) * 4 * maria_struct_->ret_m, 1, stdout))
               {
                    pedro_dprintf(-14, "\nError writing decoded audio data: %s\n",
                    strerror(errno));
                    maria_struct_->ret_m = EXIT_FAILURE;
                    break;
               }
               */

               // nsamples += maria_struct_->ret_m;
               maria_struct_->prev_li_j = li;

               int sacanagem = maria_struct_->ret_m;
               int sacanagem2 = sizeof(*out);
               if ((sacanagem2 * 4 * sacanagem) > 0)
               {
                    assert(192000 > sizeof(*out) * 4 * sacanagem);
                    memcpy(maria_struct_->buffer_junior, out, sizeof(*out) * 4 * sacanagem);
                    maria_struct_->ptr_data_position_douglas = maria_struct_->buffer_junior;
                    maria_struct_->bytes_in_the_buffer_paul += sizeof(*out) * 4 * sacanagem;

                    return;
               }
          }

          return;

     exit_function_pedro:;

          if (maria_struct_->ret_m == EXIT_SUCCESS)
          {
               /*
               pedro_dprintf(-14, "\nDone: played ");
               print_duration(stderr, nsamples, 3);
               pedro_dprintf(-14, " (%li samples @ 48 kHz).\n", (long)nsamples);
               */
          }
          /*
          if (op_seekable(maria_struct_->of) && nsamples != duration)
          {
               pedro_dprintf(-14, "\nWARNING: "
                                  "Number of output samples does not match "
                                  "declared file duration.\n");

          }
          */
          /*
          if (output_seekable && nsamples != duration)
          {
          make_wav_header(wav_header, nsamples);
          if (fseek(stdout, 0, SEEK_SET) ||
             !fwrite(wav_header, sizeof(wav_header), 1, stdout))
          {
              pedro_dprintf(-14, "Error rewriting WAV header: %s\n", strerror(errno));
              ret = EXIT_FAILURE;
          }
          }
          */
     }
     pedro_dprintf(-15, "Vai fechar o opus\n");
     op_free(maria_struct_->of);
     maria_struct_->of = NULL;
     pedro_dprintf(-15, "fechou o opus\n");
     return;
}

char *__stdcall svc_init_opus_m(char *filename_utf_8_v,
                                int *error_code_aline_,
                                juliete_struct *dados_m);

/**
 * Funcion to open a Opus file and load it to play
 *
 *
 */
char *__stdcall svc_init_opus_m(char *filename_utf_8_v,
                                int *error_code_aline_,
                                juliete_struct *dados_m)
{
     char *ptr_shinkal;
     pedro_dprintf(-15, "svc_init_opus_m\n");
     pedro_k *feline_p = calloc(sizeof(pedro_k), 1);
     // assert(0);
     if (NULL == feline_p)
     {
          *error_code_aline_ = 10001; // Cannot allocate memory
          return NULL;
     }
     feline_p->current_decoder_pedro = AMANDA_OPUS__;
     feline_p->error_code_aline_ = error_code_aline_;
     assert(feline_p->error_code_aline_);
     feline_p->filename_utf_8_m = calloc(AMANDA__SIZE, 1);

     strcpy(feline_p->filename_utf_8_m, filename_utf_8_v);
     pedro_dprintf(-14, "debug 1\n");

     feline_p->the_andrea_command = KOCI_INIT__;
     main_old_p(feline_p);
     pedro_dprintf(-14, "debug 2\n");
     assert(error_code_aline_);
     assert(feline_p);
     assert(feline_p->error_code_aline_);
     if (10004 == *feline_p->error_code_aline_)
     {
          pedro_dprintf(0, "vai tentar ogg\n");

          ptr_shinkal = svc_init_ogg_m(filename_utf_8_v,
                                       error_code_aline_,
                                       dados_m);

          if (ptr_shinkal)
          {
               free(feline_p->filename_utf_8_m);
               free(feline_p);

               feline_p = (void *)ptr_shinkal;
          }

          if (NULL == ptr_shinkal)
          {
               pedro_dprintf(0, "ogg returns NULL \n");
               ; // do nothing
          }
          else if (10004 == *feline_p->error_code_aline_)
          {
               pedro_dprintf(0, "file isnot ogg \n");
               // here handle mp4 or AAC
          }
          else
          {
               pedro_dprintf(0, "file is ogg my love...%p\n", feline_p);

               return (char *)feline_p;
          }

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
// int morcego_decode_libav(morcego___i___instance__a__bucaneiro_engineering *mv_______, int bytes_to_decode, char *bufout, int *size_out)

int __stdcall morcego_decode_libav_svc_process_opus_m(char *struct_opus_m,
                                                      __attribute__((unused)) int bytes_to_decode_m,
                                                      __attribute__((unused)) char *bufout_m,
                                                      __attribute__((unused)) int *size_out);

int __stdcall morcego_decode_libav_svc_process_opus_m(char *struct_opus_m,
                                                      __attribute__((unused)) int bytes_to_decode_m,
                                                      __attribute__((unused)) char *bufout_m,
                                                      __attribute__((unused)) int *size_out)
{
     int len_m;
     char *ptr_1;
     (void)ptr_1;
     pedro_dprintf(0, "svc_process_m\n");
     if (NULL == struct_opus_m)
     {
          *size_out = 0;
          return BE_ERROR_DURING_DECODE;
     }

     pedro_k *feline_p = (void *)struct_opus_m;
     (void)feline_p;

     if (AMANDA_OPUS__ == feline_p->current_decoder_pedro)
     {
          ; // just pass by
     }
     else if (AMANDA_OGG_VORBIS == feline_p->current_decoder_pedro)
     {

          pedro_dprintf(0, "vai chamar decoder de Ogg");
          return morcego_decode_libav_svc_process_ogg_m((char *)feline_p,
                                                        bytes_to_decode_m,
                                                        bufout_m,
                                                        size_out);
     }
     else
     {
          pedro_dprintf(0, "Error 4657563548");
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
               main_old_p(feline_p);
               goto again_amanda;
          }

          pedro_dprintf(-15, "passou e vai sair");
          exit(27);
     }

     pedro_dprintf(-15, "passou e vai sair2");
     exit(27);
     return -27;
}
void morcego_deinit_libav_svc_deinit_opus_m(char *struct_opus_m);
void morcego_deinit_libav_svc_deinit_opus_m(char *struct_opus_m)
{
     pedro_dprintf(0, "svc_deinit_opus_m\n");
     if (NULL == struct_opus_m)
     {
          return;
     }

     pedro_k *feline_p = (void *)struct_opus_m;
     (void)feline_p;

     if (AMANDA_OPUS__ == feline_p->current_decoder_pedro)
     {
          feline_p->the_andrea_command = KOCI_FINISH__;
          main_old_p(feline_p);
     }

     if (AMANDA_OGG_VORBIS == feline_p->current_decoder_pedro)
     {
          return morcego_deinit_libav_svc_deinit_ogg_m(struct_opus_m);
     }

     free(feline_p->filename_utf_8_m);
     free(feline_p);
     pedro_dprintf(0, "morcego_deinit_libav_svc_deinit_opus_m\n");
     return;
}

double
getval_100(double max, double por);
double
getval_100(double max, double por)
{

     // a formula aqui �
     // max / 100 * por

     double maxa;
     double porr;

     maxa = (double)max;
     porr = (double)por;

     maxa = (maxa / 100.0) * porr;

     return maxa;
}

void __stdcall svc_seek_opus_m(char *struct_opus_m,
                               __attribute__((unused)) double maquisistem_value);
void __stdcall svc_seek_opus_m(char *struct_opus_m,
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
          ; // just pass by
     }
     else if (AMANDA_OGG_VORBIS == feline_p->current_decoder_pedro)
     {
          svc_seek_ogg_m(struct_opus_m, maquisistem_value);
          return;
     }
     else
     {
          pedro_dprintf(1001, "Error 98574658");
          exit(27);
     }

     val_m = getval_100(feline_p->dados_do_audio_ar.raw_total_ric, maquisistem_value);

     if (NULL == feline_p->of)
     {
          return;
     }

     ret_m = op_raw_seek(feline_p->of, (int64_t)val_m);
     if (ret_m < 0)
     {
          pedro_dprintf(1001, "\nSeek failed: -> %i.\n", ret_m);
     }

     feline_p->ptr_data_position_douglas = feline_p->buffer_junior;
     feline_p->bytes_in_the_buffer_paul = 0;

     return;
}
BOOL WINAPI DllMain(__attribute__((unused)) HINSTANCE hModule,
                    __attribute__((unused)) DWORD ul_reason_for_call,
                    __attribute__((unused)) LPVOID lpReserved);
BOOL WINAPI DllMain(__attribute__((unused)) HINSTANCE hModule,
                    __attribute__((unused)) DWORD ul_reason_for_call,
                    __attribute__((unused)) LPVOID lpReserved)
{
     switch (ul_reason_for_call)
     {
     case DLL_PROCESS_ATTACH:
          OutputDebugString("svc DLL Interface "
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