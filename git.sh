#viu...


if [ "juliete" == "$1" ] 
then

cd /aoprojeto
oi="$?"
#echo $oi
if [ "0" != "$oi" ] 
then
echo "Erro 10"
exit
fi

cp --preserve=timestamps -r * /cygdrive/c/Ava/ricardinho/rsppmp3_v27
oi="$?"
#echo $oi
if [ "0" != "$oi" ] 
then
echo "Erro 20"
exit
fi

cd /cygdrive/c/Ava/ricardinho/rsppmp3_v27
oi="$?"
#echo $oi
if [ "0" != "$oi" ] 
then
echo "Erro 30"
exit
fi


cd /cygdrive/c/Ava/ricardinho/rsppmp3_v27
oi="$?"
#echo $oi
if [ "0" != "$oi" ] 
then
echo "Erro 40"
exit
fi

git add --all
oi="$?"
#echo $oi
if [ "0" != "$oi" ] 
then
echo "Erro 50"
exit
fi

git commit
oi="$?"
#echo $oi
if [ "0" != "$oi" ] 
then
echo "Erro 60"
exit
fi

git push
oi="$?"
#echo $oi
if [ "0" != "$oi" ] 
then
echo "Erro 70"
exit
fi

echo 'Feito amor...'

exit
fi

echo 'Errou amor...'