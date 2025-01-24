
echo creating build structure
rm -R build -f
mkdir build
echo "Compiling main.c"
gcc main.c -c -o build/main.o
echo "Compiling print.c"
gcc print.c -c  -o build/print.o
echo "linking"
cd build
gcc main.o print.o -o output
./output
