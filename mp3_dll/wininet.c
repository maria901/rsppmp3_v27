
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *                                                                                *
  *      Licensa de Cópia (C) <202*>  <Corporação do Trabalho Binário>             *
  *                                                                                *
  *   Este programa é software livre: você pode redistribuir isto e/ou modificar   *
  *   isto sobre os termos do GNU Licensa Geral Pública como publicado pela        *
  *   Fundação de Software Livre, tanto a versão 3 da Licensa, ou                  *
  *   (dependendo da sua opção) qualquer versão posterior.                         *
  *                                                                                *
  *   Este programa é distribuído na esperança que isto vai ser útil,              *
  *   mas SEM QUALQUER GARANTIA; sem até mesmo a implicada garantia de             *
  *   COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
  *   Licensa Geral Pública para mais detalhes.                                    *
  *                                                                                *
  *   Você deve ter recebido uma cópia da LICENSA GERAL PUBLICA                    *
  *       e a GNU Licensa Pública Menor junto com este programa                    *
  *       Se não, veja <http://www.gnu.org/licenses/>.                             *
  *                                                                                *
  *   Suporte: https://arsoftware.net.br/binarywork ____________________           *
  *   Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/           *
  *             http://nomade.sourceforge.net/binarywork/ ______________            *
  *                                                                                *
  *       e-mails direto dos felizes programadores:                                *
  *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
  *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
  *                                                                                *
  *       contato imediato(para uma resposta muita rápida) WhatsApp                *
  *       (+55)41 9627 1708 - isto está sempre ligado                              *
  *                                                                                *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif


#pragma warning( disable : 4101 )
#pragma warning( disable : 4102 )
#pragma warning( disable : 4018 )

#include <windows.h>
#include <stdio.h>
#include <math.h>
//#include <unistd.h>
#include <limits.h>
#include <time.h>

#undef NDEBUG
#include <assert.h>
#include <string.h>
#include <mmsystem.h>
#include <float.h>
#include <stdlib.h>

#include <wininet.h>
#include <conio.h>
#pragma comment (lib,"winmm.lib")

#pragma comment (lib,"wininet.lib")


#pragma comment (lib,"advapi32.lib")

#pragma comment (lib,"user32.lib")

void dprintf_z (const char *format, ...);
extern int __cdecl invertbits32 (int value);
extern short __cdecl invertbits16 (short value);
extern int __cdecl createtempfilename (char *path1, char *destfile);
extern int __cdecl detect_readonly_file (char *filename);
extern int __cdecl fix_filesize (char *filename, int len);
extern void __cdecl replace_char_binary (char *temp, char init, char out,
                                         int len);
extern int __cdecl rsp_get_error (char *buffer);
extern void __cdecl rsp_error_print ();
extern int __cdecl checkoverflow_minuschar2 (char a, char b, char *result);
extern int __cdecl checkoverflow_minuschar (char a, char b, char *result);
extern int __cdecl checkoverflow_pluschar (char a, char b, char *result);
extern void __cdecl mprintf (char *format, ...);
extern int __cdecl fix8 (int value);
extern int __cdecl fix4 (int value);
extern int __cdecl fix2 (int value);
extern int __cdecl rspparser (char *instring, char *delimiter,
                              char *returnstring, int comand);
extern void __cdecl stripfilenameandpath_url (char *path, char *onlypath,
                                              char *onlyfilename);
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
extern int __cdecl save_to_file (char *infile, char *data, int size, int mode,
                                 int limit);
extern int __cdecl getfilesize (char *infile);
extern unsigned int __cdecl getval (int max, unsigned int por);
extern double __cdecl getvalf (double maxa, double porr);
extern unsigned int __cdecl getmax (int por, unsigned int fatia);
extern unsigned int __cdecl getpor (int max, unsigned int fatia);
extern double __cdecl getporf (double maxa, double fatiaa);
extern int __cdecl contastringinsensitive (char *comando, char *string);
extern int __cdecl contastringsensitive (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal (char *comando, char *string);
extern int __cdecl pegaposicaoinsensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive (char *comando, char *string);
extern int __cdecl pegaposicaosensitive_new (char *comando, char *string);
extern int __cdecl pegaposicaosensitivefinal_new (char *comando,
                                                  char *string);
extern int __cdecl procuradordestringsensitive (char *comando, char *string);
extern int __cdecl procuradordestringinsensitive (char *comando,
                                                  char *string);
extern int __cdecl checkmaxsize (char *comando);
extern void __cdecl stripchar (char *intcomando, char caracter);
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
extern int __cdecl pathappearsvalid (char *path);
extern int __cdecl ispathreadonly (char *path);
extern int __cdecl ispathfolder (char *path);
extern int __cdecl ispathfilepartial (char *path);
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
extern void __cdecl sgenrand (unsigned long seed);
extern int __cdecl genrand ();
extern int __cdecl genrand_sinal (int fatia);

/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


extern char *__cdecl base64Encode (char *tgt, unsigned char *src);
extern void __cdecl rsp_error ();
extern void __cdecl rsp_error_val (int value);
extern void __cdecl rsp_net_error (void);
extern int __cdecl print_wininet_error ();
extern void __cdecl parse_error (char *temp);
extern int __stdcall keyboard (int parameter);
extern int __stdcall init ();
extern void __cdecl replacespacewithchar (char *temp, char init, char out,
                                          int len);
extern int __cdecl print_header_response (int response);
extern int __cdecl convert_header (char *header, int *stat, int *lenght);
extern int __stdcall http ();

extern int __cdecl main ();

int __stdcall ftp (int parameter);

int save_to_file (char *infile, char *data, int size, int mode, int limit);


void replacespacewithchar (char *temp, char init, char out, int len);

int pathappearsvalid (char *path);

int validatefoldertocreate (char *path);


int stripfilenameandpath (char *path, char *onlypath, char *onlyfilename);
int pegaposicaoinsensitivefinal (char *comando, char *string);

void stripfilenameandpath_url (char *path, char *onlypath,
                               char *onlyfilename);


/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/



// flag para saber se esta executando
static int isrunning = 0;


int internetrunning = 0;

int isdownloading = 0;

/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/



extern void removedordeespaconoinicio (char *path);

HINTERNET hInternetFile = NULL;

HINTERNET m_hSession = NULL;

HINTERNET findfile = NULL;

HINTERNET ftph = NULL;


int flagexit = 0;


int intcancel = 0;

int intpause = 0;

int intporcentagem = 0;





/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


void
rsp_error ()
{
	char lpMsgBuf[260];
	int value = GetLastError ();
	int ret;

	ret = FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM |
	                     FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
	                     GetLastError (), 0, (LPTSTR) &lpMsgBuf, 256, NULL);

	if (ret && value)
	{

		replacespacewithchar (lpMsgBuf, '\r', ' ', 257);

		replacespacewithchar (lpMsgBuf, '\n', ' ', 257);
#ifdef NPRINTF
		//dprintf_z ("200 System error : %d %s \n", value, lpMsgBuf);
#endif
	}

	SetLastError (value);

}

/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


void
rsp_error_val (int value)
{
	char lpMsgBuf[257];
	// int value = GetLastError ();
	int ret;

	ret = FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM |
	                     FORMAT_MESSAGE_IGNORE_INSERTS, NULL, value, 0,
	                     (LPTSTR) &lpMsgBuf, 256, NULL);

	if (ret)
	{
#ifdef NPRINTF
		//dprintf_z ("%d %s \n", value, lpMsgBuf);
#endif
	}
	SetLastError (value);
}

/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


void
rsp_net_error ()
{

	char strName[300] = "";
	int ret;
	int dError;

	dError = GetLastError ();


	ret = FormatMessage (FORMAT_MESSAGE_FROM_HMODULE,
	                     GetModuleHandle ("wininet.dll"), dError, 0,
	                     (LPSTR) strName, 256, NULL);

	if (ret && (dError != 12003))
	{
		replacespacewithchar (strName, '\r', ' ', 299);

		replacespacewithchar (strName, '\n', ' ', 299);
#ifdef NPRINTF
		//dprintf_z ("201 WinInet Error : %d %s \n", dError, strName);
#endif

	}

	SetLastError (dError);
}

/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


int __stdcall
keyboard (int parameter)
{

	//  return 0;
#ifdef NPRINTF
	//dprintf_z ("->Keyboard activated <- \n");
#endif
	while (1)
	{
		int ret;

		//char ret = getchar();


		int c = getch ();
		//goto saida;
		//dprintf_z("item pego %d \n", c);
		//while (getch() != 'q');

		if (c == 'p')
		{

			intpause = 1;

		}

		if (c == 'r')
		{

			intpause = 0;

		}

		if (c == 'c')
		{

			intcancel = 1;

		}

		if (c == 'q')
		{

			flagexit = 1;
		}



saida:

		//dprintf_z ("Thread running 1 \n");

		Sleep (50);

	}


}


/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


int __stdcall
init ()
{

	static HANDLE myhandle;
	static int ThreadId;
	static int parameter = 1;



	// ////;//drprintf2 ("Crinado uma thread agora \n ");

	myhandle =
		CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0,
		              (LPTHREAD_START_ROUTINE) keyboard,
		              (LPVOID) parameter, 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 0;
}





/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/



int
start_web ()
{

	static HANDLE myhandle;
	static int ThreadId;
	static int parameter = 1;



	// ////;//drprintf2 ("Crinado uma thread agora \n ");

	myhandle =
		CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0,
		              (LPTHREAD_START_ROUTINE) http,
		              (LPVOID) parameter, 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 0;
}




/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/



void
replacespacewithchar (char *temp, char init, char out, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{

		if (temp[i] == init)
		{
			temp[i] = out;
		}

	}


}


/*HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH*/



char strURL[10000] = "";


char filetosave[2000] = "";


/*HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH*/



int __stdcall
http ()
{

	int is_http = 1;
	int status = 0;
	int len = -1;
	int tamanho = 0;




	//ftp://ftp.kernel.org/pub/index.html char strURL[] = "http://rspsoftware.clic3.net/rogps2790.zip";

	//CHAR   strURL[] = "ftp://ftp.us.kernel.org/pub/linux/utils/cpu/crusoe/longrun-0.9.tar.gz";
//ftp://ftp.us.kernel.org/pub/linux/utils/cpu/crusoe/longrun-0.9.tar.gz
	//CHAR strURL[] = "http://rspsoftware.clic3.net/main.html";

	HANDLE f;
	DWORD dwRead, dwWritten;
	CHAR szTemp[4097];
	int ret;
	HMODULE mod = NULL;
	HINSTANCE ints = NULL;



#ifdef NPRINTF
	//dprintf_z ("filename %s \n", filetosave);

	//dprintf_z ("URL %s \n", strURL);
#endif

	mod = GetModuleHandle ("wininet.dll");

	if (NULL == mod)
	{

		ints = LoadLibrary ("wininet.dll");

		if (NULL == ints)
		{
			internetrunning = 0;
			internetrunning = 0;
			isdownloading = 0;
#ifdef NPRINTF
			//dprintf_z ("Cannot load required dll to access the Internet \n");
#endif
			return 1; //canot load wininet dll

		}

	}


	m_hSession =
		InternetOpen ("RSP_Software_Agent/1.0 ",
		              INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);


	if (NULL == m_hSession)
	{

		int i;

		ret = GetLastError ();

		rsp_error ();
		internetrunning = 0;
		internetrunning = 0;
		isdownloading = 0;
		return 2;

	}
#ifdef NPRINTF
	//dprintf_z ("Depois de InternetOpen \n");
#endif

	hInternetFile =
		InternetOpenUrl (m_hSession, (LPCTSTR) strURL, NULL, 0,
		                 INTERNET_FLAG_RELOAD |
		                 INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_PASSIVE, 0);

	if (hInternetFile == NULL)
	{

		int ret;
		int a, b;
		char temp[256];

		b = 256;

		ret = GetLastError ();

		rsp_error ();

		if (ret == ERROR_INTERNET_EXTENDED_ERROR)
		{

			goto direto;
		}
		rsp_net_error ();

direto:

		if (GetLastError () == ERROR_INTERNET_EXTENDED_ERROR)
		{

			ret = InternetGetLastResponseInfo (&a, temp, &b);

			if (ret)
			{

				if (strlen (temp))
				{
#ifdef NPRINTF
					//dprintf_z ("%d %s \n", a, temp);
#endif

				}
			}

		}

		if (m_hSession)
		{
			ret = InternetCloseHandle (m_hSession);
#ifdef NPRINTF
			//dprintf_z ("Fechou handle de m_hSession ? %d \n", ret);
#endif

			m_hSession = 0;
		}
		internetrunning = 0;
		internetrunning = 0;
		isdownloading = 0;
		return 3;       //internetopenurl error

	}

#ifdef NPRINTF
	//dprintf_z ("Depois de InternetOpenUrl \n");

	//dprintf_z ("Vai tentar abrir arquivo \n");
#endif

	f = CreateFile (filetosave, GENERIC_READ | GENERIC_WRITE,
	                FILE_SHARE_WRITE | FILE_SHARE_READ, NULL,
	                CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	// f = CreateFile (filetosave, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_NO_BUFFERING, NULL);


	if (f == INVALID_HANDLE_VALUE)
	{

		int ret;
		int a, b;
		char temp[256];

		b = 256;

		ret = GetLastError ();

		rsp_error ();

		if (ret == ERROR_INTERNET_EXTENDED_ERROR)
		{

			goto direto3;
		}
		rsp_net_error ();

direto3:

		if (GetLastError () == ERROR_INTERNET_EXTENDED_ERROR)
		{

			ret = InternetGetLastResponseInfo (&a, temp, &b);

			if (ret)
			{

				if (strlen (temp))
				{
#ifdef NPRINTF
					//dprintf_z ("%d %s \n", a, temp);
#endif

				}

			}
		}

		if (hInternetFile)
		{
			ret = InternetCloseHandle (hInternetFile);
#ifdef NPRINTF
			//dprintf_z ("Fechou handle de hInternetFile ? %d \n", ret);
#endif

			hInternetFile = 0;
		}

		if (m_hSession)
		{
			ret = InternetCloseHandle (m_hSession);
#ifdef NPRINTF
			//dprintf_z ("Fechou handle de m_hSession ? %d \n", ret);
#endif

			m_hSession = 0;
		}
		internetrunning = 0;
#ifdef NPRINTF
		//dprintf_z ("Nao vai fechar arquivo porque nao foi aberto \n");
#endif

		internetrunning = 0;
		isdownloading = 0;
		return 5;

	}
#ifdef NPRINTF
	//dprintf_z ("Esta puxando arquivo \n");
#endif

volta:



	while (intpause)
	{

		if (intcancel)
		{
			goto final;
		}

		Sleep (50);
	}




	if (intcancel)
	{
		goto final;
	}



	ret = InternetReadFile (hInternetFile, (LPVOID) szTemp, 4096, &dwRead);


	if (ret == 0)
	{

		int ret;
		int a, b;
		char temp[256];
#ifdef NPRINTF
		//dprintf_z ("Deu erro em InternetReadFile \n");
#endif

		b = 256;

		ret = GetLastError ();

		rsp_error ();

		if (ret == ERROR_INTERNET_EXTENDED_ERROR)
		{
			goto direto2;
		}
		rsp_net_error ();

direto2:

		if (GetLastError () == ERROR_INTERNET_EXTENDED_ERROR)
		{
			ret = InternetGetLastResponseInfo (&a, temp, &b);

			if (ret)
			{

				if (strlen (temp))
				{
#ifdef NPRINTF
					//dprintf_z ("%d %s \n", a, temp);
#endif

				}
			}

		}

		if (hInternetFile)
		{
			ret = InternetCloseHandle (hInternetFile);
#ifdef NPRINTF
			//dprintf_z ("Fechou handle de hInternetFile ? %d \n", ret);
#endif

			hInternetFile = 0;

		}

		if (m_hSession)
		{
			ret = InternetCloseHandle (m_hSession);
#ifdef NPRINTF
			//dprintf_z ("Fechou handle de m_hSession ? %d \n", ret);
#endif

			m_hSession = 0;

		}

		goto saidaok;

	}

	if (dwRead == 0)
	{
#ifdef NPRINTF
		//dprintf_z ("Nao tem mais nada , sai fora \n");
#endif

		goto final;
	}

	ret = WriteFile (f, (LPVOID) szTemp, dwRead, &dwWritten, NULL);

	isdownloading = 1;
	//  FlushFileBuffers (f);



	if (!ret)
	{
		rsp_error ();
		goto saidaok;
	}
	tamanho += dwWritten;


#ifdef NPRINTF
	//dprintf_z ("retornando \n");
#endif
	goto volta;

final:

saidaok:

#ifdef NPRINTF
	//dprintf_z ("len %d tamanho %d \n", len, tamanho);
#endif

	if (0 && (len != -1) && (len != 0) && (len != tamanho) && (tamanho > len))
	{
		int ret;
		ret = SetFilePointer (f, len, NULL, FILE_BEGIN);
		if (0xFFFFFFFF != ret)
		{
			ret = SetEndOfFile (f);
		}
	}

	CloseHandle (f);
#ifdef NPRINTF
	//dprintf_z ("Fechou arquivo \n");
#endif

	if (hInternetFile)
	{
		ret = InternetCloseHandle (hInternetFile);
#ifdef NPRINTF
		//dprintf_z ("Fechou handle de hInternetFile ? %d \n", ret);
#endif

		hInternetFile = 0;

	}

	if (m_hSession)
	{

		ret = InternetCloseHandle (m_hSession);
#ifdef NPRINTF
		//dprintf_z ("Fechou handle de m_hSession ? %d \n", ret);
#endif

		m_hSession = 0;

	}

#ifdef NPRINTF
	//dprintf_z ("puxou arquivo \n");
#endif

	internetrunning = 0;
	isdownloading = 0;
	return 0;

}




/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/
void
cancel_execution ()
{
#ifdef NPRINTF
	//dprintf_z ("chamando cancel \n");
#endif
	while (internetrunning)
	{
		intcancel = 1;
		Sleep (50);
	}
	intcancel = 0;
#ifdef NPRINTF
	//dprintf_z ("ja deu cancel \n");
#endif
}

void
pause_execution ()
{

	intpause = 1;

}


/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


void
resume_execution ()
{

	intpause = 0;

}

/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


int
isurl (char *url)
{

	int ret;
	char *temp;
	int sizeis = 0;
	//  char header[255];

	ret = strlen (url);

	if (!ret)
	{

		return 0;

	}

	temp = malloc (ret + 255);

	memset (temp, 0, 255);

	strcpy (temp, url);

	//dprintf_z ("String a ser testada antes .%s. \n", temp);

	strtolower (temp);

	//removedordeespaconoinicio (temp);
	//removedordeespaconofinal (temp);

	// dprintf_z ("String a ser testada .%s. \n", temp);


	if (!memcmp (temp, "http://", 7))
	{

		sizeis = 7;
#ifdef NPRINTF
		//dprintf_z ("is http \n");
#endif

	}
	else if (!memcmp (temp, "ftp://", 6))
	{
		sizeis = 6;
#ifdef NPRINTF
		//dprintf_z ("is ftp \n");
#endif

	}
	else
	{
#ifdef NPRINTF
		//dprintf_z ("no protocol \n");
#endif

		sizeis = 0;
	}

	free (temp);
#ifdef NPRINTF
	//dprintf_z ("isulr == %d \n", sizeis);
#endif
	return sizeis;

}

/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/


int
main5 ()
{


	int ret;


	init ();






	//pause_execution ();



/*
   // da retorno grande
   ret =
      set_ftp ("ftp.cis.uab.edu", "/pub/hyatt/TB/egtb.cpp",
               "anonymous", "wsftp605@", "c:\\backup\\main2.html",
               INTERNET_INVALID_PORT_NUMBER, INTERNET_FLAG_PASSIVE, 1,
               1, 0);
 */



//ftp://ftp.kernel.org/pub/index.html
/*
      ret =
     set_ftp ("ftp.kernel.org",
    "/pub/index.html",
    "anonymous", "wsftp605@", "c:\\backup\\files",
   INTERNET_INVALID_PORT_NUMBER, INTERNET_FLAG_PASSIVE, 1,
   1, 0);
 */
	isrunning = 1;
	start_web ();
//http();

//ftp://ftp.us.kernel.org/pub/linux/utils/cpu/crusoe/longrun-0.9.tar.gz

//ftp://localhost/bond/cdda.dll


	//  ret = set_ftp ("localhost", "/bond/cdda.dll", "anonymous", "wsftp605@", "c:\\backup\\files", INTERNET_INVALID_PORT_NUMBER, 0, 1, 1, 0);





//INTERNET_FLAG_PASSIVE
/*
   if (ret)
     {

        dprintf_z ("main-Already running call cancel first \n");

     }
 */






	while (1)
	{


		if ((isrunning == 0) || flagexit)
		{
			flagexit = 0;

			//    dprintf_z ("Status de saida : %d \n", errvalue);
			return 0;

		}


		Sleep (50);

	}

}


/*OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*/



/*

   precisa de um seletor de ftp ou http , spo istpo
   e iniciador de thread e dai pindurar isto no treco
 */



int
initiatedownload (char *filename, char *url)
{
	strcpy (strURL, url);

	internetrunning = 1;
	strcpy (filetosave, filename);
	start_web ();
	return 0;
}
