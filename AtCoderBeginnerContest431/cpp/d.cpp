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

    int N;
    cin >> N;

    vector<int> w(N);
    vector<ll> h(N);
    vector<ll> b(N);
    ll sum_b = 0, sum_w = 0;

    
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> h[i] >> b[i];
        sum_b += b[i];
        sum_w += w[i];
    }

    int max_w = (sum_w / 2);

    vector<ll> dp(max_w + 1, -LINF);
    dp[0] = 0;

    for (int i = 0; i < N; i ++) {
        ll add = h[i] - b[i];
        for (int j = max_w; w[i] <= j; j --) {

            if (dp[j - w[i]] != (-LINF)) {
                chmax(dp[j], dp[j - w[i]] + add);
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j <= max_w; j++) {
        //cout << dp[j] << endl;
        if (dp[j] != (-LINF)) chmax(ans, dp[j]);
    }

    cout << (sum_b + ans) << endl;
}
