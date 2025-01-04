#include <iostream>
#include <string>

using namespace std;

// ヘビ数判定関数
bool isSnakeNumber(long long num) {
    string s = to_string(num); // 数値を文字列に変換
    char firstDigit = s[0];    // 先頭の桁

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] >= firstDigit) {
            // 他の桁が先頭の桁以上ならヘビ数ではない
            return false;
        }
    }
    return true;
}

int main() {
    long long num = 10;
    cout << "[";
   while(num != 1000000000000000000){
    // ヘビ数判定
    if (!isSnakeNumber(num)) {
        cout << num << ",";
    }

    num++;

 }

 cout << "]" << endl;
    return 0;
}
