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
    ll n, k;
    cin >> n >> k;

    //コーナーケース
    if(n == 1){
        cout << k << endl;
        return 0;
    }else if(n == 2){
        if(k == 1){
            cout << 0 << endl;
            return 0;
        }else{
            cout << ((k * (k-1)) % mod) << endl;
            return 0;
        }
    }else if(3 <= n){
        if(k < 3){
            cout << 0 << endl;
            return 0;
        }
    }
    //通常
    ll ans = 1;
    //計算量(log n);
    auto f = [&](auto f, ll k, ll n){
        if(n == 1) return k;
        else if((n % 2) == 0){
            //k ^ 4 = k ^ 2 * k ^ 2; 
            ll x = f(f, k, n / 2);
            return ((x * x) % mod);
        }else{
            //k ^ 5 = k * k ^ 4;
            ll x = f(f, k, n-1);
            return ((k * x) % mod);
        }
    };
    // 制約から k < modより
    ans = (ans * k) % mod;
    ans = (ans * (k - 1)) % mod;
    ans = (ans * f(f, k - 2, n-2)) % mod;
    cout << ans << endl;
}