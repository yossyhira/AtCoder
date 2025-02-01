import java.util.*;
import java.io.*;

public class c {
    public static void main(String[] args) throws IOException {
        int numA = sc.nextInt();
        int numB = sc.nextInt();
        int numC = sc.nextInt();
        String text = sc.next();

        System.out.println();
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

        static double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}