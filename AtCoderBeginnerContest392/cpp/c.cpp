#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<pair<int, int>> people;
    vector<pair<int, int>> zk;
    vector<int> anszk;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        people.push_back({i, p});
    }
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        zk.push_back({i, p});
        anszk.push_back(p);
    }
    sort(zk.begin(), zk.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;//第1引数
    });
    
    for (int i = 0; i < n; i++) {
        int zp, znum;
        tie(zp, znum) = zk.at(i);
        int pp, pnum;
        tie(pp, pnum) = people.at(zp);
        pnum --;
        int ans = anszk.at(pnum);
        cout << ans << " ";
    }
}