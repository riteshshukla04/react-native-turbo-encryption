
#include "HybridTurboEncryptionSpec.hpp"


namespace margelo::nitro::turboencryption {
  class TurboEncryption final: public HybridTurboEncryptionSpec {
  public:
    TurboEncryption():HybridObject(TAG){};
    std::string encrypt(const std::string& plainText, const std::string& key) override;
    std::string decrypt(const std::string& encryptedText, const std::string& key) override;
    std::shared_ptr<Promise<std::string>> decryptAsync(const std::string& encryptedText, const std::string& key) override;
    std::shared_ptr<Promise<std::string>> encryptAsync(const std::string& plainText, const std::string& key) override;
    std::string encrypt256(const std::string& plainText, const std::string& key) override;
    std::string decrypt256(const std::string& encryptedText, const std::string& key) override;
    std::shared_ptr<Promise<std::string>> decrypt256Async(const std::string& encryptedText, const std::string& key) override;
    std::shared_ptr<Promise<std::string>> encrypt256Async(const std::string& plainText, const std::string& key) override;
  };
}
