#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    if(k == 1){
        cout << 0 << endl;
        return 0;
    }
    int num = k / 2;
    int ans = 0;
    if((k % 2) == 0){
        for (int i = 1; i <= num; i++) {
            ans += a[((i - 1)*2) + 1] - a[(i - 1)*2];
        }cout << ans << endl;
        return 0;
    }
    vector<int> Foward(num + 1,0);
    vector<int> Back(num + 1,0);
    for (int i = 1; i <= num; i ++) {
        Foward[i] = Foward[i - 1] + (a[((i - 1)*2) + 1] - a[(i - 1)*2]);
    }
    for (int i = 1; i <= num; i ++) {
        Back[i] = Back[i - 1] + (a[i * 2] - a[((i - 1)*2) + 1]);
    }
    
    ans = Foward[num]; //最後除外
    //cout << ans << endl;
    ans = min(ans, Back[num]); //0番目除外
    //cout << Back[num] << endl;
    for (int i = 1; i < k-1; i++) {
        int subAns = 0;
        if((i % 2) != 0){
            int Idx = (i / 2);
            subAns = Foward[Idx] + (a[i+1] - a[i-1]) + (Back[num] - Back[((i + 2)/ 2)]);
        }else{
           int Idx = (i / 2);
           subAns = Foward[Idx] + (Back[num] - Back[((i + 1)/ 2)]);
        }
        //cout << i << "回目　"<< subAns << endl;
        ans = min(ans, subAns);
        
    }
    //ans = min(ans, Foward[((k - 2) / 2)] + (a[(k-2)+1] - a[(k-2)-1]));
    //cout <<  Foward[((k - 2) / 2)] + (a[(k-2)+1] - a[(k-2)-1]) << endl;
    cout << ans << endl;
    return 0;


}