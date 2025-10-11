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
    int n, m;
    cin >> n >> m;
    vector<P> a;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u --; v --;
        a.pb({u, v});
    }

    int ans = INF;
    for (int i = 0; i < (1 << n); i++) {
        int cut = 0;
        for (int j = 0; j < m; j++) {
            int u, v;
            tie(u, v) = a[j];
            if (((i >> u) & 1) == ((i >> v) & 1)) {
                cut++;
            }
        }
        ans = min(ans, cut);
    }
    cout << ans << endl;
}
