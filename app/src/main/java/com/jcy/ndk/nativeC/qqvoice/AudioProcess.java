package com.jcy.ndk.nativeC.qqvoice;

public class AudioProcess {
    //音效的类型
    public static final int MODE_NORMAL = 0;
    public static final int MODE_LUOLI = 1;
    public static final int MODE_DASHU = 2;
    public static final int MODE_JINGSONG = 3;
    public static final int MODE_GAOGUAI = 4;
    public static final int MODE_KONGLING = 5;

    /**
     * 音效处理
     *
     * @param path
     * @param type
     */
    public native static void fix(String path, int type);

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
