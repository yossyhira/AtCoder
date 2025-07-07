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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a --; b --;
        g[a].pb(b); g[b].pb(a);
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int ans = INF;
    auto f = [&](int st, int mx){
        int cnt = 0;
        for (int i = st; i <= mx; i++) {
            //i番目と本来つながっていたいもの２つ
            int a, b;
            if(i == st){
                a = p[i + 1];
                b = p[mx];
            }else if(i == mx){
                a = p[st];
                b = p[mx - 1];
            }else{
                a = p[i + 1];
                b = p[i - 1];
            }
            bool a_find = false, b_find = false;
            int sz = g[p[i]].size();
            for (int j = 0; j < sz; j++) {
                if(a == g[p[i]][j]) a_find  = true;
                if(b == g[p[i]][j]) b_find  = true;
            }
            if(a_find && b_find){
                cnt += (sz - 2);
            }else if(!a_find && !b_find){
                cnt += (sz + 2);
            }else{
                cnt += sz;
            }
        }
    };

    do {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            //i番目と本来つながっていたいもの２つ
            int a, b;
            if(i == 0){
                a = p[i + 1];
                b = p[n - 1];
            }else if(i == (n-1)){
                a = p[0];
                b = p[i - 1];
            }else{
                a = p[i + 1];
                b = p[i - 1];
            }
            bool a_find = false, b_find = false;
            int sz = g[p[i]].size();
            for (int j = 0; j < sz; j++) {
                if(a == g[p[i]][j]) a_find  = true;
                if(b == g[p[i]][j]) b_find  = true;
            }
            if(a_find && b_find){
                cnt += (sz - 2);
            }else if(!a_find && !b_find){
                cnt += (sz + 2);
            }else{
                cnt += sz;
            }
        }
        chmin(ans, (cnt / 2));

        if(n == 6){

        }else if(n == 7){

        }else if(n == 8){

        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}