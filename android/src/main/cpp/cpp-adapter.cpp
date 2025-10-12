#include <jni.h>
#include "turboencryptionOnLoad.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return margelo::nitro::turboencryption::initialize(vm);
}
