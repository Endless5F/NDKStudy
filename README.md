# NDKStudy

#### 介绍
android NDK 学习

#### 软件架构
软件架构说明


#### 安装教程
1. 初始化工程
    
    创建jni jniLibs目录  创建Android.mk Application.mk  build.gradle配置

2. 无需命令行处理：
    File-》Setting-》Tools-》External Tools-》+
        
        javah-jni
            Program ：$JDKPath$/bin/javah
            Arguments ：-jni -encoding UTF-8 -d $ModuleFileDir$\src\main\jni $FileClass$
            Working directory ：$ModuleFileDir$\src\main\java
        
        ndk-build
            Program ：(本地ndk路径)E:\AndroidTools\AndroidSdk\ndk-bundle\build\ndk-build.cmd
            Arguments ：空
            Working directory ：$ModuleFileDir$\src\main
        
        javap-s
            Program ：(本地jdk路径)E:\JavaKotlinTools\JavaJdk\java\bin\javap.exe
            Arguments ：-classpath $ModuleFileDir$/build/intermediates/classes/debug -s $FileClass$
            Working directory ：$ModuleFileDir$
#### 使用说明
1. javah-jni 和 ndk-build用法：
    
    javah-jni：
        在写有native方法的类上右键-》External Tools-》javah-jni 即会在src/main/jni 目录下产生.h头文件
    
    ndk-build：
        在src/main/jni 目录上右键-》External Tools-》ndk-build 即可产生libs和obj目录，将obj目录下所有复制到jniLibs目录下，即可使用
    
    javap-s：
        在写有native方法的类上右键-》External Tools-》javap-s 即会在Terminal命令行中生成所有ID

异常说明：
    Applicaiton.mk 中的相关配置  
    APP_STL:=gnustl_static 改为 APP_STL:= c++_static
        ,否则报如下异常：APP_STL gnustl_shared is no longer supported

#### 一些基础知识和问题：
1. Android 设备的CPU类型(通常称为”ABIs”)

        armeabiv-v7a: 第7代及以上的 ARM 处理器。2011年15月以后的生产的大部分Android设备都使用它.
        arm64-v8a: 第8代、64位ARM处理器，很少设备，三星 Galaxy S6是其中之一。
        armeabi: 第5代、第6代的ARM处理器，早期的手机用的比较多。
        x86: 平板、模拟器用得比较多。
        x86_64: 64位的平板。
2. 问题描述
        
        关于华为Mate8手机Android 6.0系统运行刚刚提测的版本时，出现闪退的bug，而小米4手机Android 6.0系统却没有出现任何bug，运行良好。
        后来查看本人相关模块的代码，发现本人集成版本相关模块的代码和分支版本相关模块的代码是一模一样的，那就是说本人把分支代码合并到主干代码是没有问题的，所以去查看主干代码的问题。
        经过一番查看提交日志，发现有位同事再我合并代码之前，提交了一个关于友盟推送的so文件的记录，原来他加入了一个arm64-v8a文件夹，里面有友盟推送的arm64-v8a的so库文件。而其他的so库文本却没有arm64-v8a对应的版本。
        
        通过百度查到知乎有一段关于arm64-v8a的解释：
            arm64-v8a是可以向下兼容的，但前提是你的项目里面没有arm64-v8a的文件夹，如果你有两个文件夹armeabi和arm64-v8a，两个文件夹，armeabi里面有a.so 和 b.so,arm64-v8a里面只有a.so，那么arm64-v8a的手机在用到b的时候发现有arm64-v8a的文件夹，发现里面没有b.so，就报错了，所以这个时候删掉arm64-v8a文件夹，这个时候手机发现没有适配arm64-v8a，就会直接去找armeabi的so库，所以要么你别加arm64-v8a,要么armeabi里面有的so库，arm64-v8a里面也必须有  
        发现原来华为 Mate 8手机是64位的操作系统，而小米 4 手机是32位的操作系统，所以小米 4 手机手机运行APP没bug,而华为 Mate 8手机运行APP出现闪退bug。