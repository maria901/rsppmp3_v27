/* amanda search designer
 * 
 * Created by SharpDevelop.
 * User: Koci
 * Date: 23/07/2021
 * Time: 00:29
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace mp3dll
{
	partial class amanda_search
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.ListBox ricardo_list;
		private System.Windows.Forms.TextBox search_amanda;
		private System.Windows.Forms.Button next_maria;
		
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(amanda_search));
			this.ricardo_list = new System.Windows.Forms.ListBox();
			this.search_amanda = new System.Windows.Forms.TextBox();
			this.next_maria = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// ricardo_list
			// 
			this.ricardo_list.FormattingEnabled = true;
			this.ricardo_list.Location = new System.Drawing.Point(12, 46);
			this.ricardo_list.Name = "ricardo_list";
			this.ricardo_list.Size = new System.Drawing.Size(551, 212);
			this.ricardo_list.TabIndex = 0;
			this.ricardo_list.DoubleClick += new System.EventHandler(this.Ricardo_listDoubleClick);
			// 
			// search_amanda
			// 
			this.search_amanda.Location = new System.Drawing.Point(12, 13);
			this.search_amanda.Name = "search_amanda";
			this.search_amanda.Size = new System.Drawing.Size(457, 20);
			this.search_amanda.TabIndex = 1;
			// 
			// next_maria
			// 
			this.next_maria.Location = new System.Drawing.Point(484, 11);
			this.next_maria.Name = "next_maria";
			this.next_maria.Size = new System.Drawing.Size(78, 21);
			this.next_maria.TabIndex = 2;
			this.next_maria.Text = "Search";
			this.next_maria.UseVisualStyleBackColor = true;
			this.next_maria.Click += new System.EventHandler(this.Next_mariaClick);
			// 
			// amanda_search
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(575, 269);
			this.Controls.Add(this.next_maria);
			this.Controls.Add(this.search_amanda);
			this.Controls.Add(this.ricardo_list);
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.Name = "amanda_search";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Search in the playlist";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Amanda_searchFormClosing);
			this.Load += new System.EventHandler(this.Amanda_searchLoad);
			this.ResumeLayout(false);
			this.PerformLayout();

		}
	}
}
