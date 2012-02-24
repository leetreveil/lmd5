lmd5
===

### build

osx/unix
    gcc -Wall -shared -fPIC -o build/lmd5.so -I/usr/local/include -llua lmd5.c

win (replace lua paths with your own)
    cl -o build\lmd5.dll lmd5_win.c lmd5.c /I"C:\Program Files (x86)\Lua\5.1\include" "C:\Program Files (x86)\Lua\5.1\lib\lua51.lib" advapi32.lib /link /DLL


### use
```lua
    require("lmd5")

    local md5 = md5.new()
    md5:update("abc")
    print(md5:hexdigest())
```

thats it!



  