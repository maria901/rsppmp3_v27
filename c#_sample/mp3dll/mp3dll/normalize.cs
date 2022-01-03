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

using System;
using System.Text;
using System.Windows.Forms;
namespace mp3dll
{
    /// <summary>
    /// main class
    /// </summary>
    public partial class normalize : Form
    {
        /// <summary>
        /// normalize class
        /// </summary>
        public normalize()
        {
            InitializeComponent();
        }
        long number = MP3.number;
        StringBuilder settings = new StringBuilder(300);
        private void normalize_Load(object sender, EventArgs e)
        {

            MP3.GetSettings("replaygain", settings, "0");
            if ("1"==settings .ToString ())
            {
                otffast.CheckState = CheckState.Checked;
                MP3.EnableOnTheFlyVolumeNormalization(number, 1);
            }
            else if ("2" == settings.ToString())
            {
                checkBox1.CheckState = CheckState.Checked;
                MP3.EnableOnTheFlyVolumeNormalization(number, 2);
            }
            else if ("3" == settings.ToString())
            {
                benormalize_ch.CheckState = CheckState.Checked;
                MP3.EnableOnTheFlyVolumeNormalization(number, 3);
            }
            else
            {
                MP3.EnableOnTheFlyVolumeNormalization(number, 0);
            }

        }

        private void otffast_MouseUp(object sender, MouseEventArgs e)
        {
            checkBox1.CheckState = CheckState.Unchecked;
            if (otffast.CheckState == CheckState.Checked)
            {
                MP3.SaveSettings("replaygain", "1");
                MP3.EnableOnTheFlyVolumeNormalization(number, 1);
            }
            else
            {
                MP3.SaveSettings("replaygain", "0");
                MP3.EnableOnTheFlyVolumeNormalization(number, 0);
            }
        }

        private void otf_MouseUp(object sender, MouseEventArgs e)
        {
           
        }
        private void otfwtf_MouseUp(object sender, MouseEventArgs e)
        {
           }

        private void oftw_MouseUp(object sender, MouseEventArgs e)
        {

        }

        private void no_MouseUp(object sender, MouseEventArgs e)
        {
        }

        private void checkBox1_MouseUp(object sender, MouseEventArgs e)
        {
            benormalize_ch.CheckState = CheckState.Unchecked;
            otffast.CheckState = CheckState.Unchecked;
            if (checkBox1.CheckState == CheckState.Checked)
            {
                MP3.SaveSettings("replaygain", "2");
                MP3.EnableOnTheFlyVolumeNormalization(number, 2);
            }
            else
            {
                MP3.SaveSettings("replaygain", "0");
                MP3.EnableOnTheFlyVolumeNormalization(number, 0);
            }
        }

        private void benormalize_ch_MouseUp(object sender, MouseEventArgs e)
        {
            checkBox1.CheckState = CheckState.Unchecked;
            otffast.CheckState = CheckState.Unchecked;
            if (benormalize_ch.CheckState == CheckState.Checked)
            {
                MP3.SaveSettings("replaygain", "3");
                MP3.EnableOnTheFlyVolumeNormalization(number, 3);
            }
            else
            {
                MP3.SaveSettings("replaygain", "0");
                MP3.EnableOnTheFlyVolumeNormalization(number, 0);
            }
        }
		void NormalizeFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.k2 = null;
		}
    }
}