#include <bits/stdc++.h>
using namespace std;

int digsum(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
}

int main() {
    int maxNum, underNum, topNum, sum = 0, ans = 0;
    cin>>maxNum>>underNum>>topNum;

    for(int i = 1; i <= maxNum; i++){
        sum = digsum(i);
        if(underNum <= sum && sum <= topNum) ans += i;

    } 
    cout<<ans<<endl;
}