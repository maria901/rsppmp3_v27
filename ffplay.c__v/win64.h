
/********************************************************************************
 *                                                                              *
 *        Licensa de C?pia (C) <2021>  <Corpora??o do Trabalho Bin?rio>         *
 *                                                                              *
 *     Este  programa  ? software livre: voc? pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P?blica como       8
 *     publicado  pela Funda??o  de Software  Livre, tanto a vers?o 3  da       *
 *     Licensa, ou (dependendo da sua op??o) qualquer vers?o posterior.         *
 *                                                                              *
 *     Este  programa ? distribu?do na  esperan?a que isto vai  ser ?til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at? mesmo a implicada garantia de       *
 *     COMERCIALIZA??O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P?blica para mais detalhes.                                *
 *                                                                              *
 *     Voc? deve ter recebido uma  c?pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P?blica Menor junto com este programa                            *
 *     Se n?o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 ********************************************************************************

      E-mails:
      maria@arsoftware.net.br
      pedro@locacaodiaria.com.br

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito r?pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est? sempre ligado (eu acho...)                 *
 *                                                                              *
 *******************************************************************************/
 
#ifndef AB_WIN64_SUPPORT__
#define AB_WIN64_SUPPORT__	
	#ifdef _M_X64
	#define __INT32_OR_INT64 __int64
	#ifdef __GNUC__
	 //#warning size of __INT32_OR_INT64 is 8
	#else
	 //#pragma message ( "size of __INT32_OR_INT64 is 8" )
	#endif
	#else

	#define __INT32_OR_INT64 int
	#ifdef __GNUC__
	 //#warning size of __INT32_OR_INT64 is 4
	#else
	 //#pragma message ( "size of __INT32_OR_INT64 is 4" )
	#endif
	#endif
#endif