#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >>text;
    
    int a =  text.at(0) - '0';
    int c =  text.at(2) - '0';
    cout << a * c << endl;
}