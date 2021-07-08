AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -I .
JULIET_FLAGS  =

ALINE_SIZE    =                                  62

amandaricardo_valquiria: ..\mv_from_be.h

	x86_64-w64-mingw32-gcc.exe -c -o             \
	../morcego_interface.o morcego_interface.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe $(ALINE_SIZE)
	@./espaco_arp.exe $(ALINE_SIZE) 0 100
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
