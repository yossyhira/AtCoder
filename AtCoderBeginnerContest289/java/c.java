import java.util.*;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // NとMを読み込み
        int N = sc.nextInt();
        int M = sc.nextInt();


        // 二次元リストを初期化
        List<List<Integer>> groups = new ArrayList<>();

        // M 個のグループを読み込む
        for (int i = 0; i < M; i++) {
            int C = sc.nextInt(); // このグループの要素数

            // グループの要素を格納するリストを作成
            List<Integer> group = new ArrayList<>();
            for (int j = 0; j < C; j++) {
                group.add(sc.nextInt()); // 各要素を追加
            }

            // グループを二次元リストに追加
            groups.add(group);
        }
        sc.close();

        int ans = 0;

        for (int i = 0; i < (1 << M); i++) {
            int[] ansArray = new int [N];

            for (int j = 0; j < M; j++) {
                if((i & (1 << j)) != 0){
                    for (int k = 0; k < groups.get(j).size(); k++) {
                        int num = groups.get(j).get(k) - 1;
                        ansArray[num] = 1;
                    }
                }
            }
            int sum = 0;
            for (int l = 0; l < N; l++) {
                sum += ansArray[l];
            }
            if(sum == N){
                ans++;
            }
        }
        System.out.println(ans);

    }
}
/*
入力
3 3
2　
1 2　<= これを入れる
2
1 3　<= これを入れる
1
2　<= これを入れる

出力
1 2 
1 3 
2 
*/