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
    int n;
    cin >> n;
    vector<vector<ll>> num(n, vector<ll> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num[i][j];
        }
    }
    vector<int> p(n); // 3! の全探索
    for (int i = 0; i < n; i++) p[i] = i;
    int m;
    cin >> m;
    set<P> se;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a --; b --;
        if(b < a) swap(a, b);
        se.insert({a, b});
    }
    ll ans = LINF;
    do {
        bool ok = true;
        ll now_ans = 0;
        for (int i = 0; i < n; i++) {
            if(0 < i){
                int bef_p = p[i-1]; 
                int now_p = p[i];
                if(now_p < bef_p) swap(bef_p, now_p);
                if(se.count({bef_p, now_p})) ok = false;
            }
            now_ans += num[p[i]][i];
        }
        if(ok) chmin(ans, now_ans);
    } while (next_permutation(p.begin(), p.end()));

    if(ans == LINF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}