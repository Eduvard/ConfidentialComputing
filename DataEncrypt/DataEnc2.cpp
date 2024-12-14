unsigned char resultData[AES_BLOCK_SIZE] = { 0 };
snprintf((char*)resultData, sizeof(resultData), "%d", result);
unsigned char encryptedResult[AES_BLOCK_SIZE] = { 0 };
encryptAES(key, resultData, encryptedResult);
std::cout << "Encrypted result after computation: ";
printHex(encryptedResult, AES_BLOCK_SIZE);
