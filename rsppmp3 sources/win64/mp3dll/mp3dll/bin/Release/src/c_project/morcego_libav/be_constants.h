
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
  
#include "../mv_from_be.h"
 
#ifndef BE_CONSTANTS___
#define BE_CONSTANTS___
typedef struct morcego_property_bag_
{
					__int64 int64_1;
					__int64 int64_2;
					__int64 int64_3;
					__int64 int64_4;
					__int64 int64_5;
					double double_1;
					double double_2;
					double double_3;
					double double_4;
					double double_5;
					char string_1[1024];
					char string_2[1024];
					char string_3[1024];
					char string_4[1024];
					char string_5[1024];
					void*ptr;					
} morcego_property_bag;
 
enum morcego_decoder_constants
{

  BE_INITIAL_STATE,
  BE_DECODED,
  BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE,
  BE_ERROR_DURING_DECODE,
  BE_DECODER_NOT_LOADED,

};

enum morcego_decoder_state
{
  BE_STATE_DECODING,
  BE_STATE_NO_MORE_SAMPLES,
  BE_STATE_DECODER_FAILURE,
};

typedef struct be_libav_struct_
{
	morcego_property_bag property_bag;
	char sourcefile[1024];
	int be_channels;
	int be_samplerate;
	int be_bits_per_sample;
	double be_seconds;
	__int64 be_size_of_pcm_data;
	__int64 be_samples;
	char be_error_message[1024];
	char be_codec_name[1024];
	char be__magic_value__format_name[1024];
	char be_media_information[1024];
	int is_vbr;
	char be_mpeg[300];
	char be_layer[300];
	char be_mode[300];
	int be_bitrate;
	int is_mpeg;
	int sample_format;
	double length;
	double mp3_sizeofdata;
	double mp3_adjust;
	__int64 track_to_play_or_decode;	
	unsigned int internal_play_as_mp3___:1;
	unsigned int internal_replaygain_fast_mode:2;
	
} be_libav_struct;//the definitive audio struct

int morcego_decode_libav (morcego___i___instance__a__bucaneiro_engineering *mv_______,int bytes_to_decode, char *bufout, int *size_out);
int morcego_init_libav (morcego___i___instance__a__bucaneiro_engineering *mv_______,be_libav_struct * be_data, int morcego_is_mp3);
void morcego_deinit_libav (morcego___i___instance__a__bucaneiro_engineering *mv_______);
void morcego_seek_100_libav (morcego___i___instance__a__bucaneiro_engineering *mv_______,double valor);
char *get_morcego_interface_version (morcego___i___instance__a__bucaneiro_engineering *mv_______);

void deinit2 (morcego___i___instance__a__bucaneiro_engineering *mv_______);
int init_decoder2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,be_libav_struct *be_data);
int decode2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *buf, int *size_out);
void seek2(morcego___i___instance__a__bucaneiro_engineering *mv_______,double value);
int get_number_of_audio_tracks(morcego___i___instance__a__bucaneiro_engineering *mv_______,char*utf8_filename, char*error_message);
int get_number_of_audio_tracks_internal(morcego___i___instance__a__bucaneiro_engineering *mv_______,char*utf8_filename, char*error_message);

void
morcego_extract_wav_extended
(
morcego___i___instance__a__bucaneiro_engineering *mv_______,
        char *filename,
        char *out_wav_file,
        int wav_mode,
                int track
)
;
int
morcego_extract_wav (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename, char *out_wav_file, int wav_mode,
                     int track)
;
void get_wav_progress_information(morcego___i___instance__a__bucaneiro_engineering *mv_______,int *por,int *ret, int *fin, char*message_);
#endif
