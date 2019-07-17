#include <jni.h>
#include <stdlib.h>
#include <stdio.h>

#include <android/log.h>

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"jcy",FORMAT,__VA_ARGS__)
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"jcy",FORMAT,__VA_ARGS__)

// 计算文件大小
long get_file_size(char *path) {
    FILE *file = fopen(path, "rb");
    fseek(file, 0, SEEK_END);
    return ftell(file);
}

JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_basic_NDKFileUtils_split
        (JNIEnv *env, jclass jcls, jstring jpath, jstring jpath_pattern, jint count) {
    // 需要分割文件的路径
    jboolean isCopy = NULL;
    const char *path = (*env)->GetStringUTFChars(env, jpath, isCopy);
    //分割子文件的pattern
    const char *path_pattern = (*env)->GetStringUTFChars(env, jpath_pattern, NULL);

    //得到分割之后的子文件的路径列表
    char **patches = malloc(sizeof(char *) * count);
    int i = 0;
    for (; i < count; ++i) {
        patches[i] = malloc(sizeof(char) * 100);
        sprintf(patches[i], path_pattern, (i + 1));
        LOGI("patch path:%s", patches[i]);
    }

    //不断读取path文件，循环写入file_num个文件中
    //	整除
    //	文件大小：90，分成9个文件，每个文件10
    //	不整除
    //	文件大小：110，分成9个文件，
    //	前(9-1)个文件为(110/(9-1))=13
    //	最后一个文件(110%(9-1))=6
    int filesize = get_file_size(path);
    FILE *fpr = fopen(path, "rb");
    // 整除
    if (filesize % count == 0) {
        // 单个文件大小
        int part = filesize / count;
        i = 0;
        //逐一写入不同的分割子文件中
        for (; i < count; i++) {
            FILE *fpw = fopen(patches[i], "wb");
            int j = 0;
            for (; j < part; j++) {
                //边读边写
                fputc(fgetc(fpr), fpw);
            }
            fclose(fpw);
        }
    } else {
        //不整除
        int part = filesize / (count - 1);
        i = 0;
        //逐一写入不同的分割子文件中
        for (; i < count - 1; i++) {
            FILE *fpw = fopen(patches[i], "wb");
            int j = 0;
            for (; j < part; j++) {
                //边读边写
                fputc(fgetc(fpr), fpw);
            }
            fclose(fpw);
        }
        //the last one
        FILE *fpw = fopen(patches[count - 1], "wb");
        i = 0;
        for (; i < filesize % (count - 1); i++) {
            fputc(fgetc(fpr), fpw);
        }
        fclose(fpw);
    }

    //关闭被分割的文件
    fclose(fpr);


    //释放
    i = 0;
    for (; i < count; i++) {
        free(patches[i]);
    }
    free(patches);
    // 释放
    (*env)->ReleaseStringUTFChars(env, jpath, path);
    (*env)->ReleaseStringUTFChars(env, jpath_pattern, path_pattern);
}


JNIEXPORT void JNICALL Java_com_jcy_ndk_nativeC_basic_NDKFileUtils_patch
        (JNIEnv *env, jclass jcls, jstring jpath_pattern, jint count, jstring jmerge_path) {
    //合并之后的文件
    const char *merge_path = (*env)->GetStringUTFChars(env, jmerge_path, NULL);
    //分割子文件的pattern
    const char *path_pattern = (*env)->GetStringUTFChars(env, jpath_pattern, NULL);

    //得到分割之后的子文件的路径列表
    char **patches = malloc(sizeof(char *) * count);
    int i = 0;
    for (; i < count; i++) {
        patches[i] = malloc(sizeof(char) * 100);
        //元素赋值
        //需要分割的文件：C://jcy/liuyan.png
        //子文件：C://jcy/liuyan_%d.png
        sprintf(patches[i], path_pattern, (i + 1));
        LOGI("patch path:%s", patches[i]);
    }

    FILE *fpw = fopen(merge_path, "wb");
    //把所有的分割文件读取一遍，写入一个总的文件中
    i = 0;
    for (; i < count; i++) {
        //每个子文件的大小
        int filesize = get_file_size(patches[i]);
        FILE *fpr = fopen(patches[i], "rb");
        int j = 0;
        for (; j < filesize; j++) {
            fputc(fgetc(fpr), fpw);
        }
        fclose(fpr);
    }
    fclose(fpw);

    //释放
    i = 0;
    for (; i < count; i++) {
        free(patches[i]);
    }
    free(patches);

    (*env)->ReleaseStringUTFChars(env, jpath_pattern, path_pattern);
    (*env)->ReleaseStringUTFChars(env, jmerge_path, merge_path);

}