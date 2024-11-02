import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] n = new int[4];

        for (int i = 0; i < 4; i++) {
            int a = sc.nextInt();
            n[a - 1]++;
        }

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans += n[i]/2;
        }

        
        sc.close();

        System.out.println(ans);
    }
}