#!/bin/bash

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\RSP_Any_Enc_k\src\ffmpef_frontend\bin\x86\Release\src'


if [ "compile32" == "$1" ] 
then

make_amanda_kp amanda_32 -f 'makefile'
exit

fi

if [ "compile64" == "$1" ] 
then

make_amanda_kp ricardo_64 -f 'makefile'
exit

fi


if [ "clean" == "$1" ] 
then

rm *.o
exit

fi


if [ "id" == "$1" ] 
then
unc77.bat "$2"
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


if [ "test" == "$1" ] 
then

cp 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\RSP_Any_Enc_k\src\ffmpef_frontend\bin\Release\ffmpef_frontend.exe' 'C:\Ava\back\media test\debug_k\ffmpef_frontend.exe'

cp 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\RSP_Any_Enc_k\src\ffmpef_frontend\bin\Release\ffmpef_frontend.exe' 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\RSP_Any_Enc_k\ffmpef_frontend.exe'

cd 'C:\Ava\back\media test\debug_k'
./ffmpef_frontend.exe

echo 
echo for your pleasure...
exit
fi



if [ "codecs" == "$1" ] 
then

cd 'C:\Ava\back\media test\debug_k'
./ffmpeg -codecs >codecs_k.ava

echo 
echo for your pleasure...
exit
fi


if [ "formats" == "$1" ] 
then

cd 'C:\Ava\back\media test\debug_k'
./ffmpeg -formats >formats.ava

echo 
echo for your pleasure...
exit
fi


if [ "encoders" == "$1" ] 
then

cd 'C:\Ava\back\media test\debug_k'
./ffmpeg -encoders >encoders.ava

echo 
echo for your pleasure...
exit
fi


if [ "codecs_k" == "$1" ] 
then

make_amanda_kp codecs_k -f 'makefile'

echo 
echo for your pleasure...
exit
fi


if [ "formats_k" == "$1" ] 
then

make_amanda_kp formats_k -f 'makefile'

echo 
echo for your pleasure...
exit
fi


if [ "encoders_k" == "$1" ] 
then

make_amanda_kp encoders_k -f 'makefile'

echo 
echo for your pleasure...
exit
fi


if [ "" == "$1" ] 
then
echo
echo my love..., arguments can be \"encoders_k\" or \"codecs_k\" or \"formats_k\" or \"compile32\" or \"compile64\" or \"codecs\" or \"formats\" or \"encoders\" or \"touch\" \"file\" or "id" \"file\" or \"clean\" or \"test\", a kiss and be happy...
exit
fi