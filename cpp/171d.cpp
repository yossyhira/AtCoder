#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> M1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(M1.count(x)){
            M1[x] ++;
        }else{
            M1[x] = 1;
        }
        ans += ll(x);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int b, c;
        cin >> b >> c;
        int cnt = 0;
        if(M1.count(b)){
            cnt = M1[b]; M1[b] = 0;
            ll sum = ll(b) * cnt;
            ans -= sum;
        }

        ans += ll(c) * cnt;

        if(M1.count(c)) M1[c] += cnt;
        else M1[c] = cnt;

        cout << ans << endl;
    }
    return 0;
}