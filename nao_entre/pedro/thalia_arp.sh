#!/bin/bash

cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\impxmlv2_rspini\rspini_ou_impxmlv2\libxml2\libxml2-2.9.3'


if [ "compile32" == "$1" ] 
then

make_amanda_kp amanda_32 -f 'makefile'
exit

fi


if [ "compile32update" == "$1" ] 
then

make_amanda_kp test_update_arp -f 'makefile'
exit

fi


if [ "compile32update64" == "$1" ] 
then

make_amanda_kp test_update_arp64 -f 'makefile'
exit

fi


if [ "compile32read" == "$1" ] 
then

make_amanda_kp test_read_arp -f 'makefile'
exit

fi


if [ "compile32read64" == "$1" ] 
then

make_amanda_kp test_read_arp64 -f 'makefile'
exit

fi


if [ "compile32add" == "$1" ] 
then

make_amanda_kp test_add_arp -f 'makefile'
exit

fi


if [ "compile32add64" == "$1" ] 
then

make_amanda_kp test_add_arp64 -f 'makefile'
exit

fi


if [ "compile32del" == "$1" ] 
then

make_amanda_kp test_del_arp -f 'makefile'
exit

fi


if [ "compile32del64" == "$1" ] 
then

make_amanda_kp test_del_arp64 -f 'makefile'
exit

fi


if [ "compile32clean" == "$1" ] 
then
rm *.orig
rm *unc-backup*
rm *.o
exit

fi


if [ "compile32run" == "$1" ] 
then

#./test_arp.exe my_amanda_xml.xml
#./test_arp.exe def_arp.xml
#./test_arp.exe def_arp.xml /firewall-rules/rule/ip-destination-port/port2 ricardo
#./test_arp.exe def_arp.xml /firewall-rules/rule/ip-destination-port/@type ricardo para atributo
#./test_arp.exe def_arp.xml /firewall-rules/rule/ip-destination-port/port
./test_arp.exe def_arp.xml /firewall-rules/rule/ip-destination-port/@type

#xmlSaveFileEnc("note.xml", pDoc, "UTF-8");
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


if [ "idgnuunc" == "$1" ] 
then
unc78gnu.bat "$2"
#unc77.bat "$2"
exit

fi


if [ "id77" == "$1" ] 
then
unc77.bat "$2"
#unc77.bat "$2"
exit

fi

if [ "id78" == "$1" ] 
then
unc78.bat "$2"
#unc77.bat "$2"
exit

fi


echo options are compile32