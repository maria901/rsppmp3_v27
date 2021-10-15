AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-restrict -Wextra -Wno-unused-function -I .
 
amandaricardo_valquiria: bucaneiro

bin\interface2.dll: ../morcego/be_constants.h mv_from_be.h  ..\interface2\libav.c ..\interface2\makefile ..\morcego\be_constants.h ..\interface2\libav_video.c ..\interface2\playlist.c ..\interface2\interface2.def

	@make amandaricardo_valquiria -C ..\interface2
	
/bw_tmp/mp3_dll/allpass.o: allpass.cpp ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-g++.exe -c -o /bw_tmp/mp3_dll/allpass.o allpass.cpp $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/analisys.o: analisys.c ..\morcego\be_constants.h ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/analisys.o analisys.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/audio.o: audio.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/audio.o audio.c $(AMANDA_FLAGS__)

bucaneiro: bin\interface2.dll ../morcego/be_constants.h mv_from_be.h  interface1.def /bw_tmp/mp3_dll/decoder.o /bw_tmp/mp3_dll/audio.o /bw_tmp/mp3_dll/revmodel.o /bw_tmp/mp3_dll/freeverb_plugin_2.o /bw_tmp/mp3_dll/unicode_large.o /bw_tmp/mp3_dll/rspini.o /bw_tmp/mp3_dll/mp3wav.o /bw_tmp/mp3_dll/id3.o /bw_tmp/mp3_dll/fourier.o /bw_tmp/mp3_dll/filebuffer.o /bw_tmp/mp3_dll/amanda_s_smart_ape___folder.o /bw_tmp/mp3_dll/iir.o /bw_tmp/mp3_dll/gain_analysis.o /bw_tmp/mp3_dll/analisys.o /bw_tmp/mp3_dll/normalization.o /bw_tmp/mp3_dll/dsp.o /bw_tmp/mp3_dll/rc4.o /bw_tmp/mp3_dll/freeverb_plugin.o /bw_tmp/mp3_dll/allpass.o /bw_tmp/mp3_dll/comb.o /bw_tmp/mp3_dll/freeverb_plugin_2.o /bw_tmp/mp3_dll/revmodel.o /bw_tmp/mp3_dll/pedro_64.o /bw_tmp/mp3_dll/amanda_s_smart_ape_sha512_k.o /bw_tmp/mp3_dll/morcego_interface.o /bw_tmp/mp3_dll/smartape.c_kk.o /bw_tmp/mp3_dll/soundtouch_arp.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" rspmp3ocx1.dll increase '2021' '../sqlite/new icon july_i.ico'

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/mp3_dll/ver.o -O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/version_morcego.o version_morcego.c $(AMANDA_FLAGS__)
 
	x86_64-w64-mingw32-g++.exe -mdll ricardo.c -o rspmp3ocx1.dll interface1.def /bw_tmp/mp3_dll/ver.o /bw_tmp/mp3_dll/decoder.o /bw_tmp/mp3_dll/revmodel.o /bw_tmp/mp3_dll/freeverb_plugin_2.o /bw_tmp/mp3_dll/comb.o /bw_tmp/mp3_dll/allpass.o /bw_tmp/mp3_dll/freeverb_plugin.o /bw_tmp/mp3_dll/rc4.o /bw_tmp/mp3_dll/dsp.o /bw_tmp/mp3_dll/normalization.o /bw_tmp/mp3_dll/analisys.o /bw_tmp/mp3_dll/gain_analysis.o /bw_tmp/mp3_dll/iir.o /bw_tmp/mp3_dll/amanda_s_smart_ape___folder.o /bw_tmp/mp3_dll/pedro_64.o /bw_tmp/mp3_dll/filebuffer.o /bw_tmp/mp3_dll/fourier.o /bw_tmp/mp3_dll/id3.o /bw_tmp/mp3_dll/mp3wav.o /bw_tmp/mp3_dll/rspini.o /bw_tmp/mp3_dll/unicode_large.o /bw_tmp/mp3_dll/audio.o /bw_tmp/mp3_dll/version_morcego.o /bw_tmp/mp3_dll/morcego_interface.o /bw_tmp/mp3_dll/amanda_s_smart_ape_sha512_k.o -lwinmm -lwininet /bw_tmp/mp3_dll/soundtouch_arp.a /bin/mp3dll/interface2.dll /bin/mp3dll/AMANDA_27.DLL /bin/mp3dll/svc_opus.dll $(AMANDA_FLAGS__) -lpsapi -static

#	-static-libstdc++ -static-libgcc             \ will keep it here for historical reasons...

	cp --preserve=timestamps rspmp3ocx1.dll /bin/mp3dll/rspmp3ocx1.dll
	cp --preserve=timestamps rspmp3ocx1.dll ../bin/
	rm rspmp3ocx1.dll
	
	@echo Amanda says that it is compiled....
	$(LICAO_DE_VIDA_DO_MEU_AMOR)
clean:
	-rm *.???~
	-rm *.unc-backup~
clean_k_p: clean_k_p_pass_1 bucaneiro
clean_k_p_pass_1:
	touch .\morcego_libav\libav_interface_new\libav.c
	touch .\morcego_libav\libav_interface_new\libav_video.c
	-rm /bw_tmp/mp3_dll/*.o
	-rm /bw_tmp/mp3_dll/*.a
/bw_tmp/mp3_dll/comb.o: comb.cpp ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-g++.exe -c -o /bw_tmp/mp3_dll/comb.o comb.cpp $(AMANDA_FLAGS__)

copy:
	make copy -C "C:\aocprojeto\mp3 dll\ACME_mp3_dll_192_build_2072\bucaneiro\win32\mp3dll\mp3dll\bin\x86\Release"
csharp:
#																		??? porque isto ainda tá aqui amanda?
	@make -C "C:\aocprojeto\mp3 dll\ACME_mp3_dll_192_build_2072\bucaneiro\win32\mp3dll\mp3dll"
/bw_tmp/mp3_dll/decoder.o: decoder.c win64.h player.c decoder.h ..\morcego\be_constants.h ../morcego/be_constants.h mv_from_be.h  be_xml.c
	x86_64-w64-mingw32-gcc.exe -D__BUCANEIRO__ -c -o /bw_tmp/mp3_dll/decoder.o decoder.c $(AMANDA_FLAGS__) -DPSAPI_VERSION=1
	
	cp decoder.c 'C:/Ava/documentation_kp/rsppmp3_doc_8.9.9/'
	cp  player.c 'C:/Ava/documentation_kp/rsppmp3_doc_8.9.9/'

/bw_tmp/mp3_dll/dsp.o: dsp.c ../morcego/be_constants.h mv_from_be.h  ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/dsp.o dsp.c $(AMANDA_FLAGS__)
	
/bw_tmp/mp3_dll/filebuffer.o: filebuffer.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/filebuffer.o filebuffer.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/amanda_s_smart_ape___folder.o: amanda_s_smart_ape___folder.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/amanda_s_smart_ape___folder.o amanda_s_smart_ape___folder.c $(AMANDA_FLAGS__) 

/bw_tmp/mp3_dll/fourier.o: fourier.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/fourier.o fourier.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/freeverb_plugin.o: freeverb_plugin.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/freeverb_plugin.o freeverb_plugin.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/freeverb_plugin_2.o: freeverb_plugin_2.cpp ../morcego/be_constants.h mv_from_be.h  denormals.h comb.h allpass.h
	x86_64-w64-mingw32-g++.exe -c -o /bw_tmp/mp3_dll/freeverb_plugin_2.o freeverb_plugin_2.cpp $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/gain_analysis.o: gain_analysis.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/gain_analysis.o gain_analysis.c $(AMANDA_FLAGS__)

id_new_libav:
	make id -C .\morcego_libav\libav_interface_new

/bw_tmp/mp3_dll/id3.o: id3.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/id3.o id3.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/iir.o: iir.c ../morcego/be_constants.h mv_from_be.h  spectrum60.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/iir.o iir.c $(AMANDA_FLAGS__)

#x86_64-w64-mingw32-gcc.exe -S -masm=intel $(AMANDA_FLAGS_) -o iir_sse.S iir.c
/bw_tmp/mp3_dll/morcego_interface.o: ../morcego/be_constants.h mv_from_be.h  ../morcego/morcego_interface.c
	@make amandaricardo_valquiria -C ../morcego	
	
/bw_tmp/mp3_dll/mp3wav.o: mp3wav.c ..\morcego\be_constants.h ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/mp3wav.o mp3wav.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/normalization.o: normalization.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/normalization.o normalization.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/pedro_64.o: pedro.c
	x86_64-w64-mingw32-gcC -c -o /bw_tmp/mp3_dll/pedro_64.o	pedro.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/rc4.o: audio.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/rc4.o rc4.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/revmodel.o: revmodel.cpp ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-g++.exe -c -o /bw_tmp/mp3_dll/revmodel.o revmodel.cpp $(AMANDA_FLAGS__)
	
/bw_tmp/mp3_dll/amanda_s_smart_ape_sha512_k.o: amanda_s_smart_ape_sha512_k.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/amanda_s_smart_ape_sha512_k.o amanda_s_smart_ape_sha512_k.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/rspini.o: rspini.c e_malloc.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/rspini.o rspini.c $(AMANDA_FLAGS__)

/bw_tmp/mp3_dll/soundtouch_arp.a: ../touch/SoundTouch.cpp ../touch/TDStretch.cpp ../touch/RateTransposer.cpp ../touch/FIRFilter.cpp ../touch/FIFOSampleBuffer.cpp ../touch/AAFilter.cpp ../touch/cpu_detect_x86_win.cpp ../touch/PeakFinder.cpp ../touch/BPMDetect.cpp ../touch/WavFile.cpp ../touch/RunParameters.cpp ../touch/interface.cpp
	@make amandaricardo_valquiria -C ../touch
	
/bw_tmp/mp3_dll/unicode_large.o: unicode_large.c ../morcego/be_constants.h mv_from_be.h 
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/unicode_large.o unicode_large.c $(AMANDA_FLAGS__)

aline_clean:
	-rm /bw_tmp/mp3_dll/*.o
	
	echo pronto mister...

smartape:

	x86_64-w64-mingw32-gcc.exe -o /bw_tmp/amandaricardo_mvbuild26_33.exe smartape.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__) -DAMANDA_S_SMART_APE_ENABLE_WIDE_FUNCTION_
	$(LICAO_DE_VIDA_DO_MEU_AMOR)

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_s_smart_ape__counter.ini AssemblyInfo.smartape AssemblyInfo.cs AssemblyInfo.hh "1024 bits" 	AssemblyInfo.viu.cs increase

	cp --preserve=timestamps AssemblyInfo.cs /aoprojeto/c#_sample/mp3dll/mp3dll/Properties/AssemblyInfo.cs

smartape_v27: /bw_tmp/mp3_dll/smartape.c_kk.o
	x86_64-w64-mingw32-gcc.exe -o /bw_tmp/amandaricardo_mvbuild26_33.exe /bw_tmp/mp3_dll/smartape.c_kk.o -O3
	$(LICAO_DE_VIDA_DO_MEU_AMOR)

/bw_tmp/mp3_dll/smartape.c_kk.o: smartape.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/mp3_dll/smartape.c_kk.o smartape.c $(AMANDA_FLAGS__) $(JULIET_FLAGS) $(FELINE_FLAGS__)  -DAMANDA_S_SMART_APE_ENABLE_WIDE_FUNCTION_
	$(LICAO_DE_VIDA_DO_MEU_AMOR)

	x86_64-w64-mingw32-gcc.exe -o /bw_tmp/amandaricardo_mvbuild26_33.exe /bw_tmp/mp3_dll/smartape.c_kk.o -O3
	$(LICAO_DE_VIDA_DO_MEU_AMOR)
