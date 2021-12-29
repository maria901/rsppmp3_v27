
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                *
 *      Licensa de Cópia (C) <202*>  <Corporação do Trabalho Binário>             *
 *                                                                                *
 *   Este programa é software livre: você pode redistribuir isto e/ou modificar   *
 *   isto sobre os termos do GNU Licensa Geral Pública como publicado pela        *
 *   Fundação de Software Livre, tanto a versão 3 da Licensa, ou                  *
 *   (dependendo da sua opção) qualquer versão posterior.                         *
 *                                                                                *
 *   Este programa é distribuído na esperança que isto vai ser útil,              *
 *   mas SEM QUALQUER GARANTIA; sem até mesmo a implicada garantia de             *
 *   COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
 *   Licensa Geral Pública para mais detalhes.                                    *
 *                                                                                *
 *   Você deve ter recebido uma cópia da LICENSA GERAL PUBLICA                    *
 *       e a GNU Licensa Pública Menor junto com este programa                    *
 *       Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                                *
 *   Suporte: https://arsoftware.net.br/binarywork ____________________           *
 *   Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/           *
 *             http://nomade.sourceforge.net/binarywork/ ______________            *
 *                                                                                *
 *       e-mails direto dos felizes programadores:                                *
 *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
 *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
 *                                                                                *
 *       contato imediato(para uma resposta muita rápida) WhatsApp                *
 *       (+55)41 9627 1708 - isto está sempre ligado                              *
 *                                                                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

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

#include "mv_from_AR.h"

// 88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
//  variables

__INT32_OR_INT64 my_thread_handle_m = -1;

// 88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

#include <xmmintrin.h>

void _MM_SET_FLUSH_ZERO_MODE2(void)
{

    unsigned int __mode = _MM_FLUSH_ZERO_ON;

#ifdef WIN64
    _mm_setcsr((_mm_getcsr() & ~_MM_FLUSH_ZERO_MASK) | __mode);
#else
    __builtin_ia32_ldmxcsr((__builtin_ia32_stmxcsr() & ~_MM_FLUSH_ZERO_MASK) | __mode);
#endif
}

//[9980] BE Lzop2 DLL DLL_PROCESS_ATTACH (01:56:42 May 15 2021) _amanda_debug_

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
        OutputDebugString("ffplay.c as a DLL, by Aurora Boreal "
                          " - DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__
                          ") _amanda_debug_ \n");
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

/**
 * To print a printf based formatted system messagebox
 */
void mprintf(char *format, ...)
{
    // para imprimir messagebox quando necessario
    //#pragma comment (lib,"user32.lib")

    {
        int val;
        va_list ammannddaa;
        char buffer[20000];
        va_start(ammannddaa, format);
        vsprintf(buffer,
                 format, ammannddaa);
        val =
            MessageBoxA(0, buffer, "->Info", MB_OKCANCEL | MB_TOPMOST);
        va_end(ammannddaa);
        if (val != IDOK)
        {
            exit(1);
        }
    }
}

/**
 * @brief It will check to see if a valid instance was passed
 */
void check_mv_instance(__int64 mv_instance)
{

    cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r;

    if (0 == mv_instance)
    {
        mprintf("mv_instance cannot be 0, you need to call the function to create it first\n");
        exit(24);
    }

    a_ajtmampjv_r =
        (cardo___i___ava__a__aurora_boreal *)(__INT32_OR_INT64)
            mv_instance;

    if (0xbadc0da + 27 + 52 != a_ajtmampjv_r->sIgnature)
    {
        mprintf("Invalid signature for the mv_instance\n");
        exit(51);
    }
}

__int64 __stdcall createplayer_m(void)
{
    cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r;
    a_ajtmampjv_r =
        (cardo___i___ava__a__aurora_boreal *)(__INT32_OR_INT64)
            calloc(sizeof(cardo___i___ava__a__aurora_boreal), 1);
    if (a_ajtmampjv_r)
    {
        a_ajtmampjv_r->sIgnature = 0xbadc0da + 27 + 52; // as usual could be too 0xdeadbeef
    }
    else
        mprintf("Cannot allocate memory\n"), exit(23);

    pedro_dprintf(0, "allocated memory for ffplay.c player\n");
    return (__int64)(__INT32_OR_INT64)a_ajtmampjv_r;
}

void __stdcall closedecoder_j(__int64 *instance_64)
{
    // protected
    int *instance = (int *)(__INT32_OR_INT64)*instance_64;

    if (instance)
    {
        // dprintf_z("freeing memory %p\n", instance);

        cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r =
            (cardo___i___ava__a__aurora_boreal *)instance;

        free(instance);
        *instance_64 = 0; // correct... will crash if used again, as usual

        pedro_dprintf(0, "player instance terminated\n");
    }
    else
    {
        pedro_dprintf(1001, "tentando dar free em endereco 0\n");
    }
}

/**
 * @brief It will cancel the playback
 */
int morcego_cancel(cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r)
{

    // pedro_dprintf(-1, "in cancel 1\n");

    a_ajtmampjv_r->syncstatus = 0;

    /*
        if (a_ajtmampjv_r->decoder_c___phwo)
        {
            waveOutReset(a_ajtmampjv_r->decoder_c___phwo);
        }
    */

    // pedro_dprintf(-1, "in cancel 2\n");

    a_ajtmampjv_r->decoder_c___intloop = 0;
    a_ajtmampjv_r->decoder_c___cancelflag = 1;

    if (-1 != my_thread_handle_m)
    {
        WaitForSingleObject((void *)my_thread_handle_m, INFINITE);
        CloseHandle((void *)my_thread_handle_m);
        my_thread_handle_m = -1;
    }

    /*
        while (a_ajtmampjv_r->decoder_c___intreturn == 1000)
        {

            a_ajtmampjv_r->decoder_c___cancelflag = 1;
            Sleep(33);

            return -1;
        }
    */

    return 0;
}

/**
 * It is required to set some important settings that will define the playback
 *
 * @param track_ even if not 1 it will play only for the moment the first detected audio
 * track (soon we will be fixing it (November/2020))
 *
 */
void pass_information_to_replay(cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r,
                                char *file, int loop_, int track_)
{
    strcpy(a_ajtmampjv_r->decoder_c___filename, file);
    a_ajtmampjv_r->decoder_c___will_loop = loop_;
    a_ajtmampjv_r->decoder_c___track = track_;
}

/**
 * @brief Internal function to initiate the playback
 */
int morcego_open(cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r,
                 __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3)
{
    a_ajtmampjv_r->decoder_c___wave_out_open_flag = 1;
    a_ajtmampjv_r->decoder_c___intreturn = 1000;
    strcpy(a_ajtmampjv_r->decoder_c___intfilename, (char *)argumento2);
    a_ajtmampjv_r->decoder_c___the_track = argumento3;
    playogg_v28_v53(a_ajtmampjv_r);
    return 0;
}

/**
 * As you can see it was copied from the BW OGG Vorbis OCX code (my ocx, of course), and it will create
 * the player thread, it will be modified soon to avoid the thread problem of msvcrt.DLL (before 25/dec/2021)
 *
 */
int __stdcall playogg_v28_v53 /* because this code was borrowed from Ogg Vorbis code 20 years ago */ (cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r)
{
    assert(-1 == my_thread_handle_m);
    my_thread_handle_m = (__INT32_OR_INT64)_beginthreadex(NULL, 0, my_thread_function_v28, a_ajtmampjv_r, 0, NULL);
    return 0;
}

/**
 * @brief To cancel the playback
 *
 * @param mv_instance the instance player
 * @return int, always 0
 */
int __stdcall PlaybackCancel_ffplay(__int64 mv_instance)
{
    check_mv_instance(mv_instance);
    cardo___i___ava__a__aurora_boreal *mv_______ =
        (cardo___i___ava__a__aurora_boreal *)(__INT32_OR_INT64)
            mv_instance;
    int ret;

    while (-1 == (ret = morcego_cancel(mv_______)))
    {
    }

    pedro_dprintf(0, "Cancel called\n");

    return ret;
}