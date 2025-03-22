#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string tex;
    cin >> n >> tex;
    deque<int> deq;
    deq.push_front(n);
    for (int i = n - 1; i >= 0 ; i--) {
        if(tex[i] == 'R'){
            deq.push_front(i);
        }else{
            deq.push_back(i);
        }
    }
    for(int x : deq){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}