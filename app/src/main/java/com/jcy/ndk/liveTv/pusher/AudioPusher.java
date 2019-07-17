package com.jcy.ndk.liveTv.pusher;

import android.Manifest;
import android.app.Activity;
import android.graphics.ImageFormat;
import android.hardware.Camera;
import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder.AudioSource;

import com.android.baselibrary.util.PermissionUtil;
import com.android.baselibrary.util.ToastUtil;
import com.jcy.ndk.liveTv.params.AudioParam;
import com.jcy.ndk.nativeC.liveTv.PushNative;

import java.io.IOException;

public class AudioPusher extends Pusher{

	private AudioParam audioParam;
	private AudioRecord audioRecord;
	private boolean isPushing = false;
	private int minBufferSize;
	private PushNative pushNative;
	private Activity mActivity;

	public AudioPusher(AudioParam audioParam, PushNative pushNative, Activity activity) {
		this.audioParam = audioParam;
		this.pushNative = pushNative;
		this.mActivity = activity;
		int channelConfig = audioParam.getChannel() == 1 ? 
				AudioFormat.CHANNEL_IN_MONO : AudioFormat.CHANNEL_IN_STEREO; 
		//最小缓冲区大小
		minBufferSize = AudioRecord.getMinBufferSize(audioParam.getSampleRateInHz(), channelConfig, AudioFormat.ENCODING_PCM_16BIT);
		audioRecord = new AudioRecord(AudioSource.MIC, 
				audioParam.getSampleRateInHz(), 
				channelConfig, 
				AudioFormat.ENCODING_PCM_16BIT, minBufferSize);
	}
	

	@Override
	public void startPush() {
		isPushing = true;
		pushNative.setAudioOptions(audioParam.getSampleRateInHz(), audioParam.getChannel());
		//启动一个录音子线程
		Thread thread = new Thread(new AudioRecordTask());
		PermissionUtil.requestPermission(mActivity, new PermissionUtil.IPermissionListener() {
			@Override
			public void permissionGranted() {
				thread.start();
			}

			@Override
			public void permissionDenied() {
				ToastUtil.showShortToast("权限被拒绝");
			}
		},"权限被拒绝,请设置应用权限", Manifest.permission.RECORD_AUDIO
				, Manifest.permission.WRITE_EXTERNAL_STORAGE, Manifest.permission.READ_EXTERNAL_STORAGE);
	}

	@Override
	public void stopPush() {
		isPushing = false;
		audioRecord.stop();
	}
	
	@Override
	public void release() {
		if(audioRecord != null){
			audioRecord.release();
			audioRecord = null;
		}
	}

	class AudioRecordTask implements Runnable{

		@Override
		public void run() {
			//开始录音
			audioRecord.startRecording();
			
			while(isPushing){
				//通过AudioRecord不断读取音频数据
				byte[] buffer = new byte[minBufferSize];
				int len = audioRecord.read(buffer, 0, buffer.length);
				if(len > 0){
					//传给Native代码，进行音频编码
					pushNative.fireAudio(buffer, len);
				}
			}
		}
		
	}

}
