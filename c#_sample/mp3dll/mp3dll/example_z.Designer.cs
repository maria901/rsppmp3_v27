/* example designer ...
 * Created by SharpDevelop.
 * User: AAKP
 * Date: 07/04/2021
 * Time: 20:35
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace mp3dll
{
	partial class example_z
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private amanda_progress2.progressbar_27_51_z_v2 prog_z;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;
		private amanda_progress2.progressbar_27_51_z_v2 progressbar_27_51_z_v21;
				
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
		/// 
		
        private void InitializeComponent()
		{
			this.prog_z = new amanda_progress2.progressbar_27_51_z_v2();
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.progressbar_27_51_z_v21 = new amanda_progress2.progressbar_27_51_z_v2();
			this.SuspendLayout();
			// 
			// prog_z
			// 
			this.prog_z.BackColor = System.Drawing.Color.LightSteelBlue;
			this.prog_z.Location = new System.Drawing.Point(79, 86);
			this.prog_z.Maximum__z = 10000;
			this.prog_z.Name = "prog_z";
			this.prog_z.Size = new System.Drawing.Size(194, 10);
			this.prog_z.TabIndex = 0;
			this.prog_z.UseRoundedCorners_z = false;
			this.prog_z.Value__z = 0;
			this.prog_z.Mouse_z += new amanda_progress2.progressbar_27_51_z_v2.NewMouseEvent(this.Prog_zMouse_z);
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(356, 90);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(135, 51);
			this.button1.TabIndex = 1;
			this.button1.Text = "button1";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(356, 147);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(135, 51);
			this.button2.TabIndex = 2;
			this.button2.Text = "button2";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// progressbar_27_51_z_v21
			// 
			this.progressbar_27_51_z_v21.BackColor = System.Drawing.Color.LightSteelBlue;
			this.progressbar_27_51_z_v21.Location = new System.Drawing.Point(120, 185);
			this.progressbar_27_51_z_v21.Maximum__z = 10000;
			this.progressbar_27_51_z_v21.Name = "progressbar_27_51_z_v21";
			this.progressbar_27_51_z_v21.Size = new System.Drawing.Size(165, 52);
			this.progressbar_27_51_z_v21.TabIndex = 3;
			this.progressbar_27_51_z_v21.UseRoundedCorners_z = false;
			this.progressbar_27_51_z_v21.Value__z = 0;
			// 
			// example_z
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(691, 412);
			this.Controls.Add(this.progressbar_27_51_z_v21);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.prog_z);
			this.Name = "example_z";
			this.Text = "example_z";
			this.Load += new System.EventHandler(this.Example_zLoad);
			this.ResumeLayout(false);

		}
	}
}
