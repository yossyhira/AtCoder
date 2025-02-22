#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    reverse(text.begin(), text.end());
    for (int i = 0; i < text.size() - 1; i++) {
        if(text.at(i) == 'A' && text.at(i + 1) == 'W'){
            text[i + 1] = 'A';
            text[i] = 'C';
        }
    }
    reverse(text.begin(), text.end());

    cout << text << endl;
}