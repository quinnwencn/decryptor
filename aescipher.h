#ifndef CRYPTO_H
#define CRYPTO_H

#include <vector>
#include <QString>

#include "sslwrapper.h"

class AesCipher {
public:
    AesCipher() : ctx_(::EVP_CIPHER_CTX_new()), len_(0) {}
    ~AesCipher() = default;

    virtual bool initialize(const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv) = 0;
    virtual bool update(const std::vector<uint8_t>& plaintext, std::vector<uint8_t>& ciphertext) = 0;
    virtual bool finalize(std::vector<uint8_t>& ciphertext) = 0;

protected:
    crypto::CipherCtx ctx_;
    int len_;
};

#endif // CRYPTO_H
