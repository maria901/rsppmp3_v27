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
		
	}
}
