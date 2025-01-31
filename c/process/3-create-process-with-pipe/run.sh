rm bin -R -f
mkdir bin
gcc logger.c -o bin/logger -I ../include
gcc main.c -o bin/output -I ../include
cd bin
./output