#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<int> deq;
    deq.push_back(5);
    deq.push_back(4);
    deq.push_back(3);
    deq.push_back(2);
    deq.push_back(1);

    for(int x : deq){
      cout << x << " ";
    }
    cout << endl;
    
    deq[4] = 0; //ここの計算量
    for(int x : deq){
      cout << x << " ";
    }
    cout << endl;
    
    return 0;
}