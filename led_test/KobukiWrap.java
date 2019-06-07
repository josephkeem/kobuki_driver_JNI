public class KobukiWrap
{
    private long nativeHandle;
    public KobukiWrap() { initialize(); }
    private native void initialize();

	public native void init(long parametersWrapNativeHandle);
	public native void enable();
	public native void disable();
	public native void setBaseControl(double linear_velocity, double angular_velocity);
	public native void setLed1Black();
	public native void setLed1Red();
	public native void setLed1Green();
	public native void setLed1Orange();
	public native void setLed2Black();
	public native void setLed2Red();
	public native void setLed2Green();
	public native void setLed2Orange();
	
	

	public native void dispose();
}
