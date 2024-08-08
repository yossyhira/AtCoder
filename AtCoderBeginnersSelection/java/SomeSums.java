import java.util.Scanner;
import java.lang.Math;

public class SomeSums {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int minNum = sc.nextInt();
        int maxNum = sc.nextInt();
        int division = 0, mod = 0, sum = 0, ans = 0, nowNum = 0;
        sc.close();

        
        for(int i=1; i <= num; i++){

            nowNum = i;
            for(int j = 4; j >= 0; j--){        
                division = nowNum / (int) Math.pow(10, j);       
                sum += division;
                nowNum = nowNum % (int) Math.pow(10, j);
            }
            if((sum >= minNum) && (sum <= maxNum)){
                ans += i;
            }
            sum = 0;
        }
        System.out.println(ans);
    }
}