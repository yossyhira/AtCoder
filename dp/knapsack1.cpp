//ナップサックDP
//荷物に入る重さいないで最大価値を選ぶ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //宝石の個数と最大の重さ
    int n, weightMax;
    cin >> n >> weightMax;

    //重さと価値を格納
    vector<ll> weight(n);
    vector<ll> val(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> val[i];
    }
    //0でDP配列初期化
    //DPにはその回までかつその重さ内での最大価値を格納
    //最大価値がintの範囲外になる可能性に注意(long long にする)
    vector<vector<ll>> dp(n+1,vector<ll>(weightMax+1, 0)); //1行目と1列目に0を置きたいため、n+1, weightMax+1の配列にしたので注意

    //入れる宝石(i)を決める
    for (int i = 0; i < n; i++) {

        //その宝石の価値
        ll value = val[i];

        //各jの重さが限界の重さであると仮定して、その重さ内での最大価値について探索
        for (int j = 0; j <= weightMax; j++) {
            
            //入れる場合
            //追加した宝石がその重さ(j)以内だったら
            //重さの限界値のjをweight[i]超えていたら
            //j - weight[i]がマイナスになり、宝石が入らないと判定できる
            //つまりj - weight[i]が0以上なら宝石が入る
            if((j - weight[i]) >= 0){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j - weight[i]] + value);
            }

            //入れない場合
            //上記で重さ(j)以内に入っても（入らなくても）宝石を入れなかった場合が最大価値になる可能性があるので調べる
            //宝石を入れなかったということは、つまり重さも価値も0の物を入れたとも考えられるので
            // weight[i] = 0, value = 0より（dp[i][j - weight[i]] + value = dp[i][j -0] + 0 = dp[i][j]）となり
            // 純粋に自分の前の宝石ときの最大価値（dp[i][j]）を引き継ぐ
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
        
    }

    //最後の回の最大価値を調べる
    //n個眼目の宝石の処理が終わって、
    //重さがweightMax以内のときの最大価値は[n][weightMax]番目になる
    cout << dp[n][weightMax] << endl;
    return 0;
}