#!/bin/bash
# Compress an entire directory by running tar -zcvf file. tar. gz /path/to/dir/ command in Linux.
dt=$(date '+%d-%m-%Y_%H-%M-%S');

if [ "" == "$1" ] 
then
echo My love, the tar.gzip file is missing, ok, kisses...
exit
fi

if [ "" == "$2" ] 
then
echo Dear, the destination path that you forgot, ok, hugs...
exit
fi

echo
echo
echo
echo
echo
echo As you wish...
echo
echo
echo I love you...
echo
echo
#echo " s1 " "$1"
#echo " s2 " "$2"
mkdir """$2""" >/dev/null 2>/dev/null
tar -xvzf """$1""" -C """$2"""

echo
echo
echo
echo
echo
