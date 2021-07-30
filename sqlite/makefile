AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-unused-function -I. -Wextra \
-DHAVE_OUR_AMAZING_FUNCTION_strncpy_z
	
ricardo_128: 
	@echo 'ok my master...'
		
	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_s_smart_ape__counter.ini version_amanda_s_smart_ape.smartape version_amanda_s_smart_ape.rc version_amanda_s_smart_ape.hh "65 bits" Amanda_27.DLL increase '2021' 'new icon july_i.ico'
	
	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/interface2/ver_amanda_27.o -O coff version_amanda_s_smart_ape.rc

	@x86_64-w64-mingw32-gcc -shared Amanda_27.DEF -o /bin/mp3dll/Amanda_27.DLL simplemysql.c /bw_tmp/interface2/ver_amanda_27.o -lsqlite3 -static $(AMANDA_FLAGS__) /bin/mp3dll/INTERFACE2.DLL /bin/mp3dll/RSPMP3OCX1.DLL
	
	@x86_64-w64-mingw32-strip /bin/mp3dll/Amanda_27.DLL

	@echo 'caralho...do meu amor'