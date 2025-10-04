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
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<ll> dp(n + 1, 0);
    for (int i = 0; i < l; i++) {
        dp[i] = 1; //前と行き方変わらない時はそのまま前の値引継ぎ dp[i] = dp[i-1];でもOK(dp[0] = 1で初期化必須)．
    }
    for (int i = l; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-l]) % mod; //通りの組み合わせは足し算
    }
    cout << dp[n] << endl;
}