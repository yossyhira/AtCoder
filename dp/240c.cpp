#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= x; j++) {
            if(dp[i][j] == true){
                int aj = j + a;
                int bj = j + b;
                if(aj <= x) dp[i + 1][aj] = true;
                if(bj <= x) dp[i + 1][bj] = true;
            }
        }
    }
    if(dp[n][x])cout << "Yes" << endl;
    else cout << "No" << endl;
}