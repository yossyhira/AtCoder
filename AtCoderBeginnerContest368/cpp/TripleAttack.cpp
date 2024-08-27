#include <bits/stdc++.h>
using namespace std;

int main() {
    int Idx, enemy, mod;
    long T = 0;
    cin>>Idx;
    for(int i = 0; i < Idx; i++){
        cin>>enemy;

        T += (long)((enemy / 5) * 3);

        if (enemy % 5 != 0){
            mod = enemy % 5;
            do{
                T++;
                if(T % 3 != 0){
                    mod --;
                }else{
                    mod -= 3;
                }
            }while(mod > 0);
        }
    }

    cout << T << endl;
}
