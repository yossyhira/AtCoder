#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >>text;
    int c = 0;
    for (int i = 0; i < text.size(); i++) {
        if(text.at(i) == '2') c ++;
    }
    for (int i = 0; i < c; i++) {
        cout << 2;
    }
    cout << endl;
    return 0;
}