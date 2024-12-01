import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        String text = sc.next();
        sc.close();
        char[] s = text.toCharArray();
        int count = 0;
        for (int i = N - 1; i >= 0; i--) {
            if(count == D){
                break;
            }
            if(s[i] == '@'){
                s[i] = '.';
                count++;
            }
            
        }
        String A = new String(s);
        System.out.println(A);
    }
}