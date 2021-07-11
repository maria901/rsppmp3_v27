#!/bin/bash

cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\amandaricardo_koci_rsppmp3_64_bits\rsppmp3 sources\win64\mp3dll\mp3dll\bin\Release\src\c_project\morcego_libav\libav_interface_new'

if [ "compile" == "$1" ] 
then
make_amanda_kp amandaricardo_valquiria -f 'makefile'
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


if [ "" == "$1" ] 
then
echo
echo my love..., arguments can be \"compile\" or "id" or \"id78\" \"file\" or  \"backup_scripts\" para salvar os arquivos .sh em E:, a kiss and be happy...
exit
fi


if [ "backup_scripts" == "$1" ] 
then
echo

cd 'C:\AMANDA AVA Pereira\nossos_scripts_k'
cp --preserve=timestamps * 'D:\amanda_e_ricardo_para_sempre\shell scripts'
cp --preserve=timestamps * 'D:\amanda_e_ricardo_para_sempre\shell scripts_kp'

cd 'D:\musicas\'

cp *.jun 'D:\amanda_e_ricardo_para_sempre\shell scripts_kp\'

cd 'C:\Users\User\AppData\Roaming'

cp --preserve=timestamps .emacs 'D:\amanda_e_ricardo_para_sempre\shell scripts_kp\'

cd 'C:\cygwin64_amandaricardo_koci_10.2.0\home\User'

cp --preserve=timestamps .minttyrc 'D:\amanda_e_ricardo_para_sempre\shell scripts_kp\.minttyrc_10.2.0'

#cd 'C:\valquiria\cygwin64\home\AAKP'
cd 'C:\cygwin64_6.3.0\home\User'

cp --preserve=timestamps .minttyrc 'D:\amanda_e_ricardo_para_sempre\shell scripts_kp\.minttyrc_6.4.0'

echo scripts copiados para    \'D:\\amanda_e_ricardo_para_sempre\\shell scripts_kp\'
echo 
exit
fi
