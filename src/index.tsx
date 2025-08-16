const TurboEncryption = require('./NativeTurboEncryption').default;

// AES Type constants
export const AESType = {
  AES128: 0,
  AES256: 1,
} as const;

export type AESTypeValue = (typeof AESType)[keyof typeof AESType];

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

// AES-256 specific functions
export function encrypt256(plainText: string, key: string): string {
  return TurboEncryption.encrypt256(plainText, key);
}

export function decrypt256(encryptedText: string, key: string): string {
  return TurboEncryption.decrypt256(encryptedText, key);
}

export function encrypt256Async(
  plainText: string,
  key: string
): Promise<string> {
  return TurboEncryption.encrypt256Async(plainText, key);
}

export function decrypt256Async(
  encryptedText: string,
  key: string
): Promise<string> {
  return TurboEncryption.decrypt256Async(encryptedText, key);
}
