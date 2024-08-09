import java.util.Scanner;
public class TransportationExpenses{
	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		int Idx = sc.nextInt();
		long maxMoney = sc.nextLong();
		int []num = new int[Idx];
		long sum=0;

		for(int i = 0; i < Idx; i++) {
			num[i] = sc.nextInt();
			sum += num[i];
		}
         
		if(sum <= maxMoney) {
			System.out.println("infinite");
		}else {
			int ok = 0, ng = Integer.MAX_VALUE;
			while(Math.abs(ok-ng) > 1) {
				int mid = (ok+ng) / 2;
                System.out.println(ok+" "+ng+" "+mid);
		        long sum1 = 0;
		        for(int i:num) {
		        	sum1 += Math.min(mid,i);
		        }
		        if(sum1 <= maxMoney) {
		        	ok = mid;
		        }else {
		        	ng = mid;
		        }
			}
			System.out.println(ok);
		}
		
	}
}


/*import java.util.Scanner;
import java.util.Arrays;

public class  TransportationExpenses{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        long maxMoney = sc.nextLong();
        int sum = 0;
        int[] num;
        num = new int[Idx];

        for(int i = 0; i < Idx; i++){
            num[i] = sc.nextInt();
            sum += num[i];
        }
        sc.close();

        Arrays.sort(num);


        if(maxMoney >= sum){
            System.out.println("infinite");
        }else{
            long border = (maxMoney / Idx);
            long sum1 = 0;

            for(long i = border; i <= num[Idx - 1]; i++){
                for(int j = 0; j < Idx; j++){
                    sum1 += Math.min(num[j], i);
                }
                if(sum1 > maxMoney){
                    System.out.println(i-1);
                    break;
                }
                sum1 = 0;
            }
        }
    }
}*/

