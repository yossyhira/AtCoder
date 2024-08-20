#include <bits/stdc++.h>
using namespace std;

int main() {
    int Idx, count=0;
    cin>>Idx;
    vector<int> num(Idx);
    for(int i = 0; i < Idx; i++){
        cin>>num.at(i);
    }
    
    bool end = false;
    while(!end){
        for(int i = 0; i < Idx; i++){
            if(num.at(i) % 2 == 0){
                num.at(i) /= 2;
                count ++;
            }else{
                end = true;
                break;
            }
        }
    }

    cout << count/Idx << endl;
}
