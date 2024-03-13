#!/bin/bash
./wzo < test.txt
if [[ $? -ne 0 ]]; then
    g++ ./wzo.cpp -o ./wzo -O3 -std=c++17
    ./wzo < ./test.txt
fi