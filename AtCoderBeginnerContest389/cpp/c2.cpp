#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    deque<long long> queue; // ヘビの頭の座標を管理
    long long offset = 0;   // 全体のオフセットを管理
    vector<long long> output; // 出力結果を格納するベクター

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            // クエリタイプ1: ヘビを追加
            long long l;
            cin >> l;
            long long head_position = queue.empty() ? 0 : queue.back() + l;
            queue.push_back(head_position);
        } else if (type == 2) {
            // クエリタイプ2: 先頭のヘビを削除
            long long m = queue.front();
            queue.pop_front();
            offset += m;
        } else if (type == 3) {
            // クエリタイプ3: k番目のヘビの頭座標を出力
            int k;
            cin >> k;
            output.push_back(queue[k - 1] - offset);
        }
    }

    // 出力
    for (long long res : output) {
        cout << res << endl;
    }

    return 0;
}
