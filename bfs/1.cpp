//問題(https://qiita.com/drken/items/996d80bcae64649a6580)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//可変長の配列
using Graph = vector<vector<int>>;
//(https://qiita.com/drken/items/4a7869c5e304883f539b#2-%E8%A8%88%E7%AE%97%E6%A9%9F%E4%B8%8A%E3%81%A7%E3%81%AE%E3%82%B0%E3%83%A9%E3%83%95%E3%81%AE%E8%A1%A8%E3%81%97%E6%96%B9)

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

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に(-1)初期化
    queue<int> que; 

    // 初期条件 (頂点 0 を初期ノードとする)
    //dist[v] はスタート頂点から頂点 v まで最短何ステップで到達できるかを表す
    int start = 0;
    dist[start] = 0; //スタートは0ステップ
    //その時点での橙色頂点 (発見済みだが未訪問な頂点) を格納するキュー
    que.push(start); // スタートを橙色(自分からいける場所を見たい)頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop(); //先頭削除

        // 自分（v） から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済み(ステップ数が分かってる)の頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            //distは各頂点の最短ステップ数
            dist[nv] = dist[v] + 1; //自分がいる所の次なので自分の場所から1ステップ増やす
            que.push(nv);//発見した(そこまでのステップ数が分かった)ので
                         //自分からいける場所を後で調べる
        }
        /*
        for (int i = 0; i < G[v].size(); i++) {
            int nv = G[v][i];
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
        */
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}
