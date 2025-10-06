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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    vector<ll> dig(n-1);
    for (int i = 0; i < (n-1); i++) {
        dig[i] = num[i] - num[i+1];
    }

    ll ans = 0;
    for(auto x: dig) ans += abs(x);
    //cout << ans << endl;
    for (int i = 0; i < q; i++) {
        int l, r;
        ll v;
        cin >> l >> r >> v;
        //0-idxなので-1する．
        //lは自分の場所の前の差分なのでさらに-1する．
        l -= 2; r --;

        //変動前の差の大きさ求める
        ll bef_l = 0, bef_r = 0;
        if(0 <= l)bef_l = abs(dig[l]);
        if(r < (n-1))bef_r = abs(dig[r]);

        //変動計算
        if(0 <= l)dig[l] = dig[l] - v;
        if(r < (n-1))dig[r] = dig[r] + v;

        //変動後の差の大きさ
        ll aft_l = 0, aft_r = 0;
        if(0 <= l) aft_l = abs(dig[l]);
        if(r < (n-1)) aft_r = abs(dig[r]);

        //変動前後の絶対値の差の合計が変化量
        //aft - befなのは
        //bef = 6, aft = 7 なら aft - bef で1増えた
        //bef = 6, aft = 5 なら aft - bef で-1増えた
        //となり正しいことが分かる
        ans += ((aft_l - bef_l) + (aft_r - bef_r));  
        cout << ans << endl;
    }
}