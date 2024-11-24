# react-native-turbo-encryption
### 🚀 Superfast Encryption Module for React Native 🔐

✨ **Written 100% in C++** with ⚡ blazing-fast performance and **direct bindings** to JavaScript! 🚀  
  

## 💻 Features
- 🛡️ **End-to-end encryption** built for speed.  
- 🔗 **Direct bindings** with React Native via ultra-efficient C++ integration.  
- 📱 **Cross-platform support**: Fully optimized for both iOS and Android.  
- 🔥 Lightweight

## Installation

```sh
npm install react-native-turbo-encryption
```

## Usage


```js
import { decrypt , encrypt } from 'react-native-turbo-encryption';

const key = "mysecurekey12345" //keep 16 characters

const encryptedResult = encrypt("DSP Siraj is the best batsman in the world", key);

// encryptedResult -> 64672edc4828c8f5f8940715f44a012b90f659a20e46e76cb9731348ea6ff408b60198054da3e49ba3d566634fa122e6

const decryptedResult = decrypt(encryptedResult, key);
// decryptedResult -> "DSP Siraj is the best batsman in the world"
```
## ⚠️ Important Note: Key Length Must Be 16 Characters 🔑
Well, **I was too lazy** to add support for different key lengths. 💤


### Comparison with other libraries

| **Module Name**          | **Encryption Time (ms)** | 
|-------------------------- |-------------------------|
| react-native-turbo-encryption | *5 ms*                  |
| react-native-aes-crypto            | *30 ms*                  | 


Note: react-native-aes-crypto has better security features than this . Prefer using that if security is your top priority.

### Screenshot of Performance Results:
![Performance Comparison Turbo](./assets/turbo.png)
![Performance Comparison](./assets/aes.png)

## License

MIT

---

