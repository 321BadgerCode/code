//badger
using System;//_
using System.Net;//dns
using System.Runtime.InteropServices;//_

public static partial class device
{
	private const ushort intel = 0;
	private const ushort ia64 = 6;
	private const ushort amd64 = 9;
	[DllImport("kernel32.dll")] private static extern system_info GetNativeSystemInfo();
	[DllImport("kernel32.dll")] private static extern system_info GetSystemInfo();

	public static OperatingSystem os = Environment.OSVersion;
	[StructLayout(LayoutKind.Sequential)]
	public struct system_info
	{
		public ushort wProcessorArchitecture;
		public ushort wReserved;
		public uint dwPageSize;
		public IntPtr lpMinimumApplicationAddress;
		public IntPtr lpMaximumApplicationAddress;
		public UIntPtr dwActiveProcessorMask;
		public uint dwNumberOfProcessors;
		public uint dwProcessorType;
		public uint dwAllocationGranularity;
		public ushort wProcessorLevel;
		public ushort wProcessorRevision;
	};
	public enum type { x86, x64, unknown };
	public static type operating_system()
	{
		var sys_info = new system_info();

		if (Environment.OSVersion.Version.Major > 5 || (Environment.OSVersion.Version.Major == 5 && Environment.OSVersion.Version.Minor >= 1)) { sys_info = GetNativeSystemInfo(); }
		else { sys_info = GetSystemInfo(); }

		switch (sys_info.wProcessorArchitecture)
		{
			case intel: return type.x86;
			case ia64:
			case amd64: return type.x64;
			default: return type.unknown;
		}
	}
	public static string info() { return os.ToString(); }
	public static string name() { return Environment.MachineName; }
	public static string name2() { return Dns.GetHostName(); }
};