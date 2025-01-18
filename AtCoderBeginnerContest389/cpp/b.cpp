#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long num;
    cin >> num;
    long long ans = 1;
    long long count = 1;
    while(1){
        ans *= count;
        if(ans == num){
            break;
        }
        count ++;
    }

    cout << count << endl;
}