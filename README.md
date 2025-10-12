# react-native-turbo-encryption

### 🚀 Superfast Encryption Module for React Native 🔐

✨ **Written 100% in C++** with ⚡ blazing-fast performance and **direct bindings** to JavaScript! 🚀

**react-native-turbo-encryption is now a [Nitro Module](https://github.com/mrousavy/nitro) 🚀**

## 💻 Features

- 🛡️ **End-to-end encryption** built for speed.
- 🔗 **Direct bindings** with React Native via ultra-efficient C++ integration.
- 📱 **Cross-platform support**: Fully optimized for both iOS and Android.
- 🔥 Lightweight
- 🚀 Supports Both **async and sync** methods
- 🔐 **AES-128 and AES-256 support** - Choose your encryption strength
- ⚡ **Blazing fast performance** with native C++ implementation

## Installation

```sh
yarn add react-native-turbo-encryption react-native-nitro-modules
```

## Usage

### AES-128 (Default)

```js
import {
  decrypt,
  encrypt,
  encryptAsync,
  decryptAsync,
} from 'react-native-turbo-encryption';

const key = 'mysecurekey12345';
const encryptedResult = encrypt(
  'DSP Siraj is the best batsman in the world',
  key
);
const encryptedResultAsync = await encryptAsync(
  'DSP Siraj is the best batsman in the world',
  key
); //Async way
// encryptedResult -> 64672edc4828c8f5f8940715f44a012b90f659a20e46e76cb9731348ea6ff408b60198054da3e49ba3d566634fa122e6

const decryptedResult = decrypt(encryptedResult, key);
const decryptedResultAsync = await decryptAsync(encryptedResultAsync, key); //Async way
// decryptedResult -> "DSP Siraj is the best batsman in the world"
```

### AES-256 (Enhanced Security)

```js
import {
  decrypt256,
  encrypt256,
  encrypt256Async,
  decrypt256Async,
} from 'react-native-turbo-encryption';

const key = 'mysecurekey12345';
const encryptedResult = encrypt256(
  'DSP Siraj is the best batsman in the world',
  key
);
const encryptedResultAsync = await encrypt256Async(
  'DSP Siraj is the best batsman in the world',
  key
); //Async way

const decryptedResult = decrypt256(encryptedResult, key);
const decryptedResultAsync = await decrypt256Async(encryptedResultAsync, key); //Async way
// decryptedResult -> "DSP Siraj is the best batsman in the world"
```

### API Reference

| Method                                | Description                 | Parameters                             |
| ------------------------------------- | --------------------------- | -------------------------------------- |
| `encrypt(plainText, key)`             | Encrypt text using AES-128  | `plainText: string`, `key: string`     |
| `decrypt(encryptedText, key)`         | Decrypt text using AES-128  | `encryptedText: string`, `key: string` |
| `encryptAsync(plainText, key)`        | Async encrypt using AES-128 | `plainText: string`, `key: string`     |
| `decryptAsync(encryptedText, key)`    | Async decrypt using AES-128 | `encryptedText: string`, `key: string` |
| `encrypt256(plainText, key)`          | Encrypt text using AES-256  | `plainText: string`, `key: string`     |
| `decrypt256(encryptedText, key)`      | Decrypt text using AES-256  | `encryptedText: string`, `key: string` |
| `encrypt256Async(plainText, key)`     | Async encrypt using AES-256 | `plainText: string`, `key: string`     |
| `decrypt256Async(encryptedText, key)` | Async decrypt using AES-256 | `encryptedText: string`, `key: string` |

### Comparison with other libraries

| **Module Name**               | **Encryption Time (ms)** |
| ----------------------------- | ------------------------ |
| react-native-turbo-encryption | _5 ms_                   |
| react-native-aes-crypto       | _30 ms_                  |
