#include "pch.h"
#include "CryptoPP.h"

Crypto::Crypto()
{
    memset(_key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(_iv, 0x00, CryptoPP::AES::BLOCKSIZE);
}

std::string Crypto::Encrypt(std::string& str)
{
    std::string ciphertext;
    std::string enc64;

    //AES ��ȣȭ
    CryptoPP::AES::Encryption aesEncryption(_key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, _iv);

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(str.c_str()), str.length());
    stfEncryptor.MessageEnd();

    //��ȣȭ�� �����͸� base64�� ���ڵ� �� ��ȯ
    CryptoPP::Base64Encoder encoder;

    encoder.Put((const byte*)ciphertext.data(), ciphertext.size());
    encoder.MessageEnd();

    unsigned long long encSize = encoder.MaxRetrievable();
    if (encSize)
    {
        enc64.resize(encSize);
        encoder.Get((byte*)&enc64[0], enc64.size());
    }
    return enc64;
}

std::string Crypto::Decrypt(std::string& str)
{
    std::string decryptedtext;
    std::string dec64;

    //base64�� ���ڵ��� �����͸� ���ڵ� �� ��ȣȭ
    CryptoPP::Base64Decoder decoder;

    decoder.Put((byte*)str.data(), str.size());
    decoder.MessageEnd();

    unsigned long long decSize = decoder.MaxRetrievable();
    if (decSize && decSize <= SIZE_MAX)
    {
        dec64.resize(decSize);
        decoder.Get((byte*)&dec64[0], dec64.size());
    }

    //AES ��ȣȭ
    CryptoPP::AES::Decryption aesDecryption(_key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, _iv);

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(dec64.c_str()), dec64.size());
    stfDecryptor.MessageEnd();

    //��ȣȭ�� ������ ��ȯ
    return decryptedtext;
}

