#ifndef SSLWRAPPER_H
#define SSLWRAPPER_H
#include <memory>
#include <string>

#include <openssl/evp.h>
#include <openssl/err.h>

namespace crypto {

#define  DELETER(Type, Deletor) \
    void operator()(::Type* ptr) const { \
        ::Deletor(ptr);  \
    }

struct SslDelete {
    DELETER(EVP_CIPHER_CTX, EVP_CIPHER_CTX_free)
    DELETER(EVP_PKEY, EVP_PKEY_free)
    DELETER(EVP_PKEY_CTX, EVP_PKEY_CTX_free)
};

using CipherCtx = std::unique_ptr<::EVP_CIPHER_CTX, SslDelete>;
using EvpKey = std::unique_ptr<::EVP_PKEY, SslDelete>;
using EvpKeyCtx = std::unique_ptr<::EVP_PKEY_CTX, SslDelete>;

inline std::string getOpensslErrStr() {
    char buf[255];
    auto errorCode = ::ERR_get_error();
    ::ERR_error_string_n(errorCode, buf, sizeof(buf));
    return std::string(buf);
}

}

#endif // SSLWRAPPER_H
