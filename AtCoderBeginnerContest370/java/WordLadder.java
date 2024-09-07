import java.util.*;

public class WordLadder {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        sc.close();

        int count = 0; // `hoge` のインデックスを管理するカウンタ
        int count2 = 0; // `ans` のインデックスを管理するカウンタ
        char x; // 一時的な文字の保存用変数
        String[] hoge = new String[S.length()]; 
        String[] ans = new String[S.length()]; // 結果を保存する配列

        // S と T が一致するまでループ
        while (!S.equals(T)) {
            char[] s = S.toCharArray();
            char[] t = T.toCharArray();
            // 文字列SとTを比較し、異なる箇所を入れ替える
            for (int i = 0; i < S.length(); i++) {
                if (s[i] != t[i]) {
                    x = s[i]; // ここでセミコロンを追加
                    s[i] = t[i]; // Sの異なる部分をTの文字に変更
                    String A = new String(s); // 変更後の文字列を作成
                    hoge[count] = A; // 変更後の文字列を一時配列に格納
                    count++;
                    s[i] = x; // 元に戻す
                }
            }
            
            // null以外の要素で辞書順にソート
            Arrays.sort(hoge, (s1, s2) -> {
                if (s1 == null) return 1; // nullは最後にソート
                if (s2 == null) return -1;
                return s1.compareTo(s2);
            });

            // ソート後の最初の要素を次のSにする
            S = hoge[0];
            ans[count2] = hoge[0]; // 結果配列に保存
            count2++;
            hoge = new String[S.length()];
            count = 0;
        }

        // 実際に格納された要素数を表示
        System.out.println(count2);

        // 結果配列の中身を1行ずつ表示（null要素は無視）
        for (int i = 0; i < count2; i++) {
            System.out.println(ans[i]);
        }
    }
}
