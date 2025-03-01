#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    ll ans = 0;
    if(l == r){
        int judge;
        judge = abs(a - l) % m;
        if(judge == 0) ans++;
    }
    else if(l < a && a < r){
        ans = abs(a - l) / m;
        ans += abs(a - r) / m;
        ans ++;
    }
    else if(l < a && r < a){
        ans = abs(a - l) / m;
        ans -= abs(a - (r + 1)) / m;
    }
    else if(a < l && a < r){
        ans = abs(a - r) / m;
        ans -= abs(a - (l - 1)) / m;
    }
    else if(l == a){
        ans = abs(a - r) / m;
        ans ++;
    }
    else if(r == a){
        ans = abs(a - l) / m;
        ans ++;
    }

    cout << ans << endl;
}