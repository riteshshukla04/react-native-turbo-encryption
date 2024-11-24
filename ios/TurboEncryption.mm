
//
//  TurboEncryption.mm
//  react-native-turbo-encryption
//
//  Created by Ritesh Shukla on 25.11.24.
//



#import "TurboEncryption.h"

@implementation TurboEncryption
RCT_EXPORT_MODULE()

// Don't compile this code when we build for the old architecture.
#ifdef RCT_NEW_ARCH_ENABLED
- (NSString *)encrypt:(NSString *)encryptedHex key:(NSString *)key {
    // Convert NSString inputs to std::string
    std::string encryptedStdString = [encryptedHex UTF8String];
    std::string keyStdString = [key UTF8String];
    
    // Call the C++ function
    std::string decryptedStdString = encryptString(encryptedStdString, keyStdString);
    
    // Convert std::string result back to NSString
    NSString *result = [NSString stringWithUTF8String:decryptedStdString.c_str()];
    
    return result;
}

- (NSString *)decrypt:(NSString *)encryptedHex key:(NSString *)key {
    // Convert NSString inputs to std::string
    std::string encryptedStdString = [encryptedHex UTF8String];
    std::string keyStdString = [key UTF8String];
    
    // Call the C++ function
    std::string decryptedStdString = decryptString(encryptedStdString, keyStdString);
    
    // Convert std::string result back to NSString
    NSString *result = [NSString stringWithUTF8String:decryptedStdString.c_str()];
    
    return result;
}


- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
    return std::make_shared<facebook::react::NativeTurboEncryptionSpecJSI>(params);
}
#endif

@end
