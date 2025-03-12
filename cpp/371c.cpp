#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<bool>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int m_g;
    cin >> m_g;
    Graph G(N, vector<bool> (N, false));
    for (int i = 0; i < m_g; ++i) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        //ここではあくまでa,bは頂点番号ではなく、
        //何個目同士の頂点がつながってるかを記録
        G[a][b] = true;
        G[b][a] = true;
    }
    Graph H(N, vector<bool> (N, false));
    int m_h;
    cin >> m_h;
    for (int i = 0; i < m_h; ++i) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        //ここではあくまでa,bは頂点番号ではなく、
        //何個目同士の頂点がつながってるかを記録
        H[a][b] = true;
        H[b][a] = true;
    }
    
    vector<vector<int>> cost(N, vector<int> (N, 0));
    for (int i = 0; i < N ; i++) {
       for (int j = 0; j < N; j++) {
            if(j > i){
                cin >> cost[i][j];
                //cost[j][i] = cost[i][j];
            }
       }
    }
    
    vector<int> p(N);//3!の全探索
    for (int i = 0; i < N; i++) p[i] = i;
    const int INF = 1e9;
    int ans = INF;
    do {
        int subAns = 0;
        //cout << "next" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //Hを並べ替え(頂点番号を割り当てる)
                if(G[i][j] != H[p[i]][p[j]]){
                    //cout << p[i] << " " << p[j] << endl;
                    //cout << cost[p[i]][p[j]] << endl;
                    subAns += cost[p[i]][p[j]];
                }
                //Gを並べ替え(頂点番号を割り当てる)
                /*if(H[i][j] != G[p[i]][p[j]]){
                    subAns += cost[i][j];
                }*/
            }
        }
        ans = min(ans, subAns);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}