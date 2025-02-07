//(https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp)
#include <iostream>
#include <vector>
using namespace std;

// 入力
int H, W;
vector<vector<int>> field;

// 探索
void dfs(int h, int w) {
    //seenを無くして、探索済みを0(海)に変える
    field[h][w] = 0;

    // 八方向を探索
    for (int dh = -1; dh <= 1; ++dh) {
        for (int dw = -1; dw <= 1; ++dw) {
            int nh = h + dh, nw = w + dw;
            
            // 場外アウトしたり、0(海) だったりはスルー
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (field[nh][nw] == 0) continue;

            // 再帰的に探索
            dfs(nh, nw);
        }
    }
}

int main() {
    // 入力受け取り
    while (cin >> W >> H) {
        if (H == 0 || W == 0) break;
        field.assign(H, vector<int>(W, 0));
        for (int h = 0; h < H; ++h) for (int w = 0; w < W; ++w) cin >> field[h][w];

        // 探索開始
        int count = 0;
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (field[h][w] == 0) continue; // 残島じゃなかったらスルー
                dfs(h, w);
                ++count;
            }
        }
        cout << count << endl;
    }
}
