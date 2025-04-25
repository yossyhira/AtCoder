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
#define no cout<<"No"<<endl
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> q(n, 0);
    vector<int> a(n, 0);
    vector<int> b(n, 0);

    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    ll maxa = 1001000100100;
    for (int i = 0; i < n; i++){
        if(a[i] == 0) continue;
        chmin(maxa, ll(q[i])/a[i]);
    }
    ll ans = -1;
    for (int i = 0; i <= maxa; i++) {
        ll maxb = 100100100100;
        for (int j = 0; j < n; j++) {
            if(b[j] == 0) continue;
            chmin(maxb, (q[j] - (ll(a[j]) * i))/b[j]);
        }
        chmax(ans, i + maxb);
    }
    cout << ans << endl; 
    return 0;   
}