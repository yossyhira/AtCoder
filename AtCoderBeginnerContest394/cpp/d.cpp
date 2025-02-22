#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    stack<char> st;
    for (int i = 0; i < text.size(); i++) {
        if(text.at(i) == '(' || text.at(i) == '['|| text.at(i) == '<'){
            st.push(text.at(i));
        }else{
            if(st.size() == 0) {
                cout << "No" << endl;
             return 0;
            }
            char c = text.at(i);
            char q = st.top();
            st.pop();

            if(!(q == '(' && c == ')') && !(q == '[' && c == ']') && !(q == '<' && c == '>')){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    if(st.size() == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}