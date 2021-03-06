namespace mp3dll
{
    partial class wave_effects
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
        	System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(wave_effects));
        	this.soundtouch = new System.Windows.Forms.CheckBox();
        	this.rate = new System.Windows.Forms.TrackBar();
        	this.tempo = new System.Windows.Forms.TrackBar();
        	this.pitch = new System.Windows.Forms.TrackBar();
        	this.label2 = new System.Windows.Forms.Label();
        	this.label3 = new System.Windows.Forms.Label();
        	this.label4 = new System.Windows.Forms.Label();
        	this.button1 = new System.Windows.Forms.Button();
        	this.voice = new System.Windows.Forms.CheckBox();
        	this.echo = new System.Windows.Forms.CheckBox();
        	this.surround = new System.Windows.Forms.CheckBox();
        	this.surround2 = new System.Windows.Forms.CheckBox();
        	this.svalue = new System.Windows.Forms.TrackBar();
        	this.freeverb = new System.Windows.Forms.CheckBox();
        	this.samararicardo_linkLabel1 = new System.Windows.Forms.LinkLabel();
        	((System.ComponentModel.ISupportInitialize)(this.rate)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.tempo)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.pitch)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.svalue)).BeginInit();
        	this.SuspendLayout();
        	// 
        	// soundtouch
        	// 
        	this.soundtouch.AutoSize = true;
        	this.soundtouch.Location = new System.Drawing.Point(486, 16);
        	this.soundtouch.Name = "soundtouch";
        	this.soundtouch.Size = new System.Drawing.Size(124, 17);
        	this.soundtouch.TabIndex = 0;
        	this.soundtouch.Text = "Enable SoundTouch";
        	this.soundtouch.UseVisualStyleBackColor = true;
        	this.soundtouch.MouseUp += new System.Windows.Forms.MouseEventHandler(this.soundtouch_MouseUp);
        	// 
        	// rate
        	// 
        	this.rate.Location = new System.Drawing.Point(527, 121);
        	this.rate.Maximum = 95;
        	this.rate.Name = "rate";
        	this.rate.Size = new System.Drawing.Size(84, 45);
        	this.rate.TabIndex = 2;
        	this.rate.Value = 0;
        	this.rate.Minimum = -95;
        	this.rate.Scroll += new System.EventHandler(this.rate_Scroll);
        	// 
        	// tempo
        	// 
        	this.tempo.Location = new System.Drawing.Point(526, 39);
        	this.tempo.Maximum = 95;
        	this.tempo.Value = 0;
        	this.tempo.Minimum = -95;
        	this.tempo.Name = "tempo";
        	this.tempo.Size = new System.Drawing.Size(84, 45);
        	this.tempo.TabIndex = 3;
        	this.tempo.Scroll += new System.EventHandler(this.tempo_Scroll);
        	// 
        	// pitch
        	// 
        	this.pitch.Location = new System.Drawing.Point(527, 80);
        	this.pitch.Maximum = 60;
        	this.pitch.Value = 0;
        	this.pitch.Minimum = -60;
        	this.pitch.Name = "pitch";
        	this.pitch.Size = new System.Drawing.Size(84, 45);
        	this.pitch.TabIndex = 4;
        	this.pitch.Scroll += new System.EventHandler(this.pitch_Scroll);
        	// 
        	// label2
        	// 
        	this.label2.AutoSize = true;
        	this.label2.Location = new System.Drawing.Point(483, 50);
        	this.label2.Name = "label2";
        	this.label2.Size = new System.Drawing.Size(40, 13);
        	this.label2.TabIndex = 5;
        	this.label2.Text = "Tempo";
        	// 
        	// label3
        	// 
        	this.label3.AutoSize = true;
        	this.label3.Location = new System.Drawing.Point(483, 128);
        	this.label3.Name = "label3";
        	this.label3.Size = new System.Drawing.Size(30, 13);
        	this.label3.TabIndex = 6;
        	this.label3.Text = "Rate";
        	// 
        	// label4
        	// 
        	this.label4.AutoSize = true;
        	this.label4.Location = new System.Drawing.Point(483, 89);
        	this.label4.Name = "label4";
        	this.label4.Size = new System.Drawing.Size(31, 13);
        	this.label4.TabIndex = 7;
        	this.label4.Text = "Pitch";
        	// 
        	// button1
        	// 
        	this.button1.Location = new System.Drawing.Point(527, 166);
        	this.button1.Name = "button1";
        	this.button1.Size = new System.Drawing.Size(48, 22);
        	this.button1.TabIndex = 8;
        	this.button1.Text = "Reset";
        	this.button1.UseVisualStyleBackColor = true;
        	this.button1.Click += new System.EventHandler(this.button1_Click);
        	// 
        	// voice
        	// 
        	this.voice.AutoSize = true;
        	this.voice.Location = new System.Drawing.Point(20, 23);
        	this.voice.Name = "voice";
        	this.voice.Size = new System.Drawing.Size(93, 17);
        	this.voice.TabIndex = 9;
        	this.voice.Text = "Voice removal";
        	this.voice.UseVisualStyleBackColor = true;
        	this.voice.MouseUp += new System.Windows.Forms.MouseEventHandler(this.voice_MouseUp);
        	// 
        	// echo
        	// 
        	this.echo.AutoSize = true;
        	this.echo.Location = new System.Drawing.Point(20, 67);
        	this.echo.Name = "echo";
        	this.echo.Size = new System.Drawing.Size(51, 17);
        	this.echo.TabIndex = 10;
        	this.echo.Text = "Echo";
        	this.echo.UseVisualStyleBackColor = true;
        	this.echo.MouseUp += new System.Windows.Forms.MouseEventHandler(this.echo_MouseUp);
        	// 
        	// surround
        	// 
        	this.surround.AutoSize = true;
        	this.surround.Location = new System.Drawing.Point(20, 108);
        	this.surround.Name = "surround";
        	this.surround.Size = new System.Drawing.Size(69, 17);
        	this.surround.TabIndex = 11;
        	this.surround.Text = "Surround";
        	this.surround.UseVisualStyleBackColor = true;
        	this.surround.MouseUp += new System.Windows.Forms.MouseEventHandler(this.surround_MouseUp);
        	// 
        	// surround2
        	// 
        	this.surround2.AutoSize = true;
        	this.surround2.Location = new System.Drawing.Point(20, 164);
        	this.surround2.Name = "surround2";
        	this.surround2.Size = new System.Drawing.Size(139, 17);
        	this.surround2.TabIndex = 12;
        	this.surround2.Text = "BE Amanda Wav Effect";
        	this.surround2.UseVisualStyleBackColor = true;
        	this.surround2.MouseUp += new System.Windows.Forms.MouseEventHandler(this.surround2_MouseUp);
        	// 
        	// svalue
        	// 
        	this.svalue.Location = new System.Drawing.Point(161, 162);
        	this.svalue.Maximum = 50;
        	this.svalue.Name = "svalue";
        	this.svalue.Size = new System.Drawing.Size(84, 45);
        	this.svalue.TabIndex = 13;
        	this.svalue.TickStyle = System.Windows.Forms.TickStyle.None;
        	this.svalue.Scroll += new System.EventHandler(this.svalue_Scroll);
        	// 
        	// freeverb
        	// 
        	this.freeverb.AutoSize = true;
        	this.freeverb.Location = new System.Drawing.Point(20, 218);
        	this.freeverb.Name = "freeverb";
        	this.freeverb.Size = new System.Drawing.Size(68, 17);
        	this.freeverb.TabIndex = 14;
        	this.freeverb.Text = "Freeverb";
        	this.freeverb.UseVisualStyleBackColor = true;
        	this.freeverb.MouseUp += new System.Windows.Forms.MouseEventHandler(this.freeverb_MouseUp);
        	// 
        	// samararicardo_linkLabel1
        	// 
        	this.samararicardo_linkLabel1.Location = new System.Drawing.Point(12, 344);
        	this.samararicardo_linkLabel1.Name = "samararicardo_linkLabel1";
        	this.samararicardo_linkLabel1.Size = new System.Drawing.Size(389, 140);
        	this.samararicardo_linkLabel1.TabIndex = 15;
        	this.samararicardo_linkLabel1.TabStop = true;
        	this.samararicardo_linkLabel1.Text = "Empresa de Software de SamaraeRicardo samararicardo.sourceforge.net";
        	// 
        	// wave_effects
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.ClientSize = new System.Drawing.Size(623, 369);
        	this.Controls.Add(this.rate);
        	this.Controls.Add(this.samararicardo_linkLabel1);
        	this.Controls.Add(this.freeverb);
        	this.Controls.Add(this.svalue);
        	this.Controls.Add(this.surround2);
        	this.Controls.Add(this.surround);
        	this.Controls.Add(this.echo);
        	this.Controls.Add(this.voice);
        	this.Controls.Add(this.button1);
        	this.Controls.Add(this.label4);
        	this.Controls.Add(this.label3);
        	this.Controls.Add(this.label2);
        	this.Controls.Add(this.pitch);
        	this.Controls.Add(this.tempo);
        	this.Controls.Add(this.soundtouch);
        	this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
        	this.Name = "wave_effects";
        	this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
        	this.Text = "BE wave effects";
        	this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Wave_effectsFormClosing);
        	this.Load += new System.EventHandler(this.wave_effects_Load);
        	((System.ComponentModel.ISupportInitialize)(this.rate)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.tempo)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.pitch)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.svalue)).EndInit();
        	this.ResumeLayout(false);
        	this.PerformLayout();

        }
        private System.Windows.Forms.LinkLabel samararicardo_linkLabel1;

        #endregion

        private System.Windows.Forms.CheckBox soundtouch;
        private System.Windows.Forms.TrackBar rate;
        private System.Windows.Forms.TrackBar tempo;
        private System.Windows.Forms.TrackBar pitch;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.CheckBox voice;
        private System.Windows.Forms.CheckBox echo;
        private System.Windows.Forms.CheckBox surround;
        private System.Windows.Forms.CheckBox surround2;
        private System.Windows.Forms.TrackBar svalue;
        private System.Windows.Forms.CheckBox freeverb;
    }
}