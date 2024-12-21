import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char c1 = sc.next().charAt(0); 
        char c2 = sc.next().charAt(0);
        String text = sc.next();
        sc.close();

        StringBuilder result = new StringBuilder(text); // StringBuilder で文字列を操作

        for (int i = 0; i < n; i++) {
            if (result.charAt(i) != c1) { // 条件に合う文字を変える
                result.setCharAt(i, c2);
            }
        }

        System.out.println(result.toString()); // 結果を出力
    }
}
