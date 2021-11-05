#badger
class file:
	name:str=''
	data:str=''
	def __init__(self,name:str)->None:
		self.name=name
		self.create()
		self.read()
	def __str__(self)->str:
		return self.data
	def read(self)->None:
		self.data=open(self.name,'r').read()
	def write(self,a1:str)->None:
		self.data=a1
		open(self.name,'w').write(self.data)
	def create(self)->None:
		open(self.name,'a')
	def close(self)->None:
		open(self.name,'w').close()
	def encrypt(self)->None:
		self.write(get_encrypt(self.data))

class data:
	password:str=''
	def __init__(self,password:str)->None:
		self.password=password

def get_encrypt(a1:str)->str:
	b1:str=''

	for a in range(len(a1)):
		b1+=chr(ord(a1[a%len(a1)])^len(a1)+26)

	return b1

if __name__=="__main__":
	f=file(".\\test_1.txt")
	f.write("hello world")
	f.encrypt()
	print("encrypt: "+f.data)

	print("\n")
	a1=input("password: ")
	print("\n")

	d=data("123")
	if a1==d.password:
		f.encrypt()
		print("decrypt: "+f.data)
	else:
		print("password incorrect!")
	print("\n")
	print("[._.]: see you later :)")