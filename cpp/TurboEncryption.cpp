//
//  TurboEncryption.cpp
//  TurboEncryption
//
//  Created by Ritesh Shukla on 11/10/25.
//

#include "TurboEncryption.hpp"
#include "AESWrapper.hpp"

namespace margelo::nitro::turboencryption {
  
  std::string TurboEncryption::encrypt(const std::string &plainText, const std::string &key){
    return  encryptString(plainText, key,AESType::AES_128);
  }

  std::string TurboEncryption::decrypt(const std::string &plainText, const std::string &key){
    return decryptString(plainText,  key,AESType::AES_128);
  }

  

  std::shared_ptr<Promise<std::string>> TurboEncryption::encryptAsync(const std::string& plainText, const std::string& key){
    return Promise<std::string>::async([plainText,key](){
      return encryptString(plainText, key,AESType::AES_128);
    });
  }

  std::shared_ptr<Promise<std::string>> TurboEncryption::decryptAsync(const std::string& plainText, const std::string& key){
    return Promise<std::string>::async([plainText,key](){
      return decryptString(plainText, key,AESType::AES_128);
    });
  }


  std::string TurboEncryption::encrypt256(const std::string &plainText, const std::string &key){
    return  encryptString(plainText, key,AESType::AES_256);
  }

  std::string TurboEncryption::decrypt256(const std::string &plainText, const std::string &key){
    return decryptString(plainText,  key,AESType::AES_256);
  }

  std::shared_ptr<Promise<std::string>> TurboEncryption::decrypt256Async(const std::string& encryptedText, const std::string& key){
    return Promise<std::string>::async([encryptedText,key](){
      return decryptString(encryptedText, key,AESType::AES_256);
    });
  }

  std::shared_ptr<Promise<std::string>> TurboEncryption::encrypt256Async(const std::string& plainText, const std::string& key){
    return Promise<std::string>::async([plainText,key](){
      return encryptString(plainText, key,AESType::AES_256);
    });
  }

  
}
