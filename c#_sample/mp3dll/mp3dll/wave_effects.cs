
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://arsoftware.net.br/binarywork_____________________       *

 *              http: //nomade.sourceforge.net/binarywork_______________/       *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

using System;
using System.Text;
using System.Windows.Forms;
namespace mp3dll
{
	/// <summary>
	/// 
	/// </summary>
    public partial class wave_effects : Form
    {
        long number = MP3.number;
        public wave_effects()
        {
            InitializeComponent();
        }
        private void soundtouch_MouseUp(object sender, MouseEventArgs e)
        {
            if (soundtouch.CheckState == CheckState.Checked)
            {
            	MP3.dprintf ("tempo " + tempo.Value + " pitch "+pitch.Value+ " rate "+rate.Value);
                MP3.EnableSoundTouch(number, 1, tempo.Value, pitch.Value, rate.Value);
            }
            else
            {
            	MP3.dprintf ("tempo " + tempo.Value + " pitch "+pitch.Value+ " rate "+rate.Value);
                MP3.EnableSoundTouch(number, 0, tempo.Value, pitch.Value, rate.Value);
            }
        }
        private void tempo_Scroll(object sender, EventArgs e)
        {
            if (soundtouch.CheckState == CheckState.Checked)
            {
                MP3.EnableSoundTouch(number, 1, tempo.Value, pitch.Value, rate.Value);
            }
            else
            {
                MP3.EnableSoundTouch(number, 0, tempo.Value, pitch.Value, rate.Value);
            }
        }
        private void pitch_Scroll(object sender, EventArgs e)
        {
            if (soundtouch.CheckState == CheckState.Checked)
            {
                MP3.EnableSoundTouch(number, 1, tempo.Value, pitch.Value, rate.Value);
            }
            else
            {
                MP3.EnableSoundTouch(number, 0, tempo.Value, pitch.Value, rate.Value);
            }
        }
        private void rate_Scroll(object sender, EventArgs e)
        {
            if (soundtouch.CheckState == CheckState.Checked)
            {
                MP3.EnableSoundTouch(number, 1, tempo.Value, pitch.Value, rate.Value);
            }
            else
            {
                MP3.EnableSoundTouch(number, 0, tempo.Value, pitch.Value, rate.Value);
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            tempo.Value = 0;
            tempo_Scroll(null, null);
            pitch.Value = 0;
            pitch_Scroll(null, null);
            rate.Value = 0;
            rate_Scroll(null, null);
        }

        private void voice_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckState.Checked == voice.CheckState)
            {
                MP3.EnableVoiceRemoval(number, 1);
            }
            else
            {
                MP3.EnableVoiceRemoval(number, 0);
            }
        }

        private void echo_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckState.Checked == echo.CheckState)
            {
                MP3.EnableEcho(number, 1, 50);//range from 0 to 100,read the docs
            }
            else
            {
                MP3.EnableEcho(number, 0, 50);
            }
        }

        private void surround_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckState.Checked == surround.CheckState)
            {
                MP3.EnableSurround(number, 1);
            }
            else
            {
                MP3.EnableSurround(number, 0);
            }
        }

        private void surround2_MouseUp(object sender, MouseEventArgs e)
        {
            MP3.SaveSettings("be_effect", "0");
            if (surround2.CheckState == CheckState.Checked)
            {
                MP3.BE_Special_Wav_Effect(number, 1, svalue.Value);
                MP3.SaveSettings("be_effect", "1");
            }
            else
            {                
            	MP3.dprintf ("value "+svalue.Value);
                MP3.BE_Special_Wav_Effect(number, 0, svalue.Value);
            }
            MP3.SaveSettings("be_effect_val", svalue.Value.ToString());//default value is 32
        }
        private void svalue_Scroll(object sender, EventArgs e)
        {

            //MP3.SaveSettings("be_effect", "0");

            if (surround2.CheckState == CheckState.Checked)
            {
                MP3.BE_Special_Wav_Effect(number, 1, svalue.Value);
                //MP3.SaveSettings("be_effect", "0");
            }
            else
            {
                MP3.BE_Special_Wav_Effect(number, 0, svalue.Value);
            }
            MP3.SaveSettings("be_effect_val", svalue.Value.ToString());
        }
        private void freeverb_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckState.Checked == freeverb.CheckState)
            {
                MP3.EnableFreeverb(number, 1);
            }
            else
            {
                MP3.EnableFreeverb(number, 0);
            }
        }
        StringBuilder settings = new StringBuilder(300*6);
        private void wave_effects_Load(object sender, EventArgs e)
        {
            MP3.GetSettings("be_effect", settings, "1");
            surround2.CheckState = CheckState.Checked;
            if ("1" == settings.ToString())
            {                
                MP3.GetSettings("be_effect_val", settings, "32");
                MP3.BE_Special_Wav_Effect(number, 1, int.Parse(settings.ToString()));
                svalue.Value = int.Parse(settings.ToString());
            }
            else
            {
                surround2.CheckState = CheckState.Unchecked;
                MP3.GetSettings("be_effect_val", settings, "32");
                MP3.BE_Special_Wav_Effect(number, 0, int.Parse(settings.ToString()));
                svalue.Value = int.Parse(settings.ToString());
            }
        }
		void Wave_effectsFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.k3 = null;
		}
    }
}
