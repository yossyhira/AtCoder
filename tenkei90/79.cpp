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
const int dx[3] = { 1, 0, 1};
const int dy[3] = { 0, 1, 1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(a[i][j] != b[i][j]){
                bool ok = true;
                for (int direction = 0; direction < 3; ++direction) {
                    //xの移動
                    int next_x = i + dx[direction];
                    //yの移動
                    int next_y = j + dy[direction];
                    //高さ(縦)x、幅(横)yで取ったので、xが高さ・yが幅の範囲内か確認
                    if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) ok = false;
                }
                if(ok){
                    int add = b[i][j] - a[i][j];
                    a[i][j] += add;
                    ans += abs((ll)add);
                    for (int direction = 0; direction < 3; ++direction) {
                        //xの移動
                        int next_x = i + dx[direction];
                        //yの移動
                        int next_y = j + dy[direction];
                        a[next_x][next_y] += add; 
                    }
                }
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(a[i][j] != b[i][j]) ok = false;
        }
    }
    if(ok){
        yes;
        cout << ans << endl;
    }
    else no;

}