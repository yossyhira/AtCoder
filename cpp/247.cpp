#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int query;
    cin >> query;
    vector<ll> num;
    vector<int> ball;
    int get = 0;
    for (int i = 0; i < query; i++) {
        int que;
        cin >> que;
        if(que == 1){
            int n, b;
            cin >> n >> b;
            num.push_back(ll(n) * b);
            ball.push_back(b);
        }else{
            ll ans = 0;
            int b;
            cin >> b;
            while(1){
                //全部取り出せる
                if(b > ball[get]){
                    b -= ball[get];
                    ans += num[get];
                    get ++;
                }
                else if(b == ball[get]){
                    b -= ball[get];
                    ans += num[get];
                    get ++;
                    break;
                }else{
                    ll bNum = num[get] / ball[get];
                    ball[get] -= b;
                    ans += bNum * b;
                    num[get] = bNum * ball[get];
                    break;
                } 
            }
            cout << ans << endl;
        }
    }
}