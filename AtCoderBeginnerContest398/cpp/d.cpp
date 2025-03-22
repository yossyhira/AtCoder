#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int gx, gy;
    string tex;
    cin >> n >> gx >> gy >> tex;
    int x = 0, y = 0;
    map<pair<int, int>, int> M1;
    vector<pair<int, int>> a;
    M1[{x, y}] = 1;
    for (int i = 0; i < n; i++) {
        if(tex[i] == 'N'){
            x --;
        }
        else if(tex[i] == 'W'){
            y --;
        }
        else if(tex[i] == 'S'){
            x ++;
        }
        else if(tex[i] == 'E'){
            y ++;
        }
        //cout << x << " " << y << endl;
        if(M1.count({x, y})){

            M1[{x, y}] ++ ;
        }else{

            M1[{x, y}] = 1;
        }
        a.push_back({x, y});
    }
    vector<int> ans;
    for (int i = (a.size() - 1); i >= 0; i--) {
        int x, y;
        tie(x, y) = a.at(i);
        M1[{x, y}] --;
        x -= gx; y -= gy;

        if(M1.count({x, y})){
            int num = M1[{x, y}];
            if(num >= 1) ans.push_back(1);
            else ans.push_back(0);
        }else{
            ans.push_back(0);
        }
    }
    for (int i = ans.size() - 1; i >= 0 ; i--) {
        cout << ans[i];
    }
    cout << endl;
}