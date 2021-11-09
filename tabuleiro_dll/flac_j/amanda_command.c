/* example_c_decode_file - Simple FLAC file decoder using libFLAC
 * Copyright (C) 2007-2009  Josh Coalson
 * Copyright (C) 2011-2016  Xiph.Org Foundation
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*
 * This example shows how to use libFLAC to decode a FLAC file to a WAVE
 * file.  It only supports 16-bit stereo files.
 *
 * Complete API documentation can be found at:
 *   http://xiph.org/flac/api/
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#define PRIu64 "llu"
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

#include <stdio.h>
#include <stdlib.h>
#include "share/compat.h"
#include "FLAC/stream_decoder.h"

#include "win64.h"

#include "my_header_ava.h"

void pedro_dprintf(int amanda_level,
                   char *format, ...);

#define MAGIC_AMANDA_VALUE__ 4608

#define AMANDA__SIZE_ww ((32767 * 2) + 2)

WCHAR *amanda_utf8towide_1_(char *pUTF8, WCHAR *ar_temp);

wchar_t *
permissive_name_m_(const wchar_t *wname, WCHAR *ar_temp);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// added by ric at 03/nov/2021 06:50

typedef enum
{
    LAYER_STREAM = 0,      /* FLAC__stream_decoder_init_[ogg_]stream() without seeking */
    LAYER_SEEKABLE_STREAM, /* FLAC__stream_decoder_init_[ogg_]stream() with seeking */
    LAYER_FILE,            /* FLAC__stream_decoder_init_[ogg_]FILE() */
    LAYER_FILENAME         /* FLAC__stream_decoder_init_[ogg_]file() */
} Layer;

static __attribute__((unused)) const char *const LayerString[] = {
    "Stream",
    "Seekable Stream",
    "FILE*",
    "Filename"};

typedef struct
{
    Layer layer;
    FILE *file;
    char filename[1024];
    uint32_t current_metadata_number;
    FLAC__bool ignore_errors;
    FLAC__bool error_occurred;
    int64_t total_size;
    int64_t total_samples;
    int64_t sample_rate;
    int64_t channels;
    int64_t bps;
    pedro_k *feline_p;
} StreamDecoderClientData;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static FLAC__StreamDecoderWriteStatus write_callback(const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 *const buffer[], void *client_data);
static void metadata_callback(const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data);
static void error_callback(const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data);
/*
static FLAC__uint64 total_samples = 0;
static unsigned sample_rate = 0;
static unsigned channels = 0;
static unsigned bps = 0;
*/
static FLAC__bool write_little_endian_uint16(FILE *f, FLAC__uint16 x)
{
    return fputc(x, f) != EOF &&
           fputc(x >> 8, f) != EOF;
}

static FLAC__bool write_little_endian_int16(FILE *f, FLAC__int16 x)
{
    return write_little_endian_uint16(f, (FLAC__uint16)x);
}

static FLAC__bool write_little_endian_uint32(FILE *f, FLAC__uint32 x)
{
    return fputc(x, f) != EOF &&
           fputc(x >> 8, f) != EOF &&
           fputc(x >> 16, f) != EOF &&
           fputc(x >> 24, f) != EOF;
}

static FLAC__StreamDecoderReadStatus stream_decoder_read_callback_(const FLAC__StreamDecoder *decoder, FLAC__byte buffer[], size_t *bytes, void *client_data)
{
    StreamDecoderClientData *dcd = (StreamDecoderClientData *)client_data;
    const size_t requested_bytes = *bytes;

    (void)decoder;

    if (0 == dcd)
    {
        printf("ERROR: client_data in read callback is NULL\n");
        return FLAC__STREAM_DECODER_READ_STATUS_ABORT;
    }

    if (dcd->error_occurred)
        return FLAC__STREAM_DECODER_READ_STATUS_ABORT;

    if (feof(dcd->file))
    {
        *bytes = 0;
        return FLAC__STREAM_DECODER_READ_STATUS_END_OF_STREAM;
    }
    else if (requested_bytes > 0)
    {
        *bytes = fread(buffer, 1, requested_bytes, dcd->file);
        if (*bytes == 0)
        {
            if (feof(dcd->file))
                return FLAC__STREAM_DECODER_READ_STATUS_END_OF_STREAM;
            else
                return FLAC__STREAM_DECODER_READ_STATUS_ABORT;
        }
        else
        {
            return FLAC__STREAM_DECODER_READ_STATUS_CONTINUE;
        }
    }
    else
        return FLAC__STREAM_DECODER_READ_STATUS_ABORT; /* abort to avoid a deadlock */
}

static FLAC__StreamDecoderSeekStatus stream_decoder_seek_callback_(const FLAC__StreamDecoder *decoder, FLAC__uint64 absolute_byte_offset, void *client_data)
{
    StreamDecoderClientData *dcd = (StreamDecoderClientData *)client_data;

    (void)decoder;

    if (0 == dcd)
    {
        printf("ERROR: client_data in seek callback is NULL\n");
        return FLAC__STREAM_DECODER_SEEK_STATUS_ERROR;
    }

    if (dcd->error_occurred)
        return FLAC__STREAM_DECODER_SEEK_STATUS_ERROR;

    if (fseeko(dcd->file, (FLAC__off_t)absolute_byte_offset, SEEK_SET) < 0)
    {
        dcd->error_occurred = true;
        pedro_dprintf(-20211105, "aqui...amor\n");
        return FLAC__STREAM_DECODER_SEEK_STATUS_ERROR;
    }
    pedro_dprintf(-20211105, "*** deu seek return, pos %lld\n", absolute_byte_offset);
    return FLAC__STREAM_DECODER_SEEK_STATUS_OK;
}

static FLAC__StreamDecoderTellStatus stream_decoder_tell_callback_(const FLAC__StreamDecoder *decoder, FLAC__uint64 *absolute_byte_offset, void *client_data)
{
    StreamDecoderClientData *dcd = (StreamDecoderClientData *)client_data;
    FLAC__off_t offset;

    (void)decoder;

    if (0 == dcd)
    {
        printf("ERROR: client_data in tell callback is NULL\n");
        return FLAC__STREAM_DECODER_TELL_STATUS_ERROR;
    }

    if (dcd->error_occurred)
        return FLAC__STREAM_DECODER_TELL_STATUS_ERROR;

    offset = ftello(dcd->file);
    *absolute_byte_offset = (FLAC__uint64)offset;

    if (offset < 0)
    {
        dcd->error_occurred = true;
        return FLAC__STREAM_DECODER_TELL_STATUS_ERROR;
    }

    return FLAC__STREAM_DECODER_TELL_STATUS_OK;
}

static FLAC__StreamDecoderLengthStatus stream_decoder_length_callback_(const FLAC__StreamDecoder *decoder, FLAC__uint64 *stream_length, void *client_data)
{
    StreamDecoderClientData *dcd = (StreamDecoderClientData *)client_data;
    (void)stream_length;
    (void)decoder;

    if (0 == dcd)
    {
        printf("ERROR: client_data in length callback is NULL\n");
        return FLAC__STREAM_DECODER_LENGTH_STATUS_ERROR;
    }
    pedro_k *feline_p = dcd->feline_p;
    if (dcd->error_occurred)
    {
        pedro_dprintf(-20211105, "error occurred \n");
        return FLAC__STREAM_DECODER_LENGTH_STATUS_ERROR;
    }

    *stream_length = feline_p->tamanho_do_arquivo_m;
    pedro_dprintf(-20211105, "tammanho %lld\n", *stream_length);
    // exit(27);
    return FLAC__STREAM_DECODER_LENGTH_STATUS_OK;
}

static FLAC__bool stream_decoder_eof_callback_(const FLAC__StreamDecoder *decoder, void *client_data)
{
    StreamDecoderClientData *dcd = (StreamDecoderClientData *)client_data;

    (void)decoder;

    if (0 == dcd)
    {
        printf("ERROR: client_data in eof callback is NULL\n");
        return true;
    }

    if (dcd->error_occurred)
        return true;

    return feof(dcd->file);
}

static void stream_decoder_error_callback_(const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data)
{
    StreamDecoderClientData *dcd = (StreamDecoderClientData *)client_data;

    (void)decoder;

    if (0 == dcd)
    {
        printf("ERROR: client_data in error callback is NULL\n");
        return;
    }

    if (!dcd->ignore_errors)
    {
        printf("ERROR: got error callback: err = %u (%s)\n", (uint32_t)status, FLAC__StreamDecoderErrorStatusString[status]);
        dcd->error_occurred = true;
    }
}

size_t fread_amanda(void *__dst, size_t __sz, size_t __n, FILE *__f, pedro_k *feline_p);
size_t fread_amanda(void *__dst, size_t __sz, size_t __n, FILE *__f, pedro_k *feline_p)
{
    (void)__dst;
    (void)__sz;
    (void)__n;
    (void)__f;
    (void)feline_p;
    int len_m;
    pedro_dprintf(-20211105, "dentro de fread_amanda\n");
    while (AMANDA_CANNOT_CONSUME == feline_p->my_command_player_m)
    {
        if(10004 == *feline_p->error_code_aline_)
        {
            return 0;
        }

        Sleep(5);
        if (RICARDO_NOT_RUNNING == feline_p->decoder_state_v)
        {

            pedro_dprintf(-20211105, "RICARDO_NOT_RUNNING \n");

            len_m = min(feline_p->bytes_to_consume_j, MAGIC_AMANDA_VALUE__);
            memcpy(__dst, feline_p->internal_buf_r, len_m);
            feline_p->bytes_to_consume_j = 0;
            // feline_p->my_command_decoder_m = AMANDA_CAN_DECODE;
            return len_m;
        }
        if (feline_p->request_to_exit_ar)
        {
            pedro_dprintf(-20211105, "request_to_exit_ar \n");
            return 0;
        }
    }
    pedro_dprintf(-20211105, "vai sair de fread_amanda\n");
    len_m = min(feline_p->bytes_to_consume_j, MAGIC_AMANDA_VALUE__);
    memcpy(__dst, feline_p->internal_buf_r, len_m);
    feline_p->bytes_to_consume_j = 0;
    feline_p->my_command_player_m = AMANDA_CANNOT_CONSUME;
    feline_p->my_command_decoder_m = AMANDA_CAN_DECODE;
    pedro_dprintf(-20211105, "normal call len exit %d \n", len_m);
    return len_m;
}
unsigned __stdcall my_thread_function_v27(void *my_argument_z);
unsigned __stdcall my_thread_function_v27(void *my_argument_z)
{

    pedro_k *feline_p = (void *)my_argument_z;

    FLAC__bool ok = true;
    FLAC__StreamDecoder *decoder = 0;
    FLAC__StreamDecoderInitStatus init_status;
    StreamDecoderClientData decoder_client_data_m = {0};
    // FILE *fout;

    /*
        if (argc != 3)
        {
            fprintf(stderr, "usage: %s infile.flac outfile.wav\n", argv[0]);

            _endthreadex(0);
            return 27 + 51;
        }
    */
    decoder_client_data_m.feline_p = feline_p;

    pedro_dprintf(-20211105, "init 1\n");

    {
        WCHAR *temp_a = malloc(AMANDA__SIZE_ww);
        WCHAR *temp_a2 = malloc(AMANDA__SIZE_ww);
        decoder_client_data_m.file = _wfopen(permissive_name_m_(amanda_utf8towide_1_(feline_p->filename_utf_8_m, temp_a), temp_a2), L"rb");
        free(temp_a);
        free(temp_a2);
    }

    fseek(decoder_client_data_m.file, 0, SEEK_END);

    feline_p->tamanho_do_arquivo_m = ftell(decoder_client_data_m.file);

    fseek(decoder_client_data_m.file, 0, SEEK_SET);

    pedro_dprintf(-20211105, "init 2\n");

    if (NULL == decoder_client_data_m.file)
    {
        fprintf(stderr, "ERROR: opening %s for output\n", feline_p->filename_utf_8_m);
        feline_p->decoder_state_v = RICARDO_NOT_RUNNING;
        feline_p->error_value_p = 1;
        *feline_p->error_code_aline_ = 10004;
        _endthreadex(0);
        return 27 + 51;
    }

    strcpy(decoder_client_data_m.filename, feline_p->filename_utf_8_m);
    pedro_dprintf(-20211105, "init 3\n");
    if ((decoder = FLAC__stream_decoder_new()) == NULL)
    {
        fprintf(stderr, "ERROR: allocating decoder\n");

        fclose(decoder_client_data_m.file);
        feline_p->decoder_state_v = RICARDO_NOT_RUNNING;
        feline_p->error_value_p = 2;
        *feline_p->error_code_aline_ = 10004;
        _endthreadex(0);
        return 27 + 51;
    }
    pedro_dprintf(-20211105, "init 4\n");
    (void)FLAC__stream_decoder_set_md5_checking(decoder, true);

    decoder_client_data_m.current_metadata_number = 0;
    decoder_client_data_m.ignore_errors = false;
    decoder_client_data_m.error_occurred = false;
    pedro_dprintf(-20211105, "init 5\n");
    init_status = FLAC__stream_decoder_init_stream(decoder, stream_decoder_read_callback_, stream_decoder_seek_callback_, stream_decoder_tell_callback_, stream_decoder_length_callback_, stream_decoder_eof_callback_, write_callback, metadata_callback, stream_decoder_error_callback_, &decoder_client_data_m);
    pedro_dprintf(-20211105, "init 6\n");
    // init_status = FLAC__stream_decoder_init_file(decoder, argv[1], write_callback, metadata_callback, error_callback, /*client_data=*/fout);
    if (init_status != FLAC__STREAM_DECODER_INIT_STATUS_OK)
    {
        fprintf(stderr, "ERROR: initializing decoder: %s\n", FLAC__StreamDecoderInitStatusString[init_status]);
        ok = false;
        *feline_p->error_code_aline_ = 10004;
    }
    pedro_dprintf(-1, "init 7\n");
    if (ok)
    {
        pedro_dprintf(-20211105, "init 7.1\n");
        ok = FLAC__stream_decoder_process_until_end_of_stream(decoder);
        fprintf(stderr, "decoding: %s\n", ok ? "succeeded" : "FAILED");
        fprintf(stderr, "   state: %s\n", FLAC__StreamDecoderStateString[FLAC__stream_decoder_get_state(decoder)]);
    }
    pedro_dprintf(-20211105, "init 8\n");
    FLAC__stream_decoder_delete(decoder);

    fclose(decoder_client_data_m.file);
    feline_p->decoder_state_v = RICARDO_NOT_RUNNING;

    feline_p->error_value_p = 0;
    pedro_dprintf(-20211105, "init 9\n");
    _endthreadex(0);
    return 27 + 51;
}

FLAC__StreamDecoderWriteStatus write_callback(const FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 *const buffer[], void *client_data)
{

    StreamDecoderClientData *decoder_client_data_m = (void *)client_data;
    // FILE *f = (FILE *)decoder_client_data_m->fout_j;
    decoder_client_data_m->total_size = (int64_t)(decoder_client_data_m->total_samples /* é o número de segundos amor... */ * decoder_client_data_m->channels * (decoder_client_data_m->bps / 8));
    size_t i;

    short *short_ptr_j;

    (void)decoder;
    pedro_k *feline_p = decoder_client_data_m->feline_p;

    feline_p->decoder_m = (void *)decoder;

    feline_p->total_samples_m = (int64_t)(decoder_client_data_m->total_samples);

    if (0 == feline_p->wav_bytes)
        feline_p->wav_bytes = decoder_client_data_m->total_size;

    (void)feline_p;

    if (decoder_client_data_m->total_samples == 0)
    {
        fprintf(stderr, "ERROR: this example only works for FLAC files that have a total_samples count in STREAMINFO\n");
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    if (decoder_client_data_m->channels != 2 || decoder_client_data_m->bps != 16)
    {
        fprintf(stderr, "ERROR: this example only supports 16bit stereo streams\n");
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    if (frame->header.channels != 2)
    {
        fprintf(stderr, "ERROR: This frame contains %d channels (should be 2)\n", frame->header.channels);
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    if (buffer[0] == NULL)
    {
        fprintf(stderr, "ERROR: buffer [0] is NULL\n");
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }
    if (buffer[1] == NULL)
    {
        fprintf(stderr, "ERROR: buffer [1] is NULL\n");
        return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
    }

    /* write WAVE header before we write the first frame */
    /*
        if (frame->header.number.sample_number == 0)
        {
            if (
                fwrite("RIFF", 1, 4, f) < 4 ||
                !write_little_endian_uint32(f, decoder_client_data_m->total_size + 36) ||
                fwrite("WAVEfmt ", 1, 8, f) < 8 ||
                !write_little_endian_uint32(f, 16) ||
                !write_little_endian_uint16(f, 1) ||
                !write_little_endian_uint16(f, (FLAC__uint16)decoder_client_data_m->channels) ||
                !write_little_endian_uint32(f, decoder_client_data_m->sample_rate) ||
                !write_little_endian_uint32(f, decoder_client_data_m->sample_rate * decoder_client_data_m->channels * (decoder_client_data_m->bps / 8)) ||
                !write_little_endian_uint16(f, (FLAC__uint16)(decoder_client_data_m->channels * (decoder_client_data_m->bps / 8))) ||
                !write_little_endian_uint16(f, (FLAC__uint16)decoder_client_data_m->bps) ||
                fwrite("data", 1, 4, f) < 4 ||
                !write_little_endian_uint32(f, decoder_client_data_m->total_size))
            {
                fprintf(stderr, "ERROR: write error\n");
                return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
            }
        }
    */
    /* write decoded PCM samples */

    pedro_dprintf(-20211105, "dentro de write 1\n");

    if (feline_p->return_to_decode_j)
    {
        pedro_dprintf(-20211105, "deu pulo 1\n");
        feline_p->my_command_player_m = AMANDA_CANNOT_CONSUME;
        feline_p->my_command_decoder_m = AMANDA_CAN_DECODE;
        feline_p->return_to_decode_j = false;
    }
    while (AMANDA_CANNOT_DECODE == feline_p->my_command_decoder_m)
    {
        Sleep(5);
        if (feline_p->request_to_exit_ar)
        {
            return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
        }
    }

    pedro_dprintf(-20211105, "dentro de write 2\n");

    feline_p->bytes_to_consume_j = 0;
    short_ptr_j = (short *)feline_p->internal_buf_r;

    pedro_dprintf(-1, "***size of item %d\n", frame->header.blocksize);

    for (i = 0; i < frame->header.blocksize; i++)
    {
        *short_ptr_j++ = (FLAC__int16)buffer[0][i];
        *short_ptr_j++ = (FLAC__int16)buffer[0][i];

        feline_p->bytes_to_consume_j += 4;

        if (MAGIC_AMANDA_VALUE__ == feline_p->bytes_to_consume_j)
        {
            feline_p->my_command_decoder_m = AMANDA_CANNOT_DECODE;
            feline_p->my_command_player_m = AMANDA_CAN_CONSUME;

            while (AMANDA_CANNOT_DECODE == feline_p->my_command_decoder_m)
            {
                if (feline_p->request_to_exit_ar)
                {
                    return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
                }
                Sleep(5);
            }
            pedro_dprintf(-1, "reinit decoding...\n");
            short_ptr_j = (short *)feline_p->internal_buf_r;
            feline_p->bytes_to_consume_j = 0;
        }

        /*
        if (
            !write_little_endian_int16(f, (FLAC__int16)buffer[0][i]) || /// left  channel
            !write_little_endian_int16(f, (FLAC__int16)buffer[1][i])    /// right channel
        )
        {
            fprintf(stderr, "ERROR: write error\n");
            return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
        }
        */
    }
    pedro_dprintf(-20211105, "saindo 1 de write 1\n");
    pedro_dprintf(-1, "&&&saiu \n");

    if (feline_p->bytes_to_consume_j)
    {
        pedro_dprintf(-1, "!!!tem bytes aqui... \n");
        feline_p->my_command_decoder_m = AMANDA_CANNOT_DECODE;
        feline_p->my_command_player_m = AMANDA_CAN_CONSUME;

        if (feline_p->return_to_decode_j)
        {
            pedro_dprintf(-20211105, "deu pulo 2\n");
            feline_p->my_command_player_m = AMANDA_CANNOT_CONSUME;
            feline_p->my_command_decoder_m = AMANDA_CAN_DECODE;
            feline_p->return_to_decode_j = false;
        }

        while (AMANDA_CANNOT_DECODE == feline_p->my_command_decoder_m)
        {
            if (feline_p->request_to_exit_ar)
            {
                pedro_dprintf(-20211105, "abort request\n");
                return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
            }
            Sleep(5);
        }
    }
    pedro_dprintf(-20211105, "saindo 2 de write 1\n");
    pedro_dprintf(-20211105, "continue request\n");
    if (feline_p->request_for_seek_ric)
    {
        feline_p->request_for_seek_ric = false;
        pedro_dprintf(-1, "---->dando seek 9\n");
        if (!FLAC__stream_decoder_seek_absolute((void *)feline_p->decoder_m,
                                                (FLAC__uint64)feline_p->new_position_v))
        {
            pedro_dprintf(-20211105, "complexo 31...\n");
            if (!FLAC__stream_decoder_flush(feline_p->decoder_m))
            {
                pedro_dprintf(-20211105, "complexo 41...\n");
            }
        }
        pedro_dprintf(-20211105, "deu seek 9\n");
        // exit(27);
    }
    pedro_dprintf(-1, "saido bytes %d\n", feline_p->bytes_to_consume_j);
    return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
}

void metadata_callback(const FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data)
{
    StreamDecoderClientData *decoder_client_data_m = (void *)client_data;
    (void)decoder, (void)client_data;
    pedro_k *feline_p = decoder_client_data_m->feline_p;

    /* print some stats */
    if (metadata->type == FLAC__METADATA_TYPE_STREAMINFO)
    {
        /* save for later */
        decoder_client_data_m->total_samples = metadata->data.stream_info.total_samples;
        decoder_client_data_m->sample_rate = metadata->data.stream_info.sample_rate;
        decoder_client_data_m->channels = metadata->data.stream_info.channels;
        decoder_client_data_m->bps = metadata->data.stream_info.bits_per_sample;
        feline_p->dados_do_audio_ar.channels_p = decoder_client_data_m->channels;
        feline_p->dados_do_audio_ar.sample_rate_v = decoder_client_data_m->sample_rate;
        /*

        fprintf(stderr, "sample rate    : %u Hz\n", (unsigned int)decoder_client_data_m->sample_rate);
        fprintf(stderr, "channels       : %u\n", (unsigned int)decoder_client_data_m->channels);
        fprintf(stderr, "bits per sample: %u\n", (unsigned int)decoder_client_data_m->bps);
        fprintf(stderr, "total samples  : %" PRIu64 "\n", (uint64_t)decoder_client_data_m->total_samples);
        */
    }
}

void the_seek_for_ric_and_ava(pedro_k *feline_p);
void the_seek_for_ric_and_ava(pedro_k *feline_p)
{
    if (feline_p->decoder_m)
    {
        // feline_p->requested_to_seek_m = true;
        // FLAC__stream_decoder_flush((void *)feline_p->decoder_m);

        pedro_dprintf(-20211105, "vai dar seek\n");
        /*
                if (!FLAC__stream_decoder_seek_absolute((void *)feline_p->decoder_m,
                                                        (FLAC__uint64)feline_p->new_position_v))
                {
                    pedro_dprintf(-20211105, "complexo 31...\n");
                    if (!FLAC__stream_decoder_flush(feline_p->decoder_m))
                    {
                        pedro_dprintf(-20211105, "complexo 41...\n");
                    }
                }
                else
                {
                    feline_p->return_to_decode_j = true;
                }

                pedro_dprintf(-20211105, "deu seek\n");
        */
        /*
        if (!FLAC__stream_decoder_seek_absolute((void *)feline_p->decoder_m,
                                                (FLAC__uint64)feline_p->new_position_v))
        {
            if (FLAC__stream_decoder_get_state((void *)feline_p->decoder_m) == FLAC__STREAM_DECODER_SEEK_ERROR)
            {
                pedro_dprintf(-20211105, "erro aqui\n");
                FLAC__stream_decoder_flush((void *)feline_p->decoder_m);
                // FLAC__stream_decoder_reset((void *)feline_p->decoder_m); // he he he
            }
        }
        */
    }

    return;
}