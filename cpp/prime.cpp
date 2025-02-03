#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPrime(ll num){
    for (int i = 2; i < num - 1; i++) {
        if(num % i == 0) return false;
    }
    return true;
}
bool fastIsPrime(ll num){
    if (num < 2) return false; // 1以下は素数じゃない
    if (num == 2) return true; // 2は素数
    if (num % 2 == 0) return false; // 偶数は2以外全部ダメ
    for (int i = 2; i*i <= num ; i++) {
        if(num % i == 0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll num;
    cin >> num;
    
    cout << (fastIsPrime(num) ?"Yes" : "No")<< endl;
} 