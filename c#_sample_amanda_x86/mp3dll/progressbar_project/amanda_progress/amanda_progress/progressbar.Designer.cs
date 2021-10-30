//2021 amanda & ricardo - designer
namespace amanda_progress
{
    partial class progressbar
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
        	System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(progressbar));
        	this.fixo = new System.Windows.Forms.PictureBox();
        	this.deslizante = new System.Windows.Forms.PictureBox();
        	this.deslizante_2_z = new System.Windows.Forms.PictureBox();
        	this.maria_vision_ = new System.Windows.Forms.PictureBox();
        	((System.ComponentModel.ISupportInitialize)(this.fixo)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.deslizante)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.deslizante_2_z)).BeginInit();
        	((System.ComponentModel.ISupportInitialize)(this.maria_vision_)).BeginInit();
        	this.SuspendLayout();
        	// 
        	// fixo
        	// 
        	this.fixo.BackColor = System.Drawing.Color.LightSteelBlue;
        	this.fixo.Location = new System.Drawing.Point(3, 3);
        	this.fixo.Name = "fixo";
        	this.fixo.Size = new System.Drawing.Size(79, 22);
        	this.fixo.TabIndex = 0;
        	this.fixo.TabStop = false;
        	this.fixo.MouseDown += new System.Windows.Forms.MouseEventHandler(this.fixo_MouseDown);
        	this.fixo.MouseEnter += new System.EventHandler(this.fixo_MouseEnter);
        	this.fixo.MouseLeave += new System.EventHandler(this.fixo_MouseLeave);
        	// 
        	// deslizante
        	// 
        	this.deslizante.BackColor = System.Drawing.Color.RoyalBlue;
        	this.deslizante.Location = new System.Drawing.Point(3, 3);
        	this.deslizante.Name = "deslizante";
        	this.deslizante.Size = new System.Drawing.Size(79, 22);
        	this.deslizante.TabIndex = 1;
        	this.deslizante.TabStop = false;
        	this.deslizante.Click += new System.EventHandler(this.deslizante_Click);
        	this.deslizante.MouseDown += new System.Windows.Forms.MouseEventHandler(this.deslizante_MouseDown);
        	this.deslizante.MouseEnter += new System.EventHandler(this.deslizante_MouseEnter);
        	// 
        	// deslizante_2_z
        	// 
        	this.deslizante_2_z.BackColor = System.Drawing.Color.RoyalBlue;
        	this.deslizante_2_z.Location = new System.Drawing.Point(227, 3);
        	this.deslizante_2_z.Name = "deslizante_2_z";
        	this.deslizante_2_z.Size = new System.Drawing.Size(90, 22);
        	this.deslizante_2_z.TabIndex = 4;
        	this.deslizante_2_z.TabStop = false;
        	this.deslizante_2_z.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Deslizante_1_zMouseDown);
        	// 
        	// maria_vision_
        	// 
        	this.maria_vision_.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("maria_vision_.BackgroundImage")));
        	this.maria_vision_.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
        	this.maria_vision_.Location = new System.Drawing.Point(3, 0);
        	this.maria_vision_.Name = "maria_vision_";
        	this.maria_vision_.Size = new System.Drawing.Size(19, 19);
        	this.maria_vision_.TabIndex = 7;
        	this.maria_vision_.TabStop = false;
        	// 
        	// progressbar
        	// 
        	this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        	this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        	this.Controls.Add(this.maria_vision_);
        	this.Controls.Add(this.deslizante_2_z);
        	this.Controls.Add(this.deslizante);
        	this.Controls.Add(this.fixo);
        	this.Name = "progressbar";
        	this.Size = new System.Drawing.Size(438, 143);
        	this.Load += new System.EventHandler(this.progressbar_Load);
        	this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.progressbar_MouseDown);
        	this.MouseEnter += new System.EventHandler(this.progressbar_MouseEnter);
        	this.Resize += new System.EventHandler(this.progressbar_Resize);
        	((System.ComponentModel.ISupportInitialize)(this.fixo)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.deslizante)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.deslizante_2_z)).EndInit();
        	((System.ComponentModel.ISupportInitialize)(this.maria_vision_)).EndInit();
        	this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox fixo;
        private System.Windows.Forms.PictureBox deslizante;
        // private System.Windows.Forms.PictureBox deslizante_0_z;
        // private System.Windows.Forms.PictureBox deslizante_1_z;
        private System.Windows.Forms.PictureBox deslizante_2_z;
        // private System.Windows.Forms.PictureBox deslizante_3_z;
        // private System.Windows.Forms.PictureBox deslizante_4_z;
        private System.Windows.Forms.PictureBox maria_vision_;
    }
}