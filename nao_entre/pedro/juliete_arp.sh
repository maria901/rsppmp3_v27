#!/bin/bash

cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\impxmlv2_rspini\rspini_ou_impxmlv2\libxml2\libxml2-2.9.10\win32\VC10\'



if [ "compile32iconv" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\impxmlv2_rspini\rspini_ou_impxmlv2\libxml2\libiconv-1.16\src'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32charset" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\impxmlv2_rspini\rspini_ou_impxmlv2\libxml2\libiconv-1.16\libcharset\lib'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32lib" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\impxmlv2_rspini\rspini_ou_impxmlv2\libxml2\libiconv-1.16\lib'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32srclib" == "$1" ] 
then
cd 'C:\AMANDA AVA KOCI PEREIRA\nosso_trabalho\amanda_projects\impxmlv2_rspini\rspini_ou_impxmlv2\libxml2\libiconv-1.16\srclib\'
make_amanda_kp amanda_32 -f 'makefile'
exit

fi

if [ "compile32" == "$1" ] 
then

make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32clean" == "$1" ] 
then

rm *.o
exit

fi


if [ "compile32run" == "$1" ] 
then

./test_arp.exe my_amanda_xml.xml
exit

fi


if [ "compile32run2" == "$1" ] 
then
#uncgnu.bat xml_arp_v3.c
./test_arp.exe writer1.filename.xml
exit

fi


if [ "idgnu" == "$1" ] 
then
uncgnu.bat "$2"
#unc77.bat "$2"
exit

fi


echo options are compile32