//
//  onLoad.mm
//  feact-native-turbo-encryption
//
//  Created by Ritesh Shukla on 24.11.24.
//

#import "NativeTurboEncryptionTurboModule.h"
#import <Foundation/Foundation.h>
#import <ReactCommon/CxxTurboModuleUtils.h>

@interface OnLoad : NSObject
@end

@implementation OnLoad

+ (void)load {
  facebook::react::registerCxxModuleToGlobalModuleMap(
      std::string(facebook::react::NativeTurboEncryptionTurboModule::kModuleName),
      [&](std::shared_ptr<facebook::react::CallInvoker> jsInvoker) {
        return std::make_shared<facebook::react::NativeTurboEncryptionTurboModule>(jsInvoker);
      });
}

@end