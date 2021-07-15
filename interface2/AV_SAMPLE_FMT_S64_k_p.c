
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
	/*untested*/

	int i_k_p;
	int64_t * ar_buffer_ = (int64_t *) decoded_frame->data[0];
	int16_t * ar_buffer__a_little_more = (int16_t *) buf;

	assert(0 == frame_processed_k_p);                                 //for safety my love....
	frame_processed_k_p = 1;
	for(i_k_p = 0; i_k_p < (data_size/8); i_k_p++)
	{
		ar_buffer__a_little_more[i_k_p] = (int16_t) (ar_buffer_[i_k_p] >> 48);
	}

	*size_out = data_size / 4;

}
else if(6 == mv_______->libav_c___original_number_of_channels_k_p)
{
	/*untested*/
	
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
	int16_t *outputBuffer = (int16_t *)buf;
	int64_t * ar_buffer_ = (int64_t *) decoded_frame->data[0];

	for(i=0; i < number_of_samples_k_p; i++)
	{
		//channel 0
		int32_t sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		save_channel_0_k_p = p;

		save_channel_0_data_double_k_p = (double) sample_k_p;

		p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		save_channel_1_k_p = p;//so usa no final...

		save_channel_1_data_double_k_p = (double) sample_k_p;

		p++;

		////////////////////////////////////////////////
		//center my love...
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////subwoffer
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////surround left 4
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////surround right 5
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

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

		outputBuffer[save_channel_0_k_p] = (int16_t) save_channel_0_data_double_k_p;
		outputBuffer[save_channel_1_k_p] = (int16_t) save_channel_1_data_double_k_p;
	}
}
else if (8 == mv_______->libav_c___original_number_of_channels_k_p)
{
	/*untested*/
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
	int16_t *outputBuffer = (int16_t *)buf;
	int64_t * ar_buffer_ = (int64_t *) decoded_frame->data[0];

	for(i=0; i < number_of_samples_k_p; i++)
	{
		//channel 0
		int32_t sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		save_channel_0_k_p = p;

		save_channel_0_data_double_k_p = (double) sample_k_p;

		p++;

		///////////////////////////////////////////////
		//channel 1
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		save_channel_1_k_p = p;//so usa no final...

		save_channel_1_data_double_k_p = (double) sample_k_p;

		p++;

		////////////////////////////////////////////////
		//8 2
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

//////////////////////////////////////////////////////
///////8 3
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		sample_double_temp_k_p = (double) sample_k_p;

		sample_double_temp_k_p *= 0.708;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

////////////////////////////////////////////////////
/////8 4
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

		///////////////////////////////////////////////
		//////////8 5
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_1_data_double_k_p += sample_double_temp_k_p;

		/////////////////////////////////////////////
		//8 6

		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

		sample_double_temp_k_p = (double) sample_k_p;

		//sample_double_temp_k_p *= AR_K_P_ATTENUATION_LEVEL;

		save_channel_0_data_double_k_p += sample_double_temp_k_p;

/////////////////////////////////////////////////////
//8 7
		sample_k_p = (int32_t) (ar_buffer_[ricardo_deslocador__++] >> 48);

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
else //other combinations of channels that are not 5.1 or 7.1
{
	/*untested*/
	int i_k_p;
	int i_desloca_k_p = 0;
	int i_desloca_2_k_p = 0;
	int64_t * ar_buffer_ = (int64_t *) decoded_frame->data[0];
	int16_t * ar_buffer__a_little_more = (int16_t *) buf;
	//assert(mv_______->libav_c___original_number_of_channels_k_p < 3); //already handled my love...
	assert(0 == frame_processed_k_p);                                 //for safety my love....
	frame_processed_k_p = 1;
	for(i_k_p = 0; i_k_p < (data_size/8); i_k_p++)//simply ignore the additional channels
	{
		if(0 == i_desloca_2_k_p % mv_______->libav_c___original_number_of_channels_k_p)
		{
			ar_buffer__a_little_more[i_desloca_k_p] = (int16_t) (ar_buffer_[i_k_p] >> 48);
			i_desloca_k_p++;
		}

		if(1 == i_desloca_2_k_p % mv_______->libav_c___original_number_of_channels_k_p)
		{
			ar_buffer__a_little_more[i_desloca_k_p] = (int16_t) (ar_buffer_[i_k_p] >> 48);
			i_desloca_k_p++;
		}

		i_desloca_2_k_p++;
	}

	*size_out = i_desloca_k_p * 2;
}
