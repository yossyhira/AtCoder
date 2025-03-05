#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

int main() {
  int n, m, x;
  cin >> n >> m >> x;
 ///////////////////////////////////////////////////////////////////////
 //拡張ダイクストラは複数のパターンの頂点を用意(今回は順方向・逆方向の2パターン)
 // i : 頂点番号 (6 頂点の場合(i = 0 ~ 5))
 // a : 普通のパターン頂点(順方向) => (i * 2) - 2
 // b : 特殊パターン頂点(逆方向) => (i * 2) - 1
 // i | 0 | 1 | 2 | 3 | 4 | 5 |
 // a | 0 | 2 | 4 | 6 | 8 | 10 |
 // b | 1 | 3 | 5 | 7 | 9 | 11 |
  vector<vector<Edge>> g(n*2);
  for (int i = 1; i <= n; i ++) {
    int from = (i * 2) - 2;
    int to = (i * 2) - 1;
    //順方向から逆方向に変えるときのコスト
    g[from].emplace_back(to, x); 
    g[to].emplace_back(from, x);
  }
  for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      //順方向同士のコスト
      int conU = (u * 2) - 2; 
      int conV = (v * 2) - 2;
      g[conU].emplace_back(conV, 1); //移動のコストは1

      //逆方向同士のコスト
      int revU = (u * 2) - 1; 
      int revV = (v * 2) - 1;
      g[revV].emplace_back(revU, 1); //移動のコストは1
  }

  const ll INF = 1e18;
  vector<ll> dist(2*n, INF); //各頂点までのコストを格納(確定済みと未確定のやつが入ってる)dist[0]には頂点0のコスト

  //最短距離の候補を入れる
  priority_queue<P, vector<P>, greater<P>> q;//小さい順(昇順)に取り出す
  //priority_queue<P> q;//大きい順(降順)に取り出す
  // 降順は(priority_queue<P, vector<P>, less<P>> q;)とも書けるが、less<P>>はデフォルトで省略される(上とやってることは全く同じ)
  dist[0] = 0; //最初の距離は0 dist[スタート頂点] = 初期コスト;
  q.emplace(0, 0); //最初の頂点は0 q.emplace(初期コスト, スタート頂点);

  while (!q.empty()) {
    ll d; //距離(コスト)
    int point; //頂点
    tie(d, point) = q.top(); q.pop();
    //dist[point]には今の距離が入ってる
    //dが今の距離と違う = 更新前のキューを取り出したので見ない(結果は変わらないけど無駄な探索になる)
    //一致したら最短距離確定
    if (dist[point] != d) continue;
    
    //今の頂点point(確定済み)からいける場所をすべて試す
    for (int goPoint = 0; goPoint < g[point].size(); goPoint++) {
      //その頂点からいける場所とコストを取得
      Edge e = g[point][goPoint];
      //その場所までのコストdと行先の道のコストを足して
      // 行先のコストを取得
      ll newd = d + e.cost;
      //新しいコストのほうが行先のコストe.to以上ならコンティニュー
      if (dist[e.to] <= newd) continue;
      //距離を更新
      dist[e.to] = newd;
    
      //新しいコストと行先を追加
      q.emplace(newd,e.to);
    }
  }
  //2パターンの内の最小を選ぶ
  cout << min(dist[(n * 2) - 2], dist[(n * 2) - 1])<< endl;
  return 0;
}