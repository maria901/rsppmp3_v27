
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

/*

this sample application requires windows 7 or above
sharpdevelop 5 or visual studio 17

it will disable standby/hibernation and will avoid the monitor to turning off during playback

 */

using System;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Diagnostics;

namespace mp3dll
{
	/// <summary>
	/// Form1
	/// </summary>
	public partial class sample : Form
	{
		protected const int bar_pos_top_p = 590;
		long   item_got_z    =    0;
		long   item_number_z =    0;
		string old_stringz   = "-1";
		bool disable_pause_resume = false;
		int old_value_v27_z = 0;
		PictureBox temp_z_pic = new PictureBox();
		protected bool  mode_is_ricardo_window = false;
		
		protected int ori_width  = 0;
		protected int ori_height = 0;
		internal  int new_width  = -1;
		
		protected bool can_scape_z = true;
		protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
		{

			if ("Return" == keyData.ToString())
			{
				if (MP3.is_playlist)
				{
					int loop_ = 0;
					if (CheckState.Checked == loop.CheckState)
					{
						loop_ = 1;
					}
					
					main_timer.Enabled = false;
					
					MP3.SlowComputersCommand_k_p
						(
							number,
							0
						);
					if(true == enable_sc_hack.Checked)
					{
						MP3.SlowComputersCommand_k_p
							(
								number,
								1
							);
					}
					video_p.Image = dummy2_p.Image;
					video_f_p.Image = dummy2_p.Image;
					can_scape_z = true;
					MP3.clean_up_memory_p();
					MP3.Play(number, MP3.wide2utf8(MP3.the_filename), loop_, int.Parse(track.Text),
					         video_p.Handle.ToInt64(),
					         video_f_p.Handle.ToInt64(),
					         video_p.Width,
					         video_p.Height,
					         the_ratio,
					         video_p.Left,
					         video_p.Top);
					playlist.Visible = false;
					main_timer.Enabled = true;
				}
				return true;
			}
			if ("F8" == keyData.ToString())
			{
				int val;

				MP3.GetSettings("volume_v11", message, "100");

				val = int.Parse(message.ToString());

				val -= 5;
				if (val < 0)
				{
					val = 0;
				}
				internal_volume.Value = val;
				MP3.InternalVolume(number, val);
				MP3.SaveSettings("volume_v11", val.ToString());

			}
			if ("F9" == keyData.ToString())
			{
				int val;

				MP3.GetSettings("volume_v11", message, "100");

				val = int.Parse(message.ToString());

				val += 5;
				if (val > 200)
				{
					val = 200;
				}
				internal_volume.Value = val;
				MP3.InternalVolume(number, val);
				MP3.SaveSettings("volume_v11", val.ToString());

			}
			if ("Escape" == keyData.ToString())
			{
				if(mode_is_ricardo_window)
				{
					
					this.Width = ori_width;
					this.Height = ori_height;
					this.Top = 0;
					this.Left = 0;
					mode_is_ricardo_window = false;
					
				}
				this.TopMost = false;
				if(!can_scape_z)
				{
					
					goto next_point_z;
					
				}
				
				can_scape_z = false;
				fullscreen_state_ = 0;
				video_p_MouseClick(null, null);
				
				fs.Enabled = false;
				esconde_t.Enabled = false;

				bool flag = false;
				play_v13
					.Visible = flag;
				pause_v13
					.Visible = flag;
				resume_v13 .Visible = flag;
				cancel_v13
					.Visible = flag;

				MP3.is_full_screen = false;
				this.Text = copia;
				
				bugfix_fullscreen_z.BackColor = System.Drawing.Color.Black;

				bugfix_fullscreen_z.Left       =           20;
				bugfix_fullscreen_z.Top        =           92;
				bugfix_fullscreen_z.Width      =          667;
				bugfix_fullscreen_z.Height     =          336;
				bugfix_fullscreen_z.BringToFront           ();
				video_p.Left                   =         9000;
				video_p.Top                    =           92;
				video_p.Width                  =          667;
				video_p.Height                 =          336;
				
				video_f_p.Left                 =           20;
				video_f_p.Top                  =           92;
				video_f_p.Width                =          667;
				video_f_p.Height               =          336;
				video_p.Visible                =         true;
				video_f_p.Visible              =        false;
				
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				video_p.Left          =     20;
				video_p.Top           =     92;
				
				
				video_f_p.Left        =     20;
				video_f_p.Top         =     92;
				
				video_p.Visible       =   true;
				video_f_p.Visible     =  false;
				
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;
				
				video_p.Visible           =       true;
				video_f_p.Visible         =      false;
				
				next_point_z:
					;
				this.Height = 706;
			}
			if ("F11" == keyData.ToString())
			{
				width_plu_plus_Click(null, null);
			}
			if ("F12" == keyData.ToString())
			{
				width_minus_minus_Click(null, null);
			}
			if ("ShiftKey, Shift, Alt" == keyData.ToString())
			{
				if (0 == fullscreen_state_)
				{
					fullscreen_state_ = 1;
					default_w_Click(null, null);
				}
				else
				{
					fullscreen_state_ = 0;
					video_p_MouseClick(null, null);
				}
				return true;
			}
			if ("S, Control" == keyData.ToString())
			{

				button8_Click(null, null);
				return true;

			}
			if ("Return, Alt" == keyData.ToString())
			{

				if (0 == fullscreen_state_)
				{
					fullscreen_state_ = 1;
					button25_Click(null, null);
				}
				else
				{
					fullscreen_state_ = 0;
					video_p_MouseClick(null, null);
				}

				return true;
			}

			if ("P, Control" == keyData.ToString())
			{

				if (0 == pause_state_)
				{
					pause_state_ = 1;
					MP3.PlaybackPause(number);
				}
				else
				{
					pause_state_ = 0;
					MP3.PlaybackResume(number);
					
				}

				return true;
			}
			
			if(false == disable_pause_resume)
			{
				if ("F6" == keyData.ToString())
				{
					button7_Click(null, null);
					return true;
				}
				if ("F7" == keyData.ToString())
				{
					button5_Click(null, null);
					return true;
				}
			}
			
			switch (keyData)
			{

				case Keys.Space:

					if (0 == pause_state_)
					{
						pause_state_ = 1;
						MP3.PlaybackPause(number);
					}
					else
					{
						pause_state_ = 0;
						MP3.PlaybackResume(number);
						
					}

					break;//return true; it will avoid the absence of space in the textboxes, fixed
			}
			return base.ProcessCmdKey(ref msg, keyData);
		}
		internal string the_file_to_play;
		private ListViewColumnSorter lvwColumnSorter;
		/// <summary>
		/// amanda constructor
		/// </summary>
		public sample
			(
				string the_file_to_play_
			)
		{
			the_file_to_play = the_file_to_play_;
			InitializeComponent();
			lvwColumnSorter = new ListViewColumnSorter();
			this.playlist.ListViewItemSorter = lvwColumnSorter;
			this.WindowState = FormWindowState/* by ricardo */.Maximized;
		}

		mp3dll.avoid_standby disable_standby = new  mp3dll.avoid_standby();
		StringBuilder sample_format_k_p = new StringBuilder(300);
		StringBuilder memory_usage_z = new StringBuilder(300);
		private void timer1_Tick(object sender, EventArgs e)
		{
			string new_string;
			/**
			 * media file not loaded yet
			 */
			
			//MP3.pedro_dprintf(0, "enter 1");
			MP3.memory_usage__z(memory_usage_z);
			label20.Text = "Memory Usage: " + memory_usage_z.ToString();
			
			if (-1 == MP3.SampleRate(number))//
			{
				label16.Text = "Media type: Detecting media...";
				label5.Text = "Sample rate";
				label8.Text = "Channels";
				label7.Text = "Bitrate";
				label6.Text = "Mode";
				label9.Text = "Normalization";
				label1.Text = "Position";
				label15.Text = "Milliseconds";
				label1.Text = "Position";
				label17.Text = "Normalize factor";
				label14.Text = "Time position";
				label12.Text = "Time";
				label24.Text = "Remaining time";
				bits_per_sample.Text = "Bits per sample";

				info.Text = "Video info";
				pixel_l.Text = "Pixel Format";
				return;
			}
			
			if(mode_is_ricardo_window && this.WindowState == FormWindowState.Maximized)
			{
				this.WindowState = FormWindowState.Normal;
				video_p_MouseClick(null, null);
			}
			
			if(0==already&&1==MP3.GetSyncStatus(number))
			{
				morcego_error.Items.Add("Audio and video sync lost" );
				morcego_error.SelectedIndex = morcego_error.Items.Count - 1;
				already=1;
			}
			
			if (MP3.is_playlist)
			{
				new_string = playlist.Items[MP3.playlist_index].SubItems[0].Text;
				
				if (MP3.is_shuffle)
				{
					new_string = playlist.Items[MP3.playlist_index].SubItems[0].Text +
						" " +
						" (item " + item_number_z + " of " + playlist.Items.Count + ")";
					
				}
				
				if(old_stringz != new_string)
				{
					file_l.Text = playlist.Items[MP3.playlist_index].SubItems[0].Text;
					
					if (MP3.is_shuffle)
					{
						file_l.Text = playlist.Items[MP3.playlist_index].SubItems[0].Text +
							" " +
							" (item " + item_number_z + " of " + playlist.Items.Count + ")";
						
					}
				}
				old_stringz = new_string;
			}
			else
			{
				file_l.Text = "";
			}
			MP3.GetPixelFormat____(number, message);
			pixel_l.Text = "Pixel Format: " + message.ToString();

			if(MP3.GetTickCount() > old_value_v27_z)
			{
				MP3.pedro_dprintf(-1, "data " + pixel_l.Text);
				old_value_v27_z = MP3.GetTickCount() + 334;
			}
			
			MP3.GetVideoInfo(number, message);
			info.Text = "Video info: " + message.ToString();

			int ret2 = MP3.IntReturn(number);

			//////////////////section to update the playback status

			if (1000 == ret2)
			{
				if (1 == open_flag)
				{
					label4.Text = "Status: stop";
				}
				else
				{
					label4.Text = "Status: play";
				}
			}

			if (1001 == ret2)
			{
				label4.Text = "Status: paused";
			}

			if (ret2 < 1000)
			{
				label4.Text = "Status: stop";
			}
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			MP3.GetSampleFormatInfo(number, sample_format_k_p);
			label5.Text = "Sample rate: " + MP3.SampleRate(number).ToString() + " Sample Format: " + sample_format_k_p.ToString();
			label8.Text = "Channels: playing: " + MP3.Channels(number).ToString() + " original: " + MP3.GetOriginalNumberofChannels(number);

			bits_per_sample.Text = "Bits per sample " + MP3.Bits_per_Sample(number);

			label7.Text = "Bitrate: " + MP3.GetBitrate(number).ToString();

			MP3.GetMpegMode(number, time);
			label6.Text = "Mode: " + time.ToString();

			if (1 == MP3.IsUsingNormalization(number))
			{
				label9.Text = "Normalization: true";
			}
			else
			{
				label9.Text = "Normalization: false";
			}

			label1.Text = "Position: " + MP3.GetTimeMilliseconds(number).ToString();

			label15.Text = "Milliseconds: " + MP3.GetLengthMilliseconds(number).ToString();

			MP3.GetMediaInformation(number, time);
			label16.Text = "Media type: " + time.ToString();

			MP3.NormalizationFactor(number, time);

			label17.Text = "Normalize factor: " + time.ToString();

			peak.Value = MP3.GetPeak(number);

			Position = MP3.PlayBackPosition_10000(number);

			//progressbar_27_51_z_v21.Value = Position;
			progressbar_27_51_z_v21.Value = Position;

			MP3.GetTimeString(number, time);

			label14.Text = "Time position " + time.ToString();

			this.Text = time.ToString() + " - " + nome_da_dll;

			MP3.GetLengthString(number, time);

			label12.Text = "Time " + time.ToString();

			MP3.Alladin_GetRemainingTime(number, _data_);

			label24.Text = "Remaining time: " + _data_.ToString();

			int ret;

			ret = MP3.IntReturn(number);

			if (999 > ret)
			{
				disable_standby.EnableConstantDisplayAndPower(false);
				label10.Text = "Finished event raised";
				main_timer.Enabled = false;
				if (0 != ret)
				{

					MP3.GetErrorString(number, ret, message);
					morcego_error.Items.Add(message.ToString());
					morcego_error.SelectedIndex = morcego_error.Items.Count - 1;
					main_timer.Enabled = false;
					
					MP3.pedro_dprintf(1001, "Failed with " + file_l.Text);
					
					return;
				}

				if (MP3.is_playlist)
				{
					MP3.playlist_index++;
					if (MP3.is_shuffle)
					{
						if (MP3.is_shuffle)//why?!
						{
							int v;// = MP3.get_rand(0, playlist.Items.Count - 1);
							
							MP3.get_next_item_z(ref item_got_z, ref item_number_z);
							
							v = (int) item_got_z;
							
							MP3.playlist_index = v;
						}
					}
					else
					{
						if (MP3.playlist_index == playlist.Items.Count)
						{
							MP3.playlist_index = 0;
						}
					}
					int loop_ = 0;
					if (CheckState.Checked == loop.CheckState)
					{
						loop_ = 1;
					}
					playlist.Items[MP3.playlist_index].Selected=true;
					playlist.Items[MP3.playlist_index].EnsureVisible();
					playlist.Visible = false;
					file_l.Text = playlist.Items[MP3.playlist_index].SubItems[0].Text;
					
					if (MP3.is_shuffle)
					{
						file_l.Text = playlist.Items[MP3.playlist_index].SubItems[0].Text +
							" " +
							" (item " + item_number_z + " of " + playlist.Items.Count + ")";
						
						filetowav .Text = "Z:/Ava/back/" + playlist.Items[MP3.playlist_index].SubItems[0].Text;
					}
					
					MP3.SlowComputersCommand_k_p
						(
							number,
							0
						);
					if(true == enable_sc_hack.Checked)
					{
						MP3.SlowComputersCommand_k_p
							(
								number,
								1
							);
					}
					video_p.Image = dummy2_p.Image;
					video_f_p.Image = dummy2_p.Image;
					can_scape_z = true;
					MP3.clean_up_memory_p();
					ret = MP3.Play(number, MP3.wide2utf8(playlist.Items[MP3.playlist_index].SubItems[1].Text), loop_, int.Parse(track.Text),
					               video_p.Handle.ToInt64(),
					               video_f_p.Handle.ToInt64(),
					               video_p.Width,
					               video_p.Height,
					               the_ratio,
					               video_p.Left,
					               video_p.Top);
					disable_standby.EnableConstantDisplayAndPower(true);
					
					main_timer.Enabled = true;
				}
			}
			//MP3.pedro_dprintf(0, "exit 1");
		}
		private void button2_Click(object sender, EventArgs e)
		{
			of1.Filter = "All files (*.*)|*.*";
			of1.FileName = "";
			DialogResult dlg = of1.ShowDialog();

			if (dlg == DialogResult.OK)
			{
				filename.Text = of1.FileName;
			}
		}

		int disable = 0;

		StringBuilder settings = new StringBuilder(300*6);

		StringBuilder message = new StringBuilder(300*6);

		StringBuilder time = new StringBuilder(300);

		morcego_ratio the_ratio = morcego_ratio.BE_AUTO_______;

		string copia = "";

		int slider_original_location;

		int slider_width;

		int oldposition = 0;

		StringBuilder _data_ = new StringBuilder(300);

		int Position = 0;

		int pause_state_ = 0;
		int fullscreen_state_ = 0;

		long number = MP3.number;
		string nome_da_dll;
		int already=0;
		
		int old_value_z = 0;
		
		private void my_thread_fullscreen_fix_p()
		{
			if(false == mode_is_ricardo_window)
				progressbar_27_51_z_v21.Top = bar_pos_top_p;
			
			if(false == main_timer.Enabled)
			{
				video_p.Image = dummy2_p.Image;
				video_f_p.Image = dummy2_p.Image;
				return;
			}
			
			if(true == fullscreen_fix_p.Checked)
			{
				
				this.TopMost = true;
			}
			
			this.BringToFront();
			
			return;
		}
		private void my_thread()
		{
			//int counter_p = 0;
			int ret_arp;
			
			old_value_z = MP3.GetNumberofWaveOutDevices(number);
			label20.Left = label20.Left - 2;
			while(true)
			{
				
				Thread.Sleep(1000);
				
				//counter_p++;
				/*
				if(0 == counter_p % 3)
				{
				
					MP3.clean_up_memory_p();
					MP3.pedro_dprintf(0, "clean...");
					
				}
				 */
				if(0 == number)
				{
					return;
				}
				
				try
				{
					
					MP3.memory_usage__z(memory_usage_z);
					label20.Text = "Memory Usage: " + memory_usage_z.ToString();
					
				}
				catch
				{
					//MessageBox.Show("Erro");
					return;
				}
				
				if(0 == number)
				{
					return;
				}
				
				ret_arp = MP3.GetNumberofWaveOutDevices(number);
				
				if(old_value_z  != ret_arp)
				{
					MP3.pedro_dprintf(-1, "Detected changes in soundcards");
					disable_pause_resume = true;
					button7_Click(null, null);
					
					if(ret_arp != 0)
					{
						int l;
						waveout.Items.Clear();
						for (l = 0; l < ret_arp; l++)
						{
							MP3.GetWaveOutDevicesName(number, l, settings);
							waveout.Items.Add(settings.ToString());
							waveout.SelectedIndex = 0;
						}
					}
					old_value_z = ret_arp;

				}
			}
		}
		
		private void Form1_Load(object sender, EventArgs e)
		{
		
			string temp_i;
			this.Height = Screen.PrimaryScreen.WorkingArea.Height + 20;
			this.Width  = Screen.PrimaryScreen.WorkingArea.Width ;
			
			(new Thread(new ThreadStart(my_thread))).Start();
			
			int s16000;
			int s14000;
			int s12000;
			int s6000;
			int s3000;
			int s1000;
			int s600;
			int s310;
			int s170;
			int s60;
			
			int ret;
			
			if (MP3.count_running_k_p(Application.ExecutablePath) > 1)
			{
				if(false == MP3.allow_create_new_instance_k_p)
				{
					MP3.SaveSettings("new_filename_k_p", the_file_to_play);
					util_amanda.exit_ramses(0);
				}
			}
			koci_timer.Enabled = true;
			this.Top = 0; //why my love?...
/*
			MP3.ControlName(message);
			nome_da_dll = message.ToString();
*/

			video_p.Image = dummyimage_p.Image;
			
			video_p.Width = 667;
			
			video_p.Height = video_p.Height - 2;
			
			video_f_p.Image = dummy2_p.Image;
			track.Items.Add("1");
			track.Text = "1";
			MP3.GetSettings("slow_computers_hack_k_p", settings, "0");
			MP3.SlowComputersCommand_k_p
				(
					number,
					0
				);
			
			enable_sc_hack.Checked = false;
			
			if("1" == settings.ToString())
			{
				MP3.SlowComputersCommand_k_p
					(
						number,
						1
					);
				enable_sc_hack.Checked = true;
			}
			
			MP3.GetSettings("equalizer", settings, "0");

			if ("0" == settings.ToString())
			{
				MP3.EnableEqualizer(number, 0);
			}
			else
			{
				MP3.EnableEqualizer(number, 1);
			}
			
			
			MP3.GetSettings("s60", settings, "5");
			s60 = int.Parse(settings.ToString());
			MP3.GetSettings("s170", settings, "5");
			s170 = int.Parse(settings.ToString());
			MP3.GetSettings("s310", settings, "5");
			s310 = int.Parse(settings.ToString());
			MP3.GetSettings("s600", settings, "5");
			s600 = int.Parse(settings.ToString());
			MP3.GetSettings("s1000", settings, "5");
			s1000 = int.Parse(settings.ToString());
			MP3.GetSettings("s3000", settings, "5");
			s3000 = int.Parse(settings.ToString());
			MP3.GetSettings("s6000", settings, "5");
			s6000 = int.Parse(settings.ToString());
			MP3.GetSettings("s12000", settings, "5");
			s12000 = int.Parse(settings.ToString());
			MP3.GetSettings("s14000", settings, "5");
			s14000 = int.Parse(settings.ToString());
			MP3.GetSettings("s16000", settings, "5");
			s16000 = int.Parse(settings.ToString());

			MP3.EqualizerSettings(number,
			                      (s60 * 10),
			                      (s170 * 10),
			                      (s310 * 10),
			                      (s600 * 10),
			                      (s1000 * 10),
			                      (s3000 * 10),
			                      (s6000 * 10),
			                      (s12000 * 10),
			                      (s14000 * 10),
			                      (s16000 * 10));
			
			MP3.GetSettings("be_effect", settings, "0");
			if ("1"==settings.ToString())
			{
				MP3.GetSettings("be_effect_val", settings, "0");
				MP3.BE_Special_Wav_Effect(number, 1, int.Parse(settings.ToString ()));
			}
			else
			{
				MP3.GetSettings("be_effect_val", settings, "0");
				MP3.BE_Special_Wav_Effect(number, 0, int.Parse(settings.ToString()));
			}

			MP3.GetSettings("randon", settings, "0");

			MP3.is_shuffle = true;
			randon.CheckState = CheckState.Checked;
			if ("0" == settings.ToString())
			{
				MP3.is_shuffle = false;
				randon.CheckState = CheckState.Unchecked;
			}

			MP3.GetSettings("width", settings, "0");

			width_t.Text = settings.ToString();

			MP3.GetSettings("replaygain", settings, "0");

			MP3.EnableOnTheFlyVolumeNormalization(number, int.Parse(settings.ToString()));

			MP3.GetSettings("wav_out_vol", settings, "100");
			int value = int.Parse(settings.ToString());
			MP3.SetVolumeGain(number, value);

			wave_out_volume.Value = value;

			MP3.GetSettings("play_as_mp3", settings, "0");

			MP3.GetSettings("stereo_as_mono", settings, "0");

			/*you are not in Kansas anymore*/
			if ("0" == settings.ToString())
			{
				stereo_as_mono.CheckState = CheckState.Unchecked;
				MP3.BucaneiroPlayStereoAsMono(number, 0);

			}
			else
			{
				stereo_as_mono.CheckState = CheckState.Checked;
				MP3.BucaneiroPlayStereoAsMono(number, 1);

			}

			MP3.GetSettings("volume_v11", settings, "100");
			internal_volume.Value = int.Parse(settings.ToString());

			MP3.InternalVolume(number, internal_volume.Value);

			MP3.GetSettings("encryption", settings, "0");


			StringBuilder euo = new StringBuilder(300);

			MP3.ControlName(euo);
			temp_i = euo.ToString();

			// Get the file version.
			FileVersionInfo myFileVersionInfo = FileVersionInfo.GetVersionInfo(System.Reflection.Assembly.GetEntryAssembly().Location);
			
			copia = temp_i;

			copia += " Sample Version: " + myFileVersionInfo.ProductVersion;
			
			nome_da_dll = copia;
			
			this.Text = copia;
			
			MP3.GetSettings("filename", settings, "");
			filename.Text = MP3.utf82wide(settings.ToString());

			MP3.GetSettings("loop", settings, "0");

			if ("0" == settings.ToString())
			{
				loop.CheckState = CheckState.Unchecked;
			}
			else
			{
				loop.CheckState = CheckState.Checked;
			}

			priority.Items.Add("IDLE");
			priority.Items.Add("NORMAL");
			priority.Items.Add("HIGH");

			MP3.GetSettings("priority", settings, "1");

			priority.SelectedIndex = int.Parse(settings.ToString());

			ret = MP3.GetNumberofWaveOutDevices(number);

			if (0 == ret)
			{
				MessageBox.Show("No soundcard installed in the system");
				waveout.Text = "<no soundcard>";
			}
			else
			{
				disable = 1;

				int l;

				for (l = 0; l < ret; l++)
				{
					MP3.GetWaveOutDevicesName(number, l, settings);
					waveout.Items.Add(settings.ToString());
				}
				MP3.GetSettings("waveout", settings, "0");
				waveout.SelectedIndex = int.Parse(settings.ToString());

				disable = 0;
			}
			slider_original_location = progressbar_27_51_z_v21.Left;
			slider_width = progressbar_27_51_z_v21.Width;
			
			if("" != the_file_to_play)
			{
				
				filename.Text = the_file_to_play;
				button4_Click(null, null);
				
			}
			filetowav.Focus();
		}

		private void nobuffer_MouseUp(object sender, MouseEventArgs e)
		{
		}

		private void smart_MouseUp(object sender, MouseEventArgs e)
		{
		}

		private void limit_TextChanged(object sender, EventArgs e)
		{

		}

		private void waveout_SelectedIndexChanged(object sender, EventArgs e)
		{
			if (disable > 0)
			{
				return;
			}
			
			MP3.SaveSettings("waveout", waveout.SelectedIndex.ToString());

		}

		private void loop_MouseUp(object sender, MouseEventArgs e)
		{

			if (CheckState.Checked == loop.CheckState)
			{
				MP3.SaveSettings("loop", "1");
			}
			else
			{
				MP3.SaveSettings("loop", "0");
			}

		}
		private void button4_Click(object sender, EventArgs e)
		{
			int ret;
			disable_pause_resume = false;
			already=0;
			playlist.Visible = false;
			main_timer.Enabled = false;
			pause_state_ = 0;
			
			video_p.Image = dummy2_p.Image;
			video_f_p.Image = dummy2_p.Image;
			
			open_flag = 0;
			label10.Text = "Playing";
			MP3.GetSettings("replaygain", settings, "0");
			MP3.EnableOnTheFlyVolumeNormalization(number, int.Parse(settings.ToString()));


			MP3.SetWaveOutDevice(number, waveout.SelectedIndex);
			MP3.is_playlist = false;
			int loop_ = 0;
			if (CheckState.Checked == loop.CheckState)
			{
				loop_ = 1;
			}
			int r;
			r = MP3.Is_WPL_Playlist(number, MP3.wide2utf8(filename.Text));
			
			if (0 == r)
			{
				MP3.SlowComputersCommand_k_p
					(
						number,
						0
					);
				if(true == enable_sc_hack.Checked)
				{
					MP3.SlowComputersCommand_k_p
						(
							number,
							1
						);
				}
				can_scape_z = true;
				MP3.clean_up_memory_p();
				
				ret = MP3.Play(number, MP3.wide2utf8(filename.Text), loop_, int.Parse(track.Text),
				               video_p.Handle.ToInt64(),
				               video_f_p.Handle.ToInt64(),
				               video_p.Width,
				               video_p.Height,
				               the_ratio,
				               video_p.Left,
				               video_p.Top);
				
			}
			else
			{
				//aqui inicia o controle...
				playlist.Items.Clear();
				MP3.init_playlist_z();
				
			devolta:
				;
				r = MP3.GetPlaylistFiles(number, message);

				if (1 == r)
				{
					MP3.add_more_one_z();
					MP3.get_filename
						(
							message.ToString(),
							settings
						)
						;
					
					//aqui adiciona um item
					
					var coisa = playlist.Items.Add(MP3.utf82wide(this.settings.ToString()));
					coisa.SubItems.Add(MP3.utf82wide(message.ToString()));
					goto devolta;
				}
				MP3.is_playlist = true;
				MP3.playlist_index = 0;

				if (MP3.is_shuffle)
				{
					int v;// = MP3.get_rand(0, playlist.Items.Count - 1);
					
					MP3.get_next_item_z(ref item_got_z, ref item_number_z);
					
					v = (int) item_got_z;
					
					MP3.playlist_index = v;
				}
				playlist.Visible = true;
				playlist.Items[MP3.playlist_index].Selected = true;
				playlist.Items[MP3.playlist_index].EnsureVisible();
				playlist.Visible = false;
				file_l.Text = playlist.Items[MP3.playlist_index].SubItems[0].Text;
				
				if (MP3.is_shuffle)
				{
					file_l.Text = playlist.Items[MP3.playlist_index].SubItems[0].Text +
						" " +
						" (item " + item_number_z + " of " + playlist.Items.Count + ")";
					
				}
				
				MP3.SlowComputersCommand_k_p
					(
						number,
						0
					);
				if(true == enable_sc_hack.Checked)
				{
					MP3.SlowComputersCommand_k_p
						(
							number,
							1
						);
				}
				can_scape_z = true;
				MP3.clean_up_memory_p();
				ret = MP3.Play(number, MP3.wide2utf8(playlist.Items[MP3.playlist_index].SubItems[1].Text), loop_, int.Parse(track.Text),
				               video_p.Handle.ToInt64(),
				               video_f_p.Handle.ToInt64(),
				               video_p.Width,
				               video_p.Height,
				               the_ratio,
				               video_p.Left,
				               video_p.Top);
			}

			main_timer.Enabled = true;
			//-1 == ret then last call was not finished loading the media file yet
			
			disable_standby.EnableConstantDisplayAndPower(true);
		}

		private void filename_TextChanged(object sender, EventArgs e)
		{
			MP3.SaveSettings("filename", MP3.wide2utf8(filename.Text));
		}
		
		int open_flag = 0;
		private void button6_Click(object sender, EventArgs e)
		{
			int ret;
			disable_pause_resume = false;
			already=0;
			playlist.Visible = false;
			main_timer.Enabled = false;
			pause_state_ = 0;
			video_p.Image = dummy2_p.Image;
			video_f_p.Image = dummy2_p.Image;
			
			open_flag = 0;
			label10.Text = "Playing";
			MP3.GetSettings("replaygain", settings, "0");
			MP3.EnableOnTheFlyVolumeNormalization(number, int.Parse(settings.ToString()));

			MP3.SetWaveOutDevice(number, waveout.SelectedIndex);
			MP3.is_playlist = false;
			int loop_ = 0;
			if (CheckState.Checked == loop.CheckState)
			{
				loop_ = 1;
			}
			int r;
			r = MP3.Is_WPL_Playlist(number, MP3.wide2utf8(filename.Text));

			if (0 == r)
			{
				MP3.SlowComputersCommand_k_p
					(
						number,
						0
					);
				if(true == enable_sc_hack.Checked)
				{
					MP3.SlowComputersCommand_k_p
						(
							number,
							1
						);
				}
				can_scape_z = true;
				ret = MP3.Open(number, MP3.wide2utf8(filename.Text), loop_, int.Parse(track.Text),
				               video_p.Handle.ToInt64(),
				               video_f_p.Handle.ToInt64(),
				               video_p.Width,
				               video_p.Height,
				               the_ratio,
				               video_p.Left,
				               video_p.Top);
			}
			else
			{
				MP3.init_playlist_z();
				playlist.Items.Clear();
			devolta:
				;
				r = MP3.GetPlaylistFiles(number, message);

				if (1 == r)
				{

					MP3.add_more_one_z();
					MP3.get_filename
						(
							message.ToString(),
							settings
						)
						;

					ListViewItem coisa = playlist.Items.Add(MP3.utf82wide(settings.ToString()));
					coisa.SubItems.Add(MP3.utf82wide(message.ToString()));
					goto devolta;
				}
				MP3.is_playlist = true;
				MP3.playlist_index = 0;

				if (MP3.is_shuffle)
				{
					int v;// = MP3.get_rand(0, playlist.Items.Count - 1);
					
					MP3.get_next_item_z(ref item_got_z, ref item_number_z);
					
					v = (int) item_got_z;
					
					MP3.playlist_index = v;
				}
				playlist.Visible = true;
				playlist.Items[MP3.playlist_index].Selected = true;
				playlist.Items[MP3.playlist_index].EnsureVisible();
				playlist.Visible = false;
				file_l.Text = playlist.Items[MP3.playlist_index].SubItems[0].Text;
				
				if (MP3.is_shuffle)
				{
					file_l.Text = playlist.Items[MP3.playlist_index].SubItems[0].Text +
						" " +
						" (item " + item_number_z + " of " + playlist.Items.Count + ")";
					
				}
				
				MP3.SlowComputersCommand_k_p
					(
						number,
						0
					);
				if(true == enable_sc_hack.Checked)
				{
					MP3.SlowComputersCommand_k_p
						(
							number,
							1
						);
				}
				can_scape_z = true;
				ret = MP3.Open(number, MP3.wide2utf8(playlist.Items[MP3.playlist_index].SubItems[1].Text), loop_, int.Parse(track.Text),
				               video_p.Handle.ToInt64(),
				               video_f_p.Handle.ToInt64(),
				               video_p.Width,
				               video_p.Height,
				               the_ratio,
				               video_p.Left,
				               video_p.Top);
			}

			main_timer.Enabled = true;
			//-1 == ret then last call was not finished loading the media file yet
			disable_standby.EnableConstantDisplayAndPower(true);
			
		}

		private void morcego_pass_video_information()
		{

			int amanda_width = video_p.Width;
			if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2, if not the internals of the DLL will fix it to you
			{
				video_p.Height--;
			}
			if (1 == amanda_width % 2)
			{
				amanda_width--;
			}

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					amanda_width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button7_Click(object sender, EventArgs e)
		{
			MP3.PlaybackPause(number);
			pause_state_ = 1;
			disable_standby.EnableConstantDisplayAndPower(false);
		}

		private void button5_Click(object sender, EventArgs e)
		{
			MP3.PlaybackResume(number);
			
			pause_state_ = 0;
			disable_standby.EnableConstantDisplayAndPower(true);
		}

		private void button8_Click(object sender, EventArgs e)
		{
			main_timer.Enabled = false;
			MP3.is_playlist = false;
			MP3.PlaybackCancel(number);
			label4.Text = "Status: stop";
			label10.Text = "Cancel";
			peak.Value = 0;

			video_p.Image = dummyimage_p.Image;
			video_f_p.Image = dummy2_p.Image;
			video_f_p.Top = video_p.Top + 100;
			video_f_p.Height = 30;
			video_f_p.Width = 20;
			video_f_p.Left = 80;
			
			disable_standby.EnableConstantDisplayAndPower(false);
		}

		private void priority_SelectedIndexChanged(object sender, EventArgs e)
		{
			MP3.SaveSettings("priority", priority.SelectedIndex.ToString());
			if ("IDLE" == priority.Text)
			{
				MP3.SetPriority(number, 0);
			}
			if ("NORMAL" == priority.Text)
			{
				MP3.SetPriority(number, 1);
			}
			if ("HIGH" == priority.Text)
			{
				MP3.SetPriority(number, 2);
			}
		}

		private void button10_Click(object sender, EventArgs e)
		{

			/* why the rest of the code is not so easy to write like this...*/
			label10.Text = "Converting...";
			this.Refresh();

			StringBuilder err_msg = new StringBuilder(300);

			select_wav_mode eu = new select_wav_mode();
			eu.ShowDialog();

			//progressbar1.Value = (0);
			progressbar_27_51_z_v21.Value = (0x0);

			
			//this part of the sample need to be improved....it will soon...in a few minutes
			
			if (0 != MP3.ConvertMP3ToWavExtended(number, MP3.wide2utf8(filename.Text),
			                                     MP3.wide2utf8(filetowav.Text), MP3.wave_mode,
			                                     int.Parse(track.Text)))
			{

				morcego_error.Items.Add(5.ToString() + " - Decoder is in use");
				morcego_error.SelectedIndex = morcego_error.Items.Count - 1;
				return;
			}

			convert_timer.Enabled = true;

		}

		private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
		{
			MP3.About();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			if(null == MP3.p)
			{
				MP3.p = new equalizer();
			}
			
			MP3.p.Show();
			MP3.p.WindowState = FormWindowState.Normal;
			MP3.p.BringToFront();
			MP3.p.Activate();
		}

		private void button3_Click(object sender, EventArgs e)
		{
			if(null == MP3.k2)
			{
				MP3.k2 = new normalize();
			}
			
			MP3.k2.Show();
			MP3.k2.WindowState = FormWindowState.Normal;
			MP3.k2.BringToFront();
			MP3.k2.Activate();
		}

		private void button11_Click(object sender, EventArgs e)
		{
			//modified december 2020, 02 11:17:39 AM
			
			if(null == MP3.k)
			{
				MP3.k = new spectrum();
			}
			
			MP3.k.Show();
			MP3.k.WindowState = FormWindowState.Normal;
			MP3.k.BringToFront();
			MP3.k.Activate();
			
		}

		private void button12_Click(object sender, EventArgs e)
		{
			int i;

			for (i = 0; i < 150; i++)
			{
				StringBuilder data_ = new StringBuilder(300);

				MP3.Generate_ID3v1Genre(number, i, data_);
			}
		}

		private void button12_Click_1(object sender, EventArgs e)
		{
			if(null == MP3.p2)
			{
				MP3.p2 = new DebugInformation();
			}
			
			MP3.p2.Show();
			MP3.p2.WindowState = FormWindowState.Normal;
			MP3.p2.BringToFront();
			MP3.p2.Activate();
		}

		private void button13_Click(object sender, EventArgs e)
		{
			if(null == MP3.k3)
			{
				MP3.k3 = new wave_effects();
			}
			
			MP3.k3.Show();
			MP3.k3.WindowState = FormWindowState.Normal;
			MP3.k3.BringToFront();
			MP3.k3.Activate();
		}
		private void button14_Click(object sender, EventArgs e)
		{

			internal_volume.Value = 100;
			MP3.InternalVolume(number, internal_volume.Value);
			MP3.SaveSettings("volume_v11", internal_volume.Value.ToString());

		}
		private void stereo_as_mono_MouseUp(object sender, MouseEventArgs e)
		{

			if (CheckState.Unchecked == stereo_as_mono.CheckState)
			{

				MP3.SaveSettings("stereo_as_mono", "0");
				MP3.BucaneiroPlayStereoAsMono(number, 0);

			}
			else
			{
				MP3.SaveSettings("stereo_as_mono", "1");
				MP3.BucaneiroPlayStereoAsMono(number, 1);
			}

		}

		private void button15_Click(object sender, EventArgs e)
		{
			int ret;
			ret = MP3.GetNumberOfAudioTracks(number, MP3.wide2utf8(filename.Text), message);
			if (ret < 0)
			{
				morcego_error.Items.Add(ret + " - " + message.ToString());
				morcego_error.SelectedIndex = morcego_error.Items.Count - 1;
			}
			else
			{

				if (0 == ret)
				{
					track.Text = "1";//default to track 1
				}
				else
				{
					
					track.Items.Clear();
					for (int i = 0; i < ret; i++)
					{
						track.Items.Add((i + 1).ToString());
					}
					track.Text = "1";
				}

			}
		}

		private void convert_timer_Tick(object sender, EventArgs e)
		{
			int finished;
			int percent;
			int returnvalue;
			MP3.GetConversionInfo(number, out percent, out finished, out returnvalue, message);
			//progressbar1.Value = (percent * 100);
			
			progressbar_27_51_z_v21.Value = (percent * 100);
			
			if (0 != finished)
			{
				if (0 != returnvalue)
				{
					morcego_error.Items.Add(returnvalue.ToString() + " - " + message.ToString());
					morcego_error.SelectedIndex = morcego_error.Items.Count - 1;
				}
				label10.Text = "Finished...";
				convert_timer.Enabled = false;
				//progressbar1.Value = 10000;
				progressbar_27_51_z_v21.Value = 10000;
			}
			return;
		}

		private void progressbar1_Mouse(amanda_progress.progressbar.ExtendedMouseEvent e)
		{
			MP3.SeekTo_10000(number, e.Value);
		}
		
		private void internal_volume_Mouse(amanda_progress.progressbar.ExtendedMouseEvent e)
		{
			internal_volume.Value = e.Value;
			MP3.InternalVolume(number, e.Value);
			MP3.SaveSettings("volume_v11", e.Value.ToString());
		}

		private void wave_out_volume_Mouse(amanda_progress.progressbar.ExtendedMouseEvent e)
		{
			wave_out_volume.Value = e.Value;
			MP3.SetVolumeGain(number, e.Value);
			MP3.SaveSettings("wav_out_vol", e.Value.ToString());
		}

		private void button16_Click(object sender, EventArgs e)
		{
			if(null == MP3.p4)
			{
				MP3.p4 = new id3tag(filename.Text.Trim());
			}
			
			MP3.p4.Show();
			MP3.p4.WindowState = FormWindowState.Normal;
			MP3.p4.BringToFront();
			MP3.p4.Activate();
		}

		private void sample_FormClosing(object sender, FormClosingEventArgs e)
		{
			main_timer.Enabled = false;
			MP3.PlaybackCancel(number);
			MP3.BE_CloseDecoder(ref number);
		}

		private void button17_Click(object sender, EventArgs e)
		{
			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_AUTO_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void morcego_adjust_ratio()
		{
			if (MP3.loading_file)
			{
				MP3.dprintf("trying to load a file while the load function have not returned yet");
				return;
			}
			MP3.loading_file = true;
			double position = MP3.PlayBackPosition_AV_TIME_BASE(number);
			if (MP3.IntReturn(number) > 999)
			{

				MP3.PlaybackCancel(number);

				button6_Click(null, null);

				while (-1 == MP3.SampleRate(number))
				{
					Application.DoEvents();

					Thread.Sleep(50);
				}


				MP3.SeekTo_AV_TIME_BASE(number, position);
				MP3.PlaybackResume(number);
				
			}
			MP3.loading_file = false;
		}

		private void button24_Click(object sender, EventArgs e)
		{
			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_5x4_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button23_Click(object sender, EventArgs e)
		{
			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_16x9_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button22_Click(object sender, EventArgs e)
		{
			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_4x3_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button21_Click(object sender, EventArgs e)
		{
			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_2_21x1_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button20_Click(object sender, EventArgs e)
		{
			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_2_35x1_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button19_Click(object sender, EventArgs e)
		{
			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_2_39x1_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button18_Click(object sender, EventArgs e)
		{
			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_1x1_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button25_Click(object sender, EventArgs e)
		{
			
			(new Thread(new ThreadStart(my_thread_fullscreen_fix_p))).Start();
			can_scape_z = true;
			pause_state_ = 0;

			//double position = MP3.PlayBackPosition_AV_TIME_BASE(number);

			if (true)//what is it?!!
			{
				this.WindowState = FormWindowState.Normal;
				this.FormBorderStyle = FormBorderStyle.None;
				this.Left = 0;
				this.Top  = 0;
				this.Width  = Screen.PrimaryScreen.Bounds.Width;
				this.Height = Screen.PrimaryScreen.Bounds.Height;
				
				fullscreen_state_ = 1;

				MP3.is_full_screen = true;

				background_p.Visible = true;
				background_p.Width = this.Width;
				background_p.Height = this.Height;
				background_p.Top = 0;
				background_p.Left = 0;
				background_p.BringToFront();

				video_p.Width = this.Width;

				progressbar_27_51_z_v21.Width = this.Width - 56;

				int val = (this.Width - progressbar_27_51_z_v21.Width) / 2;

				progressbar_27_51_z_v21.Left = val - 5;

				video_p.Height = Screen.PrimaryScreen.Bounds.Height;

				if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2
				{
					video_p.Height--;
				}
				if (1 == video_p.Width % 2)
				{
					video_p.Width--;
				}

				video_p.Top = 0;
				video_p.Left = 0;
				video_p.BringToFront();
				weird_timer.Enabled = true;
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				fs.Enabled = true;
				
			}
		}

		private void video_p_MouseClick(object sender, MouseEventArgs e)
		{
			this.FormBorderStyle = FormBorderStyle.Sizable;
			this.WindowState = FormWindowState.Normal;
			
			if(mode_is_ricardo_window)
			{
				
				this.Width = ori_width;
				this.Height = ori_height;
				this.Top = 0;
				this.Left = 0;
				mode_is_ricardo_window = false;
								
				fullscreen_state_ = 0;
				video_p_MouseClick(null, null);
				
				fs.Enabled = false;
				esconde_t.Enabled = false;

				bool flag = false;
				play_v13
					.Visible = flag;
				pause_v13
					.Visible = flag;
				resume_v13 .Visible = flag;
				cancel_v13
					.Visible = flag;

				MP3.is_full_screen = false;
				this.Text = copia;
				
				bugfix_fullscreen_z.BackColor = System.Drawing.Color.Black;

				bugfix_fullscreen_z.Left       =           20;
				bugfix_fullscreen_z.Top        =           92;
				bugfix_fullscreen_z.Width      =          667;
				bugfix_fullscreen_z.Height     =          336;
				bugfix_fullscreen_z.BringToFront           ();
				video_p.Left                   =         9000;
				video_p.Top                    =           92;
				video_p.Width                  =          667;
				video_p.Height                 =          336;
				
				video_f_p.Left                 =           20;
				video_f_p.Top                  =           92;
				video_f_p.Width                =          667;
				video_f_p.Height               =          336;
				video_p.Visible                =         true;
				video_f_p.Visible              =        false;
				
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				video_p.Left          =     20;
				video_p.Top           =     92;
				
				
				video_f_p.Left        =     20;
				video_f_p.Top         =     92;
				
				video_p.Visible       =   true;
				video_f_p.Visible     =  false;
				
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;
				
				video_p.Visible           =       true;
				video_f_p.Visible         =      false;
				
				
			}
			/*
			else
				;//this.Height = 706 - 38;
			*/
			this.Height = 706 ;//- 38;
			
			this.TopMost = false;
			MP3.ShowCursor_(1);
			background_p.Visible = false;
			weird_timer.Enabled = false;
			progressbar_27_51_z_v21.Width = slider_width;
			progressbar_27_51_z_v21.Left = slider_original_location;
			progressbar_27_51_z_v21.Top = 569;
			
			fullscreen_state_ = 0;
			
			if (MP3.is_full_screen == true)
			{
				
				fs.Enabled = false;
				esconde_t.Enabled = false;

				bool flag = false;
				play_v13
					.Visible = flag;
				pause_v13
					.Visible = flag;
				resume_v13 .Visible = flag;
				cancel_v13
					.Visible = flag;

				MP3.is_full_screen = false;
				this.Text = copia;

				video_p.Left = 20;
				video_p.Top = 92;
				video_p.Width = 667;
				video_p.Height = 336;

				double position = MP3.PlayBackPosition_AV_TIME_BASE(number);
				if (MP3.IntReturn(number) > 999)
				{
					
					video_p.BringToFront();

					MP3.PassWindowInformation
						(
							number,
							video_p.Handle.ToInt64(),
							video_f_p.Handle.ToInt64(),
							video_p.Width,
							video_p.Height,
							the_ratio,
							video_p.Left,
							video_p.Top
						)
						;
				}
				else
				{
					
					video_p.Image = dummyimage_p.Image;
					video_f_p.Image = dummy2_p.Image;
					video_f_p.Top = video_p.Top + 100;
					video_f_p.Height = 30;
					video_f_p.Width = 20;
					video_f_p.Left = 80;

				}
			}
		}

		private void video_f_p_MouseClick(object sender, MouseEventArgs e)
		{
			video_p_MouseClick(null, null);
		}

		private void sample_Move(object sender, EventArgs e)
		{

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;

			return;
		}

		private void button26_Click(object sender, EventArgs e)
		{

			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_16x10_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void button25_Click_1(object sender, EventArgs e)
		{

			MP3.adjusted_ratio = 0;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);
			the_ratio = morcego_ratio.BE_2_50x1_______;

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;
		}

		private void fs_Tick(object sender, EventArgs e)
		{
			fs.Interval = 4000;
			if (MP3.disabled)
			{
				return;
			}
			if (MP3.is_full_screen == true)
			{

				play_v13
					.Visible = true;
				pause_v13
					.Visible = true;
				resume_v13
					.Visible = true;
				cancel_v13
					.Visible = true;

				play_v13
					.BringToFront();
				pause_v13
					.BringToFront();
				resume_v13
					.BringToFront();
				cancel_v13
					.BringToFront();
				progressbar_27_51_z_v21.BringToFront();

				{
					if(false == mode_is_ricardo_window)
					{
						MP3.ShowCursor_(0);
					}
					if (50 != esconde_t.Interval)
					{
						esconde_t.Enabled = false;
						esconde_t.Interval = 3000;
						esconde_t.Enabled = true;
					}



				}
			}
			else
			{
				MP3.ShowCursor_(1);
				fs.Enabled = false;
			}
		}

		private void video_p_MouseMove(object sender, MouseEventArgs e)
		{

			show_constrols(e);

		}

		private void show_constrols(MouseEventArgs e)
		{


			if (oldposition != e.X)
			{
				play_v13
					.BringToFront();
				pause_v13
					.BringToFront();
				resume_v13
					.BringToFront();
				cancel_v13
					.BringToFront();
				progressbar_27_51_z_v21.BringToFront();

				MP3.ShowCursor_(1);
				if (MP3.is_full_screen)
				{

					fs.Enabled = false;
					fs.Enabled = true;
					play_v13
						.Top = 536;
					pause_v13
						.Top = 536;
					resume_v13
						.Top = 536;
					cancel_v13
						.Top = 536;
					if(false == mode_is_ricardo_window)
						progressbar_27_51_z_v21.Top = bar_pos_top_p;
					else
						progressbar_27_51_z_v21.Top = this.Height - 90;
					
					esconde_t.Enabled = false;
					esconde_t.Interval = 3000;

				}
				oldposition = e.X;
			}
		}

		private void video_f_p_MouseMove(object sender, MouseEventArgs e)
		{
			show_constrols(e);
		}

		private void play2_b_Click(object sender, EventArgs e)
		{
			can_scape_z = true;
			already=0;
			MP3.is_full_screen = true;
			fs.Enabled = true;
			MP3.PlaybackCancel(number);
			
			video_p.Width = this.Width;

			progressbar_27_51_z_v21.Width = this.Width - 46;

			int val = (this.Width - progressbar_27_51_z_v21.Width) / 2;

			progressbar_27_51_z_v21.Left = val;

			video_p.Height = this.Height;

			if (1 == video_p.Height % 2)
			{
				video_p.Height--;
			}
			if (1 == video_p.Width % 2)
			{
				video_p.Width--;
			}

			video_p.Top = 0;
			video_p.Left = 0;
			video_p.BringToFront();
			
			button6_Click(null, null);
			
			while (-1 == MP3.SampleRate(number))
			{
				Application.DoEvents();

				Thread.Sleep(50);
			}
			
			while(1 == MP3.GetWaveOutStatus_arp(number))//it is required to avoid the PlaybackResume using an old value for the wavout variable
			{
				Thread.Sleep(50);
			}
			
			MP3.PlaybackResume(number);
			
			
			play_v13
				.Visible = true;
			pause_v13
				.Visible = true;
			resume_v13
				.Visible = true;
			cancel_v13
				.Visible = true;

			play_v13
				.BringToFront();
			pause_v13
				.BringToFront();
			resume_v13
				.BringToFront();
			cancel_v13
				.BringToFront();
			
			progressbar_27_51_z_v21.BringToFront();
			
			fs.Enabled = true;
			
		}

		private void pause2_b_Click(object sender, EventArgs e)
		{
			MP3.PlaybackPause(number);
			pause_state_ = 1;
		}

		private void resume2_Click(object sender, EventArgs e)
		{
			MP3.PlaybackResume(number);
			
			pause_state_ = 0;
		}

		private void cancel2_Click(object sender, EventArgs e)
		{
			button8_Click(null, null);
		}

		private void esconde_t_Tick(object sender, EventArgs e)
		{
			if (play_v13.Top < 5000)
			{
				esconde_t.Interval = 50;
				play_v13
					.Top = play_v13.Top + 1;
				pause_v13
					.Top = pause_v13.Top + 1;
				resume_v13
					.Top = resume_v13.Top + 1;
				cancel_v13
					.Top = cancel_v13.Top + 1;
				progressbar_27_51_z_v21.Top = progressbar_27_51_z_v21.Top + 1;
			}
			else
			{
				esconde_t.Enabled = false;
				esconde_t.Interval = 3000;
			}
		}

		private void disable_video_MouseUp(object sender, MouseEventArgs e)
		{
			MP3.DisableVideo(number, 0);
			if (CheckState.Checked == disable_video.CheckState)
			{
				MP3.DisableVideo(number, 1);
			}
		}

		private void no_draw_MouseUp(object sender, MouseEventArgs e)
		{
			MP3.Don_t_Draw_Video(number, 0);
			if (CheckState.Checked == no_draw.CheckState)
			{
				MP3.Don_t_Draw_Video(number, 1);
			}
		}

		private void default_w_Click(object sender, EventArgs e)
		{
			
			(new Thread(new ThreadStart(my_thread_fullscreen_fix_p))).Start();
			can_scape_z = true;
			pause_state_ = 0;

			int w;
			int h;
			//double position = MP3.PlayBackPosition_AV_TIME_BASE(number);

			if (true)
			{
				fullscreen_state_ = 1;
				MP3.is_full_screen = true;

				this.WindowState = FormWindowState.Normal;
				this.FormBorderStyle = FormBorderStyle.None;
				this.Left = 0;
				this.Top  = 0;
				this.Width  = Screen.PrimaryScreen.Bounds.Width;
				this.Height = Screen.PrimaryScreen.Bounds.Height;
				
				fs.Enabled = true;

				MP3.GetWindowSize
					(
						number,
						out w,
						out h
					)
					;

				if (0 != w && 0 != h)
				{

					if (1 == w % 2)
					{
						w--;
					}
					if (1 == h % 2)
					{
						h--;
					}
					video_p.Width = w;
					video_p.Height = h;

					int p;

					p = (this.Width - w) / 2;

					video_p.Left = p;

					p = ((((Screen.PrimaryScreen.Bounds.Height) - h))) / 2;

					video_p.Top = p;

					background_p.Visible = true;
					background_p.Width = this.Width;
					background_p.Height = this.Height;
					background_p.Top = 0;
					background_p.Left = 0;
					background_p.BringToFront();

				}
				else
				{
					video_p.Width = this.Width;
					video_p.Height = this.Height;

					video_p.Top = 0;
					video_p.Left = 0;

				}
				progressbar_27_51_z_v21.Width = this.Width - 56;

				int val = (this.Width - progressbar_27_51_z_v21.Width) / 2;

				progressbar_27_51_z_v21.Left = val - 5;

				if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2
				{
					video_p.Height--;
				}
				if (1 == video_p.Width % 2)
				{
					video_p.Width--;
				}
				
				weird_timer.Enabled = true;
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				fs.Enabled = true;
			}
		}

		private void background_p_MouseMove(object sender, MouseEventArgs e)
		{
			show_constrols(e);
		}

		private void background_p_MouseClick(object sender, MouseEventArgs e)
		{
			video_p_MouseClick(null, e);
		}

		private void cancel_imer_Tick(object sender, EventArgs e)
		{
			button8_Click(null, null);
			cancel_imer.Enabled = false;
		}

		private void progressbar1_MouseEnter(object sender, EventArgs e)
		{

		}

		private void progressbar1_MouseLeave(object sender, EventArgs e)
		{

		}

		private void width_plu_plus_Click(object sender, EventArgs e)
		{

			MP3.adjusted_ratio += 0.1;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;

		}

		private void width_minus_minus_Click(object sender, EventArgs e)
		{

			MP3.adjusted_ratio -= 0.1;
			MP3.AdjustRatio(number, MP3.adjusted_ratio);

			MP3.PassWindowInformation
				(
					number,
					video_p.Handle.ToInt64(),
					video_f_p.Handle.ToInt64(),
					video_p.Width,
					video_p.Height,
					the_ratio,
					video_p.Left,
					video_p.Top
				)
				;

		}

		private void weird_timer_Tick(object sender, EventArgs e)
		{
			play_v13
				.Visible = true;
			pause_v13
				.Visible = true;
			resume_v13
				.Visible = true;
			cancel_v13
				.Visible = true;

			play_v13
				.BringToFront();
			pause_v13
				.BringToFront();
			resume_v13
				.BringToFront();
			cancel_v13
				.BringToFront();
			progressbar_27_51_z_v21.BringToFront();
		}

		private void fs_50_Click(object sender, EventArgs e)
		{
			(new Thread(new ThreadStart(my_thread_fullscreen_fix_p))).Start();
			can_scape_z = true;
			pause_state_ = 0;

			int w;
			int h;
			//double position = MP3.PlayBackPosition_AV_TIME_BASE(number);

			if (true)
			{
				fullscreen_state_ = 1;
				MP3.is_full_screen = true;

				this.WindowState = FormWindowState.Normal;
				this.FormBorderStyle = FormBorderStyle.None;
				this.Left = 0;
				this.Top  = 0;
				this.Width  = Screen.PrimaryScreen.Bounds.Width;
				this.Height = Screen.PrimaryScreen.Bounds.Height;

				fs.Enabled = true;

				MP3.GetWindowSize
					(
						number,
						out w,
						out h
					)
					;

				if (0 != w && 0 != h)
				{

					if (1 == w % 2)
					{
						w--;
					}
					if (1 == h % 2)
					{
						h--;
					}
					video_p.Width = w / 2;
					video_p.Height = h / 2;

					int p;

					p = (this.Width - (w / 2)) / 2;

					video_p.Left = p;

					p = ((((Screen.PrimaryScreen.Bounds.Height) - (h / 2)))) / 2;

					video_p.Top = p;

					background_p.Visible = true;
					background_p.Width = this.Width;
					background_p.Height = this.Height;
					background_p.Top = 0;
					background_p.Left = 0;
					background_p.BringToFront();

				}
				else
				{
					video_p.Width = this.Width;
					video_p.Height = this.Height;

					video_p.Top = 0;
					video_p.Left = 0;

				}
				progressbar_27_51_z_v21.Width = this.Width - 56;

				int val = (this.Width - progressbar_27_51_z_v21.Width) / 2;

				progressbar_27_51_z_v21.Left = val - 5;

				if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2
				{
					video_p.Height--;
				}
				if (1 == video_p.Width % 2)
				{
					video_p.Width--;
				}

				weird_timer.Enabled = true;
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				fs.Enabled = true;
			}

		}

		private void fs_200_Click(object sender, EventArgs e)
		{
			(new Thread(new ThreadStart(my_thread_fullscreen_fix_p))).Start();
			can_scape_z = true;
			pause_state_ = 0;

			int w;
			int h;
			//double position = MP3.PlayBackPosition_AV_TIME_BASE(number);

			if (true)
			{
				fullscreen_state_ = 1;
				MP3.is_full_screen = true;

				this.WindowState = FormWindowState.Normal;
				this.FormBorderStyle = FormBorderStyle.None;
				this.Left = 0;
				this.Top  = 0;
				this.Width  = Screen.PrimaryScreen.Bounds.Width;
				this.Height = Screen.PrimaryScreen.Bounds.Height;

				fs.Enabled = true;

				MP3.GetWindowSize
					(
						number,
						out w,
						out h
					)
					;

				if (0 != w && 0 != h)
				{

					if (1 == w % 2)
					{
						w--;
					}
					if (1 == h % 2)
					{
						h--;
					}
					video_p.Width = w * 2;
					video_p.Height = h * 2;

					int p;

					p = (this.Width - (w * 2)) / 2;

					video_p.Left = p;

					p = ((((Screen.PrimaryScreen.Bounds.Height) - h * 2))) / 2;

					video_p.Top = p;

					background_p.Visible = true;
					background_p.Width = this.Width;
					background_p.Height = this.Height;
					background_p.Top = 0;
					background_p.Left = 0;
					background_p.BringToFront();

				}
				else
				{
					video_p.Width = this.Width;
					video_p.Height = this.Height;

					video_p.Top = 0;
					video_p.Left = 0;

				}
				progressbar_27_51_z_v21.Width = this.Width - 56;

				int val = (this.Width - progressbar_27_51_z_v21.Width) / 2;

				progressbar_27_51_z_v21.Left = val - 5;

				if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2
				{
					video_p.Height--;
				}
				if (1 == video_p.Width % 2)
				{
					video_p.Width--;
				}

				weird_timer.Enabled = true;
				MP3.DisableWidthLimit(number);
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				fs.Enabled = true;
			}

		}

		private void fs_by_heigth_Click(object sender, EventArgs e)
		{
			(new Thread(new ThreadStart(my_thread_fullscreen_fix_p))).Start();
			can_scape_z = true;
			pause_state_ = 0;

			int w;
			int h;
			//double position = MP3.PlayBackPosition_AV_TIME_BASE(number);

			if (true)
			{
				fullscreen_state_ = 1;
				MP3.is_full_screen = true;

				this.WindowState = FormWindowState.Normal;
				this.FormBorderStyle = FormBorderStyle.None;
				this.Left = 0;
				this.Top  = 0;
				this.Width  = Screen.PrimaryScreen.Bounds.Width;
				this.Height = Screen.PrimaryScreen.Bounds.Height;

				fs.Enabled = true;

				MP3.GetWindowSize
					(
						number,
						out w,
						out h
					)
					;

				if (0 != w && 0 != h)
				{

					double ratio = (double)w / (double)h;//2


				again:
					;

					while (h < this.Height)
					{
						w++;
						double hh;
						double ww = w;
						hh = ww / ratio;
						h = (int)hh;
						goto again;
					}

					if (1 == w % 2)
					{
						w--;
					}
					if (1 == h % 2)
					{
						h--;
					}
					video_p.Width = w;
					video_p.Height = h;

					int p;

					p = (this.Width - w) / 2;

					video_p.Left = p;

					p = ((((Screen.PrimaryScreen.Bounds.Height) - h))) / 2;

					video_p.Top = p;

					background_p.Visible = true;
					background_p.Width = this.Width;
					background_p.Height = this.Height;
					background_p.Top = 0;
					background_p.Left = 0;
					background_p.BringToFront();

				}
				else
				{
					video_p.Width = this.Width;
					video_p.Height = this.Height;

					video_p.Top = 0;
					video_p.Left = 0;

				}
				progressbar_27_51_z_v21.Width = this.Width - 56;

				int val = (this.Width - progressbar_27_51_z_v21.Width) / 2;

				progressbar_27_51_z_v21.Left = val - 5;

				if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2
				{
					video_p.Height--;
				}
				if (1 == video_p.Width % 2)
				{
					video_p.Width--;
				}
				
				weird_timer.Enabled = true;

				MP3.DisableWidthLimit(number);

				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				fs.Enabled = true;
			}
		}

		private void fs_300_Click(object sender, EventArgs e)
		{
			(new Thread(new ThreadStart(my_thread_fullscreen_fix_p))).Start();
			can_scape_z = true;
			pause_state_ = 0;

			int w;
			int h;
			//double position = MP3.PlayBackPosition_AV_TIME_BASE(number);

			if (true)
			{
				fullscreen_state_ = 1;
				MP3.is_full_screen = true;

				this.WindowState = FormWindowState.Normal;
				this.FormBorderStyle = FormBorderStyle.None;
				this.Left = 0;
				this.Top  = 0;
				this.Width  = Screen.PrimaryScreen.Bounds.Width;
				this.Height = Screen.PrimaryScreen.Bounds.Height;

				fs.Enabled = true;

				MP3.GetWindowSize
					(
						number,
						out w,
						out h
					)
					;

				if (0 != w && 0 != h)
				{

					if (1 == w % 2)
					{
						w--;
					}
					if (1 == h % 2)
					{
						h--;
					}
					video_p.Width = w * 3;
					video_p.Height = h * 3;

					int p;

					p = (this.Width - (w * 3)) / 2;

					video_p.Left = p;

					p = ((((Screen.PrimaryScreen.Bounds.Height) - h * 3))) / 2;

					video_p.Top = p;

					background_p.Visible = true;
					background_p.Width = this.Width;
					background_p.Height = this.Height;
					background_p.Top = 0;
					background_p.Left = 0;
					background_p.BringToFront();

				}
				else
				{
					video_p.Width = this.Width;
					video_p.Height = this.Height;

					video_p.Top = 0;
					video_p.Left = 0;

				}
				progressbar_27_51_z_v21.Width = this.Width - 56;

				int val = (this.Width - progressbar_27_51_z_v21.Width) / 2;

				progressbar_27_51_z_v21.Left = val - 5;

				if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2
				{
					video_p.Height--;
				}
				if (1 == video_p.Width % 2)
				{
					video_p.Width--;
				}

				weird_timer.Enabled = true;
				MP3.DisableWidthLimit(number);
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				fs.Enabled = true;
			}

		}

		private void fs_400_Click(object sender, EventArgs e)
		{
			(new Thread(new ThreadStart(my_thread_fullscreen_fix_p))).Start();
			can_scape_z = true;
			pause_state_ = 0;

			int w;
			int h;
			//double position = MP3.PlayBackPosition_AV_TIME_BASE(number);

			if (true)
			{
				fullscreen_state_ = 1;
				MP3.is_full_screen = true;

				this.WindowState = FormWindowState.Normal;
				this.FormBorderStyle = FormBorderStyle.None;
				this.Left = 0;
				this.Top  = 0;
				this.Width  = Screen.PrimaryScreen.Bounds.Width;
				this.Height = Screen.PrimaryScreen.Bounds.Height;

				fs.Enabled = true;

				MP3.GetWindowSize
					(
						number,
						out w,
						out h
					)
					;

				if (0 != w && 0 != h)
				{

					if (1 == w % 2)
					{
						w--;
					}
					if (1 == h % 2)
					{
						h--;
					}
					video_p.Width = w * 4;
					video_p.Height = h * 4;

					int p;

					p = (this.Width - (w * 4)) / 2;

					video_p.Left = p;

					p = ((((Screen.PrimaryScreen.Bounds.Height) - h * 4))) / 2;

					video_p.Top = p;

					background_p.Visible = true;
					background_p.Width = this.Width;
					background_p.Height = this.Height;
					background_p.Top = 0;
					background_p.Left = 0;
					background_p.BringToFront();

				}
				else
				{
					video_p.Width = this.Width;
					video_p.Height = this.Height;

					video_p.Top = 0;
					video_p.Left = 0;

				}
				progressbar_27_51_z_v21.Width = this.Width - 56;

				int val = (this.Width - progressbar_27_51_z_v21.Width) / 2;

				progressbar_27_51_z_v21.Left = val - 5;

				if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2
				{
					video_p.Height--;
				}
				if (1 == video_p.Width % 2)
				{
					video_p.Width--;
				}

				video_p.BringToFront();
				weird_timer.Enabled = true;
				MP3.DisableWidthLimit(number);
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				fs.Enabled = true;
			}

		}

		private void create_Click_1(object sender, EventArgs e)
		{
			my_playlist_form_z amanda = new my_playlist_form_z();
			amanda.Show();
			this.WindowState = FormWindowState.Minimized;
		}
		private void button4_Click_1(object sender, EventArgs e)
		{
			if (false == playlist.Visible)
			{
				playlist.Visible = true;
				playlist.BringToFront();
				playlist.Focus();
				playlist.Activation = ItemActivation.Standard;
			}
			else
			{
				playlist.Visible = false;
			}
		}

		private void enable_slow_computer_hack_(object sender, MouseEventArgs e)
		{
			MP3.SaveSettings
				(
					
					"slow_computers_hack_k_p",
					"0"
				);
			MP3.SlowComputersCommand_k_p
				(
					number,
					0
				);
			if(true == enable_sc_hack.Checked)
			{
				MP3.SlowComputersCommand_k_p
					(
						number,
						1
					);
				MP3.SaveSettings
					(
						
						"slow_computers_hack_k_p",
						"1"
					);
			}
		}
		private void randon_MouseUp(object sender, MouseEventArgs e)
		{
			MP3.SaveSettings("randon", "0");
			MP3.is_shuffle = false;
			if (CheckState.Checked == randon.CheckState)
			{
				MP3.SaveSettings("randon", "1");
				MP3.is_shuffle = true;
			}
		}

		private void playlist_DoubleClick(object sender, EventArgs e)
		{
			ListViewItem coisa = playlist.SelectedItems[0];
			MP3.playlist_index = playlist.SelectedItems[0].Index;
			
			MP3.set_played_item_z(MP3.playlist_index);
			
			int loop_ = 0;
			if (CheckState.Checked == loop.CheckState)
			{
				loop_ = 1;
			}
			file_l.Text = coisa.SubItems[0].Text;
			
			MP3.SlowComputersCommand_k_p
				(
					number,
					0
				);
			if(true == enable_sc_hack.Checked)
			{
				MP3.SlowComputersCommand_k_p
					(
						number,
						1
					);
			}
			
			video_p.  Image   = dummy2_p.Image;
			video_f_p.Image   = dummy2_p.Image;
			can_scape_z = true;
			MP3.clean_up_memory_p();
			
			Clipboard.SetText(coisa.SubItems[1].Text);
			
			MP3.Play(number, MP3.wide2utf8(coisa.SubItems[1].Text), loop_, int.Parse(track.Text),
			         video_p.Handle.ToInt64(),
			         video_f_p.Handle.ToInt64(),
			         video_p.Width,
			         video_p.Height,
			         the_ratio,
			         video_p.Left,
			         video_p.Top);
			playlist.Visible = false;
			main_timer.Enabled = true;
			disable_pause_resume = false;
		}

		private void playlist_MouseUp(object sender, MouseEventArgs e)
		{

		}

		private void playlist_KeyUp(object sender, KeyEventArgs e)
		{


			ListViewItem coisa = playlist.SelectedItems[0];
			MP3.playlist_index = playlist.SelectedItems[0].Index;
			MP3.the_filename = coisa.SubItems[1].Text;
			

		}

		private void playlist_KeyDown(object sender, KeyEventArgs e)
		{
			

		}

		private void playlist_Click(object sender, EventArgs e)
		{

			ListViewItem coisa = playlist.SelectedItems[0];
			MP3.playlist_index = playlist.SelectedItems[0].Index;
			MP3.the_filename = coisa.SubItems[1].Text;

		}

		private void button27_Click(object sender, EventArgs e)
		{
			double p

				;

			try
			{
				p = double.Parse(sync_t.Text);
				MP3.AdjustSync(number, p);
			}
			catch
			{
				sync_t.Text = "0";
			}
		}

		private void open_v12_Click(object sender, EventArgs e)
		{
			button6_Click(null, null);
		}

		private void play_v12_Click(object sender, EventArgs e)
		{
			button4_Click(null, null);
		}

		private void pause_v12_Click(object sender, EventArgs e)
		{
			button7_Click(null, null);
		}

		private void resume_v12_Click(object sender, EventArgs e)
		{
			button5_Click(null, null);
		}

		private void cancel_v12_Click(object sender, EventArgs e)
		{
			button8_Click(null, null);
		}

		private void select_v12_Click(object sender, EventArgs e)
		{
			button2_Click(null, null);
		}

		private void play_v13_Click(object sender, EventArgs e)
		{
			play2_b_Click(null, null);
		}

		private void pause_v13_Click(object sender, EventArgs e)
		{
			pause2_b_Click(null, null);
		}

		private void resume_v13_Click(object sender, EventArgs e)
		{
			resume2_Click(null, null);
		}

		private void cancel_v13_Click(object sender, EventArgs e)
		{
			/*
				cancel2_Click(null, null);
			 */
			fullscreen_state_ = 0;
			video_p_MouseClick(null, null);
		}

		private void by_RSP_Software_Click(object sender, EventArgs e)
		{
			System.Diagnostics.Process.Start("https://arsoftware.net.br/binarywork/");
		}
		void PlaylistColumnClick(object sender, ColumnClickEventArgs e)
		{
			
			// Determine if clicked column is already the column that is being sorted.
			if (e.Column == lvwColumnSorter.SortColumn) {
				// Reverse the current sort direction for this column.
				if (lvwColumnSorter.Order == SortOrder.Ascending) {
					lvwColumnSorter.Order = SortOrder.Descending;
				} else {
					lvwColumnSorter.Order = SortOrder.Ascending;
				}
			} else {
				// Set the column number that is to be sorted; default to ascending.
				lvwColumnSorter.SortColumn = e.Column;
				lvwColumnSorter.Order = SortOrder.Ascending;
			}

			// Perform the sort with these new sort options.
			this.playlist.Sort();
		}
		void Koci_timerTick(object sender, EventArgs e)
		{
			string the_ring_k_p;
			MP3.GetSettings("new_filename_k_p", MP3.ricardo_koci_strb, util_amanda.amanda_pereira_empty_string_k_p);
			the_ring_k_p = MP3.ricardo_koci_strb.ToString();
			if("" != the_ring_k_p)
			{
				filename.Text = the_ring_k_p;
				MP3.SaveSettings("new_filename_k_p", util_amanda.amanda_pereira_empty_string_k_p);
				button4_Click(null, null);//easy way to play a file...
				
				//nao é muito complexo pra voce?!
				filetowav.Focus();
			}
		}
		void Progressbar_27_51_z_v21Mouse(amanda_progress.progressbar.ExtendedMouseEvent e)
		{
			MP3.SeekTo_10000(number, e.Value);
		}
		
		void File_lClick(object sender, EventArgs e)
		{
			filetowav .Text = "Z:/Ava/back/" + file_l.Text;
		}
		void Button2Click_amanda(object sender, EventArgs e)
		{
			int new_window_w = -1;
			int ret_arp_ = 0;
			bool adjust_me_please_i = false;
			if(false == mode_is_ricardo_window)
			{
				
				MP3.GetSettings("_i_amanda_initial_size_w", message, "502");
				new_window_w = int.Parse(message.ToString());
				adjust_me_please_i = true;
				ori_width  = this.Width;
				ori_height = this.Height;
				mode_is_ricardo_window = true;
				
			}
			
			//vamos lá
			(new Thread(new ThreadStart(my_thread_fullscreen_fix_p))).Start();
			can_scape_z = true;
			pause_state_ = 0;

			//double position = MP3.PlayBackPosition_AV_TIME_BASE(number);

			if (true)
			{
				fullscreen_state_ = 1;
				MP3.is_full_screen = true;

				this.WindowState = FormWindowState.Normal;
				this.FormBorderStyle = FormBorderStyle.Sizable;
				
				if(-1 == new_width)
					this.Width  = 502;
				
				if(-1 != new_window_w)
				{
					this.Width = new_window_w;
				}
				
				MP3.SaveSettings("_i_amanda_initial_size_w", this.Width.ToString());
				
				double calc_a = this.Width;
				double calc_h = calc_a;
				
				calc_h = calc_a / 1.7777777;
				
				this.Height = Convert.ToInt32(calc_h);
				
				fs.Enabled = true;
				
				double calc_c = 68;
				double calc_d = calc_c / 1.77777;
				
				video_p.Width  = Convert.ToInt32(calc_a - calc_c);
				video_p.Height = Convert.ToInt32(calc_h - calc_d);

				int p;

				p = ((this.Width - 20) - video_p.Width) / 2;

				video_p.Left = p + 3;

				video_p.Top = 0;

				background_p.Visible = true;
				background_p.Width = Screen.PrimaryScreen.Bounds.Width;
				background_p.Height = Screen.PrimaryScreen.Bounds.Height;
				background_p.Top = 0;
				background_p.Left = 0;
				background_p.BringToFront();
				
				if (1 == video_p.Height % 2)//these values always need to be a a multiple of 2
				{
					video_p.Height--;
				}
				if (1 == video_p.Width % 2)
				{
					video_p.Width--;
				}
				
				weird_timer.Enabled = true;
				MP3.PassWindowInformation
					(
						number,
						video_p.Handle.ToInt64(),
						video_f_p.Handle.ToInt64(),
						video_p.Width,
						video_p.Height,
						the_ratio,
						video_p.Left,
						video_p.Top
					)
					;

				fs.Enabled = true;
				
				progressbar_27_51_z_v21.Width = this.Width - 50;
				progressbar_27_51_z_v21.Left = 15;
				progressbar_27_51_z_v21.Top = this.Height - 90;
				this.TopMost = true;
				
				if(adjust_me_please_i)
				{
					
					MP3.GetSettings("_i_left_position", message, "-1");
					
					if("-1" == message.ToString())
					{
						;
					}
					else
					{
						try
						{
							ret_arp_ = int.Parse (message.ToString());
							
							if(ret_arp_ < 0)
							{
								MP3.SaveSettings("_i_left_position", "0");
							}
							
							
							if(ret_arp_ > Screen.PrimaryScreen.Bounds.Width)
							{
								MP3.SaveSettings("_i_left_position", "0");
							}
						}
						catch
						{
							MP3.SaveSettings("_i_left_position", "0");
						}
					}
					
					
					MP3.GetSettings("_i_top_position", message, "-1");
					
					if("-1" == message.ToString())
					{
						;
					}
					else
					{
						try
						{
							ret_arp_ = int.Parse (message.ToString());
							
							if(ret_arp_ < 0)
							{
								MP3.SaveSettings("_i_top_position", "0");
							}
														
							if(ret_arp_ > Screen.PrimaryScreen.Bounds.Height)
							{
								MP3.SaveSettings("_i_top_position", "0");
							}
						}
						catch
						{
							MP3.SaveSettings("_i_top_position", "0");
						}
					}
					
					MP3.GetSettings("_i_left_position", message, "-1");
					
					if("-1" == message.ToString())
					{
						
						this.Left = (Screen.PrimaryScreen.Bounds.Width  - this.Width ) / 2;
						this.Top  = (Screen.PrimaryScreen.Bounds.Height - this.Height) / 2;
						MP3.SaveSettings("_i_left_position", this.Left.ToString());
						MP3.SaveSettings("_i_top_position",  this.Top.ToString());
						
					}
					else
					{
						try
						{
							MP3.GetSettings("_i_left_position", message, "0");
							this.Left = int.Parse(message.ToString());
							MP3.GetSettings("_i_top_position", message, "0");
							this.Top = int.Parse(message.ToString());
						}
						catch
						{
							
						}
						
					}
				}
				else
				{
					MP3.SaveSettings("_i_left_position", this.Left.ToString());
					MP3.SaveSettings("_i_top_position",  this.Top.ToString());
				}
			}
		}
		void SampleResizeEnd(object sender, EventArgs e)
		{
			
			if(mode_is_ricardo_window)
			{
				new_width = this.Width;
				Button2Click_amanda(null, null);
				new_width = -1;
			}
		}
	}
}
