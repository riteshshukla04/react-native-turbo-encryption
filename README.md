# react-native-turbo-encryption

### 🚀 Superfast Encryption Module for React Native 🔐

✨ **Written 100% in C++** with ⚡ blazing-fast performance and **direct bindings** to JavaScript! 🚀

**Requires new arch to be set to true**

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
npm install react-native-turbo-encryption
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

Note: react-native-aes-crypto has better security features than this. Prefer using that if security is your top priority.

## 🔧 Technical Details

This module uses the [tinyaes](https://github.com/kokke/tiny-AES-C) C library as a submodule for AES encryption. The library has been modified to support both AES-128 and AES-256 encryption modes.

### Submodule Modifications

The `tinyaes` submodule has been modified to enable AES-256 support:

- Enabled `AES256` macro in `cpp/tinyaes/aes.h`
- Configured key sizes to support both AES-128 and AES-256
- Added proper key handling for both encryption modes

**Note**: Since the submodule code has been modified, you may need to handle submodule updates carefully. Consider forking the tinyaes repository if you need to maintain these changes long-term.

### Handling Submodule Changes

Since we've modified the `tinyaes` submodule code, here are the recommended approaches:

1. **Fork the tinyaes repository** and point the submodule to your fork
2. **Document the changes** in this README (as done above)
3. **Create a patch file** for the modifications ✅ (done)
4. **Consider contributing** the AES-256 support back to the original tinyaes project

**Recommended workflow for future updates:**

1. **Fork the tinyaes repository** on GitHub
2. **Apply the patch** to your fork
3. **Update the submodule** to point to your fork
4. **Test thoroughly** to ensure compatibility

This way, you maintain control over the modifications while still being able to receive updates from the original repository.

To track these changes, you can:

```bash
# Check the current submodule status
git submodule status

# See what changes have been made to the submodule
cd cpp/tinyaes
git status
git diff

# Commit the submodule changes
git add .
git commit -m "Enable AES-256 support"
```

### Patch File

A patch file has been created (`aes256-support.patch`) that contains the exact changes made to the tinyaes submodule. This can be used to:

- Apply the same changes to future versions of the submodule
- Share the modifications with others
- Document the exact changes made

To apply this patch to a fresh submodule:

```bash
cd cpp/tinyaes
git apply ../../aes256-support.patch
```

### Current Submodule Status

The tinyaes submodule is currently at commit `3dec066` with the AES-256 support changes committed. The submodule is in a detached HEAD state, which is normal for submodules.

**Current submodule commit**: `3dec066e9b9c21aa66d98563b6247d28971d2cc4`
**Changes**: Enabled AES-256 support and configured key sizes for dual AES-128/AES-256 compatibility

### Screenshot of Performance Results:

![Performance Comparison Turbo](./assets/turbo.png)
![Performance Comparison](./assets/aes.png)
