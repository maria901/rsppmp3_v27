/*

RSP Software 2008
  ______
 /_
__/vansa

rspsoftware@hotmail.com
http://rspsoftware.com.br

*/

#define Ricardinho_and_Little_Amanda_THESIZE (300*6)

#include /* amanda's smart ape */ <windows.h>
#include /* amanda's smart ape  */ <stdint.h>
#include /* amanda's smart ape   */ <stdio.h>
#include /* amanda's smart ape  */ <stdlib.h>
#include /* amanda's smart ape  */ <string.h>
#include /* amanda's smart ape    */ <time.h>
#include /* amanda's smart ape   */ <errno.h>
#include /* amanda's smart ape   */ <fcntl.h>
#include /* amanda's smart ape   */ <ctype.h>
#include /* amanda's smart ape    */ <math.h>
#include /* amanda's smart ape  */ <wctype.h>
#include /* amanda's smart ape   */ <wchar.h>
#include /* amanda's smart ape  */ <stdarg.h>
#include /* amanda's smart ape  */ <stddef.h>
#include /* amanda's smart ape  */ <setjmp.h>
#include /* amanda's smart ape  */ <locale.h>
#include /* amanda's smart ape  */ <signal.h>
#include /* amanda's smart ape  */ <limits.h>
#include /* amanda's smart ape   */ <float.h>
#include /* amanda's smart ape  */ <iso646.h>

#undef NDEBUG
#include /* amanda's smart ape  */ <assert.h>
#include /* amanda's smart ape */ <stdbool.h>
#include /* amanda's smart ape */ <process.h>

//#include /* amanda's smart ape */   "mysql.h" for historical reasons...

#include "version_amanda_s_smart_ape.hh"

//////////////////////////////////////////////////////////////////////////////////////////////////////
// function defines at 22:31

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

int __fastcall replacestringsensitive2_juliete(char *comando, char *source, char *dest);

bool __fastcall init_amanda_s_smart_ape(void);

//////////////////////////////////////////////////////////////////////////////////////////////////////
// suas funções amor...

void
mprintf (char *format, ...)
{
	va_list args;
	char buffer[1024];
	va_start (args, format);
	vsprintf (buffer, format, args);
	/*
	   MessageBox (0, buffer, "BW1", MB_ICONINFORMATION | MB_OK | MB_TOPMOST);
	   MessageBox (0, buffer, "BW2", MB_ICONWARNING     | MB_OK | MB_TOPMOST);
	   MessageBox (0, buffer, "BW3", MB_ICONQUESTION    | MB_OK | MB_TOPMOST);*/
	MessageBox (0, buffer, "BinaryWork Corp. Info", MB_ICONERROR | MB_OK | MB_SYSTEMMODAL);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void morcego_encoder_amanda_s_smart_ape(char *morcego_in_amanda_s_smart_ape)
{
	/*
			morcego_in = morcego_in.Replace("&", "&amp;");
			string str = morcego_in.Replace("'", "&apos;");
			str = str.Replace("\\", "&bar;"); //que bug fix hein amor...
			//str = str.Replace ("\"", "&apos;");
			return str;
	*/

	replacestringsensitive2_juliete(morcego_in_amanda_s_smart_ape,
									"&", "&amp;");
	replacestringsensitive2_juliete(morcego_in_amanda_s_smart_ape,
									"'", "&apos;");
	replacestringsensitive2_juliete(morcego_in_amanda_s_smart_ape,
									"\\", "&bar;");

	return;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// variaveis

bool * has_an_entry_amanda_s_smart_ap_ptr     = NULL;
char * webm________________amanda_s_smart_ape = NULL;
char * normalization_value_amanda_s_smart_ape = NULL;
char * normalization_valu2_amanda_s_smart_ape = NULL;
char * normalization_valu3_amanda_s_smart_ape = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////
#define MAXPATH_UTF_8_MODE_AMANDA_S_SMART_APE (MAX_PATH * 6 \
) /* is it enough */

#define SEU_BANCO_DE_DADOS_MEU_AMOR__AMANDA_S_SMART_APE ((((((("amanda_s_smart_ape.DB")))))))

#define Amanda_27_CONSTANTE_1027                                         (1027)
#define Amanda_27_CONSTANTE_100000                                      (100000)
//#define SEU_BANCO_DE_DADOS_MEU_AMOR__AMANDA_S_SMART_APE ((((((("nul")))))))

#include <sqlite3.h>
#include <stdio.h>

enum ava_mysql_mode
{
	/// <summary>
	/// Mode select, precisa de um callback.
	/// </summary>
	ar_Mode_Select = 1,
	/// <summary>
	/// Mode insert ou update ou delete ou outros que não precisam de um callback.
	/// </summary>
	ar_Mode_Insert_Delete_or_Update = 2,
	/// <summary>
	/// Mode count, para select count, não deve ser usado todo dia, ok.
	/// </summary>
	ar_Mode_Count = 3,
};

int
version_amanda_s_smart_ape(void)
{

	sqlite3 *db;
	sqlite3_stmt *res;

	int rc = sqlite3_open(":memory:", &db);

	if (rc != SQLITE_OK)
	{

		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}

	rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);

	if (rc != SQLITE_OK)
	{

		fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}

	rc = sqlite3_step(res);

	if (rc == SQLITE_ROW)
	{
		printf("->%s\n", sqlite3_column_text(res, 0));
	}

	sqlite3_finalize(res);
	sqlite3_close(db);

	return 0;
}

void strncpy_z(char *dest_z, char *src_z, int len);

#ifdef HAVE_OUR_AMAZING_FUNCTION_strncpy_z

void strncpy_z(char *dest_z, char *src_z, int len)
{
	assert(0 <= len);

	len--;

	if (0 > len)
	{
		len = 0;
	}

	if (strlen(src_z) < (size_t) len)
	{
		strcpy(dest_z, src_z);
	}
	else
	{
		memcpy(dest_z, src_z, len);
		dest_z[len] = 0;
	}
	return;
}

#endif

typedef struct unicode_large_
{
	WCHAR unicode_large_c___pUSC2[300];
	WCHAR unicode_large_c___pUSC2_2[300];
	char unicode_large_c___pUTF8[(300*6)];
	char unicode_large_c___pUTF8_2[(300*6)];
	int unicode_large_c___position_utf8;
	int unicode_large_c___position;
}   unicode_large;

char *__stdcall
widetoutf8_fixed
(
	unicode_large *ul_______,
        WCHAR * pUSC2
)
{
	if (0 == ul_______->unicode_large_c___position_utf8)
	{
		ul_______->unicode_large_c___position_utf8 = 1;
		WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) ul_______->unicode_large_c___pUTF8, Ricardinho_and_Little_Amanda_THESIZE, 0,
		                     0);
		return ul_______->unicode_large_c___pUTF8;
	}
	else
	{
		ul_______->unicode_large_c___position_utf8 = 0;
		WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) ul_______->unicode_large_c___pUTF8_2, Ricardinho_and_Little_Amanda_THESIZE, 0,
		                     0);
		return ul_______->unicode_large_c___pUTF8_2;
	}
	return NULL;
}

char * get_ava_name(void)
{
					 
	static char temp_Pk[MAX_PATH] = {
		               0,
	                   };
					 	
	if(0 == temp_Pk[0])
	{
		
		HMODULE       hmod;
		hmod = GetModuleHandle("rspmp3ocx1.dll");
		if (0 ==      hmod)
		{
			mprintf("Missing rspmp3ocx1.dll dll \n");
			exit       (1);
		}
		{
			WCHAR temp_w[300];
			unicode_large *ul = calloc(sizeof(unicode_large), 1);
			GetModuleFileNameW(hmod, temp_w, 300);

			strcpy(temp_Pk, widetoutf8_fixed(ul, temp_w));

			free(ul);
		}
		temp_Pk[strlen(    temp_Pk) - strlen("rspmp3ocx1.dll")] = 0;
		strcat(temp_Pk, "amanda_s_smart_ape.DB");//don`t be afraid, it will be replaced with a xml file with extension .mis, later in the code
	
	}
	
	return temp_Pk;
	
}

/**
 * Our amazing function to send SQL commands to SQLite
 * 
 * @param data__z_amanda_s_smart_ape despite this name it is the SQL command...
 * 
 * @param message_amanda_s_smart_ape a string message in case of errors, limited to 1027 chars
 * 
 * @return 0 if no error, 1 otherwise
 */ 
int ar_Mode_Insert_Delete_or_Update_function_amanda_s_smart_ape(char *data__z_amanda_s_smart_ape,
																__attribute__((unused)) char *message_amanda_s_smart_ape)
{
	//07/07/2021 7:07 smartape and amanda
	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open(get_ava_name(), &db);

	if (message_amanda_s_smart_ape)
	{
		message_amanda_s_smart_ape[0] = '\0';
	}

	if (rc != SQLITE_OK)
	{

		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));

		if (message_amanda_s_smart_ape)
		{
			strncpy_z(message_amanda_s_smart_ape, (void *) sqlite3_errmsg(db), 1027);
		}

		sqlite3_close(db);

		return 1;
	}

	char *sql = data__z_amanda_s_smart_ape;

	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

	if (rc != SQLITE_OK)
	{

		//fprintf(stderr, "SQL error: %s\n", err_msg);
		if (message_amanda_s_smart_ape)
			strncpy_z(message_amanda_s_smart_ape, err_msg, 1027);

		sqlite3_free(err_msg);
		sqlite3_close(db);

		return 1;
	}

	sqlite3_close(db);

	return 0;
}

int create_table_amanda_s_smart_ape(void)
{

	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open(get_ava_name(), &db);

	if (rc != SQLITE_OK)
	{

		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}

	char *sql = "CREATE TABLE IF NOT EXISTS Friends(Id INTEGER PRIMARY KEY, Name TEXT);"
    "INSERT INTO Friends(Name) VALUES ('Tom');"
    "INSERT INTO Friends(Name) VALUES ('Rebecca');"
    "INSERT INTO Friends(Name) VALUES ('Jim');"
    "INSERT INTO Friends(Name) VALUES ('Roger');"
    "INSERT INTO Friends(Name) VALUES ('Robert');";

	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

	if (rc != SQLITE_OK)
	{

		fprintf(stderr, "SQL error: %s\n", err_msg);

		sqlite3_free(err_msg);
		sqlite3_close(db);

		return 1;
	}

int last_id = sqlite3_last_insert_rowid(db);
    printf("The last Id of the inserted row is %d\n", last_id);

	sqlite3_close(db);

	return 0;
}

typedef int (*__cdecl callback_amanda_s_smart_ape_)(void *NotUsed,
													int argc,
													char **argv,
													char **azColName);

int callback_amanda_s_smart_ape(void *NotUsed,
								int argc,
								char **argv,
								char **azColName);

int ar_Mode_Select_function_amanda_s_smart_ape(__attribute__((unused)) char *data__z_amanda_s_smart_ape,
											   __attribute__((unused)) char *message_amanda_s_smart_ape,
											   callback_amanda_s_smart_ape_ callback_amanda_s_smart_ape___ 
											   )
{
	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open(get_ava_name(), &db);

	if (rc != SQLITE_OK)
	{
		/*
			fprintf(stderr,
			"Cannot open database: %s\n",
			sqlite3_errmsg(db));
		*/
		sqlite3_close(db);

		if (message_amanda_s_smart_ape)
		{
			strncpy_z(message_amanda_s_smart_ape, (void *) sqlite3_errmsg(db), 1027);
		}

		return 1;
	}

	char *sql = data__z_amanda_s_smart_ape;
        
    rc = sqlite3_exec(db, sql, callback_amanda_s_smart_ape___, 0, &err_msg);
    
    if (rc != SQLITE_OK )
	{
        /*
			fprintf(stderr, "Failed to select data\n");
			fprintf(stderr, "SQL error: %s\n", err_msg);
		*/
		if (message_amanda_s_smart_ape)
		{
			sprintf(message_amanda_s_smart_ape, "SQL error: %s", err_msg);
		}

        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}
//amanda
int callback_amanda_s_smart_ape_not_in_use(__attribute__((unused)) void *NotUsed,
								__attribute__((unused)) int argc,
								__attribute__((unused)) char **argv,
								__attribute__((unused)) char **azColName)
{

	NotUsed = 0;

	for (int i = 0; i < argc; i++)
	{
		if(0 == strcmp("webm________________amanda_s_smart_ape", azColName[i]))
		{
			strcpy(webm________________amanda_s_smart_ape, argv[i] ? argv[i] : "");
		}
		if(0 == strcmp("normalization_value_amanda_s_smart_ape", azColName[i]))
		{
			strcpy(normalization_value_amanda_s_smart_ape, argv[i] ? argv[i] : "");
		}
		if(0 == strcmp("normalization_valu2_amanda_s_smart_ape", azColName[i]))
		{
			strcpy(normalization_valu2_amanda_s_smart_ape, argv[i] ? argv[i] : "");
		}
		if(0 == strcmp("normalization_valu3_amanda_s_smart_ape", azColName[i]))
		{
			strcpy(normalization_valu2_amanda_s_smart_ape, argv[i] ? argv[i] : "");
		}
		
	}

	return 0;
}

//amanda1
int callback_amanda_s_smart_ape_23_39(__attribute__((unused)) void *NotUsed,
								__attribute__((unused)) int argc,
								__attribute__((unused)) char **argv,
								__attribute__((unused)) char **azColName)
{

	NotUsed = 0;

	(*has_an_entry_amanda_s_smart_ap_ptr) = true;

	for (int i = 0; i < argc; i++)
	{
		if(0 == strcmp("webm________________amanda_s_smart_ape", azColName[i]))
		{
			strcpy(webm________________amanda_s_smart_ape, argv[i] ? argv[i] : "");
		}
		if(0 == strcmp("normalization_value_amanda_s_smart_ape", azColName[i]))
		{			
			strcpy(normalization_value_amanda_s_smart_ape, argv[i] ? argv[i] : "");
			
		}//             normalization_valu2_amanda_s_smart_ape
		if(0 == strcmp("normalization_valu2_amanda_s_smart_ape", azColName[i]))
		{//        normalization_valu2_amanda_s_smart_ape
			strcpy(normalization_valu2_amanda_s_smart_ape, argv[i] ? argv[i] : "");
			
		}
		if(0 == strcmp("normalization_valu3_amanda_s_smart_ape", azColName[i]))
		{
			strcpy(normalization_valu3_amanda_s_smart_ape, argv[i] ? argv[i] : "");
		}
		
	}

	return 0;
}

//amanda2
bool __fastcall amanda_s_smart_ape_add_entry(__attribute__((unused)) char *entry_______________amanda_s_smart_ape_,
																__attribute__((unused)) char *webm________________amanda_s_smart_ape,
																__attribute__((unused)) char *normalization_value_amanda_s_smart_ape_replaygain,
																
																__attribute__((unused)) char *normalization_valu2_amanda_s_smart_ape_BENORMALIZE,
																
																__attribute__((unused)) char *normalization_valu3_amanda_s_smart_ape)
{
	int ret_amanda_s_smart_ape;

	char   message_for_amanda_s_smart_ape         [Amanda_27_CONSTANTE_1027                   ];
	char   entry_______________amanda_s_smart_ape [MAXPATH_UTF_8_MODE_AMANDA_S_SMART_APE      ];
	char * buffer_for_insert_amanda_s_smart_ape    = malloc(Amanda_27_CONSTANTE_100000)         ;
	
	if (false == init_amanda_s_smart_ape())
	{
		return false;
	}

	strcpy(entry_______________amanda_s_smart_ape, entry_______________amanda_s_smart_ape_)    ;

	morcego_encoder_amanda_s_smart_ape(entry_______________amanda_s_smart_ape)                 ;

	strcpy(buffer_for_insert_amanda_s_smart_ape, "insert into Amanda_27_cache(entry_______________amanda_s_smart_ape, webm________________amanda_s_smart_ape,  normalization_value_amanda_s_smart_ape, normalization_valu2_amanda_s_smart_ape) values ('");

	strcat(buffer_for_insert_amanda_s_smart_ape, entry_______________amanda_s_smart_ape);
	strcat(buffer_for_insert_amanda_s_smart_ape, "', '");
	strcat(buffer_for_insert_amanda_s_smart_ape, webm________________amanda_s_smart_ape),
	strcat(buffer_for_insert_amanda_s_smart_ape, "', '");
	strcat(buffer_for_insert_amanda_s_smart_ape, normalization_value_amanda_s_smart_ape_replaygain);
	strcat(buffer_for_insert_amanda_s_smart_ape, "', '");
	strcat(buffer_for_insert_amanda_s_smart_ape, normalization_valu2_amanda_s_smart_ape_BENORMALIZE);
	strcat(buffer_for_insert_amanda_s_smart_ape, "');");

	ret_amanda_s_smart_ape = ar_Mode_Insert_Delete_or_Update_function_amanda_s_smart_ape(buffer_for_insert_amanda_s_smart_ape, message_for_amanda_s_smart_ape);	
	
	if (ret_amanda_s_smart_ape)
	{
		free(buffer_for_insert_amanda_s_smart_ape);
		pedro_dprintf(1001, "Error inserting data %s\n", message_for_amanda_s_smart_ape);
		return false;
	}

	free(buffer_for_insert_amanda_s_smart_ape);
	return true;
}

//amanda2
bool __fastcall amanda_s_smart_ape_do_sql(__attribute__((unused)) char *sql_______________amanda_s_smart_ape_)
{
	int ret_amanda_s_smart_ape;

	char   message_for_amanda_s_smart_ape         [Amanda_27_CONSTANTE_1027                   ];
	char   entry_______________amanda_s_smart_ape [MAXPATH_UTF_8_MODE_AMANDA_S_SMART_APE      ];
	char * buffer_for_insert_amanda_s_smart_ape    = malloc(Amanda_27_CONSTANTE_100000)         ;
	
	if (false == init_amanda_s_smart_ape())
	{
		return false;
	}

	strcpy(entry_______________amanda_s_smart_ape, sql_______________amanda_s_smart_ape_)      ;

	//morcego_encoder_amanda_s_smart_ape(entry_______________amanda_s_smart_ape)                 ;
	
	ret_amanda_s_smart_ape = ar_Mode_Insert_Delete_or_Update_function_amanda_s_smart_ape(entry_______________amanda_s_smart_ape, message_for_amanda_s_smart_ape);	
	
	if (ret_amanda_s_smart_ape)
	{
		free(buffer_for_insert_amanda_s_smart_ape);
		
		return false;
	}

	free(buffer_for_insert_amanda_s_smart_ape);
	return true;
}

//amanda5
bool __fastcall init_amanda_s_smart_ape(void)
{
	int ret_amanda_s_smart_ape;
	
	char   message_for_amanda_s_smart_ape         [Amanda_27_CONSTANTE_1027                   ];
	char * buffer_for_query_amanda_s_smart_ape    = malloc(Amanda_27_CONSTANTE_100000)         ;

	ret_amanda_s_smart_ape = ar_Mode_Insert_Delete_or_Update_function_amanda_s_smart_ape("CREATE TABLE IF NOT EXISTS Amanda_27_cache (amanda_s_smart_ape INTEGER PRIMARY KEY, webm________________amanda_s_smart_ape TEXT, normalization_mode__amanda_s_smart_ape TEXT, normalization_value_amanda_s_smart_ape TEXT);", message_for_amanda_s_smart_ape);

	if (ret_amanda_s_smart_ape)
	{
		free(buffer_for_query_amanda_s_smart_ape);
		pedro_dprintf(1001, "Error creating table: %s\n", message_for_amanda_s_smart_ape);
		return false;
	}
	
	//str = "ALTER TABLE pagamentos_parcelados_i ADD controle_contacorrente_parcela text(300000);";

	ret_amanda_s_smart_ape = ar_Mode_Insert_Delete_or_Update_function_amanda_s_smart_ape("ALTER TABLE Amanda_27_cache ADD entry_______________amanda_s_smart_ape TEXT", message_for_amanda_s_smart_ape);

	if (ret_amanda_s_smart_ape)
	{
		pedro_dprintf(-1, "Error in ALTER table: %s\n", message_for_amanda_s_smart_ape);
		//return false;
	}
	ret_amanda_s_smart_ape = ar_Mode_Insert_Delete_or_Update_function_amanda_s_smart_ape("ALTER TABLE Amanda_27_cache ADD normalization_valu2_amanda_s_smart_ape TEXT", message_for_amanda_s_smart_ape);

	if (ret_amanda_s_smart_ape)
	{
		pedro_dprintf(-1, "Error in ALTER table: %s\n", message_for_amanda_s_smart_ape);
		//return false;
	}
	ret_amanda_s_smart_ape = ar_Mode_Insert_Delete_or_Update_function_amanda_s_smart_ape("ALTER TABLE Amanda_27_cache ADD normalization_valu3_amanda_s_smart_ape TEXT", message_for_amanda_s_smart_ape);

	if (ret_amanda_s_smart_ape)
	{
		pedro_dprintf(-1, "Error in ALTER table: %s\n", message_for_amanda_s_smart_ape);
		//return false;
	}
	free(buffer_for_query_amanda_s_smart_ape);
	return true;
}
//amanda3
bool __fastcall amanda_s_smart_ape_query_webm_and_normalization(__attribute__((unused)) char *entry_______________amanda_s_smart_ape_,
																__attribute__((unused)) char *webm________________amanda_s_smart_ape__,
																__attribute__((unused)) char *normalization_mode__amanda_s_smart_ape_not_in_use,
																__attribute__((unused)) char *normalization_value_amanda_s_smart_ape__,
																
																__attribute__((unused)) char *normalization_valu2_amanda_s_smart_ape__,
																
																__attribute__((unused)) char *normalization_valu3_amanda_s_smart_ape__,
																__attribute__((unused)) bool * has_an_entry_amanda_s_smart_ap_)
{
	int ret_amanda_s_smart_ape;
	
	char   message_for_amanda_s_smart_ape         [Amanda_27_CONSTANTE_1027                   ];
	char   entry_______________amanda_s_smart_ape [MAXPATH_UTF_8_MODE_AMANDA_S_SMART_APE      ];
	char * buffer_for_query_amanda_s_smart_ape    = malloc(Amanda_27_CONSTANTE_100000)         ;

	//init_amanda_s_smart_ape();

	webm________________amanda_s_smart_ape = webm________________amanda_s_smart_ape__;
	normalization_value_amanda_s_smart_ape = normalization_value_amanda_s_smart_ape__;
	normalization_valu2_amanda_s_smart_ape = normalization_valu2_amanda_s_smart_ape__;
	normalization_valu3_amanda_s_smart_ape = normalization_valu3_amanda_s_smart_ape__;

	has_an_entry_amanda_s_smart_ap_ptr = has_an_entry_amanda_s_smart_ap_;

	(*has_an_entry_amanda_s_smart_ap_ptr) = false;

	strcpy(entry_______________amanda_s_smart_ape, entry_______________amanda_s_smart_ape_)  ;

	if (false == init_amanda_s_smart_ape())
	{
		return false;
	}

	morcego_encoder_amanda_s_smart_ape(entry_______________amanda_s_smart_ape)           ;

	strcpy(buffer_for_query_amanda_s_smart_ape, "SELECT entry_______________amanda_s_smart_ape,  webm________________amanda_s_smart_ape, normalization_value_amanda_s_smart_ape, normalization_valu2_amanda_s_smart_ape, normalization_valu3_amanda_s_smart_ape FROM Amanda_27_cache WHERE entry_______________amanda_s_smart_ape = '");

	strcat(buffer_for_query_amanda_s_smart_ape, entry_______________amanda_s_smart_ape);
	strcat(buffer_for_query_amanda_s_smart_ape, "';");

	(*has_an_entry_amanda_s_smart_ap_ptr) = false;

	//exit(27);

	ret_amanda_s_smart_ape = ar_Mode_Select_function_amanda_s_smart_ape(buffer_for_query_amanda_s_smart_ape, message_for_amanda_s_smart_ape, callback_amanda_s_smart_ape_23_39);

	if (ret_amanda_s_smart_ape)
	{
		pedro_dprintf(1001, "Error on SELECT: %s\n", message_for_amanda_s_smart_ape);
		free(buffer_for_query_amanda_s_smart_ape);
		return false;
	}
		
	free(buffer_for_query_amanda_s_smart_ape);
	return true;
}

	//////////////////////////////////////////////////////

#if 0

int main()
{
	int ret_amanda_s_smart_ape;
	
	create_table_amanda_s_smart_ape();
	
	char message_for_amanda_s_smart_ape[1027];

	ret_amanda_s_smart_ape = ar_Mode_Insert_Delete_or_Update_function_amanda_s_smart_ape
	("insert into head values;", message_for_amanda_s_smart_ape);

	if(ret_amanda_s_smart_ape)
	{
		printf("Err: %s\n", message_for_amanda_s_smart_ape);
	}

	{

		//"SELECT COUNT(*) FROM cars"

		ret_amanda_s_smart_ape = ar_Mode_Select_function_amanda_s_smart_ape("SELECT COUNT(*) FROM cars", message_for_amanda_s_smart_ape, *callback_amanda_s_smart_ape);

		if (ret_amanda_s_smart_ape)
		{
			printf("Err: %s\n", message_for_amanda_s_smart_ape);
		}
	}

	return 0;
}

#endif
/*

como usar blob

#include <sqlite3.h>
#include <stdio.h>


int main(int argc, char **argv) {

    FILE *fp = fopen("woman.jpg", "rb");
    
    if (fp == NULL) {
        
        fprintf(stderr, "Cannot open image file\n");    
        
        return 1;
    }
        
    fseek(fp, 0, SEEK_END);
    
    if (ferror(fp)) {
        
        fprintf(stderr, "fseek() failed\n");
        int r = fclose(fp);

        if (r == EOF) {
            fprintf(stderr, "Cannot close file handler\n");          
        }    
        
        return 1;
    }  
    
    int flen = ftell(fp);
    
    if (flen == -1) {
        
        perror("error occurred");
        int r = fclose(fp);

        if (r == EOF) {
            fprintf(stderr, "Cannot close file handler\n");
        }
        
        return 1;     
    }
    
    fseek(fp, 0, SEEK_SET);
    
    if (ferror(fp)) {
        
        fprintf(stderr, "fseek() failed\n");
        int r = fclose(fp);

        if (r == EOF) {
            fprintf(stderr, "Cannot close file handler\n");
        }    
        
        return 1;
    }

    char data[flen+1];

    int size = fread(data, 1, flen, fp);
    
    if (ferror(fp)) {
        
        fprintf(stderr, "fread() failed\n");
        int r = fclose(fp);

        if (r == EOF) {
            fprintf(stderr, "Cannot close file handler\n");
        }
        
        return 1;     
    }
    
    int r = fclose(fp);

    if (r == EOF) {
        fprintf(stderr, "Cannot close file handler\n");
    }    
 
  
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    
    sqlite3_stmt *pStmt;

    char *sql = "INSERT INTO Images(Data) VALUES(?)";
    
    rc = sqlite3_prepare(db, sql, -1, &pStmt, 0);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        
        return 1;
    }    
    
    sqlite3_bind_blob(pStmt, 1, data, size, SQLITE_STATIC);    
    
    rc = sqlite3_step(pStmt);
    
    if (rc != SQLITE_DONE) {
        
        printf("execution failed: %s", sqlite3_errmsg(db));
    }
        
    sqlite3_finalize(pStmt);    

    sqlite3_close(db);

    return 0;
}

*/

/*

listar as tabelas disponiveis...

#include <sqlite3.h>
#include <stdio.h>


int callback(void *, int, char **, char **);


int main(void) {
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", 
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char *sql = "SELECT name FROM sqlite_master WHERE type='table'";
        
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}

int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName) {
    
    NotUsed = 0;
    
    for (int i = 0; i < argc; i++) {

        printf("%s\n", argv[i] ? argv[i] : "NULL");
    }
    
    return 0;
}

*/

/*

como definir uma transação

char *sql = "DROP TABLE IF EXISTS Friends;"
                "BEGIN TRANSACTION;" 
                "CREATE TABLE Friends(Id INTEGER PRIMARY KEY, Name TEXT);" 
                "INSERT INTO Friends(Name) VALUES ('Tom');" 
                "INSERT INTO Friends(Name) VALUES ('Rebecca');" 
                "INSERT INTO Friends(Name) VALUES ('Jim');" 
                "INSERT INTO Friend(Name) VALUES ('Robert');"
                "COMMIT;";


*/

#ifndef WIN64

static void amandaricardo_pereira_koci_string_replace(char *data_feline,
													  char *search_string_feline,
													  char *dest_string_feline);
/**
 * Function to replace a string in Windows, developed by me 24 years ago and the
 * bug was fixed during these years, now the number of bugs inside is low
 *
 */
static void amandaricardo_pereira_koci_string_replace(char *data_feline,
													  char *search_string_feline,
													  char *dest_string_feline)
{
	int g;
	int p;
	int i;
	int size_of_dest = strlen(dest_string_feline);
	int size_of_search = strlen(search_string_feline);
	int size_of_data = strlen(data_feline);
	int data_position = 0;
	char *data_large;
	double asrc;
	double a;
	int size__;
	if (0 == size_of_search)
	{
		asrc = 1.;
	}
	else
	{
		asrc = (double)size_of_search;
	}
	a = size_of_dest / asrc;
	size__ = (int)ceil(a);
	data_large = calloc((size_of_data * size__) + 1 + 100000, 1); //possible bug here...amanda
	for (i = 0; i < size_of_data; i++)
	{
		if (data_feline[i] == search_string_feline[0])
		{
			int desloca = i;
			for (p = 0; p < size_of_search; p++)
			{
				if (0 == data_feline[desloca])
				{
					goto jump_inside;
				}
				if (data_feline[desloca++] != search_string_feline[p])
				{
					goto jump_inside;
				}
			}

			for (g = 0; g < size_of_dest; g++)
			{
				data_large[data_position] = dest_string_feline[g];
				data_position++;
			}
			i += size_of_search - 1;
		}
		else
		{
		jump_inside:;
			data_large[data_position++] = data_feline[i];
		}
	}
	data_large[data_position] = 0;
	/*
	if(100000<strlen(data_large))
	{
		printf("Erro 1015: Tamanho de entradas superior a 100000 bytes, terminando o programa, contate o programador e mande um printscreen");
		exit(25);
	}
	*/
	strcpy(data_feline, data_large);
	free(data_large);
	return;
}

int __fastcall replacestringsensitive2_juliete(char *comando, char *source, char *dest)
{
	amandaricardo_pereira_koci_string_replace(comando, source, dest);
	return -27;
}

#endif