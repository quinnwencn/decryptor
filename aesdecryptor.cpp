#include "aesdecryptor.h"

bool AesDecryptor::initialize(const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv) {
    if (::EVP_DecryptInit_ex(ctx_.get(), ::EVP_aes_128_cbc(), nullptr, key.data(), iv.data()) != 1) {
        return false;
    }

    return true;
}

bool  AesDecryptor::update(const std::vector<uint8_t>& ciphertext, std::vector<uint8_t>& plaintext) {
    if (plaintext.size() == 0) {
        plaintext.resize(ciphertext.size());
    }

    int len = 0;
    if (::EVP_DecryptUpdate(ctx_.get(), plaintext.data(), &len, ciphertext.data(), ciphertext.size()) != 1) {
        return false;
    }

    len_ += len;
    return true;
}

bool  AesDecryptor::finalize(std::vector<uint8_t>& plaintext) {
    int len = 0;
    if (::EVP_DecryptFinal_ex(ctx_.get(), plaintext.data() + len_, &len) != 1) {
        return false;
    }

    plaintext.resize(len_ + len);
    return true;
}
