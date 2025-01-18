#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;

    vector<long long> len;
    vector<long long> snake;
    long long outLen = 0;
    len.push_back(0);
    long long count = 0;
    long long outCount = 0;
    long long ansCount = 0;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1){
            long long num;
            cin >> num;
            snake.push_back(num);
            num += len.at(count);
            len.push_back(num);
            count ++;
        }
        else if (type == 2){
            outLen += snake.at(outCount);
            outCount ++;
            ansCount++;
        }
        else if(type == 3){
            long long num;
            cin >> num;
            cout << len.at(num + ansCount - 1) - outLen<< endl;
        }
    }
}