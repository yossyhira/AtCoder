#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        string s;
        cin >> s;
        unsigned n_A, n_B, n_C;
        cin >> n_A >> n_B >> n_C;
        cout << min({n_A, n_C, (n_A + n_B + n_C) / 3}) << endl;
    }
    return 0;
}
