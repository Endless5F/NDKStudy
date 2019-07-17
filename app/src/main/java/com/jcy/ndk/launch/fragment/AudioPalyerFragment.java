package com.jcy.ndk.launch.fragment;

import android.os.Bundle;
import android.os.Environment;
import android.view.LayoutInflater;
import android.view.Surface;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

import com.android.baselibrary.base.BaseFragment;
import com.jcy.ndk.R;
import com.jcy.ndk.launch.widget.VideoView;
import com.jcy.ndk.nativeC.ffmpeg.FFmpegPalyer;

import java.io.File;

public class AudioPalyerFragment extends BaseFragment implements View.OnClickListener {

    private VideoView videoView;
    private Spinner sp_video;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_ffmpeg_palyer, container, false);
        initView(view);
        return view;
    }

    private void initView(View view) {
        view.findViewById(R.id.mPlayBt).setOnClickListener(this);
        videoView = view.findViewById(R.id.video_view);
        sp_video = view.findViewById(R.id.sp_video);
        //多种格式的视频列表
        String[] videoArray = getResources().getStringArray(R.array.video_list);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(getContext(),
                android.R.layout.simple_list_item_1, android.R.id.text1, videoArray);
        sp_video.setAdapter(adapter);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.mPlayBt:
                String input = new File(Environment.getExternalStorageDirectory(),"Justin Bieber - Boyfriend.mp3").getAbsolutePath();
                String output = new File(Environment.getExternalStorageDirectory(),"Justin Bieber - Boyfriend.pcm").getAbsolutePath();
                new FFmpegPalyer().sound(input, output);
                break;
        }
    }
}
