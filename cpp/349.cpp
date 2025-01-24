#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*bool check(string s, string t){
    return true;
    //return false;
}*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < 3; i++) {
        t.at(i) -= 'A' - 'a';
    }
    if(t.at(2) == 'x'){
        t.pop_back();
    }

    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s.at(i) == t.at(count)){
            count++;
            if(count == t.size()) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}