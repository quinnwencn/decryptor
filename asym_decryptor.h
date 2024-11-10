#ifndef ASYM_DECRYPTOR_H
#define ASYM_DECRYPTOR_H
#include <vector>

#include "sslwrapper.h"

namespace crypto {

class AsymDecryptor {
public:
    AsymDecryptor(EvpKey&& key) : key_(std::move(key)) {}
    bool init();
    bool decrypt(const std::vector<uint8_t>& ciphertext, std::vector<uint8_t>& plaintext);

private:
    EvpKey key_;
    EvpKeyCtx ctx_;
};

}

#endif // ASYM_DECRYPTOR_H
