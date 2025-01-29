#! /usr/bin/sh

# This should be run first and thus will thus manage the bin folder
rm bin -R -f
mkdir bin
gcc setup.c -o bin/setup -I ../include
cd bin
./setup