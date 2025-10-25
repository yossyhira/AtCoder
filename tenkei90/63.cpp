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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> num(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> num[i][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < (1 << h); i++) {
        vector<int> choes;
        for (int j = 0; j < h; j++) {
            if((i & (1 << j)) != 0){
                choes.pb(j);
            }
        }
        //これがないと以下でokだったときchoes[0]が無くてsegmentfoltする
        if(choes.size() == 0) continue;
        
        //自動で初期値0になってる．map＜key, 値＞
        map<int, int> M1;
        int mx = -1, subans;
        for (int k = 0; k < w; k++) {
            bool ok = true;
            for (int j = 0; j < ((int)choes.size() - 1); j++) {
                if(num[choes[j]][k] != num[choes[j + 1]][k])  ok = false;
            }
            if(ok){
                M1[num[choes[0]][k]] ++;
                int now = M1[num[choes[0]][k]];
                if(mx < now){
                    mx = now;
                    subans = now * (int)choes.size();
                }
            }
       }
       chmax(ans, subans);
    }
    cout << ans << endl;
}