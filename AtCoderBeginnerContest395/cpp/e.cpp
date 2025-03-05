#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using T = tuple<ll, int, int>;

struct Edge {
  int to, cost, mode;
  Edge(int to, int cost, int mode): to(to), cost(cost), mode(mode) {}
};

int main() {
  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<Edge>> g(n);
  for (int i = 0; i < m; i++) {
      int u,v;
      cin >> u >> v;
      u--; v--;
      g[u].emplace_back(v, 1, 0); //uからvに行くためにコストb+a[v]かかる
      g[v].emplace_back(u, 1, 1); //vからuに行くためにコストb+a[v]かかる
  }

  const ll INF = 1e18;
  vector<pair<ll, int>> dist(n); //各頂点までのコストを格納(確定済みと未確定のやつが入ってる)dist[0]には頂点0のコスト
  for (int i = 0; i < n; i++) {
    dist[i].first = INF;
    dist[i].second = -1;
  }
  //最短距離の候補を入れる
  priority_queue<T, vector<T>, greater<T>> q;//小さい順(昇順)に取り出す
  //priority_queue<P> q;//大きい順(降順)に取り出す
  // 降順は(priority_queue<P, vector<P>, less<P>> q;)とも書けるが、less<P>>はデフォルトで省略される(上とやってることは全く同じ)
  dist[0].first = 0; //最初の距離はa[0]
  dist[0].second = 0; //最初の距離はa[0]
  q.emplace(0, 0, 0); //最初の頂点は0

  while (!q.empty()) {
    //cout << count << "回目" << endl;
    ll d; //距離(コスト)
    int point; //頂点
    int m; //モード
    tie(d, point, m) = q.top(); q.pop();
    //dist[point]には今の距離が入ってる
    //dが今の距離と違う = 更新前のキューを取り出したので見ない(結果は変わらないけど無駄な探索になる)
    //一致したら最短距離確定
    if (dist[point].first != d) continue;
    
    //cout << "dist[point] : "<< dist[point] << endl;
    //cout << "d : "<< d << endl;
    int nowMode = dist[point].second; 

    //今の頂点point(確定済み)からいける場所をすべて試す
    for (int goPoint = 0; goPoint < g[point].size(); goPoint++) {
      //その頂点からいける場所とコストを取得
      Edge e = g[point][goPoint];
      //その場所までのコストdと行先の道のコストを足して
      // 行先のコストを取得
      ll newd = 0;
      if(e.mode == nowMode) newd = d + 1;
      else newd = d + 1 + x;
      //ll newd = d + e.cost;
      //新しいコストのほうが行先のコストe.to以上ならコンティニュー
      if (dist[e.to].first <= newd) continue;
      //距離を更新
      dist[e.to].first = newd;
      dist[e.to].second = e.mode;
      //新しいコストと行先を追加
      q.emplace(newd,e.to, e.mode);
    }
  }

  cout << dist[n - 1].first << endl;
  return 0;
}