//01BFS(普通のBFSとダイクストラの概念を混ぜた感じ)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int di[] = {-1,0,1,0};
int dj[] = {0,-1,0,1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  int si, sj, ti, tj;
  cin >> si >> sj >> ti >> tj;
  --si; --sj; --ti; --tj;

  const int INF = 1001001001;
  vector<vector<int>> dist(h,vector<int>(w, INF));
  vector<vector<bool>> used(h,vector<bool>(w));
  deque<pair<int,int>> q;

  // i, j : 座標
  // d : その頂点までの総距離（コスト）
  // cost : その辺単体の重み(dequeの前か後のどっちに入れるのか判別に使う)
  auto push = [&](int i, int j, int d, int cost) {
    //最短距離更新するかどうか
    if (dist[i][j] <= d) return;
    dist[i][j] = d;
    //コストが0なら前，1なら後ろに追加
    if (cost == 0) q.emplace_front(i,j);
    else q.emplace_back(i,j);
  };
  push(si,sj,0,0);

  while (q.size()) {
    //最短距離で取り出しているので，見てなければ距離確定
    int i, j;
    tie(i, j) = q.front(); q.pop_front();
    if (used[i][j]) continue;
    //その座標を見たにする
    used[i][j] = true;
    //その座標の距離
    int d = dist[i][j];

    //普通の道(コスト0)
    rep(v,4) {
      int ni = i+di[v], nj = j+dj[v];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '.') push(ni,nj,d,0);
    }
    //壁の道(コスト1)
    //普通の道でも壁とみなして移動する
    //普通の道の方はif (used[i][j]) continue;かコスト0なのでpush関数のif (dist[i][j] <= d) return;ではじいてくれる
    rep(v,4) {
      int ni = i, nj = j;
      //壁の2マス分同じ方向に移動
      rep(k,2) {
        ni += di[v]; nj += dj[v];
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) break;
        push(ni,nj,d+1,1);
      }
    }
  }

  int ans = dist[ti][tj];
  cout << ans << endl;
  return 0;
}