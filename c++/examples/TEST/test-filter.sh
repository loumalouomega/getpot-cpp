#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Filter Prefixes"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES filter >& /dev/null

echo "../filter --nice"
./filter --nice

cd $tmp

