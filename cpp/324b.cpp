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
bool willOverflow(long long a, long long b) {
    if (a == 0 || b == 0) return false;
    if (a > 0) {
        if (b > 0) {
            return a > LLONG_MAX / b;
        } else {
            return b < LLONG_MIN / a;
        }
    } else {
        if (b > 0) {
            return a < LLONG_MIN / b;
        } else {
            return a != 0 && b < LLONG_MAX / a;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 38; j++) {
            ll a = pow(2, i);
            ll b = pow(3, j);
            if (willOverflow(a, b)) continue;

            ll ans = a * b;
            if(ans == n)yesr;
        }
    }
    nor;
}