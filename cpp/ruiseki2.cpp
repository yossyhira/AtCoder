#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力: H × W のグリッド
    int H, W; cin >> H >> W;
    vector<vector<int> > a(H, vector<int>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> a[i][j];

    // 二次元累積和
    vector<vector<int> > s(H+1, vector<int>(W+1, 0));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

    // クエリ [x1, x2) × [y1, y2) の長方形区域の和
    for (int i = 0; i < H+1; ++i){
        for (int j = 0; j < W+1; ++j){
           cout << s[i][j] << " ";
        }
        cout << endl;
    }

    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        x1 --; y1 --;
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }
}   
