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
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<vector<int>> mp(h, vector<int>(w, 0));
    for (int i = 0; i < n; i++) {
        int x_l, y_l, x_r, y_r;
        cin >> x_l >> y_l >> x_r >> y_r;
        x_l --; y_l --; x_r --; y_r --;

        mp[x_l][y_l] ++;
        if((x_r + 1) < h) mp[x_r + 1][y_l] --;
        if((y_r + 1) < w) mp[x_l][y_r +1] --;
        if((x_r + 1) < h && (y_r + 1) < w)mp[x_r + 1][y_r + 1] ++;
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
    //全体表示
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
    //最大値取得
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            chmax(ans, mp[i][j]);
        }
    }
    cout << ans << endl;
}

/*
(https://imoz.jp/algorithms/imos_method.html)
あなたは様々な種類のモンスターを捕まえるゲームをしています．
今あなたがいるのは W×H のタイルからなる草むらです．
この草むらでは N 種類のモンスターが現れます．
モンスター i は Ai≦x<Bi, Ci≦y<Di の範囲にしか現れません．
このゲームを効率的に進めるため，1 つのタイル上で現れるモンスターの種類の最大値が知りたいです．
（ただし，W×H は計算可能な程度の大きさとし，N は大きくなりうるものとします．）

h w
n
Ai Bi Ci Di

6 6
3
1 1 4 4
4 2 5 3
3 3 6 6
*/