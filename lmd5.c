#include <string.h>

#include "lua.h"
#include "lauxlib.h"

#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#  include <CommonCrypto/CommonDigest.h>
#  define EXPORT
#elif defined(_WIN32)
#  include "lmd5_win.h"
#  define EXPORT __declspec(dllexport)
#else
#  include <openssl/md5.h>
#  define EXPORT
#endif

#define MD5LEN  16

static MD5_CTX* getcontext(lua_State* L, int i) {
    if (luaL_checkudata(L, i, "md5.metadata") == NULL) {
        luaL_typerror(L, i, "md5.metadata");
    }
    return (MD5_CTX*)lua_touserdata(L, i);
}

static int _new(lua_State* L) {
    void* p = lua_newuserdata(L, sizeof(MD5_CTX));
    MD5_CTX* c = (MD5_CTX*)p;
    MD5_Init(c);
    luaL_getmetatable(L, "md5.metadata");
    lua_setmetatable(L, -2);
    return 1;
}

static int _update(lua_State* L) {
    const char* input = lua_tostring(L, -1);
    size_t len = lua_strlen(L, -1); 
    MD5_CTX* c = getcontext(L, 1);
    MD5_Update(c, input, len);
    return 1;
}

static int _hexdigest(lua_State* L) {
    unsigned char result[MD5LEN];
    int cbHash = MD5LEN;
    char rgbDigits[] = "0123456789abcdef";
    int i;
    char output[33];

    MD5_CTX* c = getcontext(L, 1);
    MD5_Final(result, c);

    for (i = 0; i < cbHash; i++)
    {
        sprintf(&output[i*2], "%c%c", rgbDigits[result[i] >> 4], rgbDigits[result[i] & 0xf]);
    }

    lua_pushstring(L, output);
    return 1;
}

static const luaL_reg R[] = {
    { "new",       _new          },
    { "update",    _update       },
    { "hexdigest", _hexdigest    },
    { NULL,        NULL          }
};

EXPORT int luaopen_lmd5(lua_State* L) {
    luaL_openlib(L, "md5", R, 0);
    luaL_newmetatable(L, "md5.metadata");
    lua_pushliteral(L, "__index");
    lua_pushvalue(L, -3);
    lua_rawset(L, -3); 
    return 1;
}
