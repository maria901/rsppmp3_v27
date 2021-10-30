// 2021 amanda & ricardo

#define uchar unsigned char
#define uint unsigned int

static int
id3v2tag_check(char *filename)
{
	FILE *astdin = NULL;
	int ret;
	uchar item[255];
	uint fatia1;
	uint fatia2;
	uint fatia3;
	uint fatia4;
	int tamanho;

	{
		WCHAR *temp_a = malloc(AMANDA__SIZE_ww);
		WCHAR *temp_a2 = malloc(AMANDA__SIZE_ww);
		astdin = _wfopen(permissive_name_m_(amanda_utf8towide_1_(filename, temp_a), temp_a2), L"rb");
		free(temp_a);
		free(temp_a2);
	}

	if (astdin == NULL)
	{
		return 0;
	}

	fseek(astdin, 0, SEEK_END);

	tamanho = ftell(astdin);

	fseek(astdin, 0, SEEK_SET);

	ret = fread((char *)item, 1, 10, astdin);
	fclose(astdin);
	if (ret == 10)
	{
		if (('I' == item[0]) && (item[1] == 'D') && (item[2] == '3'))
		{
			fatia1 = (uint)item[6];
			fatia2 = (uint)item[7];
			fatia3 = (uint)item[8];
			fatia4 = (uint)item[9];
			fatia1 = (fatia1 << (7 * 3)) | (fatia2 << (7 * 2)) | (fatia3 << (7)) | fatia4;
			if ((int)tamanho < (int)fatia1)
			{
				return 0;
			}

			return fatia1 + 10;
		}
	}

	return 0;
}
