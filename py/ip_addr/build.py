#badger
import PyInstaller.__main__

v1:str=input("version: ")

PyInstaller.__main__.run([
	".\\main.py",
	"-F",
	"-n=ip_addr"+v1,
	"-w",
	"--clean"
])