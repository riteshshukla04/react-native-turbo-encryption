import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  encrypt(plainText: string, key: string): string;
  decrypt(encryptedText: string, key: string): string;
  decryptAsync(encryptedText: string, key: string): Promise<string>;
  encryptAsync(plainText: string, key: string): Promise<string>;

  // AES-256 specific methods
  encrypt256(plainText: string, key: string): string;
  decrypt256(encryptedText: string, key: string): string;
  decrypt256Async(encryptedText: string, key: string): Promise<string>;
  encrypt256Async(plainText: string, key: string): Promise<string>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('TurboEncryption');
