public class KobukiWrap
{
    private long nativeHandle;
    public KobukiWrap() { initialize(); }
    private native void initialize();

	public native void init(long parametersWrapNativeHandle);
	//public native void updateOdometry( 
	public native void setBaseControl(double linear_velocity, double angular_velocity);
	public native void enable();
	public native void disable();
	

	public native void dispose();
}
