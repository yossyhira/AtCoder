import java.util.*;

public class d {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        int q = sc.nextInt();

        for (int i = 0; i < q; i++) {
            long num = sc.nextInt(); // 各クエリで取得

            int len = text.length();
            int roop = num / len;
            int mod = num % len;
            int moji = roop % 7;

            char c;
            if (mod != 0) {
                c = text.charAt(mod - 1);
            } else {
                c = text.charAt(len - 1);
            }

            // 小文字・大文字の変換処理
            if (moji == 1 || moji == 2 || moji == 4 || moji == 7) {
                if (Character.isLowerCase(c)) {
                    c = Character.toUpperCase(c);
                } else if (Character.isUpperCase(c)) {
                    c = Character.toLowerCase(c);
                }
            }
            System.out.print(c + " ");
        }

        sc.close();
        System.out.println(); // 最後に改行
    }
}
