#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int height, width;
    cin >> height >> width;
    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];

    int minH = 100000;
    int minW = 100000;
    int maxH = -1;
    int maxW = -1;

    for (int h = 0; h < height; ++h) {
        for (int w = 0; w < width; ++w) {
            if(field[h][w] == '#') {
                minH = min(minH, h);
                minW = min(minW, w);
                maxH = max(maxH, h);
                maxW = max(maxW, w);
            }
        }
    }

    for (int h = minH; h <= maxH; h++) {
        for (int w = minW; w <= maxW; w++) {
            if(field[h][w] == '.') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

}