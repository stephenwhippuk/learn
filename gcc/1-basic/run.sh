echo 'creating build structure'
rm build -R -f
mkdir build
gcc main.c -o build/hello
./build/hello
