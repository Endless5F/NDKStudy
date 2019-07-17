package com.jcy.ndk.launch.fragment;

import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.android.baselibrary.base.BaseFragment;
import com.jcy.ndk.R;
import com.jcy.ndk.nativeC.qqvoice.AudioProcess;

import org.fmod.FMOD;

import java.io.File;

public class AudioProcessFragment extends BaseFragment implements View.OnClickListener {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_qqvoice, container, false);
        initView(view);
        return view;
    }

    private void initView(View view) {
        FMOD.init(getContext());
        view.findViewById(R.id.btn_normal).setOnClickListener(this);
        view.findViewById(R.id.btn_luoli).setOnClickListener(this);
        view.findViewById(R.id.btn_dashu).setOnClickListener(this);
        view.findViewById(R.id.btn_jingsong).setOnClickListener(this);
        view.findViewById(R.id.btn_gaoguai).setOnClickListener(this);
        view.findViewById(R.id.btn_kongling).setOnClickListener(this);
    }
    @Override
    public void onClick(View v) {
        String path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "drumloop.wav";
        Log.d("jcy", "mFix");
        switch (v.getId()) {
            case R.id.btn_normal:
                AudioProcess.fix(path, AudioProcess.MODE_NORMAL);
                break;

            case R.id.btn_luoli:
                AudioProcess.fix(path, AudioProcess.MODE_LUOLI);
                break;

            case R.id.btn_dashu:
                AudioProcess.fix(path, AudioProcess.MODE_DASHU);
                break;

            case R.id.btn_jingsong:
                AudioProcess.fix(path, AudioProcess.MODE_JINGSONG);
                break;

            case R.id.btn_gaoguai:
                AudioProcess.fix(path, AudioProcess.MODE_GAOGUAI);
                break;

            case R.id.btn_kongling:
                AudioProcess.fix(path, AudioProcess.MODE_KONGLING);
                break;

            default:
                break;
        }
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        FMOD.close();
    }
}
