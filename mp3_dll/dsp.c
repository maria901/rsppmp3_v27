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
 
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif
// #define NDEBUG

#undef NDEBUG
#include <assert.h>

#include "mv_from_be.h"
void dprintf_z (const char *format, ...);
void mprintf (const char *format, ...);
int pitch_control (morcego___i___instance__a__bucaneiro_engineering *mv_______,int enabledpitchcontrol, char *buf, int bytes, int bps,
                   int nch, int pitchi);
int fix4 (int value);
int
finalize_effects_memory (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	memset (mv_______->dsp_c___sutemp, 0, 50000);
	if (mv_______->dsp_c___pitch_buffer)
	{
		free (mv_______->dsp_c___pitch_buffer);
		mv_______->dsp_c___pitch_buffer = NULL;
	}
	mv_______->dsp_c___pitch_buffer_len = 0;
	return 0;
}
int
resetwaveeefects (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	mv_______->dsp_c___limpador = 0;

	memset (mv_______->dsp_c___echof, 0, 48002);
	memset (mv_______->dsp_c___echo2, 0, 48000);
	memset (mv_______->dsp_c___echo3, 0, 48000);
	memset (mv_______->dsp_c___echo4, 0, 48000);
	memset (mv_______->dsp_c___echo5, 0, 48000);
	memset (mv_______->dsp_c___echo6, 0, 48000);
	memset (mv_______->dsp_c___echoold, 0, 48000);

	return 0;

}

void dprintf_z (const char *format, ...);
//[closed?], fixed in December 2020, 02 06:50:25 AM, it was clipping
int
voiceremoval (char *buf, int bytes, int bps, int nch)
{
	short int *samples = (short int *) buf;
	int numsamples = 0;
	int x = 0;
	numsamples = bytes / 2;
	x = numsamples;

	if (bps == 16)
	{
		short *a = samples;
		if (nch == 2)
			while (x--)
			{
				int l, r;
				l = a[1] - a[0];
				r = a[0] - a[1];
				if (l < -32767)
					l = -32767;
				if (l > 32767)
					l = 32767;
				if (r < -32768)
					r = -32768;
				if (r > 32767)
					r = 32767;
				a[0] = -l;
				a[1] = r;
				a += 2;
			}
	}
	return 0;
}
int
echo (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *buf, int bytes, int bps, __attribute__((unused)) int nch)
{

	short int          *samples;

	samples = (short int *) buf;

	if (bps == 16              )
	{
		int x/*, s*/           ;
		//s = (bytes)          ;

		memcpy (mv_______->dsp_c___echof, mv_______->dsp_c___echoold, bytes);
		memcpy (mv_______->dsp_c___echoold, mv_______->dsp_c___echo2, bytes);
		memcpy (mv_______->dsp_c___echo2, mv_______->dsp_c___echo3, bytes);
		memcpy (mv_______->dsp_c___echo3, mv_______->dsp_c___echo4, bytes);
		memcpy (mv_______->dsp_c___echo4, mv_______->dsp_c___echo5, bytes);
		memcpy (mv_______->dsp_c___echo5, mv_______->dsp_c___echo6, bytes);
		memcpy (mv_______->dsp_c___echo6, samples, bytes);

		for (x = 0; x < (bytes / 2); x++)
		{
			double ss =
			        ((double)
			         ((double) samples[x] / 2.0 +
			          (double) mv_______->dsp_c___echof[x] / 2.0) * (double) 1.5);
			int s = (int) ss;
			samples[x] = (s > 32767 ? 32767 : s < -32768 ? -32768 : s);
		}
	}
	return 0;
}

int
echofinal (morcego___i___instance__a__bucaneiro_engineering *mv_______,int multiplier, int enableecho, int ponto, char *globalbuf,
           int inttamanho, int wav_bitspersample, int intchannels)
{

	if (enableecho && ponto)
	{

		int counter = ponto;
		char *desloca = globalbuf;
		int len = 0;
		int iponto = inttamanho;
		int copy = 0;

denovo:

		if (multiplier <= 0)
		{
			multiplier = 1;
		}

		if (multiplier > 100)
		{
			multiplier = 100;
		}

		//thinktwice (1);

		len = inttamanho / multiplier;

		assert (8 == wav_bitspersample || 16 == wav_bitspersample);

		if (!iponto)
		{
			goto saida;
		}

		copy = len;

		if (copy > iponto)
		{
			copy = iponto;
		}

		while (iponto % copy)
		{
			copy = copy + 1;
		}

		if (copy % 2)
		{
			multiplier--;
			goto denovo;
		}

		if (copy > iponto)
		{
			copy = iponto;
		}

		if (0 == copy)
		{
			goto saida;
		}

		while (counter > 0)
		{

			if (counter < copy)
			{

				copy = counter;

			}

			echo (mv_______,desloca, copy, wav_bitspersample, intchannels);
			desloca = desloca + copy;
			counter = counter - copy;

		}

	}
	;
saida:
	;
	return 0;

}
int
pitch_control
(
        morcego___i___instance__a__bucaneiro_engineering *mv_______,
        int enabledpitchcontrol, char *buf, int bytes, int bps,
        int nch, int pitchi
)
{
	short int *samples = (short *) buf;
	int numsamples;
	int rlen;
	int index = 0, x;
	int n;
	int dindex;
	int pitch;
	double pitchd;

	if (pitchi > 100)
	{
		pitchi = 100;
	}

	if (pitchi < 0)
	{
		pitchi = 0;
	}

	pitchd = 50 + pitchi;

	pitch = (int) (pitchd);

	if (!enabledpitchcontrol)
	{
		return bytes;
	}
	if (!bytes)
	{
		return 0;
	}

	assert (1 == nch || 2 == nch);

	if (bps != 16)
	{
		assert (48000 >= bytes);
		return bytes;
	}
	numsamples = bytes / 2;

	rlen = numsamples * bps / 8 * nch;

	if (pitch > 200)
	{
		pitch = 200;
	}

	if (pitch < 50)
	{
		pitch = 50;
	}

	pitch = 100000 / pitch;
	n = (numsamples * pitch) / 1000;
	dindex = (numsamples << 14) / n;

	if (mv_______->dsp_c___pitch_buffer_len < rlen)
	{

		mv_______->dsp_c___pitch_buffer_len = rlen;

		if (mv_______->dsp_c___pitch_buffer)
		{

			free (mv_______->dsp_c___pitch_buffer);

		}

		mv_______->dsp_c___pitch_buffer = malloc (rlen);

	}

	assert (NULL != mv_______->dsp_c___pitch_buffer);

	if (bps == 16 && nch == 2)
	{
		short *buf = mv_______->dsp_c___pitch_buffer;
		memcpy (buf, samples, rlen);

		for (x = 0; x < n; x++)
		{

			int p = (index >> 14) << 1;
			index += dindex;
			samples[0] = buf[p];
			samples[1] = buf[p + 1];
			samples += 2;

		}

		assert (48000 >= (n * 2));

		return fix4 (n * 2);

	}
	else if (bps == 16 && nch == 1)
	{

		short *buf = mv_______->dsp_c___pitch_buffer;

		memcpy (buf, samples, rlen);

		for (x = 0; x < n; x++)
		{

			int p = (index >> 14);
			index += dindex;
			*samples++ = buf[p];

		}

		assert (48000 >= (n * 2));

		return n * 2;
	}


	assert (48000 >= (numsamples * 2));

	return numsamples * 2;

}
int
surround (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *buf, int bytes, __attribute__((unused)) int bps, int nch)
{
	short *chan1 = NULL;
	short temp1[50000];
	short temp2[50000];
	int i = 0;

	chan1 = (short *) buf;

	if (!mv_______->dsp_c____surround_clean)
	{

		mv_______->dsp_c____surround_clean = 1;
		memset (mv_______->dsp_c___sutemp, 0, 50000);

	}

	if (2 == nch)
	{

		for (i = 0; i < bytes; i = i + 2)
		{

			temp1[i] = chan1[i];
			temp2[i] = chan1[i + 1];
		}

		for (i = 0; i < bytes; i = i + 2)
		{

			chan1[i] = temp1[i];

			int val= -temp2[i];

			if(val>32767)
			{
				val = 32767;
			}

			if(val<-32768)
			{
				val=-32768;
			}
			chan1[i + 1] = val;
		}

	}
	return 0;
}
int
surround2 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *buf, int bytes, __attribute__((unused)) int bps, int nch)
{
	int i       =          0;
	int global_range_int;
	
	global_range_int = mv_______->decoder_c___globalrange;
	
	int tamanho = mv_______->decoder_c___globalrange * 20;

	if(50 < global_range_int)
	{
	     tamanho = 50 * 20; //fixed limit...
	}
	
	if(8000 == mv_______->decoder_c___intsamplerate)
	{
	     if(24 < global_range_int)
	     {
		  tamanho = 24 * 20;
	     }
	}
	
	if(11025 == mv_______->decoder_c___intsamplerate)
	{
	     if(28 < global_range_int)
	     {
		  tamanho = 28 * 20;
	     }
	}

	if(12000 == mv_______->decoder_c___intsamplerate)
	{
	     if(22 < global_range_int)
	     {
		  tamanho = 22 * 20;
	     }
	}

	switch(mv_______->decoder_c___intsamplerate)
	{
	case 8000 :
	case 11025:
	case 12000:
	case 16000:	     
	case 22050:
	case 24000:
	case 32000:
	case 44100:
	case 48000:
	     break;
	default:

	     pedro_dprintf(-1, "default call\n");
	     tamanho = 0;
	     break;    
	}
	
	if (!mv_______->dsp_c___limpador)
	{
		mv_______->dsp_c___limpador = 1;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored    "-Wmemset-elt-size"
		memset (mv_______->dsp_c___temp1, 0, 250000);
		memset (mv_______->dsp_c___temp2, 0, 250000);
		memset (mv_______->dsp_c___temp3, 0, 250000);
		memset (mv_______->dsp_c___temp4, 0, 250000);
#pragma GCC diagnostic pop
	}

	if (0 == tamanho)
	{
		return 0;
	}

	if (tamanho > 48000)
	{
		assert (0);
	}

	mv_______->dsp_c___chan1 = (short *) buf;

	if (!mv_______->dsp_c___clean)
	{

		mv_______->dsp_c___clean = 1;
		memset (mv_______->dsp_c___sutemp, 0, 50000);

	}

	if (2 == nch)
	{
		for (i = 0; i < bytes; i = i + 2)
		{

			mv_______->dsp_c___temp1[i] = mv_______->dsp_c___chan1[i];
			mv_______->dsp_c___temp2[i] = mv_______->dsp_c___chan1[i + 1];
		}

		for (i = 0; i < (bytes / 2); i++)
		{
			mv_______->dsp_c___temp3[i + tamanho] = mv_______->dsp_c___temp2[i];
		}

		for (i = 0; i < tamanho; i++)
		{
			mv_______->dsp_c___temp3[i] = mv_______->dsp_c___temp4[i];
		}

		for (i = 0; i < tamanho; i = i + 1)
		{
			mv_______->dsp_c___temp4[i] = mv_______->dsp_c___temp2[((bytes / 2) - tamanho) + i];
		}

		for (i = 0; i < bytes; i = i + 2)
		{
			mv_______->dsp_c___chan1[i] = mv_______->dsp_c___temp1[i];
			mv_______->dsp_c___chan1[i + 1] = mv_______->dsp_c___temp3[i];
		}

	}
	return 0;
}

int sound_touch (int reset, int samplerate, int channels, int size,
                 int *sizeout, char *inbuffer, char *outbuffer,
                 int tempoDelta, int pitchDelta, int rateDelta);

int
soundtouch (morcego___i___instance__a__bucaneiro_engineering *mv_______,int reset, int enable, int samplerate, int channels, int size,
            char *buf, int tempoDelta, int pitchDelta, int rateDelta)
{
	int sizeout = 0;

	if (enable)
	{
		sound_touch (reset, samplerate, channels, size, &sizeout, buf,
		             mv_______->dsp_c___outbuffer, tempoDelta, pitchDelta, rateDelta);
		memcpy (buf, mv_______->dsp_c___outbuffer, sizeout);
		return sizeout;
	}
	return size;
}
