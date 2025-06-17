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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, m;
    cin >> n >> h >> m;
    vector<vector<int>> dph((n+1), vector<int>(h+1, -INF));
    vector<P> en;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        en.pb({a, b});
    }
    dph[0][h] = m;
    //i: 敵
    //j:体力or魔力
    for (int i = 1; i <= n; i++) {
        int eh, em;
        tie(eh, em) = en[i-1];
        int ok_hp = 0, ok_maryoku = 0;
        for (int j = 0; j <= h; j++) {
            if(dph[i-1][j] == -INF){
                ok_hp ++;
                ok_maryoku ++;
                continue;
            } 
            //体力使った
            if(0 <= (j - eh))chmax(dph[i][j-eh], dph[i-1][j]);
            else ok_hp  ++;
            //魔力使った
            if(0 <= (dph[i-1][j] - em)) chmax(dph[i][j],  dph[i-1][j] - em);
            else ok_maryoku  ++;
        }
        if(ok_hp == (h+1) && ok_maryoku == (h+1)){
            cout << i - 1<< endl;
            return 0;
        }
    }
    cout << n << endl;
}