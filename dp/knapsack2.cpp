//ナップサックDP
//荷物に入る重さ「ちょうどピッタリ」での最大価値を選ぶ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18; // ありえない小さい値（-∞として使う）

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 宝石の個数と最大の重さ
    int n;
    ll weightMax;
    cin >> n >> weightMax;

    // 重さと価値を格納
    vector<ll> weight(n);
    vector<int> val(n);
    int valMax = 0;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> val[i];
        valMax += val[i];
    }

    // DP配列の初期化
    // dp[i][j]: i個までの宝石を使って、価値を「ちょうど」jにしたときの最大価値
    vector<vector<ll>> dp(n+1, vector<ll>(valMax+1, INF));

    // 価値0のときの重さは0（何も選ばない）
    dp[0][0] = 0;

    // 入れる宝石(i)を決める
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll w = weight[i];

        for (int j = 0; j <= valMax; j++) {
            // 入れない場合（前の状態を引き継ぐ）
            if (dp[i][j] != INF) { 
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);//同じ価値なら重さは軽い方(min)がいい
            }

            // 入れる場合（ちょうどの価値を作れるときのみ）
            if (j - val[i] >= 0 && dp[i][j - val[i]] != INF && (dp[i][j - val[i]] + w) <= weightMax) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j - val[i]] + w);//同じ価値なら重さは軽い方(min)がいい
            }

            //値を更新出来たらその価値を記録
            if (dp[i+1][j] != INF) ans = j;
        }
    }
    cout << ans << endl;
    return 0;
}
