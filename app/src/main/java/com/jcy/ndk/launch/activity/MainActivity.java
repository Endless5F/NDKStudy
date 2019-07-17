package com.jcy.ndk.launch.activity;

import android.support.design.widget.TabLayout;
import android.support.v4.view.ViewPager;
import android.os.Bundle;

import com.android.baselibrary.base.BaseToolbarCompatActivity;
import com.jcy.ndk.R;
import com.jcy.ndk.launch.adapter.MainPagerAdapter;
import com.jcy.ndk.launch.dataRes.MainData;

public class MainActivity extends BaseToolbarCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setMiddleTitle("首页(直播页面可运行)");

        TabLayout tabLayout = findViewById(R.id.tabLayout);
        ViewPager viewPager = findViewById(R.id.viewPager);

        viewPager.setAdapter(new MainPagerAdapter(
                getSupportFragmentManager(),this, MainData.mainVpFragment, MainData.mainTabTitle));
        tabLayout.setupWithViewPager(viewPager);//此方法就是让tablayout和ViewPager联动
        tabLayout.getTabAt(0).select();//设置第一个为选中
    }
}
