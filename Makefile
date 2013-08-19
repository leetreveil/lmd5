
build:
	gcc -Wall -shared -fPIC -o lmd5.so -I/usr/include/lua5.2 -llua lmd5.c

test:
	lua test.lua