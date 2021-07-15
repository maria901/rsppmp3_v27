/* designer 27 51 z
 * Created by BW.
 * User: AAKP
 * Date: 07/04/2021
 * Time: 20:54
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace amanda_progress2
{
	partial class progressbar_27_51_z_v2
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the control.
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
		private RoundCorneredProgressBar.RoundCorneredProgressBar fixo_z;
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(progressbar_27_51_z_v2));
			this.fixo_z = new RoundCorneredProgressBar.RoundCorneredProgressBar();
			((System.ComponentModel.ISupportInitialize)(this.fixo_z)).BeginInit();
			this.SuspendLayout();
			// 
			// fixo_z
			// 
			this.fixo_z.BackColor = System.Drawing.Color.LightSteelBlue;
			this.fixo_z.Image = ((System.Drawing.Image)(resources.GetObject("fixo_z.Image")));
			this.fixo_z.Location = new System.Drawing.Point(20, 20);
			this.fixo_z.Maximum = 10000;
			this.fixo_z.Name = "fixo_z";
			this.fixo_z.ProgressBackColor = System.Drawing.Color.LightSteelBlue;
			this.fixo_z.ProgressBarColor = System.Drawing.Color.RoyalBlue;
			this.fixo_z.ProgressFont = new System.Drawing.Font("Microsoft Sans Serif", 35.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.fixo_z.ProgressFontColor = System.Drawing.Color.Black;
			this.fixo_z.Size = new System.Drawing.Size(200, 27);
			this.fixo_z.TabIndex = 2;
			this.fixo_z.TabStop = false;
			this.fixo_z.Value_z = 0;
			this.fixo_z.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Fixo_zMouseDown);
			// 
			// progressbar_27_51_z_v2
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.Controls.Add(this.fixo_z);
			this.Name = "progressbar_27_51_z_v2";
			this.Size = new System.Drawing.Size(251, 63);
			this.Load += new System.EventHandler(this.Progressbar_27_51_zLoad);
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Progressbar_27_51_z_v2MouseDown);
			this.Resize += new System.EventHandler(this.Progressbar_27_51_z_v2Resize);
			((System.ComponentModel.ISupportInitialize)(this.fixo_z)).EndInit();
			this.ResumeLayout(false);

		}
	}
}
