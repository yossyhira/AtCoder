import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        int C = sc.nextInt();
        int[] T = new int[Idx];
        for (int i = 0; i < Idx; i++) {
            T[i] = sc.nextInt();
        } 
        int ok = T[0];
        int ans = 1;
        for (int i = 1; i < Idx; i++) {
            if(T[i] - ok >= C){
                ans ++;
                ok = T[i];
            }
        }
        sc.close();

        System.out.println(ans);
    }
}