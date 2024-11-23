#include "NativeTurboEncryptionTurboModule.h"

#include <cstring>
#include <syslog.h>
#include <vector>
#include <iomanip>
#include "aes.hpp"



// IV => Will move it to JS side soon
const uint8_t iv[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};


// Helper functions
std::string bytesToHex(const uint8_t *data, size_t length) {
    char buffer[3]; 
    std::string hexString;

    for (size_t i = 0; i < length; ++i) {
        sprintf(buffer, "%02x", data[i]);
        hexString.append(buffer);       
    }

    return hexString;
}

void convertKey(const std::string &key, uint8_t *outputKey) {
    std::memset(outputKey, 0, 16); // Initialize with zeros
    std::memcpy(outputKey, key.data(), std::min(key.size(), size_t(16)));
}

// Helper function: Converts a hex string to binary data
std::vector<uint8_t> hexToBytes(const std::string &hex) {
    std::vector<uint8_t> bytes(hex.length() / 2);
    for (size_t i = 0; i < bytes.size(); ++i) {
        sscanf(hex.substr(i * 2, 2).c_str(), "%2hhx", &bytes[i]);
    }
    return bytes;
}



// Main Encryption function
std::string encryptString(const std::string &plainText, const std::string &key) {
    uint8_t keyBytes[16];
    convertKey(key, keyBytes);

    uint8_t paddedInput[16] = {0};
    uint8_t encryptedOutput[16] = {0};

    // Copy plainText into paddedInput and ensure it's 16 bytes
    std::memcpy(paddedInput, plainText.c_str(), std::min(plainText.size(), size_t(16)));

    // Initialize AES context and encrypt
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, keyBytes, iv);
    std::memcpy(encryptedOutput, paddedInput, 16);
    AES_CBC_encrypt_buffer(&ctx, encryptedOutput, 16);

    // Convert encrypted output to hex string
    return bytesToHex(encryptedOutput, 16);
}


// Main Decryption function
std::string decryptString(const std::string &encryptedHex, const std::string &key) {
    uint8_t keyBytes[16];
    convertKey(key, keyBytes);

    std::vector<uint8_t> encryptedData = hexToBytes(encryptedHex);
    uint8_t decryptedOutput[16] = {0};

    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, keyBytes, iv);
    std::memcpy(decryptedOutput, encryptedData.data(), 16);
    AES_CBC_decrypt_buffer(&ctx, decryptedOutput, 16);

    return std::string(reinterpret_cast<char *>(decryptedOutput));
}














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
