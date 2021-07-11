#!/bin/bash

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\Albatros_RSPgzip_rspgzip2_k\files\gzip2_sample\bin\x86\Release\src\source code'



if [ "clean_my_love" == "$1" ] 
then

rm *.o
rm *.a
rm *unc-backup*
exit

fi


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
echo my love..., arguments can be \"compile32\" or \"compile64\" or \"id\" \"file\" or \"clean_my_love\", a kiss and be happy...
exit
fi