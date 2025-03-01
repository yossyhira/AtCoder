#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    map<int, int> M;
    const int INF = 1e9;
    int Ans = INF;
    for (int i = 0; i < n; i++) {
        if(M.count(num[i])){
            int x = M[num[i]];
            int subAns = i - x + 1;
            Ans = min(Ans, subAns);
            M[num[i]] = i;
        }else{
            M[num[i]] = i;
        }

    }
    if(Ans != INF)cout << Ans<< endl;
    else cout << -1 << endl;
}