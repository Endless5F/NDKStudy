package com.jcy.bsdiff;

public class BsDiff {

	/**
	 * 差分
	 * 
	 * @param oldfile
	 * @param newfile
	 * @param patchfile
	 */
	public native static void diff(String oldfile, String newfile, String patchfile);

	static{
		// Windows
//		System.loadLibrary("bsdiff");
		// Linux
		System.load("/usr/xxx/apkupdate/bsdiff.so");
	}
}
