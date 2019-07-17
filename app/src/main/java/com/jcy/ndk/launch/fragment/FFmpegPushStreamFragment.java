package com.jcy.ndk.launch.fragment;

import android.os.Bundle;
import android.os.Environment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;

import com.android.baselibrary.base.BaseFragment;
import com.jcy.ndk.R;
import com.jcy.ndk.nativeC.ffmpeg.FFmpegPalyer;

public class FFmpegPushStreamFragment extends BaseFragment implements View.OnClickListener {

    private EditText et_input;
    private EditText et_output;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_ffmpeg_push_stream, container, false);
        initView(view);
        return view;
    }

    private void initView(View view) {
        et_input = view.findViewById(R.id.et_input);
        et_output = view.findViewById(R.id.et_output);
        view.findViewById(R.id.button_start).setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        String inputurl = Environment.getExternalStorageDirectory().getPath() + "/" + et_input.getText().toString();
        String outputurl = et_output.getText().toString();
        FFmpegPalyer.push(inputurl, outputurl);
    }
}
