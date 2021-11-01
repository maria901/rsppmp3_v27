
/********************************************************************************
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
 ********************************************************************************

      E-mails:
      maria@arsoftware.net.br
      pedro@locacaodiaria.com.br

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *
 *                                                                              *
 *******************************************************************************/
 
using System;
using System.Text;
using System.Windows.Forms;
namespace mp3dll
{
    public partial class id3tag : Form
    {
        long number = MP3.number;
        StringBuilder title = new StringBuilder(100000);
        StringBuilder track = new StringBuilder(100000);
        StringBuilder artist = new StringBuilder(100000);
        StringBuilder album = new StringBuilder(100000);
        StringBuilder year = new StringBuilder(100000);
        StringBuilder genre = new StringBuilder(100000);
        StringBuilder comment = new StringBuilder(100000);
        StringBuilder encodedby = new StringBuilder(100000);
        StringBuilder url = new StringBuilder(100000);
        StringBuilder copyright = new StringBuilder(100000);
        StringBuilder originalartist = new StringBuilder(100000);
        StringBuilder composer = new StringBuilder(100000);

        int int_track;
        int int_genre;
        string filename = "";
        public id3tag(string utf8_filename_)
        {
            filename = utf8_filename_;
            filename = MP3.wide2utf8(filename);
            InitializeComponent();
        }
        StringBuilder genre_ = new StringBuilder(1000);
        private void id3tag_Load(object sender, EventArgs e)
        {            
            this.Text = this.Text + " - " + MP3.utf82wide(filename);
            int i;
            for (i = 0; i < 148; i++)
            {
                MP3.Generate_ID3v1Genre(number, i, genre_);
                string copy = genre_.ToString();
                genre_v1.Items.Add(copy);
                genre_v2.Items.Add(copy);
            }
            try
            {

                MP3.Read_ID3_v1_tag(number, filename, ref int_track, title,
                    artist, album, year, ref int_genre, comment);

                track_v1.Text = int_track.ToString();
                title_v1.Text = title.ToString();
                artist_v1.Text = artist.ToString();
                album_v1.Text = album.ToString();
                year_v1.Text = year.ToString();
                if (int_genre < 149)
                    genre_v1.SelectedIndex = int_genre;
                else
                    throw new Exception("Genre index above 148");
                comment_v1.Text = comment.ToString();
            }
            catch (Exception e_____)
            {
                MessageBox.Show(e_____.Message);
            }            
            if
            (
                0 == MP3.Read_ID3_v2_tag(number, filename, track, title, artist, album,
                year, genre, comment, encodedby, url, copyright,
                originalartist, composer
            ))
            {
                track_v2.Text = track.ToString();
                title_v2 .Text = title.ToString ();
                artist_v2 .Text = artist .ToString ();
                album_v2 .Text = album .ToString ();
                year_v2 .Text = year.ToString ();
                genre_v2 .Text = genre.ToString ();
                comment_v2 .Text = comment .ToString ();
                encoded_by_v2 .Text = encodedby .ToString ();
                url_v2 .Text = url .ToString ();
                copyright_v2 .Text = copyright .ToString ();
                original_artist_v2 .Text = originalartist .ToString ();
                composer_v2 .Text = composer .ToString ();
                
            }
            

        }

        private void save_id3v1_Click(object sender, EventArgs e)
        {
            if(""== track_v1 .Text )
            {
                track_v1 .Text="1";
            }
            try{
                int ret = MP3.Write_ID3_v1_tag(number, filename, int.Parse(track_v1.Text), title_v1.Text,
                    artist_v1.Text,
                    album_v1.Text,
                    year_v1.Text,
                    genre_v1.SelectedIndex,
                    comment_v1.Text);

                if(0!=ret)
                {
                    throw new Exception("Cannot write the ID3 v1 tag, error " + ret.ToString ());
                }
                MessageBox.Show("Done");
            }
                catch(Exception eee)
            {
                MessageBox .Show (eee.Message);
            }
        }

        private void remove_id3_v1_Click(object sender, EventArgs e)
        {
            MP3.Remove_ID3V1_tag(number, filename);
        }

        private void save_id3_v2_Click(object sender, EventArgs e)
        {

            int ret=MP3.Write_ID3_v2_tag(
                number, filename,
                track_v2.Text,
                title_v2.Text,
                artist_v2.Text,
                album_v2.Text,
                year_v2.Text,
                genre_v2.Text,
                comment_v2.Text,
                encoded_by_v2.Text,
                url_v2.Text,
                copyright_v2.Text,
                original_artist_v2.Text,
                composer_v2.Text
                );
            if (0 != ret)
            {

                MessageBox.Show("Cannot write the ID3 v2 tag, error " + ret.ToString());

            }
            else
            {
                MessageBox.Show("Done");
            }
        }

        private void remove_id3_v2_Click(object sender, EventArgs e)
        {
            MP3.Remove_ID3V2_tag(number, filename);
        }
		void Id3tagFormClosing(object sender, FormClosingEventArgs e)
		{
			MP3.p4 = null;
		}
    }
}
