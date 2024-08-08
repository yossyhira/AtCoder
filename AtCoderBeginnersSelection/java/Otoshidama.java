import java.util.Scanner;

public class Otoshidama {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int money = sc.nextInt();
        int coin10000 = -1, coin5000 = -1, coin1000 = -1, count=0;
        sc.close();

        loop: for(int i=0;i<=N;i++){
            for(int j=0;j<=N-i;j++){
                count = i*10000 + j*5000 + (N-i-j)*1000;
                if(count == money){
                        coin10000 = i;
                        coin5000 = j;
                        coin1000 = N-i-j;
                        break loop;
                    }
            }
        } 
        System.out.println(coin10000 + " " + coin5000 + " " + coin1000);
    }
}


/*loop: for(int i=0; i <= N; i++){
            for(int j=0; j <= N; j++){
                for(int k=0; k <= N; k++){
                    if (((i + j + k) == N)){
                        count = i*10000 + j*5000 + k*1000;
                        if(count == money){
                            coin10000 = i;
                            coin5000 = j;
                            coin1000 = k;
                            break loop;
                        }
                        count = 0;
                    }
                }
            }
        }*/
       