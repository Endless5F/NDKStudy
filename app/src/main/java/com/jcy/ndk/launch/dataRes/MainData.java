package com.jcy.ndk.launch.dataRes;

import android.support.v4.app.Fragment;

import com.jcy.ndk.launch.fragment.AudioPalyerFragment;
import com.jcy.ndk.launch.fragment.AudioProcessFragment;
import com.jcy.ndk.launch.fragment.FFmpegPushStreamFragment;
import com.jcy.ndk.launch.fragment.OpenSL_ES_PalyerFragment;
import com.jcy.ndk.launch.fragment.PosixThreadFragment;
import com.jcy.ndk.launch.fragment.VideoDecodeFragment;
import com.jcy.ndk.launch.fragment.VideoPalyerFragment;
import com.jcy.ndk.launch.fragment.IncrementalUpdates;
import com.jcy.ndk.launch.fragment.VideoPusherFragment;

import java.util.ArrayList;
import java.util.List;

public class MainData {
    public static List<String> mainTabTitle = new ArrayList<>();
    public static List<Fragment> mainVpFragment = new ArrayList<>();

    static {
        mainTabTitle.add("直播推流");
//        mainTabTitle.add("QQ语音变音");
//        mainTabTitle.add("增量更新");
//        mainTabTitle.add("FFmpeg视频解码");
//        mainTabTitle.add("FFmpeg视频解码播放");
//        mainTabTitle.add("FFmpeg音频解码播放");
//        mainTabTitle.add("C语言(Linux)JNI多线程");
//        mainTabTitle.add("OpenSL_ES音频播放");
//        mainTabTitle.add("FFmpeg视频推流");

        mainVpFragment.add(new VideoPusherFragment());
//        mainVpFragment.add(new AudioProcessFragment());
//        mainVpFragment.add(new IncrementalUpdates());
//        mainVpFragment.add(new VideoDecodeFragment());
//        mainVpFragment.add(new VideoPalyerFragment());
//        mainVpFragment.add(new AudioPalyerFragment());
//        mainVpFragment.add(new PosixThreadFragment());
//        mainVpFragment.add(new OpenSL_ES_PalyerFragment());
//        mainVpFragment.add(new FFmpegPushStreamFragment());
    }
}
