#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    string texts = "Z";
    cin >> text;
    texts = texts + text;
    reverse(texts.begin(), texts.end());
    vector<char> s;
    bool flagA = false;
    for (int i = 0; i < texts.size() - 1; i++) {
        if(texts.at(i) != 'W' && texts.at(i) != 'A'){
            flagA = false;
            s.push_back(texts.at(i));
        }
        else if(texts.at(i) == 'A' && texts.at(i + 1) == 'W'){
            flagA = true;
            s.push_back('C');
        }
        else if(texts.at(i) == 'A' && texts.at(i + 1) != 'W'){
            flagA = false;
            s.push_back('A');
        }
        else if(flagA && texts.at(i) == 'W' && texts.at(i + 1) == 'W'){
            s.push_back('C');
        }
        else if(flagA && texts.at(i) == 'W' && texts.at(i + 1) != 'W'){
            s.push_back('A');
            flagA = false;
        }
        else if(!flagA && texts.at(i) == 'W'){
            s.push_back('W');
            flagA = false;
        } 
    }

    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        cout << s.at(i);
    }
    cout << endl;
}