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
#define no cout<<"No"<<endl
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> field(h,vector<ll>(w, 0));
    vector<P> field_num;
    {
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> field[i][j];
                field_num.pb({i, j});
            }
        }
    }
    field_num.pb({0, 0});
    vector<vector<bool>> used(h+1,vector<bool>(w+1, false));
    
    ll ans = -1;
    auto f = [&](auto f, int cnt) -> void{
        int i, j;
        tie(i, j) = field_num[cnt];
        if(!used[i][j] && cnt < (h*w)){
            //おかない
            f(f, cnt + 1);

            //縦置き
            if((i + 1) < h){
                used[i][j] = true;
                used[i + 1][j] = true;
                f(f, cnt + 1);
                used[i][j] = false;
                used[i + 1][j] = false;
            }
            
            //横置き
            if((j + 1) < w && !used[i][j + 1]){
                used[i][j] = true;
                used[i][j + 1] = true;
                f(f, cnt + 1);
                used[i][j] = false;
                used[i][j + 1] = false;
            }
        }else if(cnt == (h*w)){
            ll subAns = 0;
            for (int hi = 0; hi < h; hi++) {
                for (int wj = 0; wj < w; wj++) {
                    if(!used[hi][wj]){
                        subAns ^= field[hi][wj];
                    }
                }
            }
            chmax(ans, subAns);
        }else if(used[i][j]){
            f(f, cnt + 1);
        }
    };
    vector<vector<bool>> hoge;
    f(f, 0);
    cout << ans << endl;
}