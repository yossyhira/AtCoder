#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<pair<ll, ll>>>;//{頂点, 重さ}

vector<bool> seen;

vector<ll> ans;

void dfs(const Graph &G, int v) {
    
    //vを探索済みにする
    seen[v] = true; 

    //vからいける場所を探索
    for (const auto& next_v : G[v]) { 
        if (seen[next_v.first]) continue;//探索済みならコンティニュー
        ans[next_v.first] = ans[v] + next_v.second; //矛盾しない値を計算
        dfs(G, next_v.first);
    }
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        a --;
        b --;
        G[a].push_back({b, w});
        G[b].push_back({a, -w}); //逆方向なら符号逆
    }


    seen.assign(N, false); // 全頂点を「未訪問」に初期化

    const ll INF = -2e18; 
    ans.assign(N, INF);

    //グラフが一つにまとまってない時は以下を繰り返す
    // 訪問済みか一つずつみて未訪問であれば探索(この時に一つのグラフ内で探索したやつは訪問済みに置き換わる)
    //一つのグラフが探索完了したのにまだ未探索なものは別のグラフにあるので新たな始点として探索
    for (int i = 0; i < N; i++) {
        if(seen[i] == false){
            //始点の値はなんでもよいので適当に0とした
            ans[i] = 0;
            dfs(G, i);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
