/*
 * 5/11/2023
 * output:
 * 	-#'s 1-4 printed in different ways.
 */
import java.util.Scanner;

public class IO{
	@SafeVarargs
	public static <T> void print(T... a1){
        int a=0;
        for(T c:a1){
            System.out.print(a<a1.length-1?c+" ":c);
            a++;
        }
        System.out.print("\n");
    }
	public static void main(String[] args){
		int n1=1,n2=2,n3=3,n4=4;

		System.out.print(n1+" "+n2+" "+n3+" "+n4+"\n");
		System.out.println(n1+" "+n2+" "+n3+" "+n4);
		System.out.printf("%d %d %d %d\n",n1,n2,n3,n4);
		//print(n1,n2,n3,n4);

		try{
			Scanner i1=new Scanner(System.in);
			print("input # bro: ");
			print(i1.nextInt());
			i1.close();
		}
		catch(Exception e){
			print("[._.]: INVALID INPUT!");
		}
	}
}