

/****************************************************************************   
 *                                                                          *
 *                Copyright (C) <202*>  <BinaryWork Corp.>                  *
 *                                                                          *
 *   This program is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by   *
 *   the  Free  Software  Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   This  program  is  distributed  in the hope that it will be useful,    *
 *   but  WITHOUT  ANY WARRANTY;  without  even  the  implied warranty of   *
 *   MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.   See the   *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   You should have received a copy of the GNU GENERAL PUBLIC LICENSE      *
 *       and GNU LESSER GENERAL PUBLIC LICENSE along with this program.     *
 *       If not, see <http://www.gnu.org/licenses/>.                        *
 *                                                                          *
 *   support: https://arsoftware.net.br/binarywork _____________            *
 *                                                                          *
 *       direct programmers e-mails:                                        *
 *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br         *
 *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br          *
 *                                                                          *
 *       immediate contact(for a very fast answer) WhatsApp                 *
 *       (+55)41 9627 1708 - it is always on                                *
 *                                                                          *
 ***************************************************************************/

using System;
using System.ComponentModel;
using System.Windows.Forms;

namespace amanda_progress
{
	public partial class progressbar : UserControl
	{
		public int Maximum
		{
			get
			{
				return (int)max;
			}
			set
			{
				max = (double)value;
			}
		}
		[Description("This event will return new mouse information")]
		public event NewMouseEvent Mouse;
		public delegate void NewMouseEvent(ExtendedMouseEvent e);
		double
			getvalf(double maxa, double porr)
		{
			maxa = (maxa / 100.0) * porr;
			return maxa;
		}
		double
			getporf(double maxa, double fatiaa)
		{
			if (0 == maxa || 0 == fatiaa)//avoid division by zero
			{
				return 0;
			}
			maxa = ((double)100 / maxa * fatiaa);
			return maxa;
		}
		private double max = 10000.0;
		private double value_b = 0.0;
		protected int new_height_z = -1;
		protected int ret_arp_;
		public progressbar()
		{
			
			InitializeComponent();

		}
		public progressbar(int init_height_z)
		{
			new_height_z = init_height_z;
			InitializeComponent();

		}
		public void set_slider_height(int value_z)
		{
			
		}
		private void progressbar_Load(object sender, EventArgs e)
		{
			
			ret_arp_ = (this.Height - 5)      / 2;						
			
			deslizante.Left         =           0;
			deslizante.Width        =           0;
			deslizante.Height       =           1;
			deslizante.Top          =           3;
			deslizante.Visible      =       false;
			
			deslizante_0_z.Left     =           0;
			deslizante_0_z.Width    =           0;
			deslizante_0_z.Height   =           1;
			deslizante_0_z.Top      =  ret_arp_++;
			
			deslizante_1_z.Left     =           0;
			deslizante_1_z.Width    =           0;
			deslizante_1_z.Height   =           1;
			deslizante_1_z.Top      =  ret_arp_++;
			
			deslizante_2_z.Left     =           0;
			deslizante_2_z.Width    =           0;
			deslizante_2_z.Height   =           1;
			deslizante_2_z.Top      =  ret_arp_++;
			
			deslizante_3_z.Left     =           0;
			deslizante_3_z.Width    =           0;
			deslizante_3_z.Height   =           1;
			deslizante_3_z.Top      =  ret_arp_++;

			deslizante_4_z.Left     =           0;
			deslizante_4_z.Width    =           0;
			deslizante_4_z.Height   =           1;
			deslizante_4_z.Top      =  ret_arp_++;
			
			fixo.Left = 0;
			fixo.Top = 0;
			fixo.Width = this.Width;
			fixo.Height = this.Height;			
			
		}
		private void progressbar_Resize(object sender, EventArgs e)
		{
			progressbar_Load(null, null);
		}

		private void deslizante_MouseDown(object sender, MouseEventArgs e)
		{
			ExtendedMouseEvent morcego = new ExtendedMouseEvent();
			double maximum = max * (double)this.Width;
			double position = max * (double)e.X;
			double val = getporf(maximum, position);
			val = getvalf(max, val);
			if (val > max)
			{
				val = max;
			}
			if (val < 0)
			{
				val = 0;
			}
			morcego.Value = (int)val;
			if (null != Mouse)
			{
				Mouse.Invoke(morcego);
			}
		}

		private void fixo_MouseDown(object sender, MouseEventArgs e)
		{
			ExtendedMouseEvent morcego = new ExtendedMouseEvent();
			double maximum = max * (double)this.Width;
			double position = max * (double)e.X;
			double val = getporf(maximum, position);
			val = getvalf(max, val);
			if (val > max)
			{
				val = max;
			}
			if (val < 0)
			{
				val = 0;
			}
			morcego.Value = (int)val;
			if (null != Mouse)
			{
				Mouse.Invoke(morcego);
			}
		}

		private void progressbar_MouseDown(object sender, MouseEventArgs e)
		{
			ExtendedMouseEvent morcego = new ExtendedMouseEvent();
			double maximum = max * (double)this.Width;
			double position = max * (double)e.X;
			double val = getporf(maximum, position);
			val = getvalf(max, val);
			if (val > max)
			{
				val = max;
			}
			if (val < 0)
			{
				val = 0;
			}
			morcego.Value = (int)val;
			if (null != Mouse)
			{
				Mouse.Invoke(morcego);
			}
		}

		private void deslizante_Click(object sender, EventArgs e)
		{

		}
		/// <summary>
		/// It  will set or get the progressbar value
		/// </summary>
		[Description("It will set the value on the progressbar")]
		public int Value
		{
			get
			{
				return (int)value_b;
			}
			set
			{
				double temp;
				value_b = value;
				if (value_b > max)
				{
					value_b = (max);
				}
				if (value_b < 0)
				{
					value_b = 0;
				}
				temp = getporf(max, value_b);
				temp = getvalf(this.Width, temp);
				
				//aqui depois altera
				deslizante_2_z.Width = (int)temp;
				
				ret_arp_ = (int) temp - 3;
				
				if(ret_arp_ > 0)
				{
					deslizante_0_z.Width = ret_arp_;
				}
				else
				{
					deslizante_0_z.Width = 0;
				}
				
				ret_arp_ = (int) temp - 1;
				
				if(ret_arp_ > 0)
				{
					deslizante_1_z.Width = ret_arp_;
				}
				else
				{
					deslizante_1_z.Width = 0;
				}
								
				ret_arp_ = (int) temp - 1;
				
				if(ret_arp_ > 0)
				{
					deslizante_3_z.Width = ret_arp_;
				}
				else
				{
					deslizante_3_z.Width = 0;
				}
								
				ret_arp_ = (int) temp - 3;
				
				if(ret_arp_ > 0)
				{
					deslizante_4_z.Width = ret_arp_;
				}
				else
				{
					deslizante_4_z.Width = 0;
				}								
			}
		}
		public class ExtendedMouseEvent
		{
			public int Value=0;
		}

		private void deslizante_MouseEnter(object sender, EventArgs e)
		{
			progressbar_MouseEnter(null, null);
		}

		private void fixo_MouseEnter(object sender, EventArgs e)
		{
			progressbar_MouseEnter(null, null);
		}

		private void progressbar_MouseEnter(object sender, EventArgs e)
		{			
			//MP3.disabled = true;, remove it someday
		}

		private void fixo_MouseLeave(object sender, EventArgs e)
		{			
			//MP3.disabled = false;
		}
		void Deslizante_1_zMouseDown(object sender, MouseEventArgs e)
		{
			Deslizante_0_zMouseDown(sender, e);
		}
		void Deslizante_0_zMouseDown(object sender, MouseEventArgs e)
		{
			ExtendedMouseEvent morcego = new ExtendedMouseEvent();
			double maximum = max * (double)this.Width;
			double position = max * (double)e.X;
			double val = getporf(maximum, position);
			val = getvalf(max, val);
			if (val > max)
			{
				val = max;
			}
			if (val < 0)
			{
				val = 0;
			}
			morcego.Value = (int)val;
			if (null != Mouse)
			{
				Mouse.Invoke(morcego);
			}
		}
	}
}
