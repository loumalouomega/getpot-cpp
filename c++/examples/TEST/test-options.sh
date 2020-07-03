#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Options (Arguments Starting with '-')"
    echo "CHOICES: 1, 2, 3;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES options >& /dev/null
cd $tmp

case $1 in

    1)
        echo "../options --nice beep neep --slice --senal-acustica"
        ../options --nice beep neep --slice --senal-acustica
        ;;

    2)
        echo "../options --nice beep neep --slice --senal-acustica --do-nothing"
        ../options --nice beep neep --slice --senal-acustica --do-nothing
        ;;

    3)
        echo "../options beep neep --slice --senal-acustica"
        ../options beep neep --slice --senal-acustica
        ;;
esac

