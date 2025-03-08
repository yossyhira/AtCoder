#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    stack<int> s;
    for (int i = 0; i < 100; i++) {
        s.push(0);
    }
    for (int i = 0; i < q; i++) {
        int qe;
        cin >> qe;
        if(qe == 1){
            int x;
            cin >> x;
            s.push(x);
        }else{
            cout << s.top() << endl;
            s.pop();
        }
    }
    return 0;
}