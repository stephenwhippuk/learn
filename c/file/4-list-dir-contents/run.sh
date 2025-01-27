rm bin -R -f
mkdir bin
gcc main.c contentreader.c -o bin/output -I ../include
cd bin
./output