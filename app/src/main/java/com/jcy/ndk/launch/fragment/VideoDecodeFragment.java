package com.jcy.ndk.launch.fragment;

import android.os.Bundle;
import android.os.Environment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.android.baselibrary.base.BaseFragment;
import com.jcy.ndk.R;
import com.jcy.ndk.nativeC.ffmpeg.VideoDecodeUtils;

import java.io.File;

public class VideoDecodeFragment extends BaseFragment implements View.OnClickListener {

    private String SD_CARD_PATH;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_ffmpeg_decode, container, false);
        initView(view);
        return view;
    }

    private void initView(View view) {
        SD_CARD_PATH = Environment.getExternalStorageDirectory().getAbsolutePath();
        view.findViewById(R.id.decode).setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.decode:
                String input = new File(Environment.getExternalStorageDirectory(),"input.mp4").getAbsolutePath();
                String output = new File(Environment.getExternalStorageDirectory(),"output_1280x720_yuv420p.yuv").getAbsolutePath();
                new VideoDecodeUtils().decode(input, output);
                break;
        }
    }
}
