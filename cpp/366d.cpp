#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 3D配列の初期化
    vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n, 0)));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> a[i][j][k];
            }
        }
    }

    // 累積和の計算
    vector<vector<vector<long long>>> sum(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                sum[i + 1][j + 1][k + 1] =
                    sum[i][j + 1][k + 1] + sum[i + 1][j][k + 1] +
                    sum[i + 1][j + 1][k] - sum[i][j][k + 1] - sum[i][j + 1][k] -
                    sum[i + 1][j][k] + sum[i][j][k] + a[i][j][k];
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        // 1-indexed に合わせる
        lx--, ly--, lz--;

        // 境界をはみ出さないように max(0, lx) で補正
        long long result = sum[rx][ry][rz]
                         - sum[max(0, lx)][ry][rz]
                         - sum[rx][max(0, ly)][rz]
                         - sum[rx][ry][max(0, lz)]
                         + sum[max(0, lx)][max(0, ly)][rz]
                         + sum[max(0, lx)][ry][max(0, lz)]
                         + sum[rx][max(0, ly)][max(0, lz)]
                         - sum[max(0, lx)][max(0, ly)][max(0, lz)];
        
        cout << result << "\n";
    }
}
