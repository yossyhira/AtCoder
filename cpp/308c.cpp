#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> ab;
    for(int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        //{分子，分母}
        ab.emplace_back(a, a + b);
    }

    vector<int> p(n);
    //iotaは配列の指定した場所の区間，指定した値から1ずつ単調増加させた値を入れていく
    //この場合はpの最初から末尾まで0から1ずつ単調増加させた値を入れていく
    //p[0] = 0, [1] = 1, [2] = 2,・・・[n-1] = n-1;
    iota(p.begin(), p.end(), 0);

    //分母：ab[j].second，分子：ab[j].first
    //同じ値の物は順序保ちたいのでstable_sort:O(n* (log n)^2);
    stable_sort(p.begin(), p.end(), [&](int i, int j) {
        return ab[i].first * ab[j].second > ab[j].first * ab[i].second;
    });
    
    //空白区切りで最後に改行入れたいとき用 空白改行 改行空白
    //" \n"[i == n - 1]は
    //(i == n - 1) ? '\n' : ' '
    //と同じ意味
    for(int i = 0; i < n; i++) cout << p[i] + 1 << " \n"[i == n - 1];
}