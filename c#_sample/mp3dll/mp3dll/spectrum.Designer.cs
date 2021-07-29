/// <summary>
/// 
/// </summary>
namespace mp3dll
{
    partial class spectrum
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
        	this.components = new System.ComponentModel.Container();
        	System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(spectrum));
        	this.timer = new System.Windows.Forms.Timer(this.components);
        	this.enable = new System.Windows.Forms.CheckBox();
        	this.label1 = new System.Windows.Forms.Label();
        	this.label2 = new System.Windows.Forms.Label();
        	this.label3 = new System.Windows.Forms.Label();
        	this.label4 = new System.Windows.Forms.Label();
        	this.label5 = new System.Windows.Forms.Label();
        	this.label6 = new System.Windows.Forms.Label();
        	this.label7 = new System.Windows.Forms.Label();
        	this.label8 = new System.Windows.Forms.Label();
        	this.label9 = new System.Windows.Forms.Label();
        	this.label10 = new System.Windows.Forms.Label();
        	this.label11 = new System.Windows.Forms.Label();
        	this.progressbar1 = new amanda_progress.progressbar();
        	this.progressbar2 = new amanda_progress.progressbar();
        	this.progressbar3 = new amanda_progress.progressbar();
        	this.progressbar4 = new amanda_progress.progressbar();
        	this.progressbar5 = new amanda_progress.progressbar();
        	this.progressbar6 = new amanda_progress.progressbar();
        	this.progressbar7 = new amanda_progress.progressbar();
        	this.progressbar8 = new amanda_progress.progressbar();
        	this.progressbar9 = new amanda_progress.progressbar();
        	this.progressbar10 = new amanda_progress.progressbar();
        	this.progressbar11 = new amanda_progress.progressbar();
        	this.SuspendLayout();
        	// 
        	// timer
        	// 
        	this.timer.Enabled = true;
        	this.timer.Interval = 40;
        	this.timer.Tick += new System.EventHandler(this.timer_Tick);
        	// 
        	// enable
        	// 
        	this.enable.AutoSize = true;
        	this.enable.Checked = true;
        	this.enable.CheckState = System.Windows.Forms.CheckState.Checked;
        	this.enable.Location = new System.Drawing.Point(83, 354);
        	this.enable.Name = "enable";
        	this.enable.Size = new System.Drawing.Size(59, 17);
        	this.enable.TabIndex = 11;
        	this.enable.Text = "Enable";
        	this.enable.UseVisualStyleBackColor = true;
        	this.enable.MouseUp += new System.Windows.Forms.MouseEventHandler(this.checkBox1_MouseUp);
        	// 
        	// label1
        	// 
        	this.label1.AutoSize = true;
        	this.label1.Location = new System.Drawing.Point(30, 320);
        	this.label1.Name = "label1";
        	this.label1.Size = new System.Drawing.Size(32, 13);
        	this.label1.TabIndex = 12;
        	this.label1.Text = "Peak";
        	// 
        	// label2
        	// 
        	this.label2.AutoSize = true;
        	this.label2.Location = new System.Drawing.Point(30, 31);
        	this.label2.Name = "label2";
        	this.label2.Size = new System.Drawing.Size(41, 13);
        	this.label2.TabIndex = 13;
        	this.label2.Text = "60 Hz";
        	// 
        	// label3
        	// 
        	this.label3.AutoSize = true;
        	this.label3.Location = new System.Drawing.Point(30, 56);
        	this.label3.Name = "label3";
        	this.label3.Size = new System.Drawing.Size(41, 13);
        	this.label3.TabIndex = 14;
        	this.label3.Text = "170 Hz";
        	// 
        	// label4
        	// 
        	this.label4.AutoSize = true;
        	this.label4.Location = new System.Drawing.Point(30, 82);
        	this.label4.Name = "label4";
        	this.label4.Size = new System.Drawing.Size(41, 13);
        	this.label4.TabIndex = 15;
        	this.label4.Text = "310 Hz";
        	// 
        	// label5
        	// 
        	this.label5.AutoSize = true;
        	this.label5.Location = new System.Drawing.Point(30, 108);
        	this.label5.Name = "label5";
        	this.label5.Size = new System.Drawing.Size(41, 13);
        	this.label5.TabIndex = 16;
        	this.label5.Text = "600 Hz";
        	// 
        	// label6
        	// 
        	this.label6.AutoSize = true;
        	this.label6.Location = new System.Drawing.Point(30, 134);
        	this.label6.Name = "label6";
        	this.label6.Size = new System.Drawing.Size(41, 13);
        	this.label6.TabIndex = 17;
        	this.label6.Text = "1 KHz";
        	// 
        	// label7
        	// 
        	this.label7.AutoSize = true;
        	this.label7.Location = new System.Drawing.Point(30, 160);
        	this.label7.Name = "label7";
        	this.label7.Size = new System.Drawing.Size(41, 13);
        	this.label7.TabIndex = 18;
        	this.label7.Text = "3 KHz";
        	// 
        	// label8
        	// 
        	this.label8.AutoSize = true;
        	this.label8.Location = new System.Drawing.Point(30, 187);
        	this.label8.Name = "label8";
        	this.label8.Size = new System.Drawing.Size(41, 13);
        	this.label8.TabIndex = 19;
        	this.label8.Text = "6 KHz";
        	// 
        	// label9
        	// 
        	this.label9.AutoSize = true;
        	this.label9.Location = new System.Drawing.Point(30, 212);
        	this.label9.Name = "label9";
        	this.label9.Size = new System.Drawing.Size(41, 13);
        	this.label9.TabIndex = 20;
        	this.label9.Text = "12 KHz";
        	// 
        	// label10
        	// 
        	this.label10.AutoSize = true;
        	this.label10.Location = new System.Drawing.Point(30, 238);
        	this.label10.Name = "label10";
        	this.label10.Size = new System.Drawing.Size(41, 13);
        	this.label10.TabIndex = 21;
        	this.label10.Text = "14 KHz";
        	// 
        	// label11
        	// 
        	this.label11.AutoSize = true;
        	this.label11.Location = new System.Drawing.Point(30, 264);
        	this.label11.Name = "label11";
        	this.label11.Size = new System.Drawing.Size(41, 13);
        	this.label11.TabIndex = 22;
        	this.label11.Text = "16 KHz";
        	// 
        	// progressbar1
        	// 
        	this.progressbar1.Location = new System.Drawing.Point(83, 27);
        	this.progressbar1.Maximum = 100;
        	this.progressbar1.Name = "progressbar1";
        	this.progressbar1.Size = new System.Drawing.Size(248, 20);
        	this.progressbar1.TabIndex = 75;
        	this.progressbar1.Value = 0;
        	// 
        	// progressbar2
        	// 
        	this.progressbar2.Location = new System.Drawing.Point(83, 261);
        	this.progressbar2.Maximum = 100;
        	this.progressbar2.Name = "progressbar2";
        	this.progressbar2.Size = new System.Drawing.Size(248, 20);
        	this.progressbar2.TabIndex = 76;
        	this.progressbar2.Value = 0;
        	// 
        	// progressbar3
        	// 
        	this.progressbar3.Location = new System.Drawing.Point(83, 131);
        	this.progressbar3.Maximum = 100;
        	this.progressbar3.Name = "progressbar3";
        	this.progressbar3.Size = new System.Drawing.Size(248, 20);
        	this.progressbar3.TabIndex = 77;
        	this.progressbar3.Value = 0;
        	// 
        	// progressbar4
        	// 
        	this.progressbar4.Location = new System.Drawing.Point(83, 157);
        	this.progressbar4.Maximum = 100;
        	this.progressbar4.Name = "progressbar4";
        	this.progressbar4.Size = new System.Drawing.Size(248, 20);
        	this.progressbar4.TabIndex = 78;
        	this.progressbar4.Value = 0;
        	// 
        	// progressbar5
        	// 
        	this.progressbar5.Location = new System.Drawing.Point(83, 317);
        	this.progressbar5.Maximum = 100;
        	this.progressbar5.Name = "progressbar5";
        	this.progressbar5.Size = new System.Drawing.Size(248, 20);
        	this.progressbar5.TabIndex = 79;
        	this.progressbar5.Value = 0;
        	// 
        	// progressbar6
        	// 
        	this.progressbar6.Location = new System.Drawing.Point(83, 235);
        	this.progressbar6.Maximum = 100;
        	this.progressbar6.Name = "progressbar6";
        	this.progressbar6.Size = new System.Drawing.Size(248, 20);
        	this.progressbar6.TabIndex = 80;
        	this.progressbar6.Value = 0;
        	// 
        	// progressbar7
        	// 
        	this.progressbar7.Location = new System.Drawing.Point(83, 209);
        	this.progressbar7.Maximum = 100;
        	this.progressbar7.Name = "progressbar7";
        	this.progressbar7.Size = new System.Drawing.Size(248, 20);
        	this.progressbar7.TabIndex = 81;
        	this.progressbar7.Value = 0;
        	// 
        	// progressbar8
        	// 
        	this.progressbar8.Location = new System.Drawing.Point(83, 183);
        	this.progressbar8.Maximum = 100;
        	this.progressbar8.Name = "progressbar8";
        	this.progressbar8.Size = new System.Drawing.Size(248, 20);
        	this.progressbar8.TabIndex = 82;
        	this.progressbar8.Value = 0;
        	// 
        	// progressbar9
        	// 
        	this.progressbar9.Location = new System.Drawing.Point(83, 105);
        	this.progressbar9.Maximum = 100;
        	this.progressbar9.Name = "progressbar9";
        	this.progressbar9.Size = new System.Drawing.Size(248, 20);
        	this.progressbar9.TabIndex = 83;
        	this.progressbar9.Value = 0;
        	// 
        	// progressbar10
        	// 
        	this.progressbar10.Location = new System.Drawing.Point(83, 79);
        	this.progressbar10.Maximum = 100;
        	this.progressbar10.Name = "progressbar10";
        	this.progressbar10.Size = new System.Drawing.Size(248, 20);
        	this.progressbar10.TabIndex = 84;
        	this.progressbar10.Value = 0;
        	// 
        	// progressbar11
        	// 
        	this.progressbar11.Location = new System.Drawing.Point(83, 53);
        	this.progressbar11.Maximum = 100;
        	this.progressbar11.Name = "progressbar11";
        	this.progressbar11.Size = new System.Drawing.Size(248, 20);
        	this.progressbar11.TabIndex = 85;
        	this.progressbar11.Value = 0;
        	// 
        	// spectrum
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.ClientSize = new System.Drawing.Size(397, 395);
        	this.Controls.Add(this.progressbar11);
        	this.Controls.Add(this.progressbar10);
        	this.Controls.Add(this.progressbar9);
        	this.Controls.Add(this.progressbar8);
        	this.Controls.Add(this.progressbar7);
        	this.Controls.Add(this.progressbar6);
        	this.Controls.Add(this.progressbar5);
        	this.Controls.Add(this.progressbar4);
        	this.Controls.Add(this.progressbar3);
        	this.Controls.Add(this.progressbar2);
        	this.Controls.Add(this.progressbar1);
        	this.Controls.Add(this.label11);
        	this.Controls.Add(this.label10);
        	this.Controls.Add(this.label9);
        	this.Controls.Add(this.label8);
        	this.Controls.Add(this.label7);
        	this.Controls.Add(this.label6);
        	this.Controls.Add(this.label5);
        	this.Controls.Add(this.label4);
        	this.Controls.Add(this.label3);
        	this.Controls.Add(this.label2);
        	this.Controls.Add(this.label1);
        	this.Controls.Add(this.enable);
        	this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
        	this.Name = "spectrum";
        	this.Text = "Spectrum analizer";
        	this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.SpectrumFormClosing);
        	this.Load += new System.EventHandler(this.spectrum_Load);
        	this.ResumeLayout(false);
        	this.PerformLayout();

        }

        #endregion
       
        private System.Windows.Forms.Timer timer;
        private System.Windows.Forms.CheckBox enable;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private amanda_progress.progressbar progressbar1;
        private amanda_progress.progressbar progressbar2;
        private amanda_progress.progressbar progressbar3;
        private amanda_progress.progressbar progressbar4;
        private amanda_progress.progressbar progressbar5;
        private amanda_progress.progressbar progressbar6;
        private amanda_progress.progressbar progressbar7;
        private amanda_progress.progressbar progressbar8;
        private amanda_progress.progressbar progressbar9;
        private amanda_progress.progressbar progressbar10;
        private amanda_progress.progressbar progressbar11;
    }
}