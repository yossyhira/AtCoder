//状態DP
//カエルが柱を飛ぶ移動コスト
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    //初めに二つ柱を頭に追加
    //DPのときに汎用性あるアルゴリズムにするため
    vector<int> h(n+k);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(i == 0){
            for (int j = 0; j < k; j++) {
                h[j] = num;
            }
        }
        h[i+k] = num;
    }
    //無限でDP配列初期化
    //DPにはその回までの最小コストを格納
    const int INF = 1001001001;
    vector<vector<int>> dp(n+k,vector<int>(k, INF)); //最初2つに0を置きたいため、n+2の配列にしたので注意
    //最初はすべて0で初期化
    for (int i = 0; i < k; i++) dp[0][i] = 0;
    for (int i = 0; i < k; i++) dp[1][i] = 0;

    for (int i = 0; i < n; i++) {
        //DPをおこなう
        for (int j = 0; j < k; j++) {
            //j = 今のやつ
            //j = 0 + 1 のときj+1だから1つ前の1,2をみる
            //j = 1 + 1 のときj+2だから2つ前の1,2をみる
            
            //今やりたい行動(j)のコストを計算
            //(i+2) - (j + 1)👇
            //j = 0 だと一つ前のiを見る
            //j = 1 だと二つ前のiを見る
            int cost = 0;
            cost = abs(h[i + k] - h[(i + k) - (j + 1)]);
           
            for (int befj = 0; befj < k; befj++) {
                //befj = 0のとき前の1
                //befj = 1のとき前の2
                dp[i+k][j] = min(dp[i + k][j], dp[(i+k) - (j + 1)][befj] + cost);
            }
        }
        
    }

    //最後の回の最小値を計算
    int ans = INF;
    for (int i = 0; i < k; i++) {
        ans = min(ans, dp[n+k-1][i]); 
    }
    cout << ans << endl;
}