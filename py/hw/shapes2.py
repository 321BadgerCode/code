#date: 9/22/2022.
#description:
	#print rectangle, ellipse, arrow, & rhombus using asterisks(*).

#define shapes.
rect:str                =	"*****\n*   *\n*   *\n*   *\n*****"
ellipse:str             =	"  ***  \n *   * \n*     *\n *   * \n  ***  "
arrow:str		=	"  *  \n *** \n*****\n  *  \n  *  "
rhombus:str	        =	"  *  \n * * \n*   *\n * * \n  *  "

#output shapes to console.
print(rect+'\n')
print(ellipse+'\n')
print(arrow+'\n')
print(rhombus)
