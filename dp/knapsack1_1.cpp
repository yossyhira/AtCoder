//ナップサックDP
//荷物に入る重さ「ちょうどピッタリ」での最大価値を選ぶ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = -1e18; // ありえない小さい値（-∞として使う）

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 宝石の個数と最大の重さ
    int n, weightMax;
    cin >> n >> weightMax;

    // 重さと価値を格納
    vector<ll> weight(n);
    vector<ll> val(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> val[i];
    }

    // DP配列の初期化
    // dp[i][j]: i個までの宝石を使って、重さを「ちょうど」jにしたときの最大価値
    vector<vector<ll>> dp(n+1, vector<ll>(weightMax+1, INF));

    // 重さ0のときの価値は0（何も選ばない）
    dp[0][0] = 0;

    // 入れる宝石(i)を決める
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll value = val[i];

        for (int j = 0; j <= weightMax; j++) {
            // 入れない場合（前の状態を引き継ぐ）
            if (dp[i][j] != INF) { 
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }

            // 入れる場合（ちょうどの重さを作れるときのみ）
            if (j - weight[i] >= 0 && dp[i][j - weight[i]] != INF) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j - weight[i]] + value);
            }

            if (dp[i+1][j] != INF) ans = max(ans, dp[i+1][j]);
        }
    }

    cout << ans << endl;
    return 0;
}
