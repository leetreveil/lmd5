
build:
	gcc -Wall -shared -fPIC -o lmd5.so -I/usr/include -llua lmd5.c

test:
	lua test.lua