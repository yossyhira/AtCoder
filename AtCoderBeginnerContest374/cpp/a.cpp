#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  
    
    cin >> N;  

    vector<int> num(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    // すべてのパターンを生成する
    int all = pow(2, N);  // 2^N 通りのパターンがある

    long ansNum = LONG_MAX;

    for (int i = 0; i < all; i++) {
        long A = 0;
        long B = 0;

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                A += num[j];
            } else {
                B += num[j];
            }
        }
        long maxNum = max(A, B);
        ansNum = min(ansNum, maxNum);
    }

    cout << ansNum << endl;

    return 0;
}

