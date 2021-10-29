// 2021...
// 2021 MathMan and amanda
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

#include <Mmsystem.h>

void pedro_dprintf(int amanda_level,
                   char *format, ...);
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

/* FAAD file buffering routines */
typedef struct
{
     long bytes_into_buffer;
     long bytes_consumed;
     long file_offset;
     unsigned char *buffer;
     int at_eof;
     FILE *infile;
} aac_buffer;

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
     char *vf;
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
     /*

     */
     // for your pleasure...

} pedro_k;

int decode_mad_MP3(char *bufmp3, int len, char *out, int outlimit,
                   int *outsize, int *large);

int Exit_mad_MP3(void);

int Init_mad_MP3(void);
/*These are the informations that you can gather
   from an mp3 file using the madlib library
 */
extern int mad_force_exit; // do not use
extern int valid_xing;
extern int madsamplerate;  // sample rate
extern int madlayer;       // layer
extern int madchannel;     // channels
extern int numberofframes; // the number of frames
extern char madmode[];
extern int madsample_per_frame;
extern int madbitrate;        // the bitrate
extern double madmpegversion; // mpeg version
extern int mad_mp3_is_valid;

#define VERSIONSTRING "OggDec 1.0\n"

static const int bits = 16;

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
     // int channels = 2;
     // int samplerate = 44100;
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

#include "id3_jump.c"

int main(int argc, char **argv)
{

     FILE *myfile = NULL;
     FILE *outfile = NULL;
     static char bufmp3[100000];
     static char out[4608];
     int chaveador = 0;
     int len = 0;
     int large = 1;
     int isize = 0;
     int bytes = 0;
     int init = 0;
     int id3_tag_size_z;

     Init_mad_MP3();
     if (2 == argc)
     {

          myfile = fopen(argv[1], "rb");

          if (NULL == myfile)
          {
               printf("Error openning file %s\n", argv[1]);
               goto saida;
          }

          id3_tag_size_z = id3v2tag_check(argv[1]);

          if (id3_tag_size_z)
               printf("ID3 tag size %d\n\n", id3_tag_size_z);

          fseek(myfile, id3_tag_size_z, SEEK_SET);

          outfile = fopen("outfile.out_k.wav", "wb");

     retornamp3:;

          len = fread(bufmp3,
                      sizeof(char),
                      large,
                      myfile);

          {
               static int size = 0;
               size += len;
               printf("Reading...% d\n", size);
          }

          if (len <= 0 && 0 != large)
          {
               printf("End of stream\n");
               goto saida;
          }
     processa:;
          chaveador =
              decode_mad_MP3(bufmp3,
                             len,
                             out,
                             4608,
                             &isize,
                             &large);
     }
     if (0 != chaveador)
     {
          goto retornamp3;
     }
     printf("Processing...\n");

     if (0 == init)
     {
          init++;
          if (outfile)
               write_prelim_header(outfile, madchannel, madsamplerate);

          assert(madchannel);
          assert(madsamplerate);
     }

     if (outfile)
          bytes += fwrite(out, 1, isize, outfile);

     fflush(stdout);
     goto processa;

saida:;
     Exit_mad_MP3();
     if (myfile)
     {
          fclose(myfile);
     }
     if (outfile)
     {
          rewrite_header(outfile, bytes);
          fclose(outfile);
     }
     printf("End of execution\n");
     return 0;
}

char *__stdcall svc_init_mp3_m(__attribute__((unused)) char *filename_utf_8_v,
                               __attribute__((unused)) int *error_code_aline_,
                               __attribute__((unused)) juliete_struct *dados_m);

char *__stdcall svc_init_mp3_m(__attribute__((unused)) char *filename_utf_8_v,
                               __attribute__((unused)) int *error_code_aline_,
                               __attribute__((unused)) juliete_struct *dados_m)
{
     pedro_dprintf(0, "dentro de svc_init_mp3_m\n");
     return NULL;
}

int __stdcall morcego_decode_libav_svc_process_mp3_m(__attribute__((unused)) char *struct_opus_m,
                                                     __attribute__((unused)) int bytes_to_decode_m,
                                                     __attribute__((unused)) char *bufout_m,
                                                     __attribute__((unused)) int *size_out);

int __stdcall morcego_decode_libav_svc_process_mp3_m(__attribute__((unused)) char *struct_opus_m,
                                                     __attribute__((unused)) int bytes_to_decode_m,
                                                     __attribute__((unused)) char *bufout_m,
                                                     __attribute__((unused)) int *size_out)
{
     return 0;
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

void __stdcall svc_seek_mp3_m(__attribute__((unused)) char *struct_opus_m,
                              __attribute__((unused)) double maquisistem_value);
void __stdcall svc_seek_mp3_m(__attribute__((unused)) char *struct_opus_m,
                              __attribute__((unused)) double maquisistem_value)
{
     return;
}
void morcego_deinit_libav_svc_deinit_mp3_m(__attribute__((unused)) char *struct_opus_m);
void morcego_deinit_libav_svc_deinit_mp3_m(__attribute__((unused)) char *struct_opus_m)
{
     (void)struct_opus_m;
     return;
}