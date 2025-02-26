#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> ans;

//ここの引数でvector<int> currentを宣言すると前の回までの状態の配列を引き継げる
//つまり、末尾を毎回消す必要ない
void solve(int num, int cnt, vector<int> current) {
    current.push_back(num);
    
    //目標のサイズnになったら
    if(current.size() == n){
        //配列に配列を入れると二次元配列にしてくれる
        ans.push_back(current);
        return;
    }
    
    for (int i = num + 10; i <= m ; i++) {
        //10 * (n - 1)であと何回10足されるか計算する
        //つまり、i + 10 * (n - (current.size() + 1))で最終的な値を計算できる。
        //最終的な値が目標値mを超えたら探索しない(枝刈り)
        if((i + 10 * (n - (current.size() + 1))) > m) return;
        solve(i, cnt + 1, current);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        //10 * (n - 1)であと何回10足されるか計算する
        //つまり、i + 10 * (n - 1)で最終的な値を計算できる。
        //最終的な値が目標値mを超えたら探索しない(枝刈り)
        if(i + 10 * (n - 1) > m) break;
        //ここでからの配列を入れる
        solve(i, 0, {});
    }
    cout << ans.size() << endl;
    for (const auto& vec : ans) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
