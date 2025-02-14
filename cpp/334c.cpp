#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    if(k == 1){
        cout << 0 << endl;
        return 0;
    }

    vector<tuple<int, int, int>> socks;
    for (int i = 1; i < k; i++) {
        int num = abs(a[i - 1] - a[i]);
        socks.push_back({num, a[i-1], a[i]});
    }

    stable_sort(socks.begin(), socks.end(), [](const auto &a, const auto &b) {
        return get<0>(a) < get<0>(b);//第一
    });

    vector<bool> used(200020, false);
    ll ans = 0;
    for (int i = 0; i < k - 1; i++) {
        int strange, sockx, socky;
        tie(strange, sockx, socky) = socks[i];
        if(!used[sockx] && !used[socky]){
            ans += strange;
            used[sockx] = true;
            used[socky] = true;
        }
    }
    cout << ans << endl;
}