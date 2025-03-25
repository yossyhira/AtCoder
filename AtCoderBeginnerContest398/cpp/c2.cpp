#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    a.push_back({-1, 0});
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i + 1});
    }
    const int INF = 2e9;
    a.push_back({INF, 0});
    sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;//第1引数
    });
    
    for (int i = n; i >= 1; i--) {
        if(a.at(i - 1).first != a.at(i).first && a.at(i + 1).first != a.at(i).first){
            cout << a.at(i).second << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}