//(https://qiita.com/drken/items/4a7869c5e304883f539b)
//O(N+M)
//行きがけ順、帰りがけ順
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<ll> score;

void dfs(const Graph &G, int v, int s) {
    //vを探索済みにする
    seen[v] = true;
    score[v] += ll(s); 
    //vからいける場所を探索
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;//探索済みならコンティニュー
        dfs(G, next_v, s);
    }
}

int main() {
    // 頂点数と辺数
    int N, Q; 
    cin >> N >> Q;
    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        G[a].push_back(b);
    }
    score.assign(N, 0);
    for (int i = 0; i < Q; i++) {
        int root, s;
        cin >> root >> s;
        root --;
        seen.assign(N, false); // 全頂点を「未訪問」に初期化
        dfs(G, root, s);
    }

    for(ll s : score) cout << s << " ";
    cout << endl;
    return 0;
}

