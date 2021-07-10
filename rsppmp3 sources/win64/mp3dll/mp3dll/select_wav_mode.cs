
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
using System.Windows.Forms;

namespace mp3dll
{
	public partial class select_wav_mode : Form
	{
		public select_wav_mode()
		{
			InitializeComponent();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			MP3.wave_mode = 1;
			this.Close();
		}

		private void button2_Click(object sender, EventArgs e)
		{
			MP3.wave_mode = 2;
			this.Close();
		}

		private void button3_Click(object sender, EventArgs e)
		{
			MP3.wave_mode = 3;
			this.Close();
		}

		private void button4_Click(object sender, EventArgs e)
		{
			MP3.wave_mode = 4;
			this.Close();
		}
		
		void Button5Click(object sender, EventArgs e)
		{
			MP3.wave_mode = 5;
			this.Close();
		}

		private void select_wav_mode_Load(object sender, EventArgs e)
		{

		}
	}
}
