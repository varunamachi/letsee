#!/bin/bash

gcc -O3 letsee.cpp -lstdc++ -std=c++17 -o letsee.exe || exit -3
./letsee.exe $@
