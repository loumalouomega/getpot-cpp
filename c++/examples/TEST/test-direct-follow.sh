#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Directly Followed Arguments: Iteration"
    echo "CHOICES: 1, 2, 3, 4, 5;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES direct_follow >& /dev/null
cd $tmp
case $1 in

1)
    echo "../direct_follow -Uss"
    ../direct_follow -Uss
    ;;
2)
    echo "../direct_follow --help"
    ../direct_follow --help
    ;;
3)
    echo "../direct_follow -Ududu -Uim -V12 -URadio"
    ../direct_follow -Ududu -Uim -V12 -URadio
    ;;
4)
    echo "../direct_follow -Ududu -Uim -V12 -URadio -V13"
    ../direct_follow -Ududu -Uim -V12 -URadio -V13
    ;;
5)
    echo "../direct_follow -Ududu -Uim -V12 -URadio -V13 -N12 -BOOLtrue"
    ../direct_follow -Ududu -Uim -V12 -URadio -V13 -N12 -BOOLtrue
    ;;

esac
