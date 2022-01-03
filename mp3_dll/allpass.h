// Allpass filter declaration
//
// Written by Jezar at Dreampoint, June 2000
// http://www.dreampoint.co.uk
// This code is public domain

/********************************************************************************
 *                                                                              *
 *        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>         *
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
