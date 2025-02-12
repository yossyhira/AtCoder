//状態DP
//カエルが柱を飛ぶ移動コスト
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    //初めに二つ柱を頭に追加
    //DPのときに汎用性あるアルゴリズムにするため
    vector<int> h(n+2);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(i == 0){
            h[0] = num; h[1] = num;
        }
        h[i+2] = num;
    }
    //無限でDP配列初期化
    //DPにはその回までの最小コストを格納
    const int INF = 1001001001;
    vector<vector<int>> dp(n+2,vector<int>(2, INF)); //最初2つに0を置きたいため、n+2の配列にしたので注意
    //最初はすべて0で初期化
    for (int i = 0; i < 2; i++) dp[0][i] = 0;
    for (int i = 0; i < 2; i++) dp[1][i] = 0;

    for (int i = 0; i < n; i++) {
        //DPをおこなう
        for (int j = 0; j < 2; j++) {
            //j = 今のやつ
            //j = 0 + 1 のときj+1だから1つ前の1,2をみる
            //j = 1 + 1 のときj+2だから2つ前の1,2をみる
            
            //今やりたい行動(j)のコストを計算
            //(i+2) - (j + 1)👇
            //j = 0 だと一つ前のiを見る
            //j = 1 だと二つ前のiを見る
            int cost = 0;
            cost = abs(h[i + 2] - h[(i+2) - (j + 1)]);
           
            for (int befj = 0; befj < 2; befj++) {
                //befj = 0のとき前の1
                //befj = 1のとき前の2
                dp[i+2][j] = min(dp[i + 2][j], dp[(i+2) - (j + 1)][befj] + cost);
            }
        }
        
    }

    //最後の回の最小値を計算
    int ans = min(dp[n+1][0], dp[n+1][1]); 
    cout << ans << endl;
}