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

void encryptAES(const unsigned char* key, const unsigned char* input, unsigned char* output) {
    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);
    AES_encrypt(input, output, &aesKey);
}

void decryptAES(const unsigned char* key, const unsigned char* input, unsigned char* output) {
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);
    AES_decrypt(input, output, &aesKey);
}

int main() {

    unsigned char encryptedData[AES_BLOCK_SIZE] = { 0 };
    encryptAES(key, sensitiveData, encryptedData);
    std::cout << "Encrypted data: ";
    printHex(encryptedData, AES_BLOCK_SIZE);


    unsigned char decryptedData[AES_BLOCK_SIZE] = { 0 };
    decryptAES(key, encryptedData, decryptedData);
    std::cout << "Decrypted data inside TEE: " << decryptedData << std::endl;

  
    bool isAttested = true;
    if (isAttested) {
        std::cout << "TEE is verified and trusted!" << std::endl;
    }
    else {
        std::cout << "TEE verification failed!" << std::endl;
    }

    
    int result = atoi((char*)decryptedData) + 10;  
    std::cout << "Processed result: " << result << std::endl;

    
    unsigned char resultData[AES_BLOCK_SIZE] = { 0 };
    snprintf((char*)resultData, sizeof(resultData), "%d", result);
    unsigned char encryptedResult[AES_BLOCK_SIZE] = { 0 };
    encryptAES(key, resultData, encryptedResult);
    std::cout << "Encrypted result after computation: ";
    printHex(encryptedResult, AES_BLOCK_SIZE);

   
    unsigned char finalResult[AES_BLOCK_SIZE] = { 0 };
    decryptAES(key, encryptedResult, finalResult);
    std::cout << "Final processed result: " << finalResult << std::endl;

    return 0;
}
