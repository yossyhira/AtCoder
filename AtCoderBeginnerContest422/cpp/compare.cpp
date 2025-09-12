#include <bits/stdc++.h>
using namespace std;

void compare_txt(const string &file1, const string &file2) {
    ifstream f1(file1), f2(file2);
    if (!f1.is_open() || !f2.is_open()) {
        cerr << "ファイルを開けませんでした。" << endl;
        return;
    }

    string line1, line2;
    int line_num = 1;
    bool diff_found = false;

    while (true) {
        bool r1 = static_cast<bool>(getline(f1, line1));
        bool r2 = static_cast<bool>(getline(f2, line2));

        if (!r1 && !r2) break; // 両方とも終わり

        if (line1 != line2) {
            diff_found = true;
            cout << "違いあり (行 " << line_num << "):\n";
            cout << "  " << file1 << ": " << (r1 ? line1 : "<EOF>") << "\n";
            cout << "  " << file2 << ": " << (r2 ? line2 : "<EOF>") << "\n";
            cout << "----------------------------------------\n";
        }
        line_num++;
    }

    if (!diff_found) {
        cout << "差分はありませんでした。" << endl;
    }
}

int main() {
    compare_txt("c.txt", "ans.txt");
    return 0;
}
