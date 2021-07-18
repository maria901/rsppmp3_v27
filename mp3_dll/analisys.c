
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
 
#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar   unsigned  char
#define uint    unsigned   int
#define ulong   unsigned  long
#define ushort  unsigned short
#endif
#endif

#include <windows.h>
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
#include "mv_from_be.h"
#include "gain_analysis.h"
#include "../morcego/be_constants.h"

double be_normalization_method
(
	morcego___i___instance__a__bucaneiro_engineering *mv_______,
	int clear_flag,
	char *buf,
	int len
)
;
__int64 _ftelli64_arab (FILE * stream);
int _fseeki64_arab (FILE * stream, __int64 offset, int origin);
size_t fread_unbuffered (void *ptr, size_t size, size_t nelem, FILE * stream);
size_t fwrite_unbuffered (const void *ptr, size_t size, size_t nelem,
                          FILE * stream);

//funcoes

WCHAR *__stdcall utf8towide (const char *pUTF8);
FILE *buffer_fopen (const char *filename, const char *mode);
char *getnetstatus (int *value);
double getporf (double maxa, double fatiaa);
double getvalf (double maxa, double porr);
double inittimer2 (int value);
int detect (char *filename, __int64 * seekpoint);
__int64 id3v2tag (char *filename);
int id3v2tag_check (char *filename);
int rewrite_header (FILE * out, unsigned int written);
int write_prelim_header (FILE * out, int channels, int samplerate);
void mprintf (const char *format, ...);
void dprintf_z (const char *format, ...);
int
mygain (uchar * buf, uint len, float factor)
{
	float                         temp;
	int                          tempo;
	int               *fatia2 = &tempo;
	int                              i;
	short                       *fatia;

	fatia = (signed short *) buf;

	for (i = 0; i < len; i = i + 2)
	{
		*fatia2 = (int) *fatia;
		temp = (float) *fatia2;
		temp = temp * factor;
		*fatia2 = (int) temp;

		if (*fatia2 > 32767)
		{
			*fatia2 = 32767;
		}
		if (*fatia2 < -32768)
		{
			*fatia2 = -32768;
		}

		*fatia = (signed short) *fatia2;
		fatia++;
	}
	return -2;
}
/**
   return 0 if no error, 1 if cannot load the media file, 2 if an error occurred in the decoder
 */
int
analize (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename, float *globalff, int *aanalized)
{
	be_libav_struct *be_real_real=(be_libav_struct *)mv_______->be_real; //fast
	*aanalized                        =     0;
	*globalff                    =     1.0005;
	__int64 analizedsize              =     0;
	int                                   ret;
	int                               size   ;
	int already                       =     0;
	int bytesprocessed                =     0;
	int executed                      =     0;
	int player_decoder_status    = BE_DECODED;
	int saiagora                      =     0;
	int sampleslimit                  =     0;

	assert(be_real_real);
































	ret = morcego_init_libav (mv_______,be_real_real, 0);

	if (ret)
	{
		*globalff=1.0123;
		*aanalized = 1;
		
		goto saida;
	}

	already = 0;

	int madchannel = be_real_real->be_channels;
	if(madchannel>2)
	{
		madchannel=2;
	}
	int madsamplerate=be_real_real->be_samplerate;

	if
	(
		2==be_real_real->internal_replaygain_fast_mode
		||3==be_real_real->internal_replaygain_fast_mode
	)
	{

		//morcego_seek_100_libav (mv_______,50);

		sampleslimit = madchannel * madsamplerate * 2 * 60;

	}

	while (1)
	{

		if (BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE ==
		    player_decoder_status)
		{
			break;
		}
		int isize=0;
		player_decoder_status =
			morcego_decode_libav (mv_______,4608, mv_______->analisys_c___out, &isize);

		if (BE_ERROR_DURING_DECODE == player_decoder_status)
		{
			*globalff       =  1.0123;
			*aanalized      =       1;
			goto            saida    ;
		}
		size=isize;
		if (already == 0)
		{

			int ret;
			if(mv_______->analisys_c___normalization_is_replaygain)
			{
				ret = InitGainAnalysis (mv_______,madsamplerate);

				if (ret == INIT_GAIN_ANALYSIS_ERROR)
				{
					goto saida;
				}
			}
			else
			{
				be_normalization_method
				(
					mv_______,
					BE_CLEAR____,
					NULL,
					0
				)
				;
			}
			if (madchannel != 1 && madchannel != 2)
			{
				goto saida;
			}

			already = 1;
		}

		{

			if (size > 4)
			{
				int                   ret = 0;
				int                         i;
				float         *pcmleft = NULL;
				float        *pcmright = NULL;
				float            *left = NULL;
				float           *right = NULL;

				signed short *data = (short *) mv_______->analisys_c___out;

				executed = 1;

				if (madchannel == 1)
				{

					if (analizedsize && (!sampleslimit))
					{
						int samplerate = madsamplerate;
						int channels = madchannel;
						int averagebyte;
						averagebyte = samplerate * channels * 2;
						sampleslimit = averagebyte * 10;
					}

					left = (float *) malloc (((size / 2) * sizeof (float)) + 4);
					pcmleft = left;

					for (i = 0; i < size; i = i + 2)
					{
						*pcmleft = (float) *data;
						pcmleft++;
						data++;
					}
					if(mv_______->analisys_c___normalization_is_replaygain)
					{
						ret = AnalyzeSamples (mv_______,left, NULL, (size / 2), 1);
					}
					else
					{

						be_normalization_method
						(
							mv_______,
							BE_PROCESS___,
							mv_______->analisys_c___out,
							size
						)
						;

					}
					bytesprocessed = bytesprocessed + size;

					if (sampleslimit)
					{

						if (bytesprocessed > sampleslimit)
						{
							saiagora = 1;
						}
					}
				}
				else if (madchannel == 2)
				{
					if (analizedsize && (!sampleslimit))
					{
						int samplerate = madsamplerate;
						int channels = madchannel;
						int averagebyte;

						averagebyte = samplerate * channels * 2;
						sampleslimit = averagebyte * 10;
					}

					left = (float *) malloc (((size / 4) * sizeof (float)) + 4);
					pcmleft = left;
					right = (float *) malloc (((size / 4) * sizeof (float)) + 4);
					pcmright = right;

					for (i = 0; i < size; i = i + 4)
					{
						*pcmleft = (float) *data;
						pcmleft++;
						data++;
						*pcmright = (float) *data;
						pcmright++;
						data++;
					}
					if(mv_______->analisys_c___normalization_is_replaygain)
					{
						ret = AnalyzeSamples (mv_______,left, right, (size / 4), 2);
					}
					else
					{

						be_normalization_method
						(
							mv_______,
							BE_PROCESS___,
							mv_______->analisys_c___out,
							size
						)
						;

					}
					bytesprocessed = bytesprocessed + size;

					if (sampleslimit)
					{

						if (bytesprocessed > sampleslimit)
						{
							saiagora = 1;
						}

					}

				}

				if (left)
				{
					free (left);
				}

				if (right)
				{
					free (right);
				}

				if(saiagora)
				{
					goto fim_de_processo;
				}
				if(mv_______->analisys_c___normalization_is_replaygain)
				{
					if (GAIN_ANALYSIS_ERROR == ret)
					{
						*globalff=1.0124;
						*aanalized = 1;
						goto saida2;
					}
				}
			}
		}
	}

fim_de_processo:;

saida:  ;

	if (executed)
	{
		float fator;
		int error = 0;
		if(mv_______->analisys_c___normalization_is_replaygain)
		{
			fator = GetTitleGain (mv_______,&error);
			fator = (float) pow (10., fator / 20.);
		}
		else
		{

			fator =
				be_normalization_method
				(
					mv_______,
					BE_RETRIEVE_NORMALIZATION_VALUE,
					NULL,
					0
				)
			;

		}
/*
                if (fator > 2.50)
                {
                        fator = 2.5;
                }
 */
		if(fator<0.3)
		{
			fator =0.3;
		}
		if (error)
		{
			fator = 1.0125;
		}
		else
		{
			*globalff = fator;
		}

		if(sampleslimit)
		{
			if(bytesprocessed<sampleslimit)
			{
				*globalff = 1.001;
			}
		}
		*aanalized = 1;
	}

saida2:

	morcego_deinit_libav (mv_______);

	return 0;

}
double be_normalization_method
(
	morcego___i___instance__a__bucaneiro_engineering *mv_______,
	int clear_flag,
	char *buf,
	int len
)
{
	int i;
	switch(clear_flag)
	{
	case BE_PROCESS___:
	{
		short *sample = (void*)buf;
		for(i=0; i<len/2; i++)
		{
			short val = sample[i];
			val = abs(val);
			mv_______->analisys_c___analisys_value=BucaneiroMax(mv_______->analisys_c___analisys_value,val);
		}
	}
	break;
	case BE_CLEAR____:
	{
		mv_______->analisys_c___analisys_value=0;
	}
	break;
	case BE_RETRIEVE_NORMALIZATION_VALUE:
	{
		double input=mv_______->analisys_c___analisys_value;
		if(input<1.0)
		{
			input=32768;
		}
		input = 32768. / input;
		return input;
	}
	break;
		return 1.00126;
	}
	return -27.0;
}
