
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
 * Time: 20:03
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace mp3dll
{
	/// <summary>
	/// Description of Microsoft_smooth_progress_z.
	/// </summary>
	public partial class Microsoft_smooth_progress_z : UserControl
	{
		public Microsoft_smooth_progress_z()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		int min = 0;// Minimum value for progress range
		int max = 100;// Maximum value for progress range
		int val = 0;// Current progress
		Color BarColor = Color.Blue;// Color of progress meter

		protected override void OnResize(EventArgs e)
		{
			// Invalidate the control to get a repaint.
			this.Invalidate();
		}

		protected override void OnPaint(PaintEventArgs e)
		{
			Graphics g = e.Graphics;
			SolidBrush brush = new SolidBrush(BarColor);
			float percent = (float)(val - min) / (float)(max - min);
			Rectangle rect = this.ClientRectangle;

			// Calculate area for drawing the progress.
			rect.Width = (int)((float)rect.Width * percent);

			// Draw the progress meter.
			g.FillRectangle(brush, rect);

			// Draw a three-dimensional border around the control.
			Draw3DBorder(g);

			// Clean up.
			brush.Dispose();
			g.Dispose();
		}

		public int Minimum
		{
			get
			{
				return min;
			}

			set
			{
				// Prevent a negative value.
				if (value < 0)
				{
					min = 0;
				}

				// Make sure that the minimum value is never set higher than the maximum value.
				if (value > max)
				{
					min = value;
					min = value;
				}

				// Ensure value is still in range
				if (val < min)
				{
					val = min;
				}

				// Invalidate the control to get a repaint.
				this.Invalidate();
			}
		}

		public int Maximum
		{
			get
			{
				return max;
			}

			set
			{
				// Make sure that the maximum value is never set lower than the minimum value.
				if (value < min)
				{
					min = value;
				}

				max = value;

				// Make sure that value is still in range.
				if (val > max)
				{
					val = max;
				}

				// Invalidate the control to get a repaint.
				this.Invalidate();
			}
		}

		public int Value
		{
			get
			{
				return val;
			}

			set
			{
				int oldValue = val;

				// Make sure that the value does not stray outside the valid range.
				if (value < min)
				{
					val = min;
				}
				else if (value > max)
				{
					val = max;
				}
				else
				{
					val = value;
				}

				// Invalidate only the changed area.
				float percent;

				Rectangle newValueRect = this.ClientRectangle;
				Rectangle oldValueRect = this.ClientRectangle;

				// Use a new value to calculate the rectangle for progress.
				percent = (float)(val - min) / (float)(max - min);
				newValueRect.Width = (int)((float)newValueRect.Width * percent);

				// Use an old value to calculate the rectangle for progress.
				percent = (float)(oldValue - min) / (float)(max - min);
				oldValueRect.Width = (int)((float)oldValueRect.Width * percent);

				Rectangle updateRect = new Rectangle();

				// Find only the part of the screen that must be updated.
				if (newValueRect.Width > oldValueRect.Width)
				{
					updateRect.X = oldValueRect.Size.Width;
					updateRect.Width = newValueRect.Width - oldValueRect.Width;
				}
				else
				{
					updateRect.X = newValueRect.Size.Width;
					updateRect.Width = oldValueRect.Width - newValueRect.Width;
				}

				updateRect.Height = this.Height;

				// Invalidate the intersection region only.
				this.Invalidate(updateRect);
			}
		}

		public Color ProgressBarColor
		{
			get
			{
				return BarColor;
			}

			set
			{
				BarColor = value;

				// Invalidate the control to get a repaint.
				this.Invalidate();
			}
		}

		private void Draw3DBorder(Graphics g)
		{
			int PenWidth = (int)Pens.White.Width;

			g.DrawLine(Pens.DarkGray,
			           new Point(this.ClientRectangle.Left, this.ClientRectangle.Top),
			           new Point(this.ClientRectangle.Width - PenWidth, this.ClientRectangle.Top));
			g.DrawLine(Pens.DarkGray,
			           new Point(this.ClientRectangle.Left, this.ClientRectangle.Top),
			           new Point(this.ClientRectangle.Left, this.ClientRectangle.Height - PenWidth));
			g.DrawLine(Pens.White,
			           new Point(this.ClientRectangle.Left, this.ClientRectangle.Height - PenWidth),
			           new Point(this.ClientRectangle.Width - PenWidth, this.ClientRectangle.Height - PenWidth));
			g.DrawLine(Pens.White,
			           new Point(this.ClientRectangle.Width - PenWidth, this.ClientRectangle.Top),
			           new Point(this.ClientRectangle.Width - PenWidth, this.ClientRectangle.Height - PenWidth));
		}
	}
}
