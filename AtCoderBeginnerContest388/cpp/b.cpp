#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, D;
    cin >> N >> D;
    vector<pair<int, int>> snake;
    for (int i = 0; i < N; i++) {
        int t, l;
        cin >> t >> l;
        snake.push_back({t, l});
    }
    for (int i = 1; i <= D; i++) {
        int ans = 0;
        for (int j = 0; j < N; j++) {
            int t, l;
            tie(t, l) = snake.at(j);
            int h = 0;
            h = (l+i) * t;
            ans = max(ans, h);
        }
        cout << ans << endl;
    }
}