#2021 by amanda & ricardo
AMANDA_FLAGS__=-O3 -Wall -Wmissing-prototypes -Wextra -Wfatal-errors -Werror -I.
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =-I./flac-1.3.3/include

amanda_32: play_flac_32m.c.o pedro_32arp.o amanda_command.c.32m.o makefile
	i686-w64-mingw32-gcc.exe -O3 -shared -o ./amanda_32/svc_flac.dll mislaine.def play_flac_32m.c.o amanda_command.c.32m.o pedro_32arp.o libFLAC-static_x86.a libogg_x86.a -static -DHAVE_CONFIG_H $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__) -Wl,-enable-stdcall-fixup
#	./test_m_.exe 'C:\Users\User\Downloads\Symphony No.6 (1st movement).flac' 'C:\Users\User\Downloads\Symphony No.6 (1st movement)_amanda_32_.flac.wav'
	
	cp --preserve=timestamps *.c *.def makefile *.a 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\flac_j'

	cp --preserve=timestamps ./amanda_32/svc_flac.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone_amanda_32'
	cp --preserve=timestamps ./amanda_32/svc_flac.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m\amanda_32'

ricardo_64: play_flac_64m.c.o pedro_64arp.o amanda_command.c.64m.o
	x86_64-w64-mingw32-gcc.exe -O3 -shared -o svc_flac.dll mislaine.def play_flac_64m.c.o amanda_command.c.64m.o pedro_64arp.o libFLAC-static.a libogg_x64.a -static $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__)
#	./test_m_.exe 'C:\Users\User\Downloads\Symphony No.6 (1st movement).flac' 'C:\Users\User\Downloads\Symphony No.6 (1st movement)_amanda_32_.flac.wav'
	
	cp --preserve=timestamps *.c *.def makefile *.a 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\flac_j'

	cp --preserve=timestamps svc_flac.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone'
	cp --preserve=timestamps svc_flac.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m'

play_flac_64m.c.o: play_flac_m.c my_header_ava.h makefile
	x86_64-w64-mingw32-gcc.exe -c -o play_flac_64m.c.o play_flac_m.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

play_flac_32m.c.o: play_flac_m.c my_header_ava.h
	i686-w64-mingw32-gcc.exe -c -o play_flac_32m.c.o play_flac_m.c -DHAVE_CONFIG_H $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

amanda_command.c.64m.o: amanda_command.c my_header_ava.h makefile
	x86_64-w64-mingw32-gcc.exe -c -o amanda_command.c.64m.o amanda_command.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

amanda_command.c.32m.o: amanda_command.c my_header_ava.h makefile
	i686-w64-mingw32-gcc.exe -c -o amanda_command.c.32m.o amanda_command.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

pedro_64arp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o pedro_64arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

pedro_32arp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o pedro_32arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)