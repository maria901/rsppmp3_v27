AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =

amandaricardo_valquiria: SoundTouch_64arp.o      \
	TDStretch_64arp.o RateTransposer_64arp.o     \
	FIRFilter_64arp.o FIFOSampleBuffer_64arp.o   \
	AAFilter_64arp.o  cpu_detect_x86_win_64arp.o \
	PeakFinder_64arp.o BPMDetect_64arp.o         \
	WavFile_64arp.o   RunParameters_64arp.o      \
	interface.2._64arp.o 
	x86_64-w64-mingw32-ar.exe rcs                \
	..\soundtouch_arp.a                              \
	SoundTouch_64arp.o                           \
	TDStretch_64arp.o RateTransposer_64arp.o     \
	FIRFilter_64arp.o FIFOSampleBuffer_64arp.o   \
	AAFilter_64arp.o  cpu_detect_x86_win_64arp.o \
	PeakFinder_64arp.o BPMDetect_64arp.o         \
	WavFile_64arp.o   RunParameters_64arp.o      \
	interface.2._64arp.o 
	
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
		
SoundTouch_64arp.o : SoundTouch.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	SoundTouch_64arp.o SoundTouch.cpp            \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
TDStretch_64arp.o : TDStretch.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	TDStretch_64arp.o TDStretch.cpp              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
RateTransposer_64arp.o : RateTransposer.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	RateTransposer_64arp.o RateTransposer.cpp    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
FIRFilter_64arp.o : FIRFilter.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	FIRFilter_64arp.o FIRFilter.cpp              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
FIFOSampleBuffer_64arp.o : FIFOSampleBuffer.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	FIFOSampleBuffer_64arp.o                     \
	FIFOSampleBuffer.cpp                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
AAFilter_64arp.o : AAFilter.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	AAFilter_64arp.o AAFilter.cpp                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
cpu_detect_x86_win_64arp.o :                     \
	cpu_detect_x86_win.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	cpu_detect_x86_win_64arp.o                   \
	cpu_detect_x86_win.cpp                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
PeakFinder_64arp.o : PeakFinder.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	PeakFinder_64arp.o PeakFinder.cpp            \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
BPMDetect_64arp.o : BPMDetect.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	BPMDetect_64arp.o BPMDetect.cpp              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
WavFile_64arp.o : WavFile.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	WavFile_64arp.o WavFile.cpp                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
RunParameters_64arp.o : RunParameters.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	RunParameters_64arp.o RunParameters.cpp      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
interface.2._64arp.o : interface.cpp
	x86_64-w64-mingw32-g++.exe -c -o             \
	interface.2._64arp.o interface.cpp           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	@./espaco_arp.exe 83 0 51
	
clean:
	-@rm *.orig >nulo  2>nulo
	-@rm *.???~ >nulo  2>nulo
	-@rm *.unc-backup~ >nulo 2>nulo
	-@rm *~* >nulo    2>nulo
	-@rm nulo
