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

 
if(3 > mv_______->libav_c___original_number_of_channels_k_p)
{
	int nb_samples = decoded_frame->nb_samples;
	int channels = pCodecCtx->channels;
	if(channels>2)
	{
		channels=2;
	}
	frame_processed_k_p = 1;
	int outputBufferLen = nb_samples * channels * 2;
	*size_out=outputBufferLen;
	short *outputBuffer=(short*)buf;
	int in_samples = decoded_frame->nb_samples;
	int i=0;
	int64_t * inputChannel0 = (int64_t *)decoded_frame->extended_data[0];
	// Mono
	if (pCodecCtx->channels==1)
	{
		for (i=0; i<in_samples; i++)
		{
			int64_t sample = *inputChannel0++;
			outputBuffer[i] = (int16_t) (sample >> 48);
		}
	}
	// Stereo
	else
	{
		int64_t * inputChannel1 = (int64_t *)decoded_frame->extended_data[1];
		for (i=0; i<in_samples; i++)
		{
			int64_t sample = *inputChannel0++;
			int64_t sample2 = *inputChannel1++;
			outputBuffer[i*2] = (int16_t) ((sample) >> 48);
			outputBuffer[i*2+1] = (int16_t) ((sample2) >> 48);
		}
	}
}
else if(6 == mv_______->libav_c___original_number_of_channels_k_p)
{
	int p_k_p = 0;
	int i_k_p;
	int save_channel_0_k_p;
	int save_channel_1_k_p;
	double save_channel_0_data_double_k_p;
	double save_channel_1_data_double_k_p;
	double sample_double_temp_k_p;
	int nb_samples = decoded_frame->nb_samples;
	frame_processed_k_p = 1;
	int outputBufferLen = nb_samples * 2 * 2;
	*size_out=outputBufferLen;
	int64_t *outputBuffer = (int64_t *)buf;
	int64_t *buf0 = (int64_t *) decoded_frame->extended_data[0];
	int64_t *buf1 = (int64_t *) decoded_frame->extended_data[1];
	int64_t *buf2 = (int64_t *) decoded_frame->extended_data[2];
	int64_t *buf3 = (int64_t *) decoded_frame->extended_data[3];
	int64_t *buf4 = (int64_t *) decoded_frame->extended_data[4];
	int64_t *buf5 = (int64_t *) decoded_frame->extended_data[5];

	for(i_k_p = 0; i_k_p < nb_samples; i_k_p++)
	{
		//channel 0
		int sample_k_p = (int) (buf0[i_k_p] >> 48L);

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}

		save_channel_0_k_p = p_k_p;

		save_channel_0_data_double_k_p = (double) sample_k_p;

		p_k_p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = (int) (buf1[i_k_p] >> 48L);

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}

		save_channel_1_k_p = p_k_p;//so usa no final...

		save_channel_1_data_double_k_p = (double) sample_k_p;

		p_k_p++;

		////////////////////////////////////////////////
		//center my love...
		sample_k_p = (int) (buf2[i_k_p] >> 48L);

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////subwoffer
		sample_k_p = (int) (buf3[i_k_p] >> 48L);

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////surround left 4
		sample_k_p = (int) (buf4[i_k_p] >> 48L);

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////surround right 5
		sample_k_p = (int) (buf5[i_k_p] >> 48L);

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

		/////////////////////////////////////////////
		//finalizing

		save_channel_0_data_double_k_p *= .5;

		if(32767.0 < save_channel_0_data_double_k_p)
		{
			save_channel_0_data_double_k_p = 32767.0;
		}

		if(-32768.0 > save_channel_0_data_double_k_p)
		{
			save_channel_0_data_double_k_p = -32768.0;
		}

		save_channel_1_data_double_k_p *= .5;

		if(32767.0 < save_channel_1_data_double_k_p)
		{
			save_channel_1_data_double_k_p = 32767.0;
		}

		if(-32768.0 > save_channel_1_data_double_k_p)
		{
			save_channel_1_data_double_k_p = -32768.0;
		}
		
		outputBuffer[save_channel_0_k_p] = (signed short) save_channel_0_data_double_k_p;
		outputBuffer[save_channel_1_k_p] = (signed short) save_channel_1_data_double_k_p;
	}

}
else if(8 == mv_______->libav_c___original_number_of_channels_k_p)
{
	int p_k_p = 0;
	int i_k_p;
	int save_channel_0_k_p;
	int save_channel_1_k_p;
	double save_channel_0_data_double_k_p;
	double save_channel_1_data_double_k_p;
	double sample_double_temp_k_p;
	int nb_samples = decoded_frame->nb_samples;
	frame_processed_k_p = 1;
	int outputBufferLen = nb_samples * 2 * 2;
	*size_out=outputBufferLen;
	int64_t *outputBuffer = (int64_t *)buf;
	int64_t *buf0 = (int64_t *) decoded_frame->extended_data[0];
	int64_t *buf1 = (int64_t *) decoded_frame->extended_data[1];
	int64_t *buf2 = (int64_t *) decoded_frame->extended_data[2];
	int64_t *buf3 = (int64_t *) decoded_frame->extended_data[3];
	int64_t *buf4 = (int64_t *) decoded_frame->extended_data[4];
	int64_t *buf5 = (int64_t *) decoded_frame->extended_data[5];
	int64_t *buf6 = (int64_t *) decoded_frame->extended_data[6];
	int64_t *buf7 = (int64_t *) decoded_frame->extended_data[7];
	for(i_k_p=0; i_k_p < nb_samples; i_k_p++)
	{
		//channel 0
		int sample_k_p = (int) (buf0[i_k_p] >> 48L);
		
		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		
		save_channel_0_k_p = p_k_p;

		save_channel_0_data_double_k_p = (double) sample_k_p;

		p_k_p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = (int) (buf1[i_k_p] >> 48L);
				
		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
				
		save_channel_1_k_p = p_k_p;//so usa no final...

		save_channel_1_data_double_k_p = (double) sample_k_p;

		p_k_p++;

		////////////////////////////////////////////////
		//8 2
		sample_k_p = (int) (buf2[i_k_p] >> 48L);
		
		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		
		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////8 3
		sample_k_p = (int) (buf3[i_k_p] >> 48L);
			
		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		
		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////8 4
		sample_k_p = (int) (buf4[i_k_p] >> 48L);
		
		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		
		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////8 5
		sample_k_p = (int) (buf5[i_k_p] >> 48L);
		
		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		
		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

		/////////////////////////////////////////////
		//8 6

		sample_k_p = (int) (buf6[i_k_p] >> 48L);
		
		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		
		sample_double_temp_k_p = sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

/////////////////////////////////////////////////////
//8 7
		sample_k_p = (int) (buf7[i_k_p] >> 48L);

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		
		sample_double_temp_k_p = sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		///finalizing 8

		save_channel_0_data_double_k_p *= .5;

		if(32767.0 < save_channel_0_data_double_k_p)
		{
			save_channel_0_data_double_k_p = 32767.0;
		}

		if(-32768.0 > save_channel_0_data_double_k_p)
		{
			save_channel_0_data_double_k_p = -32768.0;
		}

		save_channel_1_data_double_k_p *= .5;

		if(32767.0 < save_channel_1_data_double_k_p)
		{
			save_channel_1_data_double_k_p = 32767.0;
		}

		if(-32768.0 > save_channel_1_data_double_k_p)
		{
			save_channel_1_data_double_k_p = -32768.0;
		}

		outputBuffer[save_channel_0_k_p] = (signed short) save_channel_0_data_double_k_p;
		outputBuffer[save_channel_1_k_p] = (signed short) save_channel_1_data_double_k_p;
	}	
}
else //other combinations of channels that are not 5.1 or 7.1
{
	int nb_samples = decoded_frame->nb_samples;
	int outputBufferLen = nb_samples * 2 * 2;
	*size_out=outputBufferLen;
	short *outputBuffer=(short*)buf;
	int in_samples = decoded_frame->nb_samples;
	int i=0;
	int64_t * inputChannel0 = (int64_t *)decoded_frame->extended_data[0];
	int64_t * inputChannel1 = (int64_t *)decoded_frame->extended_data[1];
	frame_processed_k_p = 1;
	for (i=0; i<in_samples; i++)
	{
		int64_t sample = *inputChannel0++;
		int64_t sample2 = *inputChannel1++;
		outputBuffer[i*2] =   (int16_t) ((sample) >> 48);
		outputBuffer[i*2+1] = (int16_t) ((sample2) >> 48);
	}
}
