AMANDA_FLAGS__=-O3 -Wmissing-prototypes -Wextra -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =

amanda_32: rspogg_32k.o 
	i686-w64-mingw32-gcc.exe -O3 -o decoder_32k.exe -L. -lvorbis_x86 -logg_x86 -lvorbisfile_x86 rspogg_32k.o -lvorbisfile_x86 -logg_x86 -lvorbis_x86 -logg_x86

rspogg_32k.o: rspogg_v2.c
	i686-w64-mingw32-gcc.exe -c -o rspogg_32k.o rspogg_v2.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
ricardo_64: rspogg_64k.o 
	x86_64-w64-mingw32-gcc -O3 -o decoder_64k.exe -L. -lvorbis_x64 -logg_x64 -lvorbisfile_x64 rspogg_64k.o -lvorbisfile_x64 -logg_x64 -lvorbis_x64 -logg_x64 

#	./decoder_64k.exe
	
rspogg_64k.o: rspogg_v2.c
	x86_64-w64-mingw32-gcc.exe -c -o rspogg_64k.o rspogg_v2.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

rspogg_32k.o: rspogg_v2.c
	i686-w64-mingw32-gcc.exe -c -o rspogg_32k.o rspogg_v2.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

shinkal_480: rspogg_64k.o pedro_64arp.o
	x86_64-w64-mingw32-gcc -O3 mislaine.def -mdll -o svc_ogg.dll pedro_64arp.o -L. -lvorbis_x64 -logg_x64 -lvorbisfile_x64 rspogg_64k.o -lvorbisfile_x64 -logg_x64 -lvorbis_x64 -logg_x64

	cp --preserve=timestamps *.c *.h *.def makefile *.a 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\ogg_m'

	cp --preserve=timestamps svc_ogg.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll'
	cp --preserve=timestamps svc_ogg.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone'
	cp --preserve=timestamps svc_ogg.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m'

shinkal_4800: rspogg_32k.o pedro_32arp.o
	i686-w64-mingw32-gcc.exe -O3 mislaine.def -mdll -o ./amanda_32/svc_ogg.dll pedro_32arp.o -L. -lvorbis_x86 -logg_x86 -lvorbisfile_x86 rspogg_32k.o -lvorbisfile_x86 -logg_x86 -lvorbis_x86 -logg_x86 -Wl,-enable-stdcall-fixup

	cp --preserve=timestamps *.c *.h *.def makefile *.a 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\ogg_m'

	cp --preserve=timestamps ./amanda_32/svc_ogg.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin_amanda_x86\mp3dll'
	cp --preserve=timestamps ./amanda_32/svc_ogg.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone_amanda_32'
	cp --preserve=timestamps ./amanda_32/svc_ogg.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m/amanda_32'

pedro_64arp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o pedro_64arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

pedro_32arp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o pedro_32arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
