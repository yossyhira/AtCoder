#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> S;
  int a, Idx;
  cin >> Idx;
  for(int i = 0; i < Idx; i++){  
    cin>>a;
    S.insert(a);
  }
  cout << S.size() << endl;
}
