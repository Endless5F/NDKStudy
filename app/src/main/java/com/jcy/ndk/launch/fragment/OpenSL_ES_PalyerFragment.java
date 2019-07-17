package com.jcy.ndk.launch.fragment;

import android.os.Bundle;
import android.os.Environment;
import android.view.LayoutInflater;
import android.view.Surface;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;

import com.android.baselibrary.base.BaseFragment;
import com.jcy.ndk.R;
import com.jcy.ndk.launch.widget.VideoView;
import com.jcy.ndk.nativeC.ffmpeg.FFmpegPalyer;
import com.jcy.ndk.nativeC.ffmpeg.OpenSL_ES_AudioPlayer;

import java.io.File;

public class OpenSL_ES_PalyerFragment extends BaseFragment implements View.OnClickListener {

    private EditText et_file;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_opensl_es, container, false);
        initView(view);
        return view;
    }

    private void initView(View view) {
        view.findViewById(R.id.opensl_es).setOnClickListener(this);
        et_file = (EditText) view.findViewById(R.id.et_file);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.opensl_es:
                new Thread(){
                    public void run() {
                        String fileName = et_file.getText().toString();
                        File file = new File(Environment.getExternalStorageDirectory(),fileName);
                        OpenSL_ES_AudioPlayer.play(file.getAbsolutePath());
                    }
                }.start();
                break;
        }
    }
}
