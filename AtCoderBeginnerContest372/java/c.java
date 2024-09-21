import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        String text = sc.next();
        char[] s = text.toCharArray();

        for(int i = 0; i < q; i++){
            int Idx = sc.nextInt() - 1;
            char word = sc.next().charAt(0);

            s[Idx] = word;
            String A = new String(s);
            
            
            //ここからAに文字列"ABC"が何個あるかカウントするプログラムを作成


        }
        sc.close();

    
    }
}