#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int height, width, n;
    string text;
    cin >> height >> width >> n >> text;
    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];
    
    int ans = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(field[i][j] == '.'){
                int nowI = i;
                int nowJ = j;
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    char move = text.at(k);
                    if(move == 'U')nowI--;
                    else if(move == 'D')nowI++;
                    else if(move == 'L')nowJ--;
                    else if(move == 'R')nowJ++;

                    if(field[nowI][nowJ] == '#'){
                        ok = false;
                        break;
                    }
                }
                if(ok)ans ++;
            }
        }
    }
    cout << ans << endl;
}