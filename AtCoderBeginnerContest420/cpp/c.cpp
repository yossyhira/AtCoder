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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min(a[i], b[i]);
    }

    for (int qi = 0; qi < q; qi++) {
        char c;
        cin >> c;
        int x;
        ll v;
        cin >> x >> v; 
        x --;
        if(c == 'A'){
            ll bef = min(a[x], b[x]);
            a[x] = v;
            ll aft = min(a[x], b[x]);
            if(bef != aft){
                ans -= (bef - aft);
            }
        }else{
            ll bef = min(a[x], b[x]);
            b[x] = v;
            ll aft = min(a[x], b[x]);
            if(bef != aft){
                ans -= (bef - aft);
            }            
        }
        cout << ans << endl;
    }
}