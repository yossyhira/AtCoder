import java.util.Scanner;

public class CardGameforTwo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] num;
        int hoge, Alice = 0, Bob = 0, count = 0;
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

        for (int i = 0; i < Idx; i++){
            if((i % 2) == 0){
               Alice += num[i]; 
            }else{
                Bob += num[i];
            }
        }

        System.out.println(Alice - Bob);
    }
}