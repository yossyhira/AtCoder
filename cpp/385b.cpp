#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int height, width, x, y;
    cin >> height >> width >> x >> y;
    x --;
    y --;

    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];
    string t;
    cin >> t;
    int houseCount = 0;
    for (int i = 0; i < t.size(); i++) {
        char move = t.at(i);
        int testX = x;
        int testY = y;
        if(move == 'U') testX --;
        else if(move == 'D') testX ++;
        else if(move == 'L') testY --;
        else if(move == 'R') testY ++;
        
        if(field[testX][testY] == '#')continue;

        x = testX;
        y = testY;

        if(field[x][y] == '@'){
            houseCount ++;
            field[x][y] = '.';
        }
    }

    cout << x + 1 << " " << y + 1 <<" "<< houseCount << endl;

}