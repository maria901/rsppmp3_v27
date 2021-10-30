#2021 april

AMANDA_FLAGS__=-O3 -Wall -Wmissing-prototypes -Wextra -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =
AMANDA_SIZE   =                              62
amanda_32: decode_32k.o madlib_32k.a madxlib_32k.o playmp3_32k.o

	i686-w64-mingw32-g++ -O3 -o play_32k.exe madlib_32k.a madxlib_32k.o playmp3_32k.o -static-libstdc++ -static-libgcc 		-lwinmm -lwininet madlib_32k.a

	i686-w64-mingw32-g++ -O3 -o decode_32k.exe decode_32k.o madlib_32k.a madxlib_32k.o -static-libstdc++ -static-libgcc 		-lwinmm -lwininet madlib_32k.a
	
#	play_32k.exe E:\musicas\abba-fernando.mp3
#	decode_32k.exe E:\musicas\abba-fernando.mp3

madxlib_32k.o: madxlib.cpp madxlib.h
	i686-w64-mingw32-g++.exe -c -o madxlib_32k.o madxlib.cpp $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
playmp3_32k.o: playmp3.c id3_jump.c
	i686-w64-mingw32-gcc.exe -c -o playmp3_32k.o playmp3.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
decode_32k.o: decoder.c id3_jump.c
	i686-w64-mingw32-gcc.exe -c -o decode_32k.o decoder.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
madlib_32k.a:
#	make ar_clear  -C ./mad
	make amanda_32 -C ./mad
	
ricardo_64: pedro_64arp.o decode_64k.o madlib_64k.a madxlib_64k.o

	x86_64-w64-mingw32-g++ -O3 mislaine.def -mdll -o svc_mp3.dll pedro_64arp.o decode_64k.o madlib_64k.a madxlib_64k.o -static-libstdc++ -static-libgcc 	  -lwinmm -lwininet madlib_64k.a
		
	cp --preserve=timestamps *.c *.h *.def makefile *.a 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\mp3_m'

#	cp --preserve=timestamps svc_mp4.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll'
	cp --preserve=timestamps svc_mp3.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone'
	cp --preserve=timestamps svc_mp3.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m'
#decode_64k.exe E:\musicas\abba-fernando.mp3

madxlib_64k.o: madxlib.cpp madxlib.h
	x86_64-w64-mingw32-g++.exe -c -o madxlib_64k.o madxlib.cpp $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
playmp3_64k.o: playmp3.c id3_jump.c
	x86_64-w64-mingw32-gcc.exe -c -o playmp3_64k.o playmp3.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
decode_64k.o: decoder.c id3_jump.c
	x86_64-w64-mingw32-gcc.exe -c -o decode_64k.o decoder.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
madlib_64k.a:
#	make ar_clear  -C ./mad
	make ricardo_64 -C ./mad

pedro_64arp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o pedro_64arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)