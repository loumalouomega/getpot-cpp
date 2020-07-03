#! /usr/bin/env bash
if [[ $1 == "--hwut-info" ]]; then
    echo "Follow Arguments: Nominuses;"
    echo "CHOICES: 1, 2;"
    exit
fi

tmp=`pwd`
cd ..
make SEPERATE_OBJ=YES nominus_followers >& /dev/null
cd $tmp

case $1 in
    1)
        echo "../nominus_followers -i Vladimir Georgy Angy --nono \""
        echo "                     -o chaos mess --output --ausgabe question"
        ../nominus_followers -i Vladimir Georgy Angy --nono \
                             -o chaos mess --output --ausgabe question
        ;;
    2)
        echo "../nominus_followers -i Vladimir Georgy -oAngy"
        ../nominus_followers -i Vladimir Georgy -oAngy
        ;;
esac

