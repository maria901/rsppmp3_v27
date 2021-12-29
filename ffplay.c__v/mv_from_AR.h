
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

#include "win64.h"

typedef struct cardo___i___ava__a__aurora_boreal__
{
    int sIgnature;
    // ffmepegue_a_r_p_k_ to never change
    char ffmepegue_a_r_p_k_filename_media_utf_8[5000];

    int64_t ffmepegue_a_r_p_k_player_hwnd;

    // old values
    char libav_c___sample_rate_format_string[1024];
    int decoder_c___notloaded;
    int decoder_c___intloop;
    int decoder_c___cancelflag;
    int decoder_c___intreturn;
    int decoder_c___intreturn2; // not in use but here
    int libav_c___use_subtitles_track_i;

    double libav_c___the_ratio;
    int64_t libav_c___hwnd;
    int64_t libav_c___player_hwnd;
    int libav_c___size_of_window_width;
    int libav_c___size_of_window_height;
    int libav_c___adjust_top;
    int libav_c___adjust_left;
    int decoder_c___will_loop;
    int decoder_c___track;
    int decoder_c___intplayback;
    int decoder_c___initial_init_playback_value;
    int syncstatus;
    char decoder_c___filename[5000];
    int decoder_c___wave_out_open_flag;
    char decoder_c___intfilename[5000];
    int decoder_c___the_track;

} cardo___i___ava__a__aurora_boreal;

typedef struct my_thread_struct_z__
{
    char *filename_media_utf_8_v;
} my_thread_struct_z;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// functions

void __stdcall closedecoder_j(__int64 *instance_64);

void check_mv_instance(__int64 mv_instance);

void pedro_dprintfW( // para imprimir wide string use %ls ok?
    int amanda_level,
    const wchar_t *format, ...);

void pedro_dprintf(
    int amanda_level,
    char *format, ...);

int morcego_cancel(cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r);

void pass_information_to_replay(cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r,
                                char *file, int loop_, int track_);

int morcego_open(cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r,
                 __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3);

int __stdcall playogg_v28_v53 /* because this code was borrowed from Ogg Vorbis code 20 years ago */ (cardo___i___ava__a__aurora_boreal *a_ajtmampjv_r);

unsigned __stdcall my_thread_function_v28(void *my_argument_z);

void _MM_SET_FLUSH_ZERO_MODE2(void);

int __stdcall PlaybackCancel_ffplay(__int64 mv_instance);