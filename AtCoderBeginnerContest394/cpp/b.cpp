#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<string, int>> s;
    for (int i = 0; i < n; i++) {
        string text;
        cin >> text;
        s.push_back({text, text.size()});
    }
    sort(s.begin(), s.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;//第2引数
    });
    for (int i = 0; i < n; i++) {
        string st;
        int len;
        tie(st, len)= s[i];
        cout << st;
    }
    cout << endl;
    return 0;
}