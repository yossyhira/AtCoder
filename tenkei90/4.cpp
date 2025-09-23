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

    vector<int> h(H,0);
    vector<int> w(W,0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            h[i] += a[i][j];
            w[j] += a[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
           cout << h[i] + w[j] - a[i][j] << ' ';
        }
        cout << '\n';
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
