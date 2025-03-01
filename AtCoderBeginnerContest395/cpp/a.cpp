#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    cin >> num;
    int befN;
    cin >> befN;
    bool flag = true;
    for (int i = 0; i < num - 1; i++) {
        int NowN;
        cin >> NowN;
        if(NowN < befN) flag = false;
        if(NowN == befN) flag = false;
        befN = NowN;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}