#include <windows.h>
#include <Wincrypt.h>

typedef struct MD5_CTX_st
{
    HCRYPTPROV prov;
    HCRYPTHASH hash;
} MD5_CTX;

__declspec(dllexport) int MD5_Init(MD5_CTX* ctx);
__declspec(dllexport) int MD5_Update(MD5_CTX* ctx, const void* data, unsigned int len);
__declspec(dllexport) int MD5_Final(unsigned char* output, MD5_CTX* ctx);