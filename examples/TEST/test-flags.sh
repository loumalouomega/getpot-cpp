#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Flags"
    echo "CHOICES: 1, 2;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES flags >& /dev/null
cd $tmp

case $1 in

    1)
        echo "../flags osterix"
        ../flags osterix
        ;;

    2)
        echo "../flags osterix -hamburg"
        ../flags osterix -hamburg
        ;;

esac
