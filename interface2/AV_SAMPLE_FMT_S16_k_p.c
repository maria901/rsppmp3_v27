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
     /**
      * This part of the code will copy the 16 bits signed data to the output, just it...	
      * 
      * tested...
      */
     
     assert(0 == frame_processed_k_p); //for safety my love....
     frame_processed_k_p = 1;
     
     memcpy(buf, decoded_frame->data[0], data_size), *size_out = data_size;
}
else if(6 == mv_______->libav_c___original_number_of_channels_k_p)
{
	/* tested */
	int p = 0;
	int i;
	int save_channel_0_k_p;
	int save_channel_1_k_p;
	double save_channel_0_data_double_k_p;
	double save_channel_1_data_double_k_p;
	double sample_double_temp_k_p;
	int number_of_samples_k_p = decoded_frame->nb_samples;
	int ricardo_deslocador__ = 0;
	frame_processed_k_p = 1;

	int outputBufferLen = number_of_samples_k_p * 2 * 2;
	*size_out=outputBufferLen;
	short *outputBuffer = (int16_t *)buf;
	int16_t * ar_buffer_ = (int16_t *) decoded_frame->data[0];

	for(i=0; i < number_of_samples_k_p; i++)
	{
		//channel 0
		int16_t sample_k_p = ar_buffer_[ricardo_deslocador__++];

		save_channel_0_k_p = p;

		save_channel_0_data_double_k_p = (double) sample_k_p;

		p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = ar_buffer_[ricardo_deslocador__++];

		save_channel_1_k_p = p;//so usa no final...

		save_channel_1_data_double_k_p = (double) sample_k_p;

		p++;

		////////////////////////////////////////////////
		//center my love...
		sample_k_p = ar_buffer_[ricardo_deslocador__++];

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////subwoffer
		sample_k_p = ar_buffer_[ricardo_deslocador__++];

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////surround left 4
		sample_k_p = ar_buffer_[ricardo_deslocador__++];

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////surround right 5
		sample_k_p = ar_buffer_[ricardo_deslocador__++];

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
else if (8 == mv_______->libav_c___original_number_of_channels_k_p)
{
	/* tested */
	int p = 0;
	int i;
	int save_channel_0_k_p;
	int save_channel_1_k_p;
	double save_channel_0_data_double_k_p;
	double save_channel_1_data_double_k_p;
	double sample_double_temp_k_p;
	int number_of_samples_k_p = decoded_frame->nb_samples;
	int ricardo_deslocador__ = 0;
	frame_processed_k_p = 1;

	int outputBufferLen = number_of_samples_k_p * 2 * 2;
	*size_out=outputBufferLen;
	short *outputBuffer = (int16_t *)buf;
	int16_t * ar_buffer_ = (int16_t *) decoded_frame->data[0];

	for(i=0; i < number_of_samples_k_p; i++)
	{
		//channel 0
		/*why int my love?...*/int sample_k_p = (int) ar_buffer_[ricardo_deslocador__++];

		save_channel_0_k_p = p;

		save_channel_0_data_double_k_p = (double) sample_k_p;

		p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = (int) ar_buffer_[ricardo_deslocador__++];

		save_channel_1_k_p = p;//so usa no final...

		save_channel_1_data_double_k_p = (double) sample_k_p;

		p++;

		////////////////////////////////////////////////
		//8 2
		sample_k_p = (int) ar_buffer_[ricardo_deslocador__++];

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////8 3
		sample_k_p = (int) ar_buffer_[ricardo_deslocador__++];

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////8 4
		sample_k_p = (int) ar_buffer_[ricardo_deslocador__++];

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////8 5
		sample_k_p = (int) ar_buffer_[ricardo_deslocador__++];

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

		/////////////////////////////////////////////
		//8 6

		sample_k_p = (int) ar_buffer_[ricardo_deslocador__++];

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

/////////////////////////////////////////////////////
//8 7
		sample_k_p = (int) ar_buffer_[ricardo_deslocador__++];

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
else //if multichannel in an unkown number of channels then only the first two will play
{
	/* tested */
	int i_k_p;
	int i_desloca_k_p = 0;
	int i_desloca_2_k_p = 0;
	int16_t * ar_buffer_ = (int16_t *) decoded_frame->data[0];
	int16_t * ar_buffer__a_little_more = (int16_t *) buf;
	//assert(mv_______->libav_c___original_number_of_channels_k_p < 3); //already handled my love...
	assert(0 == frame_processed_k_p);                                 //for safety my love....
	frame_processed_k_p = 1;
	for(i_k_p = 0; i_k_p < (data_size/2); i_k_p++)
	{
		if(0 == i_desloca_2_k_p % mv_______->libav_c___original_number_of_channels_k_p)
		{
			ar_buffer__a_little_more[i_desloca_k_p] = ar_buffer_[i_k_p];
			i_desloca_k_p++;
		}

		if(1 == i_desloca_2_k_p % mv_______->libav_c___original_number_of_channels_k_p)
		{
			ar_buffer__a_little_more[i_desloca_k_p] = ar_buffer_[i_k_p];
			i_desloca_k_p++;
		}

		i_desloca_2_k_p++;
	}

	*size_out = i_desloca_k_p * 2;
}
