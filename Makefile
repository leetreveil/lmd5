
build:
	gcc -Wall -shared -fPIC -o lmd5.so -I/usr/local/include -llua lmd5.c

test:
	lua test.lua