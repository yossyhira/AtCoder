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
    int n;
    cin >> n;

    //制約からhwの上限分かった
    int h = 1000+1;
    int w = 1000+1;
    vector<vector<int>> mp(h, vector<int>(w, 0));
    for (int i = 0; i < n; i++) {
        int x_l, y_l, x_r, y_r;
        cin >> x_l >> y_l >> x_r >> y_r;
        //x_l --; y_l --; x_r --; y_r --; 今回は入力が0-idx
        //左上を原点とすると左上，右下の座標になる
        //右下(xr, yr)が紙の角なのでxr,xrのマスに角が触れてるだけで紙はない
        //座標＋１とかせずにそのまま値いれてOK
        /*
            1 1 3 2
            ....
            .#..
            .#..
            .#..
        */
        mp[x_l][y_l] ++;
        mp[x_r][y_l] --;
        mp[x_l][y_r] --;
        mp[x_r][y_r] ++;
    }
    //横方向にimos
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (w - 1); j++) {
            mp[i][j + 1] += mp[i][j];
        }
    }
    //縦方向にimos
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < (h - 1); j++) {
            mp[j + 1][i] += mp[j][i];
        }
    }
    /*
    //全体表示
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    vector<int> ans(n+1, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(mp[i][j] == 0) continue;
            ans[mp[i][j]] ++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}