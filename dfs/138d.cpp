//(https://qiita.com/drken/items/4a7869c5e304883f539b)
//O(N+M)
//行きがけ順、帰りがけ順
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<ll> score;

void dfs(const Graph &G, int child, int parent) {
    //vを探索済みにする
    seen[child] = true;
    score[child] += score[parent]; 
    //vからいける場所を探索
    for (auto next_child : G[child]) { 
        if (seen[next_child]) continue;//探索済みならコンティニュー
        dfs(G, next_child, child);
    }
}

int main() {
    // 頂点数と辺数
    int N, Q; 
    cin >> N >> Q;
    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N+1);
    G[0].push_back(1);

    seen.assign(N+1, false); // 全頂点を「未訪問」に初期化
    seen[0] = true;

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    score.assign(N+1, 0);
    for (int i = 0; i < Q; i++) {
        int root, s;
        cin >> root >> s;
        score[root] += ll(s);
    }

    dfs(G, 1, 0);

    for (int i = 1; i < score.size(); i++) {
        cout << score[i] << " ";
    }
    cout << endl;
    return 0;
}

