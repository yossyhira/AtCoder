import java.util.*;
import java.io.*;

public class VerticalWriting {
    public static void main(String[] args) {
       int n, m = 0;
       Scanner sc = new Scanner(System.in);
       n = sc.nextInt();
       String[] s = new String[n];

       for(int i = 0; i < n; i++){
           s[i] = sc.next();

           while(i > 0 && s[i].length() < s[i-1].length()) {
            s[i]+='*';
           }

           m=Math.max(m,s[i].length());
       }

       for(int i = 0; i < m; i++){
           for(int j = n - 1; j >= 0; j--){
              //s[j]のi文字目があれば表示
              //s[j].length()は大きさなので３文字の場合
              //配列の0, 1, 2なのでi < s[j].length()の不等号が＜で
              //i文字目の有無を判断
               if(i < s[j].length()){
               System.out.print(s[j].charAt(i));
               }
           }
           System.out.println();
       }
    }
}
