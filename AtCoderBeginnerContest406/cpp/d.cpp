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
    int h,w,n;
    cin >> h >> w >> n;
    vector<vector<int>> g(h);
    vector<vector<int>> r(w);
    vector<int> g2(h,0);
    vector<int> r2(w,0);
    vector<bool> lookg(h,false);
    vector<bool> lookr(w,false);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        r[y].pb(x);
    }
    int que;
    cin >> que;
    for (int i = 0; i < que; i++) {
        int q, num;
        cin >> q >> num;
        num --;
        if(q == 1){
            if(!lookg[num]){
                int ans = g[num].size() - g2[num];
                if(ans < 0) ans = 0;
                cout << ans << endl;
                for (int j = 0; j < g[num].size(); j++) {
                    r2[g[num][j]]++;
                }
                lookg[num] = true;
            }else{
                cout << 0 << endl;
            }

        }else{
            if(!lookr[num]){
                int ans = r[num].size() - r2[num];
                
                if(ans < 0) ans = 0;
                cout << ans << endl;
                for (int j = 0; j < r[num].size(); j++) {
                    g2[r[num][j]]++;
                }
                lookr[num] = true;
            }else{
                cout << 0 << endl;
            }
        }
    }
}