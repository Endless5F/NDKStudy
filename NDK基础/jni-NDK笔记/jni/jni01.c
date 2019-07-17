#define _CRT_SECURE_NO_WARNINGS
#include "com_jcy_jni_JniTest.h"
#include <string.h>
#include <stdlib.h>

JNIEXPORT jstring JNICALL Java_com_jcy_jni_JniTest_getStringFromC(JNIEnv * env, jclass jclass){
	//将C字符串转成Java字符串
	return (*env)->NewStringUTF(env,"C String");
}

JNIEXPORT jstring JNICALL Java_com_jcy_jni_JniTest_getString2FromC(JNIEnv * env, jobject jobj){
	return (*env)->NewStringUTF(env, "C String");
}

//1.访问成员属性（非静态）
//修改属性key
JNIEXPORT jstring JNICALL Java_com_jcy_jni_JniTest_accessField
		(JNIEnv * env, jobject jobj){
	//jobj是t对象，JniTest.class
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//jfieldID
	//属性名称，属性签名
	jfieldID fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");

	//jcy >> super jcy
	//获取key属性的值
	//Get<Type>Field
	jstring jstr = (*env)->GetObjectField(env, jobj, fid);
	printf("jstr:%#x\n", &jstr);

	//jstring -> c字符串
	jboolean isCopy = NULL;// 若isCopy为JNI_TRUE则代表复制了
	// ，否则为JNI_FALSE则代表没复制，复不复制为GetStringUTFChars函数内部决定
	char *c_str = (*env)->GetStringUTFChars(env, jstr, &isCopy);
	//拼接得到新的字符串
	char text[20] = "super ";
	strcat(text, c_str);

	//c字符串 ->jstring
	jstring new_jstr = (*env)->NewStringUTF(env, text);

	//修改key
	//Set<Type>Field
	(*env)->SetObjectField(env, jobj, fid, new_jstr);

	printf("new_jstr:%#x\n", &new_jstr);

	// 使用了GetStringUTFChars 一定要记得释放
	(*env)->ReleaseStringUTFChars(env, jstr, c_str);

	return new_jstr;
}

//访问静态属性
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_accessStaticField
		(JNIEnv * env, jobject jobj){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//jfieldID
	jfieldID fid = (*env)->GetStaticFieldID(env, cls, "count", "I");
	//GetStatic<Type>Field
	jint count = (*env)->GetStaticIntField(env, cls, fid);
	count++;
	//修改
	//SetStatic<Type>Field
	(*env)->SetStaticIntField(env, cls, fid, count);
}

JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_accessMethod
		(JNIEnv * env, jobject jobj){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//jmethodID
	jmethodID mid = (*env)->GetMethodID(env, cls, "genRandomInt", "(I)I");
	//调用
	//Call<Type>Method
	jint random = (*env)->CallIntMethod(env, jobj, mid, 200);
	printf("random num:%ld", random);

}

JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_accessStaticMethod
		(JNIEnv * env, jobject jobj){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//jmethodID
	jmethodID mid = (*env)->GetStaticMethodID(env, cls, "getUUID", "()Ljava/lang/String;");

	//调用
	//CallStatic<Type>Method
	jstring uuid = (*env)->CallStaticObjectMethod(env, cls, mid);

	//随机文件名称 uuid.txt
	//jstring -> char*
	//isCopy JNI_FALSE，代表java和c操作的是同一个字符串
	char *uuid_str = (*env)->GetStringUTFChars(env, uuid, JNI_FALSE);
	//拼接
	char filename[100];
	sprintf(filename, "D://%s.txt", uuid_str);
	FILE *fp = fopen(filename, "w");
	fputs("i love jcy", fp);
	fclose(fp);
}

//访问构造方法
//使用java.util.Date产生一个当前的时间戳
JNIEXPORT jobject JNICALL Java_com_jcy_jni_JniTest_accessConstructor
		(JNIEnv * env, jobject jobj){
	jclass cls = (*env)->FindClass(env, "java/util/Date");
	//jmethodID
	jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
	//实例化一个Date对象
	jobject date_obj = (*env)->NewObject(env, cls, constructor_mid);
	//调用getTime方法
	jmethodID mid = (*env)->GetMethodID(env, cls, "getTime", "()J");
	jlong time = (*env)->CallLongMethod(env, date_obj, mid);

	printf("\ntime:%lld\n", time);

	return date_obj;
}

//调用父类的方法
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_accessNonvirtualMethod
		(JNIEnv * env, jobject jobj){
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//获取man属性（对象）
	jfieldID fid = (*env)->GetFieldID(env, cls, "human", "Lcom/jcy/jni/Human;");
	//获取
	jobject human_obj = (*env)->GetObjectField(env, jobj, fid);

	//执行sayHi方法
	jclass human_cls = (*env)->FindClass(env, "com/jcy/jni/Human"); //注意：传父类的名称
	jmethodID mid = (*env)->GetMethodID(env, human_cls, "sayHi", "()V");

	//执行
	//(*env)->CallObjectMethod(env, human_obj, mid);
	//调用的父类的方法
	(*env)->CallNonvirtualObjectMethod(env, human_obj, human_cls, mid);
}

//中文问题
JNIEXPORT jstring JNICALL Java_com_jcy_jni_JniTest_chineseChars
		(JNIEnv * env, jobject jobj, jstring in){
	//输出
	//char *c_str = (*env)->GetStringUTFChars(env, in, JNI_FALSE);
	//printf("%s\n",c_str);

	//c -> jstring
	char *c_str = "马蓉与宋江";
	//char c_str[] = "马蓉与宋喆";
	//jstring jstr = (*env)->NewStringUTF(env, c_str);
	//执行String(byte bytes[], String charsetName)构造方法需要的条件
	//1.jmethodID
	//2.byte数组
	//3.字符编码jstring

	jclass str_cls = (*env)->FindClass(env, "java/lang/String");
	jmethodID constructor_mid = (*env)->GetMethodID(env, str_cls, "<init>", "([BLjava/lang/String;)V");

	//jbyte -> char
	//jbyteArray -> char[]
	jbyteArray bytes = (*env)->NewByteArray(env, strlen(c_str));
	//byte数组赋值
	//0->strlen(c_str)，从头到尾
	//对等于，从c_str这个字符数组，复制到bytes这个字符数组
	(*env)->SetByteArrayRegion(env, bytes, 0, strlen(c_str), c_str);

	//字符编码jstring
	jstring charsetName = (*env)->NewStringUTF(env, "GB2312");

	//调用构造函数，返回编码之后的jstring
	return (*env)->NewObject(env, str_cls, constructor_mid, bytes, charsetName);
}

int compare(int *a, int *b){
	return (*a) - (*b);
}

//传入
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_giveArray
		(JNIEnv * env, jobject jobj, jintArray arr){
	//jintArray -> jint指针 -> c int 数组
	jint *elems = (*env)->GetIntArrayElements(env, arr, NULL);
	//printf("%#x,%#x\n", &elems, &arr);

	//数组的长度
	int len = (*env)->GetArrayLength(env, arr);
	//排序
	qsort(elems, len, sizeof(jint), compare);

	//同步
	//mode
	//0, Java数组进行更新，并且释放C/C++数组
	//JNI_ABORT, Java数组不进行更新，但是释放C/C++数组
	//JNI_COMMIT，Java数组进行更新，不释放C/C++数组（函数执行完，数组还是会释放）
	(*env)->ReleaseIntArrayElements(env, arr, elems, JNI_COMMIT);
}

//返回数组
JNIEXPORT jintArray JNICALL Java_com_jcy_jni_JniTest_getArray
		(JNIEnv * env, jobject jobj, jint len){
	//创建一个指定大小的数组

	jintArray jint_arr = (*env)->NewIntArray(env, len);
	jint *elems = (*env)->GetIntArrayElements(env, jint_arr, NULL);
	int i = 0;
	for (; i < len; i++){
		elems[i] = i;
	}

	//同步
	(*env)->ReleaseIntArrayElements(env, jint_arr, elems, 0);

	return jint_arr;
}

//DeleteLocalRef : JNI 引用变量
//引用类型：局部引用和全局引用
//作用：在JNI中告知虚拟机何时回收一个JNI变量

//局部引用，通过DeleteLocalRef手动释放对象
//1.访问一个很大的java对象，使用完之后，还要进行复杂的耗时操作
//2.创建了大量的局部引用，占用了太多的内存，而且这些局部引用跟后面的操作没有关联性

//模拟：循环创建数组
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_localRef
		(JNIEnv * env, jobject jobj){
	int i = 0;
	for (; i < 5; i++){
		//创建Date对象
		jclass cls = (*env)->FindClass(env, "java/util/Date");
		jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
		jobject obj = (*env)->NewObject(env, cls, constructor_mid);
		//此处省略一百行代码...

		//不在使用jobject对象了
		//通知垃圾回收器回收这些对象
		(*env)->DeleteLocalRef(env, obj);
		//此处省略一百行代码...
	}
}

//全局引用
//共享(可以跨多个线程)，手动控制内存使用
jstring global_str;

//创建全局引用
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_createGlobalRef
		(JNIEnv * env, jobject jobj){
	jstring obj = (*env)->NewStringUTF(env, "jni development is powerful!");
	global_str = (*env)->NewGlobalRef(env, obj);
	global_str = (*env)->NewGlobalRef(env, obj);
}

//获取全局引用
JNIEXPORT jstring JNICALL Java_com_jcy_jni_JniTest_getGlobalRef
		(JNIEnv * env, jobject jobj){
	return global_str;
}

//释放全局引用
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_deleteGlobalRef
		(JNIEnv * env, jobject jobj){
	(*env)->DeleteGlobalRef(env, global_str);
}

//弱全局引用
//节省内存，在内存不足时可以是释放所引用的对象
//可以引用一个不常用的对象，如果为NULL，临时创建
//创建：NewWeakGlobalRef,销毁：DeleteGlobalWeakRef

//异常处理
//1.保证Java代码可以运行
//2.补救措施保证C代码继续运行

//JNI自己抛出Throwable异常
//用户通过ThrowNew抛出的异常，可以在Java层捕捉
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_exeception
		(JNIEnv * env, jobject jobj){
	jclass cls = (*env)->GetObjectClass(env, jobj);
	jfieldID fid = (*env)->GetFieldID(env, cls, "key2", "Ljava/lang/String;");
	//检测是否发生Java异常
	jthrowable exception = (*env)->ExceptionOccurred(env);
	if (exception != NULL){
		//让Java代码可以继续运行
		//清空异常信息
		(*env)->ExceptionClear(env);

		//补救措施
		fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
	}

	//获取属性的值
	jstring jstr = (*env)->GetObjectField(env, jobj, fid);
	char *str = (*env)->GetStringUTFChars(env, jstr, NULL);

	//对比属性值是否合法
	if (_stricmp(str, "super jcy") != 0){
		//认为抛出异常，给Java层处理
		jclass newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, newExcCls, "key's value is invalid!");
	}
}

//缓存策略
//static jfieldID key_id
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_cached
		(JNIEnv * env, jobject jobj){
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//获取jfieldID只获取一次
	//局部静态变量
	static jfieldID key_id = NULL;
	if (key_id == NULL){
		key_id = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
		printf("--------GetFieldID-------\n");
	}
}

//初始化全局变量，动态库加载完成之后，立刻缓存起来
jfieldID key_fid;
jmethodID random_mid;
JNIEXPORT void JNICALL Java_com_jcy_jni_JniTest_initIds
		(JNIEnv * env, jclass jcls){
	key_fid = (*env)->GetFieldID(env, jcls, "key", "Ljava/lang/String;");
	random_mid = (*env)->GetMethodID(env, jcls, "genRandomInt", "(I)I");
}