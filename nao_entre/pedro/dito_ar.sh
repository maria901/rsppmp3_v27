#!/bin/bash

cd 'C:\Ava\back\tar_1_32_new_src_use_este\tar-latest\tar-1.32\src'



if [ "ar_makefile" == "$1" ] 
then

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Lenice_makefile_forge_kp'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi

if [ "compile_ar_xz" == "$1" ] 
then

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Luis_rspadv_kp\XZ_project\lzma\bin\Release\xz_src'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi

if [ "compilegnu" == "$1" ] 
then

cd 'C:\Ava\back\tar_1_32_new_src_use_este\tar-latest\tar-1.32\gnu'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compilegnu_v2" == "$1" ] 
then

cd 'C:\Ava\back\tar_1_32_new_src_use_este\tar-latest\tar-1.32\gnu'
make_amanda_kp amanda_32 -f 'makefile_amanda2'
exit

fi


if [ "compile133" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "amanda_27" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k'
make_amanda_kp amanda_27 -f 'makefile'
exit

fi


if [ "compile133r" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k'
./tar_k.exe "$2"
exit

fi


if [ "idricardo" == "$1" ] 
then

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k'

unc78.bat tar_1_33.c

echo 
echo for your pleasure...
exit
fi


if [ "idricardo_v2" == "$1" ] 
then

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k'

unc78.bat "$2"

echo 
echo for your pleasure...
exit
fi


if [ "compile32" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\examples'
make amanda_32 -f 'makefile'
exit
fi


if [ "compile32enc" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\src\enc'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32io" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\imageio'
make amanda_32 -f 'makefile'
exit

fi


if [ "compile32png" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libpng_do_cara_ar\libpng-1.6.37'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32dec" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\src\dec'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi



if [ "compile32demux" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\src\demux'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi



if [ "compile32dsp" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\src\dsp'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi




if [ "compile32util" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\src\utils'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi




if [ "clean_ar_enc" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\src\enc'
make_amanda_kp clean_ar_enc -f 'makefile'
exit

fi




if [ "compile64" == "$1" ] 
then

make_amanda_kp ricardo_64 -f 'makefile'
exit

fi


if [ "clean" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Luis_rspadv_kp\LZMA_project\lzma\bin\Release\C_sources'
cp makefile makefile.o
cp makefile makefile.bin
cp makefile makefile.a
rm *.o
rm *.a
#rm *.bin

#dumppe rsptargzipdll.dll

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


if [ "backup_ar" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Luis_rspadv_kp\LZMA_project\lzma\bin\Release\C_sources'
cp -r * 'E:\backup_advanced\'
echo 
echo for your pleasure...
exit
fi


if [ "id" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\examples'
unc77.bat "$2"
echo 
echo for your pleasure...
exit
fi

if [ "id78" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\project picasso\Google_sources_of_webp_ar\libwebp\examples'
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
cd 'C:\Ava\back\tar_sources_para_cygwin\tar-latest\tar-1.32\src'
# para criar um arquivo ./tar.exe -cvf output_k.tar tar.exe

./tar.exe -xvf output_k.tar -C ./koci

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