#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
//#define eb emplace_back
//#define em emplace
//#define pob pop_back
//using ld = long double;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define yes cout<<"Yes"<<endl
#define yesr {cout<<"Yes"<<endl; return 0;}
#define no cout<<"No"<<endl
#define nor {cout<<"No"<<endl; return 0;}
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}// if(a==b)YN;
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に(-1)初期化
    int ans = 0;
    vector<bool> clr(N, false);
    auto bfs = [&](int s){
        queue<int> que; 
    
        // 初期条件 (頂点 0 を初期ノードとする)
        //dist[v] はスタート頂点から頂点 v まで最短何ステップで到達できるかを表す
        int start = s;
        dist[start] = 0; //スタートは0ステップ
        clr[s] = false;
        //その時点での橙色頂点 (発見済みだが未訪問な頂点) を格納するキュー
        que.push(start); // スタートを橙色(自分からいける場所を見たい)頂点にする
    
        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            int v= que.front(); // キューから先頭頂点を取り出す
            que.pop(); //先頭削除
            // 自分（v） から辿れる頂点をすべて調べる
            cout <<"v" <<v+1 << endl;
            for (int nv : G[v]) {
                cout <<"nv" <<nv +1<< endl;
                if (dist[nv] != -1){
                    if(clr[nv] == clr[v]) ans ++;
                    cout << "ans"<< ans << "nv" << nv+1 << endl;
                    continue;
                } // すでに発見済み(ステップ数が分かってる)の頂点は探索しない
                clr[nv] = (clr[v] ? false : true);
                // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                //distは各頂点の最短ステップ数
                dist[nv] = dist[v] + 1; //自分がいる所の次なので自分の場所から1ステップ増やす
                que.push(nv);//発見した(そこまでのステップ数が分かった)ので
                             //自分からいける場所を後で調べる
            }
        }

    };
    for (int i = 0; i < N; i++) {
        if(dist[i] == -1){
            bfs(i);
        }
    }
    for(auto b :clr){
        cout << b <<" ";
    }
    cout << endl;
    cout << ans / 2 << endl;
    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    //for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}