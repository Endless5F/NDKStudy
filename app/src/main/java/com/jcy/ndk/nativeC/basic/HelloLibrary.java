package com.jcy.ndk.nativeC.basic;

public class HelloLibrary {

    public String javap = "Test";

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
    //使用 native 关键字指示以原生代码形式实现的方法
    public static native String sayHello();
}
