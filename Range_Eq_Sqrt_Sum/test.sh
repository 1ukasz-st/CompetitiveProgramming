#!/bin/bash

nt=5000

for ((i=2;i<=$nt;i++)); do
    echo "1" >> ./file.txt
    echo "$i" >> ./file.txt
    out=$(./wzo < ./file.txt)
    if [[ $out == *BAD* ]]; then
        echo "BAD $i"
        break
    fi
    rm ./file.txt
done

if [[ $i == $(($nt+1)) ]]; then
    echo "All good."
fi