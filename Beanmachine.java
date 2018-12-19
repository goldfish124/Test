import java.util.Scanner;
public class Beanmachine 
{
	public static void main(String[] args) {
		Scanner input =new Scanner(System.in);
		System.out.print("Enter the number of balls:");//球的个数
		int num=input.nextInt();
		System.out.print("Enter the number of plies:");//层数
		int layers=input.nextInt();
		input.close();
		int solt[]=new int[layers+1];
		for(int i=0;i<num;i++) {
		int Rnum=0;
		for(int j=0;j<layers;j++) {
			char pos=Direction();
			System.out.print(pos);
			if(pos=='R')
				Rnum++;
		}
		System.out.println();
		System.out.println("The "+(i+1)+"balls falls into"+(Rnum+1)+"th solt.");
		solt[Rnum]++;
		}
		for(int i=0;i<solt.length;i++) {
			System.out.println("The "+(i+1)+"th solt have"+solt[i]+" balls.");
	}
}
public static char Direction() {
	double random=Math.random();
	if(random<0.5)
		return 'L';
	else
		return 'R';
}
}
	
