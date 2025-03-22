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
    
    int ans = -1, subans = -1;
    for (int i = 1; i <= n; i++) {
        int bef_num, bef_Idx;
        tie(bef_num, bef_Idx) = a.at(i - 1);

        int now_num, now_Idx;
        tie(now_num, now_Idx) = a.at(i);

        int nex_num, nex_Idx;
        tie(nex_num, nex_Idx) = a.at(i + 1);

        if(bef_num != now_num && nex_num != now_num){
            int befAns = subans;
            subans = max(subans, nex_num);
            if(subans != befAns){
                ans = now_Idx;
            }
        }
    }
    cout << ans << endl;
    return 0;
}