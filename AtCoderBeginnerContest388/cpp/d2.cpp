#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<long long, long long>> s;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        s.push_back({num, 0});
    }
    long long stock = 0;
    for (int i = 0; i < N; i++) {
        long long num;
        long long  no;
        tie(num, no) = s.at(i);
        if(no > 0) stock -= no;
        num += stock;
        long long stone = num - (N - i - 1);
        if(stone < 0){
            int Idx = i + num + 1;
            s[Idx].second ++;
        }
        stock ++;

        if(stone < 0){
            cout << 0 << " ";
        }else{
            cout << stone << " ";
        }
    }
    cout << endl;
}

/*
  s[i] += i;
        long long stone = s.at(i) - (N - i - 1);
        if(stone < 0){
            long long  num = s.at(i);

        }
        stock += stone;

        long long ans = s.at(i) - stone;
        cout << ans << " ";
*/