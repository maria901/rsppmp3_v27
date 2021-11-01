#2021 april

AMANDA_FLAGS__=-O3 -Wall -Wmissing-prototypes -Wextra -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =
AMANDA_SIZE   =                              62
	
shinkal_480: pedro_32arp.o decode_32k.o

	i686-w64-mingw32-g++ -O3 mislaine.def -mdll -o ./amanda_32/svc_wav.dll pedro_32arp.o decode_32k.o -static-libstdc++ -static-libgcc -Wl,-enable-stdcall-fixup
		
	cp --preserve=timestamps *.c *.def makefile 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\ric_wav_pcm_m'

#	cp --preserve=timestamps svc_mp4.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll'
	cp --preserve=timestamps ./amanda_32/svc_wav.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone_amanda_32'
	cp --preserve=timestamps ./amanda_32/svc_wav.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m\amanda_32'

ricardo_64: pedro_64arp.o decode_64k.o

	x86_64-w64-mingw32-g++ -O3 mislaine.def -mdll -o svc_wav.dll pedro_64arp.o decode_64k.o -static-libstdc++ -static-libgcc 	  		
	cp --preserve=timestamps *.c *.def makefile 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\ric_wav_pcm_m'

	cp --preserve=timestamps svc_wav.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone'
	cp --preserve=timestamps svc_wav.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m'

decode_64k.o: play_wav_pcm_binarywork_technology_m.c
	x86_64-w64-mingw32-gcc.exe -c -o decode_64k.o 'play_wav_pcm_binarywork_technology_m.c' $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

decode_32k.o: play_wav_pcm_binarywork_technology_m.c
	i686-w64-mingw32-gcc -c -o decode_32k.o 'play_wav_pcm_binarywork_technology_m.c' $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

pedro_64arp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o pedro_64arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

pedro_32arp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o pedro_32arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)