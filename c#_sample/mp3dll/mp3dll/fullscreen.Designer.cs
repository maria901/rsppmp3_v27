namespace mp3dll
{
    partial class fullscreen
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
            this.background_p = new System.Windows.Forms.PictureBox();
            this.video_f_p = new System.Windows.Forms.PictureBox();
            this.video_p = new System.Windows.Forms.PictureBox();
            this.cancel2 = new System.Windows.Forms.Button();
            this.pause2_b = new System.Windows.Forms.Button();
            this.resume2 = new System.Windows.Forms.Button();
            this.play2_b = new System.Windows.Forms.Button();
            this.progressbar1 = new mp3dll.progressbar();
            ((System.ComponentModel.ISupportInitialize)(this.background_p)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.video_f_p)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.video_p)).BeginInit();
            this.SuspendLayout();
            // 
            // background_p
            // 
            this.background_p.BackColor = System.Drawing.Color.Black;
            this.background_p.Image = global::mp3dll.Properties.Resources.vazio;
            this.background_p.Location = new System.Drawing.Point(429, 191);
            this.background_p.Name = "background_p";
            this.background_p.Size = new System.Drawing.Size(30, 30);
            this.background_p.TabIndex = 108;
            this.background_p.TabStop = false;
            this.background_p.Visible = false;
            // 
            // video_f_p
            // 
            this.video_f_p.BackColor = System.Drawing.Color.Black;
            this.video_f_p.Cursor = System.Windows.Forms.Cursors.Hand;
            this.video_f_p.Location = new System.Drawing.Point(200, 200);
            this.video_f_p.Name = "video_f_p";
            this.video_f_p.Size = new System.Drawing.Size(89, 53);
            this.video_f_p.TabIndex = 107;
            this.video_f_p.TabStop = false;
            // 
            // video_p
            // 
            this.video_p.BackColor = System.Drawing.Color.Black;
            this.video_p.Cursor = System.Windows.Forms.Cursors.Hand;
            this.video_p.Location = new System.Drawing.Point(79, 79);
            this.video_p.Name = "video_p";
            this.video_p.Size = new System.Drawing.Size(453, 241);
            this.video_p.TabIndex = 106;
            this.video_p.TabStop = false;
            // 
            // cancel2
            // 
            this.cancel2.Location = new System.Drawing.Point(275, 209);
            this.cancel2.Name = "cancel2";
            this.cancel2.Size = new System.Drawing.Size(77, 35);
            this.cancel2.TabIndex = 113;
            this.cancel2.Text = "Cancel";
            this.cancel2.UseVisualStyleBackColor = true;
            this.cancel2.Visible = false;
            // 
            // pause2_b
            // 
            this.pause2_b.Location = new System.Drawing.Point(109, 208);
            this.pause2_b.Name = "pause2_b";
            this.pause2_b.Size = new System.Drawing.Size(77, 35);
            this.pause2_b.TabIndex = 112;
            this.pause2_b.Text = "Pause";
            this.pause2_b.UseVisualStyleBackColor = true;
            this.pause2_b.Visible = false;
            // 
            // resume2
            // 
            this.resume2.Location = new System.Drawing.Point(192, 209);
            this.resume2.Name = "resume2";
            this.resume2.Size = new System.Drawing.Size(77, 35);
            this.resume2.TabIndex = 111;
            this.resume2.Text = "Resume";
            this.resume2.UseVisualStyleBackColor = true;
            this.resume2.Visible = false;
            // 
            // play2_b
            // 
            this.play2_b.Location = new System.Drawing.Point(26, 208);
            this.play2_b.Name = "play2_b";
            this.play2_b.Size = new System.Drawing.Size(77, 35);
            this.play2_b.TabIndex = 110;
            this.play2_b.Text = "Play";
            this.play2_b.UseVisualStyleBackColor = true;
            this.play2_b.Visible = false;
            // 
            // progressbar1
            // 
            this.progressbar1.Location = new System.Drawing.Point(24, 253);
            this.progressbar1.Maximum = 10000;
            this.progressbar1.Name = "progressbar1";
            this.progressbar1.Size = new System.Drawing.Size(669, 21);
            this.progressbar1.TabIndex = 109;
            this.progressbar1.Value = 0;
            // 
            // fullscreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(716, 483);
            this.Controls.Add(this.cancel2);
            this.Controls.Add(this.pause2_b);
            this.Controls.Add(this.resume2);
            this.Controls.Add(this.play2_b);
            this.Controls.Add(this.progressbar1);
            this.Controls.Add(this.background_p);
            this.Controls.Add(this.video_f_p);
            this.Controls.Add(this.video_p);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "fullscreen";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "fullscreen";
            this.Load += new System.EventHandler(this.fullscreen_Load);
            ((System.ComponentModel.ISupportInitialize)(this.background_p)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.video_f_p)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.video_p)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox background_p;
        private System.Windows.Forms.PictureBox video_f_p;
        private System.Windows.Forms.PictureBox video_p;
        private System.Windows.Forms.Button cancel2;
        private System.Windows.Forms.Button pause2_b;
        private System.Windows.Forms.Button resume2;
        private System.Windows.Forms.Button play2_b;
        private progressbar progressbar1;
    }
}