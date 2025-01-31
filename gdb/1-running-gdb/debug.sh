rm bin -R -f
mkdir bin
gcc main.c -o bin/output -g
cd bin
gdb output