import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  encrypt(plainText: string, key: string): string;
  decrypt(encryptedText: string, key: string): string;
}

export default TurboModuleRegistry.getEnforcing<Spec>('TurboEncryption');
