import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] X = new int[N];
        int[] A = new int[M];
        for (int i = 0; i < M; i++) {
            int Idx = sc.nextInt();
            X[Idx - 1] = 1;
        }
        if(X[0] == 0){
            System.out.println("-1");
            return;
        }

        int ans = 0;
    

        int stone = sc.nextInt() - 1;
        int place = 0;
        for (int i = 1; i < N; i++) {
            if(X[i] == 0){
                stone --;
                if(stone < 0){
                    System.out.println("-1");
                    return;
                }
                ans += i - place;
            }else{
                stone += sc.nextInt();
                place = i;
            }
        }
        sc.close();

        System.out.println(ans);
    }
}