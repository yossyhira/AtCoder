#include <bits/stdc++.h>
using namespace std;

int main() {
    int Idx;
    cin>>Idx;
    vector<int> num(Idx);
    for(int i = 0; i < Idx; i++){
        cin>>num[i];
    }
    int ans = Idx;

    ans += Idx - 1;
    int base, count = 0;
    for(int i = 3; i <= Idx; i++){
        for(int j = 0; j < Idx - (i - 1); j++){
            base = num[j] - num [j + 1];
            for(int k = j; k < j + i - 1 ; k++ ){
                if(base == num[k] - num[k+1]){
                    count++;
                    if(count == i - 1){
                        ans++;
                        count = 0;
                    }
                }else{
                    break;
                }
            }
            count = 0;
        }
    }
    cout << ans << endl;
}
