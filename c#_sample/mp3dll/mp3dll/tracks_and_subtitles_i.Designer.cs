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
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.ComboBox comboBox1;
		private System.Windows.Forms.Label label1;
		
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(tracks_and_subtitles_i));
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.audio_get_i = new System.Windows.Forms.Button();
			this.label13 = new System.Windows.Forms.Label();
			this.track = new System.Windows.Forms.ComboBox();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.button1 = new System.Windows.Forms.Button();
			this.comboBox1 = new System.Windows.Forms.ComboBox();
			this.label1 = new System.Windows.Forms.Label();
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
			this.audio_get_i.Location = new System.Drawing.Point(165, 109);
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
			this.label13.Location = new System.Drawing.Point(46, 134);
			this.label13.Name = "label13";
			this.label13.Size = new System.Drawing.Size(161, 13);
			this.label13.TabIndex = 75;
			this.label13.Text = "Play or convert the track number";
			// 
			// track
			// 
			this.track.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.track.FormattingEnabled = true;
			this.track.Location = new System.Drawing.Point(212, 131);
			this.track.Name = "track";
			this.track.Size = new System.Drawing.Size(40, 21);
			this.track.TabIndex = 74;
			this.track.SelectedIndexChanged += new System.EventHandler(this.TrackSelectedIndexChanged);
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.button1);
			this.groupBox2.Controls.Add(this.comboBox1);
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
			this.button1.Location = new System.Drawing.Point(203, 109);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(88, 20);
			this.button1.TabIndex = 76;
			this.button1.Text = "Retrieve tracks";
			this.button1.UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this.comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.comboBox1.FormattingEnabled = true;
			this.comboBox1.Location = new System.Drawing.Point(250, 131);
			this.comboBox1.Name = "comboBox1";
			this.comboBox1.Size = new System.Drawing.Size(40, 21);
			this.comboBox1.TabIndex = 74;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(84, 134);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(161, 13);
			this.label1.TabIndex = 75;
			this.label1.Text = "Play or convert the track number";
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
