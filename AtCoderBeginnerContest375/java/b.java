import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        
        int nowX = 0;
        int nowY = 0;

        double ans = 0;

        for (int i = 0; i < Idx; i++) {
            int nextX = sc.nextInt();
            int nextY = sc.nextInt();

        
            ans += Math.sqrt((double)(nowX - nextX)*(nowX - nextX) + (double)(nowY - nextY)*(nowY - nextY));

            nowX = nextX;
            nowY = nextY;
        }

        
        ans += Math.sqrt((double)(nowX - 0)*(nowX - 0) + (double)(nowY - 0)*(nowY - 0));
        sc.close();
        System.out.println(ans);
    }
}
