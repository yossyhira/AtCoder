import java.util.Arrays;
import java.util.Scanner;

public class  SecondBest{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int[] num, num1;
        num = new int[Idx];
        num1 = new int[Idx];

        for(int i = 0; i < Idx; i++){
            num[i] = sc.nextInt();
        }
        sc.close();

        for(int i = 0; i < Idx; i++){
           num1[i] = num[i];
        }
        Arrays.sort(num);
        for(int i = 0; i < Idx; i++){
            if(num1[i] == num[Idx - 2]){
                System.out.println(i + 1);
                break;
            }
        }
    }
}