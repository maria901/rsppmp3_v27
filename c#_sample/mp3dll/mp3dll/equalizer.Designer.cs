namespace mp3dll
{
    partial class equalizer
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
        	System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(equalizer));
        	this.equa = new System.Windows.Forms.CheckBox();
        	this.double_ = new System.Windows.Forms.CheckBox();
        	this.pre = new System.Windows.Forms.CheckBox();
        	this._pre = new System.Windows.Forms.TrackBar();
        	this.s60 = new System.Windows.Forms.TrackBar();
        	this.s170 = new System.Windows.Forms.TrackBar();
        	this.s600 = new System.Windows.Forms.TrackBar();
        	this.s310 = new System.Windows.Forms.TrackBar();
        	this.s1000 = new System.Windows.Forms.TrackBar();
        	this.s16000 = new System.Windows.Forms.TrackBar();
        	this.s14000 = new System.Windows.Forms.TrackBar();
        	this.s12000 = new System.Windows.Forms.TrackBar();
        	this.s3000 = new System.Windows.Forms.TrackBar();
        	this.s6000 = new System.Windows.Forms.TrackBar();
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
        	((System.ComponentModel.ISupportInitialize)(this._pre)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s60)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s170)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s600)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s310)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s1000)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s16000)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s14000)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s12000)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s3000)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.s6000)).BeginInit();
        	this.SuspendLayout();
        	// 
        	// equa
        	// 
        	this.equa.AutoSize = true;
        	this.equa.Location = new System.Drawing.Point(9, 13);
        	this.equa.Name = "equa";
        	this.equa.Size = new System.Drawing.Size(104, 17);
        	this.equa.TabIndex = 0;
        	this.equa.Text = "Enable equalizer";
        	this.equa.UseVisualStyleBackColor = true;
        	this.equa.CheckedChanged += new System.EventHandler(this.equa_CheckedChanged);
        	this.equa.MouseUp += new System.Windows.Forms.MouseEventHandler(this.equa_MouseUp);
        	// 
        	// double_
        	// 
        	this.double_.AutoSize = true;
        	this.double_.Location = new System.Drawing.Point(9, 28);
        	this.double_.Name = "double_";
        	this.double_.Size = new System.Drawing.Size(90, 17);
        	this.double_.TabIndex = 1;
        	this.double_.Text = "Double buffer";
        	this.double_.UseVisualStyleBackColor = true;
        	this.double_.MouseUp += new System.Windows.Forms.MouseEventHandler(this.double__MouseUp);
        	// 
        	// pre
        	// 
        	this.pre.AutoSize = true;
        	this.pre.Location = new System.Drawing.Point(9, 43);
        	this.pre.Name = "pre";
        	this.pre.Size = new System.Drawing.Size(83, 17);
        	this.pre.TabIndex = 2;
        	this.pre.Text = "Pre-amplifier";
        	this.pre.UseVisualStyleBackColor = true;
        	this.pre.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pre_MouseUp);
        	// 
        	// _pre
        	// 
        	this._pre.AutoSize = false;
        	this._pre.Location = new System.Drawing.Point(16, 81);
        	this._pre.Name = "_pre";
        	this._pre.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this._pre.Size = new System.Drawing.Size(40, 69);
        	this._pre.TabIndex = 3;
        	this._pre.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this._pre.Scroll += new System.EventHandler(this._pre_Scroll);
        	// 
        	// s60
        	// 
        	this.s60.AutoSize = false;
        	this.s60.Location = new System.Drawing.Point(57, 81);
        	this.s60.Name = "s60";
        	this.s60.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s60.Size = new System.Drawing.Size(40, 69);
        	this.s60.TabIndex = 4;
        	this.s60.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s60.Scroll += new System.EventHandler(this.s60_Scroll);
        	// 
        	// s170
        	// 
        	this.s170.AutoSize = false;
        	this.s170.Location = new System.Drawing.Point(97, 81);
        	this.s170.Name = "s170";
        	this.s170.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s170.Size = new System.Drawing.Size(40, 69);
        	this.s170.TabIndex = 5;
        	this.s170.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s170.Scroll += new System.EventHandler(this.s170_Scroll);
        	// 
        	// s600
        	// 
        	this.s600.AutoSize = false;
        	this.s600.Location = new System.Drawing.Point(178, 81);
        	this.s600.Name = "s600";
        	this.s600.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s600.Size = new System.Drawing.Size(40, 69);
        	this.s600.TabIndex = 6;
        	this.s600.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s600.Scroll += new System.EventHandler(this.s600_Scroll);
        	// 
        	// s310
        	// 
        	this.s310.AutoSize = false;
        	this.s310.Location = new System.Drawing.Point(138, 81);
        	this.s310.Name = "s310";
        	this.s310.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s310.Size = new System.Drawing.Size(40, 69);
        	this.s310.TabIndex = 7;
        	this.s310.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s310.Scroll += new System.EventHandler(this.s310_Scroll);
        	// 
        	// s1000
        	// 
        	this.s1000.AutoSize = false;
        	this.s1000.Location = new System.Drawing.Point(220, 81);
        	this.s1000.Name = "s1000";
        	this.s1000.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s1000.Size = new System.Drawing.Size(40, 69);
        	this.s1000.TabIndex = 8;
        	this.s1000.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s1000.Scroll += new System.EventHandler(this.s1000_Scroll);
        	// 
        	// s16000
        	// 
        	this.s16000.AutoSize = false;
        	this.s16000.Location = new System.Drawing.Point(428, 81);
        	this.s16000.Name = "s16000";
        	this.s16000.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s16000.Size = new System.Drawing.Size(40, 69);
        	this.s16000.TabIndex = 9;
        	this.s16000.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s16000.Scroll += new System.EventHandler(this.s16000_Scroll);
        	// 
        	// s14000
        	// 
        	this.s14000.AutoSize = false;
        	this.s14000.Location = new System.Drawing.Point(387, 81);
        	this.s14000.Name = "s14000";
        	this.s14000.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s14000.Size = new System.Drawing.Size(40, 69);
        	this.s14000.TabIndex = 10;
        	this.s14000.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s14000.Scroll += new System.EventHandler(this.s14000_Scroll);
        	// 
        	// s12000
        	// 
        	this.s12000.AutoSize = false;
        	this.s12000.Location = new System.Drawing.Point(346, 81);
        	this.s12000.Name = "s12000";
        	this.s12000.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s12000.Size = new System.Drawing.Size(40, 69);
        	this.s12000.TabIndex = 11;
        	this.s12000.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s12000.Scroll += new System.EventHandler(this.s12000_Scroll);
        	// 
        	// s3000
        	// 
        	this.s3000.AutoSize = false;
        	this.s3000.Location = new System.Drawing.Point(262, 81);
        	this.s3000.Name = "s3000";
        	this.s3000.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s3000.Size = new System.Drawing.Size(40, 69);
        	this.s3000.TabIndex = 12;
        	this.s3000.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s3000.Scroll += new System.EventHandler(this.s3000_Scroll);
        	// 
        	// s6000
        	// 
        	this.s6000.AutoSize = false;
        	this.s6000.Location = new System.Drawing.Point(304, 81);
        	this.s6000.Name = "s6000";
        	this.s6000.Orientation = System.Windows.Forms.Orientation.Vertical;
        	this.s6000.Size = new System.Drawing.Size(40, 69);
        	this.s6000.TabIndex = 13;
        	this.s6000.TickStyle = System.Windows.Forms.TickStyle.Both;
        	this.s6000.Scroll += new System.EventHandler(this.s6000_Scroll);
        	// 
        	// label1
        	// 
        	this.label1.AutoSize = true;
        	this.label1.Location = new System.Drawing.Point(28, 65);
        	this.label1.Name = "label1";
        	this.label1.Size = new System.Drawing.Size(23, 13);
        	this.label1.TabIndex = 14;
        	this.label1.Text = "Pre";
        	// 
        	// label2
        	// 
        	this.label2.AutoSize = true;
        	this.label2.Location = new System.Drawing.Point(143, 65);
        	this.label2.Name = "label2";
        	this.label2.Size = new System.Drawing.Size(25, 13);
        	this.label2.TabIndex = 15;
        	this.label2.Text = "310";
        	// 
        	// label3
        	// 
        	this.label3.AutoSize = true;
        	this.label3.Location = new System.Drawing.Point(223, 65);
        	this.label3.Name = "label3";
        	this.label3.Size = new System.Drawing.Size(31, 13);
        	this.label3.TabIndex = 16;
        	this.label3.Text = "1000";
        	// 
        	// label4
        	// 
        	this.label4.AutoSize = true;
        	this.label4.Location = new System.Drawing.Point(309, 65);
        	this.label4.Name = "label4";
        	this.label4.Size = new System.Drawing.Size(31, 13);
        	this.label4.TabIndex = 17;
        	this.label4.Text = "6000";
        	// 
        	// label5
        	// 
        	this.label5.AutoSize = true;
        	this.label5.Location = new System.Drawing.Point(430, 65);
        	this.label5.Name = "label5";
        	this.label5.Size = new System.Drawing.Size(37, 13);
        	this.label5.TabIndex = 18;
        	this.label5.Text = "16000";
        	// 
        	// label6
        	// 
        	this.label6.AutoSize = true;
        	this.label6.Location = new System.Drawing.Point(392, 65);
        	this.label6.Name = "label6";
        	this.label6.Size = new System.Drawing.Size(37, 13);
        	this.label6.TabIndex = 19;
        	this.label6.Text = "14000";
        	// 
        	// label7
        	// 
        	this.label7.AutoSize = true;
        	this.label7.Location = new System.Drawing.Point(267, 65);
        	this.label7.Name = "label7";
        	this.label7.Size = new System.Drawing.Size(31, 13);
        	this.label7.TabIndex = 20;
        	this.label7.Text = "3000";
        	// 
        	// label8
        	// 
        	this.label8.AutoSize = true;
        	this.label8.Location = new System.Drawing.Point(350, 65);
        	this.label8.Name = "label8";
        	this.label8.Size = new System.Drawing.Size(37, 13);
        	this.label8.TabIndex = 21;
        	this.label8.Text = "12000";
        	// 
        	// label9
        	// 
        	this.label9.AutoSize = true;
        	this.label9.Location = new System.Drawing.Point(102, 65);
        	this.label9.Name = "label9";
        	this.label9.Size = new System.Drawing.Size(25, 13);
        	this.label9.TabIndex = 22;
        	this.label9.Text = "170";
        	// 
        	// label10
        	// 
        	this.label10.AutoSize = true;
        	this.label10.Location = new System.Drawing.Point(185, 65);
        	this.label10.Name = "label10";
        	this.label10.Size = new System.Drawing.Size(25, 13);
        	this.label10.TabIndex = 23;
        	this.label10.Text = "600";
        	// 
        	// label11
        	// 
        	this.label11.AutoSize = true;
        	this.label11.Location = new System.Drawing.Point(67, 65);
        	this.label11.Name = "label11";
        	this.label11.Size = new System.Drawing.Size(19, 13);
        	this.label11.TabIndex = 24;
        	this.label11.Text = "60";
        	// 
        	// equalizer
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.ClientSize = new System.Drawing.Size(477, 160);
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
        	this.Controls.Add(this.s6000);
        	this.Controls.Add(this.s3000);
        	this.Controls.Add(this.s12000);
        	this.Controls.Add(this.s14000);
        	this.Controls.Add(this.s16000);
        	this.Controls.Add(this.s1000);
        	this.Controls.Add(this.s310);
        	this.Controls.Add(this.s600);
        	this.Controls.Add(this.s170);
        	this.Controls.Add(this.s60);
        	this.Controls.Add(this._pre);
        	this.Controls.Add(this.pre);
        	this.Controls.Add(this.double_);
        	this.Controls.Add(this.equa);
        	this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
        	this.Name = "equalizer";
        	this.Text = "Equalizer";
        	this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.EqualizerFormClosing);
        	this.Load += new System.EventHandler(this.equalizer_Load);
        	((System.ComponentModel.ISupportInitialize)(this._pre)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s60)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s170)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s600)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s310)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s1000)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s16000)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s14000)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s12000)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s3000)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.s6000)).EndInit();
        	this.ResumeLayout(false);
        	this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox equa;
        private System.Windows.Forms.CheckBox double_;
        private System.Windows.Forms.CheckBox pre;
        private System.Windows.Forms.TrackBar _pre;
        private System.Windows.Forms.TrackBar s60;
        private System.Windows.Forms.TrackBar s170;
        private System.Windows.Forms.TrackBar s600;
        private System.Windows.Forms.TrackBar s310;
        private System.Windows.Forms.TrackBar s1000;
        private System.Windows.Forms.TrackBar s16000;
        private System.Windows.Forms.TrackBar s14000;
        private System.Windows.Forms.TrackBar s12000;
        private System.Windows.Forms.TrackBar s3000;
        private System.Windows.Forms.TrackBar s6000;
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
    }
}