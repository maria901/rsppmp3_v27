#!/bin/bash

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\RSPbzip2_k\moncoes\files\bzip2\bin\x86\Release\src\sourcecode'


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
if [ "cpu" == "$1" ] 
then

make_amanda_kp cpu_detect_k -f 'makefile'
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


if [ "" == "$1" ] 
then
echo
echo my love..., arguments can be \"compile32\" or \"compile64\" or \"cpu\" "id" \"file\" or \"clean\", a kiss and be happy...
exit
fi