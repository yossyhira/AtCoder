#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double num;
    cin >> num;
    if(38.0 <= num ){
        cout << 1 << endl;
    }else if (37.5 <= num){
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
    }
    return 0;
}