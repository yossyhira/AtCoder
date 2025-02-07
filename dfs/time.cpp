//(https://qiita.com/drken/items/4a7869c5e304883f539b)
//O(N+M)
//タイムスタンプ
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> first_order; // 行きがけ順
vector<int> last_order; // 帰りがけ順

void dfs(const Graph &G, int v, int& time) {
    // 行きがけ順をインクリメントしながらメモ
    //first_ptr++というのは、値を追加した後に1足すという意味。
    //++first_ptrにすると追加する前に1足す
    first_order[v] = time++;
    
    //vを探索済みにする
    seen[v] = true; 

    //vからいける場所を探索
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;//探索済みならコンティニュー
        dfs(G, next_v, time);
    }

    // 帰りがけ順をインクリメントしながらメモ
    //全部行き終わったら値を追加
    last_order[v] = time++;
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    first_order.resize(N);
    last_order.resize(N);
    int time = 0;
    dfs(G, 0, time);

    // 各頂点 v の行きがけ順、帰りがけ順を出力
    for (int v = 0; v < N; ++v)
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
}

/*
//入力 15頂点 14枝
15 14
0 1
1 2
1 3
0 4
4 5
5 6
5 7
4 8
8 9
8 10
0 11
11 12
11 13
13 14

//出力
0: 0, 29
1: 1, 6
2: 2, 3
3: 4, 5
4: 7, 20
5: 8, 13
6: 9, 10
7: 11, 12
8: 14, 19
9: 15, 16
10: 17, 18
11: 21, 28
12: 22, 23
13: 24, 27
14: 25, 26
*/