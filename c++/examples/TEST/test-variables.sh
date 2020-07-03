#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Variables"
    echo "CHOICES: 1, 2, 3;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES variables >& /dev/null
cd $tmp

case $1 in 
    1)
        ../variables float=1e37 integer=38 string='frank-rene schaefer' vector='08.15 sourceforge 42' string=bonjorno
        ;;

    2)
        ../variables float=3.14 integer=1970 string='frank-rene schaefer' vector='08.15 sourceforge 42'
        ;;

    3)
        ../variables float=1e37 integer=1968 string='sonderbar' vector='08.15 sourceforge 42'
        ;;
esac
