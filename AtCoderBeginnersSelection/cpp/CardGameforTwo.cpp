#include <bits/stdc++.h>
using namespace std;

int main() {
    int Idx;
    cin>>Idx;
    vector<int> num(Idx);
    for(int i = 0; i < Idx; i++){
        cin>>num[i];
    }
    sort(num.rbegin(), num.rend());

    int Ascore = 0, Bscore = 0;

    for(int i = 0; i < Idx; i += 2){
        Ascore += num.at(i);
    }
    for(int i = 1; i < Idx; i += 2){
        Bscore += num.at(i);
    }

    cout << Ascore - Bscore << endl;
}
