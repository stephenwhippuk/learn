rm bin -R -f
mkdir bin
gcc hello.c -o bin/hello 
gcc main.c -o bin/output -I ../include
cd bin
./output