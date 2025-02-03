#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  int n, w;
  cin >> n >> w;
  //xが列、yが行
  vector<int> x(n), y(n);
  rep(i,n) {
    cin >> x[i] >> y[i];
    x[i]--;
  }

  //ブロックの場所(行順)
  vector<int> idx(n);
  rep(i,n) idx[i] = i;
  
  /*cout << "ソート前" << endl;
   for (int i = 0; i < idx.size(); i++) {
    cout << idx[i] << endl;
  }*/
  sort(idx.begin(), idx.end(), [&](int i, int j) {
    return y[i] < y[j];
  });
  
  /*cout << "ソート後 idx" << endl;
  for (int i = 0; i < idx.size(); i++) {
    cout << idx[i] << endl;
  }*/
  //そのブロックが下から何個目か
  vector<int> r(n);
  //どの列に何個あるか
  vector<int> num(w);

  /*cout << "r" << endl;
   for (int i = 0; i < r.size(); i++) {
    cout << r[i] << endl;
  }

  cout << "num" << endl;
   for (int i = 0; i < num.size(); i++) {
    cout << num[i] << endl;
  }*/
  
  for (int i = 0; i < n; i++) {
    //x[idx[i]]で指定したブロック番号のブロックが 
    //その列で下から何個目かをrに記録
    r[idx[i]] = num[x[idx[i]]];
    //その列の値を1増やす
    num[x[idx[i]]]++;
  }

  /*cout << "r" << endl;
   for (int i = 0; i < r.size(); i++) {
    cout << r[i] << endl;
  }

  cout << "num" << endl;
   for (int i = 0; i < num.size(); i++) {
    cout << num[i] << endl;
  }*/

  const int INF = 1001001001;
  //各段が消えるタイミング(消えなければ無限時間なるようにする)
  vector<int> d(n,INF);
  {
    //各段目に何番のブロックがあるか記録
    vector<vector<int>> blocks(n);
    //各段のブロック番号を追加　例blocks[0][1,4,5] -> 0段目に1,4,5がある
    rep(i,n) blocks[r[i]].push_back(i);
    rep(i,n) {
      //その段が消えなければコンティニュー
      if (blocks[i].size() != w) continue;
      int mx = 0;
      // その段の全てのブロックの最大値を取得
      //揃う秒数
      for (int j : blocks[i]) mx = max(mx, y[j]-1);
     
      //消えるのに追加で1秒
      d[i] = mx+1;
    }
  }
  
  

  int q;
  cin >> q;
  rep(qi,q) {
    int t, a;
    cin >> t >> a;
    a--;
    if (d[r[a]] > t) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}