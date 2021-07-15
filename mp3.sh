#viu...


if [ "junior" == "$1" ] 
then

make_amanda_kp amandaricardo_valquiria -f 'makefile' -C mp3_dll

exit
fi


if [ "compileclean" == "$1" ] 
then

make_amanda_kp clean_k_p -f 'makefile' -C mp3_dll

exit
fi


if [ "id" == "$1" ] 
then
unc77.bat "$2"
echo 
echo for your pleasure...
exit
fi


if [ "smartape" == "$1" ] 
then

make_amanda_kp smartape -f 'makefile' -C mp3_dll

exit
fi


echo 'Errou amor...'