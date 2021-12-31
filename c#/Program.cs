//badger
namespace device_info
{
	internal static class Program{
		[STAThread()]
		static void Main()
		{
			ApplicationConfiguration.Initialize();
			Application.Run(new main());
		}
	};
};