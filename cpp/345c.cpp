#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    vector<int> c(26, 0);
    for (int i = 0; i < text.size(); i++) {
        int num = text.at(i) - 'a';
        c[num]++;
    }
    ll ans = (ll(text.size())*(text.size() - 1)) / 2;
    ll cnt = 0;
    for (int i = 0; i < 26; i++) {
        if(c[i] <= 1) continue;
        
        ans -= (ll(c[i])*(c[i] - 1)) / 2;
        //aaabbbの場合、適当なaとaを選んでswapするとaaabbb
        //また、適当なbとbを選んでswapしてもaaabbbなので
        //cnt++;ではなく同じ文字(複数種でも)があれば1度め以降は既出なので＋１でOK
        cnt = 1;
    }
    cout << ans + cnt << endl;
    return 0;
}