#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> time(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
        int k;
        cin >> k;
        if(k == 0) a[i].push_back(-1);
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num;
            num --;
            a[i].push_back(num);
        }
    }
    map<int, int> M1;
    ll ans = 0;
    auto f = [&](auto f, int Idx) -> void {
        ans += time[Idx];
        for (int j = 0; j < a[Idx].size(); j++) {
            int a_num = a[Idx][j];
            if(a_num == -1) return;  
            if(!(M1.count(a_num))){
                M1[a_num] = 1;
                f(f, a_num);
            }
        }
    };

    f(f, n - 1);
    cout << ans << endl;
}