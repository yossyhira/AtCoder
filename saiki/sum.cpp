#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sum(int a, int b){
    if(a < b) swap(a, b);
    if(a == b) return b;
    return a + sum(a - 1 , b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << sum(a, b)<< endl;
}