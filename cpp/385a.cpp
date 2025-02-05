#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c){
        cout << "Yes" << endl;
    }
    else if((a+b) == c){
        cout << "Yes" << endl;
    }
    else if((a+c) == b){
        cout << "Yes" << endl;
    }
    else if((b+c) == a){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    
    return 0;
}