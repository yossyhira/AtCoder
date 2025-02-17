#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2;
    cin >> s1 >> s2;
    if(s1 == "sick"){
        if(s2 == "sick") cout << 1 << endl;
        else cout << 2 << endl;
    }else{
        if(s2 == "sick") cout << 3 << endl;
        else cout << 4 << endl;
    }
}