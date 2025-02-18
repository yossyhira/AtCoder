#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> judge;
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        a --;
        b --;
        judge.push_back({a, b});
    }
    
    int k;
    cin >> k;
    vector<pair<int, int>> dishes;
    for (int i = 0; i < k; i++) {
        int a, b; 
        cin >> a >> b;
        a --;
        b --;
        dishes.push_back({a, b});
    }
    int ans = -1;
    for (int i = 0; i < (1 << k); i++) {
        vector<bool> in_Ball(n, false);
        int subAns = 0;
        for (int j = 0; j < k; j++) {
            if((i & (1 << j)) != 0){
                int ok, ng;
                tie(ok, ng) = dishes[j];
                in_Ball[ok] = true;
            }else{
                int ok, ng;
                tie(ng, ok) = dishes[j];
                in_Ball[ok] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            tie(a, b) = judge[i];
            if(in_Ball[a] && in_Ball[b]) subAns ++;
        }
        ans = max(ans, subAns);
    }
    cout << ans << endl;
}