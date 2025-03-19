//グリッド系
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ２方向への移動ベクトル
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

// 入力
int H, W;
vector<string> field;
int ans = -1;

// 探索
bool seen[510][510]; // seen[h][w] := マス (h, w) が検知済みかどうか
void dfs(int h, int w, int cnt) {
    seen[h][w] = true;
    bool out = false, wall = false;
    // ２方向を探索
    for (int dir = 0; dir < 2; ++dir) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];

        // 場外アウトしたり、移動先が壁の場合はスルー
        if (nh < 0 || nh >= H || nw < 0 || nw >= W){
            out = true;
            continue;
        }
        if (field[nh][nw] == '#'){
            wall = true;
            continue;
        }
        out = false; wall = false;
        // 移動先が探索済みの場合
        if (seen[nh][nw]) continue;
        // 再帰的に探索
        dfs(nh, nw, cnt + 1);
    }
    if(out || wall){
        ans = max(ans, cnt);
    }
    //いろいろな動きのパターンを調べたいとき(同じ動線でも動くマス順番が変わると答えも変わる場合など)
    //今回は右と下方向なので行き方によってコストは変わらない(マンハッタン距離)
    //seen[h][w] = false;
}

int main() {
    // 入力受け取り
    cin >> H >> W;
    field.resize(H);
    for (int h = 0; h < H; ++h) cin >> field[h];

    
    // 探索開始
    memset(seen, 0, sizeof(seen)); // seen 配列全体を false に初期化

    dfs(0, 0, 1);

    // 結果
    cout << ans << endl;
}