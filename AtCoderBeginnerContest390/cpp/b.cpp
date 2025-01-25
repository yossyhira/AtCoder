#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<double> num;
    for (int i = 0; i < n; i++) {
        double hoge;
        cin >> hoge;
        num.push_back(hoge);
    }
    double first = num[0];
    double hi = num[1] / num[0];
    for (int i = 1; i < n; i++) {
        double ans = num[i - 1] * hi;
        if(ans != num[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes"<< endl;
    return 0;
}