#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> card(14, 0);
    for (int i = 0; i < 7; i++) {
       int x;
       cin >> x;
       card[x] ++;
    }
    bool two = false, three = false;
    int cnt = 0;
    for (int i = 0; i < 14; i++) {
        if(card[i] == 2) two = true;
        if(card[i] >= 3) {
            cnt ++;
            three = true;
        }
        
    }
    if(two && three || cnt > 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}