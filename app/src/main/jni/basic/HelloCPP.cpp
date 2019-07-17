#include <jni.h>
extern "C"
JNIEXPORT jstring JNICALL Java_com_jcy_ndk_nativeC_basic_HelloLibrary_sayHello(JNIEnv *env, jclass jcls) {
    //从 C++ 传字符串到 Java
    return env->NewStringUTF("Hello from C++");
}