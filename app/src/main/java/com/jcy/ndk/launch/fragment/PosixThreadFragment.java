package com.jcy.ndk.launch.fragment;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.android.baselibrary.base.BaseFragment;
import com.jcy.ndk.R;
import com.jcy.ndk.nativeC.basic.PosixThread;

public class PosixThreadFragment extends BaseFragment implements View.OnClickListener {

    private PosixThread p;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_posix_thread, container, false);
        initView(view);
        return view;
    }

    /**
     * 运行此页逻辑，需要修改 (保证一个程序中只有一处使用 JNI_OnLoad 方法)
     *  1./jni/basic/PThreadCPP.c --》 JNI_OnLoad1 为 JNI_OnLoad
     *  2./jni/livetv/LiveTv_Push_Stream.c --》 JNI_OnLoad 为 JNI_OnLoad1
     * */
    private void initView(View view) {
//        p = new PosixThread();
//        p.init();
        view.findViewById(R.id.startThread).setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
//        p.pthread();

//        LogUtil.d("jcy", PosixThread.get());
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
//        p.destroy();
    }
}
