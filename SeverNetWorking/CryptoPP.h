#pragma once
#include "pch.h"
#include <iostream>
#include <iomanip>

#pragma comment(lib, "cryptlib.lib")

#include "./cryptopp890/dll.h"
#include "./cryptopp890/modes.h"
#include "./cryptopp890/aes.h"
#include "./cryptopp890/filters.h"
#include "./cryptopp890/cryptlib.h"
#include "./cryptopp890/base64.h"

class Crypto
{
public:
	Crypto();
	~Crypto() {};

	std::string Encrypt(std::string& str);
	std::string Decrypt(std::string& str);

private:
	CryptoPP::byte _key[CryptoPP::AES::DEFAULT_KEYLENGTH];
	CryptoPP::byte _iv[CryptoPP::AES::BLOCKSIZE];
};