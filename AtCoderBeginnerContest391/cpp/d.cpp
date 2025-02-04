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
  
  sort(idx.begin(), idx.end(), [&](int i, int j) {
    return y[i] < y[j];
  });
  

  //そのブロックが下から何個目か
  vector<int> r(n);
  //どの列に何個あるか
  vector<int> num(w);

  for (int i = 0; i < n; i++) {
    //x[idx[i]]で指定したブロック番号のブロックが 
    //その列で下から何個目かをrに記録
    r[idx[i]] = num[x[idx[i]]];
    //その列の値を1増やす
    num[x[idx[i]]]++;
  }

  const int INF = 1001001001;
  //各段が消えるタイミング(消えなければ無限時間なるようにする)
  vector<int> d(n,INF);
  //変数の適用範囲を限定(スコープ管理)のために{}を付ける。無駄なメモリを使わない
  {
    //各段目に何番のブロックがあるか記録
    vector<vector<int>> blocks(n);
    //各段のブロック番号を追加　例blocks[0][1,4,5] -> 0段目に1,4,5がある
    rep(i,n) blocks[r[i]].push_back(i);
    //ここのfor文二重ループだけど実際はO(N)
    rep(i,n) {
      //その段が消えなければコンティニュー
      if (blocks[i].size() != w) continue;
      
      //消える秒数
      int mx = 0;

      // その段の全てのブロックの高さ(y)最大値を取得
      //for (int j : blocks[i]) mx = max(mx, y[j]-1);
      for (int j = 0; j < blocks[i].size(); j++) {
        int blocksNum = blocks[i][j];
        mx = max(mx, y[blocksNum]);
      }
      //消える秒数を追加
      d[i] = mx;
    }
  }
  
  

  int q;
  cin >> q;
  rep(qi,q) {
    int t, a;
    cin >> t >> a;
    a--;
    //何段目か求めていつ消えるか判定
    if (d[r[a]] > t) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}