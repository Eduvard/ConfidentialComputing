unsigned char decryptedData[AES_BLOCK_SIZE] = { 0 };
decryptAES(key, encryptedData, decryptedData);
std::cout << "Decrypted data inside TEE: " << decryptedData << std::endl;
