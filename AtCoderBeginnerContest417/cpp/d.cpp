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
    vector<int> p(n);
    vector<int> a(n);
    vector<int> b(n);
    vector<int> sum_b(n+1, 0); 
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> a[i] >> b[i];
        sum_b[i+1] = sum_b[i] + b[i];
    }
    //cout << sum_b[n] << endl;
    const int t = 1000;
    vector<vector<int>> dp(n, vector<int>(t+1, 0));
    for (int j = 0; j <= t; j++) {
        if(j <= p[n-1]) dp[n-1][j] = a[n-1] + j;
        else dp[n-1][j] = max(j - b[n-1], 0);
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j <= t; j++) {
            int num;
            if(j <= p[i]) num = a[i] + j;
            else num = max(j - b[i], 0);
            dp[i][j] = dp[i + 1][num];
        }
    }
    auto f = [&](int r) {
        int pos = upper_bound(sum_b.begin(), sum_b.end(), r) - sum_b.begin();
        return pos;
    };
    int q;
    cin >> q;
    for (int qi = 0; qi < q; qi++) {
        int x;
        cin >> x;
        int idx = 0;
        int ans = 0;
        if(t < x) {
            idx = f(x - t);
            if(n <= idx){
                ans = x - sum_b[n];
            }else{
                int j = x - sum_b[idx];
                ans = dp[idx][j];
            }
        }else{
            ans = dp[idx][x];
        }
        cout << ans << endl;

    }
}