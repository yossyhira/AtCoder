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
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    const int mx = 1e5;
    vector<vector<int>> dp(n+1, vector<int>(mx+1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= mx; j++) {
            if(dp[i-1][j] == INF) continue;
            chmin(dp[i][j], dp[i-1][j] + num[i-1]);
            chmin(dp[i][j+num[i-1]], dp[i-1][j]);
        }
    }
    int ans = INF;
    for (int j = 0; j <= mx; j++) {
        int a = j;
        if(dp[n][j] == INF) continue;
        chmax(a, dp[n][j]);
        chmin(ans, a);
    }
    cout << ans << endl;
}