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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int u,v,b;
        cin >> u >> v >> b;
        u--; v--;
        g[u][v] = b; //uからvに行くためにコストb+a[v]かかる
        g[v][u] = b; //vからuに行くためにコストb+a[v]かかる
    }

    vector<int> p(n); // n! の全探索
    for (int i = 0; i < n; i++) p[i] = i;
    ll ans = 0;
    do {
        ll subAns = 0;
        for (int i = 0; i < n - 1; i++) {
            if(g[p[i]][p[i + 1]] == -1) break;
            subAns += g[p[i]][p[i + 1]];
        }
        chmax(ans, subAns);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}