import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        String text = sc.next();
        sc.close();

        char[] s = text.toCharArray();

        int ans = 0;
        int count = 0;

        for (int i = 0; i < N; i++) {
            if(s[i] == 'O'){
             count++;
            }else{
                count = 0;
            }

            if(count == K){
                ans++;
                count = 0;
            }
            
        }

        System.out.println(ans);
    }
}