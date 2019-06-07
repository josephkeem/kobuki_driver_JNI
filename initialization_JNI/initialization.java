import java.util.concurrent.TimeUnit;

class KobukiManager{
	public KobukiManager() {
		// change the default device port from /dev/kobuki to /dev/ttyUSB0
		parameters.setDevicePort("/dev/ttyUSB0");

		// Other parameters are typically happy enough as defaults
		// namespaces all sigslot connection names under this value, only important if you want to
		parameters.setSigslotsNamespace("/kobuki");

		// Most people will prefer to do their own velocity smoothing/acceleration limiting.
		// If you wish to utilise kobuki's minimal acceleration limiter, set to true
		parameters.setEnableAccelerationLimiter(false);

		// If your battery levels are showing significant variance from factory defaults, adjust thresholds.
		// This will affect the led on the front of the robot as well as when signals are emitted by the driver.
		parameters.setBatteryCapacity(16.5);
		parameters.setBatteryLow(14.0);
		parameters.setBatteryLow(13.2);

		// initialise - it will throw an exception if parameter validation or initialisation fails.
		try {
		  kobuki.init(parameters.getNativeHandle());
		} catch(Exception e) {
			System.out.println("ERROR - java side");
		  System.out.println(e.getMessage());
		}

		try {
			TimeUnit.SECONDS.sleep(5);
			kobuki.dispose();
			parameters.dispose();
		} catch(Exception e) {
			System.out.print(e.getMessage());		
		}
  	}
	private KobukiWrap kobuki = new KobukiWrap();
	private ParametersWrap parameters = new ParametersWrap();
}

public class initialization{
	static {
        System.loadLibrary("Init");
    }
	public static void main(String [] args)
	{
		KobukiManager kobuki_manager = new KobukiManager();
		return;
	}
}

