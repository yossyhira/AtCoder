#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n);
    vector<ll> w(m);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> w[i];
    }
    sort(b.begin(), b.end(), greater<ll>());
    sort(w.begin(), w.end(), greater<ll>()); 
    ll roop = min(n, m);
    ll ans = 0;
    vector<ll> dp(n + 1, 0);
    for (ll i = 1; i <= roop; i++) {
       ll subAns = ll(b[i - 1]) + dp[i - 1];
       //cout << subAns << endl;
       if((subAns + w[i - 1]) > dp[i - 1] && (subAns + w[i - 1]) > subAns ) subAns += ll(w[i - 1]);
       //cout << subAns << endl;
       dp[i] = subAns;
       ans = max(ans, dp[i]);
    }
    //cout << ans << endl;
    if(n > m){
        for (int i = roop; i < n; i++) {
            ll subAns = ll(b[i]) + dp[i];
            dp[i + 1] = subAns;
            ans = max(ans, dp[i + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}