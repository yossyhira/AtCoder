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
    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };
    int h, w;
    cin >> h >> w;
    vector<string> mp(h);
    for (int i = 0; i < h; i++) {
        cin >> mp[i];
    }
    bool ok = true;
    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            int cnt = 0;
            if(mp[x][y] == '#'){
                for (int direction = 0; direction < 4; ++direction) {
                    //xの移動
                    int next_x = x + dx[direction];
                    //yの移動
                    int next_y = y + dy[direction];

                    //高さ(縦)x、幅(横)yで取ったので、xが高さ・yが幅の範囲内か確認
                    if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) continue;
                    //壁か確認
                    if (mp[next_x][next_y] == '#') cnt ++;
                }

                if(cnt != 2 && cnt != 4) ok = false;
            }
        }
    }
    if(ok) yn;
}