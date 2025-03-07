#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n*3);
    for (int i = 0; i < (n*3); i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end(), greater<int>()); 
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += num[i * 2 - 1];
    }
    cout << ans << endl;
    return 0;
}