#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int mod = 1e8;
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> num(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        num[i] = a;
        ans += a*(n-1);
    }
    sort(num.begin(), num.end());
    auto f = [&](ll r, int Idx) {
        int pos = lower_bound(num.begin() + Idx, num.end(), r) - num.begin(); //lower_bound(x.begin(), x.end(), r) - x.begin();
        return pos;
    };
    ll count = 0;
    for (int i = 0; i < n; i++) {
        ll nowNum = mod - num[i];
        int pos = f(nowNum, i + 1);
        if(pos < n){
            count += ll(n - pos);
        }
    }
   cout << ans - (count * mod) << endl;
}