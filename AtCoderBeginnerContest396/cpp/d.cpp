#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
using P = pair<ll,int>;

struct Edge {
  int to;
  ll cost;
  Edge(int to, ll cost): to(to), cost(cost) {}
};

using Graph = vector<vector<Edge>>;

vector<bool> seen;

int N, M;
const ll INF = LLONG_MAX;
ll ANS = INF;
void dfs(const Graph &G, int v, ll ans) {
    
    //vを探索済みにする
    seen[v] = true; 
    
    //vからいける場所を探索
    for (Edge next_v : G[v]) {
        ll keepans = ans; 
        if (seen[next_v.to]) continue;//探索済みならコンティニュー
        //cout << "辺"<<next_v.to << endl;
        //cout << "前コスト"<<ans << endl;
        ans = ans ^ next_v.cost;
        //cout << "コスト"<<ans << endl;
        if(next_v.to == (N - 1)) {
            ANS = min(ANS, ans);
            //cout << "記録" << endl;
            break;
        }
        dfs(G, next_v.to, ans);
        ans = keepans;
    }
    seen[v] = false;
}

int main() {
    // 頂点数と辺数
    cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a --;
        b --;
        G[a].emplace_back(b, w);
        G[b].emplace_back(a, w);
    }

    // 頂点 0 をスタートとした探索
    //assignはresize + 変数初期化
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    
    dfs(G, 0, 0);


    cout << ANS << endl;
    return 0;
}

