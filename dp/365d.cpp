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
    string text;
    cin >> text;
    //マイナス無限でDP配列初期化
    //DPにはその回までの各手の置ける勝利数の最大値を格納
    const int INF = 1001001001;
    vector<vector<int>> dp(n+1,vector<int>(3, -INF)); //最初0を置きたいため、n+1の配列にしたので注意
    //最初はすべて0で初期化
    for (int i = 0; i < 3; i++) dp[0][i] = 0;

    for (int i = 0; i < n; i++) {
        //文字だと扱いづらいので相手の手を数値変換
        int x = 0;
        if(text.at(i) == 'R') x = 0;
        else if(text.at(i) == 'P') x = 1;
        else if(text.at(i) == 'S') x = 2;

        //DPをおこなう
        //今出す手を0~2で全探索
        for (int nowHand = 0; nowHand < 3; nowHand++) {
            //相手の手に勝てば＋１, あいこは０, 今回は負ける場合は計算しない(問題記載)
            int win = 0;
            if(x == (nowHand + 2) % 3) win = 1;
            else if( x == (nowHand + 1) % 3) continue;
            
            //前に出した手までの勝利数を0~2ですべて調べる
            for (int befHand = 0; befHand < 3; befHand++) {
                //前の手と同じ手は出せない
                if(nowHand == befHand) continue;

                //前の回の結果をもとに今回の手の最大値を計算
                dp[i + 1][nowHand] = max(dp[i + 1][nowHand], dp[i][befHand] + win);
            }
        }
    }

    //最後の回の各手における勝利数の最大値を計算
    int ans = max({dp[n][0], dp[n][1], dp[n][2]}); 
    cout << ans << endl;
}