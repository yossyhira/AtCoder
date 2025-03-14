#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<char>> s;
vector<vector<char>> ans;
int n;
//回転の関数
//0回転
void zero(int i, int j){
    ans[i][j] = s[i][j];
}
//1回転
void one(int i, int j){
    ans[j][(n - 1 - i)] = s[i][j];
}
//2回転
void two(int i, int j){
    ans[(n - 1 - i)][(n - 1 - j)] = s[i][j];
}
//3回転
void three(int i, int j){
    ans[(n - 1 - j)][i] = s[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    s.resize(n, vector<char>(n));
    ans.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    //回転の折り返し地点
    int rev = (n / 2) - 1;
    //どれくらい折り返すかのカウント
    int cnt = 1;
    for (int si = 0; si < n; si++) {
        int i = si;
        //折り返す場所計算
        if(i > rev){
            i -= cnt;
            cnt += 2;
        }
        for (int j = 0; j < n; j++) {
            //内側の回転
            if(i <= j && j <= (n - (i + 1))){
                //回転数計算
                int rot = (i + 1) % 4;
                switch (rot){
                    case 0:
                    //cout << "0 回転" << endl;
                    //cout << "si = " << si << ", ";
                        //cout << "j = " << j << endl;
                        zero(si, j);
                        break;
                        
                        case 1:
                        //cout << "1 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "j = " << j << endl;
                        one(si, j);
                        break;
                        
                        case 2:
                        //cout << "2 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "j = " << j << endl;
                        two(si, j);
                        break;
                        
                        case 3:
                        //cout << "3 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "j = " << j << endl;
                        three(si, j);
                        
                        default:
                        break;
                    }
                }
                //外側の回転
                else if(i > j){
                    //cout << "特殊！！！！！" << endl;
                    int rot = (j + 1) % 4;
                    switch (rot){
                        case 0:
                        //cout << "0 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "j = " << j << endl;
                        //cout << "0 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "n - (j + 1) = " << j << endl;
                        zero(si, j);
                        zero(si, (n - (j + 1)));
                        break;
                        
                        case 1:
                        //cout << "1 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "j = " << j << endl;
                        //cout << "1 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "n - (j + 1) = " << j << endl;
                        one(si, j);
                        one(si, (n - (j + 1)));
                        break;
                        
                        case 2:
                        //cout << "2 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "j = " << j << endl;
                        //cout << "2 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "n - (j + 1) = " << j << endl;
                        two(si, j);
                        two(si, (n - (j + 1)));
                        break;
                        
                        case 3:
                        //cout << "3 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "j = " << j << endl;
                        //cout << "3 回転" << endl;
                        //cout << "si = " << si << ", ";
                        //cout << "n - (j + 1) = " << j << endl;
                        three(si, j);
                        three(si, (n - (j + 1)));
                        break;
                default:
                break;
            }
            //cout << "特殊 終わり！！！！！" << endl;
        }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        for(char x : ans[i]){
            cout << x;
        }
        cout << endl;
    }
}