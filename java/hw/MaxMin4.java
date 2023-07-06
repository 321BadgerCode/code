/*
 * 5/16/2023
 * input:
 * 	-input 5 integers.
 * output:
 * 	-max,min,mean.
 * due: 5/17/2023
 */
import java.util.Scanner;

public class MaxMin4{
	/*public static String fmt(double d){
	    if(d==(long)d)
	        return String.format("%d",(long)d);
	    else
	        return String.format("%s",d);
	}*/
	public static void main(String[] args){
		//input manager.
		Scanner i1=new Scanner(System.in);

		//get #'s.
		System.out.print("Please enter in first number: ");int n1=i1.nextInt();
		System.out.print("Please enter in second number: ");int n2=i1.nextInt();
		System.out.print("Please enter in third number: ");int n3=i1.nextInt();
		System.out.print("Please enter in fourth number: ");int n4=i1.nextInt();
		System.out.print("Please enter in fifth number: ");int n5=i1.nextInt();

		//get max..
		int max=n1;
		if(max<n2){max=n2;}
		if(max<n3){max=n3;}
		if(max<n4){max=n4;}
		if(max<n5){max=n5;}

		//get min..
		int min=n1;
		if(min>n2){min=n2;}
		if(min>n3){min=n3;}
		if(min>n4){min=n4;}
		if(min>n5){min=n5;}

		//get mean.
		float mean=((float)(n1+n2+n3+n4+n5))/5;

		//display output.
		System.out.printf("The largest number is: %d%n",max);
		System.out.printf("The smallest number is: %d%n",min);
		System.out.printf("The mean of the 5 numbers is: %.1f",mean);

		i1.close();
	}
}