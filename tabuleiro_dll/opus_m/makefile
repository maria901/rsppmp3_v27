AMANDA_FLAGS__=-O3 -Wmissing-prototypes -Wextra -Wall -Wfatal-errors -Werror -Wno-implicit-fallthrough -Wno-absolute-value
FELINE_FLAGS__=-Wno-unused-function -Wno-cast-function-type -Wno-parentheses -I../opus-1.3.1/include -I../opus-1.3.1/celt -I../opus-1.3.1/silk -I.
JULIET_FLAGS  =

amanda_32: opusfile_example.c.32m.o pedro_32arp.o win32utf8.c.32.o
	touch opusfile_example.c
	i686-w64-mingw32-gcc.exe                   \
	-shared -o ./amanda_32/svc_opus.dll                    \
	mislaine.def                               \
	pedro_32arp.o                              \
	-Wl,-enable-stdcall-fixup win32utf8.c.32.o opusfile_example.c.32m.o ./amanda_32/svc_wav.dll ./amanda_32/svc_ogg.dll ./amanda_32/svc_mp4.dll ./amanda_32/svc_mp3.dll -L./ -lopusfile_x86 -logg_x86  -lopus_x86 $(AMANDA_FLAGS__) $(FELINE_FLAGS__) -static
	cp --preserve=timestamps *.def *.a *.h *.c makefile 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\opus_m'

	cp --preserve=timestamps ./amanda_32/svc_opus.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone_amanda_32'

opus_m.c.32m.o: opus_m.c
	i686-w64-mingw32-gcc.exe -c -o opus_m.c.32m.o opus_m.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
		
ricardo_64: opusfile_example.c.64m.o pedro_64arp.o win32utf8.c.o
	x86_64-w64-mingw32-gcc.exe                 \
	-shared -o svc_opus.dll                    \
	mislaine.def                               \
	pedro_64arp.o                              \
	-Wl,-enable-stdcall-fixup win32utf8.c.o opusfile_example.c.64m.o svc_flac.dll svc_wav.dll svc_ogg.dll svc_mp4.dll svc_mp3.dll -L./ -lopusfile_x64 -logg_x64  -lopus_x64 $(AMANDA_FLAGS__) $(FELINE_FLAGS__)
	cp --preserve=timestamps *.def *.a *.h *.c makefile 'C:\cygwin64_amandaricardo_koci_10.2.0\aoprojeto\tabuleiro_dll\opus_m'

	cp --preserve=timestamps svc_opus.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll'
	cp --preserve=timestamps svc_opus.dll 'C:\cygwin64_amandaricardo_koci_10.2.0\bin\mp3dll_standalone'
	
	#dumppe64 -v svc_opus.dll

opusfile_example.c.64m.o: opusfile_example.c
	x86_64-w64-mingw32-gcc.exe -c -o opusfile_example.c.64m.o opusfile_example.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
opusfile_example.c.32m.o: opusfile_example.c
	i686-w64-mingw32-gcc.exe -c -o opusfile_example.c.32m.o opusfile_example.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

pedro_64arp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o pedro_64arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

pedro_32arp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o pedro_32arp.o pedro.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

win32utf8.c.o: win32utf8.c
	x86_64-w64-mingw32-gcc.exe -c -o win32utf8.c.o win32utf8.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

win32utf8.c.32.o: win32utf8.c
	i686-w64-mingw32-gcc.exe -c -o win32utf8.c.32.o win32utf8.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)

