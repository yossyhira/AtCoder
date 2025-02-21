#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    vector<int> Rcnt(26, 0);
    vector<int> Lcnt(26, 0);
    for (int i = 0; i < text.size(); i++) {
        int Idx = text.at(i) - 'A';
        Rcnt[Idx] ++;
    }
    ll ans = 0;
    for (int i = 0; i < text.size(); i++) {
        int Idx = text.at(i) - 'A';
        Rcnt[Idx]--;
        for (int j = 0; j < 26; j++) {
            ans += ll(Lcnt[j]) * ll(Rcnt[j]);
        }
        Lcnt[Idx]++;
    }
    cout << ans << endl;

    return 0;
}
