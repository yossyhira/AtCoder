#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if(n == m){
        cout << 0 << endl;
        return 0;
    }else if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    vector<int> num(m);
    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    priority_queue<int, vector<int>, greater<int>> q;
    
    int first_dig = num.front() - 1; 
    if(first_dig != 0) q.emplace(first_dig);
    
    for (int i = 0; i < m - 1; i++) {
        int dig = (num[i + 1] - num[i]) - 1;
        if(dig != 0) q.emplace(dig);
    }

    int last_dig = n - num.back(); 
    if(last_dig != 0) q.emplace(last_dig);

    int base = q.top();
    q.pop();
    int ans = 1;
    while(!q.empty()){
        int subans = 0;
        int white = q.top();
        int judge = white % base;
        subans = white / base;
        if(judge != 0) subans ++;
        ans += subans;
        q.pop();
    }
    cout << ans << endl;
    return 0;
}