import java.util.*;
import java.io.*;

public class b {
    public static void main(String[] args)throws IOException {
        int H = sc.nextInt();
        int W  = sc.nextInt();
        int D = sc.nextInt();
        char[][] n = new char[H][W];
        for (int i = 0; i < H; i++) {
            String hoge = sc.next();
            n[i]= hoge.toCharArray();
        }


        List<Integer> height = new ArrayList<>();
        List<Integer> width = new ArrayList<>();

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if(n[i][j] == '.'){
                    height.add(i);
                    width.add(j);
                }
            }  
        }

        int ans = 0, count = 0;

        for (int i = 0; i < height.size() - 1; i++) {
            char[][] array = new char[H][W]; // コピー先の配列を作成
            for (int j = 0; j < H; j++) {
                array[j] = n[j].clone(); // 1次元配列をコピー
            }

            int oneH = height.get(i); //i
            int oneW = width.get(i); // j
            
            
            for (int j = 0; j < H; j++) {
                for (int k = 0; k < W; k++) {
                    if(array[j][k] =='#')continue;

                    int distance = (Math.abs(j - oneH) + Math.abs(k - oneW));
                        
                    if(distance <= D ){
                        count ++;
                        array[j][k] = '#';
                    }
                }
            }

            for (int j = 1; j < (height.size() - i); j++) {
                int countOne = count;
                int twoH = height.get(j + i);
                int twoW = width.get(j + i);

                char[][] array2 = new char[H][W]; // コピー先の配列を作成
                for (int x = 0; x < H; x++) {
                    array2[x] = array[x].clone(); // 1次元配列をコピー
                }

                for (int k = 0; k < H; k++) {
                for (int l = 0; l < W; l++) {
                    if(array2[k][l] == '#')continue;

                    int distance = Math.abs(k - twoH) + Math.abs(l - twoW);
                    if(distance <= D ){
                        countOne ++;
                        array2[k][l] = '#';
                    }
                 }
                }

                ans = Math.max(ans, countOne);
                
            }
            count = 0;
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