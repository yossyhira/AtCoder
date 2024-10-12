#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using P = pair<int, int>;

int main() {
    vector<int> c(9);
    rep(i, 9) cin >> c[i];//マス目

    vector<int> p(9);
    rep(i, 9) p[i] = i;

    int cnt = 0, tot = 0;
    do {
        bool ok = true;
        auto f = [&](int i, int j, int k) {
            vector<P> d;
            d.emplace_back(p[i], c[i]);
            d.emplace_back(p[j], c[j]);
            d.emplace_back(p[k], c[k]);
            sort(d.begin(), d.end());
            if (d[0].second == d[1].second) ok = false;
        };

        f(0, 1, 2);
        f(3, 4, 5);
        f(6, 7, 8);
        f(0, 3, 6);
        f(1, 4, 7);
        f(2, 5, 8);
        f(0, 4, 8);
        f(2, 4, 6);

        if (ok) cnt++;
        tot++;
    } while (next_permutation(p.begin(), p.end()));

    double ans = 1.0 * cnt / tot;
    printf("%.10f\n", ans);
    return 0;
}
