
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
 
void
init_iir_60 (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{

	mv_______->iir_c_60__i=0;
	mv_______->iir_c_60__k=1;
	mv_______->iir_c_60__j=2;

	mv_______->iir_c_60__eqcfg.band_num = 10;
	mv_______->iir_c_60__eqcfg.use_xmms_original_freqs = 1;
	mv_______->iir_c_60__eqcfg.extra_filtering = 0;

	if (mv_______->iir_c_60__eqcfg.band_num == 15)
	{
		mv_______->iir_c_60__iir_cf = (void*)iir_cf15;
		mv_______->iir_c_60__iir_cf_fixed = (void*)iir_cf15_fixed;
	}
	else if (mv_______->iir_c_60__eqcfg.band_num == 31)
	{
		mv_______->iir_c_60__iir_cf = (void*)iir_cf31;
		mv_______->iir_c_60__iir_cf_fixed = (void*)iir_cf31_fixed;
	}
	else if (mv_______->iir_c_60__eqcfg.band_num == 25)
	{
		mv_______->iir_c_60__iir_cf = (void*)iir_cf25;
		mv_______->iir_c_60__iir_cf_fixed = (void*)iir_cf25_fixed;
	}
	else if (mv_______->iir_c_60__eqcfg.band_num == 10 && mv_______->iir_c_60__eqcfg.use_xmms_original_freqs)
	{
		mv_______->iir_c_60__iir_cf = (void*)iir_cforiginal10;
		mv_______->iir_c_60__iir_cf_fixed = (void*)iir_cforiginal10_fixed;
	}
	else
	{
		mv_______->iir_c_60__iir_cf = (void*)iir_cf10;
		mv_______->iir_c_60__iir_cf_fixed = (void*)iir_cf10_fixed;
	}

	memset (mv_______->iir_c_60__data_history, 0, sizeof (sXYData) * 31 * 2);
	memset (mv_______->iir_c_60__data_history2, 0, sizeof (sXYData) * 31 * 2);

	memset (mv_______->iir_c_60__data_history_fixed, 0, sizeof (sXYData_fixed) * 31 * 2);
	memset (mv_______->iir_c_60__data_history2_fixed, 0, sizeof (sXYData_fixed) * 31 * 2);

}

int
iir___60 (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *d, int length, int channels)
{
	int index, band,  channel;
	int            halflength;
	float              pcm[2];
	int deslocador     =    0;

	//double fixo_=      -0.2;

	short *data = (short *) d;

	mv_______->iir_c___value_60=0;
	mv_______->iir_c___value_170=0;
	mv_______->iir_c___value_310=0;
	mv_______->iir_c___value_600=0;
	mv_______->iir_c___value_1000=0;
	mv_______->iir_c___value_3000=0;
	mv_______->iir_c___value_6000=0;
	mv_______->iir_c___value_12000=0;
	mv_______->iir_c___value_14000=0;
	mv_______->iir_c___value_16000=0;

	mv_______->iir_c_60__gain[0][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[0][1] = MAXIMUM_FOR_FFT_____; //60
	mv_______->iir_c_60__gain[1][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[1][1] = MAXIMUM_FOR_FFT_____; //170
	mv_______->iir_c_60__gain[2][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[2][1] = MAXIMUM_FOR_FFT_____; //310
	mv_______->iir_c_60__gain[3][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[3][1] = MAXIMUM_FOR_FFT_____; //600
	mv_______->iir_c_60__gain[4][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[4][1] = MAXIMUM_FOR_FFT_____; //1000
	mv_______->iir_c_60__gain[5][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[5][1] = MAXIMUM_FOR_FFT_____; ///3000
	mv_______->iir_c_60__gain[6][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[6][1] = MAXIMUM_FOR_FFT_____; //6000
	mv_______->iir_c_60__gain[7][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[7][1] = MAXIMUM_FOR_FFT_____; //12000
	mv_______->iir_c_60__gain[8][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[8][1] = MAXIMUM_FOR_FFT_____; //14000
	mv_______->iir_c_60__gain[9][0] = MAXIMUM_FOR_FFT_____;
	mv_______->iir_c_60__gain[9][1] = MAXIMUM_FOR_FFT_____; //16000

	mv_______->iir_c_60__eqcfg.band_num = 10;
	mv_______->iir_c_60__eqcfg.use_xmms_original_freqs = 1;
	mv_______->iir_c_60__eqcfg.extra_filtering = 0;

	mv_______->iir_c_60__iir_cf = (void*)iir_cforiginal10;
	mv_______->iir_c_60__iir_cf_fixed = (void*)iir_cforiginal10_fixed;

	if (channels == 1)
	{
		deslocador = 1;
	}
	else
	{
		deslocador = 2;
	}

	halflength = (length >> 1);

	for (index = 0; index < halflength; index += deslocador)
	{

		for (channel = 0; channel < channels; channel++)
		{

			pcm[channel] = data[index + channel];

			for (band = 0; band < mv_______->iir_c_60__eqcfg.band_num; band++)
			{

				/*
				 * Store Xi(n)
				 */

				mv_______->iir_c_60__data_history[band][channel].x[mv_______->iir_c_60__i] = pcm[channel];

				/*
				 * Calculate and store Yi(n)
				 */
				mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] = (
				        /*
				         * = alpha *
				         * [x(n)-x(n-2)]
				         */
				        mv_______->iir_c_60__iir_cf
				        [band].
				        alpha
				        *
				        (mv_______->iir_c_60__data_history
				         [band]
				         [channel].
				         x
				         [mv_______->iir_c_60__i]
				         -
				         mv_______->iir_c_60__data_history
				         [band][channel].x[mv_______->iir_c_60__k])
				        /*
				         * + gamma * y(n-1)
				         */
				        +
				        mv_______->iir_c_60__iir_cf
				        [band].
				        gamma
				        *
				        mv_______->iir_c_60__data_history
				        [band][channel].y[mv_______->iir_c_60__j]
				        /*
				         * - beta * y(n-2)
				         */
				        -
				        mv_______->iir_c_60__iir_cf
				        [band].
				        beta
				        *
				        mv_______->iir_c_60__data_history
				        [band][channel].y[mv_______->iir_c_60__k]);
				int rval;
				switch(band)
				{
				case 0:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_60=BucaneiroMax(rval,mv_______->iir_c___value_60);
					break;
				case 1:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_170=BucaneiroMax(rval,mv_______->iir_c___value_170);
					break;
				case 2:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_310=BucaneiroMax(rval,mv_______->iir_c___value_310);
					break;
				case 3:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_600=BucaneiroMax(rval,mv_______->iir_c___value_600);
					break;
				case 4:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_1000=BucaneiroMax(rval,mv_______->iir_c___value_1000);
					break;
				case 5:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_3000=BucaneiroMax(rval,mv_______->iir_c___value_3000);
					break;
				case 6:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_6000=BucaneiroMax(rval,mv_______->iir_c___value_6000);
					break;
				case 7:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_12000=BucaneiroMax(rval,mv_______->iir_c___value_12000);
					break;
				case 8:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_14000=BucaneiroMax(rval,mv_______->iir_c___value_14000);
					break;
				case 9:
					rval=mv_______->iir_c_60__data_history[band][channel].y[mv_______->iir_c_60__i] * mv_______->iir_c_60__gain[band][channel]; // *
					mv_______->iir_c___value_16000=BucaneiroMax(rval,mv_______->iir_c___value_16000);
					break;
				}
			}
		}

		mv_______->iir_c_60__i++;
		mv_______->iir_c_60__j++;
		mv_______->iir_c_60__k++;

		if (mv_______->iir_c_60__i == 3)
			mv_______->iir_c_60__i = 0;
		else if (mv_______->iir_c_60__j == 3)
			mv_______->iir_c_60__j = 0;
		else
			mv_______->iir_c_60__k = 0;

	}
	mv_______->iir_c___value_60=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_60);
	mv_______->iir_c___value_170=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_16000);
	mv_______->iir_c___value_310=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_310);
	mv_______->iir_c___value_600=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_600);
	mv_______->iir_c___value_1000=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_1000);
	mv_______->iir_c___value_3000=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_3000);
	mv_______->iir_c___value_6000=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_6000);
	mv_______->iir_c___value_12000=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_12000);
	mv_______->iir_c___value_14000=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_14000);
	mv_______->iir_c___value_16000=getporf(BE__FFT_ADJUST___,mv_______->iir_c___value_16000);

	return length;
}
