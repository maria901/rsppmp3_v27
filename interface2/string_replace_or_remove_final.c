//ricardo & amanda original code
/*
    <C/C++ source code of the support dlls>    
    Copyright (C) <2020>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
	and GNU LESSER GENERAL PUBLIC LICENSE along with this program.  
	If not, see <http://www.gnu.org/licenses/>.
    
    support: http://nomade.sourceforge.net
    
	direct programmers e-mails:
	Ricardo: arsoftware25@gmail.com
	Amanda : arsoftware10@gmail.com
	
	immediate contact(for a very fast answer) WhatsApp
	(+55)41 9627 1708 - it is always on
*/
 
#include <windows.h>
#include <stdio.h>
void morcego_string_replace(char*data,char*search_string,char*dest_string)
{
	int g;
	int p;
	int i;
	int size_of_dest=strlen(dest_string);
	int size_of_search=strlen(search_string);
	int size_of_data = strlen(data);
	int data_position=0;
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
		asrc = (double) size_of_search;
	}
	a = size_of_dest / asrc;
	size__ = (int) ceil (a);//bug found on this output size calculation, please be carefull
	data_large = calloc ((size_of_data * size__) + 1, 1);
	for(i=0; i<size_of_data; i++)
	{
		if(data[i]==search_string[0])
		{
			int desloca=i;
			for(p=0; p<size_of_search; p++)
			{
				if(0==data[desloca])
				{
					//printf("Achou o erro\n");
					goto jump_inside;
				}
				if(data[desloca++]!=search_string[p])
				{
					goto jump_inside;
				}
			}
			//aqui efetua em caso de realmente achar
			for(g=0; g<size_of_dest; g++)
			{
				data_large[data_position]=dest_string[g];
				data_position++;
			}
			i+=size_of_search-1; //ta certo
		}
		else
		{
jump_inside:
			;
			data_large[data_position++]=data[i];
		}
	}
	data_large[data_position]=0;
	strcpy(data,data_large);
	free(data_large);
	return;
}
