//badger
using System;//_
using System.Diagnostics;//process
using System.Runtime.InteropServices;//_

public static partial class device
{
	public static class storage
	{
		public static double size(ulong A1) { double b1 = A1; int b2 = 0; while ((b1 > 1024) && (b2 < 5)) { b1 /= 1024; b2++; } return Math.Round(b1, 2); }
		public static string space(ulong A1) { double b1 = A1; int b2 = 0; while ((b1 > 1024) && (b2 < 5)) { b1 /= 1024; b2++; } string[] b3 = { "B", "K.B", "M.B", "G.B", "T.B" }; return string.Format("{0} {1}", Math.Round(b1, 2), b3[b2]); }
	};
	public static class memory
	{
		[DllImport("kernel32.dll")] [return: MarshalAs(UnmanagedType.Bool)] private static extern bool GlobalMemoryStatusEx(ref memory_info A1);
		private static memory_info GetMemoryStatus() { memory_info mi = new memory_info(); mi.dwLength = (uint)Marshal.SizeOf(mi); GlobalMemoryStatusEx(ref mi); return mi; }
		private static ulong GetAvailPhys() { memory_info mi = GetMemoryStatus(); return mi.ullAvailPhys; }
		private static ulong GetUsedPhys() { memory_info mi = GetMemoryStatus(); return (mi.ullTotalPhys - mi.ullAvailPhys); }
		private static ulong GetTotalPhys() { memory_info mi = GetMemoryStatus(); return mi.ullTotalPhys; }

		[StructLayout(LayoutKind.Sequential)]
		public struct memory_info
		{
			public uint dwLength;
			public uint dwMemoryLoad;
			public ulong ullTotalPhys;
			public ulong ullAvailPhys;
			public ulong ullTotalPageFile;
			public ulong ullAvailPageFile;
			public ulong ullTotalVirtual;
			public ulong ullAvailVirtual;
			public ulong ullAvailExtendedVirtual;
		};
		public static ulong available() { return GetAvailPhys(); }
		public static ulong use() { return GetUsedPhys(); }
		public static ulong total() { return GetTotalPhys(); }
		public static int percent() { return (int)((available() / 100) * total()); }
	};
	public static class cpu
	{
		private static PerformanceCounter pc = new PerformanceCounter("Processor", "% Processor Time", "_Total");

		public static string name = pc.MachineName;
		public static float usage = pc.RawValue;
	};
};