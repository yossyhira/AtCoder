#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>a;
  a.push_back(1);
  for (int i = 0; i < 10; i++) {
    a.back()++;
  }
  
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] <<" ";
  }
  cout << endl;
}