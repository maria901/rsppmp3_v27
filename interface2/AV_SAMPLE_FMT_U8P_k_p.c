
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
 
if(3 > mv_______->libav_c___original_number_of_channels_k_p)
{

	int nb_samples = decoded_frame->nb_samples;
	int channels = pCodecCtx->channels;

	if(channels>2) //pode ser um ou dois                               //solved... 13-October-2020
	{
		channels=2;
	}

	frame_processed_k_p = 1;

	int outputBufferLen = nb_samples * channels * 2;
	*size_out=outputBufferLen;
	short *outputBuffer = (int16_t *)buf;
	unsigned char *buf4;
	unsigned char *buf5;

	buf4 = (unsigned char *) decoded_frame->extended_data[0];

	if(2==channels)
	{
		buf5 = (unsigned char *) decoded_frame->extended_data[1];
	}
	int p = 0;
	int i;
	for(i=0; i < nb_samples; i++)
	{
		int sample_k_p = (int) buf4[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}

		outputBuffer[p++] = (signed short) sample_k_p;

		if(2==channels)//precisa porque pode ser um
		{
			sample_k_p = (int) buf5[i];

			sample_k_p = sample_k_p - 128;

			sample_k_p *= 256;

			if(32767 < sample_k_p)
			{
				sample_k_p = 32767;
			}

			if(-32768 > sample_k_p)
			{
				sample_k_p = -32768;
			}

			outputBuffer[p++] = (signed short) sample_k_p;
		}
	}
}
else if(6 == mv_______->libav_c___original_number_of_channels_k_p)
{
	int p = 0;
	int i;
	int save_channel_0_k_p;
	int save_channel_1_k_p;
	double save_channel_0_data_double_k_p;
	double save_channel_1_data_double_k_p;
	double sample_double_temp_k_p;
	int nb_samples = decoded_frame->nb_samples;

	frame_processed_k_p = 1;

	int outputBufferLen = nb_samples * 2 * 2;
	*size_out=outputBufferLen;
	short *outputBuffer = (int16_t *)buf;
	unsigned char *buf0 = (unsigned char *) decoded_frame->extended_data[0];
	unsigned char *buf1 = (unsigned char *) decoded_frame->extended_data[1];
	unsigned char *buf2 = (unsigned char *) decoded_frame->extended_data[2];
	unsigned char *buf3 = (unsigned char *) decoded_frame->extended_data[3];
	unsigned char *buf4 = (unsigned char *) decoded_frame->extended_data[4];
	unsigned char *buf5 = (unsigned char *) decoded_frame->extended_data[5];

	for(i=0; i < nb_samples; i++)
	{
		//channel 0
		int sample_k_p = (int) buf0[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		save_channel_0_k_p = p;

		save_channel_0_data_double_k_p = (double) sample_k_p;

		p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = (int) buf1[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		save_channel_1_k_p = p;//so usa no final...

		save_channel_1_data_double_k_p = (double) sample_k_p;

		p++;

		////////////////////////////////////////////////
		//center my love...
		sample_k_p = (int) buf2[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////subwoffer
		sample_k_p = (int) buf3[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////surround left 4
		sample_k_p = (int) buf4[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////surround right 5
		sample_k_p = (int) buf5[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

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
	int p = 0;
	int i;
	int save_channel_0_k_p;
	int save_channel_1_k_p;
	double save_channel_0_data_double_k_p;
	double save_channel_1_data_double_k_p;
	double sample_double_temp_k_p;
	int nb_samples = decoded_frame->nb_samples;

	frame_processed_k_p = 1;

	int outputBufferLen = nb_samples * 2 * 2;
	*size_out=outputBufferLen;
	short *outputBuffer = (int16_t *)buf;
	unsigned char *buf0 = (unsigned char *) decoded_frame->extended_data[0];
	unsigned char *buf1 = (unsigned char *) decoded_frame->extended_data[1];
	unsigned char *buf2 = (unsigned char *) decoded_frame->extended_data[2];
	unsigned char *buf3 = (unsigned char *) decoded_frame->extended_data[3];
	unsigned char *buf4 = (unsigned char *) decoded_frame->extended_data[4];
	unsigned char *buf5 = (unsigned char *) decoded_frame->extended_data[5];
	unsigned char *buf6 = (unsigned char *) decoded_frame->extended_data[6];
	unsigned char *buf7 = (unsigned char *) decoded_frame->extended_data[7];

	for(i=0; i < nb_samples; i++)
	{
		//channel 0
		int sample_k_p = (int) buf0[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		save_channel_0_k_p = p;

		save_channel_0_data_double_k_p = (double) sample_k_p;

		p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = (int) buf1[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}
		save_channel_1_k_p = p;//so usa no final...

		save_channel_1_data_double_k_p = (double) sample_k_p;

		p++;

		////////////////////////////////////////////////
		//8 2
		sample_k_p = (int) buf2[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////8 3
		sample_k_p = (int) buf3[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////8 4
		sample_k_p = (int) buf4[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////8 5
		sample_k_p = (int) buf5[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

		/////////////////////////////////////////////
		//8 6

		sample_k_p = (int) buf6[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

/////////////////////////////////////////////////////
//8 7
		sample_k_p = (int) buf7[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		sample_double_temp_k_p = (double) sample_k_p;

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
else //other combinations of channels that ar not 5.1 or 7.1
{
	int nb_samples = decoded_frame->nb_samples;
	int channels = pCodecCtx->channels;

	if(channels>2)                                //solved... 13-October-2020
	{
		channels=2;
	}

	frame_processed_k_p = 1;

	int outputBufferLen = nb_samples * channels * 2;
	*size_out=outputBufferLen;
	short *outputBuffer = (int16_t *)buf;
	unsigned char *buf4;
	unsigned char *buf5;

	buf4 = (unsigned char *) decoded_frame->extended_data[0];

	if(2==channels)
	{
		buf5 = (unsigned char *) decoded_frame->extended_data[1];
	}
	int p = 0;
	int i;
	for(i=0; i < nb_samples; i++)
	{
		int sample_k_p = (int) buf4[i];

		sample_k_p = sample_k_p - 128;

		sample_k_p *= 256;

		if(32767 < sample_k_p)
		{
			sample_k_p = 32767;
		}

		if(-32768 > sample_k_p)
		{
			sample_k_p = -32768;
		}

		outputBuffer[p++] = (signed short) sample_k_p;

		if(2==channels)
		{
			sample_k_p = (int) buf5[i];

			sample_k_p = sample_k_p - 128;

			sample_k_p *= 256;

			if(32767 < sample_k_p)
			{
				sample_k_p = 32767;
			}

			if(-32768 > sample_k_p)
			{
				sample_k_p = -32768;
			}

			outputBuffer[p++] = (signed short) sample_k_p;
		}
	}
}
