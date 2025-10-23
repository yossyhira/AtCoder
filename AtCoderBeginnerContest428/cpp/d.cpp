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
    int t;
    cin >> t;
    auto cnt_digit = [&](ll x){
        ll cnt_d = 1;
        while(10 <= x){
            x /= 10;
            cnt_d ++;
        }
        return cnt_d;
    };
    auto pw = [&](ll x, int n){
        ll cnt_pow = 1;
        for (int i = 0; i < n; i++) {
            cnt_pow *= x;
        }
        return cnt_pow;
    };
    auto cnt_sqrt = [&](ll x){
        ll ac = 0, wa = 3e9;
        while(1 < (wa - ac)){
            ll mid = (wa + ac) / 2;
            if((mid * mid) <= x) ac = mid;
            else wa = mid;
        }
        return ac;
    };
    for (int ti = 0; ti < t; ti++) {
        ll c, d;
        cin >> c >> d;
        ll ans = 0;
        for (int i = 1; i <= cnt_digit(c+d); i++) {
            ll l = max((ll)1, (pw(10, i-1) - c));
            ll r = min(d, pw(10, i) - 1 - c);
            if(r < l) continue;
            //cout << cnt_sqrt(c*pw(10, i) + c + r) << " "<<cnt_sqrt(c * pw(10, i) + c + l - 1)<< endl;
            ans += cnt_sqrt(c*pw(10, i) + c + r) - cnt_sqrt(c * pw(10, i) + c + l - 1);
        }
        cout << ans << endl;
    }
}