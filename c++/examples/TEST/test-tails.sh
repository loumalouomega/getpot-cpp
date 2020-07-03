#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Directly Followed Arguments: Easy, Using '*_tails()'"
    echo "CHOICES: 1, 2, 3, 4;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES tails >& /dev/null
cd $tmp

case $1 in
1)
    echo "../tails -U -Udu -Uschoene -Uwelt -V -V -V"
    ../tails -U -Udu -Uschoene -Uwelt -V -V -V
    ;;

2)
    echo "../tails -Uhallo -Udu -Uschoene -Uwelt -V1 -V2 -V3"
    ../tails -Uhallo -Udu -Uschoene -Uwelt -V1 -V2 -V3
    ;;

3)
    echo "../tails -Uhallo -Udu -Uschoene -Uwelt"
    ../tails -Uhallo -Udu -Uschoene -Uwelt
    ;;

4)
    echo "../tails -U -Udu -Uschoene -Uwelt -V -V -V -NUM3.14 -NUM1.41 -NUM"
    ../tails -U -Udu -Uschoene -Uwelt -V -V -V -NUM3.14 -NUM1.41 -NUM
    ;;
esac

