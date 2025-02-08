#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    vector<int> num(3);
    for (int i = 0; i < 3; i++) {
        cin >> num[i]; 
    }
    vector<int> p(3);//3!の全探索
    rep(i, 3) p[i] = i;

    bool frag = false;
    do {
        if((num[p[0]]*num[p[1]]) == num[p[2]]) frag = true;
    } while (next_permutation(p.begin(), p.end()));

    if(frag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}