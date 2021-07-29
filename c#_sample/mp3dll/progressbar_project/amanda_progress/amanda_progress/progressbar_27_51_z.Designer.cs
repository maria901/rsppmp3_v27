/* designer 27 51 z
 * Created by BW.
 * User: AAKP
 * Date: 07/04/2021
 * Time: 20:54
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace amanda_progress
{
	partial class progressbar_27_51_z
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
			this.fixo_z = new RoundCorneredProgressBar.RoundCorneredProgressBar();
			((System.ComponentModel.ISupportInitialize)(this.fixo_z)).BeginInit();
			this.SuspendLayout();
			// 
			// fixo_z
			// 
			this.fixo_z.BackColor = System.Drawing.SystemColors.ButtonShadow;
			this.fixo_z.Location = new System.Drawing.Point(20, 20);
			this.fixo_z.Name = "fixo_z";
			this.fixo_z.ProgressBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
			this.fixo_z.ProgressBarColor = System.Drawing.Color.Lime;
			this.fixo_z.ProgressFont = new System.Drawing.Font("Microsoft Sans Serif", 35.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.fixo_z.ProgressFontColor = System.Drawing.Color.Black;
			this.fixo_z.Size = new System.Drawing.Size(200, 27);
			this.fixo_z.TabIndex = 2;
			this.fixo_z.TabStop = false;
			this.fixo_z.Value = 100;
			// 
			// progressbar_27_51_z
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.Controls.Add(this.fixo_z);
			this.Name = "progressbar_27_51_z";
			this.Size = new System.Drawing.Size(250, 63);
			this.Load += new System.EventHandler(this.Progressbar_27_51_zLoad);
			((System.ComponentModel.ISupportInitialize)(this.fixo_z)).EndInit();
			this.ResumeLayout(false);

		}
	}
}
