#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
    vector<vector<int>> num(n);
    dsu uf(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        num[x].pb(y);
        num[y].pb(x);
          //abくっつける
          uf.merge(x,y);
    }
    if(n != m){
        no;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if(num[i].size() != 2){
            no;
            return 0;
        }
    }
    vector<vector<int>> num1 = uf.groups();
    if(num1.size()!= 1){ no; return 0;}
    yes;
}