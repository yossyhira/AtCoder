#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> fieldS(n);
    for (int h = 0; h < n; ++h) cin >> fieldS[h];
    vector<string> fieldM(m);
    for (int h = 0; h < m; ++h) cin >> fieldM[h];
    for (int Si = 0; Si < n; Si++) {
        for (int Sj = 0; Sj < n; Sj++) {
            bool ok = true;
            for (int Mi = 0; Mi < m; Mi++) {
                for (int Mj = 0; Mj < m; Mj++) {
                    if((Si+Mi) >= n || (Sj+Mj) >= n){
                        ok = false;
                        continue;
                    }
                    if(fieldS[Si+Mi][Sj+Mj] != fieldM[Mi][Mj]){
                        ok = false;
                    }
                }
                
            }
            if(ok){
                cout << Si + 1 <<" "<< Sj + 1 << endl;
            }
        }
    }
}