
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de C�pia (C) <2021>  <Corpora��o do Trabalho Bin�rio>         *
 *                                                                              *
 *     Este  programa  � software livre: voc� pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como       8
 *     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da       *
 *     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.         *
 *                                                                              *
 *     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de       *
 *     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P�blica para mais detalhes.                                *
 *                                                                              *
 *     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P�blica Menor junto com este programa                            *
 *     Se n�o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita r�pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/
 
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

	for (i = 0; i < (int) len; i = i + 2)
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
analize (morcego___i___instance__a__bucaneiro_engineering *mv_______, __attribute__((unused)) char *filename, float *globalff, int *aanalized)
{
	be_libav_struct *be_real_real=(be_libav_struct *)mv_______->be_real; //fast
	*aanalized                               =          0;
	*globalff                                =     1.0005;
	__int64 analizedsize                     =          0;
	int                                               ret;
	int                                           size   ;
	int already                              =          0;
	int bytesprocessed                       =          0;
	int executed                             =          0;
	int player_decoder_status                = BE_DECODED;
	int saiagora                             =          0;
	int sampleslimit                         =          0;
	double amanda_s_smart_ape_timestamp      =          0;
	assert(be_real_real);

//agora checa se da ou nao

amanda_s_smart_ape_timestamp = get_bucaneiro_tick();

if (mv_______->libav_c___amanda_s_smart_ape_use_cache)
{

	mv_______->libav_c___normalization_BENOR_amanda_s_smart_ape[0] = 0;
	
	mv_______->libav_c___normalization_repla_amanda_s_smart_ape[0] = 0;

     if (true == amanda_s_smart_ape_query_webm_and_normalization(mv_______->libav_c___signature___________amanda_s_smart_ape, mv_______->libav_c___webm________________amanda_s_smart_ape,
								 mv_______->libav_c___normalization_mode__amanda_s_smart_ape, mv_______->libav_c___normalization_repla_amanda_s_smart_ape, mv_______->libav_c___normalization_BENOR_amanda_s_smart_ape, mv_______->libav_c___normalization_valu3_amanda_s_smart_ape, &mv_______->libav_c___has_an_entry))
     {

	  /*
	    printf("webm .%s.\n", webm________________amanda_s_smart_ape);
	    printf("webm .%s.\n", webm________________amanda_s_smart_ape);
	  */

	  //para compilar rsppmp3: 1001
	  //para rodar rsppmp3   : 1548
	  	   
	   if(strlen(mv_______->libav_c___normalization_repla_amanda_s_smart_ape) && mv_______->analisys_c___normalization_is_replaygain)
	   {
		   *globalff = strtod(mv_______->libav_c___normalization_repla_amanda_s_smart_ape, NULL);
		   
		   *aanalized = 1;
		   
		   goto saida_amanda_s_smart_ape;
	   }
	   if(strlen(mv_______->libav_c___normalization_BENOR_amanda_s_smart_ape) && !mv_______->analisys_c___normalization_is_replaygain)
	   {
		   *globalff = strtod(mv_______->libav_c___normalization_BENOR_amanda_s_smart_ape, NULL);
		   
		   *aanalized = 1;
		   
		   goto saida_amanda_s_smart_ape;
	   }
					   
	  

     }


}












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
			morcego_decode_libav (mv_______, 4608, mv_______->analisys_c___out, &isize);

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
if(mv_______->libav_c___amanda_s_smart_ape_use_cache)
{
	if(mv_______->libav_c___has_an_entry)
	{
		//update...
				
		if(mv_______->analisys_c___normalization_is_replaygain)
		{
			strcpy(mv_______->libav_c___SQL_call_by_amanda, "update Amanda_27_cache set normalization_value_amanda_s_smart_ape = '");
		}
		else
		{
			strcpy(mv_______->libav_c___SQL_call_by_amanda, "update Amanda_27_cache set normalization_valu2_amanda_s_smart_ape = '");
		}
		sprintf(mv_______->libav_c___SQL_call_by_amanda + strlen(mv_______->libav_c___SQL_call_by_amanda), "%f", *globalff);

		strcat(mv_______->libav_c___SQL_call_by_amanda, "' where entry_______________amanda_s_smart_ape = '");

		strcpy(mv_______->libav_c___SQL_temp_by_amanda, mv_______->libav_c___signature___________amanda_s_smart_ape);

		morcego_encoder_amanda_s_smart_ape(mv_______->libav_c___SQL_temp_by_amanda);

		strcat(mv_______->libav_c___SQL_call_by_amanda, mv_______->libav_c___SQL_temp_by_amanda);

		strcat(mv_______->libav_c___SQL_call_by_amanda, "';;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;");

		if(amanda_s_smart_ape_do_sql(mv_______->libav_c___SQL_call_by_amanda))
		{
			
		}
		else
		{
			
		}

	}
	else
	{
		//create entry
				
				  mv_______->libav_c___webm________________amanda_s_smart_ape[0] = 0;

				  mv_______->libav_c___normalization_repla_amanda_s_smart_ape[0] = '\0';

				  mv_______->libav_c___normalization_BENOR_amanda_s_smart_ape[0] = 0x0;

				  mv_______->libav_c___normalization_valu3_amanda_s_smart_ape[0] = 0b0;

				if(mv_______->analisys_c___normalization_is_replaygain)
				{
					sprintf(mv_______->libav_c___normalization_repla_amanda_s_smart_ape, "%f", *globalff);
				}
				else
				{
					sprintf(mv_______->libav_c___normalization_BENOR_amanda_s_smart_ape, "%f", *globalff);
				}

				  if (amanda_s_smart_ape_add_entry(mv_______->libav_c___signature___________amanda_s_smart_ape, mv_______->libav_c___webm________________amanda_s_smart_ape, mv_______->libav_c___normalization_repla_amanda_s_smart_ape, mv_______->libav_c___normalization_BENOR_amanda_s_smart_ape,
												   mv_______->libav_c___normalization_valu3_amanda_s_smart_ape))
				  {
					  
				  }
				  //here, por parts...
				  //ja passa os 4...

				  //vamos...
		
	}
}

goto saida_amanda_s_smart_ape;

saida_amanda_s_smart_ape:
;

	amanda_s_smart_ape_timestamp = get_bucaneiro_tick() - amanda_s_smart_ape_timestamp;
	
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
