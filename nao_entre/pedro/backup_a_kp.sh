#!/bin/bash

cd '/cygdrive/c/Ava/backdebug_me'


if [ "" == "$1" ] 
then

echo My love the arguments can be \'completo\' ou \'sources\' ou \'diretorio locacao\' == \'27\' ou \'completo_gui\'

exit

fi


if [ "completo" == "$1" ] 
then


make_amanda_kp amandaricardo_koci -f 'makefile_amandaricardo_koci_arab_cd_projeto_locacao_GLOBAL'

exit

fi


if [ "sources" == "$1" ] 
then

cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Chico_backup_system_bw_arp\BE_backup_v27\tar_sample_ar\bin\Release'
./BE_backup_v27.exe                            'E:\amanda_e_ricardo_para_sempre\amandaricardo_koci_arab_cd_locacao_antigo_e_novo_te_amo\locacao_diaria_latest_arp.val.lzma'            'C:\Ava\backdebug_me\amandaricardo_decompilation_v4'                                                                                                      'true'                                                                                                                                                    '*.cc *.cpp *.c *.h *makefile* *.txt *.ico *.ini *.rc *.def *.sln *.cs *.resx *.csproj *.config' 'val.lzma' 'E:\amanda_e_ricardo_para_sempre\amandaricardo_koci_arab_cd_locacao_antigo_e_novo_te_amo\amandaricardo_koci_arab_cd_locacao_antigo_e_novo_te_amo_only_sources_new_arp'                                                                                                                                                    'true'

exit

fi


if [ "completo_gui" == "$1" ] 
then

cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Chico_backup_system_bw_arp\BE_backup_v27\tar_sample_ar\bin\Release'
./BE_backup_v27.exe                            'E:\amanda_e_ricardo_para_sempre\amandaricardo_koci_arab_cd_locacao_antigo_e_novo_te_amo\locacao_diaria_latest_arp.val.lzma'            'C:\Ava\backdebug_me\amandaricardo_decompilation_v4'                                                                                                      'true'                                                                                                                                                     '*' 'val.lzma'  'E:\amanda_e_ricardo_para_sempre\amandaricardo_koci_arab_cd_locacao_antigo_e_novo_te_amo\amandaricardo_koci_arab_cd_locacao_antigo_e_novo_te_amo_complete_arp'                                                                                                                                                    'true'

exit

fi


if [ "27" == "$1" ] 
then
cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Chico_backup_system_bw_arp\BE_backup_v27\tar_sample_ar\bin\Release'
./BE_backup_v27.exe 'E:\amanda_e_ricardo_para_sempre\Locacao Diaria Diretorio\locacao_diaria_diretorio_arp.val.lzma' 'C:\Ava\Locacao De Temporada 2.0.0 arab' 'false' '*' 'val.lzma' 'E:\amanda_e_ricardo_para_sempre\Locacao Diaria Diretorio\Locacao Diaria Diretorio_arp' 'true'

exit

fi