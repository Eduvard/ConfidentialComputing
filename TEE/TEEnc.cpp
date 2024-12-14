
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
