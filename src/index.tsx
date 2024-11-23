const TurboEncryption = require('./NativeTurboEncryption').default;


export function encrypt(plainText: string, key: string): string {
  if (key.length !== 16) {
    throw new Error("Key must be 16 characters long");
  }
  return TurboEncryption.encrypt(plainText, key);
}


export function decrypt(encryptedText: string, key: string): string {
  if (key.length !== 16) {
    throw new Error("Key must be 16 characters long");
  }
  return TurboEncryption.decrypt(encryptedText, key);
}
