#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<tuple<int, int, int>> field;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        field.push_back({i, x, y});
    }
    
    stable_sort(field.begin(), field.end(), [](const auto &a, const auto &b) {
        return get<2>(a) < get<2>(b);
    });

    cout << << endl;
}