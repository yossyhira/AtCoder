#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n+1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num[i+1] = num[i] + x;
    }

    for (int i = 0; i < n + 1; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int Lx, Rx;
        cin >> Lx >> Rx;
        Lx --;
        cout << num[Rx] - num[Lx] << endl;
    }
    return 0;
}