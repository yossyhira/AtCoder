import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Idx = sc.nextInt();
        String text = sc.next();
        sc.close();

        char[] s = text.toCharArray();
        int ans = 0;
        for (int i = 0; i < Idx - 2; i++) {
            if(s[i] == '#' & s[i + 2] == '#' & s[i + 1] == '.'){
                ans++;
            }
        }

        System.out.println(ans);
    }
}