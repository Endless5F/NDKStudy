package com.jcy.ndk.liveTv.pusher;

import android.app.Activity;
import android.hardware.Camera.CameraInfo;
import android.view.SurfaceHolder;
import android.view.SurfaceHolder.Callback;

import com.jcy.ndk.liveTv.listener.LiveStateChangeListener;
import com.jcy.ndk.liveTv.params.AudioParam;
import com.jcy.ndk.liveTv.params.VideoParam;
import com.jcy.ndk.nativeC.liveTv.PushNative;

public class LivePusher implements Callback {

    private SurfaceHolder surfaceHolder;
    private VideoPusher videoPusher;
    private AudioPusher audioPusher;
    private PushNative pushNative;

    public LivePusher(SurfaceHolder surfaceHolder, Activity activity) {
        this.surfaceHolder = surfaceHolder;
        surfaceHolder.addCallback(this);
        prepare(activity);
    }

    /**
     * 预览准备
     *
     * @param activity
     */
    private void prepare(Activity activity) {
        pushNative = new PushNative();

        //实例化视频推流器
        VideoParam videoParam = new VideoParam(480, 320, CameraInfo.CAMERA_FACING_BACK);
        videoPusher = new VideoPusher(surfaceHolder, videoParam, pushNative, activity);

        //实例化音频推流器
        AudioParam audioParam = new AudioParam();
        audioPusher = new AudioPusher(audioParam, pushNative, activity);
    }

    /**
     * 切换摄像头
     */
    public void switchCamera() {
        videoPusher.switchCamera();
    }

    /**
     * 开始推流
     *
     * @param url
     * @param liveStateChangeListener
     */
    public void startPush(String url, LiveStateChangeListener liveStateChangeListener) {
        videoPusher.startPush();
        audioPusher.startPush();
        pushNative.startPush(url);
        pushNative.setLiveStateChangeListener(liveStateChangeListener);
    }


    /**
     * 停止推流
     */
    public void stopPush() {
        videoPusher.stopPush();
        audioPusher.stopPush();
        pushNative.stopPush();
        pushNative.removeLiveStateChangeListener();
    }

    /**
     * 释放资源
     */
    private void release() {
        videoPusher.release();
        audioPusher.release();
        pushNative.release();
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {

    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        stopPush();
        release();
    }

}
