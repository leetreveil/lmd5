#include "lmd5_win.h"

#define MD5LEN  16

int MD5_Init(MD5_CTX* ctx)
{
    DWORD dwStatus;

    if (!CryptAcquireContext(&ctx->prov, NULL, NULL, PROV_RSA_FULL,
                             CRYPT_VERIFYCONTEXT))
    {
        dwStatus = GetLastError();
        return dwStatus;
    }

    if (!CryptCreateHash(ctx->prov, CALG_MD5, 0, 0, &ctx->hash))
    {
        dwStatus = GetLastError();
        CryptReleaseContext(ctx->prov, 0);
        return dwStatus;
    }

    return 0;
}

int MD5_Update(MD5_CTX* ctx, const void* data, unsigned int len)
{
    DWORD dwStatus;

    if (!CryptHashData(ctx->hash, (BYTE*)data, len, 0))
    {
        dwStatus = GetLastError();
        CryptReleaseContext(ctx->prov, 0);
        CryptDestroyHash(ctx->hash);
        return dwStatus;
    }

    return 0;
}

int MD5_Final(unsigned char* output, MD5_CTX* ctx)
{
    DWORD cbHash = MD5LEN;
    DWORD dwStatus;

    if (!CryptGetHashParam(ctx->hash, HP_HASHVAL, output, &cbHash, 0))
    {
        dwStatus = GetLastError();
    }

    CryptDestroyHash(ctx->hash);
    CryptReleaseContext(ctx->prov, 0);

    return 0;
}