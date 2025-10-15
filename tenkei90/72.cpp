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
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> mp(h);
    for (int i = 0; i < h; i++) {
        cin >> mp[i];
    }
    int st_i, st_j;
    vector<bool> vi(h, vector<bool>(w, false));
    auto f = [&](auto f, int i, int j, int cnt){
        for (int direction = 0; direction < 4; direction++) {
            int next_x = i + dx[direction];
            int next_y = j + dy[direction];
            if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w) continue;
            if (field[next_x][next_y] == '#') continue;
            if(!vi[next_x][next_y]){
                vi[next_x][next_y] = true;
                f(f, i, j, cnt + 1);
                vi[next_x][next_y] = false;
            }
            if(next_x == st_i && next_y == st_j && 3 <= cnt){
                return cnt;
            }
        }
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(mp[i][j] == '.'){
                st_i = i;
                st_j = j;
                vi[st_i][st_j] = true;
                f(f, i, j, 0);
                vi[st_i][st_j] = false;
            }
        }
    }
}