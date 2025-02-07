//(https://qiita.com/drken/items/4a7869c5e304883f539b)
//O(N+M)
//行きがけ順、帰りがけ順
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> first_order; // 行きがけ順
vector<int> last_order; // 帰りがけ順

void dfs(const Graph &G, int v, int& first_ptr, int& last_ptr) {
    // 行きがけ順をインクリメントしながらメモ
    //first_ptr++というのは、値を追加した後に1足すという意味。
    //++first_ptrにすると追加する前に1足す
    first_order[v] = first_ptr++;
    
    //vを探索済みにする
    seen[v] = true; 

    //vからいける場所を探索
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;//探索済みならコンティニュー
        dfs(G, next_v, first_ptr, last_ptr);
    }

    // 帰りがけ順をインクリメントしながらメモ
    //全部行き終わったら値を追加
    last_order[v] = last_ptr++;
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
    int first_ptr = 0, last_ptr = 0;
    dfs(G, 0, first_ptr, last_ptr);

    // 各頂点 v の行きがけ順、帰りがけ順を出力
    for (int v = 0; v < N; ++v)
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
}

/*
//入力
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
0: 0, 14
1: 1, 2
2: 2, 0
3: 3, 1
4: 4, 9
5: 5, 5
6: 6, 3
7: 7, 4
8: 8, 8
9: 9, 6
10: 10, 7
11: 11, 13
12: 12, 10
13: 13, 12
14: 14, 11
*/