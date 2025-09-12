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
    
    
    int rd_mn = 0;
    int rd_mx = 1e9;
    int tmx = 2e5;
    cout << tmx << endl;
    for (int i = 0; i < tmx; i++) {
    cout << i+1 << "回目" << endl;
    cout << get_rand(rd_mn, rd_mx)<< " " << get_rand(rd_mn, rd_mx)<< " " << get_rand(rd_mn, rd_mx) << endl;
    }
}