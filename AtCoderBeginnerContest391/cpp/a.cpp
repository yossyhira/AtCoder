#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    if(text == "N"){
        cout << "S" << endl;
    }
    else if(text == "S"){
        cout << "N" << endl;
    }
    else if(text == "E"){
        cout << "W" << endl;
    }
    else if(text == "W"){
        cout << "E" << endl;
    }
    else if(text == "NE"){
        cout << "SW" << endl;
    }
    else if(text == "SW"){
        cout << "NE" << endl;
    }
    else if(text == "NW"){
        cout << "SE" << endl;
    }
    else if(text == "SE"){
        cout << "NW" << endl;
    }
    return 0;
}