#ifndef AES_WRAPPER_HPP
#define AES_WRAPPER_HPP

#include <string>
#include <vector>

// Convert a binary buffer to a hex string
std::string bytesToHex(const uint8_t *data, size_t length);

// Convert a hex string to binary data
std::vector<uint8_t> hexToBytes(const std::string &hex);

// Encrypt a string with a given key and return the result as a hex string
std::string encryptString(const std::string &plainText, const std::string &key);

// Decrypt a hex string with a given key and return the result as plaintext
std::string decryptString(const std::string &encryptedHex, const std::string &key);

#endif // AES_WRAPPER_HPP
