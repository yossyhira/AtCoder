#include <bits/stdc++.h>
using namespace std;

int main() {


    int Idx;
    cin >> Idx;
    
    vector<int> a(Idx);
    vector<int> b(Idx);

   
    for (int i = 0; i < Idx; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < Idx; i++) {
        cin >> b.at(i);
    }
    
   sort(begin(a), end(a), greater<>());
   sort(begin(b), end(b), greater<>());
    
    cout << a.at(0)+b.at(0) << endl;
}

