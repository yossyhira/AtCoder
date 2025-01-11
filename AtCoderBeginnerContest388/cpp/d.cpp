#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> s;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        s.push_back(num);
    }
    for (int i = 0; i < N; i++) {
        int stone = s.at(i);
        int Idx = i + 1;
        while(1){
            //終わりだったらN
            if(Idx == N) break;
            //0なったら
            if(stone == 0) break;
            s[Idx] ++;
            stone --;          
            Idx ++;
        }
        cout << stone << " ";
    }
    cout << endl;
}