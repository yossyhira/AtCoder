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

    int N, M; cin >> N;
    M = (N-1);

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> ans;
    auto bfs = [&](bool a)->void{
       
        vector<int> dist(N, -1); 
        queue<pair<int, bool>> que; 
     
        int start = 0;
        dist[start] = 0; 
        que.push({start, a}); 
        int finish = N / 2;
       
        while (!que.empty()) {
            int v; bool ok;
            tie(v, ok) = que.front();
            que.pop(); 
            if(ok){
                ans.pb(v);
                if(ans.size() == finish) break;
            }
            
            for (int nv : G[v]) {
                if (dist[nv] != -1) continue; 
                dist[nv] = dist[v] + 1;
                que.push({nv, (ok ? false : true)});                
            }
        }
    };
    bfs(true);
    if(ans.size() == (N/2)){
        for (int v = 0; v < (N / 2); ++v) cout << ans[v] + 1<< " ";
        cout << endl;
    }else{
        vector<int>().swap(ans);
        bfs(false);
        for (int v = 0; v < (N / 2); ++v) cout << ans[v] + 1<< " ";
        cout << endl;
    }
}

/*
頂点1(はじめに見るやつ)がtrueだけだとダメなパターン
4
1 2
1 3
1 4
*/
