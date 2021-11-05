#badger
from os import getpid
import psutil
import socket
"""from PyInstaller.utils.hooks import collect_submodules

hiddenimports=["os._libs.tslibs.getpid","psutil._libs","socket._libs"]"""

class device():
	name=socket.gethostname()
	ip_address=socket.gethostbyname(name)
	class battery():
		def time_left():
			mm,ss=divmod(psutil.sensors_battery().secsleft,60)
			hh,mm=divmod(mm,60)
			return "%d:%02d:%02d"%(abs(hh),mm,ss)
		percent:int=psutil.sensors_battery().percent
		charge:bool=psutil.sensors_battery().power_plugged

def app_run():
	return str(psutil.Process(getpid()).parent().name())
def cpu_usage():
	return str(psutil.cpu_percent(interval=0.5))
def ram_usage():
	a1=int((psutil.virtual_memory().total-psutil.virtual_memory().available)/1024/1024)
	return str(a1)
def ram_total():
	a1=int((psutil.virtual_memory().total/1024/1024))
	return str(a1)

print("This program is currently running on: "+app_run())
print("C.P.U. percentage: "+cpu_usage()+"%")
print("R.A.M. usage: "+ram_usage()+" M.B.")
print("R.A.M. total: "+ram_total()+" M.B.")
print("-----")
print("Device name: "+device.name)
print("Device I.P. address: "+device.ip_address)
print("Device battery: "+str(device.battery.percent)+"%")
print("Device charging: "+str(device.battery.charge))
print("Device battery time left: "+device.battery.time_left())