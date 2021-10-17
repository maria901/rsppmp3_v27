#2021 april 03 - 19:30 by amand and ricardo

AMANDA_FLAGS__=-O3 -Wall -Wmissing-prototypes -Wextra -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -I. -DUSE_TAGGING
JULIET_FLAGS  =
AMANDA_SIZE   =                              62

amanda_32: mp4atom_32k.o mp4ff_32k.o mp4meta_32k.o mp4sample_32k.o mp4tagupdate_32k.o mp4util_32k.o

	i686-w64-mingw32-ar rcs libmp4_32k.a mp4atom_32k.o mp4ff_32k.o mp4meta_32k.o mp4sample_32k.o mp4tagupdate_32k.o 	mp4util_32k.o

	cp libmp4_32k.a ../

mp4atom_32k.o: mp4atom.c
	i686-w64-mingw32-gcc.exe -c -o mp4atom_32k.o mp4atom.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4ff_32k.o: mp4ff.c
	i686-w64-mingw32-gcc.exe -c -o mp4ff_32k.o mp4ff.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4meta_32k.o: mp4meta.c
	i686-w64-mingw32-gcc.exe -c -o mp4meta_32k.o mp4meta.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4sample_32k.o: mp4sample.c
	i686-w64-mingw32-gcc.exe -c -o mp4sample_32k.o mp4sample.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4tagupdate_32k.o: mp4tagupdate.c
	i686-w64-mingw32-gcc.exe -c -o mp4tagupdate_32k.o mp4tagupdate.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4util_32k.o: mp4util.c
	i686-w64-mingw32-gcc.exe -c -o mp4util_32k.o mp4util.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
ricardo_64: mp4atom_64k.o mp4ff_64k.o mp4meta_64k.o mp4sample_64k.o mp4tagupdate_64k.o mp4util_64k.o

	x86_64-w64-mingw32-ar rcs libmp4_64k.a mp4atom_64k.o mp4ff_64k.o mp4meta_64k.o mp4sample_64k.o mp4tagupdate_64k.o  	mp4util_64k.o

	cp libmp4_64k.a ../

mp4atom_64k.o: mp4atom.c
	x86_64-w64-mingw32-gcc.exe -c -o mp4atom_64k.o mp4atom.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4ff_64k.o: mp4ff.c
	x86_64-w64-mingw32-gcc.exe -c -o mp4ff_64k.o mp4ff.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4meta_64k.o: mp4meta.c
	x86_64-w64-mingw32-gcc.exe -c -o mp4meta_64k.o mp4meta.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4sample_64k.o: mp4sample.c
	x86_64-w64-mingw32-gcc.exe -c -o mp4sample_64k.o mp4sample.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4tagupdate_64k.o: mp4tagupdate.c
	x86_64-w64-mingw32-gcc.exe -c -o mp4tagupdate_64k.o mp4tagupdate.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)
	
mp4util_64k.o: mp4util.c
	x86_64-w64-mingw32-gcc.exe -c -o mp4util_64k.o mp4util.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)