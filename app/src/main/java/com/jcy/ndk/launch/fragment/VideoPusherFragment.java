package com.jcy.ndk.launch.fragment;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.view.LayoutInflater;
import android.view.SurfaceView;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.Toast;

import com.android.baselibrary.base.BaseFragment;
import com.jcy.ndk.R;
import com.jcy.ndk.liveTv.listener.LiveStateChangeListener;
import com.jcy.ndk.liveTv.pusher.LivePusher;
import com.jcy.ndk.nativeC.ffmpeg.VideoDecodeUtils;
import com.jcy.ndk.nativeC.liveTv.PushNative;

import java.io.File;

public class VideoPusherFragment extends BaseFragment implements View.OnClickListener, LiveStateChangeListener {

    static final String URL = "rtmp://39.106.174.241:1935/live/test";
    private LivePusher live;

    @SuppressLint("HandlerLeak")
    private Handler handler = new Handler(){
        public void handleMessage(android.os.Message msg) {
            switch (msg.what) {
                case PushNative.CONNECT_FAILED:
                    Toast.makeText(getContext(), "连接失败", Toast.LENGTH_SHORT).show();
                    //Log.d("jcy", "连接失败..");
                    break;
                case PushNative.INIT_FAILED:
                    Toast.makeText(getContext(), "初始化失败", Toast.LENGTH_SHORT).show();
                    break;
                default:
                    break;
            }
        }
    };

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_video_pusher, container, false);
        initView(view);
        return view;
    }

    private void initView(View view) {
        SurfaceView surfaceView =  view.findViewById(R.id.surface);
        //相机图像的预览
        live = new LivePusher(surfaceView.getHolder(), getActivity());
        view.findViewById(R.id.btn_push).setOnClickListener(this);
        view.findViewById(R.id.btn_camera_switch).setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.btn_push:
                Button btn = (Button)view;
                if(btn.getText().equals("开始直播")){
                    live.startPush(URL, this);
                    btn.setText("停止直播");
                }else{
                    live.stopPush();
                    btn.setText("开始直播");
                }
                break;
            case R.id.btn_camera_switch:
                live.switchCamera();
                break;
        }
    }

    @Override
    public void onError(int code) {
        handler.sendEmptyMessage(code);
    }
}
