#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll n;
    cin >> n;


    for (long long d = 1; d * d * d <= n; d++) {  
        if (n % d != 0) continue;

        long long k = n / d;

        
        long long a = 3, b = 3 * d, c = d * d - k;
        long long D = b * b - 4 * a * c;  
        
        if (D < 0) continue; 
        long long sqrtD = sqrt(D);
        if (sqrtD * sqrtD != D) continue;  

        long long y1 = (-b + sqrtD) / (2 * a);
        long long y2 = (-b - sqrtD) / (2 * a);
        if(y1 == 0 || y2 == 0) continue;

      
        if ((-b + sqrtD) % (2 * a) == 0) {
            cout << (y1 + d) << " " << y1 << endl;
            return 0;
        }
        if ((-b - sqrtD) % (2 * a) == 0) {
            cout << (y2 + d) << " " << y2 << endl;
            return 0;
        }
    }

    cout << -1 << endl;  
    return 0;
}
