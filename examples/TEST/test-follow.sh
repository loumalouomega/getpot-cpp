#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Follow Arguments: Any;"
    echo "CHOICES: 1, 2;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES follow >& /dev/null
cd $tmp

case $1 in 
    1)
        echo "../follow --alpha 3.14 --beta 0.815 --size -1 1 --user arnold.nyme 32141 --user ruth.chelle"
        ../follow --alpha 3.14 --beta 0.815 --size -1 1 --user arnold.nyme 32141 --user ruth.chelle
        ;;
    2)
        echo "../follow --alpha 3.14 --beta 0.815 --size -1 1 --user arnold.nyme -32141 --user ruth.chelle 3"
        ../follow --alpha 3.14 --beta 4711 --size -1 1 --user arnold.nyme -32141 --user ruth.chelle 3
        ;;
esac
