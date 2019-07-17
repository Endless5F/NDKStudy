#include <jni.h>
#include <stdlib.h>
#include <unistd.h>
#include <android/log.h>
#include "inc/fmod.hpp"
#include "com_jcy_ndk_nativeC_qqvoice_AudioProcess.h"
extern "C"
using namespace FMOD

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"jcy",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"jcy",FORMAT,##__VA_ARGS__);

#define MODE_NORMAL 0
#define MODE_LUOLI 1
#define MODE_DASHU 2
#define MODE_JINGSONG 3
#define MODE_GAOGUAI 4
#define MODE_KONGLING 5

JNIEXPORT ;void JNICALL Java_com_jcy_ndk_nativeC_qqvoice_AudioProcess_fix
        (JNIEnv *env, jclass jcls, jstring path_jstr, jint mode) {
    const char *path = env->GetStringUTFChars(path_jstr, NULL);

    System *system = NULL;
    Sound *sound = NULL;
    Channel *channel;
    DSP *dsp = NULL;
    float frequency = 0;
    bool isPlaying = true;
    LOGI("%s", path);
    try {
        FMOD::System_Create(&system);
        // 一个声音最多允许32个通道播放
        system->init(32, FMOD_INIT_NORMAL, NULL);

        //创建声音
        system->createSound(path, FMOD_DEFAULT, NULL, &sound);
        switch (mode) {
            case MODE_NORMAL:
                //原生播放
                system->playSound(sound, 0, false, &channel);
//                system->update();
                break;
            case MODE_LUOLI:
                //萝莉
                //DSP digital signal process
                //dsp -> 音效 创建fmod中预定义好的音效
                //FMOD_DSP_TYPE_PITCHSHIFT dsp，提升或者降低音调用的一种音效
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                //设置音调的参数
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 2.5);
                system->playSound(sound, 0, false, &channel);
                //添加到channel
                channel->addDSP(0,dsp);
                LOGI("%s","fix luoli");
                break;
            case MODE_JINGSONG:
                //惊悚
                system->createDSPByType(FMOD_DSP_TYPE_TREMOLO,&dsp);
                dsp->setParameterFloat(FMOD_DSP_TREMOLO_SKEW, 0.5);
                system->playSound(sound, 0, false, &channel);
                channel->addDSP(0,dsp);
                break;
            case MODE_DASHU:
                //大叔
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT,&dsp);
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH,0.8);

                system->playSound(sound, 0, false, &channel);
                //添加到channel
                channel->addDSP(0,dsp);
                LOGI("%s","fix dashu");
                break;
            case MODE_GAOGUAI:
                //搞怪
                //提高说话的速度
                system->playSound(sound, 0, false, &channel);
                channel->getFrequency(&frequency);
                frequency = frequency * 1.6;
                channel->setFrequency(frequency);
                LOGI("%s","fix gaoguai");
                break;
            case MODE_KONGLING:
                //空灵
                system->createDSPByType(FMOD_DSP_TYPE_ECHO,&dsp);
                dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY,300);
                dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK,20);
                system->playSound(sound, 0, false, &channel);
                channel->addDSP(0,dsp);
                LOGI("%s","fix kongling");
                break;
            default:
                break;
        }


    } catch (...) {
        LOGE("%s", "发生异常");
        goto end;
    }
    system->update();

    // 检查是否播放完成
    //释放资源
    //单位是微秒
    //每秒钟判断下是否在播放
    while (isPlaying) {
        channel->isPlaying(&isPlaying);
        usleep(1000 * 5);
    }

    end:
    env->ReleaseStringUTFChars(path_jstr, path);
    sound->release();
    system->close();
    system->release();
}