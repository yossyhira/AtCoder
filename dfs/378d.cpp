#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 入力
int H, W, k;
vector<string> field;
//答えのカウント
ll cnt = 0;
// 探索
bool seen[510][510]; // seen[h][w] := マス (h, w) が検知済みかどうか
void dfs(int h, int w, int move) {
    seen[h][w] = true;
    int saveMove = move;

    // 四方向を探索
    for (int dir = 0; dir < 4; ++dir) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];
        move = saveMove;
        // 場外アウトしたり、移動先が壁の場合はスルー
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == '#') continue;

        
        // 移動先が探索済みの場合
        if (seen[nh][nw]) continue;
        move ++;
        if(move == k) {
            cnt ++;
            continue;
        }
        // 再帰的に探索
        dfs(nh, nw, move);
    }
    //いろいろな動きのパターンを調べたいとき(同じ動線でも動くマス順番が変わると答えも変わる場合など)
    seen[h][w] = false;
}

int main() {
    // 入力受け取り
    cin >> H >> W >> k;
    field.resize(H);
    for (int h = 0; h < H; ++h) cin >> field[h];

    // .のマスを特定する
    vector<pair<int, int>> okGrid;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            int okH,okW;
            if (field[h][w] == '.') {
                okH = h;
                okW = w;
                okGrid.push_back({okH, okW});
            }
        }
    }

    for (int i = 0; i < okGrid.size(); i++) {     
        memset(seen, 0, sizeof(seen)); // seen 配列全体を false に初期化
        int okH, okW;
        tie(okH, okW) = okGrid.at(i);
        int move = 0;
        dfs(okH, okW, move);
    }

    cout << cnt << endl;
}
