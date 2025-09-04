#include <random>
#include <iostream>
using namespace std;
int main() {
    // 真の乱数生成器のインスタンス化
    random_device rd;
    auto get_rand = [&](int mn, int mx){
        std::uniform_int_distribution<int> dist(mn, mx);
        int x = dist(rd);
        return x;
    };
    auto move = [&](int x){
        char c;
        switch(x){
            case 0: 
                c = 'U';
                break;
            case 1:
                c = 'D';
                break;
            case 2: 
                c = 'R';
                break;
            case 3: 
                c = 'L';
                break;
            
        }
        return c;
    };

    int rd_mx = 5;
    int rd_mn = 0;
    int qmx = 10;
    for (int i = 0; i < 100; i++) {
        
    
    cout << get_rand(rd_mn, rd_mx)<< " " << get_rand(rd_mn, rd_mx)<< " " << get_rand(rd_mn, rd_mx)<< " " << get_rand(rd_mn, rd_mx)<< endl;
    int m = get_rand(1, qmx);
    int l = get_rand(1, qmx);
    int mx = max(m, l)*rd_mx;
    int n = mx;
    cout << n << " " << m << " " << l << endl;
    int all_m = 0;
    for (int i = 0; i < (m - 1); i++) {
        int x = get_rand(1, rd_mx);
        all_m += x;
        cout << move(get_rand(0, 3)) << " " << x << endl;
    }
    cout << move(get_rand(0, 3)) << " " << mx - all_m << endl;;
    int all_t = 0;
    for (int i = 0; i < (l - 1); i++) {
        int x = get_rand(1, rd_mx);
        all_t += x;
        cout << move(get_rand(0, 3)) << " " << x << endl;
    }
    cout << move(get_rand(0, 3)) << " " << mx - all_t;
    cout << endl;
    }
}