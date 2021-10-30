/* designer sample 1 amor
 * Created by SharpDevelop.
 * User: AAKP
 * Date: 07/04/2021
 * Time: 22:01
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace amanda_progress
{
	partial class Sample_z
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private amanda_progress.progressbar progressbar1;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.progressbar1 = new amanda_progress.progressbar();
			this.SuspendLayout();
			// 
			// progressbar1
			// 
			this.progressbar1.Location = new System.Drawing.Point(12, 12);
			this.progressbar1.Maximum = 10000;
			this.progressbar1.Name = "progressbar1";
			this.progressbar1.Size = new System.Drawing.Size(218, 163);
			this.progressbar1.TabIndex = 0;
			this.progressbar1.Value = 500;
			// 
			// Sample_z
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 262);
			this.Controls.Add(this.progressbar1);
			this.Name = "Sample_z";
			this.Text = "Sample_z";
			this.ResumeLayout(false);

		}
	}
}
