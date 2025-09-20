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
const int dx[2] = { 1, 0};
const int dy[2] = { 0, 1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int h,w;
        cin >> h >> w;
        vector<string> mp(h);
        for (int i = 0; i < h; i++) {
            cin >> mp[i];
        }
        vector<vector<bool>> ok(h, vector<bool>(w, false));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(i+1<h && j+1 < w &&
                    mp[i][j] == '#' &&
                   mp[i+1][j] == '#' &&
                   mp[i][j + 1] == '#' &&
                   mp[i+1][j+1] == '#') ok[i][j] = true;
            }
        }
        ll ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(ok[i][j]){
                    ok[i][j] = false;
                    ll q = ans;
                    for (int direction = 0; direction < 2; ++direction) {
                        //xの移動
                        int next_x = i + dx[direction];
                        //yの移動
                        int next_y = j + dy[direction];
                        if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) continue;
                        if(ok[next_x][next_y]){
                            ans++;
                            ok[next_x][next_y] = false;
                        }
                    }
                    if(q == ans) ans ++;
                }  
            }
        }
        cout << ans << endl;
    }
}