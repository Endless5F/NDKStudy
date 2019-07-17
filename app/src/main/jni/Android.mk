# 构建系统提供的宏函数 my-dir 将返回当前目录（包含 Android.mk 文件本身的目录）的路径，基本上是固定的，不需要去动
LOCAL_PATH := $(call my-dir)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := fmod
LOCAL_SRC_FILES := qqvoice/libfmod.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := fmodL
LOCAL_SRC_FILES := qqvoice/libfmodL.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := libavcodec
LOCAL_SRC_FILES := ffmpeg/libavcodec.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := libavdevice
LOCAL_SRC_FILES := ffmpeg/libavdevice.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := libavfilter
LOCAL_SRC_FILES := ffmpeg/libavfilter.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := libavformat
LOCAL_SRC_FILES := ffmpeg/libavformat.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := libavutil
LOCAL_SRC_FILES := ffmpeg/libavutil.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := libswresample
LOCAL_SRC_FILES := ffmpeg/libswresample.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := libswscale
LOCAL_SRC_FILES := ffmpeg/libswscale.so
include $(PREBUILT_SHARED_LIBRARY)

#预加载三方库
include $(CLEAR_VARS)
LOCAL_MODULE := libyuv
LOCAL_SRC_FILES := ffmpeg/libyuv.so
include $(PREBUILT_SHARED_LIBRARY)

#faac
include $(CLEAR_VARS)
LOCAL_MODULE    := faac
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/livetv/faac/include
LOCAL_SRC_FILES := livetv/faac/libfaac.a
#把编译的源文件打印处理
$(info $(LOCAL_SRC_FILES))
include $(PREBUILT_STATIC_LIBRARY)

#x264
include $(CLEAR_VARS)
LOCAL_MODULE    := x264
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/livetv/x264/include
LOCAL_SRC_FILES := livetv/x264/libx264.a
$(info $(LOCAL_SRC_FILES))
include $(PREBUILT_STATIC_LIBRARY)

#rtmpdump
include $(CLEAR_VARS)
LOCAL_MODULE    := rtmpdump
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/livetv/rtmpdump/include
LOCAL_SRC_FILES := livetv/rtmpdump/librtmp.a
$(info $(LOCAL_SRC_FILES))
include $(PREBUILT_STATIC_LIBRARY)

#自己的so库配置
# 会清除很多 LOCAL_XXX 变量，不会清除 LOCAL_PATH，基本上是固定的，不需要去动
include $(CLEAR_VARS)
# 需要构建模块的名称，会自动生成相应的 libNDKSample.so 文件，每个模块名称必须唯一，且不含任何空格
LOCAL_MODULE := NDKSample
LOCAL_MODULE_TAGS := optional
include $(BUILD_MULTI_PREBUILT)

# 处理多个cpp文件
# wildcard函数获取$(LOCAL_PATH)目录也就是jni目录下的所有后缀名为cpp的文件,并把结果放到变量MY_CPP_LIST里
MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
# 获取jni/basic目录下的源文件,并追加到变量MY_CPP_LIST里
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/basic/*.c)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/basic/*.cpp)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/ffmpeg/*.c)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/ffmpeg/*.cpp)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/livetv/*.c)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/qqvoice/*.cpp)

# 包含要构建到模块中的 C 或 C++ 源文件列表
LOCAL_SRC_FILES := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)

# 预加载头文件
LOCAL_C_INCLUDES += $(LOCAL_PATH)/qqvoice/inc
# 指定这个模块里会用到哪些原生 API，详见：https://developer.android.google.cn/ndk/guides/stable_apis.html
##-landroid参数 for native windows
LOCAL_LDLIBS := -llog -landroid -lOpenSLES
#使用c++的异常处理
LOCAL_CPP_FEATURES := exceptions
# 添加依赖库
LOCAL_SHARED_LIBRARIES := fmod fmodL libavcodec libavdevice libavfilter libavformat libavutil libswresample libswscale libyuv x264 faac rtmpdump
# 帮助系统将所有内容连接到一起，固定的，不需要去动
include $(BUILD_SHARED_LIBRARY)