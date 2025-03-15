#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int ans = 0;
    if(s[0] == 'o') ans ++;
    for (int i = 0; i < (s.size() - 1); i++) {
        if(s[i] == 'i' && s[i + 1] != 'o') ans ++;
        if(s[i] == 'o' && s[i + 1] != 'i') ans ++;
    }
    if(s[s.size() - 1] == 'i') ans ++;
    cout << ans << endl;
    return 0;

}