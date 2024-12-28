import java.util.*;
import java.io.*;

public class c {
    public static void main(String[] args)throws IOException {
        int hoge = sc.nextInt();
        String S = sc.next();
        String T = sc.next();

        if(S.equals(T)){
            System.out.println("Yes");
            return;
        }

        int len = Math.abs( S.length() - T.length());
        if (len >= 2){
            System.out.println("No");
            return;
        }

       if (len == 0) {
            StringBuilder TBuilder = new StringBuilder(T);
            for (int i = 0; i < S.length(); i++) {
                if (S.charAt(i) != T.charAt(i)) {
                    TBuilder.setCharAt(i, S.charAt(i));  // 文字を変更する
                    break;
                }
            }

            if (S.equals(TBuilder.toString())) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
            return;
        }else{
            if(S.length() > T.length()){
                StringBuilder SBuilder = new StringBuilder(S);
                int count = 0;
                for (int i = 0; i < S.length() - 1; i++) {
                    if (S.charAt(i) != T.charAt(i)) {
                        SBuilder.delete(i, i+1);  // 文字を変更する
                        count ++;
                        break;
                    }
                }
                if(count == 0){
                    SBuilder.delete(S.length() - 1, S.length());
                }
                if (T.equals(SBuilder.toString())) {
                System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
                return;
            }

            if(S.length() < T.length()){
                StringBuilder TBuilder = new StringBuilder(T);
                int count = 0;
                for (int i = 0; i < T.length() - 1; i++) {
                    if (T.charAt(i) != S.charAt(i)) {
                        TBuilder.delete(i, i+1);  // 文字を変更する
                        count ++;
                        break;
                    }
                }
                if(count == 0){
                    TBuilder.delete(T.length() - 1, T.length());
                }
                if (S.equals(TBuilder.toString())) {
                System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
                return;
            }
        }

        

        
    }

    static class sc {
        static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        static StringTokenizer tokenizer = new StringTokenizer("");

        static String next() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        static int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        static long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        static double nextDoublet() throws IOException {
            return Double.parseDouble(next());
        }
    }
}