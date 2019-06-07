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
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedRed(0);
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedGreen(0);
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedOrange(0);
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedBlack(0);
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedRed(1);
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedGreen(1);
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedOrange(1);
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedBlack(1);
			TimeUnit.SECONDS.sleep(1);
			kobuki.setLedBlack(3);
		} catch(Exception e) {
			System.out.println("ERROR - java side");
			System.out.println(e.getMessage());
		}
  	}

	public void disposeKobuki() {
		kobuki.dispose();
	}	

	public void disposeParameters() {
		parameters.dispose();
	}	

	private KobukiWrap kobuki = new KobukiWrap();
	private ParametersWrap parameters = new ParametersWrap();
}

public class set_led{
	static {
        System.loadLibrary("Init");
    }
	public static void main(String [] args)
	{
		KobukiManager kobuki_manager = new KobukiManager();
		kobuki_manager.disposeKobuki();
		kobuki_manager.disposeParameters();
		return;
	}
}

