#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> num(m);
    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if(i == num[j]) ok = false;
        }
        if(ok) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[] << " ";
    }
}