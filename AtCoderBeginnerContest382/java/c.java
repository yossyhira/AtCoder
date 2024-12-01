import java.util.*;
import java.io.*;

public class c {
    public static void main(String[] args)throws IOException {
        int n = sc.nextInt();
        int m  = sc.nextInt();
        int[] a = new int[n];
        int sushi = 0;
        a[0] = sc.nextInt();
        for (int i = 1; i < n; i++) {
            a[i] = sc.nextInt();
            a[i] = Math.min(a[i-1], a[i]);
        }
        for (int i = 0; i < m; i++) {
            int ac = n-1, wa = 0; 
            sushi = sc.nextInt();
            if(a[n-1] > sushi){
                System.out.println(-1);
                continue;
            }
            else if(a[0] <= sushi){
                System.out.println(1);
                continue;
            }
        //(ac - wa) > 1の間ループ。for分みたいにＯＯまでじゃないことに注意。
            while((ac - wa) > 1){
                int judgeNum = ((ac - wa) / 2) + wa;
                //int judgeNum = ((ac + wa) / 2);　上を式変形するとこれになる。
                
                if(judge(a,judgeNum, sushi)){
                    ac = judgeNum;
                }else{
                    wa = judgeNum;
                }
            }

            System.out.println(ac+1);
            
        }
        
       
    }
    // Moved the judge method outside the main method
    public static boolean judge(int[] a, int judgeNum, int sushi) {
        //寿司がa番目の人の美味度以上ならtrue
        if(a[judgeNum] <= sushi){
            return true;
        }else{
            return false;
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