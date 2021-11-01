
/********************************************************************************
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
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 ********************************************************************************

      E-mails:
      maria@arsoftware.net.br
      pedro@locacaodiaria.com.br

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *
 *                                                                              *
 *******************************************************************************/
 
using System;
using System.Text;
using System.Windows.Forms;

namespace mp3dll
{
    public partial class DebugInformation : Form
    {
        long number = MP3.number;  

        public DebugInformation()
        {
            InitializeComponent();
        }
        private void DebugInformation_Load(object sender, EventArgs e)
        {
        }
        StringBuilder alladin_data = new StringBuilder(300);
        private void get_debug_info_Tick(object sender, EventArgs e)
        {
            devolta:
            int ret;
           ret= MP3.DebugInformation(number, alladin_data);
           if (0 == ret)
           {
               list.Items.Add(alladin_data.ToString());
               list.SelectedIndex = list.Items.Count - 1;
               goto devolta;
           }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            list.Items.Clear();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
		void DebugInformationFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.p2 = null;
		}
    }
}