#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Input File Parsing: Macro Expansion (Dollar Brackets)"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES expand >& /dev/null
cd $tmp

echo "../expand --directory ../"
../expand --directory ../

