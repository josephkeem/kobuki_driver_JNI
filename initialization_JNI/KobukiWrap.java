public class KobukiWrap
{
    private long nativeHandle;
    public KobukiWrap() { initialize(); }
    private native void initialize();

	public native void init(long parametersWrapNativeHandle);

	public native void dispose();
}
