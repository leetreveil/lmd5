
build:
	gcc -Wall -shared -fPIC -o lmd5.so -I/usr/include/lua5.2 -L/usr/lib/x86_64-linux-gnu -llua5.2 lmd5.c

test:
	lua test.lua