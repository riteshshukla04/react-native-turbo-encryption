#include "NativeTurboEncryptionTurboModule.h"
#include "AESWrapper.hpp"

namespace facebook::react
{
NativeTurboEncryptionTurboModule::NativeTurboEncryptionTurboModule(std::shared_ptr<CallInvoker> jsinvoker) : NativeTurboEncryptionCxxSpec<NativeTurboEncryptionTurboModule>(std::move(jsinvoker)) {}

    std::string NativeTurboEncryptionTurboModule::encrypt(jsi::Runtime &rt, std::string plainText , std::string key){
        std::string encryptedText = encryptString(plainText, key);
        return encryptedText;
    }
    
    std::string NativeTurboEncryptionTurboModule::decrypt(jsi::Runtime &rt, std::string encryptedText , std::string key){
        std::string decryptedText = decryptString(encryptedText, key);
        return decryptedText;
    }
}
