import java.util.*;
import java.io.*;

public class a {
    public static void main(String[] args)throws IOException {
        int[] num = new int[4];
        int[] ok = new int[4];
        int count = 0;
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < 4; i++) {
            num[i] = sc.nextInt();
            if(set.add(num[i])){
                ok[count] = i;
                count ++;
            }
        }

        if(set.size() != 2){
            System.out.println("No");
            return;
        }
        int count1 = 0, count2 = 0;
        for (int i = 0; i < 4; i++) {
            if(!set.add(num[i])){
                if(num[i] == num[ok[0]])count1 ++;
                if(num[i] == num[ok[1]])count2 ++;
            }
        }
        if((count1 == 1 && count2 == 3) || (count1 == 3 && count2 == 1) || (count1 == 2 && count2 == 2)){
            System.out.println("Yes");
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