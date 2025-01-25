gcc main.c `pkg-config --cflags gtk4` `pkg-config --libs gtk4` -o hello
./hello