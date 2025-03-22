#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int mod = n % 2;
    if(mod == 0){
        int x = n / 2;
        for (int i = 0; i < n; i++) {
            if(i == (x - 1) || i == x){
                cout << '=';
            }else{
                cout << '-';
            }
        }
    }else{
        int x = n / 2;
        for (int i = 0; i < n; i++) {
            if(i == x){
                cout << '=';
            }else{
                cout << '-';
            }
        }
    } 
    cout << endl;
    return 0;
}