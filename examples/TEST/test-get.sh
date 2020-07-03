#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "GetPot 'get' - function group"
    echo "CHOICES: 0, 1, 2, 3, 4, 5, 6;"
    exit
fi


tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES get >& /dev/null
cd $tmp

case $1 in
    0)
        echo "../get"
        ../get
        ;;
    1)
        echo "../get 1"
        ../get 1
        ;;
    2)
        echo "../get 1 2"
        ../get 1 2
        ;;
    3)
        echo "../get 1 2 5"
        ../get 1 2 5
        ;;
    4)
        echo "../get 1 2 5 6"
        ../get 1 2 5 6
        ;;
    5)
        echo "../get 1 2 5 6 2"
        ../get 1 2 5 6 2
        ;;
    6)
        echo "../get hallo liebe Leute hallo guten tag 2 3 4"
        ../get hallo liebe Leute hallo guten tag 2 3 4
        ;;
esac
