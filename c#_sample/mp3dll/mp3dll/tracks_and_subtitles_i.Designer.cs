/* tracks designer my loved ape...
 * Created by SharpDevelop.
 * User: Koci
 * Date: 07/08/2021
 * Time: 20:56
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace mp3dll
{
	partial class tracks_and_subtitles_i
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.Button audio_get_i;
		private System.Windows.Forms.Label label13;
		private System.Windows.Forms.ComboBox track;
		private System.Windows.Forms.Button get_subtitles_i;
		private System.Windows.Forms.ComboBox subtitle_i;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Timer ar_timer;
		
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
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(tracks_and_subtitles_i));
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.audio_get_i = new System.Windows.Forms.Button();
			this.label13 = new System.Windows.Forms.Label();
			this.track = new System.Windows.Forms.ComboBox();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.button1 = new System.Windows.Forms.Button();
			this.get_subtitles_i = new System.Windows.Forms.Button();
			this.subtitle_i = new System.Windows.Forms.ComboBox();
			this.label1 = new System.Windows.Forms.Label();
			this.ar_timer = new System.Windows.Forms.Timer(this.components);
			this.groupBox1.SuspendLayout();
			this.groupBox2.SuspendLayout();
			this.SuspendLayout();
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.audio_get_i);
			this.groupBox1.Controls.Add(this.label13);
			this.groupBox1.Controls.Add(this.track);
			this.groupBox1.Location = new System.Drawing.Point(22, 22);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(316, 281);
			this.groupBox1.TabIndex = 0;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Audio Tracks";
			// 
			// audio_get_i
			// 
			this.audio_get_i.Location = new System.Drawing.Point(198, 109);
			this.audio_get_i.Name = "audio_get_i";
			this.audio_get_i.Size = new System.Drawing.Size(88, 20);
			this.audio_get_i.TabIndex = 76;
			this.audio_get_i.Text = "Retrieve tracks";
			this.audio_get_i.UseVisualStyleBackColor = true;
			this.audio_get_i.Click += new System.EventHandler(this.Audio_get_iClick);
			// 
			// label13
			// 
			this.label13.AutoSize = true;
			this.label13.Location = new System.Drawing.Point(24, 134);
			this.label13.Name = "label13";
			this.label13.Size = new System.Drawing.Size(215, 13);
			this.label13.TabIndex = 75;
			this.label13.Text = "Play or convert the track number, 0 for none";
			// 
			// track
			// 
			this.track.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.track.FormattingEnabled = true;
			this.track.Location = new System.Drawing.Point(245, 131);
			this.track.Name = "track";
			this.track.Size = new System.Drawing.Size(40, 21);
			this.track.TabIndex = 74;
			this.track.SelectedIndexChanged += new System.EventHandler(this.TrackSelectedIndexChanged);
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.button1);
			this.groupBox2.Controls.Add(this.get_subtitles_i);
			this.groupBox2.Controls.Add(this.subtitle_i);
			this.groupBox2.Controls.Add(this.label1);
			this.groupBox2.Location = new System.Drawing.Point(356, 22);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(316, 281);
			this.groupBox2.TabIndex = 1;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "Subtitles";
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(6, 240);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(81, 35);
			this.button1.TabIndex = 77;
			this.button1.Text = "Only for Debug";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// get_subtitles_i
			// 
			this.get_subtitles_i.Location = new System.Drawing.Point(178, 109);
			this.get_subtitles_i.Name = "get_subtitles_i";
			this.get_subtitles_i.Size = new System.Drawing.Size(113, 20);
			this.get_subtitles_i.TabIndex = 76;
			this.get_subtitles_i.Text = "Retrieve subtitles";
			this.get_subtitles_i.UseVisualStyleBackColor = true;
			this.get_subtitles_i.Click += new System.EventHandler(this.Get_subtitles_iClick);
			// 
			// subtitle_i
			// 
			this.subtitle_i.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.subtitle_i.FormattingEnabled = true;
			this.subtitle_i.Location = new System.Drawing.Point(250, 131);
			this.subtitle_i.Name = "subtitle_i";
			this.subtitle_i.Size = new System.Drawing.Size(40, 21);
			this.subtitle_i.TabIndex = 74;
			this.subtitle_i.SelectedIndexChanged += new System.EventHandler(this.Subtitle_iSelectedIndexChanged);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(59, 134);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(185, 13);
			this.label1.TabIndex = 75;
			this.label1.Text = "Show the subtitles number, 0 for none";
			// 
			// ar_timer
			// 
			this.ar_timer.Interval = 50;
			this.ar_timer.Tick += new System.EventHandler(this.Ar_timerTick);
			// 
			// tracks_and_subtitles_i
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(697, 324);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.groupBox1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.Name = "tracks_and_subtitles_i";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Tracks And Subtitles";
			this.Load += new System.EventHandler(this.Tracks_and_subtitles_iLoad);
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			this.ResumeLayout(false);

		}
	}
}
