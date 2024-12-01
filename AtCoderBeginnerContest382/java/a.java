import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        String text = sc.next();
        sc.close();
        char[] s = text.toCharArray();
        
        for (int i = 0; i < N; i++) {
            if(s[i] == '.')count++;
        }
        System.out.println(count + D);
    }
}