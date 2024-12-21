import java.util.*;
import java.io.*;

public class b {
    public static void main(String[] args)throws IOException {
        int n = sc.nextInt();
        int rete  = sc.nextInt();
        
        for (int i = 0; i < n; i++) {
            int div = sc.nextInt();
            int num =sc.nextInt();

            if(div == 1 && 1600 <= rete && rete <= 2799 ){
                rete += num; 
            } 
            else if(div == 2 && 1200 <= rete && rete <= 2399 ){
                rete += num; 
            } 
        }
        System.out.println(rete);
        
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