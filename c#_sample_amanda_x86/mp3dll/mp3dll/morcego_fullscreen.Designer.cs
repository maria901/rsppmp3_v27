namespace mp3dll
{
    partial class morcego_fullscreen
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
            this.video_f_p = new System.Windows.Forms.PictureBox();
            this.video_p = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.video_f_p)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.video_p)).BeginInit();
            this.SuspendLayout();
            // 
            // video_f_p
            // 
            this.video_f_p.BackColor = System.Drawing.Color.Black;
            this.video_f_p.Cursor = System.Windows.Forms.Cursors.Hand;
            this.video_f_p.Location = new System.Drawing.Point(-83, -47);
            this.video_f_p.Name = "video_f_p";
            this.video_f_p.Size = new System.Drawing.Size(220, 162);
            this.video_f_p.TabIndex = 84;
            this.video_f_p.TabStop = false;
            // 
            // video_p
            // 
            this.video_p.BackColor = System.Drawing.Color.Black;
            this.video_p.Cursor = System.Windows.Forms.Cursors.Hand;
            this.video_p.Location = new System.Drawing.Point(-231, -80);
            this.video_p.Name = "video_p";
            this.video_p.Size = new System.Drawing.Size(610, 360);
            this.video_p.TabIndex = 83;
            this.video_p.TabStop = false;
            this.video_p.Click += new System.EventHandler(this.video_p_Click);
            // 
            // morcego_fullscreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(512, 394);
            this.Controls.Add(this.video_f_p);
            this.Controls.Add(this.video_p);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "morcego_fullscreen";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "morcego_fullscreen";
            this.Load += new System.EventHandler(this.morcego_fullscreen_Load);
            ((System.ComponentModel.ISupportInitialize)(this.video_f_p)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.video_p)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox video_f_p;
        private System.Windows.Forms.PictureBox video_p;
    }
}