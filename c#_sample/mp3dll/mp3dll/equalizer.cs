
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
using System;
using System.Text;
using System.Windows.Forms;

namespace mp3dll
{
	public partial class equalizer : Form
	{

		/// <summary>
		/// main equalizer form
		/// </summary>
		public equalizer()
		{
			InitializeComponent();
		}

		long number = MP3.number;

		private void equalizer_Load(object sender, EventArgs e)
		{
			StringBuilder settings = new StringBuilder(1000);
			MP3.GetSettings("equalizer", settings, "0");

			if ("0" == settings.ToString())
			{
				MP3.EnableEqualizer(number, 0);
				equa.CheckState = CheckState.Unchecked;
			}
			else
			{
				MP3.EnableEqualizer(number, 1);
				equa.CheckState = CheckState.Checked;
			}

			MP3.GetSettings("s60", settings, "5");
			s60.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s170", settings, "5");
			s170.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s310", settings, "5");
			s310.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s600", settings, "5");
			s600.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s1000", settings, "5");
			s1000.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s3000", settings, "5");
			s3000.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s6000", settings, "5");
			s6000.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s12000", settings, "5");
			s12000.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s14000", settings, "5");
			s14000.Value = int.Parse(settings.ToString());
			MP3.GetSettings("s16000", settings, "5");
			s16000.Value = int.Parse(settings.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));

			MP3.GetSettings("pre", settings, "0");

			if ("0" == settings.ToString())
			{
				MP3.EnablePreamplifier(number, 0);
				pre.CheckState = CheckState.Unchecked;
			}
			else
			{
				MP3.EnablePreamplifier(number, 1);
				pre.CheckState = CheckState.Checked;
			}

			MP3.GetSettings("pre_val", settings, "5");

			_pre.Value = int.Parse (settings.ToString ());

			MP3.PreamplifierValue(number, _pre.Value * 10);

			MP3.GetSettings("double", settings, "0");

			if ("0" == settings.ToString())
			{
				MP3.DoubleBuffer (number, 0);
				double_.CheckState = CheckState.Unchecked;
			}
			else
			{
				MP3.DoubleBuffer(number, 1);
				double_.CheckState = CheckState.Checked;
			}

		}

		private void equa_MouseUp(object sender, MouseEventArgs e)
		{
			if (equa.CheckState == CheckState.Checked)
			{
				MP3.SaveSettings("equalizer", "1");
				MP3.EnableEqualizer(number, 1);
			}
			else
			{
				MP3.SaveSettings("equalizer", "0");
				MP3.EnableEqualizer(number, 0);
			}
		}

		private void equa_CheckedChanged(object sender, EventArgs e)
		{
		}

		private void _pre_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("pre_val", _pre.Value.ToString ());
			MP3.PreamplifierValue(number, _pre.Value * 10);
		}

		private void pre_MouseUp(object sender, MouseEventArgs e)
		{
			if (pre.CheckState == CheckState .Checked )
			{
				MP3.SaveSettings("pre", "1");
				MP3.EnablePreamplifier(number, 1);
			}
			else
			{
				MP3.SaveSettings("pre", "0");
				MP3.EnablePreamplifier(number, 0);
			}
		}

		private void double__MouseUp(object sender, MouseEventArgs e)
		{
			if (double_.CheckState == CheckState.Checked)
			{
				MP3.SaveSettings("double", "1");
				MP3.DoubleBuffer (number, 1);
			}
			else
			{
				MP3.SaveSettings("double", "0");
				MP3.DoubleBuffer(number, 0);
			}
		}

		private void s60_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s60", s60.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));

		}

		private void s170_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s170", s170.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}

		private void s310_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s310", s310.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}

		private void s600_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s600", s600.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}

		private void s1000_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s1000", s1000.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}

		private void s3000_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s3000", s3000.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}

		private void s6000_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s6000", s6000.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}

		private void s12000_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s12000", s12000.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}

		private void s14000_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s14000", s14000.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}

		private void s16000_Scroll(object sender, EventArgs e)
		{
			MP3.SaveSettings("s16000", s16000.Value.ToString());

			MP3.EqualizerSettings(number,
			                      (s60.Value * 10),
			                      (s170.Value * 10),
			                      (s310.Value * 10),
			                      (s600.Value * 10),
			                      (s1000.Value * 10),
			                      (s3000.Value * 10),
			                      (s6000.Value * 10),
			                      (s12000.Value * 10),
			                      (s14000.Value * 10),
			                      (s16000.Value * 10));
		}
		void EqualizerFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.p = null;
		}
	}
}
