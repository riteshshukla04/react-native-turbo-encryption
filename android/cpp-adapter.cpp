#include <jni.h>
#include "react-native-turbo-encryption.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_turboencryption_TurboEncryptionModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return turboencryption::multiply(a, b);
}
