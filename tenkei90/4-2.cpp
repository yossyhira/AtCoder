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
    // 入力: H × W のグリッド
    int H, W; cin >> H >> W;
    vector<vector<int> > a(H, vector<int>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> a[i][j];

    // 二次元累積和
    vector<vector<int> > s(H+1, vector<int>(W+1, 0));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            //求めたいマス s[i+1][j+1]の　上＋左-上下の累積の重なりs[i][j]を引く＋最後に求めたいマスの値a[i][j]を足す
            //求めたいマス s[i+1][j+1]の左上s[i][j]基準なので
            //求めたいマス s[i+1][j+1]の 上：s[i][j+1]　左：s[i+1][j]になる
            //最後に求めたいマスの値a[i][j]を足す 
            //👆配列sは外側に無駄な0があるのでs[i+1][j+1]とa[i][j]同じ場所を表している
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int ans = 0;
            //最大値 s[x2][y2]の累積から縦横の余分な累積　s[x1][y2]　s[x2][y1]を引いて
            //重なり部分のs[x1][y1]を余計に引いたので足す
            ans += s[i+1][W] - s[i][W] - s[i+1][0] + s[i][0];
            ans += s[H][j+1] - s[0][j+1] - s[H][j] + s[0][j];
            ans -= a[i][j];
            cout << ans << ' ';
            //s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]
        }
        cout << endl;
    }
        
   
}
/*
//入力
5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

//確認
0 0 0 0 0 0 
0 1 2 3 4 5 
0 2 4 6 8 10 
0 3 6 9 12 15 
0 4 8 12 16 20 
0 5 10 15 20 25 

//クエリ
1
5 5 1 5　//入力の5行目から5行目までの1列目から5列目までの和
5
*/
