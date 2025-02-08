#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s(int num){
    if(num == 1){
        string text = "1";
        return text;
    }
    string text = to_string(num);

    text = s(num - 1)+ " "+ text + " " +s(num - 1);

    return text;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    cout << s(a) << endl;
}