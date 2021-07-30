
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
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

/*
 * Created by SharpDevelop.
 * User: Koci
 * Date: 23/07/2021
 * Time: 00:29
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Drawing;
using System.Windows.Forms;

namespace mp3dll
{
	/// <summary>
	/// Description of amanda_search.
	/// </summary>
	public partial class amanda_search : Form
	{
		public amanda_search()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		protected int position_amanda;
		void Next_mariaClick(object sender, EventArgs e)
		{
			bool containsSearchResult;
			int i_amanda;
			//oi amor
			//playlist.Items[MP3.playlist_index].SubItems[1].Text
			//playlist
			ricardo_list.Items.Clear();
			try
			{
				for(i_amanda = position_amanda; i_amanda < MP3.sample_copy_ar.playlist.Items.Count; i_amanda++)
				{
					containsSearchResult = MP3.sample_copy_ar.playlist.Items[i_amanda].SubItems[0].Text.ToLower().Contains(search_amanda.Text.ToLower());
				
					if(containsSearchResult)
					{
						//position_amanda = i_amanda + 1;
						ricardo_list.Items.Add(MP3.sample_copy_ar.playlist.Items[i_amanda].SubItems[0].Text);
						
					}
				}
				
			}
			catch
			{
				position_amanda = 0;
			}
			
			//playlist.Focus();
		
		
		}
		void Ricardo_listDoubleClick(object sender, EventArgs e)
		{
			MP3.pedro_dprintf(-1, "Item pego " + ricardo_list.Items[ricardo_list.SelectedIndex].ToString());
			MP3.sample_copy_ar.playlist_search_amanda_DoubleClick(ricardo_list.Items[ricardo_list.SelectedIndex].ToString());
		
			this.WindowState = FormWindowState.Minimized;
			
		}
		void Amanda_searchLoad(object sender, EventArgs e)
		{
	
			if(null != MP3.search_copy)
			{
				MP3.search_copy.Close();
				MP3.search_copy = null;
			}
			
			MP3.search_copy = this;
		}
		void Amanda_searchFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.search_copy = null;
		}
	}
}
