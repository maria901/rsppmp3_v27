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

#include "win64.h"

#define MAGIC_AMANDA_VALUE__ 4608

void pedro_dprintf(int amanda_level,
                   char *format, ...);

void the_seek_for_ric_and_ava(char *feline_p);

unsigned __stdcall my_thread_function_v27(void *my_argument_z);

int64_t decode_mad_MP3(char *amanda_buf_in,
                       int input_len_ric,
                       char *amanda_buf_out,
                       __attribute__((unused)) int size_maria,
                       int *size_out_feline,
                       int *not_in_use_pedro);

int64_t decode_mad_MP3(char *amanda_buf_in,
                       int input_len_ric,
                       char *amanda_buf_out,
                       __attribute__((unused)) int size_maria,
                       int *size_out_feline,
                       int *not_in_use_pedro)
{
    (void)not_in_use_pedro;

    memcpy(amanda_buf_out, amanda_buf_in,
           input_len_ric);
    *size_out_feline = input_len_ric;
    return -27;
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
    AMANDA_MP3,
    AMANDA_RIC_WAV_PCM,
    AMANDA_RIC_FLAC,
};

#include "my_header_ava.h"

size_t fread_amanda(void *__dst, size_t __sz, size_t __n, FILE *__f, pedro_k *feline_p);

#define VERSIONSTRING "OggDec 1.0\n" /* for historical reasons */

int main_shinkal64_do_ric(pedro_k *feline_p);
int main_shinkal64_do_ric(pedro_k *feline_p)
{
    double a_m;

    bool seek_me_ric = false;
    int to_position_m = 0;
    char *filename_utf8_ric = feline_p->filename_utf_8_m;
    int *error_code_aline_ = feline_p->error_code_aline_;
    while (feline_p->wait_for_fix_m)
    {
        Sleep(50);
    }

    /*
        strcpy(filename_utf8_ric,
               feline_p->filename_utf_8_m);
    */

reinit_player_flac_do_ric:;

    if (KOCI_INIT__ == feline_p->the_andrea_command)
    {

        if (1 == 0)
        {
            goto reinit_player_flac_do_ric;
        }

        memset(feline_p, 0, sizeof(*feline_p));

        feline_p->filename_utf_8_m = filename_utf8_ric;
        feline_p->error_code_aline_ = error_code_aline_;
        feline_p->current_decoder_pedro = AMANDA_RIC_FLAC;

        feline_p->requested_to_seek_m = seek_me_ric;

        feline_p->new_position_v = to_position_m;

        feline_p->dados_do_audio_ar.duracao_feline = 0;

        feline_p->ptr_data_position_douglas = feline_p->buffer_junior;

        feline_p->bytes_in_the_buffer_paul = 0;

        feline_p->dados_do_audio_ar.sample_rate_v = 0;

        feline_p->the_bitrate_my_love_m = 0;

        feline_p->dados_do_audio_ar.channels_p = 0;

        pedro_dprintf(-20211105, "FLAC init\n");
        // madbitrate = 0;
        // madchannel = 0;
        // madsamplerate = 0;
    }

    if (KOCI_PROCESS__ == feline_p->the_andrea_command)
    {
        goto entering_function_pedro;
    }

    if (KOCI_FINISH__ == feline_p->the_andrea_command)
    {
        pedro_dprintf(-20211105, "ric wav pcm end mylove\n");

        goto exit_function_pedro;
    }

    if (true)
    {

        // chama a thread que vai carregar o arquivo ric...
        feline_p->my_command_decoder_m = AMANDA_CAN_DECODE;
        feline_p->my_command_player_m = AMANDA_CANNOT_CONSUME;
        feline_p->bytes_to_consume_j = 0;
        feline_p->decoder_state_v = RICARDO_RUNNING;
        feline_p->my_thread_handle_m = (__INT32_OR_INT64)_beginthreadex(NULL, 0, my_thread_function_v27, feline_p, 0, NULL);

        // while(RICARDO_RUNNING == feline_p->decoder_state_v && )

        feline_p->decoder_status_mislaine = PEREIRA_HAS_DATA;

    entering_function_pedro:;
    retornamp3:;

        feline_p->len = fread_amanda(feline_p->bufmp3,
                                     sizeof(char),
                                     MAGIC_AMANDA_VALUE__,
                                     NULL,
                                     feline_p);

        pedro_dprintf(-20211105, "main got %d return error %d", feline_p->len, feline_p->error_value_p);
/*
        if (0 == feline_p->len &&
            feline_p->requested_to_seek_m)
        {

            seek_me_ric = true;
            to_position_m = feline_p->new_position_v;
            strcpy(filename_utf8_ric, feline_p->filename_utf_8_m);
            feline_p->the_andrea_command = KOCI_INIT__;
            goto reinit_player_flac_do_ric;
        }
*/
        /*
                  {
                       static int size = 0;
                       size += feline_p->len;
                       // printf("Reading...% d\n", size);
                  }
        */
        if (0 == feline_p->len)
        {
            pedro_dprintf(-20211105, "End of stream my love\n");
            goto saida;
        }

        decode_mad_MP3(feline_p->bufmp3,
                       feline_p->len,
                       feline_p->out,
                       MAGIC_AMANDA_VALUE__,
                       &feline_p->isize,
                       &feline_p->large);
    }

    /*
    if (0 != feline_p->chaveador)
    {
         goto retornamp3;
    }
    */

    if (0 != feline_p->dados_do_audio_ar.sample_rate_v && 0 == feline_p->dados_do_audio_ar.duracao_feline)
    {

        // feline_p->dados_do_audio_ar.sample_rate_v = madsamplerate;

        // aac_channels = feline_p->mp4ASC.channelsConfiguration;

        // feline_p->dados_do_audio_ar.channels_p = madchannel;

        if (0 == feline_p->dados_do_audio_ar.duracao_feline)
        {

            // pedro_dprintf(-1, "bitrate amor... %d calc %d \n", madbitrate, feline_p->file_size_m / 240);
            /*
                           a_m = feline_p->file_size_m;

                           a_m = a_m / feline_p->the_bitrate_my_love_m;

                           a_m = a_m / 12.5;
            */
            strcpy(feline_p->dados_do_audio_ar.media_description_m, "FLAC");
            feline_p->the_bitrate_my_love_m = (int)((double)
                                                        feline_p->dados_do_audio_ar.sample_rate_v *
                                                    16.0 * (double)feline_p->dados_do_audio_ar.channels_p);

            a_m =
                (double)feline_p->wav_bytes / 4.0; // /
            ///(double)4.0;
            a_m = a_m * 22.68; // 0.0;

            feline_p->dados_do_audio_ar.duracao_feline = a_m;
        }
    }

    if (feline_p->isize)
    {
        pedro_dprintf(-1, "pegou data amor...\n");
        {
            // static int counter_m = 0;
            assert(192000 > feline_p->isize);

            // pedro_dprintf(-20212810, "value amor %d %d\n", (int)feline_p->buffer_junior_internal[0], counter_m++);
            memcpy(feline_p->buffer_junior, feline_p->out, feline_p->isize);
            feline_p->ptr_data_position_douglas = feline_p->buffer_junior;
            feline_p->bytes_in_the_buffer_paul += feline_p->isize;
            // feline_p->exit_on_next_amanda = true;

            return 0;
            ;
        }
    }

    goto retornamp3;

saida:;

    feline_p->decoder_status_mislaine = PEREIRA_NO_MORE_DATA;
    return 0;

exit_function_pedro:;

    pedro_dprintf(-20211105, "FLAC deinit\n");
    // feline_p->force_exit_ar_K__p = true;
    feline_p->request_to_exit_ar = true;

    while (RICARDO_RUNNING == feline_p->decoder_state_v)
    {
        Sleep(5);
    }
    /*
        if (feline_p->myfile)
        {
            fclose(feline_p->myfile);
        }
    */
    pedro_dprintf(-20211105, "FLAC deinit finished \n");
    return 0;
}

char *__stdcall svc_init_flac_do_ric_da_amanda_m(__attribute__((unused)) char *filename_utf_8_v,
                                                 __attribute__((unused)) int *error_code_aline_,
                                                 __attribute__((unused)) juliete_struct *dados_m);

char *__stdcall svc_init_flac_do_ric_da_amanda_m(__attribute__((unused)) char *filename_utf_8_v,
                                                 __attribute__((unused)) int *error_code_aline_,
                                                 __attribute__((unused)) juliete_struct *dados_m)
{
    pedro_dprintf(-20211105, "dentro de svc_init_flac_do_ric_da_amanda_m\n");
    // hacked at 15:24 17/oct/2021 by Amanda husband...
    /*




    for your pleasure...




    */

    // first of all the initialization on Opus DLL,

    char *ptr_shinkal;
    (void)ptr_shinkal;
    /*
    (void)OV_CALLBACKS_STREAMONLY_NOCLOSE;
    (void)OV_CALLBACKS_STREAMONLY;
    (void)OV_CALLBACKS_NOCLOSE;
    (void)OV_CALLBACKS_DEFAULT;*/

    pedro_dprintf(0, "svc_init_mp4_m\n");
    pedro_k *feline_p = calloc(sizeof(pedro_k), 1);
    // assert(0);
    if (NULL == feline_p)
    {
        *error_code_aline_ = 10001; // Cannot allocate memory
        return NULL;
    }
    feline_p->current_decoder_pedro = AMANDA_RIC_FLAC;
    feline_p->error_code_aline_ = error_code_aline_;
    assert(feline_p->error_code_aline_);
    feline_p->filename_utf_8_m = calloc(AMANDA__SIZE, 1);

    strcpy(feline_p->filename_utf_8_m, filename_utf_8_v);

    *feline_p->error_code_aline_ = 0;
    feline_p->the_andrea_command = KOCI_INIT__;

    main_shinkal64_do_ric(feline_p);

    pedro_dprintf(-20211105, "saiu de main_shinkal64_do_ric...\n");

    pedro_dprintf(-20211105, "duracao %lld\n", feline_p->dados_do_audio_ar.duracao_feline);

    if (0 == feline_p->dados_do_audio_ar.duracao_feline)
    {
        pedro_dprintf(0, "erro 10004 em flac\n");
        *feline_p->error_code_aline_ = 10004;
    }

    // exit(27);
    assert(error_code_aline_);
    assert(feline_p);
    assert(feline_p->error_code_aline_);
    // exit(27);
    if (10004 == *feline_p->error_code_aline_)
    {
        pedro_dprintf(-20212810, "arquivo nao é MP4/AAC\n");

        return (char *)feline_p;
    }

    // if opus
    // feline_p->dados_do_audio_ar.sample_rate_v = 48000;
    // feline_p->dados_do_audio_ar.channels_p = 2;

    pedro_dprintf(-20212810, "return from call %d", *feline_p->error_code_aline_);

    *dados_m = feline_p->dados_do_audio_ar;

    pedro_dprintf(-20212810, "data -> %lld\n", dados_m->duracao_feline);

    if (0 == *feline_p->error_code_aline_)
    {
        return (char *)feline_p;
    }
    else
    {
        // any other error is fatal...
        free(feline_p->filename_utf_8_m);
        free(feline_p);

        return NULL;
    }
    return NULL;
}

int __stdcall morcego_decode_libav_svc_process_flac_do_ric_da_amanda_m(__attribute__((unused)) char *struct_opus_m,
                                                                       __attribute__((unused)) int bytes_to_decode_m,
                                                                       __attribute__((unused)) char *bufout_m,
                                                                       __attribute__((unused)) int *size_out);

int __stdcall morcego_decode_libav_svc_process_flac_do_ric_da_amanda_m(__attribute__((unused)) char *struct_opus_m,
                                                                       __attribute__((unused)) int bytes_to_decode_m,
                                                                       __attribute__((unused)) char *bufout_m,
                                                                       __attribute__((unused)) int *size_out)
{

    int len_m;
    char *ptr_1;
    (void)ptr_1;
    pedro_dprintf(-20211105, " inside svc_process_flac_m\n");
    if (NULL == struct_opus_m)
    {
        *size_out = 0;
        return BE_ERROR_DURING_DECODE;
    }

    pedro_k *feline_p = (void *)struct_opus_m;
    (void)feline_p;

    if (AMANDA_OPUS__ == feline_p->current_decoder_pedro)
    {
        pedro_dprintf(1001, "Error dfdfgbv");
        exit(27);
    }
    else if (AMANDA_OGG_VORBIS == feline_p->current_decoder_pedro)
    {
        pedro_dprintf(1001, "Error 45rt35");
        exit(27);
    }
    else if (AMANDA_MP4_AAC == feline_p->current_decoder_pedro)
    {
        pedro_dprintf(1001, "Error rdfetg");
        exit(27);
    }
    else if (AMANDA_MP3 == feline_p->current_decoder_pedro)
    {
        pedro_dprintf(1001, "Error 876hju");
        exit(27);
    }
    else if (AMANDA_RIC_WAV_PCM == feline_p->current_decoder_pedro)
    {
        pedro_dprintf(1001, "Error 4r3drfe");
        exit(27);
    }
    else if (AMANDA_RIC_FLAC == feline_p->current_decoder_pedro)
    {
        ; // pass by
    }
    else
    {
        pedro_dprintf(1001, "Error edrf23sewd");
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

                main_shinkal64_do_ric(feline_p);
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

void __stdcall svc_seek_flac_do_ric_da_amanda_m(__attribute__((unused)) char *struct_opus_m,
                                                __attribute__((unused)) double maquisistem_value);
void __stdcall svc_seek_flac_do_ric_da_amanda_m(__attribute__((unused)) char *struct_opus_m,
                                                __attribute__((unused)) double maquisistem_value)
{

    pedro_k *feline_p = (void *)struct_opus_m;

    if (NULL == feline_p)
    {
        return;
    }

    {
        feline_p->wait_for_fix_m = true;

        feline_p->new_position_v = getval_100(feline_p->total_samples_m, maquisistem_value);

        pedro_dprintf(-20211105, "new pos %d \n", feline_p->new_position_v);

        feline_p->request_for_seek_ric = true;

        the_seek_for_ric_and_ava((char *)feline_p);

        feline_p->wait_for_fix_m = false;
    }

    return;
}
void morcego_deinit_libav_svc_deinit_flac_do_ric_da_amanda_m(__attribute__((unused)) char *struct_opus_m);
void morcego_deinit_libav_svc_deinit_flac_do_ric_da_amanda_m(__attribute__((unused)) char *struct_opus_m)
{
    (void)struct_opus_m;

    if (NULL == struct_opus_m)
    {
        pedro_dprintf(1001, "Erro 263746 no codigo");
        exit(27);
    }

    pedro_k *feline_p = (void *)struct_opus_m;
    feline_p->the_andrea_command = KOCI_FINISH__;
    pedro_dprintf(-20211105, "flac vai finalizar\n");
    main_shinkal64_do_ric(feline_p);
    pedro_dprintf(-20211105, "flac finalizou\n");
    free(feline_p->filename_utf_8_m);
    free(feline_p);
    pedro_dprintf(0, "saiu de deinit_flac");
    // exit(27);
    return;
}