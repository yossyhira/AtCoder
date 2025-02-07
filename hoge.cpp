#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// 汎用的なbitset出力関数
void out(const bitset<2000>& bs) {
    bool flag = false;
    for (int i = 1999; i >= 0; i--) {
        if (bs[i] == 1) flag = true; // 頭の余計な0をスキップ
        if (flag) cout << bs[i];
    }
    if (!flag) cout << "0"; // 全部0なら "0" を出力
    cout << endl;
}

int main() {
    // A or B を計算
    int A, B;
    cin >> A >> B;
    
    bitset<2000> A1(A);
    bitset<2000> B1(B);
    bitset<2000> OR  = (A1 | B1);  // OR 計算
    bitset<2000> AND = (A1 & B1);  // AND 計算
    bitset<2000> XOR = (A1 ^ B1);  // XOR 計算
    bitset<2000> NOT = (~A1);      // NOT 計算
    bitset<2000> LSHIFT = (A1 << 1); // 左シフト
    bitset<2000> RSHIFT = (A1 >> 1); // 右シフト

    cout << "OR   : "; out(OR);
    cout << "AND  : "; out(AND);
    cout << "XOR  : "; out(XOR);
    cout << "NOT  : "; out(NOT);
    cout << "LSHFT: "; out(LSHIFT);
    cout << "RSHFT: "; out(RSHIFT);

    return 0;
}
