#include "asym_decryptor.h"

#include <QMessageBox>

namespace crypto {

bool AsymDecryptor::init() {
    EvpKeyCtx ctx {::EVP_PKEY_CTX_new(key_.get(), nullptr)};
    if (ctx == nullptr) {
        QMessageBox::warning(nullptr, "Error", "Failed to allocate asym ctx");
        return false;
    }

    ctx_ = std::move(ctx);
    if (::EVP_PKEY_decrypt_init(ctx_.get()) <= 0) {
        QMessageBox::warning(nullptr, "Error", "Failed to init asym decrypt");
        return false;
    }
    return true;
}

bool AsymDecryptor::decrypt(const std::vector<uint8_t>& ciphertext, std::vector<uint8_t>& plaintext) {
    size_t len = 0;
    if (::EVP_PKEY_decrypt(ctx_.get(), nullptr, &len, ciphertext.data(), ciphertext.size()) != 1) {
        QMessageBox::warning(nullptr, "Error", "Failed to get plaintext size");
        return false;
    }

    plaintext.resize(len, 0);
    if (::EVP_PKEY_decrypt(ctx_.get(), plaintext.data(), &len, ciphertext.data(), ciphertext.size()) != 1) {
        QMessageBox::warning(nullptr, "Error", "Failed to decrypt ciphertext");
        return false;
    }

    plaintext.resize(len);
    return true;
}

}
