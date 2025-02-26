//すべてのパターンを全列挙ver(TLEする)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> ans;

  //ここで配列を宣言すると前状態の配列を引き継げる
  //末尾を毎回消す必要ない
  //ラムダ式ではauto f = [&](auto f)で引数に自分を呼び出すことで再帰になる
  auto f = [&](auto f, vector<int> a) {
    if (a.size() == n) {
      ans.push_back(a); 
      return;
    }

    int l = 1; //最初の一回用に1を入れる
    if (a.size() > 0) l = a.back()+10;
    a.push_back(l);

    //末尾がm以下の時
    while (a.back() <= m) {
      f(f,a);
      a.back()++; //末尾に１を足して次を調べる
    }
  };

  //空の配列を引数にする
  f(f, vector<int>());

  cout << ans.size() << '\n';
  for (auto a : ans) {
    rep(i,n) cout << a[i] << ' ';
    cout << '\n';
  }
  return 0;
}