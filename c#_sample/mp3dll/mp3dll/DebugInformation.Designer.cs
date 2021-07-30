namespace mp3dll
{
    partial class DebugInformation
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
        	System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DebugInformation));
        	this.list = new System.Windows.Forms.ListBox();
        	this.button1 = new System.Windows.Forms.Button();
        	this.button2 = new System.Windows.Forms.Button();
        	this.get_debug_info = new System.Windows.Forms.Timer(this.components);
        	this.SuspendLayout();
        	// 
        	// list
        	// 
        	this.list.FormattingEnabled = true;
        	this.list.Location = new System.Drawing.Point(15, 21);
        	this.list.Name = "list";
        	this.list.Size = new System.Drawing.Size(377, 173);
        	this.list.TabIndex = 0;
        	// 
        	// button1
        	// 
        	this.button1.Location = new System.Drawing.Point(13, 213);
        	this.button1.Name = "button1";
        	this.button1.Size = new System.Drawing.Size(94, 27);
        	this.button1.TabIndex = 1;
        	this.button1.Text = "Clear";
        	this.button1.UseVisualStyleBackColor = true;
        	this.button1.Click += new System.EventHandler(this.button1_Click);
        	// 
        	// button2
        	// 
        	this.button2.Location = new System.Drawing.Point(300, 213);
        	this.button2.Name = "button2";
        	this.button2.Size = new System.Drawing.Size(94, 27);
        	this.button2.TabIndex = 2;
        	this.button2.Text = "Exit";
        	this.button2.UseVisualStyleBackColor = true;
        	this.button2.Click += new System.EventHandler(this.button2_Click);
        	// 
        	// get_debug_info
        	// 
        	this.get_debug_info.Enabled = true;
        	this.get_debug_info.Interval = 1000;
        	this.get_debug_info.Tick += new System.EventHandler(this.get_debug_info_Tick);
        	// 
        	// DebugInformation
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.ClientSize = new System.Drawing.Size(406, 266);
        	this.Controls.Add(this.button2);
        	this.Controls.Add(this.button1);
        	this.Controls.Add(this.list);
        	this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
        	this.Name = "DebugInformation";
        	this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
        	this.Text = "BE Debug Information";
        	this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.DebugInformationFormClosing);
        	this.Load += new System.EventHandler(this.DebugInformation_Load);
        	this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox list;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Timer get_debug_info;
    }
}