#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> num(n);
    map<int, int> r;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        
        if(r.count(num[i])){
            r[num[i]] ++;
        }else{
            r[num[i]] = 1;
        }
    }
    map<int, int> l;
    int cnt = 0, ans = -1;
    for (int i = 0; i < n; i++) {

        r[num[i]] --;
        if(r[num[i]] == 0) cnt ++;

        if(l.count(num[i])){
            l[num[i]] ++;
        }else{
            l[num[i]] = 1;
        }
        int subAns = l.size() + (r.size() - cnt);
        ans = max(ans, subAns);
    }
    cout << ans << endl;
    return 0;
}