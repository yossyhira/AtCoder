import java.util.*;

public class delete {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        // 入力処理を行う
        sc.close();
         char[] s = text.toCharArray();
         for(int i = 0; i < text.length(); i++){
            if(s[i] == '.'){
                continue;
            }
            System.out.print(s[i]);
         }
         System.out.println();
    }
}