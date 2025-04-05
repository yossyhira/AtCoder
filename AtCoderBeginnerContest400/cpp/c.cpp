#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 整数の床 sqrt を返す
ll isqrt(ll x) {
    ll r = floor(sqrt((long double)x));
    while ((r+1)*(r+1) <= x) ++r;
    while (r*r > x) --r;
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    ll a = N >> 1;    // floor(N/2)
    ll b = N >> 2;    // floor(N/4)
    ll ans = isqrt(a) + isqrt(b);

    cout << ans << "\n";
    return 0;
}
