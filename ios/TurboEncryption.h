//
//  TurboEncryption.h
//  react-native-turbo-encryption
//
//  Created by Ritesh Shukla on 25.11.24.
//

#ifdef __cplusplus
#import "AESWrapper.hpp"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNTurboEncryptionSpec.h"

@interface TurboEncryption : NSObject <NativeTurboEncryptionSpec>
#else
#import <React/RCTBridgeModule.h>

@interface TurboEncryption : NSObject <RCTBridgeModule>
#endif

@end
