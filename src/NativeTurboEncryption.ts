import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  encrypt(plainText: string, key: string): string;
  decrypt(encryptedText: string, key: string): string;
  decryptAsync(encryptedText: string, key: string): Promise<string>;
  encryptAsync(plainText: string, key: string): Promise<string>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('TurboEncryption');
