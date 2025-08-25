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
    
    vector<vector<bool>> used_o(h, vector<bool>(w, false));
    vector<vector<bool>> used_x(h, vector<bool>(w, false));
    vector<vector<int>> dist_o(h, vector<int>(w, -1));
    vector<vector<int>> dist_x(h, vector<int>(w, -1));
    dist_o[si][sj] = 0; 
    used_o[si][sj] = true; 
    priority_queue<P, vector<P>, greater<P>> q;//小さい順(昇順)に取り出す
    vector<pair<P, bool>> memo;
    q.emplace(0, 0);
    memo.pb({{si, sj}, true});
    int ans = -1;
    auto check = [&](int i, int j, bool o){
        char ng = 'o';
        if(!o) ng = 'x';
        bool ok = false;
        for (int direction = 0; direction < 4; ++direction) {
             //iの移動
            int next_i = i + di[direction];
            //jの移動
            int next_j = j + dj[direction];
            if (next_i < 0 || next_i >= h || next_j < 0 || next_j >= w) continue;
            if(s[next_i][next_j] != ng && s[next_i][next_j] != '#') ok = true;
        }
        return ok;
    };
    auto add = [&](int i, int j, int d, bool o){
        if(o){
            dist_o[i][j] = d;
            used_o[i][j] = true;
        }else{
            dist_x[i][j] = d;
            used_x[i][j] = true;
        }
        memo.pb({{i, j}, o});
        int sz = memo.size() - 1;
        q.emplace(d, sz);
    };
    while(!q.empty()){
        int d, idx;
        tie(d, idx) = q.top(); q.pop();
        int i, j;
        bool o;
        pair<int, int> mp;
        tie(mp, o) = memo[idx];
        i = mp.fi;
        j = mp.se;
        if(gi == i && gj == j){
            ans = d;
            break;
        }else if(s[i][j] == '?'){
            bool ok = check(i, j, o);
            if(ok){
                for (int direction = 0; direction < 4; ++direction) {
                    //iの移動
                    int next_i = i + di[direction];
                    //jの移動
                    int next_j = j + dj[direction];
                    if (next_i < 0 || next_i >= h || next_j < 0 || next_j >= w) continue;
                    if(o){
                        if(s[next_i][next_j] == '#') continue;
                        else if(s[next_i][next_j] == 'x' || s[next_i][next_j] == 'G'|| s[next_i][next_j] == 'S'){
                            if(!used_x[next_i][next_j]) add(next_i, next_j, d + 1, false);
                        }
                        else if(s[next_i][next_j] =='.'){
                            if(!used_x[next_i][next_j]) add(next_i, next_j, d + 1, false);
                            if(!used_o[next_i][next_j]) add(next_i, next_j, d + 3, true);
                        }else if(s[next_i][next_j] == '?'){
                            if(!used_x[next_i][next_j]) add(next_i, next_j, d + 1, false);
                        }else{
                            if(!used_o[next_i][next_j]) add(next_i, next_j, d + 3, true);
                        }
                    }else{
                        if(s[next_i][next_j] == '#') continue;
                        else if(s[next_i][next_j] == 'o'|| s[next_i][next_j] == 'G'){
                            if(!used_o[next_i][next_j]) add(next_i, next_j, d + 1, false);
                        }
                        else if(s[next_i][next_j] =='.'){
                            if(!used_o[next_i][next_j]) add(next_i, next_j, d + 1, false);
                            if(!used_x[next_i][next_j]) add(next_i, next_j, d + 3, true);
                        }else if(s[next_i][next_j] == '?'){
                            if(!used_o[next_i][next_j]) add(next_i, next_j, d + 1, true);
                        }else{
                            if(!used_x[next_i][next_j]) add(next_i, next_j, d + 3, true);
                        }
                    }
                }
            }
        }else{
            for (int direction = 0; direction < 4; ++direction) {
                //iの移動
                int next_i = i + di[direction];
                //jの移動
                int next_j = j + dj[direction];
                if (next_i < 0 || next_i >= h || next_j < 0 || next_j >= w) continue;
                if(o){
                    if(s[next_i][next_j] == '#') continue;
                    else if(s[next_i][next_j] == 'x') continue;
                    else{
                         if(!used_o[next_i][next_j])add(next_i, next_j, d + 1, true);
                    }
                }else{
                    if(s[next_i][next_j] == '#') continue;
                    else if(s[next_i][next_j] == 'o') continue;
                    else{
                         if(!used_x[next_i][next_j]) add(next_i, next_j, d + 1, false);
                    }
                }

            }
        }
    }
   cout << ans << endl;
}