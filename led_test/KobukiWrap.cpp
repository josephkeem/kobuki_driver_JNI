#include "KobukiWrap.h"
#include <iostream>

#include <kobuki_driver/kobuki.hpp>
#include "modules/led_array.hpp"

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

JNIEXPORT void JNICALL Java_KobukiWrap_enable(JNIEnv *env, jobject obj){
	std::cout << "kobuki enable()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	k->enable();
}

JNIEXPORT void JNICALL Java_KobukiWrap_disable(JNIEnv *env, jobject obj) {
	std::cout << "kobuki disable()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	k->disable();
}

JNIEXPORT void JNICALL Java_KobukiWrap_setBaseControl(JNIEnv *env, jobject obj, jdouble linearV, jdouble angularV) {
	std::cout << "kobuki setBaseControl()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	k->setBaseControl(linearV, angularV);
	return;
}

JNIEXPORT void JNICALL Java_KobukiWrap_setLedBlack(JNIEnv *env, jobject obj, jint ledNum){
	std::cout << "kobuki setLedBlack()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	try{
		k->setLed((kobuki::LedNumber)ledNum, (kobuki::LedColour)0x00);
	} catch (int e) {
		std::cout << "ERROR - C++ side" << std::endl;
	}
	return;
}

JNIEXPORT void JNICALL Java_KobukiWrap_setLedRed(JNIEnv *env, jobject obj, jint ledNum){
	std::cout << "kobuki setLedRed()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	try{
		k->setLed((kobuki::LedNumber)ledNum, (kobuki::LedColour)0x100);
	} catch (int e) {
		std::cout << "ERROR - C++ side" << std::endl;
	}
	return;
}

JNIEXPORT void JNICALL Java_KobukiWrap_setLedGreen(JNIEnv *env, jobject obj, jint ledNum){
	std::cout << "kobuki setLedGreen()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	try{
		k->setLed((kobuki::LedNumber)ledNum, (kobuki::LedColour)0x200);
	} catch (int e) {
		std::cout << "ERROR - C++ side" << std::endl;
	}
	return;
}

JNIEXPORT void JNICALL Java_KobukiWrap_setLedOrange(JNIEnv *env, jobject obj, jint ledNum){
	std::cout << "kobuki setLedOrange()" << std::endl;
	jclass c = env->GetObjectClass(obj);
	// J is the type signature for long
	jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
	kobuki::Kobuki *k = reinterpret_cast<kobuki::Kobuki *>(handle);
	try{
		k->setLed((kobuki::LedNumber)ledNum, (kobuki::LedColour)0x300);
	} catch (int e) {
		std::cout << "ERROR - C++ side" << std::endl;
	}
	return;
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

