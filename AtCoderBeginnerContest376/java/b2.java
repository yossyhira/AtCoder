import java.util.*;

public class b2 {

    public static int f(int n, int s, int t, int x) {
     if(s > t){
        int hoge;
        hoge = s;
        s = t;
        t = hoge;
     }
     if(s < x && x < t){
        return n - (t - s);
     }else{
        return t - s;
     }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        
        int l = 1;
        int r = 2;
        int ans = 0;

        for (int i = 0; i < q; i++) {
            
            char hand = sc.next().charAt(0);
            int t  = sc.nextInt();
        
            if(hand == 'L'){
                ans += f(n, l, t, r);
                l = t;
            }else{
                ans += f(n, r, t, l);
                r = t;
            }
        }
        sc.close();

        System.out.println(ans);
    }
}