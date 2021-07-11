#!/bin/bash

cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\Zstandard_source_code\zstd-1.4.8\build\VS2010'


if [ "compile32_148" == "$1" ] 
then

#unc78gnu.bat ../../programs/zstdcli.c
#unc78.bat ../../programs/zstdcli.c

#unc78.bat ../../programs/amandaricardo_koci_dprintf.c

Amanda_Compress_v27.exe 'tar_sample_ar'

Amanda_Compress_v27.exe 'tar_sample_ar_x64'

make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32_149" == "$1" ] 
then

cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\Zstandard_source_code\zstd-1.4.9\build\VS2010'

Amanda_Compress_v27.exe 'tar_sample_ar'

Amanda_Compress_v27.exe 'tar_sample_ar_x64'

make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "arp_run" == "$1" ] 
then

#./test_arp.exe -h

make_amanda_kp run_arp -f 'makefile'

#./test_arp.exe -f ./test_arp.exe -o ./test_arp.zst
#./test_arp.exe -f -d ./test_arp.zst -o ./test_arp.out

exit

fi


if [ "compile32idclean" == "$1" ] 
then

rm *unc-backup*
exit

fi


if [ "compile64_148" == "$1" ] 
then

Amanda_Compress_v27.exe 'tar_sample_ar'

Amanda_Compress_v27.exe 'tar_sample_ar_x64'

make_amanda_kp ricardo_64 -f 'makefile'
exit

fi


if [ "clean" == "$1" ] 
then

make_amanda_kp clean_ar -f 'makefile'
exit

fi


if [ "compile32xz" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\xz_source_code\xz-5.2.5\'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32compress" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\compress_source_code\ncompress-4.2.4.6\'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32lzop" == "$1" ] 
then
cd 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_1_33_k/lzop_source_code/lzop-1.04/'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32lzopclean" == "$1" ] 
then
cd 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_1_33_k/lzop_source_code/lzop-1.04/src'
rm *.o
exit

fi


if [ "compile32lzoprun" == "$1" ] 
then
cd 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_1_33_k/lzop_source_code/lzop-1.04/'
./lzop_kkkkkkk.exe -9 -f -o makefile.lzo makefile
./lzop_kkkkkkk.exe -d -f -o makefile.2.out makefile.lzo
exit

fi


if [ "compile32compressclean" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\compress_source_code\ncompress-4.2.4.6\'
cp makeFILE makeFile.o
cp makeFIle makeFile.unc-backup.out
rm *.o
rm *unc-backup*
exit

fi


if [ "compile32compressrun" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\compress_source_code\ncompress-4.2.4.6\'
./test_ar.exe
exit

fi


if [ "compile32compressidold" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\compress_source_code\ncompress-4.2.4.6/'
unc77.bat "$2"
exit

fi


if [ "compile32compressid" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\compress_source_code\ncompress-4.2.4.6/'
unc78.bat "$2"
exit

fi


if [ "compile32xzclean" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\xz_source_code\xz-5.2.5\'
cp makefile makefile.a
cp makefile makefile.o
cp makefile makefile.unc-backup.out
rm *.o
rm *.a
rm *unc-backup*
exit

fi


if [ "compile32xzid" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\xz_source_code\xz-5.2.5\'
unc77.bat "$2"
exit

fi


if [ "compile32gzip" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\gzip_source_code\'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32bzip2" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\bzip2_source_code\'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32bzip264" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\bzip2_source_code\'
make_amanda_kp ricardo_64 -f 'makefile'
exit

fi


if [ "compile32gzip64" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\gzip_source_code\'
make_amanda_kp ricardo_64 -f 'makefile'
exit

fi


if [ "idamanda" == "$1" ] 
then
unc77.bat new_untgz_k.c


gcc -O3 -o test_k_k.exe test_k_k.c
./test_k_k.exe

echo 
echo for your pleasure...
exit
fi


if [ "compile32lzip" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code_original\lzlib-1.12-rc4\'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi




if [ "compile32lzmaidold" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzma_source_code\LZMA_sdk_c_19.00_2019_02_21/'
unc77.bat "$2"
exit

fi



if [ "compile32lzma" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzma_source_code\LZMA_sdk_c_19.00_2019_02_21/'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi

if [ "compile32lzmaclean" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzma_source_code\LZMA_sdk_c_19.00_2019_02_21/'
rm *.o
exit

fi


if [ "idlzip" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code_original\lzlib-1.12-rc4\'
unc78.bat "$2"
exit

fi


if [ "idlzip77" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code_original\lzlib-1.12-rc4\'
unc77.bat "$2"
exit

fi


if [ "idlzipgnu" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code_original\lzlib-1.12-rc4\'
uncgnu.bat "$2"
exit

fi


if [ "compile32lziptest" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code_original\lzlib-1.12-rc4\'
make_amanda_kp ricardo_64 -f 'makefile'
exit

fi



if [ "compile32lziprun" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code_original\lzlib-1.12-rc4\'
make_amanda_kp maria_48 -f 'makefile'
exit

fi


if [ "compile32lziplib" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code_original\lzlib-1.12-rc4\'
make_amanda_kp -f 'Makefile_to_compile_rspk'
exit

fi




if [ "compile32lzipcreate" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code\lzlib-1.12-rc4\'
ar_makefile.exe create
exit

fi


if [ "compile32lzipprocess" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code\lzlib-1.12-rc4\'
ar_makefile.exe
exit

fi


if [ "compile32lzipclean" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\lzip_source_code_original\lzlib-1.12-rc4\'
rm *.o
exit

fi


if [ "backup_ar" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Luis_rspadv_kp\LZMA_project\lzma\bin\Release\C_sources'
cp -r * 'E:\backup_advanced\'
echo 
echo for your pleasure...
exit
fi


if [ "id" == "$1" ] 
then
unc77.bat "$2"
echo 
echo for your pleasure...
exit
fi

if [ "id78" == "$1" ] 
then
unc78.bat "$2"
echo 
echo for your pleasure...
exit
fi


if [ "touch" == "$1" ] 
then
touch "$2"
echo 
echo for your pleasure...
exit
fi


if [ "run_tar_k" == "$1" ] 
then
cd '/cygdrive/c/Ava/back/'
# para criar um arquivo ./tar.exe -cvf output_k.tar tar.exe

#./tar.exe -xvf output_k.tar -C ./koci

tar.exe --format=pax -cvf output_pax_k.tar extract_k

#touch "$2"
echo 
echo for your pleasure...
exit
fi


if [ "" == "$1" ] 
then
echo
echo my love..., arguments can be \"compile32\" or \"compile64\" or \"touch\" \"file\" or "id" or \"id78\" \"file\" or \"clean\", a kiss and be happy...
exit
fi