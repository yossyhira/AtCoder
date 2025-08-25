#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int dist[505][505][2];

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];

  const int INF = 1001001001;
  rep(i,h)rep(j,w)rep(k,2) dist[i][j][k] = INF;
  queue<tuple<int,int,int>> q;
  auto push = [&](int i, int j, int k, int d) {
    if (dist[i][j][k] != INF) return;
    dist[i][j][k] = d;
    q.emplace(i,j,k);
  };

  rep(i,h)rep(j,w) if (a[i][j] == 'S') push(i,j,0,0);
  while (q.size()) {
    auto [i,j,k] = q.front(); q.pop();
    int d = dist[i][j][k];
    if (a[i][j] == 'G') {
      cout << d << endl;
      return 0;
    }
    rep(v,4) {
      int ni = i+di[v], nj = j+dj[v];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (a[ni][nj] == '#') continue;
      if (k == 0 && a[ni][nj] == 'x') continue;
      if (k == 1 && a[ni][nj] == 'o') continue;
      int nk = k;
      if (a[ni][nj] == '?') nk ^= 1;
      push(ni,nj,nk,d+1);
    }
  }

  cout << -1 << endl;
  return 0;
}