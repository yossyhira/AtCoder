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
#define all(p) p.begin(),p.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n;
        ll m;
        cin >> n >> m;
        ll sum = 0;
        vector<ll> a(n);
       
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sum += b[i];
        }

        sort(all(a));
        sort(all(b), greater<ll>());
        ll cnt = 0;
         auto f = [&](ll r, int idx) {
            int pos = lower_bound(a.begin() + idx, a.end(), r) - a.begin();
            return pos;
        };
        int id = 0;
        for (int i = 0; i < n; i++) {
            ll x = m - b[i];
            int p = f(x, id);
            if(p == n) continue;
            if((m - b[i]) <= a[p]){
                id = p + 1;
                cnt ++;
            }
        }
        cout << sum - (cnt * m) << endl;
    }
}