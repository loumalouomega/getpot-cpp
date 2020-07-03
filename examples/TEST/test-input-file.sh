#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Input File Parsing: Simple Example;"
    echo "CHOICES: GetPot, C, Punk, BASIC, Latex;"
    echo "SAME;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES input-file >& /dev/null
cd $tmp

../input-file --directory ../ -c $1


