#!/bin/bash

cd '/cygdrive/c/arab_cd/hack_dll'

if [ "" == "$1" ] 
then
echo My love, missing the argument to make..., to see all the makefile options call it with 'cat', now exiting for your pleasure
exit
fi


if [ "cat" == "$1" ] 
then
cat amanda_makefile
exit
fi
echo make_amanda_kp "$1" -f 'amanda_makefile'
make_amanda_kp "$1" -f 'amanda_makefile'