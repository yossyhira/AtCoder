#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> bard(n);
    for (int i = 0; i < n; i++) {
        bard[i] = i;
    }
    vector<int> home(n, 1); //サイズ3, 100で初期化
    int count = 0;
    for (int i = 0; i < q; i++) {
        int Q;
        cin >> Q;
        if(Q == 1){
            int p, h;
            cin >> p >> h;
            p --;
            h --;
            int where = 0;
            where = bard[p];
            bard[p] = h;
            home[where] --;
            if(home[where] == 1){
                count --;
            }
            home[h] ++;
            if(home[h] == 2){
                count ++;
            }
        }
        else if (Q == 2){
            cout << count << endl;
        }
    }
    return 0;
}