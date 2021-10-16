/*HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH*/

WCHAR* __stdcall utf8towide (const char *pUTF8 );
//function definitions


extern int __cdecl checkoverflow_minuschar2 (char a, char b, char *result);
extern int __cdecl checkoverflow_minuschar (char a, char b, char *result);
extern int __cdecl checkoverflow_pluschar (char a, char b, char *result);
extern void __cdecl mprintf (char *format, ...);
extern int __cdecl fix8 (int value);
extern int __cdecl fix4 (int value);
extern int __cdecl fix2 (int value);
extern int __cdecl rspparser (char *instring, char *delimiter, char *returnstring, int comand);
extern int __cdecl stripfilenameandpath (char *path, char *onlypath, char *onlyfilename);
extern int __cdecl octaltoint (char *p);
extern char *__cdecl inttooctal (unsigned int value, int numberofitens);
static int __cdecl getbits (unsigned int value, unsigned int bit);
extern int __cdecl setbits (unsigned int value, unsigned int bit, unsigned int bitvalue);
extern int __cdecl newsetbits (unsigned int value, unsigned int bit, unsigned int bitvalue);
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
static void __cdecl replacespacewithchar (char *temp, char init, char out, int len);
extern int __cdecl contastringinsensitive (char *comando, char *string);
extern int __cdecl contastringsensitive (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive (char *comando, char *string);
extern int __cdecl procuradordestringsensitive (char *comando, char *string);
extern int __cdecl procuradordestringinsensitive (char *comando, char *string);
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
extern void __cdecl changecharacter (char *path, char itemtosearch, char finalcharacter);
extern int __cdecl countitens (char *comand, char item);
extern void __cdecl strtolower (char *path);
extern void __cdecl strtoupper (char *path);
extern int __cdecl testdirectory (char *path);
extern int __cdecl createtestfilename (char *path1);
extern int __cdecl pathappearsvalid (char *path);
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


extern int __cdecl round_trick2 (float floatvalue_to_round);
extern void __cdecl init_iir2 ();
extern int __cdecl iir2 (char *d, int length, int channels);
extern int __cdecl iir_fixed2 (char *d, int length);
extern int __cdecl configequalizer2 (int b60, int b170, int b310, int b600, int b1000, int b3000, int b6000, int b12000, int b14000, int b16000);


extern int __cdecl round_trick (float floatvalue_to_round);
extern void __cdecl init_iir ();
extern int __cdecl iir (char *d, int length, int channels);
extern int __cdecl iir_fixed (char *d, int length);
extern int __cdecl configequalizer (int b60, int b170, int b310, int b600, int b1000, int b3000, int b6000, int b12000, int b14000, int b16000);


extern int __cdecl getdev ();
extern int __cdecl initplayer ();
extern int __cdecl play (unsigned char *buf, unsigned int len);
extern int __cdecl play1 (unsigned char *buf, unsigned int len);
extern int __cdecl finalizeplayer ();
extern int __cdecl setvolume3 (unsigned char *buf, unsigned int len);
extern int __cdecl setvolume2 (unsigned char *buf, unsigned int len);
extern int __cdecl decodeogg (unsigned char *filename);
extern int __stdcall startapi2 (int parameter);
extern int __stdcall playogg ();
extern int __stdcall pause ();
extern int __stdcall resume ();
extern int __stdcall cancel ();
//extern int __stdcall DllMain (void *hModule, unsigned long ul_reason_for_call, void *lpReserved);
extern int __cdecl setvolume (int newvalue);
extern int __stdcall getdevicename (unsigned char *nome, unsigned int devicenumber);
extern int __cdecl checkinit ();
extern int __stdcall interface1 (int argumento1, int argumento2, int argumento3, int argumento4);


extern int __cdecl id3tag (char *filename, int mode, float *iglobalfloat, int *ianalized, int convertmode);
extern int __cdecl id3tagcheck (char *filename);

extern int __cdecl checkoverflow_minuschar2 (char a, char b, char *result);
extern int __cdecl checkoverflow_minuschar (char a, char b, char *result);
extern int __cdecl checkoverflow_pluschar (char a, char b, char *result);
extern void __cdecl mprintf (char *format, ...);
extern int __cdecl fix8 (int value);
extern int __cdecl fix4 (int value);
extern int __cdecl fix2 (int value);
extern int __cdecl rspparser (char *instring, char *delimiter, char *returnstring, int comand);
extern int __cdecl stripfilenameandpath (char *path, char *onlypath, char *onlyfilename);
extern int __cdecl octaltoint (char *p);
extern char *__cdecl inttooctal (unsigned int value, int numberofitens);
static int __cdecl getbits (unsigned int value, unsigned int bit);
extern int __cdecl setbits (unsigned int value, unsigned int bit, unsigned int bitvalue);
extern int __cdecl newsetbits (unsigned int value, unsigned int bit, unsigned int bitvalue);
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
static void __cdecl replacespacewithchar (char *temp, char init, char out, int len);
extern int __cdecl contastringinsensitive (char *comando, char *string);
extern int __cdecl contastringsensitive (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive (char *comando, char *string);
extern int __cdecl procuradordestringsensitive (char *comando, char *string);
extern int __cdecl procuradordestringinsensitive (char *comando, char *string);
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
extern void __cdecl changecharacter (char *path, char itemtosearch, char finalcharacter);
extern int __cdecl countitens (char *comand, char item);
extern void __cdecl strtolower (char *path);
extern void __cdecl strtoupper (char *path);
extern int __cdecl testdirectory (char *path);
extern int __cdecl createtestfilename (char *path1);
extern int __cdecl pathappearsvalid (char *path);
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