   
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
    public partial class spectrum : Form
    {
        public spectrum()
        {
            InitializeComponent();
        }

        long number = MP3.number;

        private void checkBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (enable.CheckState == CheckState.Checked)
            {
                
                timer.Enabled = true;
            }
            else
            {
                timer.Enabled = false;
                
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            int ff60=0;
            int ff170=0;
            int ff310=0;
            int ff600=0;
            int ff1000=0;
            int ff3000=0;
            int ff6000=0;
            int ff12000=0;
            int ff14000=0;
            int ff16000=0;
            int fpeak=0;
            MP3.GetSpectrumAnalyzer(number,
                ref ff60,
                ref ff170,
                ref ff310,
                ref ff600,
                ref ff1000,
                ref ff3000,
                ref ff6000,
                ref ff12000,
                ref ff14000,
                ref ff16000,
                ref fpeak);

            progressbar1.Value = ff60;
            progressbar11.Value = ff170;
            progressbar10.Value = ff310;
            progressbar9.Value = ff600;
            progressbar3.Value = ff1000;
            progressbar4.Value = ff3000;
            progressbar8.Value = ff6000;
            progressbar7.Value = ff12000;
            progressbar6.Value = ff14000;
            progressbar2.Value = ff16000;
            progressbar5.Value = fpeak;
             


        }

        private void spectrum_Load(object sender, EventArgs e)
        {
            /*
             *         Form10.ProgressBar1.Value = f60
'        Form10.ProgressBar2.Value = f170
'        Form10.ProgressBar3.Value = f310
'        Form10.ProgressBar4.Value = f600
'        Form10.ProgressBar5.Value = f1000
'        Form10.ProgressBar6.Value = f3000
'        Form10.ProgressBar7.Value = f6000
'        Form10.ProgressBar8.Value = f12000
'        Form10.ProgressBar9.Value = f14000
'        Form10.ProgressBar10.Value = f16000
'        Form10.ProgressBar11.Value = peak
             * */

        }
		void SpectrumFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.k = null;
		}
    }
}
