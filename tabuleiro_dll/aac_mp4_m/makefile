AMANDA_FLAGS__=-O3 -Wall -Wmissing-prototypes -Wextra -Wfatal-errors -Werror -I.
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =
AMANDA_SIZE   =                                  62

amanda_32: aac_mp4_decode_32k.o audio_32k.o libfaad_32k.a libmp4_32k.a
	i686-w64-mingw32-gcc.exe -O3 -o decoder_32k.exe aac_mp4_decode_32k.o audio_32k.o libfaad_32k.a libmp4_32k.a
	
aac_mp4_decode_32k.o: aac_mp4_decode.c
	i686-w64-mingw32-gcc.exe -c -o aac_mp4_decode_32k.o aac_mp4_decode.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__)
	
audio_32k.o: audio.c
	i686-w64-mingw32-gcc.exe -c -o audio_32k.o audio.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__)
	
libfaad_32k.a:
#	make ar_clear  -C ./libfaad
	make amanda_32 -C ./libfaad
libmp4_32k.a:
#	make ar_clear  -C ./mp4ff
	make amanda_32 -C ./mp4ff

ricardo_64: aac_mp4_decode_64k.o audio_64k.o libfaad_64k.a libmp4_64k.a
	x86_64-w64-mingw32-gcc.exe -O3 -o decoder_64k.exe aac_mp4_decode_64k.o audio_64k.o libfaad_64k.a libmp4_64k.a

aac_mp4_decode_64k.o: aac_mp4_decode.c
	x86_64-w64-mingw32-gcc.exe -c -o aac_mp4_decode_64k.o aac_mp4_decode.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__)
	
audio_64k.o: audio.c
	x86_64-w64-mingw32-gcc.exe -c -o audio_64k.o audio.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__)
	
libfaad_64k.a:
#make ar_clear   -C ./libfaad
	make ricardo_64 -C ./libfaad
libmp4_64k.a:
#	make ar_clear   -C ./mp4ff
	make ricardo_64 -C ./mp4ff
	
shinkal_480: pedro_64arp.o aac_mp4_decode_64k.o audio_64k.o libfaad_64k.a libmp4_64k.a

	x86_64-w64-mingw32-gcc.exe -O3 mislaine.def -mdll -o svc_mp4.dll pedro_64arp.o aac_mp4_decode_64k.o audio_64k.o libfaad_64k.a libmp4_64k.a

	cp --preserve=timestamps *.c *.h *.def makefile *.a 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\aac_mp4_m'

#	cp --preserve=timestamps svc_mp4.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll'
	cp --preserve=timestamps svc_mp4.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone'
	cp --preserve=timestamps svc_mp4.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m'

shinkal_4800: pedro_32arp.o aac_mp4_decode_32k.o audio_32k.o libfaad_32k.a libmp4_32k.a

	i686-w64-mingw32-gcc.exe -O3 mislaine.def -mdll -o ./amanda_32/svc_mp4.dll pedro_32arp.o aac_mp4_decode_32k.o audio_32k.o libfaad_32k.a libmp4_32k.a -Wl,-enable-stdcall-fixup

	cp --preserve=timestamps *.c *.h *.def makefile *.a 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\aac_mp4_m'

#	cp --preserve=timestamps svc_mp4.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll'
	cp --preserve=timestamps ./amanda_32/svc_mp4.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone_amanda_32'
	cp --preserve=timestamps ./amanda_32/svc_mp4.dll 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project tabuleiro\opus_interface_m\amanda_32'


pedro_64arp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o pedro_64arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__)

pedro_32arp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o pedro_32arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__)