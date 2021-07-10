   
/*
    <C# Sample Project for rsppmp3>    
    Copyright (C) <2020>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
	and GNU LESSER GENERAL PUBLIC LICENSE along with this program.  
	If not, see <http://www.gnu.org/licenses/>.
    
    support: http://nomade.sourceforge.net
    
	direct programmers e-mails:
	Ricardo: arsoftware25@gmail.com
	Amanda : arsoftware10@gmail.com
	
	immediate contact(for a very fast answer) WhatsApp
	(+55)41 9627 1708 - it is always on
*/
 
using System;
using System.Text;
using System.Windows.Forms;

namespace mp3dll
{
    public partial class DebugInformation : Form
    {
        long number = MP3.number;  

        public DebugInformation()
        {
            InitializeComponent();
        }
        private void DebugInformation_Load(object sender, EventArgs e)
        {
        }
        StringBuilder alladin_data = new StringBuilder(300);
        private void get_debug_info_Tick(object sender, EventArgs e)
        {
            devolta:
            int ret;
           ret= MP3.DebugInformation(number, alladin_data);
           if (0 == ret)
           {
               list.Items.Add(alladin_data.ToString());
               list.SelectedIndex = list.Items.Count - 1;
               goto devolta;
           }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            list.Items.Clear();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
		void DebugInformationFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.p2 = null;
		}
    }
}