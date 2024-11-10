#ifndef AESENCRYPTOR_H
#define AESENCRYPTOR_H

#include "aescipher.h"

class AesEncryptor : public AesCipher {
public:
    AesEncryptor();
    ~AesEncryptor() = default;

    bool initialize(const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv) final;
    bool update(const std::vector<uint8_t>& plaintext, std::vector<uint8_t>& ciphertext) final;
    bool finalize(std::vector<uint8_t>& ciphertext) final;
};

#endif // AESENCRYPTOR_H
