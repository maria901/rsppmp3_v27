

AMANDA_FLAGS__=-O3 -Wall -Wmissing-prototypes -Wextra -Wfatal-errors -Werror -Wno-stringop-overflow
FELINE_FLAGS__=-Wno-unused-function -DOPT_ACCURACY -DFPM_DEFAULT -DHAVE_CONFIG_H -DASO_ZEROCHECK
JULIET_FLAGS  =
AMANDA_SIZE   =                                                                               62

amanda_32: bit_32k.o decoder.2_32k.o fixed_32k.o frame_32k.o huffman_32k.o layer12_32k.o layer3.2_32k.o stream_32k.o synth_32k.o timer_32k.o version_32k.o

	i686-w64-mingw32-ar rcs madlib_32k.a bit_32k.o decoder.2_32k.o fixed_32k.o frame_32k.o huffman_32k.o layer12_32k.o layer3.2_32k.o stream_32k.o synth_32k.o timer_32k.o version_32k.o

	cp madlib_32k.a ../

bit_32k.o: bit.c
	i686-w64-mingw32-gcc.exe -c -o bit_32k.o bit.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
decoder.2_32k.o   : decoder.c 
	i686-w64-mingw32-gcc.exe -c -o decoder.2_32k.o decoder.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
fixed_32k.o: fixed.c
	i686-w64-mingw32-gcc.exe -c -o fixed_32k.o fixed.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
frame_32k.o: frame.c
	i686-w64-mingw32-gcc.exe -c -o frame_32k.o frame.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
huffman_32k.o: huffman.c
	i686-w64-mingw32-gcc.exe -c -o huffman_32k.o huffman.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
layer12_32k.o: layer12.c
	i686-w64-mingw32-gcc.exe -c -o layer12_32k.o layer12.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
layer3.2_32k.o    : layer3.c
	i686-w64-mingw32-gcc.exe -c -o layer3.2_32k.o layer3.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
stream_32k.o: stream.c
	i686-w64-mingw32-gcc.exe -c -o stream_32k.o stream.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
synth_32k.o: synth.c
	i686-w64-mingw32-gcc.exe -c -o synth_32k.o synth.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
timer_32k.o: timer.c
	i686-w64-mingw32-gcc.exe -c -o timer_32k.o timer.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
version_32k.o: version.c
	i686-w64-mingw32-gcc.exe -c -o version_32k.o version.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
ricardo_64: bit_64k.o decoder.2_64k.o fixed_64k.o frame_64k.o huffman_64k.o layer12_64k.o layer3.2_64k.o stream_64k.o synth_64k.o timer_64k.o version_64k.o

	x86_64-w64-mingw32-ar rcs madlib_64k.a bit_64k.o decoder.2_64k.o fixed_64k.o frame_64k.o huffman_64k.o layer12_64k.o layer3.2_64k.o stream_64k.o synth_64k.o timer_64k.o version_64k.o

	cp madlib_64k.a ../

bit_64k.o: bit.c
	x86_64-w64-mingw32-gcc.exe -c -o bit_64k.o bit.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
decoder.2_64k.o   : decoder.c 
	x86_64-w64-mingw32-gcc.exe -c -o decoder.2_64k.o decoder.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
fixed_64k.o: fixed.c
	x86_64-w64-mingw32-gcc.exe -c -o fixed_64k.o fixed.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
frame_64k.o: frame.c
	x86_64-w64-mingw32-gcc.exe -c -o frame_64k.o frame.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
huffman_64k.o: huffman.c
	x86_64-w64-mingw32-gcc.exe -c -o huffman_64k.o huffman.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
layer12_64k.o: layer12.c
	x86_64-w64-mingw32-gcc.exe -c -o layer12_64k.o layer12.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
layer3.2_64k.o    : layer3.c
	x86_64-w64-mingw32-gcc.exe -c -o layer3.2_64k.o layer3.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
stream_64k.o: stream.c
	x86_64-w64-mingw32-gcc.exe -c -o stream_64k.o stream.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
synth_64k.o: synth.c
	x86_64-w64-mingw32-gcc.exe -c -o synth_64k.o synth.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
timer_64k.o: timer.c
	x86_64-w64-mingw32-gcc.exe -c -o timer_64k.o timer.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
version_64k.o: version.c
	x86_64-w64-mingw32-gcc.exe -c -o version_64k.o version.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)