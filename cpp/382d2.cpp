#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> ans;

void printAns(const vector<int>& current) {
    //cout << 1 << endl;
    ans.push_back(current);
}

void solve(int num, int cnt, vector<int> current) {
    current.push_back(num);
    if (cnt >= n) {
        printAns(current);
        return;
    }
    if(num + 10 > m){
        if(current.size() == n){
            printAns(current);

        }
        return;
    }
    for (int i = num + 10; i <= m; i++) {
        if(i > m){
            printAns(current);
            return; 
        }
        solve(i, cnt + 1, current);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        solve(i, 0, {});
    }
    cout << ans.size() << endl;
    for (const auto& vec : ans) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
