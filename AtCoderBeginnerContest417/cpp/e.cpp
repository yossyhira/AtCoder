#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
//#define eb emplace_back
//#define em emplace
//#define pob pop_back
//using ld = long double;
using Graph = vector<vector<int>>;
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
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        swap(x, y);
        Graph g(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> vi(n, false);
        vector<int> ans;
        ans.pb(x);
        int now = x;
        vi[x] = true;
        while(1){
            int mn = INF;
            for (int i = 0; i < g[now].size(); i++) {
                if(!vi[g[now][i]])chmin(mn, g[now][i]);
            }
            ans.pb(mn);
            vi[mn] = true;
            now = mn;
            if(mn == y) break;
        }

        for(auto a : ans){
            cout << a + 1<< " ";
        }
        cout << endl;
    }
}