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

## Installation

```sh
npm install react-native-turbo-encryption
```

## Usage


```js
import { decrypt , encrypt, encryptAsync, decryptAsync } from 'react-native-turbo-encryption';

const key = "mysecurekey12345"
const encryptedResult = encrypt("DSP Siraj is the best batsman in the world", key);
const encryptedResultAsync = await encryptAsync("DSP Siraj is the best batsman in the world", key); //Async way
// encryptedResult -> 64672edc4828c8f5f8940715f44a012b90f659a20e46e76cb9731348ea6ff408b60198054da3e49ba3d566634fa122e6

const decryptedResult = decrypt(encryptedResult, key);

const decryptedResultAsync = await decryptAsync(encryptedResultAsync, key);//Async way
// decryptedResult -> "DSP Siraj is the best batsman in the world"
```



### Comparison with other libraries

| **Module Name**          | **Encryption Time (ms)** | 
|-------------------------- |-------------------------|
| react-native-turbo-encryption | *5 ms*                  |
| react-native-aes-crypto            | *30 ms*                  | 


Note: react-native-aes-crypto has better security features than this . Prefer using that if security is your top priority.

### Screenshot of Performance Results:
![Performance Comparison Turbo](./assets/turbo.png)
![Performance Comparison](./assets/aes.png)



