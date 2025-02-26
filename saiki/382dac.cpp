//枝かり全列挙ver(無駄なやつは列挙しない)
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

    //末尾がm以下の時(10 * (n - a.size()))で最後の答えをしる
    //一番最後のループはn - size() = 0になるので
    //a.back() <= m でmを超えない範囲で1を足し続けてくれる
    while (a.back() + 10 * (n - a.size())<= m) {
      f(f,a);
      a.back()++; //末尾に１を足して次を調べる(新たに配列の要素を増やすわけではない)　-> 例えば　a{1}; a[0] = 1; => a.back()++; a[0] = 2; 
      //足したら上のf(f, a)にループ
      //実質、ここで1足された値をaに追加したと同じになる
      //イメージ↓
      //f(f, 1);
      //1 ++;
      //f(f, 2);
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