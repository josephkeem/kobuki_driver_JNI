#include "KobukiWrap.h"
#include <iostream>

#include <kobuki_driver/kobuki.hpp>

JNIEXPORT void JNICALL Java_KobukiWrap_initialize(JNIEnv *env, jobject obj){
	std::cout << "kobuki constructor" << std::endl;
	try{
    	kobuki::Kobuki *inst = new kobuki::Kobuki();
		// set the native handle
		jlong handle = reinterpret_cast<jlong>(inst);
		jclass c = env->GetObjectClass(obj);
		// J is the type signature for long:
		jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
		env->SetLongField(obj, handleField, handle);
	}catch (std::bad_alloc & ba) {
		std::cerr << "bad_alloc caught: " << ba.what();
	}
}

JNIEXPORT void JNICALL Java_KobukiWrap_init(JNIEnv *env, jobject obj, jlong paramHandle){
	std::cout << "kobuki init()" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
    kobuki::Parameters *p = reinterpret_cast<kobuki::Parameters *>(paramHandle);
	try{
		std::cout << "before init(p)" << std::endl;
		k->init(*p);
		std::cout << "after init(p)" << std::endl;
	} catch (int e) {
		std::cout << "ERROR - C++ side" << std::endl;
	}
	return;
}

JNIEXPORT void JNICALL Java_KobukiWrap_setBaseControl(JNIEnv *env, jobject obj, jdouble linearV, jdouble angularV) {
	std::cout << "In setBaseControl()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	k->setBaseControl(linearV, angularV);
	return;
}

JNIEXPORT void JNICALL Java_KobukiWrap_enable(JNIEnv *env, jobject obj){
	std::cout << "In enable()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	k->enable();
}

JNIEXPORT void JNICALL Java_KobukiWrap_disable(JNIEnv *env, jobject obj) {
	std::cout << "In disable()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	k->disable();
}



JNIEXPORT void JNICALL Java_KobukiWrap_dispose(JNIEnv *env, jobject obj){
	std::cout << "kobuki dispose" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);

    // set the native handle
	handle = reinterpret_cast<jlong>((long)0);
	c = env->GetObjectClass(obj);
    // J is the type signature for long:
    handleField = env->GetFieldID(c, "nativeHandle", "J");
    env->SetLongField(obj, handleField, handle);

    delete k;
}

