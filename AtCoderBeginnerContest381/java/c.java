import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        String text = sc.next();
        sc.close();
        char[] s = text.toCharArray();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if(s[i] != '/') continue;
            int d = 1;
            while(true){
                int j = i - d;
                int k = i + d;

                if(j < 0) break;
                if(k > len - 1) break;
                if(s[j] != '1') break;
                if(s[k] != '2') break;

                d++;
            }
            d --;
            ans = Math.max(ans, (d * 2) + 1);
        }
        System.out.println(ans);
    }
}