#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string text;
    cin >> n >> text;
    vector<int> one;
    int oneCount = 0;
    for (int i = 0; i < text.size(); i++) {
        if(text.at(i) == '1'){
            oneCount ++;
            one.push_back(i);
        }
    }
    //一か所に集めるのは中央値が最適
    int point = oneCount / 2;
    ll ans = 0;
    for (int i = 0; i < point; i++) {
        ans += ll(one.at(point) - one.at(i) - i - 1);
        //cout << ans << endl;
    }
    int count = 0;
    for (int i = point+1; i < one.size(); i++) {
        ans += ll(one.at(i) - one.at(point) - count - 1);
        count ++;
    }
    cout << ans << endl;
}