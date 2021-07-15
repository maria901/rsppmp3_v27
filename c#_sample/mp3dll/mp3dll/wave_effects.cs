   
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
	/// 
	/// </summary>
    public partial class wave_effects : Form
    {
        long number = MP3.number;
        public wave_effects()
        {
            InitializeComponent();
        }
        private void soundtouch_MouseUp(object sender, MouseEventArgs e)
        {
            if (soundtouch.CheckState == CheckState.Checked)
            {
            	MP3.dprintf ("tempo " + tempo.Value + " pitch "+pitch.Value+ " rate "+rate.Value);
                MP3.EnableSoundTouch(number, 1, tempo.Value, pitch.Value, rate.Value);
            }
            else
            {
            	MP3.dprintf ("tempo " + tempo.Value + " pitch "+pitch.Value+ " rate "+rate.Value);
                MP3.EnableSoundTouch(number, 0, tempo.Value, pitch.Value, rate.Value);
            }
        }
        private void tempo_Scroll(object sender, EventArgs e)
        {
            if (soundtouch.CheckState == CheckState.Checked)
            {
                MP3.EnableSoundTouch(number, 1, tempo.Value, pitch.Value, rate.Value);
            }
            else
            {
                MP3.EnableSoundTouch(number, 0, tempo.Value, pitch.Value, rate.Value);
            }
        }
        private void pitch_Scroll(object sender, EventArgs e)
        {
            if (soundtouch.CheckState == CheckState.Checked)
            {
                MP3.EnableSoundTouch(number, 1, tempo.Value, pitch.Value, rate.Value);
            }
            else
            {
                MP3.EnableSoundTouch(number, 0, tempo.Value, pitch.Value, rate.Value);
            }
        }
        private void rate_Scroll(object sender, EventArgs e)
        {
            if (soundtouch.CheckState == CheckState.Checked)
            {
                MP3.EnableSoundTouch(number, 1, tempo.Value, pitch.Value, rate.Value);
            }
            else
            {
                MP3.EnableSoundTouch(number, 0, tempo.Value, pitch.Value, rate.Value);
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            tempo.Value = 0;
            tempo_Scroll(null, null);
            pitch.Value = 0;
            pitch_Scroll(null, null);
            rate.Value = 0;
            rate_Scroll(null, null);
        }

        private void voice_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckState.Checked == voice.CheckState)
            {
                MP3.EnableVoiceRemoval(number, 1);
            }
            else
            {
                MP3.EnableVoiceRemoval(number, 0);
            }
        }

        private void echo_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckState.Checked == echo.CheckState)
            {
                MP3.EnableEcho(number, 1, 50);//range from 0 to 100,read the docs
            }
            else
            {
                MP3.EnableEcho(number, 0, 50);
            }
        }

        private void surround_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckState.Checked == surround.CheckState)
            {
                MP3.EnableSurround(number, 1);
            }
            else
            {
                MP3.EnableSurround(number, 0);
            }
        }

        private void surround2_MouseUp(object sender, MouseEventArgs e)
        {
            MP3.SaveSettings("be_effect", "0");
            if (surround2.CheckState == CheckState.Checked)
            {
                MP3.BE_Special_Wav_Effect(number, 1, svalue.Value);
                MP3.SaveSettings("be_effect", "1");
            }
            else
            {                
            	MP3.dprintf ("value "+svalue.Value);
                MP3.BE_Special_Wav_Effect(number, 0, svalue.Value);
            }
            MP3.SaveSettings("be_effect_val", svalue.Value.ToString());//default value is 32
        }
        private void svalue_Scroll(object sender, EventArgs e)
        {

            //MP3.SaveSettings("be_effect", "0");

            if (surround2.CheckState == CheckState.Checked)
            {
                MP3.BE_Special_Wav_Effect(number, 1, svalue.Value);
                //MP3.SaveSettings("be_effect", "0");
            }
            else
            {
                MP3.BE_Special_Wav_Effect(number, 0, svalue.Value);
            }
            MP3.SaveSettings("be_effect_val", svalue.Value.ToString());
        }
        private void freeverb_MouseUp(object sender, MouseEventArgs e)
        {
            if (CheckState.Checked == freeverb.CheckState)
            {
                MP3.EnableFreeverb(number, 1);
            }
            else
            {
                MP3.EnableFreeverb(number, 0);
            }
        }
        StringBuilder settings = new StringBuilder(300*6);
        private void wave_effects_Load(object sender, EventArgs e)
        {
            MP3.GetSettings("be_effect", settings, "0");
            surround2.CheckState = CheckState.Checked;
            if ("1" == settings.ToString())
            {                
                MP3.GetSettings("be_effect_val", settings, "0");
                MP3.BE_Special_Wav_Effect(number, 1, int.Parse(settings.ToString()));
                svalue.Value = int.Parse(settings.ToString());
            }
            else
            {
                surround2.CheckState = CheckState.Unchecked;
                MP3.GetSettings("be_effect_val", settings, "0");
                MP3.BE_Special_Wav_Effect(number, 0, int.Parse(settings.ToString()));
                svalue.Value = int.Parse(settings.ToString());
            }
        }
		void Wave_effectsFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.k3 = null;
		}
    }
}
