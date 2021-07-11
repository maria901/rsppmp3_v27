#!/bin/bash
# Compress an entire directory by running tar -zcvf file. tar. gz /path/to/dir/ command in Linux.
dt=$(date '+%Y-%m-%d_%H-%M-%S');
echo
echo
echo
echo
echo
echo As you wish...

pense=''

if [ "" == "$1" ]
then
echo "Meu bem você esqueceu o nome do teu projetinho, o uso é amanda_backup.sh <backup>"
exit
fi

if [ "" == "$2" ]
then
echo "Meu amor você esqueceu o wildcard, uso amanda_backup.sh <backup> <*> ou <?>"
exit
fi

#if [ "" == "$3" ] ?
#then
#echo "Meu bem você esqueceu o folder com os arquivinhos a serem backupeados, o uso é amanda_backup.sh <backup> <diretório destino> <diretorio source>"
#exit
#fi

	echo My love, folder created...
	echo
	echo
	echo
	echo
	echo
	mkdir "/cygdrive/e/amanda_e_ricardo_para_sempre/""$1" 21>/dev/null 11>/dev/null
	echo $2
	tar -zcvf "/cygdrive/e/amanda_e_ricardo_para_sempre/""$1""/""$1_""$dt"".tar.gz" *


