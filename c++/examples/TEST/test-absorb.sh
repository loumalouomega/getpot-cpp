#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Combining GetPot Objects - Absorbtion"
    echo "CHOICES: 1, 2;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES absorb >& /dev/null
cd $tmp

case $1 in 
1)
    echo "../absorb --directory ../"
    ../absorb --directory ../
    ;;
2)
    echo "../absorb --directory ../ bubu=6711 --I12"
    ../absorb --directory ../ bubu=6711 --I12
    ;;
esac
