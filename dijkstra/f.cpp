#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to), cost(cost) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n); //頂点のコスト
  for(int i = 0; i < n; i ++) cin >> a[i];

  vector<vector<Edge>> g(n);
  for (int i = 0; i < m; i++) {
      int u,v,b;
      cin >> u >> v >> b;
      u--; v--;
      g[u].emplace_back(v, b+a[v]); //uからvに行くためにコストb+a[v]かかる
      g[v].emplace_back(u, b+a[u]); //vからuに行くためにコストb+a[v]かかる
  }

  const ll INF = 1e18;
  vector<ll> dist(n, INF); //各頂点までのコストを格納(確定済みと未確定のやつが入ってる)
  //最短距離の候補を入れる
  priority_queue<P, vector<P>, greater<P>> q;//小さい順(昇順)に取り出す
  //priority_queue<P> q;//大きい順(降順)に取り出す
  dist[0] = a[0]; //最初の距離はa[0]
  q.emplace(a[0], 0); //最初の頂点は0

  int count = 0;
  while (!q.empty()) {
    //cout << count << "回目" << endl;
    count ++;
    ll d; //距離
    int point; //頂点
    tie(d, point) = q.top(); q.pop();
    //dist[point]には今の距離が入ってる
    //dが今の距離と違う = 更新前のキューを取り出したので見ない(結果は変わらないけど無駄な探索になる)
    //一致したら最短距離確定
    if (dist[point] != d) {
      cout << "dist[point] : "<< dist[point] << endl;
      cout << "d : "<< d << endl;
      continue;
    }
    //cout << "dist[point] : "<< dist[point] << endl;
    //cout << "d : "<< d << endl;

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

  for (int i = 1; i < n; i++) cout << dist[i] << ' ';
  cout << endl;
  return 0;
}