import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        sc.close();
        int beforeIdx =text.indexOf("A");
        int ans = 0;

        for(int i = 66; i <= 90; i++){
            char c = (char)(i); 
            String str = String.valueOf(c);
            int afterIdx =text.indexOf(str);
            ans += Math.abs(beforeIdx - afterIdx);
            beforeIdx = afterIdx;
        }
        System.out.println(ans);        
    }
}