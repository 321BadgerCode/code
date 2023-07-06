/*
 * #period: 1.
 * #date: 5/12/2023.
 * #description:
 * 	#print rectangle, ellipse, arrow, & rhombus using asterisks(*).
*/
public class Shapes2{
	public static void main(String[] args){
		String rect		=	"*****\n*   *\n*   *\n*   *\n*****";
		String ellipse	=	"  ***  \n *   * \n*     *\n *   * \n  ***  ";
		String arrow	=	"  *  \n *** \n*****\n  *  \n  *  ";
		String rhombus	=	"  *  \n * * \n*   *\n * * \n  *  ";

		System.out.println(rect+"\n");
		System.out.println(ellipse+"\n");
		System.out.println(arrow+"\n");
		System.out.println(rhombus);
	}
}