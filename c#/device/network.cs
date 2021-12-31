//badger
using System;//_
using System.Net;//dns
using System.Net.NetworkInformation;//ping
using System.Net.Sockets;//address_family
using System.Runtime.InteropServices;//_

public static partial class device
{
	public static class wifi
	{
		[DllImport("wininet.dll")] private static extern bool InternetGetConnectedState(out int A1, int A2);

		public static bool connect() { int b1 = 0; return InternetGetConnectedState(out b1, 0); }
	};
	public static class ip
	{
		public static string address()
		{
			var b1 = Dns.GetHostEntry(Dns.GetHostName());
			foreach (var ip in b1.AddressList) { if (ip.AddressFamily == AddressFamily.InterNetwork) { return ip.ToString(); } }
			throw new Exception("ERROR: NO NETWORK ADAPTERS WITH AN 'IPv4' ADDRESS IN THE SYSTEM!");
		}
		public static string name(string ip) { return Dns.GetHostEntry(ip).HostName; }
	};
	public static class network
	{
		public static string[] ip()
		{
			string[] output = null;
			NetworkInterface[] ni = NetworkInterface.GetAllNetworkInterfaces();
			for (int a = 0; a < ni.Length; a++)
			{
				IPInterfaceProperties properties = ni[a].GetIPProperties();

				foreach (IPAddressInformation unicast in properties.UnicastAddresses) { output[a] = unicast.Address.ToString(); }
			}
			return output;
		}
	};
};