#define AMANDA_DEBUG__NO
﻿
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
#if AMANDA_DEBUG__
using mp3dll;
#endif
namespace RoundCorneredProgressBar
{
	public partial class RoundCorneredProgressBar : PictureBox
	{		
		double pbUnit;
		int pbWIDTH, pbHEIGHT, pbComplete;

		Bitmap bmp = null;
		Graphics g;

		public RoundCorneredProgressBar()
		{
			DoubleBuffered = true;
			ProgressBarColor = Color.FromArgb(224, 224, 224);
			ProgressBackColor = Color.FromArgb(255, 128, 255);
			ProgressFont = new Font(Font.FontFamily, (int)(this.Height * 0.7), FontStyle.Bold);
			ProgressFontColor = Color.Black;
			Value_z = 0;
		}

		private int Value_i = 0;
		
		internal double Maximum_z = 10000.0;
		
		protected int ret_arp_;
		
		public int Value_z
		{
			get
			{
				return Value_i;
			}
			set
			{
				Value_i = value;
				
				ret_arp_ = Convert.ToInt32(Maximum_z);
				
				if(Value_i > ret_arp_)
				{
					#if AMANDA_DEBUG__
					MP3.pedro_dprintf(0, "above e max " + Maximum_z + " e value " + value);
					#endif
					Value_i = ret_arp_;
				}
				if(Value_i < 0)
				{
					Value_i = 0;
				}
				
				Animate_z();
				
				pbComplete = Value_i;
				#if AMANDA_DEBUG__
				MP3.pedro_dprintf(0, "pbComplete " + pbComplete);
				#endif
				t_Tick(null, null);
			}
		}
		
		public int Maximum
		{
			get
			{
				return (int)Maximum_z;
			}
			set
			{
				Maximum_z = (double)value;
				
				if(1.0 > Maximum_z)
				{
					Maximum_z = 1.0;
				}
				Animate_z();
			}
		}

		[Category("Appearance")]
		public Color ProgressBarColor { get; set; }

		[Category("Appearance")]
		public Color ProgressBackColor { get; set; }

		[Category("Appearance")]
		public Font ProgressFont { get; set; }

		[Category("Appearance")]
		public Color ProgressFontColor { get; set; }


		private GraphicsPath GetRoundRectagle(Rectangle bounds)
		{
			GraphicsPath path = new GraphicsPath();
			int radius = bounds.Height;
			if (bounds.Height <= 0) radius = 20;
			path.AddArc(bounds.X, bounds.Y, radius, radius, 180, 90);
			path.AddArc(bounds.X + bounds.Width - radius, bounds.Y, radius, radius, 270, 90);
			path.AddArc(bounds.X + bounds.Width - radius, bounds.Y + bounds.Height - radius,
			            radius, radius, 0, 90);
			path.AddArc(bounds.X, bounds.Y + bounds.Height - radius, radius, radius, 90, 90);
			path.CloseAllFigures();
			return path;
		}
		private void RecreateRegion()
		{
			mp3dll.MP3.pedro_dprintf(0, "values ori " + this.ClientRectangle.Location + "  " + this.ClientRectangle.Size);
			var bounds = new Rectangle(this.ClientRectangle.Location, this.ClientRectangle.Size);
			bounds.Inflate(-1, -1);
			this.Region = new Region(GetRoundRectagle(bounds));
			mp3dll.MP3.pedro_dprintf(0, "RecreateRegion");
			this.Invalidate();
		}
		protected override void OnSizeChanged(EventArgs e)
		{
			base.OnSizeChanged(e);
			this.RecreateRegion();
		}

		/// <summary>
		/// start the animation of filling the progress bar
		/// </summary>
		private void Animate_z()
		{
			pbWIDTH = this.Width;
			pbHEIGHT = this.Height;

			pbUnit = pbWIDTH / Maximum_z;
			
			bmp = new Bitmap(pbWIDTH, pbHEIGHT);

		}

		private void t_Tick(object sender, EventArgs e)
		{
			
			//graphics
			g = Graphics.FromImage(bmp);
			g.TextRenderingHint = System.Drawing.Text.TextRenderingHint.AntiAlias;
			g.SmoothingMode = SmoothingMode.HighQuality;

			//clear graphics
			g.Clear(ProgressBackColor);

			GraphicsPath path = new GraphicsPath();
			Rectangle innerBounds = new Rectangle(0, 0, (int)((pbComplete) * (pbUnit)), pbHEIGHT);

			//progressbar region filling
			Region r = new Region(GetRoundRectagle(innerBounds));

			g.FillRegion(new SolidBrush(ProgressBarColor), r);

			//draw string
			//g.DrawString(pbComplete + "%", new Font(ProgressFont.FontFamily, (int)(pbHEIGHT * 0.6), ProgressFont.Style), new SolidBrush(ProgressFontColor), new PointF(pbWIDTH / 2 - pbHEIGHT, pbHEIGHT / 10));

			//load bitmap in picturebox picboxPB
			this.Image = bmp;
			
			g.Dispose();
			
		}

	}
}