#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
long double dist(int sx, int sy, int gx, int gy) {
    return sqrtl((long double)((sx - gx) * (sx - gx) + (sy - gy) * (sy - gy)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<pair<int, int>>> cut(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cut[i].push_back({a, b});
        cut[i].push_back({c, d});
    }
    vector<int> p(n);//3!の全探索
    rep(i, n) p[i] = i;
    long double ans = 100010001000.0;
    do {
        for (int i = 0; i < (1 << n); i++) {
            int befX = 0, befY = 0;
            long double subans = 0.0;
            for (int j = 0; j < n; j++) {
                if((i & (1 << j)) != 0){
                    int sx, sy;
                    tie(sx, sy) = cut[p[j]].at(0); 
                    //subans += dist(befX, befY, sx, sy) / s;
                    int gx, gy;
                    tie(gx, gy) = cut[p[j]].at(1);
                    //subans += dist(sx, sy, gx, gy) / t; 
                    subans += (dist(befX, befY, sx, sy) / ((long double)s)) + (dist(sx, sy, gx, gy) / ((long double)t));
                    befX = gx;
                    befY = gy;

                }else{
                    int sx, sy;
                    tie(sx, sy) = cut[p[j]].at(1); 
                    //subans += dist(befX, befY, sx, sy) / s; 
                    int gx, gy;
                    tie(gx, gy) = cut[p[j]].at(0); 
                    //subans += dist(sx, sy, gx, gy) / t;
                    subans += (dist(befX, befY, sx, sy) / ((long double)s)) + (dist(sx, sy, gx, gy) / ((long double)t));
                    befX = gx;
                    befY = gy;
                }
            }
            ans = min(ans, subans);
        }
    } while (next_permutation(p.begin(), p.end()));
    
    printf("%.10Lf\n",ans);
    return 0;
    //cout << << endl;
}