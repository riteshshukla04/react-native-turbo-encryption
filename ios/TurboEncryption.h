#ifdef __cplusplus
#import "react-native-turbo-encryption.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNTurboEncryptionSpec.h"

@interface TurboEncryption : NSObject <NativeTurboEncryptionSpec>
#else
#import <React/RCTBridgeModule.h>

@interface TurboEncryption : NSObject <RCTBridgeModule>
#endif

@end
