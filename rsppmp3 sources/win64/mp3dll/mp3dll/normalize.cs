   
/*
    <C# Sample Project for rsppmp3>    
    Copyright (C) <2020>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
	and GNU LESSER GENERAL PUBLIC LICENSE along with this program.  
	If not, see <http://www.gnu.org/licenses/>.
    
    support: http://nomade.sourceforge.net
    
	direct programmers e-mails:
	Ricardo: arsoftware25@gmail.com
	Amanda : arsoftware10@gmail.com
	
	immediate contact(for a very fast answer) WhatsApp
	(+55)41 9627 1708 - it is always on
*/

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