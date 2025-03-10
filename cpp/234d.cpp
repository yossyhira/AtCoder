#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        q.emplace(num);
    }
    bool top = true;
    int ans;
    for (int i = k; i < n; i++) {
        if(top) ans = q.top();
        cout << ans << endl;
        int next;
        cin >> next;
        if(ans < next){
            q.pop();
            q.emplace(next);
            top = true;
        }else top = false;
    }
    cout << q.top() << endl;
    return 0;
}