#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i].push_back('.');
        }
    }
    for (int i = 0; i < n; i++) {
        int j = n + 1 - (i + 1);
        if((i + 1) <= j ){
            if(((i+1) % 2) != 0){
                for (int si = i; si < j; si++) {
                    for (int gi = i; gi < j; gi++) {
                        g[si][gi] = '#';
                    }
                }
            }else{
                for (int si = i; si < j; si++) {
                    for (int gi = i; gi < j; gi++) {
                        g[si][gi] = '.';
                    }
                }
            }
        }
    }
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
}