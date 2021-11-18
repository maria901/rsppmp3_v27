/********************************************************************************
 *                                                                              *
 *        Licensa de C�pia (C) <2021>  <Corpora��o do Trabalho Bin�rio>         *
 *                                                                              *
 *     Este  programa  � software livre: voc� pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como       8
 *     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da       *
 *     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.         *
 *                                                                              *
 *     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de       *
 *     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P�blica para mais detalhes.                                *
 *                                                                              *
 *     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P�blica Menor junto com este programa                            *
 *     Se n�o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 ********************************************************************************

       E-mails:
       maria@arsoftware.net.br
       pedro@locacaodiaria.com.br

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito r�pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                 *
 *                                                                              *
 *******************************************************************************/

#include <xmmintrin.h>

void just_free_libav_v(morcego___i___instance__a__bucaneiro_engineering *mv_______);

void _MM_SET_FLUSH_ZERO_MODE2(unsigned int __mode)
{
#ifdef WIN64
     _mm_setcsr((_mm_getcsr() & ~_MM_FLUSH_ZERO_MASK) | __mode);
#else
     __builtin_ia32_ldmxcsr((__builtin_ia32_stmxcsr() & ~_MM_FLUSH_ZERO_MASK) | __mode);
#endif
}

#define WINDOW_FLAG___ HWND_TOP
#define SHOW_FLAG__ SWP_SHOWWINDOW | SWP_NOCOPYBITS
#define NO_SHOW_FLAG__ SWP_HIDEWINDOW | SWP_NOCOPYBITS

void __stdcall svc_seek_opus_m(char *struct_opus_m,
                               __attribute__((unused)) double maquisistem_value);

int __fastcall DetectChangeInSoundCards_i_internal(void);

void get_sha_512_as_string_k(char *buffer_k, unsigned int len_k, char *digest_k);

int __stdcall morcego_decode_libav_svc_process_opus_m(char *struct_opus_m,
                                                      __attribute__((unused)) int bytes_to_decode_m,
                                                      __attribute__((unused)) char *bufout_m,
                                                      __attribute__((unused)) int *size_out);

double amanda_tempo;

int already_got_i = -1;

/**
   calculate the size of the player buffer for mv_______->decoder_c___wav
 */
double
calculate_slice_player_23_06_2011(int size)
{
     double temp;
     temp = size;
     temp = temp * 2 * 2;
     temp = temp / 29.400; // magic value
     return temp;
}
/**
 * Main decoder (player) function.
 * \param filename the file to play as a utf-8 encoded C string
 * \return 0 if no error or the error value<br>
 */
int morcego_play(
    morcego___i___instance__a__bucaneiro_engineering *mv_______,
    unsigned char
        *filename,
    int track)
{
reinicia_z:;
     RECT rect;
     char *myptr;
     char tempname[MAXPATH_UTF_8_MODE_AMANDA_S_SMART_APE];
     char message_amanda_s_smart_ape[1027] = {0};
     double fixotime;
     double newtempo = 0;
     double deslocamento = 0;
     double deslocamento2 = 0;
     fixotime = 0;
     int isize;
     int ret = 0;
     int channels;
     int opened = 0;
     int samplerate;
     int didfixmp3 = 0;
     int tempfilegerado = 0;
     int player_decoder_status = BE_DECODED;
     uint size = 0;
     uint size1;
     uint size2;
     uint funcao;
     uint waveflag;
     uint intchannels;
     int returnvalue_amanda_s_smart_ape;
     int finished_amanda_s_smart_ape;
     int percent_amanda_s_smart_ape;
     unsigned char out[16000];
     unsigned int returnvalue;
     int64_t converted_long_int_amanda_s_smart_ape;
     pedro_dprintf(-15102021, "1");
     mv_______->libav_c___is_desktop_playback_amanda = false;

     mv_______->libav_c___window_was_set______i = false;

     if (enable_desktop_i)
     {
          HWND hwnd;

          {

               hwnd = FindWindow(("Progman"), NULL);
               if (hwnd)
                    hwnd = FindWindowEx(hwnd, NULL, ("SHELLDLL_DefView"), NULL);
               if (hwnd)
                    hwnd = FindWindowEx(hwnd, NULL, ("SysListView32"), NULL);
               if (!hwnd)
               {
                    pedro_dprintf(-1, "couldn't find \"SysListView32\" window, "
                                      "wallpaper mode not supported");
                    goto no_use_i;
               }

               mv_______->libav_c___is_desktop_playback_amanda = true;

               mv_______->libav_c___size_of_window_width = w_i;
               mv_______->libav_c___size_of_window_height = h_i;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"

               mv_______->libav_c___player_hwnd = (int64_t)hwnd;

#pragma GCC diagnostic pop

               // mv_______->libav_c___the_ratio = ratio_;
               mv_______->libav_c___adjust_top = 0;
               mv_______->libav_c___adjust_left = 0;

               mv_______->libav_c___request_for_adjust = 1;
               mv_______->libav_c___original_width__i = w_i;
               mv_______->libav_c___original_height_i = h_i;

               if (-1 == already_got_i)
               {
                    {
                         WINDOWINFO info_i = {0};
                         info_i.cbSize = sizeof(info_i);
                         GetWindowInfo((HWND)(__INT32_OR_INT64)
                                           mv_______->libav_c___player_hwnd,
                                       &info_i);

                         mv_______->libav_c___show_desktop_window_i = false;
                         if ((info_i.dwStyle & 0x10000000) == 0x10000000)
                         {
                              mv_______->libav_c___show_desktop_window_i = true;
                         }
                    }
                    already_got_i = mv_______->libav_c___show_desktop_window_i;
               }

               mv_______->libav_c___show_desktop_window_i = already_got_i;

               if (GetWindowRect((HWND)(__INT32_OR_INT64)
                                     mv_______->libav_c___player_hwnd,
                                 &rect))
               {

                    int width__i = rect.right - rect.left;
                    int height_i = rect.bottom - rect.top;
                    pedro_dprintf(-1, "ok ric,,,sizes %d %d\n", width__i, height_i);

                    mv_______->libav_c___original_width__i = width__i;
                    mv_______->libav_c___original_height_i = height_i;
               }
          }
     }
     pedro_dprintf(-15102021, "2");
no_use_i:;

     pedro_dprintf(-1, "em player, file %s\n", filename);

     mv_______->decodec_c___last_pcm_slice_to_play_k_p = 0;
     mv_______->decoder_c___force_exit = 0;
     mv_______->decoder_c___analized = 0;
     mv_______->decoder_c___bitrate = 0;
     mv_______->decoder_c___cancelflag = 0;
     mv_______->decoder_c___flag_de_pause = 0;
     funcao = 0;
     intchannels = 0;
     mv_______->decoder_c___intismp3 = 0;
     mv_______->decoder_c___intsamplerate = 0;
     mv_______->decoder_c___inttamanho = 0;
     mv_______->decoder_c___leftval = 0;
     mv_______->decoder_c___liberafft = 1;
     memset(&mv_______->decoder_c___wav, 0, sizeof(mv_______->decoder_c___wav));
     memset(mv_______->dsp_c___layer, 0, 255);
     memset(mv_______->dsp_c___mode, 0, 255);
     memset(mv_______->dsp_c___mpeg, 0, 255);
     myptr = mv_______->decoder_c___globalbuf;
     mv_______->decoder_c___newsecond = 0;
     mv_______->decoder_c___newtime = 0;
     mv_______->decoder_c___pauseflag = 0;
     mv_______->decoder_c___ponto = 0;
     mv_______->decoder_c___pwfx.cbSize = 0;
     mv_______->decoder_c___pwfx.nBlockAlign = 0;
     mv_______->decoder_c___pwfx.wBitsPerSample = 0;
     mv_______->decoder_c___pwfx.wFormatTag = 0;
     returnvalue = 0;
     mv_______->decoder_c___rightval = 0;
     mv_______->decoder_c___salvadata = 0;
     mv_______->decoder_c___seconds = 0;
     mv_______->decoder_c___seekto = -1;
     size1 = 0;
     size2 = 0;
     waveflag = 0;
     mv_______->decoder_c___morcego_channels = 0;
     mv_______->decoder_c___bits_per_sample = 0;

     pedro_dprintf(-1, "dentro de playogg");
     pedro_dprintf(-15102021, "3");
     if (mv_______->decoder_c___usandoencrypt)
     {
          char temp[MAXPATH_UTF_8_MODE_AMANDA_S_SMART_APE];
          rspgettemppath_multithread(temp);
          ret = createtempfilename(temp, tempname);
          tempfilegerado = 1;
          encryptfile((char *)filename, tempname, mv_______->decoder_c___key2);
          strcpy((char *)filename, tempname);
     }
     SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
     /////////////////////////////////////////////////////////////////////////////////////////////////////////Morcego ok12
     /////////////////////////////////////////////////////////////////////////////////////////////////////////?
     pedro_dprintf(-1, "Audio begin...");
     switch (mv_______->decoder_c___intpriority)
     {
     case 0:

          SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
          break;
     case 1:

          SetPriorityClass(GetCurrentProcess(),
                           NORMAL_PRIORITY_CLASS);

          break;
     case 2:

          SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS); // time critical mode only Microsoft can use...
          break;
     default:
          break;
     }

     mv_______->decoder_c___intismp3 = 1;

     pedro_dprintf(-1, "OI");
     mv_______->libav_c___player_ar_only_one_frame_flag = 0;
     pedro_dprintf(-15102021, "4");
     void
         init_iir_60(morcego___i___instance__a__bucaneiro_engineering * mv_______);
     init_iir_60(mv_______);
     init_iir(mv_______);
     init_iir____2(mv_______);
     player_decoder_status = BE_DECODED;

     mv_______->libav_c___audio_finished = 0;

     mv_______->decoder_c___intplayback = mv_______->decoder_c___initial_init_playback_value;

     mv_______->libav_c___video_ready_to_play = 0;

     be_libav_struct *be_real_real = (be_libav_struct *)mv_______->be_real;

     memset(&mv_______->decoder_c___spec, 0, sizeof(mv_______->decoder_c___spec));

     memset(be_real_real, 0, sizeof(be_libav_struct));
     be_real_real->internal_replaygain_fast_mode = mv_______->decoder_c___internal_replaygain_fast_mode;
     be_real_real->track_to_play_or_decode = track;

     strcpy(be_real_real->sourcefile, (char *)filename);

     memset(mv_______->decoder_c___morcego_libav_error, 0, 1024);

     be_real_real->internal_play_as_mp3___ = 0;
     if (play_as_mp3)
     {
          be_real_real->internal_play_as_mp3___ = 1;
     }
     if (mv_______->decoder_c___cancelflag)
     {
          goto saida;
     }

     // assert(0 && "here my love...");

     mv_______->libav_c___amanda_s_smart_ape_new_generated_duration = -1;

     mv_______->libav_c___amanda_s_smart_ape__check_and_get_webm_fix_if_true = true;

     converted_long_int_amanda_s_smart_ape = (__INT32_OR_INT64)mv_______;

     mv_______->libav_c___amanda_s_smart_ape_is_new_webm = false;

     mv_______->libav_c___normalization_BENOR_amanda_s_smart_ape[0] = 0;

     mv_______->libav_c___normalization_repla_amanda_s_smart_ape[0] = 0;

     mv_______->decoder_c___tio = -2;
     /*

        Braulio Zanotto, professor de educa��o fisica e juiz de futebol
        Vinicus, filho do Braulio
        Vladinei amigo de 1982 do colegio Pedro II
        Magnani amigo de ano desconhecido do colegio
        Pereira amigo do Pedro II, otimo jogador de futebol junto com o Xu, estava comigo no alistamento militar no colegio militar de Curitiba
        Xu grande amigo otimo jogador de futebol no colegio Pedro II
        Eduardo, me ensinou sobre encrypta��o em 82 a encryptacao se chamava Zenit Polar, grande amigo, so discutimos uma unica vez e ele tomava cerveja junto com o Pereira ja em 82
        Adriana uma amiguinha do colegio Nivaldo Braba por quem eu me apaixonei, e no fim do ano teve um amigo secreto e saiu pra mim comprar um presente pra ela , alguem sujeriu um broche, e eu comprei e presenteei, adoraria saber se ela ainda tem esse broche...
        Andreia amiga minha e da Adriana porquem eu tambem me apaixonei, e somente uma vez acompanhei ela ate a casa dela quando estava perto da casa dela ela disse que eu deveria voltar dali mesmo e nao ir ate a casa dela, esta gostava mesmo de mim
        Maciel amigo do Pereira e do Xu tambem, grande amigo como todos os outros uma unica vez eu o Pereira e o Maciel saimos fazer bagun�a no bairro seminario uma tarde, foi muito legal
        Tabushi triste historia aconteceu, eu e o Maciel estavamos brincando de jogar pedra num e no outro e o Tabushi tava perto mas distrido, de repente eu joguei uma pedra grande no Maciel mas a pedra foi em dire��o ao Tabushi e ele tava distrido e claro a pedra pegou na cabe�a dele, come�ou a sair sangue quando o Tabushi viu o sangue disparou na minha dire��o e como ele tinha uns kilos a mais nao conseguiu me pegar e eu corri pra casa, no dia seguinte achei que ele ia me dar uma surra logo que chegasse no colegio mas ele com a cabe�a enfaixada apenas disse que n�o batia em crian�a, foi muito triste, podeia ter acertado o olho dele dai seria uma problema pro resto da vida
        Viviane amiga do Aercio e de mim, o Aercio vivia tirando sarro dela e ela ficava braba, ela sempre usava o mesmo tenis nao estragava nunca, eu achava ela uma gata mas nunca me apaixonei
        Aercio um dos melhores amigos, grande gozador, junto com outro amigo que eu nao lembro o nome mas estava tambem comigo no alistamento no colegio militar de Curitiba, uma vez o Aercio trouxe uma bicicleta com problemas pra escola e um amigo dele foi andar com ela e ela estragou ele disse na hora "vai pagar", o cara tentou se livrar do problema na ele ficou pegando no p� dele, foi hil�rio, bons tempos, foi nesse ano que eu ganhei minha unica medalha de campe�o em alguma coisa, foi no campeonato de futebol da escola nossa sala ganhou do colegio inteiro n�o em pergunte como, n�o me lembro se marquei gol, foi muito legal
        D�bora uma amiguinha do colegio no mesmo tempo de Aercio e Viviane ela gostava de mim mas n�o adimitia, as vezes ela seguia a gente dentro do banheiro dos meninos, kkkkk, mas logo saia, muito engra�ado, na outra sala do colegio tinha uma menina que vivia puxando papo comigo, s� ela e a Debora gostaram de mim na �poca de col�gio
        C�lio amigo da Vila Verde e filho do dono da casa que eu morava, gente finissima queria lembrar do nome do irm�o dele tamb�m, pessoa muito legal este irm�o e esposa eles n�o sabiam oque fazer pra me agradar l� fiz muita amizade com o pai e a m�o deles tamb�m vivia indo na casa dos parentes deles de Curitiba, todo dia a gente saia pra algum evento eu que carregava todo mundo, e nunca cobrava a gasolina, grande C�lio
        C�lia minha tia C�lia, eu gostava dela mas ela n�o gostava de ningu�m, ela morreu nova fui eu que cuidei de todo o enterro dela e fui eu que paguei tudo acompanhado da m�e e da tia Mena e da v� Elisa que n�o paravam de chorar um s� minuto, quem emprestou o Fuke pra gente fazer a correria foi o Carlinhos, meu ex-padrasto 
        C�lia filha do tio Alexandre irm� do Ma�ricio, eu era apaixonado por ela em 82, a gente ia toda hora na casa dela mas ela nunca demonstrou o menor interesse de namorar comigo, mas ela sabia sim que eu era ligad�o nela, mora em Foz do Igua�u hoje em dia
        Paola filha da C�lia m�e do China da Vila Verde, eu me apaixonei por ela logo que conheci, demorou pra mim parar de pensar nela
        Edna irm� da Paola, tivemos um breve namoro de uma semana
        Sil irm� da Edna, grande amiga, eu levava a v� dela no hospital Erasto Gaertner pra tratamento e ela ia junto, m�e do �caro
        �caro filho da Sil, tinha tr�s anos de idade
        China grande amigo, me ajudou muito durante todo o tempo que eu morei na Vila Verde, ensinei pra ele coisas sobre com�rcio de software na Internet pra ele me ajudar a vender software, nunca saimos na porrada por incr�vel que pare�a
        Testa amigo meu e do China, hil�rio, n�o tinha tempo ruim pra ele, grande amigo, uma vez eu jantei na casa da fam�lia dele
        Nilson grande amigo, gra�as a ele minha empresa de software n�o faliu em 98 quando a m�e do Junior me deu um ponta p� na bunda, mas infelizmente este amigo fez uma coisa que eu nunca perdoei, n�o vou entrar em detalhes, mas � uma coisa que amigo nunca faria, mas � uma coisa que EU fa�o com meus amigos americanos progrmadores
        Sirlei esposa do Nilson, m�e da Cibele, grande amiga
        Sirlei m�e da Kelly minha vizinha do tempo que eu morava em Curitiba, quando morei com a minha v� em 2004 eu tava sempre na papalaria deles comprando bala
        Elvis grande amigo, nunca mais vi, era meu vizinho, uma vez eu socorri uns acidentados com o fiat da empresa que eu trabalhava e cheguei em casa com o carro cheio de sangue, foi ele que lavou o carro inteiro e removeu o sangue todo, ningu�m dos acidentados morreu mesmo eles tendo perdido muito sangue, eu s� socorri dois acidentes em todo o tempo que eu tive carteira, se mudaram para longe, mas a amixade vai durar pra sempre
        Marcelo meu tio que � mais novo que eu, grande companheiro de inf�ncia, evitava que a gente fizesse grandes cagadas porque pelo menos ele tinha a cabe�a no lugar, hoje � dono de uma empresa bem sucedida, vive uma boa vida e � casado mas n�o tem filhos mas disse que ter ter, espor que seja antes dos 60
        Marcelo grande amigo de Coronel Vivida, quando eu tive problemas com a m�e da Ale eu dormi umas noites na casa da m�e dele por n�o ter outro lugar pra ficar, foram tempos dificeis, ele tinha um curso de informatica junto com a esposa dele que era muito bacana
        Cleyton grande amigo, primo do China, depois que fizemos amizade eu passava muito tempo com ele e com a Marilda esposa dele e a filha deles, eles foram cuidar de uma chacara em Registro do pai dele e fui eu que levei, queriam que eu levasse uma leitoa no porta malas do carro, kkkkkkkkkkk, claro que n�o faria isso
        Marilda esposa do Cleyton, grande amiga, minha comadre, pessoa adoravel
        Marcela filha da Melinda o do James, conhe�o desde que nsceu e era eu que consertava o computador dela quando dava problema
        Eduardo amigo advogado (ou Juiz) de Coronel Vivida, o pai dele meu amigo tamb�m o Egidio era Juiz da cidade, fizemos grande amizade e eu sempre tava consertando o computador dele quando entrava virus, grande amig�o, tinha poucos amigos em Coronel Vivida o pessoal achava que eu era algum ladr�o famoso da Internet e que a Policia Federal logo iam me prender, he he he, olha a cabe�a dessa gente, mas alguns l� eram meus amigos como o Chic�o e familia, eles tinham um a�ougue que eu comprava toda hora uma vez trouxe um vinho de coco pro Chic�o que se comprava em Campo Largo porque todo m�s tinha que ir buscar os Dolares em Curitiba, que tamb�m eram muitos, por sorte porque eu sou um bom programador de DLLs e ActiveX
        Paulo tio Paulo, grande amigo de inf�ncia, nunca me bateu, se preocupava muito comigo, n�o tenho queixa dele
        Paulo primo Paulo da tia Mena, grande amigo, foi caminhoneiro, mas nunca fui viajar com ele, gstaria de ter ido, o problema seria ter que parar a cada meia hora pra urinar, kkkkkkkkkkkkkkkk, pai do Linho e dos outros primos que eu n�o lembro o nome, gente finissima
        Paulo primo Paulo da tia Lurdes mulher do tio Nando, grande amigo, mas a gente n�o se dava bem quando eramos crian�a, ele era dificil de lidar, hoje somos amigos no Facebook
        Dito grande primo, como eu sempre ia nos fins de semana na casa da Tia Mena somos bons amigos, ele que me ensinou a jogar fliperama oque mais alguns anos mais tarde seria meu primeiro emprego oficial, n�o tenho queixa dele, a n�o ser o fato que qualquer coisinha ele me batia, era maior que eu dois anos, eu nunca consegui bater nele, ele me levava no som do bairro dele mas nao era a minha praia
        Luiz primo mais proximo, n�o tenho queixas, nos damos sempre bem, nunca brigamos, nunca me bateu nem nunca bati nele, somos amigos no Facebook
        Cide grande primo, como era mais velho n�o tinhamos muito em comum mas o tio Paulo conta historias da conviv�ncia com ele, n�o tenho queixa, estava no casamento dele que dura at� hoje, mas n�o sei nome da filha
        Side filho do meu padrasto, grande colega, n�o tenho queixas dele
        Sanderson irm�o do Side, chorou muito quando o pai dele morreu semana passada, gostava muito do pai e estava na hora que a m�e descobriu que ele morreu, eu infelizmente n�o pude fazer nada, foi de repente
        Silvia irm� do Sanderson, n�o tenho queixa, nunca conversamos
        Vit�ria filha do Silvinho s� aparece algumas vezes, ou aparecia antes do v� dela falecer
        Renata ate onde eu sei � esposa do Silvinho, o filho bombeiro do Silvio que faleceu semana passada
        Carlinhos grande Crlinhos filho da Lurdes do Zeco, faziamos cada arte quando eramos crian�as que n�o da para por nos livros, amigos muito arteros os dele tamb�m no Xaxim em Curitiba
        Carlinhos meu ex-padrasto, faleceu a alguns meses, trabalhei com ele com pintura de carro, pessoa dificil, mas tinhamos boa amizade
        Jota irm�o do Carlinhos e tamb�m meu tio, sempre me levava pra pescar e era hil�rio, fui pescar na ilha da Galheta perto da ilha do Mel com ele, l� que eu aprendi oque � pescar meixe maior doque voc� pode tiar da �gua, os peixes era t�o grandes que os anzois abriam por incrivel que pare�a, foi muito legal, faleceu a algum tempo, pai do Polico que � gerente de empresa hoje em dia, uma vez eu vi o Polico prender o dedo numa porta de carro, fiquei com pena mas oque eu ia fazer, uma vez a Maristela minha terceira esposa prendeu sem quer o dedo da Thalia filha da minha segunda esposa na porta do carro e eu perdi o controle, foi triste, n�o tm coisa pior doque voce ver um filho sofrer e n�o poder fazer nada, ela colocou a menina no carro e foi batebdo a porta, s� podia dar nisso, agora os filhos dela ela colocava com jeito no carro, foi um momento triste da minha vida, por causa dessa briga ficamos uma semana separados mas o dela da Thalia que agora � juiza nem chegou a sair sangue igual do Polico que amassou de verdade
        Edson tio Edson, pessoa dificil, nunca fomos amigos, pensa que � mais doque eu, precisa aprender uma coisas sobre relaciomaneto com estranhos, se um dia for preso vai aprender na pris�o
        Rubinho tio irm�o do Carlinhos tamb�m, boa pessoa, mas nuncsa fomos pr�ximos, pai da Simone da Thais e do H�lio, n�o tenho queixa de nenhum deles, uma vez eu ajudei a desmontar uma casa de madeira com o Rub�ns e tambem ajudei a construir uma casa nova do Rubens
        Helinho filho do Rubinho e da S�nia, n�o vejo a S�nia d�cadas, grande amigo, mas nunca fomos pescar juntos, � uma pena
        Lurdes esposa do meu amigo Zeco, pessoa bacana, os filhos dela adora ela, e o pai deles tambem, faleceu a alguns anos, tive a oprtunidade de conversar com ele um pouco antes dele falecer, n�o tenho queixa do Zeco, mas uma vez eu tava na casa do meu padrinho Osmail e ele tava na cozinha e eu abri a geladeira e peguei um peda�o de lingui�a blumenau, ele ficou me olhando s�rio eu coloquei de volta a lingui�a e fechei a geladeira, foi a �nica vez que algu�m me deu uma bronca com o olhar
        Lurdes tia esposa do tio Nando, n�o tenho queixas, mas ela ficava possessa quando eu o o Paulinho filho dela nos estranhava-mos, e isso acontecia sempre, hoje nos damos bem os tr�s
        Waldemar v� Walmdemar, pessoa durona, n�o tenho queixa, e ele ajudou a socorrer a minha irm� Rejane quando ela se queimou com caf� e eu tava ao lado dela, era pra mim fazer o caf� mas ela se meteu e o caf� virou em cima dela ela era pequenina, um dos momentos mais tristes da minha vida porque eu n�o fazer nada, chamei o v� e ele come�ou a resolver o problema, quando a m�e chegou em casa ficou braba comigo mas que culpa eu tive?
        Robson grande irm�o, a gente dormia no mesmo colch�o at� os seis anos de idade, uma vez eu vi o Paulinho bater nele e n�o pude fazer nada porque ele era maior, era dificl conviver com os coleguinhas de Rio Branco do Sul, o Pulinho era um dos piores, e eu fui testemunha ocular do momento exato que o tio Paulo atirou um avi�o de plastico na dire��o do Robson e acertou o olho dele e ele come�ou a ter problemas de vis�o tenho a imagem na mente, e o Robson correndo na dire��o da m�e pra ver oque fazer, foi muito ruim
        Robson amigo do hospital psiquiatrico san julian, ele era meu amigo e sempre trazia uma coca gelada pra mim quando o meu dinheiro acabou, ele se apaixonou pela professora de musica, e disse que ia apostar todas as fichas nessa romance, interessante, ele me chamava de Bat
        Romel grande irm�o
        Regina dona do mercadinho que eu comprava as coisas quando morei no seminario, onde eu s� namorei uma menina em dois anos, mas ela era uma gatinha, n�o sei oque ela viu em mim, foi num colegio do bairro, muito legal, mas sobre a Regina, pessoa muito bacana e vendia pra gente mesmo sem dinheiro, virou quase da familia
        Regina esposa do Side, sempre jogavamos baralho quando eu estava 
        Filomena
        Siri
        Edenei
        Elcio
        Arliuze
        Julio
        Luiz
        Raul
        Hermano
        Andreia
        Thalia
        Aline
        Ericsson
        Marquinhos
        Arthur
        Arthur
        Rejane
        Julia
        Julia
        Maria
        Barbara
        Cassia
        Paulinho
        Cezinha
        Tata
        Ale
        MIslaine
        Marlene
        Soeli
        Maristela
        Toninho
        Celso
        Boi
        Negrinho
        Doca
        Linho
        Zezinha
        Denise
        Diva
        Dilson
        MAriane
        Cleyton
        Marilda
        MAriane
        Marilene
        Selma
        Edinho
        Edinho
        Elzinha
        Douglas
        Lucrecia
        Eliza
        C�lia
        C�lia
        Elisa
        Lucilene
        J�
        J�
        Jorge
        Jorge ?
        Mateus
        Mateus
        Cleusa
        Cleusa
        Kiko
        V� Santa
        Tio Pedro
        Orlei
        Orlei
        Anacleto
        Wilsinho
        Moises
        Anacleto
        Sebasti�o
        Felipe
        Fernando
        M�e do Lar
        Berenice
        Naufel
        Belmiro
        Madrinha Tereza
        Tio Pedro
        V� Pedro
        Madalena uma pessoa por que eu me apaixonei e nunca perguntei o nome dela
        Jaqueline
        Razera
        Andr�a
        Cristina
        Renato
        B�rbara
        Janete
        Fabio
        Paulo
        Ladinho
        Patrick
        Patrick
        Nat�lia
        Jefinho
        Ariel, esta � inesquecivel...
        Tentci
        Leoni
        Vera
        Vinicius

        















     */

     // Pedro is my grand grand father ...
     pedro_dprintf(-1, "he he he -> %s\n", decimalparabinario_64__amanda_s_smart_ape(mv_______->decoder_c___tio, true));
     /*



















     */

     mv_______->libav_c___j_again_call_j = false;

     if (mv_______->libav_c___m_packet_ptr)
     {
          just_free_libav_v(mv_______);
     }

     pedro_dprintf(-1, "chamado sim\n");
     (void)ConvertMP3ToWavExtended(converted_long_int_amanda_s_smart_ape, (void *)filename,
                                   (void *)"lpt1", 1,
                                   mv_______->decoder_c___track);
     while (1 != 0)
     {
          pedro_dprintf(-15102021, "entrando no loop len_m %d", strlen(message_amanda_s_smart_ape));
          Sleep(38); // correct...
          GetConversionInfo(converted_long_int_amanda_s_smart_ape, &percent_amanda_s_smart_ape, &finished_amanda_s_smart_ape, &returnvalue_amanda_s_smart_ape, message_amanda_s_smart_ape);
          pedro_dprintf(-15102021, "b.1");
          if (0 != finished_amanda_s_smart_ape)
          {
               pedro_dprintf(-15102021, "b.2");
               break;
          }
     }
     pedro_dprintf(-1, "depois 1");
     /////////////////////////////////////////////////////////////////////////////////

     {
          // here ?...
     }

     /////////////////////////////////////////////////////////////////////////////////

     pedro_dprintf(-15102021, "never appear here a");
     ret = morcego_init_libav(mv_______, be_real_real, play_as_mp3);
     pedro_dprintf(-1, "never appear here b");
     pedro_dprintf(-1, "Passou de morcego_init_libav");

     loading_z = false;
     pedro_dprintf(-1, "em player, carregou perfeitamente\n");
     if (ret)
     {
          strcpy(mv_______->decoder_c___morcego_libav_error, be_real_real->be_error_message);
          strncpy(mv_______->dsp_c___mode, " ", 254);
          strncpy(mv_______->dsp_c___mpeg, "0", 254);
          mv_______->decoder_c___bitrate = 0;
          returnvalue = 901;
          mv_______->decoder_c___cancelflag = 1;
          goto saida;
     }
     mv_______->decoder_c___isvbr = be_real_real->is_vbr;
     mv_______->decoder_c___bits_per_sample = be_real_real->be_bits_per_sample;
     samplerate = be_real_real->be_samplerate;
     mv_______->decoder_c___the_samplerate = samplerate;
     strncpy(mv_______->dsp_c___mode, be_real_real->be_mode, 254);
     mv_______->dsp_c___mode[254] = 0;
     strncpy(mv_______->dsp_c___layer, be_real_real->be_media_information, 254);
     mv_______->dsp_c___layer[254] = 0;
     mv_______->decoder_c___morcego_channels = be_real_real->be_channels;
     channels = 1;
     if (2 == mv_______->decoder_c___morcego_channels || 4 == mv_______->decoder_c___morcego_channels || 6 == mv_______->decoder_c___morcego_channels || 8 == mv_______->decoder_c___morcego_channels)
     {
          channels = 2;
     }
     mv_______->decoder_c___the_bitrate = be_real_real->be_bitrate;
     mv_______->decoder_c___bitrate = mv_______->decoder_c___the_bitrate;

     mv_______->decoder_c___seconds = be_real_real->be_seconds;
     mv_______->decoder_c___newsecond = mv_______->decoder_c___seconds;

     opened = 0;

     mv_______->decoder_c___intsamplerate = samplerate;
     if (mv_______->decoder_c___cancelflag)
     {
          goto saida;
     }
     if (0 != mv_______->decoder_c___internal_replaygain_fast_mode)
     {
          if (mv_______->decoder_c___intsamplerate < 8000 || mv_______->decoder_c___intsamplerate > 48000)
          {
               mv_______->decoder_c___globalfactor = 1.0;
               mv_______->decoder_c___analized = 1;
          }
          else
          {

               morcego_deinit_libav(mv_______);

               mv_______->libav_c___dont_do_video = 1;

               id3tag(mv_______, (char *)filename, 0, &mv_______->decoder_c___globalfactor,
                      &mv_______->decoder_c___analized, 0);

               mv_______->libav_c___dont_do_video = 0;

               if (mv_______->decoder_c___cancelflag)
               {
                    goto saida;
               }

               ret = morcego_init_libav(mv_______, be_real_real, play_as_mp3);

               if (mv_______->decoder_c___cancelflag)
               {
                    goto saida;
               }

               if (ret)
               {
                    strcpy(mv_______->decoder_c___morcego_libav_error, be_real_real->be_error_message);
                    strncpy(mv_______->dsp_c___mode, " ", 254);
                    strncpy(mv_______->dsp_c___mpeg, "0", 254);
                    mv_______->decoder_c___bitrate = 0;
                    returnvalue = 901;
                    mv_______->decoder_c___cancelflag = 1;
                    goto saida;
               }
          }
     }
     mv_______->decoder_c___wav.blockalign = ((channels * 16) / 8);
     mv_______->decoder_c___wav.bitspersample = 16;
     if (channels != 1 && channels != 2)
     {
          returnvalue = 25;
          mv_______->decoder_c___cancelflag = 1;
          goto saida;
     }
     if (samplerate < 7350 || samplerate > 96000)
     {
          returnvalue = 26;
          mv_______->decoder_c___cancelflag = 1;
          goto saida;
     }
     ret = getdev();
     if (!ret)
     {
          mv_______->decoder_c___cancelflag = 1;
          returnvalue = 9;
          goto saida2;
     }
     intchannels = channels;

     mv_______->decoder_c___newtime = mv_______->decoder_c___seconds;
     fixotime = mv_______->decoder_c___newtime * ((double)mv_______->decoder_c___intsamplerate * (double)4);
     deslocamento = 0;
     setvolume(mv_______, mv_______->decoder_c___valuetoset);
     mv_______->decoder_c___notloaded = 0;
     resetwaveeefects(mv_______);

     {

          if (0 == mv_______->decoder_c___multiplayer_or_not)
          {

               char *buf = calloc(100000, 1);
               soundtouch(mv_______, 1, 1, 44100, 2, 4, buf, 0, 0, 0);
               free(buf);
          }
     }

     {
          void freeverbinit(morcego___i___instance__a__bucaneiro_engineering * mv_______);
          if (!mv_______->decoder_c___multiplayer_or_not)
               freeverbinit(mv_______);
     }
     if (!mv_______->decoder_c___multiplayer_or_not)
     {
          void set_reverb_params(float roomsize, float damp, float wet,
                                 float dry, float width, float mode);
          set_reverb_params(0.5, 0.25, 0.333, 0.75, 1.0, 0);
     }
     mv_______->decoder_c___inttamanho = calculate_slice_player_23_06_2011(mv_______->decoder_c___intsamplerate);

     pedro_dprintf(-1, "mv_______->decoder_c___inttamanho %d", mv_______->decoder_c___inttamanho);
     // exit(25);

     while (mv_______->decoder_c___inttamanho % 32)
     {
          mv_______->decoder_c___inttamanho++;
     }

     {

          double val;
          val = (double)mv_______->decoder_c___inttamanho * 15.;

          val = val / mv_______->decoder_c___intsamplerate / 4;
          mv_______->decoder_c___valor_de_deslocamento_de_audio = val;
          pedro_dprintf(-1, "deslocamento %f %d\n", mv_______->decoder_c___valor_de_deslocamento_de_audio, mv_______->decoder_c___intsamplerate);
     }

     mv_______->decoder_c___just_clean_buffers = 1;

     play_number_1_26_june_2011(mv_______, NULL, 1);
     play_number_2_26_june_2011(mv_______, NULL, 1);
     play_number_3_26_june_2011(mv_______, NULL, 1);

     mv_______->decoder_c___just_clean_buffers = 0;

     mv_______->decoder_c___salvadata = 0;

     mv_______->decoder_c___loaded_player = 0;

     mv_______->decoder_c___clean_up_flag = 1;

     mv_______->decodec_c___function_play_position = 0;

     mv_______->decoder_c___newsecond_copy = 0;
     pedro_dprintf(-1, "never appear here c");

     mv_______->libav_c___m_already_seek = false;
     mv_______->libav_c___m_update_video = false;
     mv_______->libav_c___m_update_counter = 0;
     while (1)
     {
     retornaaqui:

          if (2 == DetectChangeInSoundCards_i_internal())
          {

               // aqui amor, vai l�aa....

               int ret_minha_amanda_da_albania_eh_pra_sempre = 0;

               mv_______->decoder_c___pwfx.wFormatTag = WAVE_FORMAT_PCM;

               mv_______->decoder_c___pwfx.nChannels = 2; /*
                                                                        hardcoded because even mono files are converted to stereo in order to play and multichannel files are mixed to play using only two channels (October/2020).
                                                                      */

               mv_______->decoder_c___pwfx.nSamplesPerSec =
                   mv_______->decoder_c___intsamplerate;

               mv_______->decoder_c___pwfx.nAvgBytesPerSec = (mv_______->decoder_c___intsamplerate * 4);
               mv_______->decoder_c___pwfx.nAvgBytesPerSec =
                   mv_______->decoder_c___wav.avebytespersec;
               mv_______->decoder_c___pwfx.nBlockAlign = 4;
               mv_______->decoder_c___pwfx.wBitsPerSample = 16; // hardcoded because even other values are converted to signed 16 bits in order to play at this moment, may change in the future, I am not sure...
               mv_______->decoder_c___pwfx.cbSize = 0;

               if (mv_______->decoder_c___phwo)
               {

                    waveOutReset(
                        mv_______->decoder_c___phwo);

                    ret_minha_amanda_da_albania_eh_pra_sempre = waveOutClose(mv_______->decoder_c___phwo);

                    if (ret_minha_amanda_da_albania_eh_pra_sempre == MMSYSERR_NOERROR)
                    {
                         mv_______->decoder_c___phwo = 0;
                    }
                    else
                    {

                         switch (ret_minha_amanda_da_albania_eh_pra_sempre)
                         {
                         case MMSYSERR_INVALHANDLE:
                              // dprintf("MMSYSERR_INVALHANDLE\n");
                              break;
                         case WAVERR_STILLPLAYING:

                              // dprintf("WAVERR_STILLPLAYING\n");
                              break;
                         case MMSYSERR_NOERROR:
                              // dprintf("MMSYSERR_NOERROR\n");
                              break;
                         case WAVERR_SYNC:
                              // dprintf("WAVERR_SYNC\n");
                              break;
                         case WAVERR_BADFORMAT:
                              // dprintf("WAVERR_BADFORMAT\n");
                              break;
                         case MMSYSERR_NOMEM:
                              // dprintf("MMSYSERR_NOMEM\n");
                              break;
                         case MMSYSERR_NODRIVER:
                              // dprintf("MMSYSERR_NODRIVER\n");
                              break;
                         case MMSYSERR_BADDEVICEID:
                              // dprintf("MMSYSERR_BADDEVICEID\n");
                              break;
                         default:
                              // dprintf("UNKNOWN\n");
                              break;
                         }
                    }
               }

               if (0 == mv_______->decoder_c___phwo)
               {
                    mv_______->decoder_c___intwaveout = 0;
                    // dprintf("waveOutOpen init\n");
                    ret_minha_amanda_da_albania_eh_pra_sempre =
                        waveOutOpen(&mv_______->decoder_c___phwo,
                                    mv_______->decoder_c___intwaveout,
                                    &mv_______->decoder_c___pwfx, (DWORD_PTR)callback, 0,
                                    CALLBACK_FUNCTION);

                    if (ret_minha_amanda_da_albania_eh_pra_sempre)
                    {
                         returnvalue = 2;
                         mv_______->decoder_c___cancelflag = 1;
                         goto saida;
                    }
               }
          }

          if (mv_______->decoder_c___seekto != -1)
          {
               /*if (method_is_internal_pcm)
               {
                    while (is_decoding)
                    {
                              Sleep (50);
                    }
               }*/

               mv_______->decoder_c___salvadata = 0;
               if (mv_______->decoder_c___phwo)
               {
                    ret = waveOutReset(mv_______->decoder_c___phwo);
                    ret = waveOutReset(mv_______->decoder_c___phwo);
                    if (mv_______->decoder_c___flag_de_pause)
                    {
                         ret = waveOutPause(mv_______->decoder_c___phwo);
                    }
               }
               if (mv_______->decoder_c___newtime != 0)
               {
                    if (mv_______->decoder_c___intismp3)
                    {
                         double retf;
                         didfixmp3 = 1;

#ifndef THALIA_NEW_STANDALONE_AUDIO_PLAYER__

                         morcego_seek_100_libav(mv_______, mv_______->decoder_c___seekto);

#else
                         if (mv_______->libav_c___m_mode_is_ffmpeg)
                         {
                              morcego_seek_100_libav(mv_______, mv_______->decoder_c___seekto);
                         }
                         else
                              svc_seek_opus_m(mv_______->libav_c___thalia_stand_alone_player_, mv_______->decoder_c___seekto);
#endif
                         mv_______->libav_c___m_already_seek = true;

                         retf = getvalf(fixotime,
                                        mv_______->decoder_c___seekto);
                         deslocamento = retf;
                    }
               }
               mv_______->decoder_c___seekto = -1;
               myptr = mv_______->decoder_c___globalbuf;
               size = 0;
               mv_______->decoder_c___ponto = 0;
          }
          if (waveflag == 0)
          {
               int p = 0;
               if ((p = initplayer(mv_______)))
               {
                    returnvalue = 2;
                    mv_______->decoder_c___cancelflag = 1;
                    goto saida;
               }
               // dprintf("valor de p %d\n",p);
               waveflag = 1;
          }
          setvolume(mv_______, mv_______->decoder_c___valuetoset);
          if (0 == mv_______->decoder_c___salvadata)
          {
               if (mv_______->decoder_c___intismp3)
               {
                    if (BE_DECODED_BUT_NO_MORE_SAMPLES_AVAILABLE ==
                        player_decoder_status)
                    {
                         // for MathMan pleasure...
                         goto saida;
                    }

#ifndef THALIA_NEW_STANDALONE_AUDIO_PLAYER__

                    player_decoder_status =
                        morcego_decode_libav(mv_______, 4096 - 4, (char *)out, &isize);
#else

                    if (mv_______->libav_c___m_mode_is_ffmpeg)
                    {
                         player_decoder_status =
                             morcego_decode_libav(mv_______, 4096, (char *)out, &isize);
                    }
                    else
                         player_decoder_status = morcego_decode_libav_svc_process_opus_m(mv_______->libav_c___thalia_stand_alone_player_,
                                                                                         4096,
                                                                                         (char *)out,
                                                                                         &isize);
#endif
                    pedro_dprintf(-1, "ret %d isize %d", player_decoder_status, isize);

                    if (BE_ERROR_DURING_DECODE == player_decoder_status)
                    {

                         returnvalue = 901;
                         mv_______->decoder_c___cancelflag = 1;
                         goto saida;
                    }

                    memcpy(mv_______->dsp_c___convbuffer, out, isize);

                    pedro_dprintf(-1, "isize %d", isize);

                    size = isize;
                    if (0 == mv_______->decoder_c___multiplayer_or_not)
                    {
                         size = soundtouch(mv_______, 0, mv_______->decoder_c___enablesoundtouch,
                                           mv_______->decoder_c___intsamplerate,
                                           intchannels, size,
                                           mv_______->dsp_c___convbuffer, mv_______->decoder_c___gtempo, mv_______->decoder_c___gpitch, mv_______->decoder_c___grate);
                    }
               }
          }
          else
          {
               size = 0;
          }
          if (mv_______->decoder_c___cancelflag)
          {
               goto saida;
          }
          if (1 == intchannels)
               size = PCM16MonoToPCM16Stereo(mv_______->dsp_c___convbuffer, size, mv_______->dsp_c___convbuffer);

          if (mv_______->decoder_c___bucaneiro_play_as_mono)
          {
               BucaneiroStereoToMono(mv_______->dsp_c___convbuffer, size);
          }
          if (mv_______->decoder_c___salvadata)
          {
               unsigned char *ptr;
               ptr = (unsigned char *)mv_______->dsp_c___convbuffer;
               ptr = ptr + mv_______->decoder_c___salvadata;
               memcpy(mv_______->decoder_c___tempbuf, mv_______->dsp_c___convbuffer, size);
               memcpy(mv_______->dsp_c___convbuffer, mv_______->decoder_c___salvbuffer, mv_______->decoder_c___salvadata);
               memcpy(ptr, mv_______->decoder_c___tempbuf, size);
               size = size + mv_______->decoder_c___salvadata;
               mv_______->decoder_c___salvadata = 0;
          }
          mv_______->decoder_c___ponto = mv_______->decoder_c___ponto + size;
          memcpy(myptr, (unsigned char *)mv_______->dsp_c___convbuffer, size);
          myptr += size;
          if (mv_______->decoder_c___ponto > mv_______->decoder_c___inttamanho)
          {
               unsigned char *ptr;
               ptr = (unsigned char *)mv_______->decoder_c___globalbuf;
               ptr = ptr + mv_______->decoder_c___inttamanho;
               mv_______->decoder_c___salvadata = mv_______->decoder_c___ponto - mv_______->decoder_c___inttamanho;
               memcpy(mv_______->decoder_c___salvbuffer, ptr, mv_______->decoder_c___salvadata);
               mv_______->decoder_c___ponto = mv_______->decoder_c___inttamanho;
          }
          pedro_dprintf(-1, "never appear here f");
          if (mv_______->decoder_c___ponto < mv_______->decoder_c___inttamanho)
          {
               ; // to remember forever...
          }
          else
          {

               if (mv_______->libav_c___video_ready_to_play)
               {
                    if (!mv_______->libav_c___initiate_playback)
                    {

                         if (!mv_______->decoder_c___intplayback)
                         {

                              mv_______->libav_c___pause_video_thread = 1;
                         }
                         if (mv_______->decoder_c___intloop)
                         {
                              mv_______->decoder_c___initial_init_playback_value = 1;
                         }

                         mv_______->libav_c___initiate_playback = 1;

                         mv_______->libav_c___audio_position_real = get_bucaneiro_tick();

                         mv_______->libav_c___posicaoinicial_do_audio = mv_______->libav_c___audio_position_real;
                    }
               }

#ifdef generate_white_noise
               if (1)
               {
                    int s;
                    char buffer2[48000];
                    short *desl;
                    sgenrand(GetTickCount());
                    memset(buffer2, 0, 48000);
                    s = 0;
                    desl = (short *)mv_______->decoder_c___globalbuf;
                    for (i = 0; i < (mv_______->decoder_c___ponto / 2); i++)
                    {
                         int j;
                         j = genrand();
                         s = 0;
                         if (j > 0)
                         {
                              s = 1;
                         }
                         j = j % 32000;
                         if (1 == s)
                         {
                              j = abs(j);
                         }
                         else
                         {
                              j = abs(j);
                              j = -j;
                         }
                         desl[i] = j;
                    }
               }
#endif

               if (/*podia ser if(*/ 0 != mv_______->decoder_c___internal_replaygain_fast_mode)
               {
                    if (mv_______->decoder_c___analized)
                    {

                         mygain((unsigned char *)mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, mv_______->decoder_c___globalfactor);
                         if (3 != mv_______->decoder_c___internal_replaygain_fast_mode)
                              mygain((unsigned char *)mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, 1.5);
                    }
               }
               if (mv_______->decoder_c___enablesurround)
               {

                    surround(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, mv_______->decoder_c___wav.bitspersample, 2);
               }
               if (mv_______->decoder_c___enablesurround2)
               {

                    if (mv_______->decoder_c___intsamplerate > limite_i)
                    {
                         surround2(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, mv_______->decoder_c___wav.bitspersample, 2);
                    }
               }
               if (mv_______->decoder_c___enablevoiceremoval)
               {
                    voiceremoval(mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, mv_______->decoder_c___wav.bitspersample, 2);
               }
               echofinal(mv_______, mv_______->decoder_c___multiplier, mv_______->decoder_c___enableecho, mv_______->decoder_c___ponto,
                         mv_______->decoder_c___globalbuf, mv_______->decoder_c___inttamanho, mv_______->decoder_c___wav.bitspersample, 2);
               if (mv_______->decoder_c___enablefreeverb && (!mv_______->decoder_c___multiplayer_or_not))
               {
                    freeverb(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, 0, 2, mv_______->decoder_c___wav.bitspersample, 2);
               }
               if (mv_______->decoder_c___enablepreamp)
               {

                    setvolume2(mv_______, (unsigned char *)mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto);
               }

               setvolume3(mv_______, (unsigned char *)mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto);
               /*
                  to avoid the Flush-to-zero x86 and x64 floating point problem that can cause the processor
                  usage to go up to 100% on 0 value samples (silence) */

               _MM_SET_FLUSH_ZERO_MODE2(_MM_FLUSH_ZERO_ON);
               //_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_OFF); to return to the standard mode

               // amanda_fix_dithering(mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto); // this was the fix before the _MM_SET_FLUSH_ZERO_MODE

               if (mv_______->decoder_c___enableequalizer)
               {
                    if (mv_______->decoder_c___wav.bitspersample == 16)
                    {

                         double amanda_tempo;
                         amanda_tempo = get_bucaneiro_tick();
                         iir(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, 2);

                         if (mv_______->decoder_c___doublebuffer)
                         {

                              iir___2(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, 2);
                         }

                         pedro_dprintf(-1, "tempo decorrido amanda2... %f", (get_bucaneiro_tick() - amanda_tempo) * 1000.);
                    }
               }
               if (mv_______->decoder_c___intismp3)
               {
                    double retf;
                    deslocamento = deslocamento + mv_______->decoder_c___ponto; // decoder_c___ponto need to be modified for SoundTouch support
                    // for video and audio sincronization with different tempo,
                    // just multiply the ratio of the data entering and exiting
                    // SoundTouch to this value, and the video will sinchronize
                    // perfectly

                    double val;

                    val = (double)mv_______->decoder_c___ponto / ((double)mv_______->decoder_c___intsamplerate * 4.0);

                    mv_______->decoder_c___newsecond_copy += val;

                    if (1 == mv_______->decoder_c___debug_flag)
                    {
                         Sleep(2500);

                         mv_______->decoder_c___debug_flag = 0;
                    }

                    deslocamento2 = deslocamento;
                    retf = deslocamento;
                    retf = retf - ((double)mv_______->decoder_c___inttamanho * 2.0) + 100.0;
                    if (retf < 0)
                    {
                         retf = 0;
                    }

                    newtempo = (double)retf / ((double)mv_______->decoder_c___intsamplerate * 4);
                    mv_______->decoder_c___newsecond = newtempo;
                    pedro_dprintf(-1, "setando tempo part 3 %f", newtempo);
               }
               if (mv_______->decoder_c___flag_de_pause && (mv_______->decoder_c___newsecond < 1.0))
               {
                    mv_______->decoder_c___newsecond = 0;
               }
               if (mv_______->decoder_c___cancelflag)
               {
                    goto saida;
               }
               if (mv_______->decoder_c___seekto != -1)
               {
                    goto retornaaqui;
               }
               if (funcao == 0)
               {
                    if (mv_______->decoder_c___intplayback && mv_______->decoder_c___flagdewave)
                    {
                         mv_______->decoder_c___pauseflag = 0;
                         mv_______->decoder_c___flag_de_pause = 0;
                         ret = waveOutRestart(mv_______->decoder_c___phwo);
                         mv_______->decoder_c___intplayback = 0;
                    }
                    if (mv_______->decoder_c___seekto != -1)
                    {
                         goto retornaaqui;
                    }

                    if (1)
                    {
                         if (0 == mv_______->decoder_c___flag_de_pause)
                         {
                              mv_______->decoder_c___liberafft = 0;
                         }

                         if (!mv_______->decoder_c___flag_de_pause)
                         {
                              mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
                              mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
                         }

                         if (mv_______->decoder_c___intismp3 && (!mv_______->decoder_c___flag_de_pause))
                         {
                              double retf;
                              deslocamento2 =
                                  deslocamento2 + ((double)mv_______->decoder_c___inttamanho / 4.0);
                              retf = deslocamento2;
                              retf = retf - ((double)mv_______->decoder_c___inttamanho * 2.0) + 100.0;
                              if (retf < 0)
                              {
                                   retf = 0;
                              }

                              newtempo =
                                  (double)retf / ((double)mv_______->decoder_c___intsamplerate * (double)4);

                              mv_______->decoder_c___newsecond = newtempo;
                              pedro_dprintf(-1, "setando tempo part 2 %f", newtempo);
                         }

                         if (mv_______->decoder_c___cancelflag)
                         {

                              goto saida;
                         }

                         while (mv_______->decoder_c___pauseflag)
                         {

                              if (mv_______->decoder_c___seekto != -1)
                              {

                                   goto retornaaqui;
                              }
                              Sleep(50);
                              if (mv_______->decoder_c___cancelflag)
                              {

                                   goto saida;
                              }
                         }

                         if (mv_______->decoder_c___seekto != -1)
                         {

                              goto retornaaqui;
                         }
                    }

                    size1 = mv_______->decoder_c___ponto;

                    // memcpy (peakchannel1, mv_______->decoder_c___globalbuf, 49000);

                    memcpy(mv_______->dsp_c___globalbuf1, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto);
                    funcao = 1;
                    if (mv_______->decoder_c___seekto != -1)
                    {

                         goto retornaaqui;
                    }

                    if (mv_______->decoder_c___intismp3)
                    {

                         if (didfixmp3)
                         {

                              didfixmp3 = 0;

                              memset(mv_______->dsp_c___globalbuf1, 0, 9000);
                         }
                    }
                    play(mv_______, (unsigned char *)mv_______->dsp_c___globalbuf1, size1);
                    goto pula;
               }
               if (funcao == 1)
               {
                    mv_______->decoder_c___flagdewave = 1;
                    if (mv_______->decoder_c___seekto != -1)
                    {
                         goto retornaaqui;
                    }

                    if (1)
                    {

                         if (!mv_______->decoder_c___flag_de_pause)
                         {
                              mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
                              mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
                         }

                         if (mv_______->decoder_c___intismp3 && (!mv_______->decoder_c___flag_de_pause))
                         {
                              double retf;
                              deslocamento2 =
                                  deslocamento2 + ((double)mv_______->decoder_c___inttamanho / 4.0);

                              retf = deslocamento2;
                              retf = retf - ((double)mv_______->decoder_c___inttamanho * 2.0) + 100.0;
                              if (retf < 0)
                              {

                                   retf = 0;
                              }

                              newtempo =
                                  (double)retf / ((double)mv_______->decoder_c___intsamplerate * (double)4);

                              mv_______->decoder_c___newsecond = newtempo;
                              pedro_dprintf(-1, "setando tempo part 1 %f %d %d", newtempo, mv_______->decoder_c___inttamanho, mv_______->decoder_c___intsamplerate);
                         }

                         if (mv_______->decoder_c___cancelflag)
                         {
                              goto saida;
                         }

                         while (mv_______->decoder_c___pauseflag)
                         {

                              if (mv_______->decoder_c___seekto != -1)
                              {

                                   goto retornaaqui;
                              }
                              Sleep(50);
                              if (mv_______->decoder_c___cancelflag)
                              {

                                   goto saida;
                              }
                         }

                         if (mv_______->decoder_c___seekto != -1)
                         {

                              goto retornaaqui;
                         }
                    }

                    // memcpy (peakchannel2, mv_______->decoder_c___globalbuf, 49000);

                    size2 = mv_______->decoder_c___ponto;
                    memcpy(mv_______->decoder_c___globalbuf2, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto);
                    funcao = 0;

                    if (mv_______->decoder_c___seekto != -1)
                    {

                         goto retornaaqui;
                    }
                    if (mv_______->decoder_c___intismp3)
                    {

                         if (didfixmp3)
                         {
                              didfixmp3 = 0;
                              memset(mv_______->decoder_c___globalbuf2, 0, 9000);
                         }
                    }
                    play(mv_______, (unsigned char *)mv_______->decoder_c___globalbuf2, size2);
                    goto pula;
               };
          pula:;
               myptr = mv_______->decoder_c___globalbuf;
               mv_______->decoder_c___ponto = 0;
          }
     }
saida:;
saida2:;

     mv_______->decoder_c___flagdewave = 1;
     if (mv_______->decoder_c___intplayback && mv_______->decoder_c___flagdewave && (!mv_______->decoder_c___cancelflag))
     {
          mv_______->decoder_c___pauseflag = 0;
          mv_______->decoder_c___flag_de_pause = 0;
          ret = waveOutRestart(mv_______->decoder_c___phwo);
          mv_______->decoder_c___intplayback = 0;
     }
     if (mv_______->decoder_c___intismp3 && (opened == 1))
     {
          opened = 0;
     }

     // setor finalizador
     if (mv_______->decoder_c___salvadata && (!mv_______->decoder_c___cancelflag))
     {
          memcpy(mv_______->decoder_c___globalbuf + mv_______->decoder_c___ponto, mv_______->decoder_c___salvbuffer, mv_______->decoder_c___salvadata);
          mv_______->decoder_c___ponto = mv_______->decoder_c___ponto + mv_______->decoder_c___salvadata;
          mv_______->decoder_c___salvadata = 0;
     }
     if ((!mv_______->decoder_c___cancelflag))
     {
          if (mv_______->decoder_c___analized)
          {
               mygain((unsigned char *)mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, mv_______->decoder_c___globalfactor);
               if (3 != mv_______->decoder_c___internal_replaygain_fast_mode)
                    mygain((unsigned char *)mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, 1.5);
          }

          if (mv_______->decoder_c___enablesurround)
          {

               surround(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, mv_______->decoder_c___wav.bitspersample, 2);
          }

          if (mv_______->decoder_c___enablesurround2)
          {
               if (mv_______->decoder_c___intsamplerate > limite_i)
               {
                    surround2(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, mv_______->decoder_c___wav.bitspersample, 2);
               }
          }

          if (mv_______->decoder_c___enablevoiceremoval)
          {
               voiceremoval(mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, mv_______->decoder_c___wav.bitspersample, 2);
          }
          echofinal(mv_______, mv_______->decoder_c___multiplier, mv_______->decoder_c___enableecho, mv_______->decoder_c___ponto, mv_______->decoder_c___globalbuf,
                    mv_______->decoder_c___inttamanho, mv_______->decoder_c___wav.bitspersample, 2);

          if (mv_______->decoder_c___enablefreeverb && (!mv_______->decoder_c___multiplayer_or_not))
          {

               freeverb(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, 0, 2, mv_______->decoder_c___wav.bitspersample, 2);
          }
     }

     if (mv_______->decoder_c___enablepreamp && (!mv_______->decoder_c___cancelflag))
     {

          setvolume2(mv_______, (unsigned char *)mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto);
     }

     if ((!mv_______->decoder_c___cancelflag))
     {

          setvolume3(mv_______, (unsigned char *)mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto);
     }

     if (mv_______->decoder_c___enableequalizer && (!mv_______->decoder_c___cancelflag))
     {
          if (mv_______->decoder_c___wav.bitspersample == 16)
          {
               iir(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, 2);
               if (mv_______->decoder_c___doublebuffer)
               {
                    // here
                    iir___2(mv_______, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto, 2);
               }
          }
     }

     if (mv_______->decoder_c___ponto && (!mv_______->decoder_c___cancelflag))
     {
          ;
          if (funcao == 0)
          {

               if (1)
               {

                    if (!mv_______->decoder_c___flag_de_pause)
                    {

                         mv_______->decoder_c___rightval = mv_______->decoder_c___spec.peak;
                         mv_______->decoder_c___leftval = mv_______->decoder_c___spec.peak;
                    }

                    // Sleep (50);
                    if (mv_______->decoder_c___cancelflag)
                    {
                         goto final;
                    }
                    while (mv_______->decoder_c___pauseflag)
                    {
                         if (mv_______->decoder_c___seekto != -1)
                         {
                              goto retornaaqui;
                         }
                         Sleep(50);
                         if (mv_______->decoder_c___cancelflag)
                         {
                              goto final;
                         }
                    }
               }
               size1 = mv_______->decoder_c___ponto;
               memcpy(mv_______->dsp_c___globalbuf1, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto);
               funcao = 1;

               pedro_dprintf(-1, "play 1 %d k_p", size1);
               pedro_dprintf(-1, "antes ");
               mv_______->decodec_c___last_pcm_slice_to_play_k_p = 1;
               if (returnvalue == 0 && mv_______->decoder_c___cancelflag == 0)
               {
                    mv_______->decoder_c___newsecond = mv_______->decoder_c___seconds;
               }
               play(mv_______, (unsigned char *)mv_______->dsp_c___globalbuf1, size1);
               goto pula1;
          }
          if (funcao == 1)
          {

               if (1)
               {

                    if (mv_______->decoder_c___cancelflag)
                    {
                         goto final;
                    }

                    while (mv_______->decoder_c___pauseflag)
                    {

                         if (mv_______->decoder_c___seekto != -1)
                         {

                              goto retornaaqui;
                         }
                         Sleep(50);
                         if (mv_______->decoder_c___cancelflag)
                         {

                              goto final;
                         }
                    }
               }
               size2 = mv_______->decoder_c___ponto;
               memcpy(mv_______->decoder_c___globalbuf2, mv_______->decoder_c___globalbuf, mv_______->decoder_c___ponto);
               funcao = 0;
               pedro_dprintf(-1, "play 12 %d k_p", size2);
               pedro_dprintf(-1, "antes ");
               mv_______->decodec_c___last_pcm_slice_to_play_k_p = 1;
               if (returnvalue == 0 && mv_______->decoder_c___cancelflag == 0)
               {
                    mv_______->decoder_c___newsecond = mv_______->decoder_c___seconds;
               }
               play(mv_______, (unsigned char *)mv_______->decoder_c___globalbuf2, size2);
               goto pula1;
          }
     }
pula1:;

     mv_______->decodec_c___last_pcm_slice_to_play_k_p = 1;
     if (returnvalue == 0 && mv_______->decoder_c___cancelflag == 0)
     {
          mv_______->decoder_c___newsecond = mv_______->decoder_c___seconds;
     }

     memset(mv_______->libav_c___empty_data, 0, 4);

     play(mv_______, (unsigned char *)mv_______->libav_c___empty_data, 4);

     // seria aqui meu amor?...
     pedro_dprintf(-1, "antes ok ");

     mv_______->libav_c___player_ar_only_one_frame_flag = 0;

     while (mv_______->libav_c___video_thread_running && (!mv_______->decoder_c___cancelflag))
     {
          mv_______->libav_c___audio_frame = -1;
          mv_______->libav_c___audio_finished = 1;

          Sleep(15);
          mv_______->libav_c___player_ar_only_one_frame_flag = 2;
     }

     morcego_deinit_libav(mv_______);
     pedro_dprintf(-1, "depois ok  ");
     /*
     if (mv_______->decoder_c___intloop == 1 && (!mv_______->decoder_c___cancelflag))
     {
          goto reinicia;
     }
     */
     if (!mv_______->decoder_c___cancelflag)
     {
          if (mv_______->decoder_c___cancelflag == 1)
          {
               goto final;
          }
     };
final:
     if (returnvalue == 0 && mv_______->decoder_c___cancelflag == 0)
     {
          mv_______->decoder_c___newsecond = mv_______->decoder_c___seconds;
     }

     if (mv_______->decoder_c___intismp3 && (opened == 1))
     {
          opened = 0;
     }
     memset(&mv_______->decoder_c___spec, 0, sizeof(mv_______->decoder_c___spec));

     // Sleep(5000);
     finalizeplayer(mv_______);
     pedro_dprintf(-1, "depois ");
     mv_______->decoder_c___notloaded = 0;
     mv_______->decoder_c___leftvalf = 0;
     mv_______->decoder_c___rightvalf = 0;
     finalize_effects_memory(mv_______);

     assert(NULL == mv_______->dsp_c___pitch_buffer);

     if (tempfilegerado)
     {
          _wunlink(permissive_name_m_(amanda_utf8towide_3_(tempname))); // bug found no utf-8 support
     }

     mv_______->decoder_c___spec.peak = 0; // why it is not always working my love?...
     mv_______->libav_c___video_ready_to_play = 0;

     mv_______->decoder_c___wave_out_open_flag = 0;

     if (mv_______->decoder_c___intloop == 1 && (!mv_______->decoder_c___cancelflag))
     {
          goto reinicia_z;
     }

     if (mv_______->libav_c___window_was_set______i)
     {
          if (mv_______->libav_c___is_desktop_playback_amanda)
          {
               SetWindowPos(
                   (HWND)(__INT32_OR_INT64)
                       mv_______->libav_c___player_hwnd,
                   WINDOW_FLAG___,
                   2,
                   2,
                   mv_______->libav_c___original_width__i - 2,
                   mv_______->libav_c___original_height_i - 2,
                   (SHOW_FLAG__));

               SetWindowPos(
                   (HWND)(__INT32_OR_INT64)
                       mv_______->libav_c___player_hwnd,
                   WINDOW_FLAG___,
                   0,
                   0,
                   mv_______->libav_c___original_width__i,
                   mv_______->libav_c___original_height_i,
                   (SHOW_FLAG__));

               if (!mv_______->libav_c___show_desktop_window_i)
               {
                    SetWindowPos(
                        (HWND)(__INT32_OR_INT64)
                            mv_______->libav_c___player_hwnd,
                        WINDOW_FLAG___,
                        0,
                        0,
                        mv_______->libav_c___original_width__i,
                        mv_______->libav_c___original_height_i,
                        (NO_SHOW_FLAG__));
               }
          }
     }

     return returnvalue;
}
