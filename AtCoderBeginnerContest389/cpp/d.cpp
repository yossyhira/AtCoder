#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_inBox(int x, int y, int r){
    ll NewX, NewY;
    NewX = 2 * ll(x) + 1;
    NewY = 2 * ll(y) + 1;

    ll ans = NewX * NewX + NewY * NewY;
    if(ans <= 4*(ll(r)*ll(r))) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r;
    cin >> r;
    const int INF = 1001001001;
    ll ans = 0;
    for (int y = 0; y <= r; y++) {
        int ac = 0, wa = INF;
        //×と〇の境界になるまで(差が１)ループ
        while (wa - ac > 1) {
            int x = (wa+ac)/2;
            //cout << x << endl;
            if (is_inBox(x, y, r)){
                ac = x;
                //cout << "OK" << endl;
            }
            else {
                wa = x;
                //cout << "No" << endl;
            }
        }
        ans += ll(ac);
    }
    ans *= 4;
    ans ++;
    cout << ans << endl;
}
