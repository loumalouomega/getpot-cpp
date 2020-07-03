#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Next Argument"
    echo "CHOICES: 1, 2, 3;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES next >& /dev/null
cd $tmp

case $1 in
    1)
        echo "../next 0.1 123.4 'hallo welt' 21"
        ../next 0.1 123.4 'hallo welt' 21
        ;;
    2)
        echo "../next 'hallo welt' gugu 47.1 logo"
        ../next 'hallo welt' gugu 47.1 logo
        ;;
    3)
        echo "../next 0.000009 0.000009 12 65535 df aee ff 123 000d '\n'"
        ../next 0.000009 0.000009 12 65535 df aee ff 123 000d '\n'
        ;;
esac
