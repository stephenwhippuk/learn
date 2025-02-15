rm bin -R -f
mkdir bin
g++ main.cpp -std=c++11 -o bin/conv
cd bin
./conv 10