#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h;
    for (int i = 0; i < n; i++) {
        int num ;
        cin >> num;
        h.push_back(num);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int base_Num = h.at(i);
        for (int j = 1; j <= n; j++) {
            int count = 1, Idx;
            while(1){
                Idx = i+j*count;
                if(Idx >= n) break;
                if( base_Num != h.at(Idx)) break;
                count ++;     
            }
            ans = max(ans, count);
        }
    }
    cout << ans << endl;
}