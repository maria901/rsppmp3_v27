//by amanda & ricardo 30-08-2020 01-27

/*
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
    
        support: http://nomade.sourceforge.net/?AR=true&ar_debug=1
    
	direct programmers e-mails:
	Ricardo: arsoftware25@gmail.com  ricardo@arsoftware.net.br contato@locacaodiaria.com.br
	 Amanda: arsoftware10@gmail.com  amanda@arsoftware.net. br vendas@locacaodiaria.com.b r
	
	immediate contact(for a very fast answer) WhatsApp
	(+55)41 9627 1708 - it is always on
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
)
{
	if(-1 < amanda_level)
	{
		va_list args;
		char buffer[20000];
		va_start (args, format);
		vsprintf (buffer, format, args);
		if('\n' == buffer[strlen(buffer)-1])
		{
			buffer[strlen(buffer)-1]=' ';
		}
		strcat(buffer," _amanda_debug_");
		OutputDebugString (buffer);
		//someday we fix it...
	}
	return;
}
