#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> num(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            num[i][j] = (i+1)*(j+1);
        }
    }
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(num[i][j] != x){
                ans += num[i][j];
            }
        }
    }

    cout << ans<< endl;
}