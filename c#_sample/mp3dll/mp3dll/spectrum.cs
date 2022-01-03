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
using System.Windows.Forms;

namespace mp3dll
{
    public partial class spectrum : Form
    {
        public spectrum()
        {
            InitializeComponent();
        }

        long number = MP3.number;

        private void checkBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (enable.CheckState == CheckState.Checked)
            {
                
                timer.Enabled = true;
            }
            else
            {
                timer.Enabled = false;
                
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            int ff60=0;
            int ff170=0;
            int ff310=0;
            int ff600=0;
            int ff1000=0;
            int ff3000=0;
            int ff6000=0;
            int ff12000=0;
            int ff14000=0;
            int ff16000=0;
            int fpeak=0;
            MP3.GetSpectrumAnalyzer(number,
                ref ff60,
                ref ff170,
                ref ff310,
                ref ff600,
                ref ff1000,
                ref ff3000,
                ref ff6000,
                ref ff12000,
                ref ff14000,
                ref ff16000,
                ref fpeak);

            progressbar1.Value = ff60;
            progressbar11.Value = ff170;
            progressbar10.Value = ff310;
            progressbar9.Value = ff600;
            progressbar3.Value = ff1000;
            progressbar4.Value = ff3000;
            progressbar8.Value = ff6000;
            progressbar7.Value = ff12000;
            progressbar6.Value = ff14000;
            progressbar2.Value = ff16000;
            progressbar5.Value = fpeak;
             


        }

        private void spectrum_Load(object sender, EventArgs e)
        {
            /*
             *         Form10.ProgressBar1.Value = f60
'        Form10.ProgressBar2.Value = f170
'        Form10.ProgressBar3.Value = f310
'        Form10.ProgressBar4.Value = f600
'        Form10.ProgressBar5.Value = f1000
'        Form10.ProgressBar6.Value = f3000
'        Form10.ProgressBar7.Value = f6000
'        Form10.ProgressBar8.Value = f12000
'        Form10.ProgressBar9.Value = f14000
'        Form10.ProgressBar10.Value = f16000
'        Form10.ProgressBar11.Value = peak
             * */

        }
		void SpectrumFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.k = null;
		}
    }
}
