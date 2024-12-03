const TurboEncryption = require('./NativeTurboEncryption').default;


export function encrypt(plainText: string, key: string): string {
  console.log(key.length)
  return TurboEncryption.encrypt(plainText, key);
}


export function decrypt(encryptedText: string, key: string): string {
  console.log(key.length)
  return TurboEncryption.decrypt(encryptedText, key);
}
