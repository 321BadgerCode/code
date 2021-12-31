//badger
using System;//basic
using System.IO;//file
using System.Windows.Forms;//basic

namespace device_info{
	public partial class main:Form{
		public main()
		{
			InitializeComponent();
			new box("User(device)", "User platform type/operating system: " + device.operating_system().ToString() + "; " + device.info() + "\nUser I.P(internet protocol) adress: " + device.ip.address() + "\nWifi conncectivity: " + device.wifi.connect()).message();
			new box("User(memory)", "Total memory: " + device.storage.space(device.memory.total()) + "\nMemory used: " + device.storage.space(device.memory.use()) + "\nMemory available: " + device.storage.space(device.memory.available())/* + "\nMemory percent: " + device.storage.size((ulong)device.memory.percent())*/).message();
			//new box("User(C.P.U)", "C.P.U(central processing unit) name: " + device.cpu.name + "\nC.P.U(central processing unit) usage: " + device.cpu.usage.ToString()).message();
			new box("User('C' drive)", "Drive name: " + device.drive.name + "\nDrive total storage: " + device.storage.size((ulong)device.drive.total) + "\nDrive available storage: " + device.storage.size((ulong)device.drive.available) + "\nDrive storage: " + device.storage.size((ulong)device.drive.storage()) + "%").message();
			new box("User(file)", "User folder: " + device.file.user() + "\nApplication directory: " + device.file.application()).message();
			new box("Application", new box.text_box("Application path: " + app.path + "\nApplication directory: " + app.dir + "\nApplication name: " + app.name + "\nApplication company: " + app.company + "\nApplication version: " + app.version + "\nApplication test: " + app.test, new box.style2(null, null, null)) { WordWrap = false }, null).message();
			new box("opening...", new box.text_box("the app is almost open", new box.style2(BorderStyle.Fixed3D, Color.Black, Color.White)),new Size(500, 500)) { ShowInTaskbar = true,BackColor=Color.Black }.important();
		}
	};
};
//audio: change function to play sound, but to not make it into file