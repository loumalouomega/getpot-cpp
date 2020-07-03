#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Field Separator in Array Arguments"
    echo "CHOICES: 1, 2;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES field_separator >& /dev/null
cd $tmp

case $1 in 

    1)
        echo "../field_separator fs='.' test='129. 11. 32.  5'"
        ../field_separator fs='.' test='129. 11. 32.  5'
        ;;
    2)
        echo "../field_separator fs='. ' test='129. 11. 32.  5'"
        ../field_separator fs='. ' test='129. 11. 32.  5'
        ;;
esac
