#include "NativeTurboEncryptionTurboModule.h"
#include "AESWrapper.hpp"
#include <thread>

namespace facebook::react
{
NativeTurboEncryptionTurboModule::NativeTurboEncryptionTurboModule(std::shared_ptr<CallInvoker> jsinvoker) : NativeTurboEncryptionCxxSpec<NativeTurboEncryptionTurboModule>(std::move(jsinvoker)) {}

    std::string NativeTurboEncryptionTurboModule::encrypt(jsi::Runtime &rt, std::string plainText, std::string key){
        std::string encryptedText = encryptString(plainText, key, AESType::AES_128);
        return encryptedText;
    }
    
    std::string NativeTurboEncryptionTurboModule::decrypt(jsi::Runtime &rt, std::string encryptedText, std::string key){
        std::string decryptedText = decryptString(encryptedText, key, AESType::AES_128);
        return decryptedText;
    }

    jsi::Value NativeTurboEncryptionTurboModule::encryptAsync(jsi::Runtime &rt, std::string plainText, std::string key)
    {
        jsi::Function promiseConstructor = rt.global().getPropertyAsFunction(rt, "Promise");
        
        return promiseConstructor.callAsConstructor(rt,
                                                    jsi::Function::createFromHostFunction(
                                                                                          rt,
                                                                                          jsi::PropNameID::forAscii(rt, "promiseArg"),
                                                                                          2,
                                                                                          [plainText, key, jsInvoker = jsInvoker_](
                                                                                                                                       jsi::Runtime &runtime,
                                                                                                                                       const jsi::Value &thisValue,
                                                                                                                                       const jsi::Value *arguments,
                                                                                                                                       std::size_t count) -> jsi::Value
                                                                                          {
                                                                                              auto resolverValue = std::make_shared<jsi::Value>((arguments[0].asObject(runtime)));
                                                                                              
                                                                                              std::thread([plainText, key, resolverValue = std::move(resolverValue), jsInvoker, &runtime]()
                                                                                                          {
                                                                                                  std::string encryptedString = encryptString(plainText, key, AESType::AES_128);
                                                                                                  // Post back to JS thread
                                                                                                  jsInvoker->invokeAsync([resolverValue, encryptedString, &runtime]() {
                                                                                                      resolverValue->asObject(runtime).asFunction(runtime).call(runtime, encryptedString);
                                                                                                  }); })
                                                                                              .detach();
                                                                                              return jsi::Value::undefined();
                                                                                          })
                                                    
                                                    );
    }


    jsi::Value NativeTurboEncryptionTurboModule::decryptAsync(jsi::Runtime &rt, std::string encryptedText, std::string key)
    {
        jsi::Function promiseConstructor = rt.global().getPropertyAsFunction(rt, "Promise");
        
        return promiseConstructor.callAsConstructor(rt,
                                                    jsi::Function::createFromHostFunction(
                                                                                          rt,
                                                                                          jsi::PropNameID::forAscii(rt, "promiseArg"),
                                                                                          2,
                                                                                          [encryptedText, key, jsInvoker = jsInvoker_](
                                                                                                                                       jsi::Runtime &runtime,
                                                                                                                                       const jsi::Value &thisValue,
                                                                                                                                       const jsi::Value *arguments,
                                                                                                                                       std::size_t count) -> jsi::Value
                                                                                          {
                                                                                              auto resolverValue = std::make_shared<jsi::Value>((arguments[0].asObject(runtime)));
                                                                                              
                                                                                              std::thread([encryptedText, key, resolverValue = std::move(resolverValue), jsInvoker, &runtime]()
                                                                                                          {
                                                                                                std::string  decryptedString = decryptString(encryptedText, key, AESType::AES_128);
                                                                                                  // Post back to JS thread
                                                                                                  jsInvoker->invokeAsync([resolverValue, decryptedString, &runtime]() {
                                                                                                      resolverValue->asObject(runtime).asFunction(runtime).call(runtime, decryptedString);
                                                                                                  }); })
                                                                                              .detach();
                                                                                              return jsi::Value::undefined();
                                                                                          })
                                                    
                                                    );
        }
    
    // AES-256 specific methods
    std::string NativeTurboEncryptionTurboModule::encrypt256(jsi::Runtime &rt, std::string plainText, std::string key){
        std::string encryptedText = encryptString(plainText, key, AESType::AES_256);
        return encryptedText;
    }
    
    std::string NativeTurboEncryptionTurboModule::decrypt256(jsi::Runtime &rt, std::string encryptedText, std::string key){
        std::string decryptedText = decryptString(encryptedText, key, AESType::AES_256);
        return decryptedText;
    }
    
    jsi::Value NativeTurboEncryptionTurboModule::encrypt256Async(jsi::Runtime &rt, std::string plainText, std::string key)
    {
        jsi::Function promiseConstructor = rt.global().getPropertyAsFunction(rt, "Promise");
        
        return promiseConstructor.callAsConstructor(rt,
                                                    jsi::Function::createFromHostFunction(
                                                                                          rt,
                                                                                          jsi::PropNameID::forAscii(rt, "promiseArg"),
                                                                                          2,
                                                                                          [plainText, key, jsInvoker = jsInvoker_](
                                                                                                                                       jsi::Runtime &runtime,
                                                                                                                                       const jsi::Value &thisValue,
                                                                                                                                       const jsi::Value *arguments,
                                                                                                                                       std::size_t count) -> jsi::Value
                                                                                          {
                                                                                              auto resolverValue = std::make_shared<jsi::Value>((arguments[0].asObject(runtime)));
                                                                                              
                                                                                              std::thread([plainText, key, resolverValue = std::move(resolverValue), jsInvoker, &runtime]()
                                                                                                          {
                                                                                                  std::string encryptedString = encryptString(plainText, key, AESType::AES_256);
                                                                                                  // Post back to JS thread
                                                                                                  jsInvoker->invokeAsync([resolverValue, encryptedString, &runtime]() {
                                                                                                      resolverValue->asObject(runtime).asFunction(runtime).call(runtime, encryptedString);
                                                                                                  }); })
                                                                                              .detach();
                                                                                              return jsi::Value::undefined();
                                                                                          })
                                                    
                                                    );
    }
    
    jsi::Value NativeTurboEncryptionTurboModule::decrypt256Async(jsi::Runtime &rt, std::string encryptedText, std::string key)
    {
        jsi::Function promiseConstructor = rt.global().getPropertyAsFunction(rt, "Promise");
        
        return promiseConstructor.callAsConstructor(rt,
                                                    jsi::Function::createFromHostFunction(
                                                                                          rt,
                                                                                          jsi::PropNameID::forAscii(rt, "promiseArg"),
                                                                                          2,
                                                                                          [encryptedText, key, jsInvoker = jsInvoker_](
                                                                                                                                       jsi::Runtime &runtime,
                                                                                                                                       const jsi::Value &thisValue,
                                                                                                                                       const jsi::Value *arguments,
                                                                                                                                       std::size_t count) -> jsi::Value
                                                                                          {
                                                                                              auto resolverValue = std::make_shared<jsi::Value>((arguments[0].asObject(runtime)));
                                                                                              
                                                                                              std::thread([encryptedText, key, resolverValue = std::move(resolverValue), jsInvoker, &runtime]()
                                                                                                          {
                                                                                                std::string  decryptedString = decryptString(encryptedText, key, AESType::AES_256);
                                                                                                  // Post back to JS thread
                                                                                                  jsInvoker->invokeAsync([resolverValue, decryptedString, &runtime]() {
                                                                                                      resolverValue->asObject(runtime).asFunction(runtime).call(runtime, decryptedString);
                                                                                                  }); })
                                                                                              .detach();
                                                                                              return jsi::Value::undefined();
                                                                                          })
                                                    
                                                    );
    }
 

 
}
