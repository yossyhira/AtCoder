#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//using Graph = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<vector<int>> num(N);
    if(M == 0) {
        cout << "No" << endl; 
        return 0;
    }
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        num[a].push_back(b);
        num[b].push_back(a);
        if(num[a].size() > 2 || num[b].size() > 2){
            cout << "No" << endl; 
            return 0;
        }
    }
    int startNum = 0, baseIdx = 0;
    bool ng = true;
    for (int i = 0; i < N; i++) {
        if(num[i].size() == 1){
            baseIdx = i;
            startNum = num[i][0];
            ng = false;
        }
        num[i].push_back(0);
    }
    if(ng){
        cout << "No" << endl;
        return 0;
    }
    
    num[baseIdx][1] ++;
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < num[i].size(); j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }*/
    for (int i = 0; i < N; i++) {
        int baseNum = baseIdx;
        baseIdx = startNum;
        int x = num[baseIdx].size() - 1;
        num[baseIdx][x] ++;
        if(num[baseIdx].size() == 2)break;
        for (int j = 0; j < x; j++) {
          if(baseNum != num[baseIdx][j]){
            num[baseIdx][x] ++;
            startNum = num[baseIdx][j];
          }
        }
    }
    for (int i = 0; i < N; i++) {
        int x = num[i].size() - 1;
        if(num[i][x] != x){
            cout << "No" << endl;
            return 0;
        }
    }


    cout << "Yes"<< endl;
}