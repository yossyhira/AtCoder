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
    int r = 0, l = 0;
    M[num[r]] = 1;
    const int INF = 1e9;
    int Ans = INF;
    while(r < n){
        r++;
        if(M.count(num[r])){
            M[num[r]] ++;
            if(M[num[r]] == 2){
                while(M[num[r]] == 2){
                    M[num[l]] --;
                    l ++;
                }
                int subAns = r - (l - 1) + 1;
                Ans = min(Ans, subAns);
            }
        }else{
            M[num[r]] ++;
        }

    };
    if(Ans != INF)cout << Ans<< endl;
    else cout << -1 << endl;
}