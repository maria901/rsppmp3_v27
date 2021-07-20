AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-unused-function -I .

amandaricardo_valquiria: interface2.def ../mp3_dll/mv_from_be.h makefile /bw_tmp/interface2/libav.o /bw_tmp/interface2/libav_video.o /bw_tmp/interface2/amandaricardo_koci_dprintf.o /bw_tmp/amandaricardo_mvbuild26_33.exe


	@/bw_tmp/amandaricardo_mvbuild26_33.exe ./amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" interface2.dll increase 2021

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/interface2/ver.o -O coff version_ricardo_mislaine_final_2_.rc

	x86_64-w64-mingw32-gcc.exe -O3 -mdll -o interface2.dll /bw_tmp/interface2/libav_video.o /bw_tmp/interface2/libav.o amanda.c /bw_tmp/interface2/amandaricardo_koci_dprintf.o /bw_tmp/interface2/ver.o interface2.def /bin/mp3dll/avcodec-59.dll /bin/mp3dll/avdevice-59.dll /bin/mp3dll/avfilter-8.dll /bin/mp3dll/avformat-59.dll /bin/mp3dll/avutil-57.dll /bin/mp3dll/postproc-56.dll /bin/mp3dll/swresample-4.dll /bin/mp3dll/swscale-6.dll /bin/mp3dll/rspmp3ocx1.dll /bin/mp3dll/mod_sdl2_2_0_12_kp.dll -static

	@echo 

	cp --preserve=timestamps interface2.dll /bin/mp3dll/interface2.dll
	cp --preserve=timestamps interface2.dll ../bin/

	rm interface2.dll

#esfregue a lampada     "../mp3_dllrspmp3ocx1.dll" falta incluir isto

dump:
	dumppe avcodec-53.dll >avcodec-53.dll.txt.h
	dumppe avdevice-53.dll >avdevice-53.dll.txt.h
	dumppe avfilter-2.dll >avfilter-2.dll.txt.h
	dumppe avformat-53.dll >avformat-53.dll.txt.h
	dumppe avutil-51.dll >avutil-51.dll.txt.h
	dumppe postproc-51.dll >postproc-51.dll.txt.h
	dumppe swresample-0.dll >swresample-0.dll.txt.h
	dumppe swscale-2.dll >swscale-2.dll.txt.h
	dumppe avcodec-53.dll >avcodec-53.dll.txt.h	

id:
	unc77.bat libav.c
	unc77.bat libav_video.c
	unc77.bat playlist.c

amanda_clean:
	-@rm *.???~ >nulo 2>nulo
	-@rm *.unc-backup~	>nulo 2>nulo
	-@rm *.?~ >nulo 2>nulo

/bw_tmp/interface2/libav.o: libav.c libav_video.c ../mp3_dll/mv_from_be.h AV_SAMPLE_FMT_U8P_k_p.c AV_SAMPLE_FMT_S16P_k_p.c AV_SAMPLE_FMT_S32P_k_p.c AV_SAMPLE_FMT_FLTP_k_p.c AV_SAMPLE_FMT_DBL_k_p.c AV_SAMPLE_FMT_S64P_k_p.c AV_SAMPLE_FMT_U8_k_p.c AV_SAMPLE_FMT_S16_k_p.c AV_SAMPLE_FMT_S32_k_p.c AV_SAMPLE_FMT_S64_k_p.c AV_SAMPLE_FMT_FLT_k_p.c AV_SAMPLE_FMT_DBLP_k_p.c ../morcego/be_constants.h

	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/interface2/libav.o libav.c $(AMANDA_FLAGS__) -DMINHA_AMANDA_
	
/bw_tmp/interface2/libav_video.o: libav_video.c libav.c ../mp3_dll/mv_from_be.h playlist.c ../morcego/be_constants.h

	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/interface2/libav_video.o libav_video.c $(AMANDA_FLAGS__) -DMINHA_AMANDA_
	
/bw_tmp/interface2/amandaricardo_koci_dprintf.o : amandaricardo_koci_dprintf.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/interface2/amandaricardo_koci_dprintf.o amandaricardo_koci_dprintf.c $(AMANDA_FLAGS__)

feline_test:
	x86_64-w64-mingw32-gcc.exe -c -o maria.exe amanda_and_ricardo_test.c $(AMANDA_FLAGS__)
	
/bw_tmp/amandaricardo_mvbuild26_33.exe: /aoprojeto/mp3_dll/smartape.c
	make_amanda_kp.exe smartape -C '/aoprojeto/mp3_dll/'
