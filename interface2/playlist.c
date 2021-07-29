
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
 *     Suporte: https://arsoftware.net.br/binarywork_____________________       *
 *     Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/       *
 *              http: //nomade.sourceforge.net/binarywork_______________/       *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     Ricardinho:    arsoftware25@gmail.com    ricardo@arsoftware.net.br       *
 *     Koci______:    arsoftware10@gmail.com    am_koci@arsoftware.net.br       *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/
 
void process_playlist_junior_filho_do_ricardo(morcego___i___instance__a__bucaneiro_engineering * mv_______);

int
getpos (char *comando, char *string)
{
	char *intcomando;
	int ret;
	int sizeret;
	int i;
	int b;
	int c;
	int pos = 0;

	c = 0;

	intcomando = malloc (strlen (comando) + 2);

	strcpy (intcomando, comando);

	ret = strlen (intcomando);

	sizeret = strlen (string);

	if (sizeret > ret)
	{

		free (intcomando);
		return 0;
	}

	if (ret && sizeret)
	{

		for (i = 0; i < ret; i++)
		{
			c = i;
			if ((intcomando[i]) == (string[0]))
			{

				for (b = 0; b < sizeret; b++)
				{

					if (((intcomando[i + b]) != (string[b])))
					{
						goto error1;
					}

				}

				if (b == sizeret)
				{

					pos = i + 1;

					free (intcomando);
					return pos;
				}

error1:
				continue;
			}

		}

		free (intcomando);
		return pos;

	}
	else
	{
		free (intcomando);
		return 0;
	}
	;

	free (intcomando);
	return 0;

	free (intcomando);//why??!
	return c + 1;
}

void morcego_string_replace(char*data,char*search_string,char*dest_string);
#include "string_replace_or_remove_final.c"

void
strtolower (char *path)
{
	int ret;
	int i;
	ret = strlen (path);
	if (ret)
	{
		for (i = 0; i < ret; i++)
		{
			path[i] = tolower (path[i]);
		}
		return;
	}
}
char *
strrstr (char *s1, char *s2)
{
	char *sc2, *psc1, *ps1;
	if (*s2 == '\0')
	{
		return ((char *) s1);
	}
	ps1 = s1 + strlen (s1);
	while (ps1 != s1)
	{
		--ps1;
		for (psc1 = ps1, sc2 = s2;; )
		{
			if (*(psc1++) != *(sc2++))
			{
				break;
			}
			else if (*sc2 == '\0')
			{
				return ((char *) ps1);
			}
		}
	}
	return ((char *) NULL);
}
int
stripfilenameandpath (char *path, char *onlypath, char *onlyfilename)
{
	int ret;
	int i;
	int p;
	char temp[300*6];
	char *fixo;
	const int separator = '\\';
	fixo = path;
	if (path == NULL)
	{

		if (onlypath != NULL)
		{
			memset (onlypath, 0, 1);
		}

		if (onlyfilename != NULL)
		{
			memset (onlyfilename, 0, 1);
		}

		return 1;
	}

	ret = strlen (path);

	if (!ret)
	{

		if (onlypath != NULL)
		{
			memset (onlypath, 0, 1);
		}

		if (onlyfilename != NULL)
		{
			memset (onlyfilename, 0, 1);
		}

		return 0;
	}

	for (i = 0; i < ret; i++)
	{

		if (path[i] == separator)
		{
			goto continua;
		}

	}

	if (onlypath != NULL)
	{
		memset (onlypath, 0, 1);
	}

	if (onlyfilename != NULL)
	{
		strcpy (onlyfilename, path);
	}

	return 0;

	;
continua:
	;

	strcpy (temp, path);

	p = 0;

	for (i = strlen (path); i > -1; i--)
	{

		if (temp[i] == separator)
		{
			temp[i + 1] = 0;
			break;
		}
		p++;
	}

	p = ret - p;

	fixo += p + 1;
	if (onlypath != NULL)
	{
		strcpy (onlypath, temp);
	}
	if (onlyfilename != NULL)
	{
		strcpy (onlyfilename, fixo);
	}
	return 0;
}
int
strip_extension_alladin (char *data, char *ext)
{
	char temp[300*6];
	char *ptr = NULL;
	stripfilenameandpath (data, NULL, temp);
	ptr = strrstr (temp, ".");
	if (NULL == ptr)
	{
		strcpy (ext, "");
		return 0;
	}
	ptr++;
	strcpy (ext, ptr);
	strtolower (ext);
	return 0;
}

void process_playlist(morcego___i___instance__a__bucaneiro_engineering * mv_______)
{
	WCHAR *__stdcall
	utf8towide_multithread
	(
		__int64 mv_instance,
		const char *pUTF8
	)
	;

	char playlist_path[300*6];

	__int64 mv_instance=(__int64)(__INT32_OR_INT64)mv_______;

/*
   char *mv_______->playlist_c___media_files[50000];
        int mv_______->playlist_c___media_files_int[50000][2];
        int mv_______->playlist_c___media_files_count;
 */
	int i;

	stripfilenameandpath (mv_______->playlist_c___playlist_filename, playlist_path, NULL);

	for(i=0; i<mv_______->playlist_c___media_files_count; i++)
	{
		if(mv_______->playlist_c___media_files[i])
		{
			//dprintf("dando free");
			free(mv_______->playlist_c___media_files[i]);
			mv_______->playlist_c___media_files[i]=NULL;
		}
	}
	mv_______->playlist_c___player_index=0;
	mv_______->playlist_c___media_files_count=0;

	//now read the data
	{
		FILE *myfile=NULL;

		myfile=_wfopen (utf8towide_multithread(mv_instance,mv_______->playlist_c___playlist_filename),L"rb");
		if(myfile)
		{

			char media_file[300*4+1]={0,};

			while(fgets(media_file, 300*4, myfile))
			  {
			    if(0 == ftell(myfile))//he he he...
			      {
				break;
			      }
			    {
					int ret;
					ret = getpos(media_file,"media src=");
					if(ret)
					{

						char media_file_[300*4+1]={0,};
						strcpy(media_file_,&media_file[ret+strlen("media src=")]);
						ret=getpos(media_file_,"\"");
						media_file_[ret-1]=0;
						//te amo é isso ai
						morcego_string_replace(media_file_,"&amp;","&"); morcego_string_replace(media_file_,"&apos;","'");
						{

							if
							(
								('\\'==media_file_[0]&&'\\'==media_file_[1])
								||
								(':'==media_file_[1])
							)
							{

							}
							else
							{
								char temp[300*6]
								;
								strcpy(temp,playlist_path)
								;

								strcat(temp,media_file_);

								strcpy(media_file_,temp);

							}
						}

						if(mv_______->playlist_c___media_files_count<50000)
						{
							mv_______->playlist_c___media_files[mv_______->playlist_c___media_files_count]=malloc(300*6+1);

							strcpy(mv_______->playlist_c___media_files[mv_______->playlist_c___media_files_count],&media_file_[0]);//what is this?!
							mv_______->playlist_c___media_files_count++;
						}

					}

				}

			}

			fclose(myfile);
		}
	}

}

int64_t
getfilesize_ar_fixed__(morcego___i___instance__a__bucaneiro_engineering * mv_______, char *infile_ar)
{
	__int64 ret;
	FILE *myfile;
	__int64 mv_instance = (__int64)(__INT32_OR_INT64)mv_______;

	if ((myfile = _wfopen(utf8towide_multithread(mv_instance, infile_ar), L"rb")) == NULL)
	{
		return -1;
	}
	ret = _fseeki64(myfile, 0, SEEK_END);
	ret = _ftelli64(myfile);
	fclose(myfile);
	return ret;
}

void process_playlist_junior_filho_do_ricardo(morcego___i___instance__a__bucaneiro_engineering * mv_______)
{
  int ret_arp;
  WCHAR *__stdcall
    utf8towide_multithread
    (
     __int64 mv_instance,
     const char *pUTF8
     )
    ;

  __int64 mv_instance=(__int64)(__INT32_OR_INT64)mv_______;

  /*
    char *mv_______->playlist_c___media_files[50000];
    int mv_______->playlist_c___media_files_int[50000][2];
    int mv_______->playlist_c___media_files_count;
  */
  int i;

  for(i=0; i<mv_______->playlist_c___media_files_count; i++)
    {
      if(mv_______->playlist_c___media_files[i])
	{
	  //dprintf("dando free");
	  free(mv_______->playlist_c___media_files[i]);
	  mv_______->playlist_c___media_files[i]=NULL;
	}
    }
  mv_______->playlist_c___player_index=0;
  mv_______->playlist_c___media_files_count=0;

  //now read the data
  {
    FILE *myfile=NULL;

    myfile=_wfopen (utf8towide_multithread(mv_instance,mv_______->playlist_c___playlist_filename),L"rb");
    if(myfile)
      {

	char media_file[300*4+1]={0,};

	while(fgets(media_file, 300*4, myfile))
	  {
	    if(0 == ftell(myfile))
	      {
		break;
	      }	    

	    char   media_file_copy__amanda_s_smart_ape[300*4+1] = {0,};
	    char   media_file_                        [300*4+1] = {0,};
		char * ptr__amanda_s_smart_ape     ;
		char * ptr__amanda_s_smart_ape_init;
	    strcpy(media_file_, media_file);
	    ret_arp=getpos(media_file_,"\n");  
				  
	    media_file_[ret_arp-1]=0;

	    ret_arp=getpos(media_file_,"\r");
  
	    if(0 != ret_arp)
	      //ok...!?
	      media_file_[ret_arp-1]=0;

	    if(0 == strlen(media_file_))
	      {
		continue;
	      }
	      
	    //viu?...

		  {
			  if ((ptr__amanda_s_smart_ape_init = strstr(media_file_, "#")))
			  {
				  
				  strcpy(media_file_copy__amanda_s_smart_ape, media_file_);

				  ptr__amanda_s_smart_ape = strstr(media_file_copy__amanda_s_smart_ape, "#");

				  if (ptr__amanda_s_smart_ape)//double check...this is it...
				  {
					  
					  if ('#' == media_file_[0])
					  {
						  continue;
					  }

					  *ptr__amanda_s_smart_ape = 0;
					  if (-1 != getfilesize_ar_fixed__(mv_______, media_file_copy__amanda_s_smart_ape))
					   {
						  *ptr__amanda_s_smart_ape_init = 0;
					  }
				  }
			  }
		  }

		if(mv_______->playlist_c___media_files_count<50000)// kkkk em casa de ferreiro espeto de pau
	      {
		mv_______->playlist_c___media_files[mv_______->playlist_c___media_files_count]=malloc(300*6+1);

		strcpy(mv_______->playlist_c___media_files[mv_______->playlist_c___media_files_count],&media_file_[0]);//what is this?!
		mv_______->playlist_c___media_files_count++;
	      }	    
	  }
	fclose(myfile);
      }
  }
}

int is_playlist(morcego___i___instance__a__bucaneiro_engineering * mv_______,char*filename_)
{
	char extension[300*6];
	strip_extension_alladin
	(
		filename_,
		extension
	)
	;

	if(0==strcmp(extension,"wpl"))
	{
		mv_______->playlist_c___is_playlist=1;
		strcpy(mv_______->playlist_c___playlist_filename,filename_);
		process_playlist(mv_______);
		return 1;
	}
	
	if(0==strcmp(extension,"jun"))
	{
		mv_______->playlist_c___is_playlist=1;
		strcpy(mv_______->playlist_c___playlist_filename,filename_);
		process_playlist_junior_filho_do_ricardo(mv_______);
		return 1;
	}
	mv_______->playlist_c___is_playlist=0;
	return 0;
}
