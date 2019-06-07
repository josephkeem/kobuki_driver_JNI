public class ParametersWrap
{
    private long nativeHandle;
	public long getNativeHandle(){
		return nativeHandle;
	}

    public ParametersWrap() { initialize(); }
    private native void initialize();

	public native void setDevicePort(String str);
	public native String getDevicePort();
	public native void setSigslotsNamespace(String str);
	public native String getSigslotsNamespace();
	public native void setEnableAccelerationLimiter(boolean b);
	public native boolean getEnableAccelerationLimiter();
	public native void setBatteryCapacity(double d);
	public native double getBatteryCapacity();
	public native void setBatteryLow(double d);
	public native double getBatteryLow();
	public native void setBatteryDangerous(double d);
	public native double getBatteryDangerous();

	public native void dispose();
}
