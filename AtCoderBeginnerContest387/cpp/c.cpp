#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        string s = to_string(i);
        int n = s.size();
        vector<int> num;
        for (int j = 0; j < n; j++) {
            int digit = s[j] - '0';
            num.push_back(digit);
        }

        int tmp = num[0];

        for (int i = 0; i <= 10; i++) {
            num
        }
        for (int j = 1; j < n; j++) {
            if(num[j] >= tmp){
                i = 1 * ((n - j + 1)*10);
            }
        }

    }
    //cout << << endl;
}