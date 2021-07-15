/*
 * Created by SharpDevelop.
 * User: AAKP
 * Date: 07/04/2021
 * Time: 20:54
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace amanda_progress
{
	/// <summary>
	/// Description of progressbar_27_51_z.
	/// </summary>
	public partial class progressbar_27_51_z : UserControl
	{
		public progressbar_27_51_z()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		void Progressbar_27_51_zLoad(object sender, EventArgs e)
		{
			fixo_z.Left = 0;
			fixo_z.Top = 0;
			fixo_z.Width = this.Width;
			fixo_z.Height = this.Height;
			fixo_z.Animate();
		}
	}
}
