package com.jcy.ndk.nativeC.basic;

import java.util.UUID;

public class PosixThread {

    public native void pthread();

    public native void init();

    public native void destroy();

    public static String get() {
        return UUID.randomUUID().toString();
    }

    static {
        // 加载库，要将所有库加载进来，
        // 不管是不是该类中本地方法所要使用的，否则会因为库找不到而闪退
        System.loadLibrary("fmodL");
        System.loadLibrary("fmod");
        System.loadLibrary("avutil");
        System.loadLibrary("swresample");
        System.loadLibrary("avcodec");
        System.loadLibrary("avformat");
        System.loadLibrary("swscale");
        System.loadLibrary("avfilter");
        System.loadLibrary("avdevice");
        System.loadLibrary("NDKSample");
    }
}
