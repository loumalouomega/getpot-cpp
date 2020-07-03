#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Nominus Arguments;"
    echo "CHOICES: 1, 2;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES nominus >& /dev/null
cd $tmp

case $1 in 
    1)
        ../nominus sss ddd fff
        ;;

    2)
        ../nominus -v sss -a ddd variable=12 fff
        ;;
esac
