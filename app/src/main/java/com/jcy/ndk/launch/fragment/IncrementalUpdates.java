package com.jcy.ndk.launch.fragment;

import android.os.Bundle;
import android.os.Environment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.android.baselibrary.base.BaseFragment;
import com.jcy.ndk.R;
import com.jcy.ndk.nativeC.basic.NDKFileUtils;

import java.io.File;

public class IncrementalUpdates extends BaseFragment implements View.OnClickListener {

    private String SD_CARD_PATH;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_incremental_pdates, container, false);
        initView(view);
        return view;
    }

    private void initView(View view) {
        SD_CARD_PATH = Environment.getExternalStorageDirectory().getAbsolutePath();
        view.findViewById(R.id.split).setOnClickListener(this);
        view.findViewById(R.id.patch).setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.split:
                // 增量更新 拆分
                String path = SD_CARD_PATH + File.separatorChar+ "NDKTestVideo.mp4";
                String path_pattern = SD_CARD_PATH + File.separatorChar+ "NDKTestVideo_%d.mp4";
                NDKFileUtils.split(path, path_pattern, 5);
                break;
            case R.id.patch:
                // 增量更新 合并
                String path_pattern1 = SD_CARD_PATH +File.separatorChar+ "NDKTestVideo_%d.mp4";
                String merge_path = SD_CARD_PATH +File.separatorChar+ "NDKTestVideo_Merge.mp4";
                NDKFileUtils.patch(path_pattern1, 5, merge_path);
                break;
        }
    }
}
