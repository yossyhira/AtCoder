#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
//#define eb emplace_back
//#define em emplace
//#define pob pop_back
//using ld = long double;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define yes cout<<"Yes"<<endl
#define yesr {cout<<"Yes"<<endl; return 0;}
#define no cout<<"No"<<endl
#define nor {cout<<"No"<<endl; return 0;}
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> now_money(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> now_money[i];
    }
    vector<int> bounus_money(n+1, 0);
    for (int i = 0; i < m; i++) {
        int c, y;
        cin >> c >> y;
        bounus_money[c] = y;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -LINF));
    dp[0][0] = 0;
    //i = 何回目のトス
    //j = 何連続で成功した
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            //表
            chmax(dp[i+1][j+1], (ll)dp[i][j] + now_money[i+1] + bounus_money[j+1]);

            //裏
            chmax(dp[i+1][0], (ll)dp[i][j]);
        }
    }

    ll ans = -LINF;
    for (int j = 0; j <= n; j++) {
        chmax(ans, dp[n][j]);
    }
    cout << ans << endl;

}