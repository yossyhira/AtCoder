import java.util.Scanner;

public class Kagamimochi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] num;
        int hoge, count = 0, waitNum = 0, mochiNum = 0;
        int Idx = sc.nextInt();
        num = new int[Idx];
        for (int i = 0; i < Idx; i++){
            num[i] = sc.nextInt();
        }
        sc.close();

        while(true){
            for (int i = 0; i < Idx-1; i++){
                if(num[i] < num[i+1]){
                    hoge = num[i];
                    num[i] = num[i+1];
                    num[i+1] = hoge;
                    count = 1;
                }
            }
            if (count == 0){
                break;
            }
            count = 0;
        }

        for (int i = 0; i < Idx - 1; i++){
            waitNum = num[i];

            if(num[i] != num[i + 1]){
                mochiNum++;
            }
        }

        System.out.println(mochiNum + 1);
    }
}