/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jcy_ndk_nativeC_liveTv_PushNative */

#ifndef _Included_com_jcy_ndk_nativeC_liveTv_PushNative
#define _Included_com_jcy_ndk_nativeC_liveTv_PushNative
#ifdef __cplusplus
extern "C" {
#endif
#undef com_jcy_ndk_nativeC_liveTv_PushNative_CONNECT_FAILED
#define com_jcy_ndk_nativeC_liveTv_PushNative_CONNECT_FAILED 101L
#undef com_jcy_ndk_nativeC_liveTv_PushNative_INIT_FAILED
#define com_jcy_ndk_nativeC_liveTv_PushNative_INIT_FAILED 102L
/*
 * Class:     com_jcy_ndk_nativeC_liveTv_PushNative
 * Method:    startPush
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_liveTv_PushNative_startPush
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_jcy_ndk_nativeC_liveTv_PushNative
 * Method:    stopPush
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_liveTv_PushNative_stopPush
  (JNIEnv *, jobject);

/*
 * Class:     com_jcy_ndk_nativeC_liveTv_PushNative
 * Method:    release
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_liveTv_PushNative_release
  (JNIEnv *, jobject);

/*
 * Class:     com_jcy_ndk_nativeC_liveTv_PushNative
 * Method:    setVideoOptions
 * Signature: (IIII)V
 */
JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_liveTv_PushNative_setVideoOptions
  (JNIEnv *, jobject, jint, jint, jint, jint);

/*
 * Class:     com_jcy_ndk_nativeC_liveTv_PushNative
 * Method:    setAudioOptions
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_liveTv_PushNative_setAudioOptions
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_jcy_ndk_nativeC_liveTv_PushNative
 * Method:    fireVideo
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_liveTv_PushNative_fireVideo
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     com_jcy_ndk_nativeC_liveTv_PushNative
 * Method:    fireAudio
 * Signature: ([BI)V
 */
JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_liveTv_PushNative_fireAudio
  (JNIEnv *, jobject, jbyteArray, jint);

#ifdef __cplusplus
}
#endif
#endif