#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
int cnt = 0;
int ansCnt = 0;
vector<vector<int>> ans;
void int printAns(){
    ansCnt ++;
    for (int i = 0; i < ans[ansCnt - 1].size() - 1; i++) {
        ans[ansCnt].push_back(ans[ansCnt - 1][i]);
    }
}
void int ans(int num, int cnt){
    cnt ++;
    if(cnt >= n) {
        printAns();
        break;
    }
    if(num + 10 > m){
        break;
    }
    ans[ansCnt].push_back(num);
   for (int i =  num + 10 ; i < m; i++) {
        if(i > m) {
            printAns();
            break;
        }
        ans(i, cnt);
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        cnt = 0;
        ans(i, cnt);
    }
    
    for (int i = 0; i < ans.size(); i++) {
        for(int x : ans[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}