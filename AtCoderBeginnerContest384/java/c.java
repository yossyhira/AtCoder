import java.util.*;
import java.io.*;

public class c {
    public static void main(String[] args) throws IOException {
        // スコアと対応するクエスト
        int[] score = new int[5];
        char[] quest = {'A', 'B', 'C', 'D', 'E'};

        // 入力を受け取る
        for (int i = 0; i < 5; i++) {
            score[i] = sc.nextInt();
        }
        int count2 = 0;
        // 部分集合の合計をキーにして、対応する文字列をマップに保存
        Map<Integer, String> mMap = new HashMap<>();
        for (int i = 0; i < (1 << 5); i++) { // 部分集合の生成
            int sum = 0;
            
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < 5; j++) {
                if ((i & (1 << j)) != 0) { // 部分集合に含まれる場合
                    sum += score[j];
                    sb.append(quest[j]);
                }
            }

            // 合計が0でない場合のみマップに追加
            if (sum != 0) {
                mMap.put(sum, sb.toString());
            }else{
                System.out.println(i);
            }
            count2++;
        }
        System.out.println(count2);
        System.out.println(mMap.size());

        // キー（合計値）でソートして出力
        List<Integer> sortedKeys = new ArrayList<>(mMap.keySet());
        sortedKeys.sort(Collections.reverseOrder()); // 降順ソート
        // sortedKeys の長さ分だけループを回す
        ArrayList<String> list = new ArrayList<>();
        int count = 0;
        for (int i = 0; i < sortedKeys.size() - 1; i++) {
            int key = sortedKeys.get(i);
            int nextkey = sortedKeys.get(i + 1);

            if(key != nextkey && count == 0){
                String value = mMap.get(key);
                System.out.println(value);
            }
            else if(key != nextkey && count != 0){
                String value = mMap.get(key);
                list.add(value);
                Collections.sort(list);
                for (String str : list) {
                    System.out.println(str);
                }
                count = 0;
            }
            else{
                String value = mMap.get(key);
                list.add(value);
                count ++;
            }
        }

        int key = sortedKeys.get(sortedKeys.size()-1);
        if(count == 0){
            String value = mMap.get(key);
            System.out.println(value);
        }else{
            String value = mMap.get(key);
            list.add(value);
            Collections.sort(list);
            for (String str : list) {
                System.out.println(str);
            }
        }

    }

    // 入力を扱う便利なクラス
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

        static double nextDouble() throws IOException { // 修正
            return Double.parseDouble(next());
        }
    }
}
