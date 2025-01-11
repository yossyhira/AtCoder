#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> m;
    for (int i = 0; i < N; i++) {
        int mochi;
        cin >> mochi;
        m.push_back(mochi);
    }

    auto f = [&](int r) {
        int pos = upper_bound(m.begin(), m.end(), r) - m.begin();
        return pos;
    };

    long long  ans = 0;

    for (int i = 0; i < N; i++) {
        int num = (m.at(i) / 2);
        int Idx = f(num);
        if(Idx > 0){
            ans += Idx;
        }
    }
    cout << ans << endl;
}