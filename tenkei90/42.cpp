#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
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
//const int mod = 1e9 + 7;
using mint = modint1000000007; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    vector<mint> dp(k+1, mint(0));
    dp[0] = mint(1);
    const int x = 9;
    if((k % x) == 0){
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= x; j++) {
                if(0 <= (i - j)) dp[i] += dp[i - j];
            }
        }
        cout << dp[k].val() << endl;
    }else{
        cout << 0 << endl;
    }
}