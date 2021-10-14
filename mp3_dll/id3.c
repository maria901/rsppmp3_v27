//My hands have created it a lot of years ago...

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

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif
#include <windows.h>
#include   <stdio.h>

#undef NDEBUG
#include  <assert.h>

extern int __cdecl ispathfile                  (char                  *path);
extern int __cdecl save_to_file(char *infile, char *data, int size, int mode,
                                                                  int limit);
extern int __cdecl createtempfilename          (char *path1, char *destfile);
extern int __cdecl fix_filesize                (    char *filename, int len);
extern __int64 __cdecl getfilesize             (       char *infile        );
extern int __cdecl detect_readonly_file        (char *filename             );

#include                                                       "mv_from_be.h"

//#include "folder.h"

static int id3v2tag_check (char *filename);
__int64 _ftelli64_arab (FILE * stream);
int _fseeki64_arab (FILE * stream, __int64 offset, int origin);
__int64 id3v2tag (char *filename);
int id3v2tag_ok_write (char *filename);
short invertbits16 (short value);
int invertbits32 (int value);
extern const char *const ID3v1_genre[];
int pegaposicaoinsensitive (char *comando, char *string);
const char *const ID3v1_genre[] = {
/*  1*/ "Blues",
/*  2*/ "Classic Rock",
/*  3*/ "Country",
/*  4*/ "Dance",
/*  5*/ "Disco",
/*  6*/ "Funk",
/*  7*/ "Grunge",
/*  8*/ "Hip-Hop",
/*  9*/ "Jazz",
/* 10*/ "Metal",
/* 11*/ "New Age",
/* 12*/ "Oldies",
/* 13*/ "Other",
/* 14*/ "Pop",
/* 15*/ "R&B",
/* 16*/ "Rap",
/* 17*/ "Reggae",
/* 18*/ "Rock",
/* 19*/ "Techno",
/* 20*/ "Industrial",
/* 21*/ "Alternative",
/* 22*/ "Ska",
/* 23*/ "Death Metal",
/* 24*/ "Pranks",
/* 25*/ "Soundtrack",
/* 26*/ "Euro-Techno",
/* 27*/ "Ambient",
/* 28*/ "Trip-Hop",
/* 29*/ "Vocal",
/* 30*/ "Jazz+Funk",
/* 31*/ "Fusion",
/* 32*/ "Trance",
/* 33*/ "Classical",
/* 34*/ "Instrumental",
/* 35*/ "Acid",
/* 36*/ "House",
/* 37*/ "Game",
/* 38*/ "Sound Clip",
/* 39*/ "Gospel",
/* 40*/ "Noise",
/* 41*/ "Alternative Rock",
/* 42*/ "Bass",
/* 43*/ "Soul",
/* 44*/ "Punk",
/* 45*/ "Space",
/* 46*/ "Meditative",
/* 47*/ "Instrumental Pop",
/* 48*/ "Instrumental Rock",
/* 49*/ "Ethnic",
/* 50*/ "Gothic",
/* 51*/ "Darkwave",
/* 52*/ "Techno-Industrial",
/* 53*/ "Electronic",
/* 54*/ "Pop-Folk",
/* 55*/ "Eurodance",
/* 56*/ "Dream",
/* 57*/ "Southern Rock",
/* 58*/ "Comedy",
/* 59*/ "Cult",
/* 60*/ "Gangsta",
/* 61*/ "Top 40",
/* 62*/ "Christian Rap",
/* 63*/ "Pop/Funk",
/* 64*/ "Jungle",
/* 65*/ "Native American",
/* 66*/ "Cabaret",
/* 67*/ "New Wave",
/* 68*/ "Psychadelic",
/* 69*/ "Rave",
/* 70*/ "Showtunes",
/* 71*/ "Trailer",
/* 72*/ "Lo-Fi",
/* 73*/ "Tribal",
/* 74*/ "Acid Punk",
/* 75*/ "Acid Jazz",
/* 76*/ "Polka",
/* 77*/ "Retro",
/* 78*/ "Musical",
/* 79*/ "Rock & Roll",
/* 80*/ "Hard Rock",
	/* 81 */ "Folk",
	/* Winamp extensions */
/* 82*/ "Folk/Rock",
/* 83*/ "National Folk",
/* 84*/ "Swing",
/* 85*/ "Fast-Fusion",
/* 86*/ "Bebob",
/* 87*/ "Latin",
/* 88*/ "Revival",
/* 89*/ "Celtic",
/* 90*/ "Bluegrass",
/* 91*/ "Avantgarde",
/* 92*/ "Gothic Rock",
/* 93*/ "Progressive Rock",
/* 94*/ "Psychedelic Rock",
/* 95*/ "Symphonic Rock",
/* 96*/ "Slow Rock",
/* 97*/ "Big Band",
/* 98*/ "Chorus",
/* 99*/ "Easy Listening",
/*100*/ "Acoustic",
/*101*/ "Humour",
/*102*/ "Speech",
/*103*/ "Chanson",
/*104*/ "Opera",
/*105*/ "Chamber Music",
/*106*/ "Sonata",
/*107*/ "Symphony",
/*108*/ "Booty Bass",
/*109*/ "Primus",
/*110*/ "Porn Groove",
/*111*/ "Satire",
	/*112 */ "Slow Jam",
	/* Winamp 1.7 */
/*113*/ "Club",
/*114*/ "Tango",
/*115*/ "Samba",
/*116*/ "Folklore",
	/*117 */ "Ballad",
	/* Winamp 1.90 */
/*118*/ "Power Ballad",
/*119*/ "Rhythmic Soul",
/*120*/ "Freestyle",
/*121*/ "Duet",
/*122*/ "Punk Rock",
/*123*/ "Drum Solo",
/*124*/ "A Capella",
/*125*/ "Euro-House",
/*126*/ "Dance Hall",
/*127*/ "Goa",
/*128*/ "Drum & Bass",
/*129*/ "Club-House",
/*130*/ "Hardcore",
/*131*/ "Terror",
/*132*/ "Indie",
/*133*/ "BritPop",
/*134*/ "Negerpunk",
/*135*/ "Polsk Punk",
/*136*/ "Beat",
/*137*/ "Christian Gangsta",
/*138*/ "Heavy Metal",
/*139*/ "Black Metal",
/*140*/ "Crossover",
/*141*/ "Contemporary Christian",
/*142*/ "Christian Rock",
	/*143 */ "Merengue",
	/* Winamp 1.91 */
/*144*/ "Salsa",
/*145*/ "Thrash Metal",
/*146*/ "Anime",
/*147*/ "JPop",
/*148*/ "Synthpop",
	" ",
	" "
};
static int
id3v2tag_check (char *filename)
{
	FILE *astdin = NULL;
	int ret;
	uchar item[255];
	uint fatia1;
	uint fatia2;
	uint fatia3;
	uint fatia4;
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	if ((astdin = _wfopen (permissive_name_m_(amanda_utf8towide_3_(filename)), L"rb")) == NULL)
	{
		free(ul_______);
		return 0;
	}
	ret = fread ((char *) item, 1, 10, astdin);
	fclose (astdin);
	if (ret == 10)
	{
		if (('I' == item[0]) && (item[1] == 'D') && (item[2] == '3'))
		{
			fatia1 = (uint) item[6];
			fatia2 = (uint) item[7];
			fatia3 = (uint) item[8];
			fatia4 = (uint) item[9];
			fatia1 = (fatia1 << (7 * 3)) | (fatia2 << (7 * 2))
			         | (fatia3 << (7)) | fatia4;
			if (getfilesize (filename) < fatia1)
			{
				free(ul_______);
				return 0;
			}
			free(ul_______);
			return fatia1 + 10;
		}
	}
	free(ul_______);
	return 0;
}

int
id3v1tag_ok (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename)
{
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	char buf[200];
	FILE *stream = NULL;
	int returnvalue = 0;
	__int64 ret;

	if ((stream = _wfopen (permissive_name_m_(amanda_utf8towide_3_(filename)), L"rb")) == NULL)  //"rb+"
	{

		returnvalue = 1; // Cannot open mp3 file
		goto saida;

	}

	ret = getfilesize (filename);

	if (ret < 128)

	{
		returnvalue = 3; // invalid file
		goto saida;

	}

	ret = _fseeki64_arab (stream, -128, SEEK_END);

	ret = fread (buf, 1, 128, stream);

	if (128 == ret)
	{
		;               //dprintf("leu 128 \n");
		if (memcmp (buf, "TAG", 3) == 0)
		{


			uchar *ptr;



			memset (mv_______->id3_c___v1Title, 0, 100);
			memset (mv_______->id3_c___v1Artist, 0, 100);
			memset (mv_______->id3_c___v1Album, 0, 100);
			memset (mv_______->id3_c___v1Year, 0, 100);
			memset (mv_______->id3_c___v1Comment, 0, 100);

			memcpy (mv_______->id3_c___v1Title, &buf[3], 30);
			memcpy (mv_______->id3_c___v1Artist, &buf[3 + 30], 30);
			memcpy (mv_______->id3_c___v1Album, &buf[3 + 30 + 30], 30);
			memcpy (mv_______->id3_c___v1Year, &buf[3 + 30 + 30 + 30], 4);

			ptr = (unsigned char *) &buf[125];

			if (0 == *ptr)
			{
				memcpy (mv_______->id3_c___v1Comment, &buf[3 + 30 + 30 + 30 + 4], 28);

				ptr = (unsigned char *) &buf[126];

				; //dprintf("valor lido de track %d \n", *ptr);
				mv_______->id3_c___v1Track = *ptr;

			}
			else
			{

				memcpy (mv_______->id3_c___v1Comment, &buf[3 + 30 + 30 + 30 + 4], 30);
				mv_______->id3_c___v1Track = 0;

			}

			ptr = (unsigned char *) &buf[127];

			;
			mv_______->id3_c___v1Genre = *ptr;


			if (mv_______->id3_c___v1Genre > 148)
			{
				mv_______->id3_c___v1Genre = 148;
			}

		}
		else
		{

			;       //dprintf("nao tem id3tag \n");
			returnvalue = 2; // v1 not found
			goto saida;

		}

	}
	else
	{
		;               //dprintf("nao leu 128 \n");
		returnvalue = 2; // v1 not found
		goto saida;

	}

	;
saida:
	;

	if (stream)
	{

		fclose (stream);

	}

	free(ul_______);
	return returnvalue;
}
int
id3v1tag_ok_write (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename)
{
	unicode_large *ul_______=calloc(sizeof(unicode_large),1); //check on the malloc error is a waste of time because it will fail anyway to show a messagebox
	char buf[200];
	uchar eu = 0;
	FILE *stream = NULL;
	int returnvalue = 0;
	__int64 ret;
	if (detect_readonly_file (filename))
	{

		returnvalue = 4;
		goto saida;

	}

	if ((stream = _wfopen (permissive_name_m_(amanda_utf8towide_3_(filename)), L"rb+")) == NULL) //"rb+"
	{

		returnvalue = 1; // Cannot open mp3 file
		goto saida;

	}


	ret = getfilesize (filename);

	if (ret < 128)

	{
		returnvalue = 3; // invalid file
		goto saida;

	}


	ret = _fseeki64_arab (stream, -128, SEEK_END);

	ret = fread (buf, 1, 128, stream);

	if (128 == ret)
	{



		;               //dprintf("leu 128 \n");
		if (memcmp (buf, "TAG", 3) == 0)
		{
			;       //dprintf("achou id3 tag \n");

			ret = _fseeki64_arab (stream, -128, SEEK_END);

			ret = fwrite ("TAG", 1, 3, stream);
			ret = fwrite (mv_______->id3_c___v1Title, 1, 30, stream);
			ret = fwrite (mv_______->id3_c___v1Artist, 1, 30, stream);
			ret = fwrite (mv_______->id3_c___v1Album, 1, 30, stream);
			ret = fwrite (mv_______->id3_c___v1Year, 1, 4, stream);

			if (mv_______->id3_c___v1Track)
			{
				eu = 0;

				ret = fwrite (mv_______->id3_c___v1Comment, 1, 28, stream);
				ret = fwrite (&eu, 1, 1, stream);

				eu = mv_______->id3_c___v1Track;

				ret = fwrite (&eu, 1, 1, stream);

			}
			else
			{

				ret = fwrite (mv_______->id3_c___v1Comment, 1, 30, stream);
			}

			eu = mv_______->id3_c___v1Genre;


			ret = fwrite (&eu, 1, 1, stream);


		}
		else
		{

			;       //dprintf("nao achou id3 tag \n");

			ret = _fseeki64_arab (stream, 0, SEEK_END);

			ret = fwrite ("TAG", 1, 3, stream);
			ret = fwrite (mv_______->id3_c___v1Title, 1, 30, stream);
			ret = fwrite (mv_______->id3_c___v1Artist, 1, 30, stream);
			ret = fwrite (mv_______->id3_c___v1Album, 1, 30, stream);
			ret = fwrite (mv_______->id3_c___v1Year, 1, 4, stream);


			if (mv_______->id3_c___v1Track)
			{
				eu = 0;

				ret = fwrite (mv_______->id3_c___v1Comment, 1, 28, stream);
				ret = fwrite (&eu, 1, 1, stream);

				eu = mv_______->id3_c___v1Track;

				ret = fwrite (&eu, 1, 1, stream);

			}
			else
			{
				ret = fwrite (mv_______->id3_c___v1Comment, 1, 30, stream);
			}

			eu = mv_______->id3_c___v1Genre;

			ret = fwrite (&eu, 1, 1, stream);

		}

	}
	else
	{
		;               //dprintf("nao leu 128 \n");
		returnvalue = 2; // v1 not found
		goto saida;

	}


	;
saida:
	;

	if (stream)
	{

		fclose (stream);

	}

	free(ul_______);
	return returnvalue;

}


int
remove_id3v1_tag (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename)
{

	__int64 ret;
	////thinktwice (1);
	if (detect_readonly_file (filename))
	{

		return 3;


	}

	ret = id3v1tag_ok (mv_______,filename);

	if (0 == ret)
	{

		ret = fix_filesize (filename, getfilesize (filename) - 128);

		if (0 == ret)
		{

			return 0;

		}

	}
	else
	{

		return 0;       //dont have id3v1 tag or invalid file

	}

	return 1;               //unable to remove id3v1 tag

}

static void
fixframe (char *theframe, int size, int mode)
{

	char                *temp;
	char               *temp2;
	int                     i;
	
	temp = malloc (size + 10);

	temp2 = theframe         ;

	if (1 == mode            )
	{


		if (size <= 1)
		{
			strcpy (theframe, "");
			goto saifora;

		}

		temp2++;

		strcpy (temp, temp2);

		strcpy (theframe, temp);

		goto saifora;

	}

	if (2 == mode)
	{
//modo wxxx
		if (size <= 2)
		{
			strcpy (theframe, "");
			goto saifora;

		}

		temp2++;


		for (i = 0; i < (size - 2); i++)
		{
			//dprintf("modo 2 valor de temp2 %d \n", *temp2);
			if (0 == *temp2)
			{

				//dprintf("locaizou 0 de dois \n");
				temp2++;
				goto jump2;
			}
			temp2++;
		}

		strcpy (theframe, "");
		goto saifora;

jump2:

		strcpy (temp, temp2);

		strcpy (theframe, temp);

		goto saifora;

	}


	if (5 == mode)
	{
		if (size <= 5)
		{
			strcpy (theframe, "");
			goto saifora;

		}

		temp2++;
		temp2++;
		temp2++;
		temp2++;


		for (i = 0; i < (size - 5); i++)
		{
			//dprintf("valor de temp2 %d \n", *temp2);
			if (0 == *temp2)
			{
				//dprintf("locaizou 0 de cinco \n");

				temp2++;
				goto jump5;
			}
			temp2++;
		}

		strcpy (theframe, "");
		goto saifora;

jump5:

		strcpy (temp, temp2);

		strcpy (theframe, temp);

		goto saifora;

	}


saifora:

	free (temp);
}
/*
   #define DWORDSWAP(dw) (((dw) >> 24) |\ (((dw) >> 8) & 0x0000FF00) |\ (((dw) << 8) & 0x00FF0000) |\ (((dw) << 24) & 0xFF000000))
 */
static int
invertbits2 (int value)
{
	return (int) ((((uint) value) >> 24) |
	              ((((uint) value) >> 8) & 0x0000FF00) |
	              ((((uint) value) << 8) & 0x00FF0000) |
	              ((((uint) value) << 24) & 0xFF000000));
}
static int
invertbits (int value)
{

	int out;
	char *input = (char *) &value;
	char *output = (char *) &out;
	output[0] = input[3];
	output[1] = input[2];
	output[2] = input[1];
	output[3] = input[0];
	return out;
}
static int
getv2data (char *filename, char *data, int size)
{
	unicode_large *ul_______=calloc(sizeof(unicode_large),1);
	int ret;
	FILE *stream = NULL;
	int returnvalue = 0;
	if ((stream = _wfopen (permissive_name_m_(amanda_utf8towide_3_(filename)), L"rb")) == NULL)
	{
		returnvalue = 1;
		goto saida;
	}
	ret = fread(data, 1, size, stream);
	if (ret == size)
	{
		returnvalue = 0;
		goto saida;
	}
	else
	{
		returnvalue = 2;
		goto saida;
	}
saida:
	fclose (stream);
	free(ul_______);
	return returnvalue;
}
int
id3v2tag_ok (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename)
{
	__int64 thesize = 0;

	int mode = 0;
	int framesize;
	int tamanhodetag = 0;
	int ret;
	int returnvalue = 0;
	char *itens = NULL;
	char *ptr;
	char v2nome[10];
	int *iptr;
	char *theframe = NULL;
	mv_______->id3_c___v2Composersize = 0;
	mv_______->id3_c___v2OriginalArtistsize = 0;
	mv_______->id3_c___v2Copyrightsize = 0;
	mv_______->id3_c___v2URLsize = 0;
	mv_______->id3_c___v2EncodedBysize = 0;
	mv_______->id3_c___v2Commentsize = 0;
	mv_______->id3_c___v2Genresize = 0;
	mv_______->id3_c___v2Yearsize = 0;
	mv_______->id3_c___v2Albumsize = 0;
	mv_______->id3_c___v2Artistsize = 0;
	mv_______->id3_c___v2Titlesize = 0;
	mv_______->id3_c___v2Tracksize = 0;

//   __asm
//   {
//
//      int 3;
//
//   }


//mprintf("estamos dentro\n");
	////thinktwice (1);

	thesize = getfilesize (filename);

	if (mv_______->id3_c___v2Track)
	{
		free (mv_______->id3_c___v2Track);
		mv_______->id3_c___v2Track = NULL;
	}

	if (mv_______->id3_c___v2Title)
	{

		free (mv_______->id3_c___v2Title);
		mv_______->id3_c___v2Title = NULL;
	}

	if (mv_______->id3_c___v2Artist)
	{
		free (mv_______->id3_c___v2Artist);
		mv_______->id3_c___v2Artist = NULL;
	}

	if (mv_______->id3_c___v2Album)
	{
		free (mv_______->id3_c___v2Album);
		mv_______->id3_c___v2Album = NULL;
	}

	if (mv_______->id3_c___v2Year)
	{
		free (mv_______->id3_c___v2Year);
		mv_______->id3_c___v2Year = NULL;
	}

	if (mv_______->id3_c___v2Genre)
	{
		free (mv_______->id3_c___v2Genre);
		mv_______->id3_c___v2Genre = NULL;
	}

	if (mv_______->id3_c___v2Comment)
	{
		free (mv_______->id3_c___v2Comment);
		mv_______->id3_c___v2Comment = NULL;
	}

	if (mv_______->id3_c___v2EncodedBy)
	{
		free (mv_______->id3_c___v2EncodedBy);
		mv_______->id3_c___v2EncodedBy = NULL;
	}

	if (mv_______->id3_c___v2URL)
	{
		free (mv_______->id3_c___v2URL);
		mv_______->id3_c___v2URL = NULL;
	}

	if (mv_______->id3_c___v2Copyright)
	{
		free (mv_______->id3_c___v2Copyright);
		mv_______->id3_c___v2Copyright = NULL;
	}

	if (mv_______->id3_c___v2OriginalArtist)
	{
		free (mv_______->id3_c___v2OriginalArtist);
		mv_______->id3_c___v2OriginalArtist = NULL;
	}

	if (mv_______->id3_c___v2Composer)
	{
		free (mv_______->id3_c___v2Composer);
		mv_______->id3_c___v2Composer = NULL;
	}

	ret = id3v2tag_check (filename);

	if (ret)
	{
// temo tag check

		tamanhodetag = ret; //dprintf("temos v2 tag check %d \n", ret);
// somente copiamos os itens iniciais num arquivo

		//dprintf("vai alocar %d \n", ret + 100);
		itens = malloc (ret + 100);
		//dprintf("getv2data 1 \n");
		ret = getv2data (filename, itens, ret);
		//dprintf("getv2data 2 \n");
		if (ret)
		{

			returnvalue = 2; // cannot load data from file
			goto saida;
		}

		ptr = itens;
		ptr = ptr + 10;

getinfo:
		;

		if (0 == *ptr || ((ptr - itens) + 10) >= tamanhodetag)
		{

			goto finish;
		}

		memset (v2nome, 0, 10);
		memcpy (v2nome, ptr, 4);
		ptr = ptr + 4;
		iptr = (int *) ptr;
		framesize = invertbits (*iptr);

		if ((framesize >= (thesize) || (framesize < 0)))
		{

			framesize = 1;
			memset (v2nome, 0, 10);

		}

		ptr = ptr + 4;
		ptr++;
		ptr++;

		if (framesize > 64000)
		{
			returnvalue = 1;
			goto saida;
		}

		theframe = malloc (framesize + 10);
		memset (theframe, 0, framesize + 10);
		memcpy (theframe, ptr, framesize);
		mode = 1;
		if (!memcmp (v2nome, "WXXX", 4))
		{
			mode = 2;
		}

		if (!memcmp (v2nome, "COMM", 4))
		{
			mode = 5;
		}

		fixframe (theframe, framesize, mode);
		if (!memcmp (v2nome, "TENC", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2EncodedBysize = strlen (theframe);
				if (mv_______->id3_c___v2EncodedBy)
				{
					free (mv_______->id3_c___v2EncodedBy);
					mv_______->id3_c___v2EncodedBy = NULL;
				}
				if ((mv_______->id3_c___v2EncodedBysize + 100) > thesize)
				{

					returnvalue = 1; //nao tem id3v2
					goto saida;
				}
				mv_______->id3_c___v2EncodedBy = malloc (mv_______->id3_c___v2EncodedBysize + 100);
				memset (mv_______->id3_c___v2EncodedBy, 0, mv_______->id3_c___v2EncodedBysize + 100);
				strcpy (mv_______->id3_c___v2EncodedBy, theframe);
			}

		}

		if (!memcmp (v2nome, "WXXX", 4))
		{
			if (strlen (theframe) && framesize > 2)
			{
				mv_______->id3_c___v2URLsize = strlen (theframe);
				if (mv_______->id3_c___v2URL)
				{
					free (mv_______->id3_c___v2URL);
					mv_______->id3_c___v2URL = NULL;
				}
				if ((mv_______->id3_c___v2URLsize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2URL = malloc (mv_______->id3_c___v2URLsize + 100);
				memset (mv_______->id3_c___v2URL, 0, mv_______->id3_c___v2URLsize + 100);
				strcpy (mv_______->id3_c___v2URL, theframe);
			}
		}

		if (!memcmp (v2nome, "TCOP", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2Copyrightsize = strlen (theframe);
				if (mv_______->id3_c___v2Copyright)
				{
					free (mv_______->id3_c___v2Copyright);
					mv_______->id3_c___v2Copyright = NULL;
				}
				if ((mv_______->id3_c___v2Copyrightsize + 100) > thesize)
				{

					returnvalue = 1; //nao tem id3v2
					goto saida;
				}
				mv_______->id3_c___v2Copyright = malloc (mv_______->id3_c___v2Copyrightsize + 100);
				memset (mv_______->id3_c___v2Copyright, 0, mv_______->id3_c___v2Copyrightsize + 100);
				strcpy (mv_______->id3_c___v2Copyright, theframe);
			}

		}

		if (!memcmp (v2nome, "TOPE", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2OriginalArtistsize = strlen (theframe);
				if (mv_______->id3_c___v2OriginalArtist)
				{
					free (mv_______->id3_c___v2OriginalArtist);
					mv_______->id3_c___v2OriginalArtist = NULL;
				}
				if ((mv_______->id3_c___v2OriginalArtistsize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2OriginalArtist = malloc (mv_______->id3_c___v2OriginalArtistsize + 100);
				memset (mv_______->id3_c___v2OriginalArtist, 0, mv_______->id3_c___v2OriginalArtistsize + 100);
				strcpy (mv_______->id3_c___v2OriginalArtist, theframe);
			}
		}

		if (!memcmp (v2nome, "TCOM", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2Composersize = strlen (theframe);
				if (mv_______->id3_c___v2Composer)
				{
					free (mv_______->id3_c___v2Composer);
					mv_______->id3_c___v2Composer = NULL;
				}
				if ((mv_______->id3_c___v2Composersize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2Composer = malloc (mv_______->id3_c___v2Composersize + 100);
				memset (mv_______->id3_c___v2Composer, 0, mv_______->id3_c___v2Composersize + 100);
				strcpy (mv_______->id3_c___v2Composer, theframe);
			}
		}

		if (!memcmp (v2nome, "TCON", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2Genresize = strlen (theframe);
				if (mv_______->id3_c___v2Genre)
				{
					free (mv_______->id3_c___v2Genre);
					mv_______->id3_c___v2Genre = NULL;
				}
				if ((mv_______->id3_c___v2Genresize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2Genre = malloc (mv_______->id3_c___v2Genresize + 100);
				memset (mv_______->id3_c___v2Genre, 0, mv_______->id3_c___v2Genresize + 100);
				strcpy (mv_______->id3_c___v2Genre, theframe);
				{
					int ret;
					int ret2;
					ret = pegaposicaoinsensitive (mv_______->id3_c___v2Genre, "(");
					ret2 = pegaposicaoinsensitive (mv_______->id3_c___v2Genre, ")");
					if (ret && ret2)
					{
						char *temp;
						temp = malloc (100);
						strcpy (temp, &mv_______->id3_c___v2Genre[ret]);
						ret = atoi (temp);
						if (ret < 148)
						{
							strcpy (mv_______->id3_c___v2Genre, ID3v1_genre[ret]);
							mv_______->id3_c___v2Genresize = strlen (mv_______->id3_c___v2Genre);
						}
						free (temp);
					}
				}
			}
		}

		if (!memcmp (v2nome, "TRCK", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2Tracksize = strlen (theframe);
				if (mv_______->id3_c___v2Track)
				{
					free (mv_______->id3_c___v2Track);
					mv_______->id3_c___v2Track = NULL;
				}
				if ((mv_______->id3_c___v2Tracksize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2Track = malloc (mv_______->id3_c___v2Tracksize + 100);
				memset (mv_______->id3_c___v2Track, 0, mv_______->id3_c___v2Tracksize + 100);
				strcpy (mv_______->id3_c___v2Track, theframe);
			}
		}

		if (!memcmp (v2nome, "COMM", 4))
		{
			if (strlen (theframe) && framesize > 5)
			{
				mv_______->id3_c___v2Commentsize = strlen (theframe);
				if (mv_______->id3_c___v2Comment)
				{
					free (mv_______->id3_c___v2Comment);
					mv_______->id3_c___v2Comment = NULL;
				}
				if ((mv_______->id3_c___v2Commentsize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2Comment = malloc (mv_______->id3_c___v2Commentsize + 100);
				memset (mv_______->id3_c___v2Comment, 0, mv_______->id3_c___v2Commentsize + 100);
				strcpy (mv_______->id3_c___v2Comment, theframe);
			}
		}

		if (!memcmp (v2nome, "TYER", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2Yearsize = strlen (theframe);
				if (mv_______->id3_c___v2Year)
				{
					free (mv_______->id3_c___v2Year);
					mv_______->id3_c___v2Year = NULL;
				}
				if ((mv_______->id3_c___v2Yearsize + 100) > thesize)
				{

					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2Year = malloc (mv_______->id3_c___v2Yearsize + 100);
				memset (mv_______->id3_c___v2Year, 0, mv_______->id3_c___v2Yearsize + 100);
				strcpy (mv_______->id3_c___v2Year, theframe);
			}
		}
		if (!memcmp (v2nome, "TALB", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2Albumsize = strlen (theframe);
				if (mv_______->id3_c___v2Album)
				{
					free (mv_______->id3_c___v2Album);
					mv_______->id3_c___v2Album = NULL;
				}
				if ((mv_______->id3_c___v2Albumsize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2Album = malloc (mv_______->id3_c___v2Albumsize + 100);
				memset (mv_______->id3_c___v2Album, 0, mv_______->id3_c___v2Albumsize + 100);
				strcpy (mv_______->id3_c___v2Album, theframe);
			}
		}

		if (!memcmp (v2nome, "TPE1", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2Artistsize = strlen (theframe);
				if (mv_______->id3_c___v2Artist)
				{
					free (mv_______->id3_c___v2Artist);
					mv_______->id3_c___v2Artist = NULL;
				}
				if ((mv_______->id3_c___v2Artistsize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2Artist = malloc (mv_______->id3_c___v2Artistsize + 100);
				memset (mv_______->id3_c___v2Artist, 0, mv_______->id3_c___v2Artistsize + 100);
				strcpy (mv_______->id3_c___v2Artist, theframe);
			}
		}

		if (!memcmp (v2nome, "TIT2", 4))
		{
			if (strlen (theframe) && framesize > 1)
			{
				mv_______->id3_c___v2Titlesize = strlen (theframe);
				if (mv_______->id3_c___v2Title)
				{
					free (mv_______->id3_c___v2Title);
					mv_______->id3_c___v2Title = NULL;
				}
				if ((mv_______->id3_c___v2Titlesize + 100) > thesize)
				{
					returnvalue = 1;
					goto saida;
				}
				mv_______->id3_c___v2Title = malloc (mv_______->id3_c___v2Titlesize + 100);
				memset (mv_______->id3_c___v2Title, 0, mv_______->id3_c___v2Titlesize + 100);
				strcpy (mv_______->id3_c___v2Title, theframe);
			}
		}
		ptr += framesize;
		free (theframe);
		theframe = NULL;
		goto getinfo;
finish:
		;
	}
	else
	{
		returnvalue = 1;
		goto saida;
	}
saida:
	;
	if (itens)
	{
		free (itens);
	}
	if (theframe)
	{
		free (theframe);
	}
	return returnvalue;
}
int
id3v2tag_ok_write_multithread
(
        morcego___i___instance__a__bucaneiro_engineering *mv_______,
        char *filename
)
{
	__int64 mv_instance=(__int64)(__INT32_OR_INT64)mv_______;
	int noterror          =    0;
	__int64 thesize       =    0;
	FILE *in              = NULL;
	FILE *out             = NULL;
	int sizetowrite       =    0;
	int didfilename       =    0;
	int framesize               ;
	int tamanhodetag      =    0;
	int ret                     ;
	int returnvalue       =    0;
	char *itens           = NULL;
	char *ptr                   ;
	char v2nome           [10  ];
	int *iptr                   ;
	char *theframe        = NULL;
	char *theframe2       = NULL;
	char mp3file   [1024] ={0, };
	char header             [11];
	int frame_handled     =    0;
	int COMM              =   1;
	int TALB              =    1;
	int TCOM              =    1;
	int TCON              =    1;
	int TCOP              =    1;
	int TENC              =    1;
	int TIT2              =    1;
	int TOPE              =    1;
	int TPE1              =    1;
	int TRCK              =    1;
	int TYER              =    1;
	int WXXX              =    1;
	
	(void) mv_instance;
	
	if (     detect_readonly_file
	                  (filename))
	{
		returnvalue       =    1;
		goto              saida ;
	}

	thesize = getfilesize (filename);

	ret = createtempfilename (mv_______->id3_c___tempfolder, mp3file);

	if (!ret)
	{
		didfilename = 1;
	}
	else
	{
		returnvalue = 2;
		goto saida;
	}

	header[0] = 'I';
	header[1] = 'D';
	header[2] = '3';
	// Version number
	header[3] = 3;
	header[4] = 0;
	// Clear Flags byte
	header[5] = 0;
	// Write tag length
	header[6] = 0;          //((dwTagSize >> 21) & 0x7F );
	header[7] = 0;          //((dwTagSize >> 14) & 0x7F );
	header[8] = 0;          //((dwTagSize >>  7) & 0x7F );
	header[9] = 0;          //((dwTagSize      ) & 0x7F );

	ret = save_to_file_multithread (mv_______,mp3file, header, 10, 1, 0);

	ret = id3v2tag_check (filename);

	if (ret)
	{

		tamanhodetag = ret;
		itens = malloc (ret + 100);
		ret = getv2data (filename, itens, ret);
		if (ret)
		{
			returnvalue = 3;
			goto saida;
		}

		ptr = itens;
		ptr = ptr + 10;
getinfo:
		;
		if (0 == *ptr || ((ptr - itens) + 10) >= tamanhodetag)
		{
			if (TENC)
			{

				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2EncodedBy)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2EncodedBy);
				}

				ret = save_to_file (mp3file, "TENC", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0x40;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2EncodedBy)
				{
					save_to_file (mp3file,
					              mv_______->id3_c___v2EncodedBy, strlen (mv_______->id3_c___v2EncodedBy), 1, 0);
				}
			}
			if (WXXX)
			{
				frame_handled = 1;
				sizetowrite = 2;
				if (mv_______->id3_c___v2URL)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2URL);
				}
				ret = save_to_file (mp3file, "WXXX", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0\0", 2, 1, 0);
				if (mv_______->id3_c___v2URL)
				{
					save_to_file (mp3file, mv_______->id3_c___v2URL, strlen (mv_______->id3_c___v2URL), 1, 0);
				}
			}
			if (TCOP)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2Copyright)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Copyright);
				}
				ret = save_to_file (mp3file, "TCOP", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2Copyright)
				{
					save_to_file (mp3file,
					              mv_______->id3_c___v2Copyright, strlen (mv_______->id3_c___v2Copyright), 1, 0);
				}
			}
			if (TOPE)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2OriginalArtist)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2OriginalArtist);
				}
				ret = save_to_file (mp3file, "TOPE", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2OriginalArtist)
				{
					save_to_file (mp3file,
					              mv_______->id3_c___v2OriginalArtist,
					              strlen (mv_______->id3_c___v2OriginalArtist), 1, 0);
				}
			}
			if (TCOM)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2Composer)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Composer);
				}
				ret = save_to_file (mp3file, "TCOM", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2Composer)
				{
					save_to_file (mp3file,
					              mv_______->id3_c___v2Composer, strlen (mv_______->id3_c___v2Composer), 1, 0);
				}
			}
			if (TCON)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2Genre)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Genre);
				}
				ret = save_to_file (mp3file, "TCON", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2Genre)
				{
					save_to_file (mp3file, mv_______->id3_c___v2Genre, strlen (mv_______->id3_c___v2Genre), 1, 0);
				}
			}
			if (TRCK)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2Track)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Track);
				}
				ret = save_to_file (mp3file, "TRCK", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2Track)
				{
					save_to_file (mp3file, mv_______->id3_c___v2Track, strlen (mv_______->id3_c___v2Track), 1, 0);
				}
			}
			if (COMM)
			{
				frame_handled = 1;
				sizetowrite = 5;
				if (mv_______->id3_c___v2Comment)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Comment);
				}
				ret = save_to_file (mp3file, "COMM", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0\0\0\0\0\0\0\0\0\0", 5, 1, 0);
				if (mv_______->id3_c___v2Comment)
				{
					save_to_file (mp3file, mv_______->id3_c___v2Comment, strlen (mv_______->id3_c___v2Comment), 1, 0);
				}
			}
			if (TYER)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2Year)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Year);
				}
				ret = save_to_file (mp3file, "TYER", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2Year)
				{
					save_to_file (mp3file, mv_______->id3_c___v2Year, strlen (mv_______->id3_c___v2Year), 1, 0);
				}
			}
			if (TALB)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2Album)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Album);
				}

				ret = save_to_file (mp3file, "TALB", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				//dprintf("1 valor de invertbits %d\n", ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2Album)
				{
					save_to_file (mp3file, mv_______->id3_c___v2Album, strlen (mv_______->id3_c___v2Album), 1, 0);
				}
			}
			if (TPE1)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2Artist)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Artist);
				}
				ret = save_to_file (mp3file, "TPE1", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2Artist)
				{
					save_to_file (mp3file, mv_______->id3_c___v2Artist, strlen (mv_______->id3_c___v2Artist), 1, 0);
				}
			}
			if (TIT2)
			{
				frame_handled = 1;
				sizetowrite = 1;
				if (mv_______->id3_c___v2Title)
				{
					sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Title);
				}
				ret = save_to_file (mp3file, "TIT2", 4, 1, 0);
				ret = sizetowrite;
				ret = invertbits (ret);
				ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
				header[0] = 0;
				header[1] = 0;
				save_to_file (mp3file, header, 2, 1, 0);
				save_to_file (mp3file, "\0", 1, 1, 0);
				if (mv_______->id3_c___v2Title)
				{
					save_to_file (mp3file, mv_______->id3_c___v2Title, strlen (mv_______->id3_c___v2Title), 1, 0);
				}
			}
			goto finish;
		}
		memset (v2nome, 0, 10);
		memcpy (v2nome, ptr, 4);
		ptr = ptr + 4;
		iptr = (int *) ptr;
		framesize = invertbits (*iptr);
		if ((framesize >= (thesize) || (framesize < 0)))
		{
			framesize = 1;
			memset (v2nome, 0, 10);
			noterror = 1;
		}
		ptr = ptr + 4;
		ptr++;
		ptr++;
		if (framesize > 64000)
		{
			returnvalue = 8;
			goto saida;
		}
		theframe = malloc (framesize + 10);
		memset (theframe, 0, framesize + 10);
		memcpy (theframe, ptr, framesize);
		theframe2 = malloc (framesize + 10);
		memset (theframe2, 0, framesize + 10);
		memcpy (theframe2, ptr, framesize);
		if (!memcmp (v2nome, "TENC", 4))
		{
			if (0 == TENC)
			{
				goto proximo;
			}
			TENC = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2EncodedBy)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2EncodedBy);
			}
			ret = save_to_file (mp3file, "TENC", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0x40;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2EncodedBy)
			{
				save_to_file (mp3file, mv_______->id3_c___v2EncodedBy, strlen (mv_______->id3_c___v2EncodedBy), 1, 0);
			}
		}
		if (!memcmp (v2nome, "WXXX", 4))
		{
			if (0 == WXXX)
			{
				goto proximo;
			}
			WXXX = 0;
			frame_handled = 1;
			sizetowrite = 2;
			if (mv_______->id3_c___v2URL)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2URL);
			}
			ret = save_to_file (mp3file, "WXXX", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0\0", 2, 1, 0);
			if (mv_______->id3_c___v2URL)
			{
				save_to_file (mp3file, mv_______->id3_c___v2URL, strlen (mv_______->id3_c___v2URL), 1, 0);
			}
		}
		if (!memcmp (v2nome, "TCOP", 4))
		{
			if (0 == TCOP)
			{
				goto proximo;
			}
			TCOP = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Copyright)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Copyright);
			}
			ret = save_to_file (mp3file, "TCOP", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Copyright)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Copyright, strlen (mv_______->id3_c___v2Copyright), 1, 0);
			}
		}
		if (!memcmp (v2nome, "TOPE", 4))
		{
			if (0 == TOPE)
			{

				goto proximo;
			}
			TOPE = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2OriginalArtist)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2OriginalArtist);
			}
			ret = save_to_file (mp3file, "TOPE", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2OriginalArtist)
			{
				save_to_file (mp3file, mv_______->id3_c___v2OriginalArtist,
				              strlen (mv_______->id3_c___v2OriginalArtist), 1, 0);
			}
		}
		if (!memcmp (v2nome, "TCOM", 4))
		{
			if (0 == TCOM)
			{

				goto proximo;
			}
			TCOM = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Composer)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Composer);
			}
			ret = save_to_file (mp3file, "TCOM", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Composer)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Composer, strlen (mv_______->id3_c___v2Composer), 1, 0);
			}
		}

		if (!memcmp (v2nome, "TCON", 4))
		{
			if (0 == TCON)
			{
				goto proximo;
			}
			TCON = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Genre)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Genre);
			}
			ret = save_to_file (mp3file, "TCON", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Genre)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Genre, strlen (mv_______->id3_c___v2Genre), 1, 0);
			}
		}

		if (!memcmp (v2nome, "TRCK", 4))
		{
			if (0 == TRCK)
			{
				goto proximo;
			}
			TRCK = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Track)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Track);
			}
			ret = save_to_file (mp3file, "TRCK", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Track)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Track, strlen (mv_______->id3_c___v2Track), 1, 0);
			}
		}

		if (!memcmp (v2nome, "COMM", 4))
		{
			if (0 == COMM)
			{
				goto proximo;
			}
			COMM = 0;
			frame_handled = 1;
			sizetowrite = 5;
			if (mv_______->id3_c___v2Comment)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Comment);
			}
			ret = save_to_file (mp3file, "COMM", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0\0\0\0\0\0\0\0\0\0", 5, 1, 0);
			if (mv_______->id3_c___v2Comment)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Comment, strlen (mv_______->id3_c___v2Comment), 1, 0);
			}
		}

		if (!memcmp (v2nome, "TYER", 4))
		{
			if (0 == TYER)
			{
				goto proximo;
			}
			TYER = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Year)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Year);
			}
			ret = save_to_file (mp3file, "TYER", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Year)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Year, strlen (mv_______->id3_c___v2Year), 1, 0);
			}
		}
		if (!memcmp (v2nome, "TALB", 4))
		{
			if (0 == TALB)
			{
				goto proximo;
			}
			TALB = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Album)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Album);
			}
			ret = save_to_file (mp3file, "TALB", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Album)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Album, strlen (mv_______->id3_c___v2Album), 1, 0);
			}
		}

		if (!memcmp (v2nome, "TPE1", 4))
		{
			if (0 == TPE1)
			{
				goto proximo;
			}
			TPE1 = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Artist)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Artist);
			}
			ret = save_to_file (mp3file, "TPE1", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Artist)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Artist, strlen (mv_______->id3_c___v2Artist), 1, 0);
			}
		}

		if (!memcmp (v2nome, "TIT2", 4))
		{
			if (0 == TIT2)
			{
				goto proximo;
			}
			TIT2 = 0;
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Title)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Title);
			}
			ret = save_to_file (mp3file, "TIT2", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Title)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Title, strlen (mv_______->id3_c___v2Title), 1, 0);
			}
		}

		if ((0 == frame_handled) && noterror)
		{
			save_to_file (mp3file, v2nome, 4, 1, 0);
			ret = invertbits (framesize);
			save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			save_to_file (mp3file, "\0\0", 2, 1, 0);
			save_to_file (mp3file, theframe2, framesize, 1, 0);
		}

proximo:
		;
		ptr += framesize;
		free (theframe);
		theframe = NULL;
		free (theframe2);
		theframe2 = NULL;
		frame_handled = 0;
		goto getinfo;;
	}
	else
	{
		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2EncodedBy)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2EncodedBy);
			}
			ret = save_to_file (mp3file, "TENC", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0x40;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2EncodedBy)
			{
				save_to_file (mp3file, mv_______->id3_c___v2EncodedBy, strlen (mv_______->id3_c___v2EncodedBy), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 2;
			if (mv_______->id3_c___v2URL)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2URL);
			}
			ret = save_to_file (mp3file, "WXXX", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0\0", 2, 1, 0);
			if (mv_______->id3_c___v2URL)
			{
				save_to_file (mp3file, mv_______->id3_c___v2URL, strlen (mv_______->id3_c___v2URL), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Copyright)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Copyright);
			}
			ret = save_to_file (mp3file, "TCOP", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Copyright)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Copyright, strlen (mv_______->id3_c___v2Copyright), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2OriginalArtist)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2OriginalArtist);
			}
			ret = save_to_file (mp3file, "TOPE", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2OriginalArtist)
			{
				save_to_file (mp3file, mv_______->id3_c___v2OriginalArtist,
				              strlen (mv_______->id3_c___v2OriginalArtist), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Composer)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Composer);
			}
			ret = save_to_file (mp3file, "TCOM", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Composer)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Composer, strlen (mv_______->id3_c___v2Composer), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Genre)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Genre);
			}
			ret = save_to_file (mp3file, "TCON", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Genre)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Genre, strlen (mv_______->id3_c___v2Genre), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Track)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Track);
			}
			ret = save_to_file (mp3file, "TRCK", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Track)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Track, strlen (mv_______->id3_c___v2Track), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 5;
			if (mv_______->id3_c___v2Comment)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Comment);
			}
			ret = save_to_file (mp3file, "COMM", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0\0\0\0\0\0\0\0\0\0", 5, 1, 0);
			if (mv_______->id3_c___v2Comment)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Comment, strlen (mv_______->id3_c___v2Comment), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Year)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Year);
			}
			ret = save_to_file (mp3file, "TYER", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Year)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Year, strlen (mv_______->id3_c___v2Year), 1, 0);
			}
		}
		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Album)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Album);
			}
			ret = save_to_file (mp3file, "TALB", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Album)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Album, strlen (mv_______->id3_c___v2Album), 1, 0);
			}
		}
		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Artist)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Artist);
			}
			ret = save_to_file (mp3file, "TPE1", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Artist)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Artist, strlen (mv_______->id3_c___v2Artist), 1, 0);
			}
		}

		if (1)
		{
			frame_handled = 1;
			sizetowrite = 1;
			if (mv_______->id3_c___v2Title)
			{
				sizetowrite = sizetowrite + strlen (mv_______->id3_c___v2Title);
			}
			ret = save_to_file (mp3file, "TIT2", 4, 1, 0);
			ret = sizetowrite;
			ret = invertbits (ret);
			ret = save_to_file (mp3file, (char *) &ret, 4, 1, 0);
			header[0] = 0;
			header[1] = 0;
			save_to_file (mp3file, header, 2, 1, 0);
			save_to_file (mp3file, "\0", 1, 1, 0);
			if (mv_______->id3_c___v2Title)
			{
				save_to_file (mp3file, mv_______->id3_c___v2Title, strlen (mv_______->id3_c___v2Title), 1, 0);
			}
		}
	}

finish:
	;
	{

		char buffer[4097];
		int ret;
		int atributos;
		atributos = GetFileAttributes (filename);
		ret = SetFileAttributes (filename, FILE_ATTRIBUTE_NORMAL);
		ret = (int) getfilesize (mp3file);
		header[0] = 'I';
		header[1] = 'D';
		header[2] = '3';
		// Version number
		header[3] = 3;
		header[4] = 0;
		// Clear Flags byte
		header[5] = 0;
		// Write tag length
		header[6] = ((ret >> 21) & 0x7F);
		header[7] = ((ret >> 14) & 0x7F);
		header[8] = ((ret >> 7) & 0x7F);
		header[9] = ((ret) & 0x7F);
		if ((out = _wfopen (permissive_name_m_(amanda_utf8towide_3_(mp3file)), L"rb+")) == NULL)
		{
			returnvalue = 4;
			goto saida;
		}
		ret = fwrite (header, 1, 10, out);
		fclose (out);
		out = NULL;
		save_to_file (mp3file, "\0\0\0\0\0\0\0\0\0\0\0", 10, 1, 0);
		if ((in = _wfopen (permissive_name_m_(amanda_utf8towide_3_(filename)), L"rb")) == NULL)
		{
			returnvalue = 5;
			goto saida;
		}
		if ((out = _wfopen (permissive_name_m_(amanda_utf8towide_3_(mp3file)), L"ab")) == NULL)
		{
			returnvalue = 6;
			goto saida;
		}

		if (tamanhodetag)
		{
			ret = _fseeki64_arab (in, tamanhodetag, SEEK_SET);
		}

maisum:
		;
		ret = fread (buffer, 1, 4096, in);
		if (ret <= 0)
		{
			goto terminou;
		}

		ret = fwrite (buffer, 1, ret, out);
		goto maisum;;
terminou:
		;
		fclose (in);
		fclose (out);
		in = NULL;
		out = NULL;
		ret = CopyFile (mp3file, filename, 0);
		if (0 == ret)
		{
			returnvalue = 7;
			goto saida;
		}
		if ((unsigned int) atributos != 0xFFFFFFFF)
		{
			ret = SetFileAttributes (filename, atributos);
		}
		ret = DeleteFile (mp3file);
	}
saida:
	if (itens)
	{
		free (itens);
	}

	if (theframe)
	{
		free (theframe);
	}

	if (theframe2)
	{
		free (theframe2);
	}

	if (in)
	{
		fclose (in);
	}
	if (out)
	{
		fclose (out);
	}

	if (didfilename)
	{
		if (ispathfile (mp3file))
		{
			ret = DeleteFile (mp3file);
		}
	}
	return returnvalue;
}

int
remove_id3v2_tag (morcego___i___instance__a__bucaneiro_engineering *mv_______,char *filename)
{
	unicode_large *ul_______=
	calloc(            sizeof
	(      unicode_large),1);
	FILE *in          = NULL;
	FILE *out         = NULL;
	int didfilename   =    0;
	int tamanhodetag  =    0;
	int ret                 ;
	int returnvalue   =    0;
	char *itens       = NULL;
	char *theframe    = NULL;
	char *theframe2   = NULL;
   char mp3file[1827] = {0,};
	
	if (detect_readonly_file (filename))
	{
		returnvalue = 1;
		goto saida;
	}
	ret = createtempfilename (mv_______->id3_c___tempfolder, mp3file);
	if (!ret)
	{
		didfilename = 1;
	}
	else
	{
		returnvalue = 2;
		goto saida;
	}
	ret = id3v2tag_check (filename);
	if (ret)
	{
		char buffer[4097];
		int atributos;
		tamanhodetag = ret;
		atributos = GetFileAttributesW (utf8towide_fixed(ul_______,filename));
		ret = SetFileAttributesW (permissive_name_m_(amanda_utf8towide_3_(filename)), FILE_ATTRIBUTE_NORMAL);
		if ((in = _wfopen (permissive_name_m_(amanda_utf8towide_3_(filename)), L"rb")) == NULL)
		{
			//dprintf          ("The file 'data' was not opened\n");
			returnvalue = 3; //cannot open input file to read
			goto saida;
		}
		else
		{
			//dprintf          ("The file 'data' was opened\n");
		}

		if ((out = _wfopen (permissive_name_m_(amanda_utf8towide_3_(mp3file)), L"ab")) == NULL)
		{
			//dprintf          ("The file 'data' was not opened\n");
			returnvalue = 4; //cannot open temp file to write
			goto saida;
		}
		else
		{
			//dprintf          ("The file 'data' was opened\n");
		}


		if (tamanhodetag)
		{

			ret = _fseeki64_arab (in, tamanhodetag, SEEK_SET);; //dprintf("tamanho desocado %d \n", ftell (in));
		}
		else
		{

			;       //dprintf("nao vai deslocarporque nao tem tag \n");
		}

maisum:
		ret = fread (buffer, 1, 4096, in);
		if (ret <= 0)
		{

			goto terminou;
		}

		ret = fwrite (buffer, 1, ret, out);
		goto maisum;;
terminou:
		;
		fclose (in);
		fclose (out);
		in = NULL;
		out = NULL;;    //dprintf("fechou tudo \n");
// agora so falta copia um em cima do outro
		ret = CopyFileW (utf8towide_fixed(ul_______,mp3file), utf8towide_fixed(ul_______,filename), 0);
		if (0 == ret)
		{

			returnvalue = 5; //cannot replace original file
			goto saida;
		}

		if ((unsigned int) atributos != 0xFFFFFFFF)
		{
			ret = SetFileAttributesW (utf8towide_fixed(ul_______,filename), atributos);
		}

		ret = DeleteFileW (utf8towide_fixed(ul_______,mp3file));
	}


saida:


	if (itens)
	{
		;               //dprintf("liberando itens \n");
		free (itens);
	}

	if (theframe)
	{

		;               //dprintf("nao pode ocorrer \n");
		free (theframe);
	}

	if (theframe2)
	{

		;               //dprintf("nao pode ocorrer \n");
		free (theframe2);
	}

	if (in)
	{
		;               //dprintf("fechando in de rebote \n");
		fclose (in);
	}
	if (out)
	{
		;               //dprintf("fechando out de rebote \n");
		fclose (out);
	}

	if (didfilename)
	{

		if (ispathfile (mp3file))
		{
			;       //dprintf("deletando arquivo temporario \n");
			ret = DeleteFileW (utf8towide_fixed(ul_______,mp3file));
		}

	}
	free(ul_______);
	return returnvalue;
}

int
v2cleanup (morcego___i___instance__a__bucaneiro_engineering *mv_______)
{
	//dprintf("chamando clean up \n");

	//thinktwice (1);

	;                       //dprintf("v2 cleaning up \n");
	mv_______->id3_c___v2Composersize = 0;
	mv_______->id3_c___v2OriginalArtistsize = 0;
	mv_______->id3_c___v2Copyrightsize = 0;
	mv_______->id3_c___v2URLsize = 0;
	mv_______->id3_c___v2EncodedBysize = 0;
	mv_______->id3_c___v2Commentsize = 0;
	mv_______->id3_c___v2Genresize = 0;
	mv_______->id3_c___v2Yearsize = 0;
	mv_______->id3_c___v2Albumsize = 0;
	mv_______->id3_c___v2Artistsize = 0;
	mv_______->id3_c___v2Titlesize = 0;
	mv_______->id3_c___v2Tracksize = 0;
	if (mv_______->id3_c___v2Track)
	{
		free (mv_______->id3_c___v2Track);
		mv_______->id3_c___v2Track = NULL;
	}

	if (mv_______->id3_c___v2Title)
	{
		free (mv_______->id3_c___v2Title);
		mv_______->id3_c___v2Title = NULL;
	}

	if (mv_______->id3_c___v2Artist)
	{
		free (mv_______->id3_c___v2Artist);
		mv_______->id3_c___v2Artist = NULL;
	}

	if (mv_______->id3_c___v2Album)
	{
		free (mv_______->id3_c___v2Album);
		mv_______->id3_c___v2Album = NULL;
	}

	if (mv_______->id3_c___v2Year)
	{
		free (mv_______->id3_c___v2Year);
		mv_______->id3_c___v2Year = NULL;
	}

	if (mv_______->id3_c___v2Genre)
	{
		free (mv_______->id3_c___v2Genre);
		mv_______->id3_c___v2Genre = NULL;
	}

	if (mv_______->id3_c___v2Comment)
	{
		free (mv_______->id3_c___v2Comment);
		mv_______->id3_c___v2Comment = NULL;
	}

	if (mv_______->id3_c___v2EncodedBy)
	{
		free (mv_______->id3_c___v2EncodedBy);
		mv_______->id3_c___v2EncodedBy = NULL;
	}

	if (mv_______->id3_c___v2URL)
	{
		free (mv_______->id3_c___v2URL);
		mv_______->id3_c___v2URL = NULL;
	}

	if (mv_______->id3_c___v2Copyright)
	{
		free (mv_______->id3_c___v2Copyright);
		mv_______->id3_c___v2Copyright = NULL;
	}

	if (mv_______->id3_c___v2OriginalArtist)
	{

		free (mv_______->id3_c___v2OriginalArtist);
		mv_______->id3_c___v2OriginalArtist = NULL;

	}

	if (mv_______->id3_c___v2Composer)
	{

		free (mv_______->id3_c___v2Composer);
		mv_______->id3_c___v2Composer = NULL;

	}

	return 0;
}