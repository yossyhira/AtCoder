import java.util.*;
import java.io.*;

public class b {
    public static void main(String[] args)throws IOException {
        String text = sc.next();
        char[] s = text.toCharArray();
        int count = 0;
        int ans = 0;
        boolean zero = false;

        for (int i = 0; i < text.length(); i++) {
            if(s[i] != '0' && !(zero)){
                ans++;
            }

            else if(s[i] == '0'){
                count++;
                zero = true;
            }

            else if(s[i] != '0' && zero){
                ans += count / 2;
                ans += count % 2;
                count = 0;
                ans ++;
                zero = false;
            }
        }
        if(count > 0){
            ans += count / 2;
            ans += count % 2;
        }
        System.out.println(ans);
        
        
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