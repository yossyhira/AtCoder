#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    rep(i, n) cin >> num[i];

    ll ans = 0;
    int r = 0, l;

    for(int i = 0; i < n; i++){
        while(r < n){
            if(r > i + 1 && num[r] - num[r - 1] != num[r - 1] - num[r - 2]) break;
            r++;
        }
        ans += r - i;
    }
    cout << ans << endl;
    return 0;
}