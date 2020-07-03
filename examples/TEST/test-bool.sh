#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Test the boolean type;"
    echo "CHOICES: true, false, default;"
    exit
fi


tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES bool >& /dev/null
cd $tmp

case $1 in
    true)
        ../bool vrai a=vraie b=vraie -Cvrai -d vraie vraie -e vrai vrai f='0 vrai 2' i=vrai j=vraie
        ;;
    false)
        ../bool faux a=fausse b=fausse -Cfaux -d fausse fausse -e faux faux f='0 faux 2' i=faux j=fausse
        ;;
    default)
        ../bool
        ;;
esac
