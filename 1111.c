#include <stdio.h>

/*
RC4初始化函数
*/
void rc4_init(unsigned char *s, unsigned char *key, unsigned long Len_k)
{
    int i = 0, j = 0;
    char k[256] = {0};
    unsigned char tmp = 0;
    for (i = 0; i < 256; i++)
    {
        s[i] = i;
        k[i] = key[i % Len_k];
    }
    for (i = 0; i < 256; i++)
    {
        j = (j + s[i] + k[i]) % 256;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/*
RC4加解密函数
unsigned char* Data     加解密的数据
unsigned long Len_D     加解密数据的长度
unsigned char* key      密钥
unsigned long Len_k     密钥长度
*/
void rc4_crypt(unsigned char *Data, unsigned long Len_D, unsigned char *key, unsigned long Len_k) // 加解密
{
    unsigned char s[256];
    rc4_init(s, key, Len_k);
    int i = 0, j = 0, t = 0;
    unsigned long k = 0;
    unsigned char tmp;
    for (k = 0; k < Len_D; k++)
    {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        t = (s[i] + s[j]) % 256;
        Data[k] = Data[k] ^ s[t];
    }
}
void main()
{
    // 字符串密钥
    unsigned char key[] = "moectf2023";
    unsigned long key_len = sizeof(key) - 1;
    // 数组密钥
    // unsigned char key[] = {};
    // unsigned long key_len = sizeof(key);

    // 加解密数据
    unsigned char data[] = {
        0x1B,
        0x9B,
        0xFB,
        0x19,
        0x06,
        0x6A,
        0xB5,
        0x3B,
        0x7C,
        0xBA,
        0x03,
        0xF3,
        0x91,
        0xB8,
        0xB6,
        0x3D,
        0x8A,
        0xC1,
        0x48,
        0x2E,
        0x50,
        0x11,
        0xE7,
        0xC7,
        0x4F,
        0xB1,
        0x27,
        0xCF,
        0xF3,
        0xAE,
        0x03,
        0x09,
        0xB2,
        0x08,
        0xFB,
        0xDC,
        0x22,
    };
    // 加解密
    rc4_crypt(data, sizeof(data), key, key_len);

    for (int i = 0; i < sizeof(data); i++)
    {
        printf("%c", data[i]);
    }
    printf("\n");
    return;
}
