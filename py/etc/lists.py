import random

basket=["apple","banana","cherry"]

for n in range(0,len(basket)):
        print(basket[n])

for fruit in basket:
        print(fruit)

fruit=random.choice(basket)
basket.remove(fruit)
print(fruit)
