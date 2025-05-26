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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> field(h,vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> field[i][j];
        }
    }
    ll ans = -1;
    bool one = false;
    int acnt = 0;
    for (int i = 0; i < (1 << (h*w)); i++) {
        if( __builtin_popcount(i) % 2 != 0) continue;
        vector<vector<int>> bit_field(h+1,vector<int>(w+1, 0));
        vector<vector<bool>> used(h+1,vector<bool>(w+1, false));
        int hcnt = 0, wcnt = 0, onecnt = 0;
        bool out = false;
        ll subans = 0;
        for (int j = 0; j < (h*w); j++) {
            if((i & (1 << j)) != 0){
                bit_field[hcnt][wcnt] = 1;
            }else{
                bit_field[hcnt][wcnt] = 0;
            }
            wcnt ++;
            if(wcnt == w){
                wcnt = 0;
                hcnt ++;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
               
            }
        }

        if(!out) chmax(ans, subans);
    }
    cout << ans << endl;
}