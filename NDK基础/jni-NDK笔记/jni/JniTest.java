package com.jcy.jni;

import java.sql.Date;
import java.util.Random;
import java.util.UUID;

public class JniTest {
	public native String getString2FromC();
	public native static String getStringFromC();
	
	//Access the property and return the modified property content
	public String key = "jcy";
	public native String accessField();
	public static int count = 9;
	public native void accessStaticField();
	
	public native void accessMethod();
	public native void accessStaticMethod();
	
	public native Date accessConstructor();
	
	public native void accessNonvirtualMethod();
	
	public native String chineseChars(String in);
	
	public native void giveArray(int[] array);
	
	public native int[] getArray(int len);
	
	public native void localRef();
	
	public native void createGlobalRef();
	
	public native String getGlobalRef();
	
	public native void deleteGlobalRef();
	
	public native void exeception();
	
	public native void cached();
	
	public native static void initIds();
	
	static{
		System.loadLibrary("jni_01");
	}
	
	public static void main(String[] args) {
		String text = getStringFromC();
		
		JniTest t = new JniTest();
		String text2 = t.getString2FromC();
		System.out.println(text2);
		
		System.out.println("key修改前："+t.key);
		t.accessField();
		System.out.println("key修改后："+t.key);
		
		System.out.println("count修改前："+count);
		t.accessStaticField();
		System.out.println("count修改后："+count);
		
		t.accessMethod();
		t.accessStaticMethod();
		
		t.accessConstructor();
		
		t.accessNonvirtualMethod();
		
		System.out.println(t.chineseChars("宋喆"));
		
		int[] array = {9,100,10,37,5,10};
		//The sorting
		t.giveArray(array);
		for (int i : array) {
			System.out.println(i);
		}
		
		//----------
		int[] array2 = t.getArray(10);
		System.out.println("------------");
		for (int i : array2) {
			System.out.println(i);
		}
		
		System.out.println("------08-17------");
		t.createGlobalRef();
		System.out.println(t.getGlobalRef());
		//Release when you're done
		t.deleteGlobalRef();
		System.out.println("释放完了...");
		//System.out.println(t.getGlobalRef());
		
		try {
			t.exeception();						
		} catch (Exception e) {
			System.out.println("发生异常："+e.getMessage());
		}
		
		System.out.println("--------异常发生之后-------");
		
		try {
			t.exeception();
		} catch (Exception e) {
			//e.printStackTrace();
			System.out.println(e.getMessage());
		}
		
		//Keep calling the cached method
		for (int i = 0; i < 100; i++) {
			t.cached();
		}
	}
	
	//Generates a random number within the specified range
	public int genRandomInt(int max){
		System.out.println("genRandomInt 执行了...");
		return new Random().nextInt(max); 
	}
		
	//Produces a UUID string
	public static String getUUID(){
		return UUID.randomUUID().toString();
	}
}
