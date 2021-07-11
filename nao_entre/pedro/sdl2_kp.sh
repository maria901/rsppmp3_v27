#!/bin/bash

echo primeiro tem que extrair 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\amandaricardo_koci_rsppmp3_64_bits\rsppmp3 sources\win64\mp3dll\mp3dll\bin\Release\src\c_project\modified_SDL_2.0.12\modified_SDL_2.0.12.7z'

exit

cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\amandaricardo_koci_rsppmp3_64_bits\rsppmp3 sources\win64\mp3dll\mp3dll\bin\Release\src\c_project\modified_SDL_2.0.12\VisualC\SDL'


if [ "compile" == "$1" ] 
then

make_amanda_kp ar_kp -f 'makefile'
exit

fi


if [ "clean" == "$1" ] 
then

rm *.o
make_amanda_kp ar_kp -f 'makefile'
exit

fi


if [ "id" == "$1" ] 
then
unc77.bat "$2"
echo 
echo for your pleasure...
exit
fi


if [ "" == "$1" ] 
then
echo
echo my love..., arguments can be \"compile\" or "id" \"file\" or \"clean\", a kiss and be happy...
exit
fi