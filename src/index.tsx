const TurboEncryption = require('./NativeTurboEncryption').default;

export function multiply(a: number, b: number): number {
  return TurboEncryption.multiply(a, b);
}
