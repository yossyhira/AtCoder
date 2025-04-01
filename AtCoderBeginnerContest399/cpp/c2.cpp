#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  int ans = 0;
  dsu uf(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (uf.same(a,b)) {
      ans++;
      continue;
    }
    uf.merge(a,b);
  }
  vector<vector<int>> num = uf.groups();
  for (int i = 0; i < num.size(); i++) {
    for (int j = 0; j < num[i].size(); j++) {
      cout << num[i][j] << " ";
    }
    cout << endl;
  }
  cout << ans << endl;
  return 0;
}