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
using Graph = vector<vector<int>>;
#define yes cout<<"Yes"<<endl
#define yesr {cout<<"Yes"<<endl; return 0;}
#define no cout<<"No"<<endl
#define nor {cout<<"No"<<endl; return 0;}
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define all(x) begin(x), end(x)
const int di[4] = { 1, 0, -1, 0 };
const int dj[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    int si, sj, gi, gj;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(s[i][j] == 'S'){
                si = i;
                sj = j;
            }
            else if(s[i][j] == 'G'){
                gi = i;
                gj = j;
            }
        }
    }

    queue<tuple<int,int,int>> q;
    vector<vector<vector<int>>> d(2, vector<vector<int>>(h, vector<int>(w, -1)));
    d[0][si][sj] = 0;
    q.emplace(0, si, sj);
    int ans = -1;
    while(!q.empty()){
        int idx, i, j;
        tie(idx, i, j) = q.front(); q.pop();
        if(gi == i && gj == j){
            ans = d[idx][i][j];
            break;
        }
        for (int direction = 0; direction < 4; ++direction) {
             //iの移動
            int next_i = i + di[direction];
            //jの移動
            int next_j = j + dj[direction];

            int new_idx = idx;
            if(s[i][j] == '?') new_idx = new_idx^1;

            if (next_i < 0 || next_i >= h || next_j < 0 || next_j >= w) continue;
            if ((new_idx == 0 && s[next_i][next_j] == 'x') || (new_idx == 1 && s[next_i][next_j] == 'o') || s[next_i][next_j] == '#') continue;
            if (d[new_idx][next_i][next_j] != -1) continue;

            d[new_idx][next_i][next_j] = d[idx][i][j] + 1;
            q.emplace(new_idx, next_i, next_j);
        }
    }
    cout << ans << endl;
}