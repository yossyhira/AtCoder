#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> num;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    for (int i = 0; i < 4; i++) {
        vector<int> num_copy = num;
        int tmp = 0;
        tmp = num_copy[i];
        num_copy[i] = num_copy[i+1];
        num_copy[i + 1] = tmp;
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if(num_copy[i] < num_copy[i + 1]){
                count ++;
            }
        }
        if(count == 4){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}