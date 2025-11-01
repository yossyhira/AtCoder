#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<long long> cnt(n+1,0);
    for(int i=0; i < n; i++){
        int a; 
        cin >> a;
        cnt[a]++;
    }
    long long ans = 0;
    for(int v=0; v <= n; v++){

        long long c = cnt[v];
        if (c >= 2){
            ans += (c*(c-1)/2) * (n - c);
        }
    }
    cout << ans << endl;
    return 0;
}
