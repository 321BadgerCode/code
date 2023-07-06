#date: 11/29/2022
#description:
	#output:
		#mad-lib with random words.
import random

adj=["slimy","sticky","colorful","crazy","cool"]
noun=["dragon","rhino","badger","playground","computer"]
plural_noun=["pentagons","sheep","schools","dogs","cats"]
game=["video games","Sorry","Monopoly","chess","checkers"]
verb_ing=["running","walking","strolling","hiking","rushing"]
plant=["English Ivy","Spider Plant","Aloe Vera","Indian Basil","Areca Palm"]
body_part=["arm","shoulder","knee","head","hand"]
place=["Pentagon","Russia","Eiffel Tower","Disney World","Japan"]
"""plural_noun=[""]
for i in range(0,len(noun)):
        plural_noun.append(noun[a]+"s")"""

#adj..
adj1=random.choice(adj)
adj.remove(adj1)

adj2=random.choice(adj)
adj.remove(adj2)

adj3=random.choice(adj)
adj.remove(adj3)

#noun.
noun1=random.choice(noun)
noun.remove(noun1)

noun2=random.choice(noun)
noun.remove(noun2)

noun3=random.choice(noun)
noun.remove(noun3)

#plural noun.
plural_noun1=random.choice(plural_noun)
plural_noun.remove(plural_noun1)

plural_noun2=random.choice(plural_noun)
plural_noun.remove(plural_noun2)

plural_noun3=random.choice(plural_noun)
plural_noun.remove(plural_noun3)

plural_noun4=random.choice(plural_noun)
plural_noun.remove(plural_noun4)

#game.
game1=random.choice(game)
game.remove(game1)

#verb end w/ -ing.
verb_ing1=random.choice(verb_ing)
verb_ing.remove(verb_ing1)

verb_ing2=random.choice(verb_ing)
verb_ing.remove(verb_ing2)

verb_ing3=random.choice(verb_ing)
verb_ing.remove(verb_ing3)

verb_ing4=random.choice(verb_ing)
verb_ing.remove(verb_ing4)

#plant.
plant1=random.choice(plant)
plant.remove(plant1)

#body part.
body_part1=random.choice(body_part)
body_part.remove(body_part1)

#place.
place1=random.choice(place)
place.remove(place1)

#random int. for hours of work.
hours=random.randint(0,24)

print()
print("-------------My Mad Lib-------------")
print()
print("A vacation is when you take a trip to some " + adj1 +" place")
print("with your " + adj2 + " family. Usually you go to some place ")
print("that is near a/an " +noun1 +" or up on a/an "+ noun2)
print("A good vacation place is one where you can ride " + plural_noun1)
print("or play " + game1 +" or go hunting for " + plural_noun2 + ".  I like ")
print("to spend my time " + verb_ing1 + " or "+verb_ing2 + ".")
print("When parents go on a vacation, they spend their time eating")
print("three " + plural_noun3 +" a day, and fathers play golf, and mothers ")
print("sit around " + verb_ing3 + ". Last summer, my little brother ")
print("fell in a/an " + noun3 + " and got poison " + plant1 + " all")
print("over his " + body_part1 + ".  My family is going to go to (the) ")
print(place1 + " , and I will practice "+verb_ing4+".  Parents")
print("need vacations more than kids because parents are always very ")
print(adj3+" and because they have to work",hours) #insert a random integer generator for the appropriate number here
print("hours every day all year making enough " + plural_noun4 + " to pay " )
print("for the vacation.")
