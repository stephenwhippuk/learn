echo compiling application
rm bin -R -f
mkdir bin
cd lib
./build.sh
cd ..
gcc main.c  -L lib/bin -l mylib -o bin/hello
echo executing application ... 
cd bin
./hello

