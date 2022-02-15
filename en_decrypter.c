#include "stdio.h"
#include "string.h"
#include "o_aes.h"
//#include "openssl/rsa.h"

void encrypt(unsigned char *str_i, const unsigned char *key_o, unsigned char *str_o)
{

    AES_KEY key;
    AES_set_encrypt_key(key_o, 128, &key);
    if (strlen((const char *) str_i) > 128)
    {
        unsigned char str_I[128];
        unsigned char str_O[128];
        size_t times = (strlen((const char *) str_i) / 128) + 1;
        for (int a = 0; a < times; a++)
        {
            for (int i = 0; i < 128; i++)
            {
                str_I[i] = str_i[i];
            }
            for (size_t i = 0; i < strlen((const char *) str_i); i++)
                str_i[i] = str_i[i + 128];
            AES_encrypt(str_I, str_O, &key);
            strcat((char *) str_o, (char *) str_O);
        }

    } else
        AES_encrypt(str_i, str_o, &key);
}

void decrypt(unsigned char *str_i, const unsigned char *key_o, unsigned char *str_o)
{

    AES_KEY key;
    AES_set_decrypt_key(key_o, 128, &key);
    if (strlen((const char *) str_i) > 128)
    {
        unsigned char str_I[128];
        unsigned char str_O[128];
        size_t times = (strlen((const char *) str_i) / 128) + 1;
        for (int a = 0; a < times; a++)
        {
            for (int i = 0; i < 128; i++)
            {
                str_I[i] = str_i[i];
            }
            for (size_t i = 0; i < strlen((const char *) str_i); i++)
                str_i[i] = str_i[i + 128];
            AES_decrypt(str_I, str_O, &key);
            strcat((char *) str_o, (char *) str_O);
        }

    } else
        AES_decrypt(str_i, str_o, &key);
}

int main()
{
    unsigned char key_o[16];//用户定义的密钥
    unsigned char str_i[16];
    unsigned char str_o[16];
    int type;
    printf("input AES key(15letters)(optional)");
    scanf("%s",key_o);
    if (strlen((char *)key_o)==0)
        strcpy((char *)key_o,"0123456789abcde");
    printf("Input string.\n1024 letters at most.\n");
    if (strlen((char *) str_i) > 1024)
        printf("Check your input length.\n");
    scanf("%s",str_i);
    printf("Choose type\nPress 1 to encrypt or 2 to decrypt.\nPress 0 to exit.\n");
    scanf("%d",&type);
    if (type == 1)
        encrypt(str_i, key_o, str_o);
    else if (type == 2)
        decrypt(str_i, key_o, str_o);
    else if (type == 0)
        return 0;
    else
        printf("Check your input.\n");
    printf("%s",str_o);
}