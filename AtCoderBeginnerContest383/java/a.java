import java.util.*;
import java.io.*;

public class a {
    public static void main(String[] args)throws IOException {
        int n = sc.nextInt();
        int beforT = 0;
        int beforeV = 0;

        for (int i = 0; i < n; i++) {
            int nowT = sc.nextInt();
            int nowV = sc.nextInt();

            int time = nowT - beforT;
            int V = beforeV - time; 
            V = Math.max(0, V);

            V += nowV;

            beforT = nowT;
            beforeV = V;
        }
        System.out.println(beforeV);
        
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