#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, qe;
    cin >> n >> qe;
    vector<int> bird(n);
    for (int i = 0; i < n; i++) {
        bird[i] = i + 1;
    }
    map<int, int> M;
    for (int i = 0; i < qe; i++) {
        int q;
        cin >> q;
        if(q == 1){
            int a, b;
            cin >> a >> b;
            a --;
            bird[a] = b;
        }
        else if(q == 2){
            int a, b;
            cin >> a >> b;
            if(M.count(a)) a = M[a];
            if(M.count(b)) b = M[b];
            M[a] = b;
            M[b] = a;
        }else{
            int a;
            cin >> a;
            a --;
            int home = bird[a];
            if(M.count(home)) home = M[home];
            
            cout << home << endl;
        }
    }
}