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
    int n;
    cin >> n;
    vector<ll> r(n);
    vector<ll> c(n);
    vector<LP> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> c[i];
        mp[i].fi = r[i];
        mp[i].se = c[i];
    }

    sort(all(r));
    sort(all(c));

    ll x = r[r.size()/2], y = c[c.size()/2];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (abs(x - mp[i].fi) + abs(y - mp[i].se)); 
    }
    cout << ans << endl;
}