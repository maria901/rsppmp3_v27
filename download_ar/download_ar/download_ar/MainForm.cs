/*
 * Created by SharpDevelop.
 * User: Koci
 * Date: 05/12/2021
 * Time: 01:27
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using Microsoft.Win32;

namespace download_ar
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		public MainForm(string data1_,string data2_)
		{
			data1 = data1_;
			data2 = data2_;
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		string data1;
		string data2;
		
		int exit_code_andrea = 28;
		//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
		// these apis are for debug purposes only
		
		[DllImport("ffmpeg_v.DLL")]
		public static extern int
			download_ar_from_net(string filename_utf8, string dest_file_utf_8);
		
		[DllImport("ffmpeg_v.DLL")]
		public static extern int
			close_ar_and_deinit();
		
		[DllImport("ffmpeg_v.DLL")]
		public static extern int
			get_ar_returnvalue();
		
		[DllImport("ffmpeg_v.DLL")]
		public static extern int
			is_ar_running();
		
		[DllImport("ffmpeg_v.DLL")]
		public static extern int
			ar_progress();
		
		[DllImport("ffmpeg_v.DLL")]
		public static extern int
			ar_pause();
		
		[DllImport("ffmpeg_v.DLL")]
		public static extern int
			ar_resume();
		
		[DllImport("ffmpeg_v.DLL")]
		public static extern int
			ar_cancel();
		void Button1Click(object sender, EventArgs e)
		{
			
			int ret_ar = download_ar_from_net("https://arsoftware.net.br/mod_ffmpeg_v/ar_downloads/moustafa.mp3",
			                                  "C:\\Ava\\back\\a__restore\\amanda.mp3");
			
			if(0 == ret_ar)
			{
				timer1.Enabled = true;
			}
		}
		void Timer1Tick(object sender, EventArgs e)
		{
			
			int ret_ar ;
			
			ret_ar = is_ar_running();
			
			if(0 == ret_ar)
			{
				timer1.Enabled = false;
				this.Text = this.Text + "     finished";
				close_ar_and_deinit();
				exit_code_andrea = get_ar_returnvalue();
				//MessageBox .Show ("Aqui " + exit_code_andrea.ToString());
				Environment.Exit(exit_code_andrea);
				this.Close();
			}
			else
			{
				this.Text = (ar_progress() / 100).ToString() + "%";
			}
		}
		void MainFormLoad(object sender, EventArgs e)
		{
			
			if("" != data1)
			{
				//Button1Click(null, null);
				
				int ret_ar = download_ar_from_net
					(data1,
					 data2);
				
				if(0 == ret_ar)
				{
					
					timer1.Enabled = true;
				}
			}
		}
		void MainFormFormClosing(object sender, FormClosingEventArgs e)
		{
			Environment.Exit(exit_code_andrea);
		}
		
	}
}
