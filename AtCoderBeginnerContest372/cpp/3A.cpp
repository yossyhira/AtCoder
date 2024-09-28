#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin>>a;
    int count = 0;
    int num = 0;
    int num2[21];
    while (a != 0)
    {
        for(int i = 10; i >= 0; i--){
            num = pow(3, i);
            if(num <= a){
                a -= num;
                num2[count] = i; 
                count++;
                break;
            }
        }
    }
    cout<<count<<endl;
    for(int i = 0; i < count - 1; i++){
        cout << num2[i] << " ";
    }
    cout << num2[count - 1] << endl;
    return 0;

}
