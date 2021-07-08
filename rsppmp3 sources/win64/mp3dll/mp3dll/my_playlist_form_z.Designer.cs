/* my playlist form designer
 * Created by SharpDevelop.
 * User: AAKP
 * Date: 23/03/2021
 * Time: 09:26
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace mp3dll
{
	partial class my_playlist_form_z
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.ListBox my_list_box;
		private System.Windows.Forms.Button create_jun_z;
		private System.Windows.Forms.SaveFileDialog my_save_file_z;
		private System.Windows.Forms.Button sort_z;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;
		
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(my_playlist_form_z));
			this.label1 = new System.Windows.Forms.Label();
			this.my_list_box = new System.Windows.Forms.ListBox();
			this.create_jun_z = new System.Windows.Forms.Button();
			this.my_save_file_z = new System.Windows.Forms.SaveFileDialog();
			this.sort_z = new System.Windows.Forms.Button();
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(15, 13);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(312, 18);
			this.label1.TabIndex = 0;
			this.label1.Text = "Drag and drop files to create a JUN playlist";
			// 
			// my_list_box
			// 
			this.my_list_box.FormattingEnabled = true;
			this.my_list_box.Location = new System.Drawing.Point(19, 41);
			this.my_list_box.Name = "my_list_box";
			this.my_list_box.Size = new System.Drawing.Size(612, 134);
			this.my_list_box.TabIndex = 1;
			// 
			// create_jun_z
			// 
			this.create_jun_z.Location = new System.Drawing.Point(503, 200);
			this.create_jun_z.Name = "create_jun_z";
			this.create_jun_z.Size = new System.Drawing.Size(128, 41);
			this.create_jun_z.TabIndex = 2;
			this.create_jun_z.Text = "Create JUN Playlist";
			this.create_jun_z.UseVisualStyleBackColor = true;
			this.create_jun_z.Click += new System.EventHandler(this.Create_zClick);
			// 
			// my_save_file_z
			// 
			this.my_save_file_z.Filter = "JUN playlist |*.jun| All files|*";
			// 
			// sort_z
			// 
			this.sort_z.Location = new System.Drawing.Point(19, 200);
			this.sort_z.Name = "sort_z";
			this.sort_z.Size = new System.Drawing.Size(128, 41);
			this.sort_z.TabIndex = 3;
			this.sort_z.Text = "Sort";
			this.sort_z.UseVisualStyleBackColor = true;
			this.sort_z.Click += new System.EventHandler(this.Sort_zClick);
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(153, 200);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(128, 41);
			this.button1.TabIndex = 4;
			this.button1.Text = "Clear";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Clear_zClick);
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(369, 200);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(128, 41);
			this.button2.TabIndex = 5;
			this.button2.Text = "Add to existing JUN Playlist";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Add_zClick);
			
			// 
			// my_playlist_form_z
			// 
			this.AllowDrop = true;
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(652, 262);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.sort_z);
			this.Controls.Add(this.create_jun_z);
			this.Controls.Add(this.my_list_box);
			this.Controls.Add(this.label1);
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.Name = "my_playlist_form_z";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Create a playlist";
			this.TopMost = true;
			this.DragDrop += new System.Windows.Forms.DragEventHandler(this.My_playlist_form_zDragDrop);
			this.DragEnter += new System.Windows.Forms.DragEventHandler(this.My_playlist_form_zDragEnter);
			this.ResumeLayout(false);

		}
	}
}
