//ユニオンファインドで頂点に値を乗っけるやつ
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
    dsu uf(n);
    //リーダーのグループの黒頂点の個数
    vector<int> l(n, 0);
    //その頂点が白か黒か
    vector<int> c(n, 0);
    for (int qi = 0; qi < q; qi++) {
        int x;
        cin >> x;
        if(x == 1){
            int u, v;
            cin >> u >> v;
            u --; v --;
            int lu = uf.leader(u);
            int lv = uf.leader(v);
            //仲間でなければくっつける
            if(lu != lv){
                //マージはグループのサイズが大きい方に統合されるので
                // リーダーがluかlvどどちらかになる
                uf.merge(u, v);
                // lu, lvのどっちがリーダーか分からないのでもう一度リーダー調べる
                int w=uf.leader(lu);
                l[w]=l[lu]+l[lv];
            }
        }else if(x == 2){
            int u;
            cin >> u;
            u --;
            int lu = uf.leader(u);
            //白黒反転(XOR)
            c[u] ^= 1;
            if(c[u]) l[lu] ++;
            else l[lu] --;
        }else{
            int u;
            cin >> u;
            u --;
            int x = uf.leader(u);
            if(0 < l[x]) yn;
        }
    }
}