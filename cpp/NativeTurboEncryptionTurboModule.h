#if __has_include(<React-Codegen/RNTurboEncryptionSpecJSI.h>)
#include <React-Codegen/RNTurboEncryptionSpecJSI.h>
#elif __has_include("RNTurboEncryptionSpecJSI.h")
#include "RNTurboEncryptionSpecJSI.h"
#endif



#include <jsi/jsi.h>
#include <ReactCommon/CallInvoker.h>








namespace facebook::react {
class NativeTurboEncryptionTurboModule: public NativeTurboEncryptionCxxSpec<NativeTurboEncryptionTurboModule> {
public:
    NativeTurboEncryptionTurboModule(std::shared_ptr<CallInvoker> jsInvoker);

    std::string encrypt(jsi::Runtime &rt, std::string plainText, std::string key);
    std::string decrypt(jsi::Runtime &rt, std::string encryptedText, std::string key);
};
}
