
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


/*
 * Created by SharpDevelop.
 * User: AAKP
 * Date: 07/04/2021
 * Time: 20:35
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Drawing;
using System.Windows.Forms;
using RoundCorneredProgressBar;

namespace mp3dll
{
	/// <summary>
	/// Description of example_z.
	/// </summary>
	public partial class example_z : Form
	{
		public example_z()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		void Example_zLoad(object sender, EventArgs e)
		{
			
			
		}
		void Button1Click(object sender, EventArgs e)
		{
			//prog_z.Animate();
			prog_z.Maximum__z = 10000;
			progressbar_27_51_z_v21 .UseRoundedCorners_z = false;
		}
		int counter_z =0;
		void Button2Click(object sender, EventArgs e)
		{
			counter_z      += 500;
			prog_z.Value__z = counter_z;
			progressbar_27_51_z_v21 .UseRoundedCorners_z = true;
		}
		void Prog_zMouse_z(amanda_progress2.progressbar_27_51_z_v2.ExtendedMouseEvent e)
		{
			MP3.pedro_dprintf(0, "value de mouse_z " + e.Value_z);
		}
	}
}
