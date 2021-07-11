#!/bin/bash

cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\amandaricardo_koci_rsppmp3_64_bits\rsppmp3 sources\win64\mp3dll\mp3dll\bin\Release\src\c_project'


if [ "compile" == "$1" ] 
then

make_amanda_kp amandaricardo_valquiria -f 'makefile'

exit
fi


if [ "compileclean" == "$1" ] 
then

make_amanda_kp clean_k_p -f 'makefile'

exit
fi


if [ "id" == "$1" ] 
then
unc77.bat "$2"
echo 
echo for your pleasure...
exit
fi


if [ "smartape" == "$1" ] 
then

make_amanda_kp smartape -f 'makefile'

exit
fi


if [ "" == "$1" ] 
then
echo
echo my love..., arguments can be \"smartape\" \"compile\" or \"compileclean\" or "id" \"file\", a kiss and be happy...for only your pleasure
exit
fi