import java.util.*;

public class c2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long M = sc.nextLong();
        
        long ans = (N * N);

        // 使用済みの座標を記録するセット
        Set<String> used = new HashSet<>();
        
        for (int i = 0; i < M; i++) {
            int g = sc.nextInt() - 1;
            int r = sc.nextInt() - 1;

            // メインの座標
            if (used.add(g + "," + r)) {
                ans--;
            }
            
            // ナイトの動きの座標
            int[][] moves = {
                {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
            };
            
            for (int[] move : moves) {
                int newG = g + move[0];
                int newR = r + move[1];
                
                if (0 <= newG && newG < N && 0 <= newR && newR < N && used.add(newG + "," + newR)) {
                    ans--;
                }
            }
        }
        sc.close();

        System.out.println(ans);
    }
}
