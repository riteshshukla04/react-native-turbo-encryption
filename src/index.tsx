const TurboEncryption = require('./NativeTurboEncryption').default;

export function encrypt(plainText: string, key: string): string {
  return TurboEncryption.encrypt(plainText, key);
}

export function decrypt(encryptedText: string, key: string): string {
  return TurboEncryption.decrypt(encryptedText, key);
}

export function encryptAsync(plainText: string, key: string): Promise<string> {
  return TurboEncryption.encryptAsync(plainText, key);
}

export function decryptAsync(
  encryptedText: string,
  key: string
): Promise<string> {
  return TurboEncryption.decryptAsync(encryptedText, key);
}
