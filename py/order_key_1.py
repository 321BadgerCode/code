#badger
from string import *
from time import sleep,time
from os import system
import itertools

"""def generate_key(length):
	chars=ascii_letters+digits
	a=[[""]*length]*len(chars)
	for b in range(len(a)):
		for c in range(len(a[0])):
			a[b][c]=chars[b]
	return a"""
def generate_key(length):
	chars=ascii_lowercase+digits
	a=0
	b=[[""]*length]*len(chars)**length
	for c in itertools.product(chars,repeat=length):
		for d in range(length):
			b[a][d]=c[d]
			print(b[a],a,d)
			a+=1
	return b
num_of_keys=1
start=time()
keys=generate_key(num_of_keys)
end=time()
print(keys)
print("[._.]: It took "+str(end-start)+" to generate the keys :)")
system("pause")