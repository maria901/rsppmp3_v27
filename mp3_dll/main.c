/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                             *
*        Licensa de C�pia (C) <2022>  <Corpora��o do Trabalho Bin�rio>        *
*                                                                             *
*     Este  programa  � software livre: voc� pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como     10
*     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da      *
*     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.        *
*                                                                             *
*     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,      *
*     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de      *
*     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral P�blica para mais detalhes.                               *
*                                                                             *
*     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa P�blica Menor junto com este programa                           *
*     Se n�o, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito r�pida) WhatsApp               *
*     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
  
#pragma warning( disable : 4101 )
#pragma warning( disable : 4102 )
#pragma warning( disable : 4018 )

#pragma comment (lib,"user32.lib")

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <conio.h>

// #define NDEBUG

#undef NDEBUG
#include <assert.h>



void
dprintf_z (const char *format, ...)
{
//#line 353
//#error  C2059: syntax error : '}'
#ifdef RSPDEBUG

  {

    int rete;
    va_list args;
    static char buffer[1000000];
    int ret;

    rete = GetLastError ();

    va_start (args, format);
    ret = vsprintf (buffer, format, args);
    OutputDebugString (buffer);
    printf (buffer);

//setmessage (501, buffer);
//rspsendmessage ();

    SetLastError (rete);

  }
#else

  return;
#endif


}

typedef int (__stdcall * PlayMp3) (int number, char *filename, int loop);
PlayMp3 PlayMp3_f;



int
main ()
{

  HMODULE hmod;

  int funcao = 0;









  hmod = LoadLibrary ("rspmp3ocx1.dll");

  if (0 == hmod)
    {
      //dprintf_z ("Error loading dll\n");
      goto saida;
    }



  PlayMp3_f = (void *) GetProcAddress (hmod, "PlayMp3");

  PlayMp3_f (4, "c:\\orinoco.mp3", 0);
  PlayMp3_f (5, "c:\\orinoco.mp3", 0);



  while (1)
    {
      int ret;

      //printf("Vai chamar getchar\n");
      ret = getch ();

      if ('q' == ret)
	{
	  break;
	}

    }




saida:
  //dprintf_z ("saindo\n");
  return 0;
}
