unsigned char encryptedData[AES_BLOCK_SIZE] = { 0 };
encryptAES(key, sensitiveData, encryptedData);
std::cout << "Encrypted data: ";
printHex(encryptedData, AES_BLOCK_SIZE);
