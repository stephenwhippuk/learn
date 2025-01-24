echo compiling mylib ...
rm bin -R -f
mkdir bin
gcc lib.c -c -o bin/mylib.o

echo creating library ...
ar rcs bin/libmylib.a bin/mylib.o