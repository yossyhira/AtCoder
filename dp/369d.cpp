//状態DP
//経験値のコスト
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    //値を読み取り(今回は頭に余計な配列不要)
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    //0でDP配列初期化
    //DPにはその回までの最大経験値を格納
    //今回は行動(選ぶ・選ばない)を列にするのではなく、
    //選んだ結果(奇数番目・偶数番目)を列にするのがポイント
    //dp[n][0] -> 奇数番目の敵
    //dp[n][1] -> 偶数番目の敵
    vector<vector<ll>> dp(n,vector<ll>(2, 0)); 
    //最初の敵は絶対奇数番目なので、経験値は確定
    //奇数　-> h[0]
    //偶数　-> 0
   dp[0][0] = h[0];//奇数
    

   //DPをおこなう
    for (int i = 1; i < n; i++) {
        //j = 今回の敵が奇数番目か偶数番目か
        for (int j = 0; j < 2; j++) {

            //今やりたい行動(j)の経験値を計算
            int cost = 0;
            //奇数ならその敵の値、偶数なら二倍
            //j = 0なら奇数でh[i]、偶数ならh[i] + h[i] * 1で二倍になる
            cost = h[i] + (h[i] * j);//jをうまく利用する

            //奇数番目の敵なら
            if(j == 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][0]); //敵(i)を倒さなかった -> 前の奇数番目の経験値を引き継ぐ(経験値追加しない)
                dp[i][j] = max(dp[i][j], dp[i - 1][1] + cost); //敵(i)を倒した -> 前の偶数番目の経験値に今回の経験値を追加

            }else{//偶数番目の敵なら
                dp[i][j] = max(dp[i][j], dp[i - 1][0] + cost);//敵(i)を倒した -> 前の奇数番目の経験値に今回の経験値を追加
                dp[i][j] = max(dp[i][j], dp[i - 1][1]); //敵(i)を倒さなかった -> 前の偶数番目の経験値を引き継ぐ(経験値追加しない)
            }
        }
        
    }

    //最後の回の最大値を計算
    ll ans = max(dp[n-1][0], dp[n-1][1]); 
    cout << ans << endl;
}