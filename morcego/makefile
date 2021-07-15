AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -I .
JULIET_FLAGS  =

ALINE_SIZE    =                                  62

include ../make_include

AMANDA_ESPACO_= $(RIC)

amandaricardo_valquiria: ../mp3_dll/mv_from_be.h \
	be_constants.h

	x86_64-w64-mingw32-gcc.exe -c -o             \
	../mp3_dll/morcego_interface.o               \
	morcego_interface.c                          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	$(AMANDA_ESPACO_)

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
