#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "UFO-Detection: User Specified Arguments"
    echo "CHOICES: 1, 2, 3, 4, 5, 6;"
    exit
fi

tmp=`pwd`
cd ..; make SEPERATE_OBJ=YES ufo >& /dev/null
cd $tmp

case $1 in

    1)
        echo "../ufo yes no -i source.cpp --arguments"
        ../ufo yes no -i source.cpp --arguments
        ;;

    2)
        echo "../ufo -i source.cpp --force n=13 -xzt --options"
        ../ufo -i source.cpp --force n=13 -xzt --options
        ;;

    3)
        echo "../ufo zfd if=source.cpp force n=13 -l -zrt -olp --flags"
        ../ufo zfd if=source.cpp force n=13 -l -zrt -olp --flags
        ;;

    4)
        echo "../ufo zfd x=12 y=234 loength=21 height=21 n=2 --variables"
        ../ufo zfd x=12 y=234 loength=21 height=21 n=2 --variables
        ;;

    5)
        # (edit file section labels in example.pot)
        echo "../ufo --sections --input-file ../example.pot"
        ../ufo --sections --input-file ../example.pot
        ;;

    6)
        echo "../ufo n=21 -i in.dat -o out.dat /etc/fstab force --nominuses "
        ../ufo n=21 -i in.dat -o out.dat /etc/fstab force --nominuses 
        ;;
esac
