
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
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace amanda_progress2
{
	/// <summary>
	/// Description of progressbar_27_51_z.
	/// </summary>
	public partial class progressbar_27_51_z_v2 : UserControl
	{
		public progressbar_27_51_z_v2()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		[Description("This event will return new mouse information")]
		public event NewMouseEvent Mouse_z;
		public delegate void NewMouseEvent(ExtendedMouseEvent e);
		
		protected void adsjut_init_z()
		{
			int pegou_z;
			double calc_z;
			
			if(7 < this.Width)
			{
				fixo_z.Width = this.Width - 6;
				fixo_z .Left = 3;
			}
			else
			{
			fixo_z.Width = this.Width;
			fixo_z .Left = 0;
			}
			
			
			//fixo_z.Width = this.Width;
			//fixo_z .Left = 0;
			/*
			fixo_z.Height = 12;
			
			fixo_z.Top = Convert.ToInt32(((double) this.Height - (double) fixo_z.Height) / 2.0);
			*/
			
			fixo_z.Height = this.Height - 3;
			
			fixo_z.Top = 2;
			
			fixo_z.Value_z = 0;
						
		}
		
		void Progressbar_27_51_zLoad(object sender, EventArgs e)
		{
			
			adsjut_init_z();
			
		}
		protected bool UseRoundedCorners_i_z;
		public bool UseRoundedCorners_z
		{
			get
			{
				return UseRoundedCorners_i_z;
			}
			set
			{
				if(value)
				{					
					UseRoundedCorners_i_z = true;	
					this.BackColor = Color.FromArgb(0xF0F0F0);
				}
				else
				{					
					this.BackColor = fixo_z.BackColor;
					UseRoundedCorners_i_z = false;
				}
			}
		}
		
		public Color BackColor_z
		{
			get
			{
				return this.BackColor;
			}
			set
			{
				this.BackColor = ((value));				
			}
		}
		
		public int Value__z
		{
			get
			{
				return fixo_z.Value_z;
			}
			set
			{
				fixo_z.Value_z = value;
			}
		}
		public int Maximum__z
		{
			get
			{
				return fixo_z.Maximum;
			}
			set
			{
				fixo_z.Maximum = value;
			}
		}
		void Progressbar_27_51_z_v2Resize(object sender, EventArgs e)
		{
			adsjut_init_z();
		}
		public class ExtendedMouseEvent
		{
			public int Value_z = 0;
		}
		protected double
			getporf(double maxa, double fatiaa)
		{
			if (0 == maxa || 0 == fatiaa)//avoid division by zero
			{
				return 0;
			}
			maxa = ((double)100 / maxa * fatiaa);
			return maxa;
		}
		double
			getvalf(double maxa, double porr)
		{
			maxa = (maxa / 100.0) * porr;
			return maxa;
		}
		void Fixo_zMouseDown(object sender, MouseEventArgs e)
		{
			ExtendedMouseEvent morcego_z = new ExtendedMouseEvent();
			double maximum  = fixo_z.Maximum_z * (double)this.Width;
			double position = fixo_z.Maximum_z * (double)e.X;
			double val = getporf(maximum, position);
			val = getvalf(fixo_z.Maximum_z, val);
			if (val > fixo_z.Maximum_z)
			{
				val = fixo_z.Maximum_z;
			}
			if (val < 0)
			{
				val = 0;
			}
			morcego_z.Value_z = (int)val;
			if (null != Mouse_z)
			{
				Mouse_z.Invoke(morcego_z);
			}
		}
		void Progressbar_27_51_z_v2MouseDown(object sender, MouseEventArgs e)
		{
			ExtendedMouseEvent morcego_z = new ExtendedMouseEvent();
			double maximum  = fixo_z.Maximum_z * (double)this.Width;
			double position = fixo_z.Maximum_z * (double)e.X;
			double val = getporf(maximum, position);
			val = getvalf(fixo_z.Maximum_z, val);
			if (val > fixo_z.Maximum_z)
			{
				val = fixo_z.Maximum_z;
			}
			if (val < 0)
			{
				val = 0;
			}
			morcego_z.Value_z = (int)val;
			if (null != Mouse_z)
			{
				Mouse_z.Invoke(morcego_z);
			}
		}
		
	}
}
