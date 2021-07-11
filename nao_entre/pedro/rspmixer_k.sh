#!/bin/bash

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Mauricio_rspmixer_k\files_k\mixer\bin\x86\Release\src\mixer_c_source_code_k'


if [ "compile32" == "$1" ] 
then

    make_amanda_kp amanda_32 -f 'makefile'

#dumppe64 -v rspmixer.dll
    
exit

fi

if [ "compile64" == "$1" ] 
then

make_amanda_kp ricardo_64 -f 'makefile'
exit

fi


if [ "clean" == "$1" ] 
then
cp makefile makefile.o
cp makefile makefile.a
rm *.o
rm *.a
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


if [ "K" = "$1" ] 
then
echo
echo ok, as you wish...

#mkdir 'E:\FOTOS_k'

cd 'E:\'

cd 'C:\Amanda Ava Pereira\FOTOS'
oi_K="$?"

if [ "0" != "$oi_K" ] 
then
echo 'Diretorio fotos no drive C não existe, saindo...'
exit
fi

cp --preserve=timestamps * 'E:\FOTOS_k'





cd 'C:\Users\AAKP\Desktop\Amanda & Ricardo\ar_koci_icones'
oi_K="$?"

if [ "0" != "$oi_K" ] 
then
echo 'Diretorio icones no drive C não existe, saindo...'
exit
fi

cp --preserve=timestamps * 'E:\FOTOS_k'






echo .
echo Copiou amor...
echo .

exit
fi


if [ "" == "$1" ] 
then
echo
echo my love..., arguments can be \"compile32\" or \"compile64\" or \"touch\" \"file\" or "id" or \"id78\" \"file\" or \"clean\", a kiss and be happy...
exit
fi

