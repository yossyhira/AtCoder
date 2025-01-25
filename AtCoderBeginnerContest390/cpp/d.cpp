#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<ll> num;
    for (int i = 0; i < n; i++) {
        ll hoge;
        cin >> hoge;
        num.push_back(hoge);
    }

    set<ll> ans_set;
    for (int i = 0; i < (1 << n); i++) {
    ll sum = 0;
    vector<ll> num2;
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        if((i & (1 << j)) != 0){
            sum += num[j];
        }else{
           num2.push_back(j);
        }
    }
    
    ans ^= sum;
    
    for(auto v: num2) {
        ans ^= num[v];
    }

    ans_set.insert(ans);
}

    cout << ans_set.size()<< endl;
}