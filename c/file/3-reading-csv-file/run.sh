rm bin -R -f
mkdir bin
gcc main.c -o bin/output -I ../include
cd bin
./output