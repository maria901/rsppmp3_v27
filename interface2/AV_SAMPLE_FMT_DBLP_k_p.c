/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                             *
*        Licensa de C?pia (C) <2022>  <Corpora??o do Trabalho Bin?rio>        *
*                                                                             *
*     Este  programa  ? software livre: voc? pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral P?blica como     10
*     publicado  pela Funda??o  de Software  Livre, tanto a vers?o 3  da      *
*     Licensa, ou (dependendo da sua op??o) qualquer vers?o posterior.        *
*                                                                             *
*     Este  programa ? distribu?do na  esperan?a que isto vai  ser ?til,      *
*     mas SEM  QUALQUER GARANTIA; sem  at? mesmo a implicada garantia de      *
*     COMERCIALIZA??O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral P?blica para mais detalhes.                               *
*                                                                             *
*     Voc? deve ter recebido uma  c?pia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa P?blica Menor junto com este programa                           *
*     Se n?o, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito r?pida) WhatsApp               *
*     (+55)41 9627 1708 - isto est? sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
 
if(3 > mv_______->libav_c___original_number_of_channels_k_p)
{

	frame_processed_k_p = 1;
	int nb_samples = decoded_frame->nb_samples;
	int channels = pCodecCtx->channels;

	if(channels>2)
	{
		channels=2;
	}

	int outputBufferLen = nb_samples * channels * 2;
	*size_out=outputBufferLen;
	short *outputBuffer=(short*)buf;
	int in_samples = decoded_frame->nb_samples;
	int i=0;
	double * inputChannel0 = (double *)decoded_frame->extended_data[0];

	// Mono
	if (pCodecCtx->channels==1)
	{
		for (i=0; i<in_samples; i++)
		{
			double sample = *inputChannel0++;
			if (sample<-1.0f) sample=-1.0f;
			else if (sample>1.0f) sample=1.0f;
			outputBuffer[i] = (int16_t) (sample * 32766.0f);
		}
	}
	// Stereo
	else
	{
		double * inputChannel1 = (double *)decoded_frame->extended_data[1];
		for (i=0; i<in_samples; i++)
		{

			double sample = *inputChannel0++;
			if (sample<-1.0f) sample=-1.0f;
			else if (sample>1.0f) sample=1.0f;
			double sample2 = *inputChannel1++;
			if (sample2<-1.0f) sample2=-1.0f;
			else if (sample2>1.0f) sample2=1.0f;

			outputBuffer[i*2] = (int16_t) ((sample) * 32766.0f);
			outputBuffer[i*2+1] = (int16_t) ((sample2) * 32766.0f);
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
	double *outputBuffer = (double *)buf;
	double *buf0 = (double *) decoded_frame->extended_data[0];
	double *buf1 = (double *) decoded_frame->extended_data[1];
	double *buf2 = (double *) decoded_frame->extended_data[2];
	double *buf3 = (double *) decoded_frame->extended_data[3];
	double *buf4 = (double *) decoded_frame->extended_data[4];
	double *buf5 = (double *) decoded_frame->extended_data[5];

	for(i_k_p = 0; i_k_p < nb_samples; i_k_p++)
	{
		//channel 0
		double sample_k_p = buf0[i_k_p] * 32767.0;

		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}

		save_channel_0_k_p = p_k_p;

		save_channel_0_data_double_k_p = sample_k_p;

		p_k_p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = buf1[i_k_p] * 32767.0;

		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}

		save_channel_1_k_p = p_k_p;//so usa no final...

		save_channel_1_data_double_k_p = sample_k_p;

		p_k_p++;

		////////////////////////////////////////////////
		//center my love...
		sample_k_p = buf2[i_k_p]  * 32767.0;

		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}

		sample_double_temp_k_p = sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////subwoffer
		sample_k_p = buf3[i_k_p]  * 32767.0;

		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}

		sample_double_temp_k_p = sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////surround left 4
		sample_k_p = buf4[i_k_p]  * 32767.0;

		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}

		sample_double_temp_k_p = sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////surround right 5
		sample_k_p = buf5[i_k_p]  * 32767.0;

		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}

		sample_double_temp_k_p = sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

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
	double *outputBuffer = (double *)buf;
	double *buf0 = (double *) decoded_frame->extended_data[0];
	double *buf1 = (double *) decoded_frame->extended_data[1];
	double *buf2 = (double *) decoded_frame->extended_data[2];
	double *buf3 = (double *) decoded_frame->extended_data[3];
	double *buf4 = (double *) decoded_frame->extended_data[4];
	double *buf5 = (double *) decoded_frame->extended_data[5];
	double *buf6 = (double *) decoded_frame->extended_data[6];
	double *buf7 = (double *) decoded_frame->extended_data[7];
	
	for(i_k_p=0; i_k_p < nb_samples; i_k_p++)
	{
		//channel 0
		double sample_k_p = buf0[i_k_p] * 32767.0;
		
		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}
		
		save_channel_0_k_p = p_k_p;

		save_channel_0_data_double_k_p = sample_k_p;

		p_k_p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = buf1[i_k_p] * 32767.0;
				
		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}
				
		save_channel_1_k_p = p_k_p;//so usa no final...

		save_channel_1_data_double_k_p = sample_k_p;

		p_k_p++;

		////////////////////////////////////////////////
		//8 2
		sample_k_p = buf2[i_k_p] * 32767.0;
		
		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}
		
		sample_double_temp_k_p = sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////8 3
		sample_k_p = buf3[i_k_p] * 32767.0;
			
		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}
		
		sample_double_temp_k_p = sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////8 4
		sample_k_p = buf4[i_k_p] * 32767.0;
		
		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}
		
		sample_double_temp_k_p = sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////8 5
		sample_k_p = buf5[i_k_p] * 32767.0;
		
		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}
		
		sample_double_temp_k_p = sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

		/////////////////////////////////////////////
		//8 6

		sample_k_p = buf6[i_k_p] * 32767.0;
		
		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
		}
		
		sample_double_temp_k_p = sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

/////////////////////////////////////////////////////
//8 7
		sample_k_p = buf7[i_k_p] * 32767.0;

		if(32767.0 < sample_k_p)
		{
			sample_k_p = 32767.0;
		}

		if(-32768.0 > sample_k_p)
		{
			sample_k_p = -32768.0;
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
	frame_processed_k_p = 1;
	int nb_samples = decoded_frame->nb_samples;
	int outputBufferLen = nb_samples * 2 * 2;
	*size_out=outputBufferLen;
	short *outputBuffer=(short*)buf;
	int in_samples = decoded_frame->nb_samples;
	int i=0;
	double * inputChannel0 = (double *)decoded_frame->extended_data[0];
	double * inputChannel1 = (double *)decoded_frame->extended_data[1];
	for (i=0; i<in_samples; i++)
	{
		double sample = *inputChannel0++;
		if (sample<-1.0f) sample=-1.0f;
		else if (sample>1.0f) sample=1.0f;
		double sample2 = *inputChannel1++;
		if (sample2<-1.0f) sample2=-1.0f;
		else if (sample2>1.0f) sample2=1.0f;

		outputBuffer[i*2] = (int16_t) ((sample) * 32767.0f);
		outputBuffer[i*2+1] = (int16_t) ((sample2) * 32767.0f);
	}

}
