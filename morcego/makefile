AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-restrict -Wno-unused-function -I .

amandaricardo_valquiria: ../mp3_dll/mv_from_be.h be_constants.h

	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/morcego_interface.o morcego_interface.c $(AMANDA_FLAGS__)

amandaricardo_valquiria_shinkal: ../mp3_dll/mv_from_be.h be_constants.h

	x86_64-w64-mingw32-gcc.exe -DTHALIA_NEW_STANDALONE_AUDIO_PLAYER__ -c -o /bw_tmp/mp3_dll/morcego_interface_shinkal.o morcego_interface.c $(AMANDA_FLAGS__)

#	-rm *~*
#	-rm *.orig

ar_id:
#indent morcego_interface.c
	unc77.bat morcego_interface.c
clean:
	-@rm *.???~ >nulo 2>nulo
	-@rm *.unc-backup~	>nulo 2>nulo
	-@rm *.?~ >nulo 2>nulo
	-@rm nulo
	@echo Amanda it is ok...
