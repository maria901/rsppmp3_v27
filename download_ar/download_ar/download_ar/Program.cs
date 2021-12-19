/*
 * Created by SharpDevelop.
 * User: Koci
 * Date: 05/12/2021
 * Time: 01:27
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Windows.Forms;

namespace download_ar
{
	/// <summary>
	/// Class with program entry point.
	/// </summary>
	internal sealed class Program
	{
		/// <summary>
		/// Program entry point.
		/// </summary>
		[STAThread]
		private static void Main(string[] args)
		{
			string data1 = "";
			string data2 = "";
			try
			{
				data1 = args[0];
				data2 = args[1];
			}
			catch
			{
				data1 = "";
				data2 = "";
			}
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new MainForm(data1, data2));
		}
		
	}
}
