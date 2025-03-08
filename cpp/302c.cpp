#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool flag = false;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int h = 0;
    do{
        h ++;
        int anscnt = 0; 
        for (int i = 0; i < n - 1; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if(s[p[i]][j] != s[p[i + 1]][j]) cnt ++;
            }
            if(cnt == 1) anscnt ++;
        }
        if(anscnt == (n - 1)) flag = true;
    } while(next_permutation(p.begin(), p.end()));
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << h << endl;
    return 0;
}