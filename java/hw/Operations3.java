/*
 * 5/15/2023
 * input:
 * 	-name,2 integers.
 * output:
 * 	-operations of the 2 inputed #'s.
 */
import java.util.Scanner;

public class Operations3{
	public static <T> void print(T[] a1,String end){
        int a=0;
        for(T c:a1){
            System.out.print(a<a1.length-1?c+" ":c);
            a++;
        }
        System.out.print(end);
    }
	@SafeVarargs
	public static <T> void print(T... a1){
        print(a1,"\n");
    }
	public static String get_capitalize(String str){
		return str.substring(0,1).toUpperCase()+str.substring(1);
	}
	public static String get_cap(String str){
		String b1[]=str.split(" ");
		String ans="";
		for(int a=0;a<b1.length;a++){
			String name=get_capitalize(b1[a]);
			ans+=a<b1.length-1?name+" ":name;
		}
		return ans;
	}
	public static void main(String[] args){
		//input manager.
		Scanner i1=new Scanner(System.in);

		//get name.
		print(new String[]{"What is your name? "},"");
		String name=i1.nextLine();
		print("Hello",get_cap(name));

		//get #'s.
		print(new String[]{"Please enter in first number:"},"");
		int n1=i1.nextInt();
		print(new String[]{"Please enter in second number:"},"");
		int n2=i1.nextInt();

		//operations.
		print(n1,"+",n2,"=",n1+n2);
		print(n1,"-",n2,"=",n1-n2);
		print(n1,"*",n2,"=",n1*n2);
		print(n1,"/",n2,"=",n1/n2);
		print(n1," mod ",n2,"=",n1%n2);

		/*System.out.printf("%d + %d = %d%n",n1,n2,n1+n2);
		System.out.printf("%d - %d = %d%n",n1,n2,n1-n2);
		System.out.printf("%d * %d = %d%n",n1,n2,n1*n2);
		System.out.printf("%d ÷ %d = %d%n",n1,n2,n1/n2);
		System.out.printf("%d mod %d = %d",n1,n2,n1%n2);*/

		i1.close();
	}
}