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
    vector<int> dp(n+k, INF); //最初2つに0を置きたいため、n+2の配列にしたので注意
    //最初はすべて0で初期化
    for (int i = 0; i < k; i++) dp[i] = 0;
    

    for (int i = 0; i < n; i++) {
        //DPをおこなう
        for (int j = 0; j < k; j++) {
            //j = 今のやつ
            //j = 0 + 1 のときj+1だから1つ前の1,2をみる
            //j = 1 + 1 のときj+2だから2つ前の1,2をみる
            int cost = 0;
            cost = abs(h[i + k] - h[(i + k) - (j + 1)]);
           
            dp[i+k] = min(dp[i + k], dp[(i+k) - (j + 1)] + cost);
        }
        
    }

    //最後の回の最小値を計算
    cout << dp[n+k-1] << endl;
}