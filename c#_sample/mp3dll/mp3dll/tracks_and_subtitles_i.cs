/*
 * Created by SharpDevelop.
 * User: Koci
 * Date: 07/08/2021
 * Time: 20:56
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Drawing;
using System.Windows.Forms;

namespace mp3dll
{
	/// <summary>
	/// Description of tracks_and_subtitles_i.
	/// </summary>
	public partial class tracks_and_subtitles_i : Form
	{
		public tracks_and_subtitles_i()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		void Tracks_and_subtitles_iLoad(object sender, EventArgs e)
		{
			
		}
		void Audio_get_iClick(object sender, EventArgs e)
		{
			int ret;
			ret = MP3.GetNumberOfAudioTracks(MP3.sample_copy_i.number, MP3.wide2utf8(MP3.sample_copy_i.filename.Text), MP3.sample_copy_i.message);
			if (ret < 0)
			{
				MP3.sample_copy_i.morcego_error.Items.Add(ret + " - " + MP3.sample_copy_i.message.ToString());
				MP3.sample_copy_i.morcego_error.SelectedIndex = MP3.sample_copy_i.morcego_error.Items.Count - 1;
			}
			else
			{

				if (0 == ret)
				{
					track.Text           = "1";//default to track 1, as you may expect and me too
					MP3.selected_track_i =  1 ;
				}
				else
				{
					
					track.Items.Clear();
					for (int i = -1; i < ret; i++)
					{
						track.Items.Add((i + 1).ToString());
					}
					track.Text           =  "1";
					MP3.selected_track_i =   1 ;
				}

			}
		}
		void TrackSelectedIndexChanged(object sender, EventArgs e)
		{
			try
			{
				MP3.selected_track_i =  int.Parse(track.Text);
			}
			catch
			{
				MP3.selected_track_i = 1;
			}			
		}
		void Get_subtitles_iClick(object sender, EventArgs e)
		{
			int ret;
			ret = MP3.GetNumberOfSubtitles(MP3.sample_copy_i.number, MP3.wide2utf8(MP3.sample_copy_i.filename.Text), MP3.sample_copy_i.message);
			if (ret < 0)
			{
				MP3.sample_copy_i.morcego_error.Items.Add(ret + " - " + MP3.sample_copy_i.message.ToString());
				MP3.sample_copy_i.morcego_error.SelectedIndex = MP3.sample_copy_i.morcego_error.Items.Count - 1;
			}
			else
			{

				if (0 == ret)
				{
					subtitle_i.Text               = "0";//default to track 0 (none), as you may expect and me too
					MP3.selected_subtitle_track_i =  0 ;
				}
				else
				{
					
					subtitle_i.Items.Clear();
					for (int i = -1; i < ret; i++)
					{
						subtitle_i.Items.Add((i + 1).ToString());
					}
					subtitle_i.Text               =  "0";
					MP3.selected_subtitle_track_i =   0 ;
				}

			}
		}
		void Subtitle_iSelectedIndexChanged(object sender, EventArgs e)
		{
			
			try
			{
				MP3.selected_subtitle_track_i =  int.Parse(subtitle_i.Text);
			}
			catch
			{
				MP3.selected_subtitle_track_i = 1;
			}
		}
		void Button1Click(object sender, EventArgs e)
		{
			;//
			
			int ret_ar = MP3.download_ar_from_net("https://arsoftware.net.br/mod_ffmpeg_v/ar_downloads/moustafa.mp3",
			                         "C:\\Ava\\back\\a__restore\\amanda.mp3");
			
			if(0 == ret_ar)
			{
				ar_timer.Enabled = true;
			}
			
		}
		void Ar_timerTick(object sender, EventArgs e)
		{
	
			int ret_ar ;
			
			ret_ar = MP3.is_ar_running();
			
			if(0 == ret_ar)
			{
				ar_timer.Enabled = false;
				this.Text = this.Text + "     finished";
				MP3.close_ar_and_deinit();
			}
			else
			{
				this.Text = MP3.ar_progress().ToString();
			}
			
		}
	}
}
