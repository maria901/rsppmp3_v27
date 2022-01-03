/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                             *
*        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>        *
*                                                                             *
*     Este  programa  é software livre: você pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     10
*     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opção) qualquer versão posterior.        *
*                                                                             *
*     Este  programa é distribuído na  esperança que isto vai  ser útil,      *
*     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de      *
*     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Pública para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Pública Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito rápida) WhatsApp               *
*     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
  
#include "win64.h"

extern int __stdcall IntReturn(__int64 mv_instance);
extern void __stdcall GetConversionInfo(__int64 mv_instance,int *percent,int *finished,int *returnvalue_,char *___message);
extern int __cdecl morcego_pause(struct morcego_instance_be_ *mv_______);
extern int __stdcall PlaybackPause(__int64 mv_instance);
extern int __cdecl morcego_resume(struct morcego_instance_be_ *mv_______);
extern int __stdcall PlaybackResume(__int64 mv_instance);
extern int __stdcall PlaybackCancel(__int64 mv_instance);
extern int __cdecl morcego_samplerate(struct morcego_instance_be_ *mv_______);
extern int __stdcall SampleRate(__int64 mv_instance);
extern int __cdecl morcego_channels_(struct morcego_instance_be_ *mv_______);
extern int __stdcall Channels(__int64 mv_instance);
extern int __stdcall Bits_per_Sample(__int64 mv_instance);
extern int __cdecl morcego_gettime(struct morcego_instance_be_ *mv_______);
extern int __stdcall GetTimeMilliseconds(__int64 mv_instance);
extern int __cdecl morcego_gettimes(struct morcego_instance_be_ *mv_______);
extern int __stdcall GetTime(__int64 mv_instance);
extern int __cdecl morcego_gettimestring(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __stdcall GetTimeString(__int64 mv_instance,char *time);
extern int __cdecl morcego_getsecondsstring(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __stdcall GetLengthString(__int64 mv_instance,char *time);
extern int __cdecl morcego_getseconds(struct morcego_instance_be_ *mv_______);
extern int __stdcall GetLengthMilliseconds(__int64 mv_instance);
extern int __cdecl morcego_getsecondss(struct morcego_instance_be_ *mv_______);
extern int __stdcall GetLength(__int64 mv_instance);
extern int __cdecl morcego_closeplayer(struct morcego_instance_be_ *mv_______);
extern int __stdcall ClosePlayer(__int64 mv_instance);
extern int __cdecl morcego_seekto(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern void __stdcall SeekTo(__int64 mv_instance,double seek);
extern void __stdcall ShowCursor_(int enable);
extern void __stdcall SeekTo_10000(__int64 mv_instance,double seek);
extern void __stdcall SeekTo_AV_TIME_BASE(__int64 mv_instance,double seek);
extern int __cdecl morcego_getplaybackposition(struct morcego_instance_be_ *mv_______);
extern int __stdcall PlayBackPosition(__int64 mv_instance);
extern int __cdecl morcego_be_getplaybackposition_2(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __stdcall PlayBackPosition_10000(__int64 mv_instance);
extern double __stdcall PlayBackPosition_AV_TIME_BASE(__int64 mv_instance);
extern int __stdcall SetPriority(__int64 mv_instance,int priority);
extern int __stdcall SetVolumeGain(__int64 mv_instance,int value);
extern int __stdcall SetWaveOutDevice(__int64 mv_instance,int device);
extern int __stdcall GetWaveOutDevicesName(__int64 mv_instance,int device,char *data);
extern int __cdecl morcego_isvbr(struct morcego_instance_be_ *mv_______);
extern int __stdcall GetVBR(__int64 mv_instance);
extern int __stdcall GetBitrate(__int64 mv_instance);
extern int __stdcall GetMpegVersion(__int64 mv_instance,char *version);
extern int __stdcall GetMediaInformation(__int64 mv_instance,char *layer_);
extern int __stdcall GetMpegMode(__int64 mv_instance,char *mode_);
extern int __stdcall ConvertMP3ToWav(__int64 mv_instance,char *input,char *output,int tipo,char *mess,int track);
extern int __cdecl morcego_converttowav_be(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __stdcall ConvertMP3ToWavExtended(__int64 mv_instance,char *input,char *output,int tipo_de_wav,int track);
extern int __stdcall EnableEqualizer(__int64 mv_instance,int enable);
extern int __stdcall EqualizerSettings(__int64 mv_instance,int Band60,int Band170,int Band310,int Band600,int Band1000,int Band3000,int Band6000,int Band12000,int Band14000,int Band16000);
extern int __stdcall EnablePreamplifier(__int64 mv_instance,int enable);
extern int __stdcall PreamplifierValue(__int64 mv_instance,int value);
extern int __cdecl morcego_internalvolume(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __stdcall InternalVolume(__int64 mv_instance,int value);
extern int __stdcall EnableOnTheFlyVolumeNormalization(__int64 mv_instance,int mode);
extern int __stdcall DoubleBuffer(__int64 mv_instance,int enable);
extern int __stdcall PauseState(__int64 mv_instance);
extern int __stdcall IsUsingNormalization(__int64 mv_instance);
extern int __cdecl morcego_normalizationdata(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __stdcall NormalizationFactor(__int64 mv_instance,char *value);
extern int __cdecl morcego_getleftchannel(struct morcego_instance_be_ *mv_______);
extern int __stdcall GetPeak(__int64 mv_instance);
extern int __stdcall Read_ID3_v1_tag(__int64 mv_instance,char *filename,int *Track,char *Title,char *Artist,char *Album,char *Year,int *Genre,char *Comment);
extern int __stdcall Generate_ID3v1Genre(__int64 mv_instance,int pos,char *data);
extern int __cdecl morcego_wv1Comment(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __stdcall Write_ID3_v1_tag(__int64 mv_instance,char *filename,int Track,char *Title,char *Artist,char *Album,char *Year,int Genre,char *Comment);
extern int __stdcall Remove_ID3V1_tag(__int64 mv_instance,char *filename);
extern int __cdecl morcego_v2Composer(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2OriginalArtist(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2Copyright(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2URL(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2EncodedBy(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2Comment(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2Genre(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2Year(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2Album(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2Artist(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2Title(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __cdecl morcego_v2Track(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2);
extern int __stdcall Read_ID3_v2_tag(__int64 mv_instance,char *filename,char *Track,char *Title,char *Artist,char *Album,char *Year,char *Genre,char *Comment,char *EncodedBy,char *URL,char *Copyright,char *OriginalArtist,char *Composer);
extern int __stdcall Write_ID3_v2_tag(__int64 mv_instance,char *filename,char *Track,char *Title,char *Artist,char *Album,char *Year,char *Genre,char *Comment,char *EncodedBy,char *URL,char *Copyright,char *OriginalArtist,char *Composer);
extern int __stdcall Remove_ID3V2_tag(__int64 mv_instance,char *filename);
extern int __cdecl morcego_getfft60(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft170(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft310(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft600(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft1000(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft3000(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft6000(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft12000(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft14000(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfft16000(struct morcego_instance_be_ *mv_______);
extern int __cdecl morcego_getfftpeak(struct morcego_instance_be_ *mv_______);
extern int __stdcall GetSpectrumAnalyzer(__int64 mv_instance,int *f60,int *f170,int *f310,int *f600,int *f1000,int *f3000,int *f6000,int *f12000,int *f14000,int *f16000,int *fpeak);
extern int __stdcall EnableSpectrumAnalyzer(__int64 mv_instance,int enable);
extern int __stdcall IsPathFile(__int64 mv_instance,char *filename);
extern int __stdcall IsPathFolder(__int64 mv_instance,char *filename);
extern int __stdcall DebugInformation(__int64 mv_instance,char *debug);
extern int __cdecl morcego_enablevoiceremoval(struct morcego_instance_be_ *mv, __INT32_OR_INT64 argumento2);
extern int __stdcall EnableVoiceRemoval(__int64 mv_instance,int enable);
extern int __cdecl morcego_enableecho(struct morcego_instance_be_ *mv_______, int argumento2, int argumento3);
extern int __stdcall EnableEcho(__int64 mv_instance,int enable,int delay);
extern int __stdcall EnableSurround(__int64 mv_instance,int enable);
extern int __stdcall BE_Special_Wav_Effect(__int64 mv_instance,int enable,int range);
extern int __cdecl morcego_useencryption(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3);
extern int __stdcall UseEncryption(__int64 mv_instance,int enable,char *pass);
extern int __stdcall Encrypt_File(__int64 mv_instance,char *input,char *output,char *pass);
extern int __stdcall EnableFreeverb(__int64 mv_instance,int enable);
extern int __stdcall EnableSoundTouch(__int64 mv_instance,int enable,int tempo,int pitch,int rate);
extern int __stdcall GetNumberofWaveOutDevices(__int64 mv_instance);
extern void __cdecl removespace_begin(char *path);
extern void __cdecl removespace_end(char *path);
extern void __cdecl removespace(char *data);
extern int __cdecl morcego_geterrorstring(struct morcego_instance_be_ *mv_______, __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3);
extern int __stdcall GetErrorString(__int64 mv_instance,int value,char *data);
extern int __stdcall GetNumberOfAudioTracks(__int64 mv_instance,char *utf8_filename,char *error_message);
extern int __stdcall BucaneiroPlayStereoAsMono(__int64 mv_instance,int enable);
extern int __stdcall About();
extern int __stdcall Alladin_GetRemainingTime(__int64 mv_instance,char *data);
extern void __cdecl calc(int val,int *bytes,int *kbs,char *mb,char *gb);
extern int __cdecl PCM16MonoToPCM16Stereo(char *inSamples_b,unsigned int b_len,char *outSamples_b);
extern void __cdecl BucaneiroStereoToMono(char *buffer,int len);
extern void __stdcall IsMultiplayer(__int64 mv_instance,int multiplayer_or_not);
extern void __stdcall SetVideoWidth(__int64 mv_instance,int width);

void __stdcall PassWindowInformation
(
        __int64 mv_instance,
        __int64 hwnd,
        __int64 player_hwnd,
        int width,
        int heigth,
        int ratio,
        int left,
        int top
)
;
