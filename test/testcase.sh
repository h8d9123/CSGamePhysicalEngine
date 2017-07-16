#!/bin/bash
clear
clear
echo "-------------------------------------------------------------------------"
echo "building...."
cd ..
./build.sh
cd ./test
echo " ------------------------------------------------------------------------"
echo
echo test $1
g++ $1 -L../src/libs -I../src/math -lcppunit -ldl -lphymath -o a.out
chmod +x a.out
./a.out
