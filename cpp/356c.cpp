#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) num[i] = i;
    vector<vector<int>> q(m);
    vector<char> open(m); 
    for (int i = 0; i < m; i++) {
        int c;
        cin >>c;
        for (int j = 0; j < c; j++) {
            int a;
            cin >> a;
            a--;
            q[i].push_back(a);
        }
        cin >> open[i];
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> okKey;
        for (int j = 0; j < n; j++) {
            if((i & (1 << j)) != 0){
                okKey.push_back(j);
            }
        }
        int ansCount = 0;
        for (int i = 0; i < m; i++) {
            int openCount = 0;
            for (int j = 0; j < q[i].size(); j++) {
                int keyNum = q[i][j];
                auto it = find(okKey.begin(), okKey.end(), keyNum);
                int ans = (it != okKey.end()) ? distance(okKey.begin(), it) : -1;
                if(ans != -1)openCount++;
            }
            if((openCount >= k && open[i] == 'o') || (openCount < k && open[i] == 'x')) ansCount++;
        }
        if(ansCount == m) ans++;
    }
    cout << ans << endl;
    return 0;
}