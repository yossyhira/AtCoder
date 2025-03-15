#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    //cin >> n;
    ll q = 1e8, w = (1e8 - 1);
    n = (q * q * q) - (w* w * w);
    cout << n << endl;
    for (ll i = 1; i <= 100000000; i++){
        ll x_3 = n + (i * i * i);
        //ll x = static_cast<long long>(cbrt(x_3));
        ll x = cbrt(x_3);
        ll check = (x * x * x) - (i* i * i);
        if(check == n){
            cout << x << " " << i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
    //ll x = 28;
    //cout << cbrt(x) << endl;
}