
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://arsoftware.net.br/binarywork_____________________       *

 *              http: //nomade.sourceforge.net/binarywork_______________/       *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

using System;
using System.Drawing;
using System.Windows.Forms;

namespace mp3dll
{
	/// <summary>
	/// Description of my_playlist_form_z.
	/// </summary>
	public partial class my_playlist_form_z : Form
	{
		bool sort_mode_z = false;
		public my_playlist_form_z()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		void My_playlist_form_zDragDrop(object sender, DragEventArgs e_z)
		{
			string[] files_z = (string[])e_z.Data.GetData(DataFormats.FileDrop);
			foreach (string koci_eu_te_amo_file in files_z)
			{
				//ava_util.ar_dprintf("kkkk " + file);
				MP3.pedro_dprintf(0, "pegou " +
				                  koci_eu_te_amo_file);
				
				my_list_box.Items.Add(koci_eu_te_amo_file);
				
			}
		}
		void My_playlist_form_zDragEnter(object sender, DragEventArgs e_z)
		{
			if (e_z.Data.GetDataPresent(DataFormats.FileDrop))
				e_z.Effect = DragDropEffects.Copy;
		}
		private void Sort_zClick(object sender, EventArgs e)
		{
			int items_z = my_list_box.Items.Count;
			int i_z;
			if(my_list_box.Items.Count != 0)
			{
				string[] strArray_z = new string[my_list_box.Items.Count];
				
				for(i_z = 0; i_z < items_z; i_z++)
				{
					
					strArray_z[i_z] = my_list_box.Items[i_z].ToString();
					
				}
				if(false == sort_mode_z)
				{
					sort_mode_z     = true;
					Array.Sort(strArray_z);
				}
				else
				{
					sort_mode_z       = false;
					Array.Reverse(strArray_z);
				}
				my_list_box.Items.Clear();
				for(i_z = 0; i_z < items_z; i_z++)
				{
					
					my_list_box.Items.Add(strArray_z[i_z]);
					
				}
			}
		}
		private void Create_zClick(object sender, EventArgs e)
		{
			int i_z;
			if(0 == my_list_box.Items.Count)
			{
				return;
			}
			my_save_file_z.FileName = "my_playlist_one.jun";
			DialogResult amanda = my_save_file_z.ShowDialog();
			
			if(DialogResult.OK == amanda)
			{
				//process...
				if(0 == MP3.init_jun_playlist_z(MP3.wide2utf8(my_save_file_z.FileName)))
				{
					for(i_z = 0; i_z < my_list_box.Items.Count; i_z++)
					{
						MP3.add_item_to_playlist_z(MP3.wide2utf8(my_list_box.Items[i_z].ToString()));
					}
					MP3.close_playlist_z();
					create_jun_z.Text = "Done";
				}
				else
				{
					create_jun_z.Text = "Error";
				}
			}
		}
		private void Clear_zClick(object sender, EventArgs e)
		{
			my_list_box.Items.Clear();
		}
		private void Add_zClick(object sender, EventArgs e)
		{
			int i_z;
			if(0 == my_list_box.Items.Count)
			{
				return;
			}
			my_save_file_z.FileName = "my_playlist_one.jun";
			DialogResult amanda = my_save_file_z.ShowDialog();
			
			if(DialogResult.OK == amanda)
			{
				//process...
				if(0 == MP3.add_to_jun_playlist_z(MP3.wide2utf8(my_save_file_z.FileName)))
				{
					for(i_z = 0; i_z < my_list_box.Items.Count; i_z++)
					{
						MP3.add_item_to_playlist_z(MP3.wide2utf8(my_list_box.Items[i_z].ToString()));
					}
					MP3.close_playlist_z();
					button2.Text = "Done";
				}
				else
				{
					button2.Text = "Error";
				}
			}
		}
	}
}
