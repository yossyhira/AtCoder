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
    const int INF = 1001001001;
    vector<vector<int>> dp(n+1,vector<int>(3, -INF));
    for (int i = 0; i < 3; i++) dp[0][i] = 0;

    for (int i = 0; i < n; i++) {
        int x = 0;
        if(text.at(i) == 'R') x = 0;
        else if(text.at(i) == 'P') x = 1;
        else if(text.at(i) == 'S') x = 2;

        for (int nowHand = 0; nowHand < 3; nowHand++) {
            int win = 0;
            if(x == (nowHand + 2) % 3) win = 1;
            else if( x == (nowHand + 1) % 3) continue;
            
            for (int befHand = 0; befHand < 3; befHand++) {
                if(nowHand == befHand) continue;
                dp[i + 1][nowHand] = max(dp[i + 1][nowHand], dp[i][befHand] + win);
            }
        }
    }
    int ans = max({dp[n][0], dp[n][1], dp[n][2]}); 
    cout << ans << endl;
}