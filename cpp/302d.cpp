#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vector<ll> a(n);
    vector<ll> b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto f = [&](ll r) {
        int pos = upper_bound(b.begin(), b.end(), r) - b.begin();
        pos --;
        return pos;
    };
    ll ans = -1;
    for (int i = 0; i < n; i++) {
        ll num = a[i] + d;
        int pos = f(num);
        if(pos == -1) continue;
        ll subAns = b[pos];
        if( (a[i] - d) <= subAns) ans = max(ans, subAns + a[i]);
    }
    cout << ans << endl;
    return 0;
}