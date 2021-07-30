namespace mp3dll
{
    partial class normalize
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
        	System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(normalize));
        	this.otffast = new System.Windows.Forms.CheckBox();
        	this.checkBox1 = new System.Windows.Forms.CheckBox();
        	this.benormalize_ch = new System.Windows.Forms.CheckBox();
        	this.SuspendLayout();
        	// 
        	// otffast
        	// 
        	this.otffast.AutoSize = true;
        	this.otffast.Location = new System.Drawing.Point(12, 58);
        	this.otffast.Name = "otffast";
        	this.otffast.Size = new System.Drawing.Size(199, 17);
        	this.otffast.TabIndex = 0;
        	this.otffast.Text = "On the fly normalization (ReplayGain)";
        	this.otffast.UseVisualStyleBackColor = true;
        	this.otffast.MouseUp += new System.Windows.Forms.MouseEventHandler(this.otffast_MouseUp);
        	// 
        	// checkBox1
        	// 
        	this.checkBox1.AutoSize = true;
        	this.checkBox1.Location = new System.Drawing.Point(12, 35);
        	this.checkBox1.Name = "checkBox1";
        	this.checkBox1.Size = new System.Drawing.Size(225, 17);
        	this.checkBox1.TabIndex = 1;
        	this.checkBox1.Text = "On the fly normalization (ReplayGain) (fast)";
        	this.checkBox1.UseVisualStyleBackColor = true;
        	this.checkBox1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.checkBox1_MouseUp);
        	// 
        	// benormalize_ch
        	// 
        	this.benormalize_ch.AutoSize = true;
        	this.benormalize_ch.Location = new System.Drawing.Point(12, 12);
        	this.benormalize_ch.Name = "benormalize_ch";
        	this.benormalize_ch.Size = new System.Drawing.Size(280, 17);
        	this.benormalize_ch.TabIndex = 2;
        	this.benormalize_ch.Text = "On the fly normalization (BENormalize) (recommended)";
        	this.benormalize_ch.UseVisualStyleBackColor = true;
        	this.benormalize_ch.MouseUp += new System.Windows.Forms.MouseEventHandler(this.benormalize_ch_MouseUp);
        	// 
        	// normalize
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.ClientSize = new System.Drawing.Size(299, 87);
        	this.Controls.Add(this.benormalize_ch);
        	this.Controls.Add(this.checkBox1);
        	this.Controls.Add(this.otffast);
        	this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
        	this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
        	this.MaximizeBox = false;
        	this.Name = "normalize";
        	this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
        	this.Text = "Normalize";
        	this.TopMost = true;
        	this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.NormalizeFormClosing);
        	this.Load += new System.EventHandler(this.normalize_Load);
        	this.ResumeLayout(false);
        	this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox otffast;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.CheckBox benormalize_ch;
    }
}