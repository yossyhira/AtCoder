#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//可変長の配列
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (有向グラフ)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        G[a].push_back(b);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に(-1)初期化
    queue<int> que; 

    // 初期条件 (頂点 0 を初期ノードとする)
    //dist[v] はスタート頂点から頂点 v まで最短何ステップで到達できるかを表す
    int start = 0;//スタートの頂点

    //今回はまたスタートに戻ってきたいのであえて距離を追加しない
    //ここの一手分少なくなるので最後に一手足す！！！
    //dist[start] = 0; //スタートは0ステップ

    //その時点での発見済みだが未訪問な頂点を格納するキュー
    que.push(start); 

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop(); //先頭削除

        // 自分（v） から辿れる頂点をすべて調べる
        for (int i = 0; i < G[v].size(); i++) {
            int nv = G[v][i];
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            if(nv == 0) break; //スタートにかえって来たら探索終了
            que.push(nv);
        }
    }

    // 結果出力
    if(dist[0] != -1)cout << dist[0] + 1<< endl;//最初の一手を足す！！(最初を無視したから)
    else cout << -1 << endl;//閉路が無ければ-1
    return 0;
}