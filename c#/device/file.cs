//badger
using System;//_
using System.IO;//file

public static partial class device
{
	public static class drive
	{
		private static DriveInfo di = new DriveInfo("C");

		public static DriveType type = di.DriveType;
		public static string name = di.Name;
		public static string system = di.DriveFormat;
		public static long available = di.AvailableFreeSpace;
		public static long total = di.TotalSize;
		public static double storage() { double b1 = 0; if (di.IsReady) { b1 = (di.AvailableFreeSpace / (float)di.TotalSize) * 100; } return b1; }
	};
	public static class file
	{
		public static string user() { return Environment.GetFolderPath(Environment.SpecialFolder.UserProfile); }
		public static string application() { return Path.GetFullPath(".\\"); }
	};
};