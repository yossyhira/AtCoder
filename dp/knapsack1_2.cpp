//ナップサック思い出し練習 2025.06.18 wed
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
struct Item {
  ll w, v;
  Item() : w(0), v(0) {}
  Item(ll w, ll v): w(w), v(v) {}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<Item> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i].w >> num[i].v;
    }
    //for(Item x : num) cout << x.w << x.v << endl;
    vector<vector<ll>> dp(n+1, vector<ll>(w+1, -LINF));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= w; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int weight = num[i-1].w;
        int value = num[i-1].v;
        for (int j = 1; j <= w; j++) {
            //荷物に入れる
            if(0 <= (j-weight)) chmax(dp[i][j], dp[i-1][j-weight]+value);

            //入れない
            chmax(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}