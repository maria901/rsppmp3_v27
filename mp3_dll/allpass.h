// Allpass filter declaration
//
// Written by Jezar at Dreampoint, June 2000
// http://www.dreampoint.co.uk
// This code is public domain

/********************************************************************************
 *                                                                              *
 *        Licensa de C�pia (C) <2022>  <Corpora��o do Trabalho Bin�rio>         *
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
 
#ifndef _allpass_
#define _allpass_
#include "denormals.h"

class allpass
{
public:
  allpass ();
  void setbuffer (float *buf, int size);
  inline float process (float inp);
  void mute ();
  void setfeedback (float val);
  float getfeedback ();
// private:
  float feedback;
  float *buffer;
  int bufsize;
  int bufidx;
};


// Big to inline - but crucial for speed

inline float
allpass::process (float input)
{
  float output;
  float bufout;

  bufout = buffer[bufidx];

  //undenormalise (bufout);

  output = -input + bufout;
  buffer[bufidx] = input + (bufout * feedback);

  if (++bufidx >= bufsize)
    bufidx = 0;

  return output;
}

#endif //_allpass

//ends
