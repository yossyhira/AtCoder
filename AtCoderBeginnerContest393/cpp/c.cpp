#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//using Graph = vector<set<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    //Graph G(N+1,vector<bool>(N+1, false));
    map<pair<int, int>, int> M1;
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if(a == b){
            ans ++;
            continue;
        }
        if(!M1.count({a, b}) && !M1.count({b, a}) ){
            M1[{a, b}] = 1;
            M1[{b, a}] = 1;
        }else{
            ans ++;
        }
    }
    cout << ans << endl;
}