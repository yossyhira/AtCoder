#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    int ans = 0;
    for (int i = 0; i < text.size(); i++) {
        if(text.at(i) == 'A'){
            for (int j = i ; j < text.size(); j++) {
                if(text.at(j) == 'B' && j + (j - i) < text.size()){
                    if(text.at(j + (j - i)) == 'C') ans ++;
                }
            }
        }
    }
    cout <<ans << endl;
}