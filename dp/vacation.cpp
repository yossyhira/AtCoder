//状態DP
//じゃんけんで前の手を連続せずに勝つ最大値を求める
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> happiness(n,vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> happiness[i][j];
        }
    }
    //マイナス無限でDP配列初期化
    //DPにはその回までの各手の置ける幸福の最大値を格納
    const int INF = 1001001001;
    vector<vector<int>> dp(n+1,vector<int>(3, -INF)); //最初0を置きたいため、n+1の配列にしたので注意
    //最初はすべて0で初期化
    for (int i = 0; i < 3; i++) dp[0][i] = 0;

    for (int i = 0; i < n; i++) {
        for (int nowj = 0; nowj < 3; nowj++) {

            int happy = happiness[i][nowj];
            
            //前に出した手までの勝利数を0~2ですべて調べる
            for (int befj = 0; befj < 3; befj++) {
                //前と同じ活動はダメ
                if(nowj == befj) continue;

                //前の回の結果をもとに今回の手の最大値を計算
                dp[i + 1][nowj] = max(dp[i + 1][nowj], dp[i][befj] + happy);
            }
        }
    }

    //最後の回の各手における勝利数の最大値を計算
    int ans = max({dp[n][0], dp[n][1], dp[n][2]}); 
    cout << ans << endl;
}