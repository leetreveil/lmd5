lmd5
===
cross platform md5 library for lua

build
-----------------

osx/unix

    make

win (replace lua paths with your own)

    cl -o lmd5.dll lmd5_win.c lmd5.c /I"C:\Program Files (x86)\Lua\5.1\include" "C:\Program Files (x86)\Lua\5.1\lib\lua51.lib" advapi32.lib /link /DLL


usage
-----------------

```lua
require("lmd5")
local md5 = md5.new()
md5:update("abc")
print(md5:hexdigest())
```

thats it!

licence
-----------------

(The MIT License)

Copyright (c) 2012 Lee Treveil <leetreveil@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the 'Software'), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



  