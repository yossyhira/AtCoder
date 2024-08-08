import java.util.Scanner;

public class Coins {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int coin500 = sc.nextInt();
        int coin100 = sc.nextInt();
        int coin50 = sc.nextInt();
        int money = sc.nextInt();
        int count=0, count1 = 0;
        sc.close();

        for(int i=0; i<=coin500; i++){
            for(int j=0; j<=coin100; j++){
                for(int k=0; k<=coin50; k++){
                    count = i*500 + j*100 + k*50;
                    if(count == money){
                        count1++;
                    }
                    count = 0;
                }
            }
        }
        System.out.println(count1);
    }
}