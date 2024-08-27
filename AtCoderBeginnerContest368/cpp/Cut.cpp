#include <bits/stdc++.h>
using namespace std;

int main() {
    int Idx, draw;
    cin >> Idx;
    cin >> draw;
    deque<int> num (Idx + 1);
    for(int i = 0; i < Idx; i++){
        cin >> num[i];
    }
    
    for(int i = 0; i < draw; i++){
        num.push_front(num[Idx - 1]);
        num.pop_back();
    }

    for(int i = 0; i < Idx; i++) cout <<num[i]<< ' ';
    cout << endl;
}
