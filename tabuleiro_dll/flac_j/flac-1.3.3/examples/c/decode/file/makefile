#2021 by amanda & ricardo
AMANDA_FLAGS__=-O3 -Wall -Wmissing-prototypes -Wextra -Wfatal-errors -Werror -I.
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =-I../../../../include

ricardo_64: main.c
	x86_64-w64-mingw32-gcc.exe -O3 -o test_m_.exe main.c libFLAC-static.a libogg_x64.a -static $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(Z) $(FELINE_FLAGS__)
	./test_m_.exe 'C:\Users\User\Downloads\Symphony No.6 (1st movement).flac' 'C:\Users\User\Downloads\Symphony No.6 (1st movement).flac.wav'
