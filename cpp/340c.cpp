#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> m;
ll f(ll a) {
    if(a == 1) return 0;
    if(m.count(a)) return m[a];
    m[a] = f(a/2) + f((a+1)/2) + a;
    return m[a];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a;
    cin >> a;

    cout<< f(a) << endl;  // 改行を追加
}
