# this wont reate the bin filder which is managed by setup
gcc main.c delete.c -o bin/output -I ../include
cd bin
./output