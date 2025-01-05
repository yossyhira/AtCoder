#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a;
    cin >> a;
    if((a % 3) == 0){
        cout << 0 << endl;
        return 0;
    }
    string s = to_string(a);
    int n = s.size();
    vector<int> num;
    for (int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        num.push_back(digit);
    }

    int ans = 1000000;
    bool ok = false;

    for (int i = 0; i < (1 << n); i++) {
        int three = 0, count = 0;
        for (int j = 0; j < n; j++) {
            if((i & (1 << j)) != 0){
                //消した合計
                count ++;
            }else{
                //消さなかった
                three += num[j];
            }
        }

        if((three != 0) && ((three % 3) == 0)){
            ans = min(ans, count);
            ok = true;
        }
    }
    
    if(ok){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}