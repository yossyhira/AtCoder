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
    ll l, r;
    cin >> l >> r;
    auto cnt_lenge = [&](ll x){
        ll cnt = 1;
        while(10 <= x){
            x /= 10;
            cnt ++;
        }
        return cnt;
    };
    int l_lenge = cnt_lenge(l);
    int r_lenge = cnt_lenge(r);
    ll ans = 0;

    auto cnt_ans = [&](ll l, ll r, int len){
        return (((((((l + r) % mod)*(((r - l) + 1)%mod)) % mod / 2)%mod) * len) % mod);

    };
    auto f_min = [&](){

    };
    auto f_max = [&](){

    };

    if(l_lenge == r_lenge){
        //合計＊長さ
        ans = cnt_ans(l, r, l_lenge);
    }else{
        /*
        Ｌ桁の最大値とＲ桁の最小値求めてそれを例外処理
        Ｌ＋１以上Ｒ未満桁の最大最小求めて上の長さ一致の式で計算
        最大．最小，長さ一致関数するか～～
        */
    }
    cout << ans << endl;
}