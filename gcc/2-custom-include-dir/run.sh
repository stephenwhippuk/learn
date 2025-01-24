echo 'creating build structure'
rm build -R -f
mkdir build
echo 'compiling'
gcc main.c -o build/main -I ./custom
./build/main