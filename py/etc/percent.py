#badger
def get_percent(numerator:float,denominator:float)->float:
        return (numerator/denominator)*100

i1:float=float(input("numerator: "))
i2:float=float(input("denominator: "))

print("")
print("equ.: ("+str(i1)+'÷'+str(i2)+")*100")
print('='+str(get_percent(i1,i2))+'%')
