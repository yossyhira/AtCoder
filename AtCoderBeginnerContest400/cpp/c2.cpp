#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  for (int a = 1; a < 60; a++) {
    n /= 2;
    ll m = sqrtl(n);
    //重複しないように奇数だけ追加
    //1追加して四捨五入する
    ans += (m+1)/2;
  }
  cout << ans << endl;
  return 0;
}