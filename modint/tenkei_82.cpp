#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

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
const ll mod = 1e9 + 7;

// ================= ACL modint =================
using mint = modint1000000007;
// =============================================

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
    
    auto cnt_ans = [&](ll l, ll r, int len){
        mint L = l;
        mint R = r;
        mint n = (R - L + 1);
        mint res = (L + R) * n / mint(2);
        res *= mint(len);
        return res;
    };
     
    auto f_min = [&](int n){
        ll x = 1;
        for (int i = 0; i < (n-1); i++) {
            x *= 10;
        }
        return x;
    };
    auto f_max = [&](int n){
        ll x = 1;
        for (int i = 0; i < n; i++) {
            x *= 10;
        }
        x --;
        return x;
    };
    
    mint ans = 0;
    if(l_lenge == r_lenge){
        //合計＊長さ
        ans = cnt_ans(l, r, l_lenge);
    }else{
        /*
        Ｌ桁の最大値とＲ桁の最小値求めてそれを例外処理
        Ｌ＋１以上Ｒ未満桁の最大最小求めて上の長さ一致の式で計算
        引数は桁数で最大・最小，長さ一致関数するか～～
        */
        ll mx_l = f_max(l_lenge);
        ans = cnt_ans(l, mx_l, l_lenge);
        
        for (int i = (l_lenge + 1); i < r_lenge; i++) {
            ll mn = f_min(i);
            ll mx = f_max(i);
            ans = ans + cnt_ans(mn, mx, i);
        }
        
        ll mn_r = f_min(r_lenge);
        ans = ans + cnt_ans(mn_r, r, r_lenge);
    }
    cout << ans.val() << endl; // ← mint の値は .val() で出力
}
