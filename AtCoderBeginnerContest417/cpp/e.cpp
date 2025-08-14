#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
//#define eb emplace_back
//#define em emplace
//#define pob pop_back
//using ld = long double;
using Graph = vector<vector<int>>;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        x --;
        y --;
        Graph g(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> ans;
        ans.pb(x);
        vector<bool> vi(n, false);
        vi[x] = true;
        int look = x;
        //cout << "koko" << endl;
        while(1){
            if(look == y) break;
            vector<bool> used(n, false); // 全頂点を「未訪問」に(-1)初期化
            queue<int> que; 
            
            // 初期条件 (頂点 0 を初期ノードとする)
            //used[v] はスタート頂点から頂点 v まで最短何ステップで到達できるかを表す
            used[y] = true; //スタートは0ステップ
            //その時点での橙色頂点 (発見済みだが未訪問な頂点) を格納するキュー
            que.push(y); // スタートを橙色(自分からいける場所を見たい)頂点にする
            
            // BFS 開始 (キューが空になるまで探索を行う)
            while (!que.empty()) {
                int v = que.front(); // キューから先頭頂点を取り出す
                que.pop(); //先頭削除
                
                // 自分（v） から辿れる頂点をすべて調べる
                for (int nv : g[v]) {
                    if (used[nv]) continue;
                    if (vi[nv]) continue;
                    if(nv == look) continue;
                    used[nv] = true; 
                    que.push(nv);
                }
            }
            //cout << "koko" << endl;
            int find = INF;
            for (int j = 0; j < g[look].size(); j++) {
                //cout << "koko" << endl;
                if(vi[g[look][j]]) {
                    //cout << "ving" << endl;
                    continue;}
                //cout << "viok" << endl;
                if(!used[g[look][j]]) continue;
                //cout << "usedok" << endl;
                chmin(find, g[look][j]);
                //cout << "minok" << endl;
            }
            //cout << find << endl;
            ans.pb(find);
            vi[find] = true;
            look = find;
            //cout << "koko" << endl;
        }

        for(auto num : ans){
            cout << num + 1 << " ";
        }
        cout << endl;
    }
}