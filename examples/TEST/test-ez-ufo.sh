#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "UFO-Detection: Easy"
    echo "CHOICES: 1, 2, 3, 4;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES ez-ufo >& /dev/null
cd $tmp

case $1 in

    1)
        echo "../ez-ufo yes no -i source.cpp --arguments"
        ../ez-ufo yes no -i source.cpp --arguments
        ;;

    2)
        echo "../ez-ufo zfd x=12 y=234 loength=21 height=21 n=2 --variables"
        ../ez-ufo zfd x=12 y=234 loength=21 height=21 n=2 --variables
        ;;
    3)
        echo "../ez-ufo yes no -i source.cpp --nominuses -o out.o gogo"
        ../ez-ufo yes no -i source.cpp --nominuses -o out.o gogo
        ;;

    4)
        echo "../ez-ufo n=21 -i in.dat -o out.dat /etc/fstab force --nominuses"
        ../ez-ufo n=21 -i in.dat -o out.dat /etc/fstab force --nominuses
        ;;

esac
