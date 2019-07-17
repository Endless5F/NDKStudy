package com.jcy.ndk.nativeC.liveTv;

import com.jcy.ndk.liveTv.listener.LiveStateChangeListener;

public class PushNative {
	
	public static final int CONNECT_FAILED = 101;
	public static final int INIT_FAILED = 102;
	
	LiveStateChangeListener liveStateChangeListener;
	
	/**
	 * 接收Native层抛出的错误
	 * @param code
	 */
	public void throwNativeError(int code){
		if(liveStateChangeListener != null){
			liveStateChangeListener.onError(code);
		}
	}
	
	
	public native void startPush(String url);
	
	public native void stopPush();
	
	public native void release();
	
	/**
	 * 设置视频参数
	 * @param width
	 * @param height
	 * @param bitrate
	 * @param fps
	 */
	public native void setVideoOptions(int width, int height, int bitrate, int fps);
	
	/**
	 * 设置音频参数
	 * @param sampleRateInHz
	 * @param channel
	 */
	public native void setAudioOptions(int sampleRateInHz, int channel);
	

	/**
	 * 发送视频数据
	 * @param data
	 */
	public native void fireVideo(byte[] data);
	
	/**
	 * 发送音频数据
	 * @param data
	 * @param len
	 */
	public native void fireAudio(byte[] data, int len);
	
	
	public void setLiveStateChangeListener(LiveStateChangeListener liveStateChangeListener) {
		this.liveStateChangeListener = liveStateChangeListener;
	}
	
	public void removeLiveStateChangeListener(){
		this.liveStateChangeListener = null;
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
