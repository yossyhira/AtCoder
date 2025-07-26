#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n;
    int m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> ls;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        ll d = a - b;
        ls.emplace_back(d, a, b);
    }
    sort(ls.begin(), ls.end());
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ll d, a, b;
        tie(d, a, b) = ls[i];
        if (a > n) continue;
        ll x = (n - a) / d + 1;
        ans += x;
        n -= x * d;
        cout << ans << "回目 " << a << " "<<b  << " " << n << endl;
    }
    cout << ans << endl;
}
