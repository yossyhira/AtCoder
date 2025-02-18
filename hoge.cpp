#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int addNum(int a){
    return (a * (a + 1)) / 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
   int sum = addNum(a);
    cout << sum << endl;
}