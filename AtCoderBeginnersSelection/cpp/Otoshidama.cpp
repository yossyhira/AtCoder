#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, money;
    cin>>N>>money;
    int coin10000 = -1, coin5000 = -1, coin1000 = -1, count=0,k=0;

        for(int i=0; i <= N; i++){
            for(int j=0; j <= N; j++){
                k = N-(i+j);
                if(k >= 0){
                    count = i*10000 + j*5000 + k*1000;
                    if(((i + j + k) == N) && (count == money)){
                        cout<<i<<" "<<j<<" "<<k<<endl;
                        return 0;
                    }
                    count = 0;
                }
            }
        }
    
    cout<<coin1000<<" "<<coin5000<<" "<<coin10000<<endl;
}