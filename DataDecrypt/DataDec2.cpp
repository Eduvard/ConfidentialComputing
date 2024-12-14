unsigned char finalResult[AES_BLOCK_SIZE] = { 0 };
decryptAES(key, encryptedResult, finalResult);
std::cout << "Final processed result: " << finalResult << std::endl;
