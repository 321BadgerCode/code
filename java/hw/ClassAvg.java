import java.util.Scanner;

public class ClassAvg{
	public static void main(String[] args){
		Scanner i1=new Scanner(System.in);

		System.out.print("How many students are in the class?");
		int student=10;

		int sum=0;
		int i=0;
		while(i<student){
			System.out.print("Grade "+(i+1)+": ");
			float grade=i1.nextFloat();

			if(grade<0){
				System.out.println("That grade is unacceptable");
			}
			else if(grade>100){
				System.out.println("That grade is unacceptable");
			}
			else{
				sum+=grade;
				i++;
			}
		}
		float avg=sum/student;
		System.out.println("The mean of the 10 numbers is: "+avg);
	}
}