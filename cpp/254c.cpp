#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    vector<vector<int>> sep(k);
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        sep[i % k].push_back(ans[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) {
        sort(sep[i].begin(), sep[i].end());
    }
    vector<int> test;
    for (int i = 0; i < ((n/k) + 1); i++) {
        for (int j = 0; j < k; j++) {
            if(sep[j].size() > i){
                test.push_back(sep[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if(ans[i] != test[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}