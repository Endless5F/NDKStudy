package com.jcy.ndk.nativeC.basic;

// 增量更新
public class NDKFileUtils {
    // 拆分分件
    public native static void split(String path,String path_pattern, int count);
    // 合并文件
    public native static void patch(String path_pattern,int count,String merge_path);

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
