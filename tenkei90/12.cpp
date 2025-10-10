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
#define yesr {cout<<"Yes"<<endl; return 0;}
#define no cout<<"No"<<endl
#define nor {cout<<"No"<<endl; return 0;}
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7;
const int x[4] = {1, -1, 0, 0};
const int y[4] = {0, 0, 1, -1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    //h*w頂点にする
    dsu uf(h*w);
    vector<vector<bool>> red(h, vector<bool>(w, false));
    int q;
    cin >> q;
    //頂点番号に変換
    //r, cは 0-idx!!!!
    auto rc2n = [&](int r, int c){
        return (r*w + c);
    };
    for (int qi = 0; qi < q; qi++) {
        int t;
        cin >> t;
        if(t == 1){
            int r, c;
            cin >> r >> c;
            r --; c --;
            red[r][c] = true;
            int add_num = rc2n(r, c);
            for (int i = 0; i < 4; i++) {
                int nr = r + x[i];
                int nc = c + y[i];
                if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;

                if(red[nr][nc]){
                    int base_num = rc2n(nr, nc);
                    uf.merge(base_num, add_num);
                }
            }
        }else{
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1 --; c1 --; r2 --; c2--;

            if(red[r1][c1] && red[r2][c2] && uf.same(rc2n(r1, c1), rc2n(r2, c2))) yn;
        }
    }

}