#ifndef AESDECRYPTOR_H
#define AESDECRYPTOR_H

#include "aescipher.h"

class AesDecryptor : public AesCipher {
public:
    AesDecryptor() = default;
    ~AesDecryptor() = default;

    bool initialize(const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv) final;
    bool update(const std::vector<uint8_t>& ciphertext, std::vector<uint8_t>& plaintext) final;
    bool finalize(std::vector<uint8_t>& plaintext) final;
};

#endif // AESDECRYPTOR_H
