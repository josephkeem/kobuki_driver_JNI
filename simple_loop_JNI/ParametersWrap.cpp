#include "ParametersWrap.h"
#include <iostream>

#include <kobuki_driver/parameters.hpp>

JNIEXPORT void JNICALL Java_ParametersWrap_initialize(JNIEnv *env, jobject obj) {
	std::cout << "parameters constructor" << std::endl;
	try{
		kobuki::Parameters *inst = new kobuki::Parameters();
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

JNIEXPORT void JNICALL Java_ParametersWrap_setDevicePort(JNIEnv *env, jobject obj, jstring jstr){
	std::cout << "parameters set device" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	const char *str= env->GetStringUTFChars(jstr, 0);
	k->device_port = str;
	env->ReleaseStringUTFChars(jstr, str);
}

JNIEXPORT jstring JNICALL Java_ParametersWrap_getDevicePort(JNIEnv *env, jobject obj){
	std::cout << "parameters get device" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	return env->NewStringUTF(k->device_port.c_str());
}

JNIEXPORT void JNICALL Java_ParametersWrap_setSigslotsNamespace(JNIEnv *env, jobject obj, jstring jstr){
	std::cout << "parameters set sigslots" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	const char *str= env->GetStringUTFChars(jstr, 0);
	k->sigslots_namespace = str;
	env->ReleaseStringUTFChars(jstr, str);
}

JNIEXPORT jstring JNICALL Java_ParametersWrap_getSigslotsNamespace(JNIEnv *env, jobject obj){
	std::cout << "parameters get sigslots" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	return env->NewStringUTF(k->sigslots_namespace.c_str());
}

JNIEXPORT void JNICALL Java_ParametersWrap_setEnableAccelerationLimiter(JNIEnv *env, jobject obj, jboolean b){
	std::cout << "parameters set enable" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	k->enable_acceleration_limiter = (bool)b;
}

JNIEXPORT jboolean JNICALL Java_ParametersWrap_getEnableAccelerationLimiter(JNIEnv *env, jobject obj){
	std::cout << "parameters get enable" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	return (jboolean)k->enable_acceleration_limiter;
}

JNIEXPORT void JNICALL Java_ParametersWrap_setBatteryCapacity(JNIEnv *env, jobject obj, jdouble d){
	std::cout << "parameters set battery cap" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	k->battery_capacity = d;
}

JNIEXPORT jdouble JNICALL Java_ParametersWrap_getBatteryCapacity(JNIEnv *env, jobject obj){
	std::cout << "parameters get battery cap" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	return k->battery_capacity;
}

JNIEXPORT void JNICALL Java_ParametersWrap_setBatteryLow(JNIEnv *env, jobject obj, jdouble d){
	std::cout << "parameters set battery low" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	k->battery_low = d;
}

JNIEXPORT jdouble JNICALL Java_ParametersWrap_getBatteryLow(JNIEnv *env, jobject obj){
	std::cout << "parameters get battery low" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	return k->battery_low;

}

JNIEXPORT void JNICALL Java_ParametersWrap_setBatteryDangerous(JNIEnv *env, jobject obj, jdouble d){
	std::cout << "parameters set battery dang" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	k->battery_dangerous = d;
}

JNIEXPORT jdouble JNICALL Java_ParametersWrap_getBatteryDangerous(JNIEnv *env, jobject obj){
	std::cout << "parameters get battery dang" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *k = reinterpret_cast<kobuki::Parameters *>(handle);
	return k->battery_dangerous;
}

JNIEXPORT void JNICALL Java_ParametersWrap_dispose(JNIEnv *env, jobject obj){
	std::cout << "parameters dispose" << std::endl;
	jclass c = env->GetObjectClass(obj);
    // J is the type signature for long:
    jfieldID handleField = env->GetFieldID(c, "nativeHandle", "J");
	jlong handle = env->GetLongField(obj, handleField);
    kobuki::Parameters *p = reinterpret_cast<kobuki::Parameters *>(handle);

    // set the native handle
	handle = reinterpret_cast<jlong>((long)0);
	c = env->GetObjectClass(obj);
    // J is the type signature for long:
    handleField = env->GetFieldID(c, "nativeHandle", "J");
    env->SetLongField(obj, handleField, handle);

    delete p;
}

