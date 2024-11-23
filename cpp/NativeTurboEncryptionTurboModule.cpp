#include "NativeTurboEncryptionTurboModule.h"

#include <cstring>
#include <syslog.h>
#include <vector>
#include <iomanip>
#include "aes.hpp"

// Initialization vector (16 bytes)
const uint8_t iv[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

// Convert std::string key to uint8_t[16]
void convertKey(const std::string &key, uint8_t *outputKey)
{
    std::memset(outputKey, 0, 16); // Initialize with zeros
    std::memcpy(outputKey, key.data(), std::min(key.size(), size_t(16)));
}

// Helper: Add padding to plaintext to make its size a multiple of 16 bytes
std::vector<uint8_t> addPadding(const std::string &plainText)
{
    size_t paddingSize = 16 - (plainText.size() % 16);
    std::vector<uint8_t> paddedData(plainText.begin(), plainText.end());
    paddedData.resize(plainText.size() + paddingSize, static_cast<uint8_t>(paddingSize));
    return paddedData;
}

// Helper: Remove padding from decrypted plaintext
std::string removePadding(const std::vector<uint8_t> &paddedData)
{
    size_t paddingSize = paddedData.back(); // Padding size is stored in the last byte
    return std::string(paddedData.begin(), paddedData.end() - paddingSize);
}

// Alternative implementation: Converts binary data to a hex string
std::string bytesToHex(const uint8_t *data, size_t length)
{
    char buffer[3];
    std::string hexString;

    for (size_t i = 0; i < length; ++i)
    {
        sprintf(buffer, "%02x", data[i]);
        hexString.append(buffer);
    }

    return hexString;
}

// Helper function: Converts a hex string to binary data
std::vector<uint8_t> hexToBytes(const std::string &hex)
{
    std::vector<uint8_t> bytes(hex.length() / 2);
    for (size_t i = 0; i < bytes.size(); ++i)
    {
        sscanf(hex.substr(i * 2, 2).c_str(), "%2hhx", &bytes[i]);
    }
    return bytes;
}

// Function to encrypt a string with a string key and return the result as a hex string
std::string encryptString(const std::string &plainText, const std::string &key)
{
    uint8_t keyBytes[16];
    convertKey(key, keyBytes);

    // Add padding to the plaintext
    std::vector<uint8_t> paddedData = addPadding(plainText);

    // Prepare the encrypted output buffer
    std::vector<uint8_t> encryptedData(paddedData.size());

    // Initialize AES context
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, keyBytes, iv);

    // Encrypt data in blocks of 16 bytes
    for (size_t i = 0; i < paddedData.size(); i += 16)
    {
        std::memcpy(&encryptedData[i], &paddedData[i], 16);
        AES_CBC_encrypt_buffer(&ctx, &encryptedData[i], 16);
    }

    // Convert encrypted data to hex string
    return bytesToHex(encryptedData.data(), encryptedData.size());
}

// Function to decrypt a hex string with a string key and return the result as a plaintext string
std::string decryptString(const std::string &encryptedHex, const std::string &key)
{
    uint8_t keyBytes[16];
    convertKey(key, keyBytes);

    // Convert hex string back to binary
    std::vector<uint8_t> encryptedData = hexToBytes(encryptedHex);

    // Prepare the decrypted output buffer
    std::vector<uint8_t> decryptedData(encryptedData.size());

    // Initialize AES context
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, keyBytes, iv);

    // Decrypt data in blocks of 16 bytes
    for (size_t i = 0; i < encryptedData.size(); i += 16)
    {
        std::memcpy(&decryptedData[i], &encryptedData[i], 16);
        AES_CBC_decrypt_buffer(&ctx, &decryptedData[i], 16);
    }

    // Remove padding and return plaintext
    return removePadding(decryptedData);
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
