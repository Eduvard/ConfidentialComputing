#include <iostream>
#include <openssl/aes.h>
#include <openssl/rand.h>

unsigned char key[AES_BLOCK_SIZE] = "0123456789abcdef";  
unsigned char sensitiveData[16] = "SensitiveData123";   

void printHex(const unsigned char* data, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%02x", data[i]);
    }
    printf("\n");
}
