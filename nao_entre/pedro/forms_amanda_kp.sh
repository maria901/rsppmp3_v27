#!/bin/bash

cd 'C:\Ava\backdebug_me\amandaricardo_decompilation_v4\LocaçãodeTemporada\koci_pereira_backup\koci_pereira_backup'

if [ "" == "$1" ] 
then
echo My love, missing the argument to make..., to see all the makefile options call it with 'cat', now exiting for your pleasure
exit
fi


if [ "cat" == "$1" ] 
then
cat k_p_makefile
exit
fi
echo make_amanda_kp.exe "$1" -f 'k_p_makefile'
make_amanda_kp.exe "$1" -f 'k_p_makefile'