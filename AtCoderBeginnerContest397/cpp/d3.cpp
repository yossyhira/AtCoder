#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    for (ll d = 1; (d * d * d) < n; d++) {
        //コメントアウトしたやり方だとcが丸め誤差の影響を考慮する必要がある。
        //if( (n -  (d * d * d)) % (3*d)) continue;
        ll c = (n -  (d * d * d)) / (3 * d);
        ll y = ll((-1 * d) + sqrt((d * d) + (4 * c))) / 2;
        /*ll check = y * y + y * d - c;
        if(check == 0){
            cout << (d + y) << " " << y << endl;
            return 0;
        }*/
        ll check = ((d + y) * (d + y) * (d + y)) - (y * y * y);//cに誤差があるときはここの計算の答えがnと一致しなくなり、if文で弾ける
        if(check == n && y != 0){
            cout << (d + y) << " " << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}