/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                             *
*        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>        *
*                                                                             *
*     Este  programa  é software livre: você pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     10
*     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opção) qualquer versão posterior.        *
*                                                                             *
*     Este  programa é distribuído na  esperança que isto vai  ser útil,      *
*     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de      *
*     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Pública para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Pública Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito rápida) WhatsApp               *
*     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
  
extern unsigned __int64 __stdcall Int64ShllMod32 (unsigned __int64 Value,
						  unsigned long ShiftCount);
extern __int64 __stdcall Int64ShraMod32 (__int64 Value,
					 unsigned long ShiftCount);
extern unsigned __int64 __stdcall Int64ShrlMod32 (unsigned __int64 Value,
						  unsigned long ShiftCount);
extern void *__cdecl GetFiberData (void);
extern void *__cdecl GetCurrentFiber (void);
extern int __cdecl checkoverflow_minuschar2 (char a, char b, char *result);
extern int __cdecl checkoverflow_minuschar (char a, char b, char *result);
extern int __cdecl checkoverflow_pluschar (char a, char b, char *result);
extern void __cdecl mprintf (char *format, ...);
extern int __cdecl fix8 (int value);
extern int __cdecl fix4 (int value);
extern int __cdecl fix2 (int value);
extern int __cdecl rspparser (char *instring, char *delimiter,
			      char *returnstring, int comand);
extern int __cdecl stripfilenameandpath (char *path, char *onlypath,
					 char *onlyfilename);
extern int __cdecl octaltoint (char *p);
extern char *__cdecl inttooctal (unsigned int value, int numberofitens);
static int __cdecl getbits (unsigned int value, unsigned int bit);
extern int __cdecl setbits (unsigned int value, unsigned int bit,
			    unsigned int bitvalue);
extern int __cdecl newsetbits (unsigned int value, unsigned int bit,
			       unsigned int bitvalue);
extern unsigned int __cdecl binarioparadecimal (char *binval);
extern char *__cdecl decimalparabinarioprintf (unsigned int value);
extern char *__cdecl decimalparabinario (unsigned int value);
extern char *__cdecl decimalparabinarioold (unsigned int value);
extern char __cdecl pegaultimocaracter (char *path);
extern double __cdecl inittimer2 (int value);
extern float __cdecl inittimer (unsigned int comando);
extern int __cdecl rspgetdrivetype (char *path1);
extern char *__cdecl rspgetcomputername ();
extern int __cdecl rspsetcurrentdirectory (char *path);
extern char *__cdecl rspgetcurrentdirectory ();
extern char *__cdecl rspgetsystemdirectory ();
extern char *__cdecl rspgetwindowsdirectory ();
extern char *__cdecl rspgettemppath ();
extern int __cdecl getfilesize (char *infile);
extern unsigned int __cdecl getval (int max, unsigned int por);
extern unsigned int __cdecl getmax (int por, unsigned int fatia);
extern unsigned int __cdecl getpor (int max, unsigned int fatia);
extern int __cdecl contastringinsensitive (char *comando, char *string);
extern int __cdecl contastringsensitive (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive (char *comando, char *string);
extern int __cdecl procuradordestringsensitive (char *comando, char *string);
extern int __cdecl procuradordestringinsensitive (char *comando,
						  char *string);
extern int __cdecl checkmaxsize (char *comando);
extern void __cdecl stripspace (char *intcomando);
extern void __cdecl trocadordebackslashtras (char *path);
extern void __cdecl trocadordebackslashfrente (char *path);
extern void __cdecl adicionadordebackslashtras (char *path);
extern void __cdecl adicionadordebackslashfrente (char *path);
extern void __cdecl removedordeespaconofinal (char *path);
extern void __cdecl removedordecaracternofinal (char *path, char caracter);
extern void __cdecl removedordecaracternoinicio (char *path, char caracter);
extern void __cdecl removedordeespaconoinicio (char *path);
extern void __cdecl changecharacter (char *path, char itemtosearch,
				     char finalcharacter);
extern int __cdecl countitens (char *comand, char item);
extern void __cdecl strtolower (char *path);
extern void __cdecl strtoupper (char *path);
extern int __cdecl testdirectory (char *path);
extern int __cdecl createtestfilename (char *path1);
extern int __cdecl pathexists (char *path);
extern int __cdecl ispathreadonly (char *path);
extern int __cdecl ispathfolder (char *path);
extern int __cdecl ispathfile (char *path);
extern void __cdecl geterrorstringrspmakedir (int errorcode, char *path);
extern int __cdecl rspmakedirUNIX (char *destination, char *path);
extern int __cdecl rspmakedir (char *path);
extern char *__cdecl validanomedearquivoerrorstring ();
extern int __cdecl validanomedearquivo (char *path);
extern char *__cdecl validatefoldertocreateerrorstring ();
extern int __cdecl validatefoldertocreate (char *path);
extern int __cdecl rspposicaofixa (int mode, int value);
extern int __cdecl wildcardselection (const char *path, const char *string1);
